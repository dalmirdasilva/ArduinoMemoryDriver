#include <Arduino.h>
#include <ExternalEeprom.h>
#include <ExternalByteArrayEeprom.h>
#include <ExternalFileEeprom.h>
#include <ExternalMappedEeprom.h>
#include "ExternalFileEeprom.h"

#define EEPROM_SIZE 128

int main() {
    unsigned int i;
    unsigned char byteArray[EEPROM_SIZE];
    ExternalByteArrayEeprom eve(byteArray, EEPROM_SIZE);
    ExternalMappedEeprom eme0(&eve, 10, 100);
    ExternalMappedEeprom eme1(&eve, 0, 9);
    ExternalMappedEeprom eme2(&eve, 100, EEPROM_SIZE);
	Serial.print("eme0: ");
	Serial.println(eme0.getDeviceSize());

	Serial.print("eme1: ");
	Serial.println(eme1.getDeviceSize());

	Serial.print("eme2: ");
	Serial.println(eme2.getDeviceSize());

    for (i = 0; i < eme0.getDeviceSize(); i++) {
        eme0.write(i, 0xff);
    }

    for (i = 0; i < eme1.getDeviceSize(); i++) {
        eme1.write(i, 0xee);
    }

    for (i = 0; i < eme2.getDeviceSize(); i++) {
        eme2.write(i, 0xaa);
    }

    Serial.print("0xffd: ");
    Serial.println(eve.read(0xffd));

    Serial.print("0xa2d: ");
    Serial.println(eve.read(0xa2d));

    Serial.print("0xef: ");
    Serial.println(eve.read(0xef));
}
