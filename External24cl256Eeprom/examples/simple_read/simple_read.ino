#include <Wire.h>
#include <WiredDevice.h>
#include <EepromBasedWiredDevice.h>
#include <ExternalEeprom.h>
#include <External24cl256Eeprom.h>

External24cl256Eeprom eeprom = External24cl256Eeprom(0xa0);

void setup() {
    Serial.begin(9600);
    Serial.println("initialized");
    eeprom.write(0, 0xab);
    Serial.println(eeprom.read(0), HEX);
    eeprom.write(1, 0xae);
    Serial.println(eeprom.read(1), HEX);
    eeprom.write(2, 0x0b);
    Serial.println(eeprom.read(2), HEX);
    eeprom.write(1000, 0x5b);
    Serial.println(eeprom.read(1000), HEX);
    eeprom.write(48, 0x22);
    Serial.println(eeprom.read(48), HEX);
}

void loop() {
}
