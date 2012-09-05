all:
	@echo "Compiling..."
	c++ main.cpp -o eeprom.bin -I./ \
	    -I./ExternalEeprom \
	    -I./ExternalByteArrayEeprom \
	    -I./ExternalFileEeprom \
	    -I./ExternalMappedEeprom \
	    -I/usr/share/arduino/libraries/Wire \
	    -I/usr/share/arduino/libraries/ \
	    -I/usr/share/arduino/hardware/arduino/cores/arduino
clean:
	rm eeprom.bin
