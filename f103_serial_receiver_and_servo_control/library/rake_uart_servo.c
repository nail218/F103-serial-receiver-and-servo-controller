/* Private includes ----------------------------------------------------------*/

#include "rake_uart_servo.h"

/* Extern variables -----------------------------------------------*/

extern TIM_HandleTypeDef htim2;
extern Rake_Uart_HandleTypeDef ruart1;


int len, pwm_value[4];
int channel[4]={TIM_CHANNEL_1,TIM_CHANNEL_2,TIM_CHANNEL_3,TIM_CHANNEL_4};

/* Private functions -----------------------------------------------*/
void PWM_start(TIM_HandleTypeDef *htim){
	uint8_t i;
	for(i=0;i<4;i++){
	HAL_TIM_PWM_Start( &htim2, channel[i]);
	}
}


void PWM_transmission(TIM_HandleTypeDef *htim){
	uint8_t j;	
		for(j=0;j<4;j++){
			__HAL_TIM_SET_COMPARE(&htim2, channel[j], pwm_value[j]);//Passing pwm value to timer1 output pin
			HAL_Delay(100);
		}
}


void PWM_calculation(){
	pwm_value[0]=((ruart1.Rx_Buffer[1] - '0') * 100 )+((ruart1.Rx_Buffer[2] - '0') * 10 )+(ruart1.Rx_Buffer[3] - '0');
	pwm_value[1]=((ruart1.Rx_Buffer[5] - '0') * 100 )+((ruart1.Rx_Buffer[6] - '0') * 10 )+(ruart1.Rx_Buffer[7] - '0');
	pwm_value[2]=((ruart1.Rx_Buffer[9] - '0') * 100 )+((ruart1.Rx_Buffer[10] - '0') * 10 )+(ruart1.Rx_Buffer[11] - '0');
	pwm_value[3]=((ruart1.Rx_Buffer[13] - '0') * 100 )+((ruart1.Rx_Buffer[14] - '0') * 10 )+(ruart1.Rx_Buffer[15] - '0');
	//PWM values must be 25 between 125 for truthly motion of the servo motors. 



}
