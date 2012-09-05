/**
 * Arduino - External Virtual eeprom
 * 
 * ExternalFileEeprom.cpp
 * 
 * This an implementation of Virtual eeprom.
 * 
 * @author Dalmir da Silva <dalmirdasilva@gmail.com>
 */

#ifndef __ARDUINO_EXTERNAL_FILE_EEPROM_CPP__
#define __ARDUINO_EXTERNAL_FILE_EEPROM_CPP__ 1

#include "ExternalFileEeprom.h"
#include <stddef.h>
#include <stdlib.h>
#include <stddef.h>

ExternalFileEeprom::ExternalFileEeprom(char *fileName, unsigned int deviceSize) : ExternalEeprom(16, deviceSize, 0), fileName(fileName) {
    fp = fopen(fileName, "rb+");
    if (fp == NULL) {
        printf("Error when opening file: %s.\n", fileName);
        exit(1);
    }
}

void ExternalFileEeprom::writeBlock(unsigned int address, unsigned char* buffer, int len) {
    fseek(fp, address, 0);
    fwrite(buffer, sizeof(unsigned char), len, fp);
}

void ExternalFileEeprom::readBlock(unsigned int address, unsigned char* buffer, int len) {
    fseek(fp, address, 0);
    fread(buffer, sizeof(unsigned char), len, fp);
}

#endif /* __ARDUINO_EXTERNAL_FILE_EEPROM_CPP__ */
