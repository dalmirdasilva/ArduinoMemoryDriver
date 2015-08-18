/**
 * Arduino - External 24x16 eeprom
 * 
 * External24x16Eeprom.h
 * 
 * This an implementation of 24X16 eeprom.
 * 
 * @author Dalmir da Silva <dalmirdasilva@gmail.com>
 */

#ifndef __ARDUINO_EXTERNAL_24X16_EEPROM_H__
#define __ARDUINO_EXTERNAL_24X16_EEPROM_H__ 1

#include <ExternalEeprom.h>
#include <EepromBasedWiredDevice.h>

class External24x16Eeprom : public ExternalEeprom {
public:

    /**
     * Public constructor.
     * 
     * @param device The i2c address of the device.
     */
    External24x16Eeprom(unsigned char deviceAddress);
};

#endif /* __ARDUINO_EXTERNAL_24X16_EEPROM_H__ */
