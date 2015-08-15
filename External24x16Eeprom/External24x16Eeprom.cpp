/**
 * Arduino - External 24x16 eeprom
 * 
 * External24x16Eeprom.cpp
 * 
 * This an implementation of 24x16 eeprom.
 * 
 * @author Dalmir da Silva <dalmirdasilva@gmail.com>
 */

#ifndef __ARDUINO_EXTERNAL_24X16_EEPROM_CPP__
#define __ARDUINO_EXTERNAL_24X16_EEPROM_CPP__ 1

#include "External24x16Eeprom.h"
#include <Arduino.h>
#include <Wire.h>

External24x16Eeprom::External24x16Eeprom(unsigned char deviceAddress) :
        ExternalEeprom(0x20, 0x7ff, deviceAddress) {
    Wire.begin();
}

void External24x16Eeprom::writeBlock(unsigned int address, unsigned char* buf,
        int len) {
    unsigned char block;
    block = (unsigned char) ((address >> 8) & 0x07);
    Wire.beginTransmission(getDeviceAddress() | block);
    Wire.write((unsigned char) (address & 0xff));
    for (int i = 0; i < len; i++) {
        Wire.write(buf[i]);
    }
    Wire.endTransmission();
    delay(5);
}

void External24x16Eeprom::readBlock(unsigned int address, unsigned char* buf,
        int len) {
    unsigned char block, blockAddress;
    block = (unsigned char) ((address >> 8) & 0x07);
    blockAddress = (getDeviceAddress() | block);
    Wire.beginTransmission(blockAddress);
    Wire.write((unsigned char) (address & 0xff));
    Wire.endTransmission();
    Wire.requestFrom((int) blockAddress, len);
    for (int i = 0; i < len; i++) {
        while (!Wire.available())
            ;
        buf[i] = Wire.read();
    }
}

#endif /* __ARDUINO_EXTERNAL_24X16_EEPROM_CPP__ */
