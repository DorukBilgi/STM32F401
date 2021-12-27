#include "UART.h"

void USART2_Init(void){
//1. enable clock access to UART 
	RCC -> APB1ENR |= 0x20000; //enables pin 17 | bu sadece 17. biti yapiyor
//2. enable clock access to port A
	RCC -> AHB1ENR |= 0x00000001;
//3. Enable pins for alternate functions, pa2, pa3
	GPIOA->MODER &= ~0x00F0;
	GPIOA->MODER |= 0x00A0; //enable alt. func. for pa2, pa3
//4. Configure type of alternate function
 GPIOA -> AFR[0] &= ~0xFF00;
 GPIOA -> AFR[0] |= 0x7700;	
//Configure UART read/transmit
	
	//DATA SHEET
	USART2->BRR = 0x0683;//BAUD RATE
	USART2->CR1 = 0x000C;//CONTROL REGISTER 1 enable tx rx 8-bit data
	USART2->CR2 = 0x000;//CONTROL REGISTER 2
	USART2->CR3 = 0x000;//CONTROL REGISTER 3
	USART2->CR1 |= 0x2000;//CONTROL REGISTER 1 enable uart
	
}

//send CHAR to COMP
int USART2_write(int ch){
	
	while(!(USART2->SR & 0x0080)){} //STATUS REGISTER (if not empty wait)
	USART2->DR = (ch & 0xFF); //DATA REGISTER
		
	return ch;
	
}

int USART2_read(void){
	
	while(!(USART2->SR & 0x0020)){} //STATUS REGISTER (if not empty wait)
		
	return USART2->DR;
}

struct _FILE {int handle;};
FILE __stdin  = {0};
FILE __stdout = {1};
FILE __stderr = {2};

int fgetc(FILE *f) {
	int c;
	
	c = USART2_read();
	
	if(c == '\r') {
		 USART2_write(c);
		 c= '\n';
	}
	
	USART2_write(c);
	
	return c;
	
}

int fputc(int c, FILE *f) {
	return USART2_write(c);
}

int n;
char str[80];


void test_setup(void){
	
	printf("please enter a number: ");
	scanf("%d", &n);
	printf("The number entered is: %d\r\n", n);
	printf("please type a character string: ");
	gets(str);
	printf("The character entered string is: ");
	puts(str);
	printf("\r\n");
	
}
