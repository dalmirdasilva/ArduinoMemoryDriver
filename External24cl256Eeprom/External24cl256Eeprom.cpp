/**
 * Arduino - External 24cl256 eeprom
 * 
 * External24cl256Eeprom.cpp
 * 
 * This an implementation of 24cl256 eeprom.
 * 
 * @author Dalmir da Silva <dalmirdasilva@gmail.com>
 */

#include "External24cl256Eeprom.h"

External24cl256Eeprom::External24cl256Eeprom(unsigned char deviceAddress) :
        ExternalEeprom(deviceAddress, 0x40, 0x7fff) {
    setAddressSize(0x02);
}
