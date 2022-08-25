#include <Arduboy2.h>
#include "TestStruct.h"

Arduboy2 arduboy;

TestStruct test_Read;
TestStruct test_Write;

void setup() {

    arduboy.boot();
    arduboy.setFrameRate(30);
    arduboy.flashlight();
    arduboy.systemButtons();

    
    test_Write.x = 4;
    test_Write.y = 5;
    test_Write.z = 6;
    
    test_Write.put(24, test_Write);

    test_Read.get(24, test_Read);


}

void loop() {

}
