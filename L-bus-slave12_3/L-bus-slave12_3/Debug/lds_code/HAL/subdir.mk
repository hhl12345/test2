################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lds_code/HAL/lds_hal_adc.c \
../lds_code/HAL/lds_hal_can.c \
../lds_code/HAL/lds_hal_flash.c \
../lds_code/HAL/lds_hal_gpio.c \
../lds_code/HAL/lds_hal_i2c.c \
../lds_code/HAL/lds_hal_iwdg.c \
../lds_code/HAL/lds_hal_pwm.c \
../lds_code/HAL/lds_hal_timer.c \
../lds_code/HAL/lds_hal_uart.c \
../lds_code/HAL/lds_hal_watchDog.c 

OBJS += \
./lds_code/HAL/lds_hal_adc.o \
./lds_code/HAL/lds_hal_can.o \
./lds_code/HAL/lds_hal_flash.o \
./lds_code/HAL/lds_hal_gpio.o \
./lds_code/HAL/lds_hal_i2c.o \
./lds_code/HAL/lds_hal_iwdg.o \
./lds_code/HAL/lds_hal_pwm.o \
./lds_code/HAL/lds_hal_timer.o \
./lds_code/HAL/lds_hal_uart.o \
./lds_code/HAL/lds_hal_watchDog.o 

C_DEPS += \
./lds_code/HAL/lds_hal_adc.d \
./lds_code/HAL/lds_hal_can.d \
./lds_code/HAL/lds_hal_flash.d \
./lds_code/HAL/lds_hal_gpio.d \
./lds_code/HAL/lds_hal_i2c.d \
./lds_code/HAL/lds_hal_iwdg.d \
./lds_code/HAL/lds_hal_pwm.d \
./lds_code/HAL/lds_hal_timer.d \
./lds_code/HAL/lds_hal_uart.d \
./lds_code/HAL/lds_hal_watchDog.d 


# Each subdirectory must supply rules for building sources it contributes
lds_code/HAL/lds_hal_adc.o: ../lds_code/HAL/lds_hal_adc.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F072xB -DDEBUG -c -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -I../lds_code/timerApp -I../lds_code/HAL -I../lds_code/motionSeneor -I../lds_code/lightSeneor -I../lds_code/ledApp -I../lds_code/LBus -I../lds_code/config -I../lds_code/buttonApp -I../lds_code/app -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"lds_code/HAL/lds_hal_adc.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
lds_code/HAL/lds_hal_can.o: ../lds_code/HAL/lds_hal_can.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F072xB -DDEBUG -c -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -I../lds_code/timerApp -I../lds_code/HAL -I../lds_code/motionSeneor -I../lds_code/lightSeneor -I../lds_code/ledApp -I../lds_code/LBus -I../lds_code/config -I../lds_code/buttonApp -I../lds_code/app -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"lds_code/HAL/lds_hal_can.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
lds_code/HAL/lds_hal_flash.o: ../lds_code/HAL/lds_hal_flash.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F072xB -DDEBUG -c -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -I../lds_code/timerApp -I../lds_code/HAL -I../lds_code/motionSeneor -I../lds_code/lightSeneor -I../lds_code/ledApp -I../lds_code/LBus -I../lds_code/config -I../lds_code/buttonApp -I../lds_code/app -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"lds_code/HAL/lds_hal_flash.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
lds_code/HAL/lds_hal_gpio.o: ../lds_code/HAL/lds_hal_gpio.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F072xB -DDEBUG -c -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -I../lds_code/timerApp -I../lds_code/HAL -I../lds_code/motionSeneor -I../lds_code/lightSeneor -I../lds_code/ledApp -I../lds_code/LBus -I../lds_code/config -I../lds_code/buttonApp -I../lds_code/app -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"lds_code/HAL/lds_hal_gpio.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
lds_code/HAL/lds_hal_i2c.o: ../lds_code/HAL/lds_hal_i2c.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F072xB -DDEBUG -c -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -I../lds_code/timerApp -I../lds_code/HAL -I../lds_code/motionSeneor -I../lds_code/lightSeneor -I../lds_code/ledApp -I../lds_code/LBus -I../lds_code/config -I../lds_code/buttonApp -I../lds_code/app -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"lds_code/HAL/lds_hal_i2c.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
lds_code/HAL/lds_hal_iwdg.o: ../lds_code/HAL/lds_hal_iwdg.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F072xB -DDEBUG -c -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -I../lds_code/timerApp -I../lds_code/HAL -I../lds_code/motionSeneor -I../lds_code/lightSeneor -I../lds_code/ledApp -I../lds_code/LBus -I../lds_code/config -I../lds_code/buttonApp -I../lds_code/app -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"lds_code/HAL/lds_hal_iwdg.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
lds_code/HAL/lds_hal_pwm.o: ../lds_code/HAL/lds_hal_pwm.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F072xB -DDEBUG -c -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -I../lds_code/timerApp -I../lds_code/HAL -I../lds_code/motionSeneor -I../lds_code/lightSeneor -I../lds_code/ledApp -I../lds_code/LBus -I../lds_code/config -I../lds_code/buttonApp -I../lds_code/app -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"lds_code/HAL/lds_hal_pwm.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
lds_code/HAL/lds_hal_timer.o: ../lds_code/HAL/lds_hal_timer.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F072xB -DDEBUG -c -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -I../lds_code/timerApp -I../lds_code/HAL -I../lds_code/motionSeneor -I../lds_code/lightSeneor -I../lds_code/ledApp -I../lds_code/LBus -I../lds_code/config -I../lds_code/buttonApp -I../lds_code/app -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"lds_code/HAL/lds_hal_timer.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
lds_code/HAL/lds_hal_uart.o: ../lds_code/HAL/lds_hal_uart.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F072xB -DDEBUG -c -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -I../lds_code/timerApp -I../lds_code/HAL -I../lds_code/motionSeneor -I../lds_code/lightSeneor -I../lds_code/ledApp -I../lds_code/LBus -I../lds_code/config -I../lds_code/buttonApp -I../lds_code/app -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"lds_code/HAL/lds_hal_uart.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
lds_code/HAL/lds_hal_watchDog.o: ../lds_code/HAL/lds_hal_watchDog.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F072xB -DDEBUG -c -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -I../lds_code/timerApp -I../lds_code/HAL -I../lds_code/motionSeneor -I../lds_code/lightSeneor -I../lds_code/ledApp -I../lds_code/LBus -I../lds_code/config -I../lds_code/buttonApp -I../lds_code/app -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"lds_code/HAL/lds_hal_watchDog.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

