/**
 * Arduino - External eeprom
 * 
 * ExternalEeprom.cpp
 * 
 * This is an abstract class of external eeprom.
 * 
 * @author Dalmir da Silva <dalmirdasilva@gmail.com>
 */

#define min(a, b) ((a > b) ? b : a)  

#include "ExternalEeprom.h"

ExternalEeprom::ExternalEeprom(unsigned char deviceAddress, int pageSize, unsigned int deviceSize)
        : EepromBasedWiredDevice(0x50 | (deviceAddress & 0x07)), pageSize(pageSize), deviceSize(deviceSize) {
}

void ExternalEeprom::write(unsigned int address, unsigned char b) {
    writeBlock(address, &b, 1);
}

void ExternalEeprom::writeBytes(unsigned int address, unsigned char* buf, int len) {
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

int ExternalEeprom::readBytes(unsigned int address, unsigned char* buf, int len) {
    int total, partial, chunkSize;
    unsigned int available;
    if (address >= deviceSize) {
        return -1;
    }
    available = (deviceSize - address);
    if (available < (unsigned char) len) {
        len = (int) available;
    }
    total = 0;
    while (len > 0) {
        chunkSize = min(len, pageSize);
        partial = readBlock(address, buf, chunkSize);
        if (partial <= 0) {
            return total;
        }
        total += partial;
        address += partial;
        buf += partial;
        len -= partial;
    }
    return total;
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
    unsigned int eopAddress = ((address + pageSize - 1) / pageSize) * pageSize;
    return (eopAddress - address);
}
