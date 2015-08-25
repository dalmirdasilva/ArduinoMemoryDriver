/**
 * Arduino - External eeprom
 * 
 * ExternalMappedEeprom.cpp
 * 
 * This is an abstract class of external eeprom.
 * 
 * @author Dalmir da Silva <dalmirdasilva@gmail.com>
 */

#include "ExternalMappedEeprom.h"

ExternalMappedEeprom::ExternalMappedEeprom(ExternalEeprom* externalEeprom, unsigned int startAddress, unsigned int endAddress)
        : ExternalEeprom(externalEeprom->getDeviceAddress(), externalEeprom->getPageSize(), externalEeprom->getDeviceSize()), externalEeprom(externalEeprom), startAddress(startAddress), endAddress(endAddress) {
}

void ExternalMappedEeprom::writeBlock(unsigned int address, unsigned char* buf, int len) {
    unsigned int mappedAddress = (address + startAddress);
    if (mappedAddress < endAddress) {
        unsigned int available = (endAddress - mappedAddress);
        len = ((unsigned int) len > available) ? available : len;
        externalEeprom->writeBlock(mappedAddress, buf, len);
    }
}

int ExternalMappedEeprom::readBlock(unsigned int address, unsigned char* buf, int len) {
    unsigned int mappedAddress = (address + startAddress);
    int total = 0;
    if (mappedAddress < endAddress) {
        unsigned int available = (endAddress - mappedAddress);
        len = ((unsigned int) len > available) ? available : len;
        total = externalEeprom->readBlock(mappedAddress, buf, len);
    }
    return total;
}
