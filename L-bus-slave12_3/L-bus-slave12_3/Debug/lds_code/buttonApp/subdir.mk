################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lds_code/buttonApp/lds_buttonApp.c 

OBJS += \
./lds_code/buttonApp/lds_buttonApp.o 

C_DEPS += \
./lds_code/buttonApp/lds_buttonApp.d 


# Each subdirectory must supply rules for building sources it contributes
lds_code/buttonApp/lds_buttonApp.o: ../lds_code/buttonApp/lds_buttonApp.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F072xB -DDEBUG -c -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -I../lds_code/timerApp -I../lds_code/HAL -I../lds_code/motionSeneor -I../lds_code/lightSeneor -I../lds_code/ledApp -I../lds_code/LBus -I../lds_code/config -I../lds_code/buttonApp -I../lds_code/app -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"lds_code/buttonApp/lds_buttonApp.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

