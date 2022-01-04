#include "my_STM32F4_gpio_lib.h"//_driver.h otomatik mainde kullanilabilir.



GPIO_InitTypedDef myGPIO_InitStruct;

int main(void){

	
	myGPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	myGPIO_InitStruct.Pin  = GPIO_PIN_5;
	myGPIO_InitStruct.Pull = GPIO_NOPULL;
	
  __LIB_RCC_GPIOA_CLK_ENABLE();
	LIB_GPIO_Init(GPIOA,&myGPIO_InitStruct);


	while(1){
	   for(int i =0;i< 900000;i++){}
			 LIB_GPIO_TooglePin(GPIOA,GPIO_PIN_5);

	}
   
}
