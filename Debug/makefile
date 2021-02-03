################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
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
LSS += \
Project2ADC_LCD.lss \

SIZEDUMMY += \
sizedummy \


# All Target
all: Project2ADC_LCD.elf secondary-outputs

# Tool invocations
Project2ADC_LCD.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Project2ADC_LCD.map -mmcu=atmega16 -o "Project2ADC_LCD.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Project2ADC_LCD.lss: Project2ADC_LCD.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Project2ADC_LCD.elf  >"Project2ADC_LCD.lss"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Project2ADC_LCD.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega16 Project2ADC_LCD.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Project2ADC_LCD.elf
	-@echo ' '

secondary-outputs: $(LSS) $(SIZEDUMMY)

.PHONY: all clean dependents

-include ../makefile.targets
