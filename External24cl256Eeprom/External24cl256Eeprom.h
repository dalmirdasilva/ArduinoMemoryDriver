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
     * @param device
     */
    External24cl256Eeprom(unsigned char device);

protected:

    /**
     * Writes a block of bytes separately by pages to the device.
     * All bytes during a page write operation must reside on the same page.
     * 
     * @param address
     * @param buf
     * @param len
     */
    virtual void writeBlock(unsigned int address, unsigned char* buf, int len);

    /**
     * Reads a block of bytes from the device.
     * 
     * @param address
     * @param buf
     * @param len
     */
    virtual void readBlock(unsigned int address, unsigned char* buf, int len);
};

#endif /* __ARDUINO_EXTERNAL_24CL256_EEPROM_H__ */