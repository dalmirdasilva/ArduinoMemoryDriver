/**
 * Arduino - External Virtual eeprom
 * 
 * ExternalByteArrayEeprom.h
 * 
 * This an implementation of VIRTUAL eeprom.
 * 
 * @author Dalmir da Silva <dalmirdasilva@gmail.com>
 */

#ifndef __ARDUINO_EXTERNAL_BYTE_ARRAY_EEPROM_H__
#define __ARDUINO_EXTERNAL_BYTE_ARRAY_EEPROM_H__ 1

#include <ExternalEeprom.h>

class ExternalByteArrayEeprom : public ExternalEeprom {
    
    /**
     * The used buffer.
     */
    unsigned char* byteArray;

public:

    /**
     * Public constructor.
     * 
     * @param device
     */
    ExternalByteArrayEeprom(unsigned char* byteArray, unsigned int deviceSize);

protected:

    /**
     * Writes a block of bytes separately by pages to the device.
     * All bytes during a page write operation must reside on the same page.
     * 
     * @param address
     * @param buffer
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

#endif /* __ARDUINO_EXTERNAL_BYTE_ARRAY_EEPROM_H__ */
