#打开当前的相对目录
NPC = $(shell pwd)
CSRC =$(NPC)/csrc/
VSRC =$(NPC)/vsrc/
#wildcard 获取该路径下 所有的  通配符对应 的  文件
CPP = $(wildcard $(CSRC)*.cpp)
VPP = $(wildcard $(VSRC)*.v)
TOPNAME = Vtop
#OBJ_PATH = $(NPC)/obj_dir/
#OBJ_MK = $(wildcard $(OBJ_PATH)*.mk)
################ 接入nvboard #####################
NXDC_FILES = $(NPC)/constr/top.nxdc
#尝试创建集成路径
BUILD_DIR = ./build
OBJ_DIR = $(BUILD_DIR)/obj_dir
BIN = $(BUILD_DIR)/$(TOPNAME)


# rules for verilator
INC_PATH ?=
INCFLAGS = $(addprefix -I, $(INC_PATH))
CFLAGS += $(INCFLAGS) -DTOP_NAME="\"V$(TOPNAME)\""
LDFLAGS += -lSDL2 -lSDL2_image


all:  sim run
	@echo "jmx makefile"

# constraint file
SRC_AUTO_BIND = $(abspath $(BUILD_DIR)/auto_bind.cpp)
$(SRC_AUTO_BIND): $(NXDC_FILES)
	python3 $(NVBOARD_HOME)/scripts/auto_pin_bind.py $^ $@

#注意，可以有多个目标文件，但总是默认第一个为最终的文件， 只要 写完最终文件  当即停止
####################  verilator  编译执行 ############
sim: $(VPP)  $(CPP)  $(NVBOARD_ARCHIVE)
	@#git必须命令
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	@#上述sim  target（目标文件.o 、label标签、 执行文件（目前就是当作这些.o文件链接生成的执行文件sim））
	verilator -Wall -MMD --build -cc --trace --top-module $(VSRC)/top.v $(VPP) $(CPP) \
	 $(addprefix -CFLAGS , $(CFLAGS)) $(addprefix -LDFLAGS , $(LDFLAGS)) \
	--Mdir $(OBJ_DIR) --exe -o $(abspath $(BIN))

#####################build 创建的 自动化verilator  .mk文件  运行################
#objmk: sim
	@#找不到makefile文件，因为.mk不叫makfile,-C就是对应的目录， 自动查找
	@#$(MAKE) -C $(OBJ_PATH)
	@#-f执行不改变环境变量， 还是当前目录，只不过进去执行了一下又出来，直接对应的是文件 而不是目录
#	$(MAKE)  -f $(OBJ_MK)

##################  运行 生成的  executable file #################### 注意，波形文件在当前MAKEFILE文件目录下
run: sim $(BIN)	$(SRC_AUTO_BIND)
	@$(BIN)

.PHONY: clean run
clean:
	-rm -f  *.o sim  all run

# rules for NVBoard
include $(NVBOARD_HOME)/scripts/nvboard.mk

include ../Makefile
