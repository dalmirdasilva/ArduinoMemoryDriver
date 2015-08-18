/**
 * Arduino - External 24x16 eeprom
 * 
 * External24x16Eeprom.cpp
 * 
 * This an implementation of 24x16 eeprom.
 * 
 * @author Dalmir da Silva <dalmirdasilva@gmail.com>
 */

#ifndef __ARDUINO_EXTERNAL_24X16_EEPROM_CPP__
#define __ARDUINO_EXTERNAL_24X16_EEPROM_CPP__ 1

#include "External24x16Eeprom.h"

External24x16Eeprom::External24x16Eeprom(unsigned char deviceAddress) :
        ExternalEeprom(0x20, 0x7ff, deviceAddress) {
    setAddressSize(0x01);
}

#endif /* __ARDUINO_EXTERNAL_24X16_EEPROM_CPP__ */
