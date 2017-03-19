

#include "IRBlaster.h"


void IRBlaster::init(){
	Serial.println("Initializing IR Blaster");
	display.init();
	count = 0;
}

void IRBlaster::tick(){
	if (digitalRead(INCREMENT_PIN) == LOW){
		display.write_number(++count);
	}
	display.refresh();
}
