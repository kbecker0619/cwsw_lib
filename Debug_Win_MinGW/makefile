################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include ut/tests/subdir.mk
-include ut/subdir.mk
-include cwsw_lib/src/subdir.mk
-include build/Debug/Cygwin-Windows/ut/subdir.mk
-include build/Debug/Cygwin-Windows/tests/ut/tests/subdir.mk
-include build/Debug/Cygwin-Windows/_ext/2066400048/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: cwsw_lib.exe

# Tool invocations
cwsw_lib.exe: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: Cygwin C Linker'
	gcc  -o "cwsw_lib.exe" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS) cwsw_lib.exe
	-@echo ' '

post-build:
	-@echo 'Create S19 to help track changes to EXE'
	-objcopy -O srec "E:/_Projects/pdev2/cwsw_lib.git/Debug_Win_MinGW/cwsw_lib.exe" "cwsw_lib.s19"
	-@echo ' '

.PHONY: all clean dependents post-build

-include ../makefile.targets
