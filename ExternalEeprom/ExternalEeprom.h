/**
 * Arduino - External eeprom
 * 
 * ExternalEeprom.h
 * 
 * This is an abstract class of external eeprom.
 * 
 * @author Dalmir da Silva <dalmirdasilva@gmail.com>
 */

#ifndef __ARDUINO_EXTERNAL_EEPROM_H__
#define __ARDUINO_EXTERNAL_EEPROM_H__ 1

#include <EepromBasedWiredDevice.h>

class ExternalEeprom : public EepromBasedWiredDevice {

    /**
     * The size of the device.
     */
    unsigned int deviceSize;

    /**
     * The size of the device page.
     */
    int pageSize;
public:

    /**
     * Writes a unsigned char at the address into the device.
     * 
     * @param address   The address where the data will be written.
     * @param b         The data to be written.
     */
    virtual void write(unsigned int address, unsigned char b);

    /**
     * Writes a buffer of bytes at the address into the device.
     * 
     * @param address
     * @param buffer
     * @param len
     */
    virtual void writeBytes(unsigned int address, unsigned char* buf, int len);

    /**
     * Reads a unsigned char from the device.
     * 
     * @param address
     * @return 
     */
    virtual int read(unsigned int address);

    /**
     * Reads a buffer with len bytes from the device.
     * 
     * @param address
     * @param buf
     * @param len
     */
    virtual int readBytes(unsigned int address, unsigned char* buf, int len);

    /**
     * Writes len bytes at the address with data.
     * 
     * @param address
     * @param data
     * @param len
     */
    virtual int setBytes(unsigned int address, unsigned char b, int len);

    /**
     * Gets the page size of the device.
     * 
     * @return 
     */
    int getPageSize() {
        return pageSize;
    }

    /**
     * Gets the total size of the device.
     * 
     * @return 
     */
    unsigned int getDeviceSize() {
        return deviceSize;
    }

protected:

    /**
     * Protected constructor.
     * 
     * @param device
     */
    ExternalEeprom(unsigned char deviceAddress, int pageSize, unsigned int deviceSize);

    /**
     * Determines the length until first multiple of 'pageSize' of an address
     * so writing always occurs up to 'pageSize' unsigned char boundaries.
     * 
     * @param address
     * @return 
     */
    unsigned int endOfPage(unsigned int address);
};

#endif /* __ARDUINO_EXTERNAL_EEPROM_H__ */
