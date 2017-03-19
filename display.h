

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

#define TENS_DIGIT_PIN 3
#define ONES_DIGIT_PIN 2
#define INCREMENT_PIN 12
#define ACCEPT_PIN 13


class Display {
public:
	void init();
	void write_number(int number);
	void refresh();
private:
	void clear_display();
	void write_digit(int number, int digit);
	void delay_with_refresh(int delay_length);


	int first_digit;
	int second_digit;
};



#endif // display_h
