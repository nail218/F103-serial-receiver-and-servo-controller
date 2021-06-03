/**
  * @file           : rake_uart_servo.h
  * @brief          : Header for rake_uart_servo.c file.
	*/
	
#ifndef RAKE_UART_SERVO_H
#define RAKE_UART_SERVO_H

#ifdef __cplusplus
extern "C" {
#endif
 
/* Private includes ----------------------------------------------------------*/

#include "stm32f1xx_hal.h"

/* Private variables ----------------------------------------------------------*/



typedef struct UART_struct{
   unsigned char Rx_indx;	
	 unsigned char Rx_data[2];
	 unsigned char Rx_Buffer[50];
	 unsigned char Transfer_cplt;
}Rake_Uart_HandleTypeDef; 



/* Private function prototypes -----------------------------------------------*/

void PWM_transmission(TIM_HandleTypeDef *htim);
void PWM_start(TIM_HandleTypeDef *htim);
void PWM_calculation(void);


#ifdef __cplusplus
}
#endif

#endif  /* RAKE_UART_SERVO_H */

