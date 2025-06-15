# # We try to detect the OS we are running on, and adjust commands as needed
# ifeq ($(OS),Windows_NT)
#     TARGET_TEST_EXTENSION=.exe
#     LD_WRAP=true
# else
#     TARGET_TEST_EXTENSION=.out
#     UNAME_S := $(shell uname -s)
#     ifeq ($(UNAME_S),Linux)
#         LD_WRAP=true
#     endif
#     ifeq ($(UNAME_S),Darwin)
#         LD_WRAP=false
#     endif
# endif

#Compiler executables to use
CC=arm-none-eabi-gcc
LD=arm-none-eabi-ld 
AR=arm-none-eabi-ar
AS=arm-none-eabi-as
CP=arm-none-eabi-objcopy
OD=arm-none-eabi-objdump

# Target file name
TARGET_BASE = robot
TARGET_ELF = bin/$(TARGET_BASE).elf
TARGET_HEX = bin/$(TARGET_BASE).hex
TARGET_MAP = bin/$(TARGET_BASE).map

# Processor and instruction specifications
CPU = cortex-m4
MCU = STM32F446xx 
MCFLAGS = -mcpu=$(CPU) -mthumb -mlittle-endian -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb-interwork
OPTIMIZE = -Os
WRAP_PRINTF = -Wl,-wrap,printf -fno-builtin-printf

# Location of dependencies
STM32CUBE_ROOT = ../libraries/STM32Cube_F4_FW
CMSIS_ROOT = ../libraries/CMSIS_5
RTOS_ROOT = ../libraries/CMSIS-FreeRTOS
UNITY_ROOT = ../libraries/Unity

# List of build directories
BUILD_DIR = build build/stm32f4_HAL build/FreeRTOS
BIN_DIR = bin 

# Source files
SRCDIR = src
SRCSTMCUBEDIR = $(STM32CUBE_ROOT)/Drivers/STM32F4xx_HAL_Driver/Src
MPU6050LIB_ROOT = TM_MPU6050

# Source to compile only for target processor
SRC_STM = \
	$(SRCDIR)/stm32f4xx_it.c \
	$(SRCDIR)/system_stm32f4xx.c \
	$(SRCDIR)/main.c \
	$(SRCDIR)/uart.c \
	$(SRCDIR)/cmd_task.c\
	$(SRCDIR)/heartbeat_task.c \
	$(SRCDIR)/cmd_line_buffer.c \
	$(SRCDIR)/cmd_parser.c \
	$(SRCDIR)/heartbeat_cmd.c \
	$(SRCDIR)/controller.c \
	$(SRCDIR)/controller_cmd.c \
	$(SRCDIR)/motor.c\
	$(SRCDIR)/data_logging.c\
	$(SRCDIR)/IMU.c\
	$(SRCDIR)/control_task.c

	SRC_MPU6050LIB = \
	$(MPU6050LIB_ROOT)/tm_stm32_gpio.c \
	$(MPU6050LIB_ROOT)/tm_stm32_i2c.c \
	$(MPU6050LIB_ROOT)/tm_stm32_mpu6050.c	
	
# Assembly source files
A_SRC = \
	$(SRCDIR)/startup_stm32f446xx.S

# Source for STM32F4 Cube HAL Driver library
SRC_STM_CUBE = \
	$(SRCSTMCUBEDIR)/stm32f4xx_hal.c \
	$(SRCSTMCUBEDIR)/stm32f4xx_hal_dma.c \
	$(SRCSTMCUBEDIR)/stm32f4xx_hal_adc.c \
	$(SRCSTMCUBEDIR)/stm32f4xx_hal_adc_ex.c \
	$(SRCSTMCUBEDIR)/stm32f4xx_hal_gpio.c \
	$(SRCSTMCUBEDIR)/stm32f4xx_ll_gpio.c \
	$(SRCSTMCUBEDIR)/stm32f4xx_ll_usart.c \
	$(SRCSTMCUBEDIR)/stm32f4xx_ll_dma.c \
	$(SRCSTMCUBEDIR)/stm32f4xx_ll_rcc.c \
	$(SRCSTMCUBEDIR)/stm32f4xx_hal_i2c.c \
	$(SRCSTMCUBEDIR)/stm32f4xx_hal_i2c_ex.c \
	$(SRCSTMCUBEDIR)/stm32f4xx_hal_tim.c \
	$(SRCSTMCUBEDIR)/stm32f4xx_hal_tim_ex.c \
	$(SRCSTMCUBEDIR)/stm32f4xx_hal_rtc.c \
	$(SRCSTMCUBEDIR)/stm32f4xx_hal_rcc.c \
	$(SRCSTMCUBEDIR)/stm32f4xx_hal_rcc_ex.c \
	$(SRCSTMCUBEDIR)/stm32f4xx_hal_pwr.c \
	$(SRCSTMCUBEDIR)/stm32f4xx_hal_pwr_ex.c \
	$(SRCSTMCUBEDIR)/stm32f4xx_hal_cortex.c \
	$(SRCSTMCUBEDIR)/stm32f4xx_hal_spi.c \
	$(SRCSTMCUBEDIR)/stm32f4xx_hal_dac.c \
	$(SRCSTMCUBEDIR)/stm32f4xx_hal_dac_ex.c \
	$(SRCSTMCUBEDIR)/stm32f4xx_hal_can.c

