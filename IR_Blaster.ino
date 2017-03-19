#include "Arduino.h"
#include "IRLib.h"
#include "IRLibTimer.h"
#include "LiquorLEDCodes.h"
#include "TVLEDCodes.h"
#include "display.h"
#include <avr/sleep.h>

//Create a receiver object to listen on pin 11
IRrecv My_Receiver(11);

//Create a decoder object
IRdecode My_Decoder;
IRsendNEC My_Sender;

Display display;

void setup()
{
  Serial.begin(9600);
  delay(500);
  Serial.println("Ok, let's see if this works!d!");
//  My_Receiver.enableIRIn(); // Start the receiver
  display.init();
  for (int i = 0; i < 10; i++) {
	  display.write_number(i);
	  delay(1000);
  }

}

void loop() {

}




void listen_for_IR_code(){
	if (My_Receiver.GetResults(&My_Decoder)) {
		Serial.println("Passing to decoder");
		My_Decoder.decode();		//Decode the data
		My_Decoder.DumpResults();	//Show the results on serial monitor
		My_Receiver.resume(); 		//Restart the receiver
	}
}

void send_IR_code(){
  if (Serial.read() != -1) {
	Serial.println("Sending");
	//send a code every time a character is received from the serial port
	My_Sender.send(TVLED_POWER_ON);
	Serial.println("sent on.");
	delay(5000);
	My_Sender.send(TVLED_POWER_OFF);
	Serial.println("sent off.");
  }
}
