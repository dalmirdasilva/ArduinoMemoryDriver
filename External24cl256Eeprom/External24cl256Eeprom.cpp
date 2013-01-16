/**
 * Arduino - External 24cl256 eeprom
 * 
 * External24cl256Eeprom.cpp
 * 
 * This an implementation of 24cl256 eeprom.
 * 
 * @author Dalmir da Silva <dalmirdasilva@gmail.com>
 */

#ifndef __ARDUINO_EXTERNAL_24CL256_EEPROM_CPP__
#define __ARDUINO_EXTERNAL_24CL256_EEPROM_CPP__ 1

#include "External24cl256Eeprom.h"
#include <Arduino.h>
#include <Wire.h>

External24cl256Eeprom::External24cl256Eeprom(unsigned char device) :
        ExternalEeprom(0x40, 0x7fff, device) {
    Wire.begin();
}

void External24cl256Eeprom::writeBlock(unsigned int address, unsigned char* buf,
        int len) {
    Wire.beginTransmission(getDevice());
    Wire.write((unsigned char) (address >> 8) & 0xff);
    Wire.write((unsigned char) (address & 0xff));
    for (int i = 0; i < len; i++) {
        Wire.write(buf[i]);
    }
    Wire.endTransmission();
    delay(5);
}

void External24cl256Eeprom::readBlock(unsigned int address, unsigned char* buf,
        int len) {
    Wire.beginTransmission(getDevice());
    Wire.write((unsigned char) (address >> 8) & 0xff);
    Wire.write((unsigned char) (address & 0xff));
    Wire.endTransmission();
    Wire.requestFrom((int) getDevice(), len);
    for (int i = 0; i < len; i++) {
        while (!Wire.available())
            ;
        buf[i] = Wire.read();
    }
}

#endif /* __ARDUINO_EXTERNAL_24CL256_EEPROM_CPP__ */
