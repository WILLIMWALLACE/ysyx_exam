PWD_PATH = $(shell pwd)
YSYX_PATH = $(PWD_PATH)/ysyx-workbench/
NPC = $(YSYX_PATH)/npc/
CSRC =$(NPC)/csrc/
VSRC =$(NPC)/vsrc/
CPP = $(wildcard $(CSRC)*.cpp)
VPP = $(wildcard $(VSRC)*.v)
vpath %.v ./vsrc
vpath %.cpp $(CSRC)



all:  sim
	@echo "jmx first makefile"



#compile: 
#	verilator -Wall --cc top.v --exe --trace --build top_tb.cpp
#	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!

#注意，可以有多个目标文件，但总是默认第一个为最终的文件， 只要 写完最终文件  当即停止
sim:
	#git必须命令
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	#上述sim  target（目标文件.o 、label标签、 执行文件（目前就是当作这些.o文件链接生成的执行文件sim））
#	cc -o sim $(objects)
	verilator -Wall --cc --exe --trace --build $(VSRC)top.v $(CSRC)top_tb.cpp




.PHONY: clean
clean:
	rm -f  *.o sim compile                    

include ../Makefile