# Source for FreeRTOSv10 CMSISv2
SRC_RTOS = \
	$(RTOS_ROOT)/Source/croutine.c \
	$(RTOS_ROOT)/Source/event_groups.c \
	$(RTOS_ROOT)/Source/list.c \
	$(RTOS_ROOT)/Source/queue.c \
	$(RTOS_ROOT)/Source/tasks.c \
	$(RTOS_ROOT)/Source/timers.c \
	$(RTOS_ROOT)/Source/stream_buffer.c \
	$(RTOS_ROOT)/CMSIS/RTOS2/FreeRTOS/Source/cmsis_os2.c \
	$(RTOS_ROOT)/CMSIS/RTOS2/FreeRTOS/Source/ARM/clib_arm.c \
	$(RTOS_ROOT)/CMSIS/RTOS2/FreeRTOS/Source/os_systick.c \
	$(SRCDIR)/heap_useNewlib.c \
	RTE/_Target_1/port.c

SRC_TARGET = $(SRC_STM)


# Extract directory information for RTOS and test source files
SRCRTOSDIR = $(dir $(SRC_RTOS))
	
INC_STM_CUBE = \
	$(STM32CUBE_ROOT)/Drivers/STM32F4xx_HAL_Driver/Inc/ \
	$(STM32CUBE_ROOT)/Drivers/CMSIS/Include/ \
	$(STM32CUBE_ROOT)/Drivers/CMSIS/DSP/Include\
	$(STM32CUBE_ROOT)/Drivers/CMSIS/Device/ST/STM32F4xx/Include/

INC_RTOS = \
	$(RTOS_ROOT)/Source/include \
	$(RTOS_ROOT)/CMSIS/RTOS2/FreeRTOS/Include \
	$(RTOS_ROOT)/Source/portable/GCC/ARM_CM4F \
	$(CMSIS_ROOT)/CMSIS/Include \
	$(CMSIS_ROOT)/CMSIS/Core/Include \
	$(CMSIS_ROOT)/CMSIS/RTOS2/Include \
	$(CMSIS_ROOT)/Device/ARM/ARMCM4/Include \
	RTE/RTOS \
	RTE/_Target_1

INC_STM = \
	.\
	src \
	$(INC_COMMON) \
	$(INC_STM_CUBE) \
	$(INC_RTOS)\
	$(MPU6050LIB_ROOT)



TARGET_INCLUDES = $(addprefix -I,$(INC_STM))

# List the output object (.o) files for the compiler to build if any file changes
TARGET_OBJ =  $(patsubst $(SRCDIR)/%.c, build/%.o, $(SRC_TARGET))
TARGET_OBJ += $(patsubst $(SRCDIR)/%.S, build/%.o, $(A_SRC))
TARGET_OBJ += $(patsubst $(SRCSTMCUBEDIR)/%.c, build/stm32f4_HAL/%.o, $(SRC_STM_CUBE))
TARGET_OBJ += $(patsubst %.c, build/FreeRTOS/%.o, $(notdir $(SRC_RTOS)))
TARGET_OBJ +=  $(patsubst $(MPU6050LIB_ROOT)/%.c, build/%.o, $(SRC_MPU6050LIB))

# Compiler Options
# CFLAGS += -std=c99 #Breaks tests on Linux due to removal of fileno() function from stdio
CFLAGS += -MD #Generate dependency '.d' files
CFLAGS += '-D__WEAK=__attribute__((weak))'
CFLAGS += -D$(MCU)
CFLAGS += -DARM_MATH_CM4
CFLAGS += -DUSE_FULL_LL_DRIVER
# Disable specific compiler warnings
CFLAGS += -Wno-comment
# CFLAGS += -Wno-parentheses-equality #Commented out due to not existing in clang, only in gcc
CFLAGS += -Wno-int-to-pointer-cast
CFLAGS += -Wno-unknown-pragmas
CFLAGS += -Wno-maybe-uninitialized
CFLAGS += -Wno-switch-default
CFLAGS += -Wno-char-subscripts
# Enable lots of compiler warnings and errors
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -Wpointer-arith
CFLAGS += -Wwrite-strings
CFLAGS += -Wunreachable-code
CFLAGS += -Werror-implicit-function-declaration
CFLAGS += -Wstrict-prototypes
CFLAGS += -Wundef
CFLAGS += -Wpointer-to-int-cast
CFLAGS += -Wshadow
CFLAGS += -Wfatal-errors
# added due to an error on gcc 10+ where a value is defined more then once without extern def.
CFLAGS += -fcommon  

ALL_CFLAGS = $(CFLAGS) $(MCFLAGS) $(WRAP_PRINTF) $(OPTIMIZE)

