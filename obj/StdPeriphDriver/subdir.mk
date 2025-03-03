################################################################################
# MRS Version: 1.9.2
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../StdPeriphDriver/CH59x_adc.c \
../StdPeriphDriver/CH59x_clk.c \
../StdPeriphDriver/CH59x_flash.c \
../StdPeriphDriver/CH59x_gpio.c \
../StdPeriphDriver/CH59x_i2c.c \
../StdPeriphDriver/CH59x_lcd.c \
../StdPeriphDriver/CH59x_pwr.c \
../StdPeriphDriver/CH59x_sys.c \
../StdPeriphDriver/CH59x_uart1.c 

OBJS += \
./StdPeriphDriver/CH59x_adc.o \
./StdPeriphDriver/CH59x_clk.o \
./StdPeriphDriver/CH59x_flash.o \
./StdPeriphDriver/CH59x_gpio.o \
./StdPeriphDriver/CH59x_i2c.o \
./StdPeriphDriver/CH59x_lcd.o \
./StdPeriphDriver/CH59x_pwr.o \
./StdPeriphDriver/CH59x_sys.o \
./StdPeriphDriver/CH59x_uart1.o 

C_DEPS += \
./StdPeriphDriver/CH59x_adc.d \
./StdPeriphDriver/CH59x_clk.d \
./StdPeriphDriver/CH59x_flash.d \
./StdPeriphDriver/CH59x_gpio.d \
./StdPeriphDriver/CH59x_i2c.d \
./StdPeriphDriver/CH59x_lcd.d \
./StdPeriphDriver/CH59x_pwr.d \
./StdPeriphDriver/CH59x_sys.d \
./StdPeriphDriver/CH59x_uart1.d 


# Each subdirectory must supply rules for building sources it contributes
StdPeriphDriver/CH59x_adc.o: C:/Users/Administrator/Desktop/Wireless-switch-CH592/StdPeriphDriver/CH59x_adc.c
	@	@	riscv-none-elf-gcc -march=rv32imac -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common  -g -DCLK_OSC32K=0 -I"C:\Users\Administrator\Desktop\Wireless-switch-CH592\Startup" -I"C:\Users\Administrator\Desktop\Wireless-switch-CH592\APP\include" -I"C:\Users\Administrator\Desktop\Wireless-switch-CH592\Profile\include" -I"C:\Users\Administrator\Desktop\Wireless-switch-CH592\StdPeriphDriver\inc" -I"C:\Users\Administrator\Desktop\Wireless-switch-CH592\HAL\include" -I"C:\Users\Administrator\Desktop\Wireless-switch-CH592\Ld" -I"C:\Users\Administrator\Desktop\Wireless-switch-CH592\LIB" -I"C:\Users\Administrator\Desktop\Wireless-switch-CH592\RVMSIS" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
StdPeriphDriver/CH59x_clk.o: C:/Users/Administrator/Desktop/Wireless-switch-CH592/StdPeriphDriver/CH59x_clk.c
	@	@	riscv-none-elf-gcc -march=rv32imac -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common  -g -DCLK_OSC32K=0 -I"C:\Users\Administrator\Desktop\Wireless-switch-CH592\Startup" -I"C:\Users\Administrator\Desktop\Wireless-switch-CH592\APP\include" -I"C:\Users\Administrator\Desktop\Wireless-switch-CH592\Profile\include" -I"C:\Users\Administrator\Desktop\Wireless-switch-CH592\StdPeriphDriver\inc" -I"C:\Users\Administrator\Desktop\Wireless-switch-CH592\HAL\include" -I"C:\Users\Administrator\Desktop\Wireless-switch-CH592\Ld" -I"C:\Users\Administrator\Desktop\Wireless-switch-CH592\LIB" -I"C:\Users\Administrator\Desktop\Wireless-switch-CH592\RVMSIS" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
StdPeriphDriver/CH59x_flash.o: C:/Users/Administrator/Desktop/Wireless-switch-CH592/StdPeriphDriver/CH59x_flash.c
	@	@	riscv-none-elf-gcc -march=rv32imac -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common  -g -DCLK_OSC32K=0 -I"C:\Users\Administrator\Desktop\Wireless-switch-CH592\Startup" -I"C:\Users\Administrator\Desktop\Wireless-switch-CH592\APP\include" -I"C:\Users\Administrator\Desktop\Wireless-switch-CH592\Profile\include" -I"C:\Users\Administrator\Desktop\Wireless-switch-CH592\StdPeriphDriver\inc" -I"C:\Users\Administrator\Desktop\Wireless-switch-CH592\HAL\include" -I"C:\Users\Administrator\Desktop\Wireless-switch-CH592\Ld" -I"C:\Users\Administrator\Desktop\Wireless-switch-CH592\LIB" -I"C:\Users\Administrator\Desktop\Wireless-switch-CH592\RVMSIS" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
StdPeriphDriver/CH59x_gpio.o: C:/Users/Administrator/Desktop/Wireless-switch-CH592/StdPeriphDriver/CH59x_gpio.c
	@	@	riscv-none-elf-gcc -march=rv32imac -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common  -g -DCLK_OSC32K=0 -I"C:\Users\Administrator\Desktop\Wireless-switch-CH592\Startup" -I"C:\Users\Administrator\Desktop\Wireless-switch-CH592\APP\include" -I"C:\Users\Administrator\Desktop\Wireless-switch-CH592\Profile\include" -I"C:\Users\Administrator\Desktop\Wireless-switch-CH592\StdPeriphDriver\inc" -I"C:\Users\Administrator\Desktop\Wireless-switch-CH592\HAL\include" -I"C:\Users\Administrator\Desktop\Wireless-switch-CH592\Ld" -I"C:\Users\Administrator\Desktop\Wireless-switch-CH592\LIB" -I"C:\Users\Administrator\Desktop\Wireless-switch-CH592\RVMSIS" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
