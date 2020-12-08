################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lds_code/LBus/lds_LBus_basic_func.c \
../lds_code/LBus/lds_LBus_buf.c \
../lds_code/LBus/lds_LBus_fifo.c \
../lds_code/LBus/lds_LBus_func.c \
../lds_code/LBus/lds_LBus_func_DT1.c \
../lds_code/LBus/lds_LBus_func_DT4.c \
../lds_code/LBus/lds_LBus_para.c 

OBJS += \
./lds_code/LBus/lds_LBus_basic_func.o \
./lds_code/LBus/lds_LBus_buf.o \
./lds_code/LBus/lds_LBus_fifo.o \
./lds_code/LBus/lds_LBus_func.o \
./lds_code/LBus/lds_LBus_func_DT1.o \
./lds_code/LBus/lds_LBus_func_DT4.o \
./lds_code/LBus/lds_LBus_para.o 

C_DEPS += \
./lds_code/LBus/lds_LBus_basic_func.d \
./lds_code/LBus/lds_LBus_buf.d \
./lds_code/LBus/lds_LBus_fifo.d \
./lds_code/LBus/lds_LBus_func.d \
./lds_code/LBus/lds_LBus_func_DT1.d \
./lds_code/LBus/lds_LBus_func_DT4.d \
./lds_code/LBus/lds_LBus_para.d 


# Each subdirectory must supply rules for building sources it contributes
lds_code/LBus/lds_LBus_basic_func.o: ../lds_code/LBus/lds_LBus_basic_func.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F072xB -DDEBUG -c -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -I../lds_code/timerApp -I../lds_code/HAL -I../lds_code/motionSeneor -I../lds_code/lightSeneor -I../lds_code/ledApp -I../lds_code/LBus -I../lds_code/config -I../lds_code/buttonApp -I../lds_code/app -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"lds_code/LBus/lds_LBus_basic_func.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
lds_code/LBus/lds_LBus_buf.o: ../lds_code/LBus/lds_LBus_buf.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F072xB -DDEBUG -c -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -I../lds_code/timerApp -I../lds_code/HAL -I../lds_code/motionSeneor -I../lds_code/lightSeneor -I../lds_code/ledApp -I../lds_code/LBus -I../lds_code/config -I../lds_code/buttonApp -I../lds_code/app -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"lds_code/LBus/lds_LBus_buf.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
lds_code/LBus/lds_LBus_fifo.o: ../lds_code/LBus/lds_LBus_fifo.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F072xB -DDEBUG -c -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -I../lds_code/timerApp -I../lds_code/HAL -I../lds_code/motionSeneor -I../lds_code/lightSeneor -I../lds_code/ledApp -I../lds_code/LBus -I../lds_code/config -I../lds_code/buttonApp -I../lds_code/app -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"lds_code/LBus/lds_LBus_fifo.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
lds_code/LBus/lds_LBus_func.o: ../lds_code/LBus/lds_LBus_func.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F072xB -DDEBUG -c -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -I../lds_code/timerApp -I../lds_code/HAL -I../lds_code/motionSeneor -I../lds_code/lightSeneor -I../lds_code/ledApp -I../lds_code/LBus -I../lds_code/config -I../lds_code/buttonApp -I../lds_code/app -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"lds_code/LBus/lds_LBus_func.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
lds_code/LBus/lds_LBus_func_DT1.o: ../lds_code/LBus/lds_LBus_func_DT1.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F072xB -DDEBUG -c -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -I../lds_code/timerApp -I../lds_code/HAL -I../lds_code/motionSeneor -I../lds_code/lightSeneor -I../lds_code/ledApp -I../lds_code/LBus -I../lds_code/config -I../lds_code/buttonApp -I../lds_code/app -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"lds_code/LBus/lds_LBus_func_DT1.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
lds_code/LBus/lds_LBus_func_DT4.o: ../lds_code/LBus/lds_LBus_func_DT4.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F072xB -DDEBUG -c -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -I../lds_code/timerApp -I../lds_code/HAL -I../lds_code/motionSeneor -I../lds_code/lightSeneor -I../lds_code/ledApp -I../lds_code/LBus -I../lds_code/config -I../lds_code/buttonApp -I../lds_code/app -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"lds_code/LBus/lds_LBus_func_DT4.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
lds_code/LBus/lds_LBus_para.o: ../lds_code/LBus/lds_LBus_para.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F072xB -DDEBUG -c -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -I../lds_code/timerApp -I../lds_code/HAL -I../lds_code/motionSeneor -I../lds_code/lightSeneor -I../lds_code/ledApp -I../lds_code/LBus -I../lds_code/config -I../lds_code/buttonApp -I../lds_code/app -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"lds_code/LBus/lds_LBus_para.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