# Remove full suite of system functions, instead use newlib 'nano' to save program memory
NEWLIB_NANO = \
    --specs=nosys.specs \
	--specs=nano.specs
# Tell nano functions such as printf() to use floating point support
PRINTF_LIB_FLOAT = \
	-u _printf_float \
	-u _scanf_float
MATH_LIB = -lm

# Linker flags
LDFLAGS = -D$(MCU) -Wl,-Map=$(TARGET_MAP),--cref
LDFLAGS += $(NEWLIB_NANO) $(PRINTF_LIB_FLOAT) $(MATH_LIB)
LDFLAGS += -Wl,--print-memory-usage
LDFLAGS += -T STM32F446RETx_FLASH.ld
LDFLAGS += $(STM32CUBE_ROOT)/Drivers/CMSIS/Lib/GCC/libarm_cortexM4lf_math.a

# Flags for putting code under test
MISC_TEST = -DUNITY_FLOAT_PRECISION=0.0001f
ifeq ($(LD_WRAP),true)
	MISC_TEST += -Wl,-wrap,cmd_parse
else
	MISC_TEST += -DNO_LD_WRAP
endif

# Tell the compiler where to search for any file ending in '.c' if the path isn't given
VPATH = $(SRCDIR):$(SRCSTMCUBEDIR):$(SRCDIR):$(SRCRTOSDIR):$(MPU6050LIB_ROOT)

# Function to compile objects (.o) from target source (.c / .S) files for each build folder.
# Allows the makefile to compile user code, HAL library and RTOS from the search path vpath
# and build the output into seperate folders.
# Called by 'foreach' to write multiple targets cleanly
define make-goal
$1/%.o: %.c
	@echo +++TARGET+++ Compiling: [$$<]
	@$(CC) $(TARGET_INCLUDES) $(ALL_CFLAGS) -c $$< -o $$@

$1/%.o: %.S
	@echo +++TARGET+++ Assembling: [$$<]
	@$(CC) $(TARGET_INCLUDES) $(ALL_CFLAGS) -c $$< -o $$@
endef

$(foreach bdir,$(BUILD_DIR),$(eval $(call make-goal,$(bdir))))

# Function to compile objects (.o) from test source (.c) files for each source folder.
# Allows the makefile to know the directory path to the exact source files specified
# Necessary as VPATH would tell the compiler to use 
# the real HAL library e.g. ISO:/libraries/STM32Cube_F4/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_tim.c 
# when we require use of the mock HAL library e.g. mock/stm32f4xx_hal_tim.c
define make-test-goal
test/build/%.o: $1/%.c
	@echo +++TEST+++ Compiling: [$$<]
	@gcc -g -O0 $(MISC_TEST) $(CFLAGS) -Wno-double-promotion $(TEST_INCLUDES) -c $$< -o $$@
endef
$(foreach sdir,$(SRCTESTDIR),$(eval $(call make-test-goal,$(sdir))))

#################################################
# Targets for the makefile
#################################################

all: checkdirs default 

default: checkdirs test_only target_only
	- ./$(TARGET_TEST)

#################################################
# Test
#################################################

test: checkdirs test_only
	- ./$(TARGET_TEST) -v

test_only: $(TEST_OBJ)
	@echo +++TEST+++ Linking compiled code into test binary: $(TARGET_TEST)
	@gcc -O0 $(MISC_TEST) $^ $(MATH_LIB) -o $(TARGET_TEST)

clean_test:
	rm -f $(TARGET_TEST)
	rm -f $(TEST_OBJ)
	rm -f $(TEST_OBJ:.o=.d)

#################################################
# Program
#################################################

program: checkdirs target_only
	@echo +++ Programming STM32 via ST-Link using OpenOCD
	@echo +++ 
	@openocd -d1 -f interface/stlink-v2-1.cfg -f target/stm32f4x.cfg -c "program $(TARGET_ELF) verify reset exit"

target_only: $(TARGET_OBJ)
	@echo +++TARGET+++ Linking compiled code into target binary: $(TARGET_ELF)
	@$(CC)  $(MCFLAGS) $(OPTIMIZE) $^ $(LDFLAGS) -o $(TARGET_ELF)
	arm-none-eabi-size $(TARGET_ELF)
	@echo +++ Build complete

clean_stm:
	rm -f $(TARGET_ELF) $(TARGET_MAP)
	rm -f $(TARGET_OBJ)
	rm -f $(TARGET_OBJ:.o=.d)

#################################################
# Clean and misc operations
#################################################

clean: clean_test clean_stm

checkdirs: $(BUILD_DIR) $(BUILD_TEST_DIR) $(BIN_DIR)

#################################################
# Ensure objects get turned into dependency files
#################################################

-include $(TARGET_OBJ:.o=.d)
-include $(TEST_OBJ:.o=.d)

# If build directories don't exist, create them
$(BUILD_DIR) $(BUILD_TEST_DIR) $(BIN_DIR):
ifeq ($(OS),Windows_NT)
	@echo "Making build directory: $@"
	@mkdir "$@"
else
	@echo "Making build directory: $@"
	@mkdir -p "$@"
endif