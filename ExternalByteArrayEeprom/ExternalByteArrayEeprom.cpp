/**
 * Arduino - External Virtual eeprom
 * 
 * ExternalByteArrayEeprom.cpp
 * 
 * This an implementation of Virtual eeprom.
 * 
 * @author Dalmir da Silva <dalmirdasilva@gmail.com>
 */

#include "ExternalByteArrayEeprom.h"

ExternalByteArrayEeprom::ExternalByteArrayEeprom(unsigned char* byteArray, unsigned int deviceSize)
        : ExternalEeprom(0, 16, deviceSize), byteArray(byteArray) {
}

void ExternalByteArrayEeprom::writeBlock(unsigned int address, unsigned char* buf, int len) {
    for (int i = 0; i < len; i++) {
        byteArray[address + i] = buf[i];
    }
}

int ExternalByteArrayEeprom::readBlock(unsigned int address, unsigned char* buf, int len) {
    for (int i = 0; i < len; i++) {
        buf[i] = byteArray[address + i];
    }
    return len;
}
