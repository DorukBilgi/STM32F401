#ifndef LED_H
#define LED_H

#include <stdint.h>
#include "UART.h"

//interface
typedef enum {

RED = 0,
GREEN,     //1
YELLOW,    //1
BLUE 	     //1

}LedColor_Type;

typedef enum { 

	OFF = 0,
	ON = 1

}LedState_Type;


//Led's attribute

typedef struct {
	
	LedColor_Type color; //Color of LED
	LedState_Type state; //State of LED
	
}Led_Type;

//Declaration of member functions
void Led_ctor(Led_Type * const me, LedColor_Type _color, LedState_Type _state);
void Led_setState(Led_Type * const me, LedState_Type _state);
LedState_Type Led_getState(Led_Type * const me);

#endif
