#include "Led.h"

//Definition of Member Functions
void Led_ctor(Led_Type * const me, LedColor_Type _color, LedState_Type _state) {
	
	me->color = _color; //by pointer
	me->state = _state; //by pointer
	
	//HARDWARE INITIALIZE!!!
	RCC->AHB1ENR |= LED_PORT_CLOCK; // GPIOB EN SETB TIMER BIT
	
	switch(_color){
	
		case RED:
			LED_PORT->MODER |= LED_RED_MODE_BIT;
			if(me->state == ON){
				LED_PORT->ODR |= LED_RED_PIN;
				printf("The RED LED is set ON \n\r");
			}
			else {
				LED_PORT->ODR &= ~LED_RED_PIN;
			  printf("The RED LED is set OFF \n\r");
	}
	break;
	
	case YELLOW:
			LED_PORT->MODER |= LED_YELLOW_MODE_BIT;
			if(me->state == ON){
				LED_PORT->ODR |= LED_YELLOW_PIN;
				printf("The YELLOW LED is set ON \n\r");
			}
			else {
				LED_PORT->ODR &= ~LED_YELLOW_PIN;
			  printf("The YELLOW LED is set OFF \n\r");
	}
	break;
	
	case BLUE:
			LED_PORT->MODER |= LED_BLUE_MODE_BIT;
			if(me->state == ON){
				LED_PORT->ODR |= LED_BLUE_PIN;
				printf("The BLUE LED is set ON \n\r");
			}
			else {
				LED_PORT->ODR &= ~LED_BLUE_PIN;
			  printf("The BLUE LED is set OFF \n\r");
	}
	break;
	
	case GREEN:
			LED_PORT->MODER |= LED_GREEN_MODE_BIT;
			if(me->state == ON){
				LED_PORT->ODR |= LED_GREEN_PIN;
				printf("The GREEN LED is set ON \n\r");
			}
			else {
				LED_PORT->ODR &= ~LED_GREEN_PIN;
			  printf("The GREEN LED is set OFF \n\r");
	}
	break;
	
 }
	
}

void Led_setState(Led_Type * const me, LedState_Type _state){
	
	me->state = _state;
	
	switch(me->color){
	
		case RED:
			LED_PORT->MODER |= LED_RED_MODE_BIT;
			if(me->state == ON){
				LED_PORT->ODR |= LED_RED_PIN;
				printf("The RED LED is set ON \n\r");
			}
			else {
				LED_PORT->ODR &= ~LED_RED_PIN;
			  printf("The RED LED is set OFF \n\r");
	}
	break;
	
	case YELLOW:
			LED_PORT->MODER |= LED_YELLOW_MODE_BIT;
			if(me->state == ON){
				LED_PORT->ODR |= LED_YELLOW_PIN;
				printf("The YELLOW LED is set ON \n\r");
			}
			else {
				LED_PORT->ODR &= ~LED_YELLOW_PIN;
			  printf("The YELLOW LED is set OFF \n\r");
	}
	break;
	
	case BLUE:
			LED_PORT->MODER |= LED_BLUE_MODE_BIT;
			if(me->state == ON){
				LED_PORT->ODR |= LED_BLUE_PIN;
				printf("The BLUE LED is set ON \n\r");
			}
			else {
				LED_PORT->ODR &= ~LED_BLUE_PIN;
			  printf("The BLUE LED is set OFF \n\r");
	}
	break;
	
	case GREEN:
			LED_PORT->MODER |= LED_GREEN_MODE_BIT;
			if(me->state == ON){
				LED_PORT->ODR |= LED_GREEN_PIN;
				printf("The GREEN LED is set ON \n\r");
			}
			else {
				LED_PORT->ODR &= ~LED_GREEN_PIN;
			  printf("The GREEN LED is set OFF \n\r");
	}
	break;
	
 }
	
}
LedState_Type Led_getState(Led_Type * const me){

switch(me->color){
		
		case RED:
			   printf("The RED Led is cureently %d \n\r",me->state);
				 break;
	  case GREEN:
			   printf("The GREEN Led is cureently %d \n\r",me->state);
				 break;
		case BLUE:
			   printf("The BLUE Led is cureently %d\n\r",me->state);
				 break;
		case YELLOW:
			   printf("The YELLOW Led is cureently  %d \n\r",me->state);
				 break;
		
		
	 }
  
	return me->state;


}
