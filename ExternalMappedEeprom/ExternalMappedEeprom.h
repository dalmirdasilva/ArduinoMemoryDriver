/**
 * Arduino - External eeprom
 * 
 * ExternalMappedEeprom.h
 * 
 * This is an abstract class of external eeprom.
 * 
 * @author Dalmir da Silva <dalmirdasilva@gmail.com>
 */

#ifndef __ARDUINO_EXTERNAL_MAPPED_EEPROM_H__
#define __ARDUINO_EXTERNAL_MAPPED_EEPROM_H__ 1

#include "ExternalEeprom.h"

class ExternalMappedEeprom : public ExternalEeprom {
    
    /**
     * The underlying external eeprom
     */
    ExternalEeprom* externalEeprom;
    
    /**
     * The start address of the map
     */
    unsigned int startAddress;
    
    /**
     * The end address of the map
     */
    unsigned int endAddress;
public:

    /**
     * Public constructor.
     * 
     * @param externalEeprom
     * @param startAddress
     * @param endAddress
     */
    ExternalMappedEeprom(ExternalEeprom* externalEeprom, unsigned int startAddress, unsigned int endAddress);

    /**
     * Device size.
     * 
     * @return 
     */
    unsigned int getDeviceSize() {
        return (endAddress - startAddress);
    }
    
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
     * @param buffer
     * @param len
     */
    virtual void readBlock(unsigned int address, unsigned char* buf, int len);
};

#endif /* __ARDUINO_EXTERNAL_MAPPED_EEPROM_H__ */
