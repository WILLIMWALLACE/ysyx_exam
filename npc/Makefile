#打开当前的相对目录
NPC = $(shell pwd)
CSRC =$(NPC)/csrc/
VSRC =$(NPC)/vsrc/
#wildcard 获取该路径下 所有的  通配符对应 的  文件
CPP = $(wildcard $(CSRC)*.cpp)
VPP = $(wildcard $(VSRC)*.v)
OBJ_PATH = $(NPC)/obj_dir/
OBJ_MK = $(wildcard $(OBJ_PATH)*.mk)
#vpath %.v ./vsrc
#vpath %.cpp $(CSRC)

all:  sim objmk
	@echo "jmx first makefile"


#注意，可以有多个目标文件，但总是默认第一个为最终的文件， 只要 写完最终文件  当即停止
sim:
	@#git必须命令
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	@#上述sim  target（目标文件.o 、label标签、 执行文件（目前就是当作这些.o文件链接生成的执行文件sim））
#	cc -o sim $(objects)
	verilator -Wall --cc --exe --trace --build $(VPP) $(CPP)

objmk: sim
	@#找不到makefile文件，因为.mk不叫makfile
	#$(MAKE) -C $(OBJ_PATH)
	$(MAKE)  -f $(OBJ_MK)

.PHONY: clean
clean:
	-rm -f  *.o sim objmk all                    

include ../Makefile
