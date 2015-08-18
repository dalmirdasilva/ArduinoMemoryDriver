/**
 * Arduino - External 24cl256 eeprom
 * 
 * External24cl256Eeprom.cpp
 * 
 * This an implementation of 24cl256 eeprom.
 * 
 * @author Dalmir da Silva <dalmirdasilva@gmail.com>
 */

#ifndef __ARDUINO_EXTERNAL_24CL256_EEPROM_CPP__
#define __ARDUINO_EXTERNAL_24CL256_EEPROM_CPP__ 1

#include "External24cl256Eeprom.h"
#include <Arduino.h>
#include <Wire.h>

External24cl256Eeprom::External24cl256Eeprom(unsigned char deviceAddress) :
        ExternalEeprom(deviceAddress, 0x40, 0x7fff) {
    setAddressSize(0x02);
}

#endif /* __ARDUINO_EXTERNAL_24CL256_EEPROM_CPP__ */
