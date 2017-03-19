

#ifndef display_h
#define display_h
#include <Arduino.h>


#define DISP0 4
#define DISP1 5
#define DISP2 6
#define DISP3 8
#define DISP4 10
#define DISP5 9
#define DISP6 7


class Display {
public:
	void init();
	void write_number(int number);
private:
	void clear_display();
};



#endif // display_h
