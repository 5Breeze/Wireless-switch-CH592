################################################################################
# MRS Version: 1.9.2
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include StdPeriphDriver/subdir.mk
-include Startup/subdir.mk
-include RVMSIS/subdir.mk
-include Profile/subdir.mk
-include LIB/subdir.mk
-include HAL/subdir.mk
-include APP/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
SECONDARY_FLASH += \
Broadcaster-CH592.hex \

SECONDARY_LIST += \
Broadcaster-CH592.lst \

SECONDARY_SIZE += \
Broadcaster-CH592.siz \


# All Target
all: Broadcaster-CH592.elf secondary-outputs

# Tool invocations
Broadcaster-CH592.elf: $(OBJS) $(USER_OBJS)
	@	@	riscv-none-elf-gcc -march=rv32imac -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common  -g -T "C:\Users\Administrator\Desktop\Wireless-switch-CH592\Ld\Link.ld" -nostartfiles -Xlinker --gc-sections -L"../" -L"C:\Users\Administrator\Desktop\Wireless-switch-CH592\LIB" -L"C:\Users\Administrator\Desktop\Wireless-switch-CH592\StdPeriphDriver" -Xlinker --print-memory-usage -Wl,-Map,"Broadcaster-CH592.map" --specs=nano.specs --specs=nosys.specs  -o "Broadcaster-CH592.elf" $(OBJS) $(USER_OBJS) $(LIBS) -lprintfloat
	@	@
Broadcaster-CH592.hex: Broadcaster-CH592.elf
	@	riscv-none-elf-objcopy -O ihex "Broadcaster-CH592.elf"  "Broadcaster-CH592.hex"
	@	@
Broadcaster-CH592.lst: Broadcaster-CH592.elf
	@	riscv-none-elf-objdump --source --all-headers --demangle --line-numbers --wide "Broadcaster-CH592.elf" > "Broadcaster-CH592.lst"
	@	@
Broadcaster-CH592.siz: Broadcaster-CH592.elf
	@	riscv-none-elf-size --format=berkeley "Broadcaster-CH592.elf"
	@	@
# Other Targets
clean:
	-$(RM) $(ASM_UPPER_DEPS)$(OBJS)$(SECONDARY_FLASH)$(SECONDARY_LIST)$(SECONDARY_SIZE)$(ASM_DEPS)$(S_DEPS)$(S_UPPER_DEPS)$(C_DEPS) Broadcaster-CH592.elf
	-@
secondary-outputs: $(SECONDARY_FLASH) $(SECONDARY_LIST) $(SECONDARY_SIZE)

.PHONY: all clean dependents

-include ../makefile.targets
