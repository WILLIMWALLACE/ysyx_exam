#include <proc.h>
#include <elf.h>
//#include <fs.h>
//#include ISA_H

#ifdef __LP64__
# define Elf_Ehdr Elf64_Ehdr
# define Elf_Phdr Elf64_Phdr
#else
# define Elf_Ehdr Elf32_Ehdr
# define Elf_Phdr Elf32_Phdr
#endif

#if defined(__ISA_AM_NATIVE__)
# define EXPECT_TYPE EM_X86_64
#elif defined(__ISA_X86__)
# define EXPECT_TYPE EM_X86_64
#elif defined(__ISA_MIPS32__)
# define EXPECT_TYPE EM_MIPS
#elif defined(__ISA_RISCV32__) || defined(__ISA_RISCV64__)
# define EXPECT_TYPE EM_RISCV
#elif
# error unsupported ISA __ISA__
#endif

size_t ramdisk_read(void *buf, size_t offset, size_t len) ;
size_t ramdisk_write(const void *buf, size_t offset, size_t len);

int sys_open(const char *path);
int sys_write(int fd,  char *buf, size_t count,Context *c);
int sys_read(int fd,void *buf,size_t count,Context *c);
int sys_close();

static uintptr_t loader(PCB *pcb, const char *filename) {
  Elf_Ehdr ehdr;
  //ramdisk_read(&ehdr, 0, sizeof(ehdr));
  //printf("e_ident = %d\n",ehdr.e_ident);
  //printf("machine=%d\n",ehdr.e_machine);
  //printf("pnum=%d\n",ehdr.e_phnum);
  int fd = sys_open(filename);
  //printf("fd=%d\n",fd);
  sys_read(fd,&ehdr,0,0);
  printf("readfinish\n");
  Elf_Phdr phdr[ehdr.e_phnum];
  assert(*(uint32_t *)ehdr.e_ident == 0x464c457f);
  assert(ehdr.e_machine == EXPECT_TYPE);
  //sys_read(fd,(char *)phdr,ehdr.e_phentsize*ehdr.e_phnum,ehdr.e_phoff,0);
  sys_close();
 // printf("offset=%d,len=%d\n",ehdr.e_phoff,ehdr.e_phentsize*ehdr.e_phnum);
  ramdisk_read(phdr, ehdr.e_phoff, ehdr.e_phentsize*ehdr.e_phnum);
  for(int i=0; i<ehdr.e_phnum; i++){
    if(phdr[i].p_type == PT_LOAD){
      //printf("phdr[%d].offset=%s\n",i,phdr[i].p_offset);
      ramdisk_read((void*)phdr[i].p_vaddr,phdr[i].p_offset,phdr[i].p_memsz);
      //printf("vaddr=%d,filez=%d,memsize=%d\n",phdr[i].p_vaddr,phdr[i].p_filesz,phdr[i].p_memsz);
      memset((void*)(phdr[i].p_vaddr + phdr[i].p_filesz),0,(phdr[i].p_memsz - phdr[i].p_filesz));
    }
  }
  return ehdr.e_entry;
}

void naive_uload(PCB *pcb, const char *filename) {
 // printf("enter the loader\n");
  uintptr_t entry = loader(pcb, filename);
  Log("Jump to entry = %p", entry);
  ((void(*)())entry) ();
}

