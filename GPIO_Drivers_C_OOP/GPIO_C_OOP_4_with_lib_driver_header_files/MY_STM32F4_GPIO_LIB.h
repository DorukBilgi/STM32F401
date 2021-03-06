#ifndef __MY_STM32F4_GPIO_LIB_H__
#define __MY_STM32F4_GPIO_LIB_H__

#include "my_STM32F4_gpio_driver.h"

//Reference manual 
//GPIO main features Up to 16 I/Os under control
#define GPIO_PIN_0    ((uint16_t)0x0001) //00000000000000001
#define GPIO_PIN_1    ((uint16_t)0x0002)
#define GPIO_PIN_2    ((uint16_t)0x0004)
#define GPIO_PIN_3    ((uint16_t)0x0008)
#define GPIO_PIN_4    ((uint16_t)0x0010)
#define GPIO_PIN_5    ((uint16_t)0x0020)
#define GPIO_PIN_6    ((uint16_t)0x0040)
#define GPIO_PIN_7    ((uint16_t)0x0080)
#define GPIO_PIN_8    ((uint16_t)0x0100)
#define GPIO_PIN_9    ((uint16_t)0x0200)
#define GPIO_PIN_10   ((uint16_t)0x0400)
#define GPIO_PIN_11   ((uint16_t)0x0800)
#define GPIO_PIN_12   ((uint16_t)0x1000)
#define GPIO_PIN_13   ((uint16_t)0x2000)
#define GPIO_PIN_14   ((uint16_t)0x4000)
#define GPIO_PIN_15   ((uint16_t)0x8000)
#define GPIO_PIN_ALL  ((uint16_t)0xFFFF)
//GPIO port mode register MODER

#define GPIO_MODE_INPUT       0x00U //reset state                            00
#define GPIO_MODE_OUTPUT_PP   0x01U //General purpose output mode, push pull 01
#define GPIO_MODE_AF_PP       0x02U //Alternate function mode, push pull     10

//GPIO port pull-up/pull-down register
#define GPIO_NOPULL           0x00U //00: No pull-up, pull-down
#define GPIO_PULLUP           0x01U //01: Pull-up
#define GPIO_PULLDOWN         0x02U //10: Pull-down

typedef struct{

	uint32_t  Pin;
	uint32_t  Mode;
	uint32_t  Pull;
	uint32_t  Speed;
	uint32_t  Alternate;
	
}GPIO_InitTypedDef;


typedef enum{

GPIO_PIN_0_RESET = 0,
GPIO_PIN_0_SET//otomatik 1 atanir, asagilara inersen 1,2,3 atanir

}GPIO_PinState;

//declare member functions
void LIB_GPIO_Init             (GPIO_TypeDef *GPIOx, GPIO_InitTypedDef *GPIO_Init); //MY_STM32F4_gpio_driver_H dosyasindaki GPIO_TypeDef structina adresleme yapti *GPIOx 
GPIO_PinState LIB_GPIO_ReadPin (GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);
void LIB_GPIO_WritePin         (GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin, GPIO_PinState PinState);
void LIB_GPIO_TooglePin        (GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);

//hangi gpio ise (A-H) onun clk enable olmali
void __LIB_RCC_GPIOA_CLK_ENABLE(void);
void __LIB_RCC_GPIOB_CLK_ENABLE(void);
void __LIB_RCC_GPIOC_CLK_ENABLE(void);
void __LIB_RCC_GPIOD_CLK_ENABLE(void);
void __LIB_RCC_GPIOE_CLK_ENABLE(void);
void __LIB_RCC_GPIOF_CLK_ENABLE(void);
void __LIB_RCC_GPIOG_CLK_ENABLE(void);
void __LIB_RCC_GPIOH_CLK_ENABLE(void);

#endif