StdPeriphDriver/CH59x_i2c.o: C:/Users/Administrator/Desktop/Wireless-switch-CH592/StdPeriphDriver/CH59x_i2c.c
	@	@	riscv-none-elf-gcc -march=rv32imac -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common  -g -DCLK_OSC32K=0 -I"C:\Users\Administrator\Desktop\Wireless-switch-CH592\Startup" -I"C:\Users\Administrator\Desktop\Wireless-switch-CH592\APP\include" -I"C:\Users\Administrator\Desktop\Wireless-switch-CH592\Profile\include" -I"C:\Users\Administrator\Desktop\Wireless-switch-CH592\StdPeriphDriver\inc" -I"C:\Users\Administrator\Desktop\Wireless-switch-CH592\HAL\include" -I"C:\Users\Administrator\Desktop\Wireless-switch-CH592\Ld" -I"C:\Users\Administrator\Desktop\Wireless-switch-CH592\LIB" -I"C:\Users\Administrator\Desktop\Wireless-switch-CH592\RVMSIS" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
StdPeriphDriver/CH59x_lcd.o: C:/Users/Administrator/Desktop/Wireless-switch-CH592/StdPeriphDriver/CH59x_lcd.c
	@	@	riscv-none-elf-gcc -march=rv32imac -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common  -g -DCLK_OSC32K=0 -I"C:\Users\Administrator\Desktop\Wireless-switch-CH592\Startup" -I"C:\Users\Administrator\Desktop\Wireless-switch-CH592\APP\include" -I"C:\Users\Administrator\Desktop\Wireless-switch-CH592\Profile\include" -I"C:\Users\Administrator\Desktop\Wireless-switch-CH592\StdPeriphDriver\inc" -I"C:\Users\Administrator\Desktop\Wireless-switch-CH592\HAL\include" -I"C:\Users\Administrator\Desktop\Wireless-switch-CH592\Ld" -I"C:\Users\Administrator\Desktop\Wireless-switch-CH592\LIB" -I"C:\Users\Administrator\Desktop\Wireless-switch-CH592\RVMSIS" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
StdPeriphDriver/CH59x_pwr.o: C:/Users/Administrator/Desktop/Wireless-switch-CH592/StdPeriphDriver/CH59x_pwr.c
	@	@	riscv-none-elf-gcc -march=rv32imac -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common  -g -DCLK_OSC32K=0 -I"C:\Users\Administrator\Desktop\Wireless-switch-CH592\Startup" -I"C:\Users\Administrator\Desktop\Wireless-switch-CH592\APP\include" -I"C:\Users\Administrator\Desktop\Wireless-switch-CH592\Profile\include" -I"C:\Users\Administrator\Desktop\Wireless-switch-CH592\StdPeriphDriver\inc" -I"C:\Users\Administrator\Desktop\Wireless-switch-CH592\HAL\include" -I"C:\Users\Administrator\Desktop\Wireless-switch-CH592\Ld" -I"C:\Users\Administrator\Desktop\Wireless-switch-CH592\LIB" -I"C:\Users\Administrator\Desktop\Wireless-switch-CH592\RVMSIS" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
StdPeriphDriver/CH59x_sys.o: C:/Users/Administrator/Desktop/Wireless-switch-CH592/StdPeriphDriver/CH59x_sys.c
	@	@	riscv-none-elf-gcc -march=rv32imac -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common  -g -DCLK_OSC32K=0 -I"C:\Users\Administrator\Desktop\Wireless-switch-CH592\Startup" -I"C:\Users\Administrator\Desktop\Wireless-switch-CH592\APP\include" -I"C:\Users\Administrator\Desktop\Wireless-switch-CH592\Profile\include" -I"C:\Users\Administrator\Desktop\Wireless-switch-CH592\StdPeriphDriver\inc" -I"C:\Users\Administrator\Desktop\Wireless-switch-CH592\HAL\include" -I"C:\Users\Administrator\Desktop\Wireless-switch-CH592\Ld" -I"C:\Users\Administrator\Desktop\Wireless-switch-CH592\LIB" -I"C:\Users\Administrator\Desktop\Wireless-switch-CH592\RVMSIS" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
StdPeriphDriver/CH59x_uart1.o: C:/Users/Administrator/Desktop/Wireless-switch-CH592/StdPeriphDriver/CH59x_uart1.c
	@	@	riscv-none-elf-gcc -march=rv32imac -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common  -g -DCLK_OSC32K=0 -I"C:\Users\Administrator\Desktop\Wireless-switch-CH592\Startup" -I"C:\Users\Administrator\Desktop\Wireless-switch-CH592\APP\include" -I"C:\Users\Administrator\Desktop\Wireless-switch-CH592\Profile\include" -I"C:\Users\Administrator\Desktop\Wireless-switch-CH592\StdPeriphDriver\inc" -I"C:\Users\Administrator\Desktop\Wireless-switch-CH592\HAL\include" -I"C:\Users\Administrator\Desktop\Wireless-switch-CH592\Ld" -I"C:\Users\Administrator\Desktop\Wireless-switch-CH592\LIB" -I"C:\Users\Administrator\Desktop\Wireless-switch-CH592\RVMSIS" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

