

#ifndef IRBlaster_h
#define IRBlaster_h
#include <Arduino.h>
#include "display.h"


class IRBlaster{
public:
	void init();
	void tick();
private:
	Display display;
	int count;
};

#endif // IRBlaster_h
