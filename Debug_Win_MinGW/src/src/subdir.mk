################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/src/cwsw_lib.c 

OBJS += \
./src/src/cwsw_lib.o 

C_DEPS += \
./src/src/cwsw_lib.d 


# Each subdirectory must supply rules for building sources it contributes
src/src/%.o: ../src/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -std=gnu11 -D"XPRJ_Debug_Win_MinGW=1" -I"E:/_Projects/pdev2/cwsw_lib.git/ut" -I"E:/_Projects/pdev2/cwsw_lib.git/cfg" -I"E:/_Projects/pdev2/cwsw_lib.git/src" -O0 -g3 -pedantic -Wall -Wextra -Wconversion -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


