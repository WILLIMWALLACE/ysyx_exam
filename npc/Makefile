all:  sim
	@echo "jmx first makefile"


#objects = top_tb.o verilated.o
CSRC = /csrc
VSRC = /vsrc
vpath %.v $(VSRC)
vpath %.cpp $(CSRC)

#compile: 
#	verilator -Wall --cc top.v --exe --trace --build top_tb.cpp
#	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!

#注意，可以有多个目标文件，但总是默认第一个为最终的文件， 只要 写完最终文件  当即停止
sim:
	#git必须命令
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	#上述sim  target（目标文件.o 、label标签、 执行文件（目前就是当作这些.o文件链接生成的执行文件sim））
#	cc -o sim $(objects)
	verilator -Wall --cc top.v --exe --trace --build top_tb.cpp




.PHONY: clean
clean:
	rm -f  *.o sim compile                    

include ../Makefile
