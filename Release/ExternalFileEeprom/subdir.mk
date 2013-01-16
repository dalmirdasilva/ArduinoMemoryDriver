################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../ExternalFileEeprom/ExternalFileEeprom.cpp 

OBJS += \
./ExternalFileEeprom/ExternalFileEeprom.o 

CPP_DEPS += \
./ExternalFileEeprom/ExternalFileEeprom.d 


# Each subdirectory must supply rules for building sources it contributes
ExternalFileEeprom/%.o: ../ExternalFileEeprom/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -I/usr/share/arduino/hardware/arduino/variants/standard -I/usr/share/arduino/libraries/Wire -I/usr/share/arduino/hardware/arduino/cores/arduino -I"/storage/microcontroller/arduino/driver/memory/External24cl256Eeprom" -I"/storage/microcontroller/arduino/driver/memory/External24x16Eeprom" -I"/storage/microcontroller/arduino/driver/memory/ExternalByteArrayEeprom" -I"/storage/microcontroller/arduino/driver/memory/ExternalEeprom" -I"/storage/microcontroller/arduino/driver/memory/ExternalFileEeprom" -I"/storage/microcontroller/arduino/driver/memory/ExternalMappedEeprom" -Wall -Os -fpack-struct -fshort-enums -funsigned-char -funsigned-bitfields -fno-exceptions -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


