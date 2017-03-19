

#ifndef IRBlaster_h
#define IRBlaster_h
#include <Arduino.h>
#include "display.h"
#include "Time.h"
#include "TVLEDCodes.h"
#include "LiquorLEDCodes.h"
#include "IRLib.h"
#include "IRLibTimer.h"


#define INCREMENT_PIN 12
#define ACCEPT_PIN 13

#define HOUR_TO_TURN_ON 18
#define MINUTE_TO_TURN_ON 0
#define HOUR_TO_TURN_OFF 23
#define MINUTE_TO_TURN_OFF 0


class IRBlaster{
public:
	void init();
	void tick();
	void set_time();
private:
	void set_hour();
	void set_minute();
	void tick(int *number_to_increment);

	Display display;
	int count_since_last_time_check;
	int my_hour;
	int my_minute;
	IRsendNEC MySender;
};

#endif // IRBlaster_h
