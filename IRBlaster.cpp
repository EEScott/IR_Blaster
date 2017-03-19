

#include "IRBlaster.h"


void IRBlaster::init(){
	Serial.println("Initializing IR Blaster");
	// buttons:
	pinMode(INCREMENT_PIN, INPUT);
	pinMode(ACCEPT_PIN, INPUT);

	display.init();
	my_hour = 0;
	my_minute = 0;
	set_time();
}

void IRBlaster::tick(){
	if (my_minute != minute()) {
		my_minute = minute();
		my_hour = hour();
		display.write_number(my_minute);
	}

	display.refresh();
}

void IRBlaster::tick(int *number_to_increment){
	if (digitalRead(INCREMENT_PIN) == LOW){
		Serial.print("Found increment hour: ");
		Serial.println(*number_to_increment);
		*number_to_increment = *number_to_increment + 1;
		Serial.println(*number_to_increment);
		display.write_number(*number_to_increment);
	}
	display.refresh();
}

void IRBlaster::set_time(){
	// set hour
	Serial.println("Set Hour");
	set_hour();
	display.write_number(my_minute);
	Serial.println("Set Minute");
	set_minute();

	setTime(my_hour,my_minute,0,0,0,0);
	Serial.print("Set time with ");
	Serial.print(my_hour);
	Serial.print(":");
	Serial.println(my_minute);
}

void IRBlaster::set_hour(){
	display.set_blink(true);
	while(digitalRead(ACCEPT_PIN) == HIGH){
		tick(&my_hour);
		if (my_hour > 23){
			my_hour = 0;
			display.write_number(my_hour);
		}
	}
	Serial.println("Hour Accepted");
	display.set_blink(false);
	display.delay_with_refresh(300);
}

void IRBlaster::set_minute(){
	display.set_blink(true);
	while(digitalRead(ACCEPT_PIN) == HIGH){
		tick(&my_minute);
		if (my_minute > 59){
			my_minute = 0;
			display.write_number(my_minute);
		}
	}
	Serial.println("Minute Accepted");
	display.set_blink(false);
	display.delay_with_refresh(300);
}
