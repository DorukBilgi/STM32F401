#include "Led.h"

//Definition of Member Functions
//constructor da member function gibi tanimlaniyor
Led::Led(LedColor_Type _color, LedState_Type _state) 
//Option 2
//:color(_color),
// state(_state)
{
	
	//Option 1: me pointeri kullanmiyoruz c++ this bu ise yariyor
	this->color = _color; //by pointer
	this->state = _state; //by pointer
	
	//HARDWARE INITIALIZE!!!
	RCC->AHB1ENR |= LED_PORT_CLOCK; // GPIOB EN SETB TIMER BIT
	
	switch(_color){
	
		case RED:
			LED_PORT->MODER |= LED_RED_MODE_BIT;
			if(this->state == ON){
				LED_PORT->ODR |= LED_RED_PIN;
				
			}
			else {
				LED_PORT->ODR &= ~LED_RED_PIN;
			
	}
	break;
	
	case YELLOW:
			LED_PORT->MODER |= LED_YELLOW_MODE_BIT;
			if(this->state == ON){
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
			if(this->state == ON){
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
			if(this->state == ON){
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

void Led::Led_setState(LedState_Type _state){
	//tüm "me" ler yerine this yaziliyor
	this->state = _state;
	
	switch(this->color){
	
		case RED:
			LED_PORT->MODER |= LED_RED_MODE_BIT;
			if(this->state == ON){
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
			if(this->state == ON){
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
			if(this->state == ON){
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
			if(this->state == ON){
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
LedState_Type Led::Led_getState(void)const{

switch(this->color){
		
		case RED:
			   printf("The RED Led is cureently %d \n\r",this->state);
				 break;
	  case GREEN:
			   printf("The GREEN Led is cureently %d \n\r",this->state);
				 break;
		case BLUE:
			   printf("The BLUE Led is cureently %d\n\r",this->state);
				 break;
		case YELLOW:
			   printf("The YELLOW Led is cureently  %d \n\r",this->state);
				 break;
		
		
	 }
  
	return this->state;


}
