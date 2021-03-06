#include "Led.h"

//static allocation
Led led1(RED,ON);//constructor ile atama

LedState_Type led1_state;
LedState_Type led2_state;
LedState_Type led3_state;

int main(void){

  USART2_Init();
	
	//automatic allocation
	Led led2(BLUE,ON);
	
	//dynamic allocation malloc
	Led *led3 = new Led(YELLOW,ON);
	
	led1_state = led1.Led_getState();
	led2_state = led2.Led_getState();
	led3_state = led3->Led_getState();
	
	led1.Led_setState(OFF);
	led2.Led_setState(OFF);
	led3->Led_setState(OFF);
	
	delete led3;
	while(1){
	
	}
}
