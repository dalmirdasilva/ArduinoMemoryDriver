/**
 * Arduino - External Virtual eeprom
 * 
 * ExternalByteArrayEeprom.cpp
 * 
 * This an implementation of Virtual eeprom.
 * 
 * @author Dalmir da Silva <dalmirdasilva@gmail.com>
 */

#ifndef __ARDUINO_EXTERNAL_BYTE_ARRAY_EEPROM_CPP__
#define __ARDUINO_EXTERNAL_BYTE_ARRAY_EEPROM_CPP__ 1

#include "ExternalByteArrayEeprom.h"

ExternalByteArrayEeprom::ExternalByteArrayEeprom(unsigned char* byteArray, unsigned int deviceSize)
        : ExternalEeprom(0, 16, deviceSize), byteArray(byteArray) {
}

void ExternalByteArrayEeprom::writeBlock(unsigned int address, unsigned char* buf, int len) {
    for (int i = 0; i < len; i++) {
        byteArray[address + i] = buf[i];
    }
}

void ExternalByteArrayEeprom::readBlock(unsigned int address, unsigned char* buf, int len) {
    for (int i = 0; i < len; i++) {
        buf[i] = byteArray[address + i];
    }
}

#endif /* __ARDUINO_EXTERNAL_BYTE_ARRAY_EEPROM_CPP__ */
