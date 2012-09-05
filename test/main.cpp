#include <stdio.h>

#include <ExternalEeprom.h>
#include <ExternalEeprom.cpp>
#include <ExternalByteArrayEeprom.h>
#include <ExternalByteArrayEeprom.cpp>
#include <ExternalFileEeprom.h>
#include <ExternalFileEeprom.cpp>
#include <ExternalMappedEeprom.h>
#include <ExternalMappedEeprom.cpp>

#include "ExternalFileEeprom/ExternalFileEeprom.h"
#include "ExternalMappedEeprom/ExternalMappedEeprom.h"

#define EEPROM_SIZE 32768

int main() {
    unsigned char byteArray[EEPROM_SIZE];
    unsigned int i;
    ExternalByteArrayEeprom eve(byteArray, EEPROM_SIZE);
    ExternalFileEeprom efe((char*) "/tmp/driver", EEPROM_SIZE);
    ExternalMappedEeprom eme(&efe, 10, 100);
    ExternalMappedEeprom eme1(&efe, 0, 9);
    ExternalMappedEeprom eme2(&efe, 200, 300);
    printf("ee: %d\n", eme.getDeviceSize());
    printf("ee1: %d\n", eme1.getDeviceSize());
    printf("ee2: %d\n", eme2.getDeviceSize());
    for (i = 0; i < eme.getDeviceSize(); i++) {
        eme.write(i, 0xff);
    }
    for (i = 0; i < eme1.getDeviceSize(); i++) {
        eme1.write(i, 0xee);
    }
    for (i = 0; i < eme2.getDeviceSize(); i++) {
        eme2.write(i, 0xaa);
    }
    for (i = 0; i < EEPROM_SIZE; i++) {
        eve.write(i, i);
    }
    printf("0xffd: %x\n", eve.read(0xffd));
    printf("0x3d: %x\n", eve.read(0x3d));
    printf("0x33f: %x\n", eve.read(0x33f));
    printf("0x01: %x\n", eve.read(0x01));
    return 0;
}