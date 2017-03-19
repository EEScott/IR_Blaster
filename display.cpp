

#include "display.h"

void Display::init(){
	Serial.println("Init");

	pinMode(DISP0, OUTPUT);
	pinMode(DISP1, OUTPUT);
	pinMode(DISP2, OUTPUT);
	pinMode(DISP3, OUTPUT);
	pinMode(DISP4, OUTPUT);
	pinMode(DISP5, OUTPUT);
	pinMode(DISP6, OUTPUT);
}

void Display::write_number(int number){
	Serial.print("Writing: ");
	Serial.println(number);
	clear_display();
	switch(number) {
		case 0:
			digitalWrite(DISP0,HIGH);
			digitalWrite(DISP1,HIGH);
			digitalWrite(DISP2,HIGH);
			digitalWrite(DISP3,HIGH);
			digitalWrite(DISP4,HIGH);
			digitalWrite(DISP5,HIGH);
			break;
		case 1:
			digitalWrite(DISP2,HIGH);
			digitalWrite(DISP3,HIGH);
			break;
		case 2:
			digitalWrite(DISP0,HIGH);
			digitalWrite(DISP1,HIGH);
			digitalWrite(DISP3,HIGH);
			digitalWrite(DISP4,HIGH);
			digitalWrite(DISP6,HIGH);
			break;
		case 3:
			digitalWrite(DISP1,HIGH);
			digitalWrite(DISP2,HIGH);
			digitalWrite(DISP3,HIGH);
			digitalWrite(DISP4,HIGH);
			digitalWrite(DISP6,HIGH);
			break;
		case 4:
			digitalWrite(DISP2,HIGH);
			digitalWrite(DISP3,HIGH);
			digitalWrite(DISP5,HIGH);
			digitalWrite(DISP6,HIGH);
			break;
		case 5:
			digitalWrite(DISP1,HIGH);
			digitalWrite(DISP2,HIGH);
			digitalWrite(DISP4,HIGH);
			digitalWrite(DISP5,HIGH);
			digitalWrite(DISP6,HIGH);
			break;
		case 6:
			digitalWrite(DISP0,HIGH);
			digitalWrite(DISP1,HIGH);
			digitalWrite(DISP2,HIGH);
			digitalWrite(DISP4,HIGH);
			digitalWrite(DISP5,HIGH);
			digitalWrite(DISP6,HIGH);
			break;
		case 7:
			digitalWrite(DISP2,HIGH);
			digitalWrite(DISP3,HIGH);
			digitalWrite(DISP4,HIGH);
			break;
		case 8:
			digitalWrite(DISP0,HIGH);
			digitalWrite(DISP1,HIGH);
			digitalWrite(DISP2,HIGH);
			digitalWrite(DISP3,HIGH);
			digitalWrite(DISP4,HIGH);
			digitalWrite(DISP5,HIGH);
			digitalWrite(DISP6,HIGH);
			break;
		case 9:
			digitalWrite(DISP2,HIGH);
			digitalWrite(DISP3,HIGH);
			digitalWrite(DISP4,HIGH);
			digitalWrite(DISP5,HIGH);
			digitalWrite(DISP6,HIGH);
			break;
	}
}

void Display::clear_display(){
	Serial.println("Clearing");
	digitalWrite(DISP0,LOW);
	digitalWrite(DISP1,LOW);
	digitalWrite(DISP2,LOW);
	digitalWrite(DISP3,LOW);
	digitalWrite(DISP4,LOW);
	digitalWrite(DISP5,LOW);
	digitalWrite(DISP6,LOW);
}

