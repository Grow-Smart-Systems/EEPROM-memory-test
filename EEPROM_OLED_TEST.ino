#include "src/OLED/OLED.h"
#include "src/Utils/Timer.h"
#include "src/Storage/MaintenanceEEPROM.h"
#include "src/Utils/BoolArray.h"

OLED _screen;

void setup() {
    Serial.begin(74880);
    Serial.println("Start!");

    if(!_screen.init())
    {
        Serial.println("OLED init error!");
        return;
    }
    _screen.printInitializeScreen();

    // EEPROM
    MaintenanceEEPROM eeprom;

    const auto map = eeprom.ReadWriteMemoryTest();
    //const auto map = eeprom.ReadDataFormMemory();

    _screen.printMemoryMap(map);
    Serial.println("End!");
}

void loop() {
  // put your main code here, to run repeatedly:

}

