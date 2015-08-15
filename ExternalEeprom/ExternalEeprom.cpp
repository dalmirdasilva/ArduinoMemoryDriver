/**
 * Arduino - External eeprom
 * 
 * ExternalEeprom.cpp
 * 
 * This is an abstract class of external eeprom.
 * 
 * @author Dalmir da Silva <dalmirdasilva@gmail.com>
 */

#ifndef __ARDUINO_EXTERNAL_EEPROM_CPP__
#define __ARDUINO_EXTERNAL_EEPROM_CPP__ 1

#define min(a, b) ((a > b) ? b : a)  

#include "ExternalEeprom.h"

ExternalEeprom::ExternalEeprom(int pageSize, unsigned int deviceSize,
        unsigned char device) {
    this->pageSize = pageSize;
    deviceSize = deviceSize;
    this->device = 0x50 | (device & 0x07);
}

void ExternalEeprom::write(unsigned int address, unsigned char b) {
    writeBlock(address, &b, 1);
}

void ExternalEeprom::writeBytes(unsigned int address, unsigned char* buf,
        int len) {
    unsigned int eop, room;
    int chunkSize;
    room = (deviceSize - address);
    if (room == 0) {
        return;
    }
    len = (room < (unsigned char) len) ? room : len;
    eop = endOfPage(address);
    chunkSize = min(eop, (unsigned char) len);
    if (chunkSize > 0) {
        writeBlock(address, buf, chunkSize);
        address += chunkSize;
        buf += chunkSize;
        len -= chunkSize;
    }
    while (len > 0) {
        chunkSize = min(len, pageSize);
        writeBlock(address, buf, chunkSize);
        address += chunkSize;
        buf += chunkSize;
        len -= chunkSize;
    }
}

int ExternalEeprom::read(unsigned int address) {
    unsigned char b;
    if (readBytes(address, &b, 1) == -1) {
        return -1;
    }
    return (int) b;
}

int ExternalEeprom::readBytes(unsigned int address, unsigned char* buf,
        int len) {
    int cnt, chunkSize = pageSize;
    unsigned int available;
    if (address >= deviceSize) {
        return -1;
    }
    available = (deviceSize - address);
    if (available < (unsigned char) len) {
        len = (int) available;
    }
    cnt = len;
    while (len > 0) {
        chunkSize = min(len, pageSize);
        readBlock(address, buf, chunkSize);
        address += chunkSize;
        buf += chunkSize;
        len -= chunkSize;
    }
    return cnt;
}

int ExternalEeprom::setBytes(unsigned int address, unsigned char b, int len) {
    unsigned char buf[pageSize];
    int eop, chunkSize;
    unsigned int room;
    if (address >= deviceSize) {
        return -1;
    }
    room = (deviceSize - address);
    if (room < (unsigned char) len) {
        len = (int) room;
    }
    for (int i = 0; i < pageSize; i++) {
        buf[i] = b;
    }
    eop = endOfPage(address);
    if (eop > 0) {
        chunkSize = min(eop, len);
        writeBlock(address, buf, chunkSize);
        address += chunkSize;
        len -= chunkSize;
    }
    while (len > 0) {
        chunkSize = min(len, pageSize);
        writeBlock(address, buf, chunkSize);
        address += chunkSize;
        len -= chunkSize;
    }
    return len;
}

unsigned int ExternalEeprom::endOfPage(unsigned int address) {
    // Why / and then * by the same number?
    unsigned int eopAddr = ((address + pageSize - 1) / pageSize) * pageSize;
    return (eopAddr - address);
}

#endif /* __ARDUINO_EXTERNAL_EEPROM_CPP__ */
