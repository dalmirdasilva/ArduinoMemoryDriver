/**
 * Arduino - External 24cl256 eeprom
 * 
 * External24cl256Eeprom.h
 * 
 * This an implementation of 24cl256 eeprom.
 * 
 * @author Dalmir da Silva <dalmirdasilva@gmail.com>
 */

#ifndef __ARDUINO_EXTERNAL_24CL256_EEPROM_H__
#define __ARDUINO_EXTERNAL_24CL256_EEPROM_H__ 1

#include <ExternalEeprom.h>

class External24cl256Eeprom : public ExternalEeprom {
public:

    /**
     * Public constructor.
     * 
     * @param deviceAddress The i2c addredd of the device.
     */
    External24cl256Eeprom(unsigned char deviceAddress);
};

#endif /* __ARDUINO_EXTERNAL_24CL256_EEPROM_H__ */
