

#include "display.h"

void Display::init(){
	Serial.println("Initializing Display.");
	// buttons:
	pinMode(INCREMENT_PIN, INPUT);
	pinMode(ACCEPT_PIN, INPUT);
	// segments:
	pinMode(DISP0, OUTPUT);
	pinMode(DISP1, OUTPUT);
	pinMode(DISP2, OUTPUT);
	pinMode(DISP3, OUTPUT);
	pinMode(DISP4, OUTPUT);
	pinMode(DISP5, OUTPUT);
	pinMode(DISP6, OUTPUT);
	// digit select:
	pinMode(ONES_DIGIT_PIN, OUTPUT);
	pinMode(TENS_DIGIT_PIN, OUTPUT);
	digitalWrite(ONES_DIGIT_PIN, HIGH);
	digitalWrite(TENS_DIGIT_PIN, HIGH);
	blink = true;
}

void Display::delay_with_refresh(int delay_length){
	delay_length /= 2;
	for (int i = 0; i < delay_length; i++){
		refresh();
	}
}

void Display::write_digit(int number, int digit){
	clear_display();

	// turn off digits
	digitalWrite(ONES_DIGIT_PIN,HIGH);
	digitalWrite(TENS_DIGIT_PIN,HIGH);

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
	// Turn on digit
	switch(digit){
			case 10:
				digitalWrite(TENS_DIGIT_PIN,LOW);
				break;
			case 1:
				digitalWrite(ONES_DIGIT_PIN,LOW);
				break;
	}
}

void Display::write_number(int number){
	Serial.print("Writing: ");
	Serial.println(number);

	// Get first digit:
	first_digit = number/10;
	second_digit = number%10;

	delay_with_refresh(200);
}

void Display::refresh(){
	if (blink_count < 400) {
		// FLASH BOTH DIGITS
		write_digit(first_digit, 10);
		delay(1);
		write_digit(second_digit, 1);
	} else {
		clear_display();
	}
	if (blink_count++ > 550){
		Serial.println("Reseting blink_count");
		blink_count=0;
	}
	delay(1);
}

void Display::clear_display(){
	digitalWrite(DISP0,LOW);
	digitalWrite(DISP1,LOW);
	digitalWrite(DISP2,LOW);
	digitalWrite(DISP3,LOW);
	digitalWrite(DISP4,LOW);
	digitalWrite(DISP5,LOW);
	digitalWrite(DISP6,LOW);
}

