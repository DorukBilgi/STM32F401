#ifndef LED_H
#define LED_H

#include <stdint.h>
#include "UART.h"

//OOP
#include "stm32f4xx.h"                  // Device header
#define LED_PORT GPIOB //GPIO 

#define LED_PORT_CLOCK (1U<<1) //1 bitini 1 pozisyonuna kaydet

#define LED_RED_PIN    (1U<<14) //14 bitini 1 pozisyonuna SETB
#define LED_GREEN_PIN  (1U<<12)
#define LED_BLUE_PIN   (1U<<15)
#define LED_YELLOW_PIN (1U<<13)
//DATA SHEETTEN MODER14,12,15,13 MODER 01 set edilecek

#define LED_RED_MODE_BIT    (1U<<28)
#define LED_GREEN_MODE_BIT  (1U<<24)
#define LED_YELLOW_MODE_BIT (1U<<26)
#define LED_BLUE_MODE_BIT   (1U<<30)


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

class Led {
	
	public:
		//constructor
		Led(LedColor_Type _color, LedState_Type _state);
		//member Function
	  void Led_setState(LedState_Type _state);
	  LedState_Type Led_getState() const;
	
	private:
		
	//member variables
	  LedColor_Type color; //Color of LED
	  LedState_Type state; //State of LED
	
	
};

#endif
