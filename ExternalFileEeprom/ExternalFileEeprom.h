/**
 * Arduino - External Virtual eeprom
 * 
 * ExternalFileEeprom.h
 * 
 * This an implementation of VIRTUAL eeprom.
 * 
 * @author Dalmir da Silva <dalmirdasilva@gmail.com>
 */

#ifndef __ARDUINO_EXTERNAL_FILE_EEPROM_H__
#define __ARDUINO_EXTERNAL_FILE_EEPROM_H__ 1

#include <ExternalEeprom.h>

class ExternalFileEeprom : public ExternalEeprom {
private:
    char *fileName;
    FILE *fp;
public:

    /**
     * Public constructor.
     * 
     * @param device
     */
    ExternalFileEeprom(char *fileName, unsigned int size);

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

#endif /* __ARDUINO_EXTERNAL_FILE_EEPROM_H__ */
