################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../ExternalMappedEeprom/ExternalMappedEeprom.cpp 

OBJS += \
./ExternalMappedEeprom/ExternalMappedEeprom.o 

CPP_DEPS += \
./ExternalMappedEeprom/ExternalMappedEeprom.d 


# Each subdirectory must supply rules for building sources it contributes
ExternalMappedEeprom/%.o: ../ExternalMappedEeprom/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -I/usr/share/arduino/hardware/arduino/variants/standard -I/usr/share/arduino/libraries/Wire -I/usr/share/arduino/hardware/arduino/cores/arduino -I"/home/dalmir/storage/microcontroller/arduino/driver/memory/External24cl256Eeprom" -I"/home/dalmir/storage/microcontroller/arduino/driver/memory/External24x16Eeprom" -I"/home/dalmir/storage/microcontroller/arduino/driver/memory/ExternalByteArrayEeprom" -I"/home/dalmir/storage/microcontroller/arduino/driver/memory/ExternalEeprom" -I"/home/dalmir/storage/microcontroller/arduino/driver/memory/ExternalFileEeprom" -I"/home/dalmir/storage/microcontroller/arduino/driver/memory/ExternalMappedEeprom" -DUSB_VID=null -DUSB_PID=null -DARDUINO=101 -Wall -Os -ffunction-sections -fdata-sections -ffunction-sections -fdata-sections -fno-exceptions -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


