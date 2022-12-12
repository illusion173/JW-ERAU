#include "usr_tasks.h"
#include "stdbool.h"
// 2 seconds = 2000 ms
///////////////////////////////////////////////

#if defined(STM32L476xx)
#define LED_ON GPIO_PIN_SET
#define LED_OFF GPIO_PIN_RESET
#elif defined(STM32F412Zx)
#define LED_ON GPIO_PIN_RESET
#define LED_OFF GPIO_PIN_SET
#endif

//Learned what Macros are by Troy Neubauer, extremely helpful, made this a lot simpler
//Macro to receive information of pin, put into Hal function
#define ReadPin(pin) HAL_GPIO_ReadPin(pin##_GPIO_Port, pin##_Pin)
//Macro to Write a specific thing to the pin, as received from the if statements below
#define WriteToPin(pin, value)HAL_GPIO_WritePin(pin##_GPIO_Port, pin##_Pin, value)
//Macro to Toggle pin, depending on the input using Hal Function
#define TogglePin(pin) HAL_GPIO_TogglePin(pin##_GPIO_Port, pin##_Pin)
void USR_Task_RunLoop(void) {
	uint8_t up = ReadPin(JOY_U);
	uint8_t center = ReadPin(JOY_C);
	uint8_t down = ReadPin(JOY_D);
  uint8_t left = ReadPin(JOY_L);
  uint8_t right = ReadPin(JOY_R);
  
	//if up is pressed, Green on, red On
	 if (up) {
    WriteToPin(LD_R, LED_ON);
    WriteToPin(LD_G, LED_ON);
  }
	 //If down is pressed, both are off
	 else if (down) {
    WriteToPin(LD_R, LED_OFF);
    WriteToPin(LD_G, LED_OFF);
  }
	 //If Center is pressed, both turn on and off every 2 seconds
	 else if (center) {
    WriteToPin(LD_R, LED_ON);
    WriteToPin(LD_G, LED_ON);
    for (uint32_t i = 0; i < 10; i++) {
      TogglePin(LD_R);
      TogglePin(LD_G);
      HAL_Delay(200);
    }
    // Toggle Green to begin alternation
    TogglePin(LD_G);
		}
	 //If right is pressed, Red is off, green is on for two seconds
		else if (right) {
    WriteToPin(LD_R, LED_OFF);
    WriteToPin(LD_G, LED_ON);
		}
		//If Left is pressed, Red is on for two seconds, green is off
		else if (left) {
		WriteToPin(LD_R, LED_ON);
    WriteToPin(LD_G, LED_OFF);
		} 
		else {
    TogglePin(LD_R);
    TogglePin(LD_G);
    HAL_Delay(100);
  }
	//Needed some help with this one, Wouldn't work with the Hal_Delay(2000), this seemed to work, closest I could get it to
  if (up || down || left || right) {
    HAL_Delay(1999);
    WriteToPin(LD_R, LED_ON);
    WriteToPin(LD_G, LED_OFF);
    HAL_Delay(1);
  }
}

//Turn Red on, Green off.
void USR_Task_LD_R_on_LD_G_off(void) {
  HAL_GPIO_WritePin(LD_R_GPIO_Port, LD_R_Pin, GPIO_PIN_SET); 
  HAL_GPIO_WritePin(LD_G_GPIO_Port, LD_G_Pin, GPIO_PIN_RESET);
}


// IGNORE
//Boolean Function
//Examples for later
/*
void USR_Task_LD_R_on_LD_G_off(void){
	HAL_GPIO_WriteToPin(LD_R_GPIO_Port, LD_R_Pin, GPIO_PIN_SET); 
  HAL_GPIO_WriteToPin(LD_G_GPIO_Port, LD_G_Pin, GPIO_PIN_RESET);
}

void USR_Task_LD_R_on_LD_G_ON(void){
	HAL_GPIO_WriteToPin(LD_R_GPIO_Port, LD_R_Pin, GPIO_PIN_SET); 
  HAL_GPIO_WriteToPin(LD_G_GPIO_Port, LD_G_Pin, GPIO_PIN_SET);
}
*/
// Up Key is pressed
/*
void USR_Task_RunLoop(void) {
	if(JOY_U_key_is_pressed()){
		USR_Task_LD_R_on_LD_G_ON(void);
		HAL_Delay(2000);
	}
	else{
		Turn_off_LD_R();
	}
}

*/

//Down Key is pressed
/*
void USR_Task_RunLoop(void) {
	if(JOY_D_key_is_pressed()){
		USR_Task_LD_R_on_LD_G_ON(void);
		HAL_Delay(2000);
	}
	else{
		Turn_off_LD_R();
	}
}
*/