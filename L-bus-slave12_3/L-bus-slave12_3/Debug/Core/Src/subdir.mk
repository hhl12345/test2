################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/can.c \
../Core/Src/gpio.c \
../Core/Src/i2c.c \
../Core/Src/iwdg.c \
../Core/Src/main.c \
../Core/Src/retarget.c \
../Core/Src/stm32f0xx_hal_msp.c \
../Core/Src/stm32f0xx_it.c \
../Core/Src/sysmem.c \
../Core/Src/system_stm32f0xx.c \
../Core/Src/tim.c \
../Core/Src/usart.c 

OBJS += \
./Core/Src/can.o \
./Core/Src/gpio.o \
./Core/Src/i2c.o \
./Core/Src/iwdg.o \
./Core/Src/main.o \
./Core/Src/retarget.o \
./Core/Src/stm32f0xx_hal_msp.o \
./Core/Src/stm32f0xx_it.o \
./Core/Src/sysmem.o \
./Core/Src/system_stm32f0xx.o \
./Core/Src/tim.o \
./Core/Src/usart.o 

C_DEPS += \
./Core/Src/can.d \
./Core/Src/gpio.d \
./Core/Src/i2c.d \
./Core/Src/iwdg.d \
./Core/Src/main.d \
./Core/Src/retarget.d \
./Core/Src/stm32f0xx_hal_msp.d \
./Core/Src/stm32f0xx_it.d \
./Core/Src/sysmem.d \
./Core/Src/system_stm32f0xx.d \
./Core/Src/tim.d \
./Core/Src/usart.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/can.o: ../Core/Src/can.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F072xB -DDEBUG -c -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -I../lds_code/timerApp -I../lds_code/HAL -I../lds_code/motionSeneor -I../lds_code/lightSeneor -I../lds_code/ledApp -I../lds_code/LBus -I../lds_code/config -I../lds_code/buttonApp -I../lds_code/app -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/can.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Core/Src/gpio.o: ../Core/Src/gpio.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F072xB -DDEBUG -c -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -I../lds_code/timerApp -I../lds_code/HAL -I../lds_code/motionSeneor -I../lds_code/lightSeneor -I../lds_code/ledApp -I../lds_code/LBus -I../lds_code/config -I../lds_code/buttonApp -I../lds_code/app -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/gpio.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Core/Src/i2c.o: ../Core/Src/i2c.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F072xB -DDEBUG -c -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -I../lds_code/timerApp -I../lds_code/HAL -I../lds_code/motionSeneor -I../lds_code/lightSeneor -I../lds_code/ledApp -I../lds_code/LBus -I../lds_code/config -I../lds_code/buttonApp -I../lds_code/app -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/i2c.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Core/Src/iwdg.o: ../Core/Src/iwdg.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F072xB -DDEBUG -c -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -I../lds_code/timerApp -I../lds_code/HAL -I../lds_code/motionSeneor -I../lds_code/lightSeneor -I../lds_code/ledApp -I../lds_code/LBus -I../lds_code/config -I../lds_code/buttonApp -I../lds_code/app -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/iwdg.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Core/Src/main.o: ../Core/Src/main.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F072xB -DDEBUG -c -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -I../lds_code/timerApp -I../lds_code/HAL -I../lds_code/motionSeneor -I../lds_code/lightSeneor -I../lds_code/ledApp -I../lds_code/LBus -I../lds_code/config -I../lds_code/buttonApp -I../lds_code/app -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/main.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Core/Src/retarget.o: ../Core/Src/retarget.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F072xB -DDEBUG -c -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -I../lds_code/timerApp -I../lds_code/HAL -I../lds_code/motionSeneor -I../lds_code/lightSeneor -I../lds_code/ledApp -I../lds_code/LBus -I../lds_code/config -I../lds_code/buttonApp -I../lds_code/app -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/retarget.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Core/Src/stm32f0xx_hal_msp.o: ../Core/Src/stm32f0xx_hal_msp.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F072xB -DDEBUG -c -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -I../lds_code/timerApp -I../lds_code/HAL -I../lds_code/motionSeneor -I../lds_code/lightSeneor -I../lds_code/ledApp -I../lds_code/LBus -I../lds_code/config -I../lds_code/buttonApp -I../lds_code/app -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/stm32f0xx_hal_msp.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Core/Src/stm32f0xx_it.o: ../Core/Src/stm32f0xx_it.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F072xB -DDEBUG -c -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -I../lds_code/timerApp -I../lds_code/HAL -I../lds_code/motionSeneor -I../lds_code/lightSeneor -I../lds_code/ledApp -I../lds_code/LBus -I../lds_code/config -I../lds_code/buttonApp -I../lds_code/app -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/stm32f0xx_it.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Core/Src/sysmem.o: ../Core/Src/sysmem.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F072xB -DDEBUG -c -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -I../lds_code/timerApp -I../lds_code/HAL -I../lds_code/motionSeneor -I../lds_code/lightSeneor -I../lds_code/ledApp -I../lds_code/LBus -I../lds_code/config -I../lds_code/buttonApp -I../lds_code/app -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/sysmem.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Core/Src/system_stm32f0xx.o: ../Core/Src/system_stm32f0xx.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F072xB -DDEBUG -c -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -I../lds_code/timerApp -I../lds_code/HAL -I../lds_code/motionSeneor -I../lds_code/lightSeneor -I../lds_code/ledApp -I../lds_code/LBus -I../lds_code/config -I../lds_code/buttonApp -I../lds_code/app -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/system_stm32f0xx.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Core/Src/tim.o: ../Core/Src/tim.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F072xB -DDEBUG -c -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -I../lds_code/timerApp -I../lds_code/HAL -I../lds_code/motionSeneor -I../lds_code/lightSeneor -I../lds_code/ledApp -I../lds_code/LBus -I../lds_code/config -I../lds_code/buttonApp -I../lds_code/app -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/tim.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Core/Src/usart.o: ../Core/Src/usart.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F072xB -DDEBUG -c -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -I../lds_code/timerApp -I../lds_code/HAL -I../lds_code/motionSeneor -I../lds_code/lightSeneor -I../lds_code/ledApp -I../lds_code/LBus -I../lds_code/config -I../lds_code/buttonApp -I../lds_code/app -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/usart.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

