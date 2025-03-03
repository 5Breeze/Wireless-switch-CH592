################################################################################
# MRS Version: 1.9.2
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/MCU.c \
../HAL/RTC.c \
../HAL/SLEEP.c 

OBJS += \
./HAL/MCU.o \
./HAL/RTC.o \
./HAL/SLEEP.o 

C_DEPS += \
./HAL/MCU.d \
./HAL/RTC.d \
./HAL/SLEEP.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/MCU.o: C:/Users/Administrator/Desktop/Wireless-switch-CH592/HAL/MCU.c
	@	@	riscv-none-elf-gcc -march=rv32imac -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common  -g -DCLK_OSC32K=0 -I"C:\Users\Administrator\Desktop\Wireless-switch-CH592\Startup" -I"C:\Users\Administrator\Desktop\Wireless-switch-CH592\APP\include" -I"C:\Users\Administrator\Desktop\Wireless-switch-CH592\Profile\include" -I"C:\Users\Administrator\Desktop\Wireless-switch-CH592\StdPeriphDriver\inc" -I"C:\Users\Administrator\Desktop\Wireless-switch-CH592\HAL\include" -I"C:\Users\Administrator\Desktop\Wireless-switch-CH592\Ld" -I"C:\Users\Administrator\Desktop\Wireless-switch-CH592\LIB" -I"C:\Users\Administrator\Desktop\Wireless-switch-CH592\RVMSIS" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
HAL/RTC.o: C:/Users/Administrator/Desktop/Wireless-switch-CH592/HAL/RTC.c
	@	@	riscv-none-elf-gcc -march=rv32imac -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common  -g -DCLK_OSC32K=0 -I"C:\Users\Administrator\Desktop\Wireless-switch-CH592\Startup" -I"C:\Users\Administrator\Desktop\Wireless-switch-CH592\APP\include" -I"C:\Users\Administrator\Desktop\Wireless-switch-CH592\Profile\include" -I"C:\Users\Administrator\Desktop\Wireless-switch-CH592\StdPeriphDriver\inc" -I"C:\Users\Administrator\Desktop\Wireless-switch-CH592\HAL\include" -I"C:\Users\Administrator\Desktop\Wireless-switch-CH592\Ld" -I"C:\Users\Administrator\Desktop\Wireless-switch-CH592\LIB" -I"C:\Users\Administrator\Desktop\Wireless-switch-CH592\RVMSIS" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
HAL/SLEEP.o: C:/Users/Administrator/Desktop/Wireless-switch-CH592/HAL/SLEEP.c
	@	@	riscv-none-elf-gcc -march=rv32imac -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common  -g -DCLK_OSC32K=0 -I"C:\Users\Administrator\Desktop\Wireless-switch-CH592\Startup" -I"C:\Users\Administrator\Desktop\Wireless-switch-CH592\APP\include" -I"C:\Users\Administrator\Desktop\Wireless-switch-CH592\Profile\include" -I"C:\Users\Administrator\Desktop\Wireless-switch-CH592\StdPeriphDriver\inc" -I"C:\Users\Administrator\Desktop\Wireless-switch-CH592\HAL\include" -I"C:\Users\Administrator\Desktop\Wireless-switch-CH592\Ld" -I"C:\Users\Administrator\Desktop\Wireless-switch-CH592\LIB" -I"C:\Users\Administrator\Desktop\Wireless-switch-CH592\RVMSIS" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

