/**
 * Arduino - External eeprom
 * 
 * ExternalMappedEeprom.cpp
 * 
 * This is an abstract class of external eeprom.
 * 
 * @author Dalmir da Silva <dalmirdasilva@gmail.com>
 */

#ifndef __ARDUINO_EXTERNAL_MAPPED_EEPROM_CPP__
#define __ARDUINO_EXTERNAL_MAPPED_EEPROM_CPP__ 1

#include "ExternalMappedEeprom.h"

ExternalMappedEeprom::ExternalMappedEeprom(ExternalEeprom* externalEeprom, unsigned int startAddress, unsigned int endAddress) 
: ExternalEeprom(externalEeprom->getPageSize(), externalEeprom->getDeviceSize(), externalEeprom->getDevice()), externalEeprom(externalEeprom) {
    this->startAddress = startAddress;
    this->endAddress = endAddress;
}

void ExternalMappedEeprom::writeBlock(unsigned int address, unsigned char* buf, int len) {
    unsigned int mappedAddress = (address + startAddress);
    if (mappedAddress < endAddress) {
        unsigned int available = (endAddress - mappedAddress);
        len = (len > available) ? available : len;
        externalEeprom->writeBlock(mappedAddress, buf, len);
    }
}

void ExternalMappedEeprom::readBlock(unsigned int address, unsigned char* buf, int len) {
    unsigned int mappedAddress = (address + startAddress);
    if (mappedAddress < endAddress) {
        unsigned int available = (endAddress - mappedAddress);
        len = (len > available) ? available : len;
        externalEeprom->readBlock(mappedAddress, buf, len);
    }
}

#endif /* __ARDUINO_EXTERNAL_MAPPED_EEPROM_CPP__ */
