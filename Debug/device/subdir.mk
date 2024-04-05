################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../device/system_LPC804.c 

C_DEPS += \
./device/system_LPC804.d 

OBJS += \
./device/system_LPC804.o 


# Each subdirectory must supply rules for building sources it contributes
device/%.o: ../device/%.c device/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DCPU_LPC804M101JDH24 -DCPU_LPC804M101JDH24_cm0plus -DSDK_OS_BAREMETAL -DSDK_DEBUGCONSOLE=1 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -I"/home/elejandc/Documents/MCUXpresso_11.8.0_1165/workspace/Pad3/board" -I"/home/elejandc/Documents/MCUXpresso_11.8.0_1165/workspace/Pad3/source" -I"/home/elejandc/Documents/MCUXpresso_11.8.0_1165/workspace/Pad3/drivers" -I"/home/elejandc/Documents/MCUXpresso_11.8.0_1165/workspace/Pad3/CMSIS" -I"/home/elejandc/Documents/MCUXpresso_11.8.0_1165/workspace/Pad3/device" -I"/home/elejandc/Documents/MCUXpresso_11.8.0_1165/workspace/Pad3/component/uart" -I"/home/elejandc/Documents/MCUXpresso_11.8.0_1165/workspace/Pad3/utilities" -O0 -fno-common -g3 -Wall -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-device

clean-device:
	-$(RM) ./device/system_LPC804.d ./device/system_LPC804.o

.PHONY: clean-device

