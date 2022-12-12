#include "usr_tasks.h"
#include "stdbool.h"
////////////////////////////////////////////////
static bool JOY_L_key_is_pressed(void) {
	return HAL_GPIO_ReadPin(JOY_L_GPIO_Port, JOY_L_Pin);
}
static void Turn_on_LD_R(void) {
	    if (HAL_GPIO_ReadPin(JOY_L_GPIO_Port, JOY_L_Pin)) { // Checking the left key of the Joystick
#if defined(STM32L476xx) 
        HAL_GPIO_WritePin(LD_R_GPIO_Port, LD_R_Pin, GPIO_PIN_SET); 
#elif defined(STM32F412Zx)  
        HAL_GPIO_WritePin(LD_R_GPIO_Port, LD_R_Pin, GPIO_PIN_RESET);         
#endif
    } else {
        HAL_GPIO_WritePin(LD_R_GPIO_Port, LD_R_Pin, GPIO_PIN_SET); 
        HAL_Delay(200);  
    }
}
static void Turn_off_LD_R(void) {
	    if (HAL_GPIO_ReadPin(JOY_L_GPIO_Port, JOY_L_Pin)) { // Checking the left key of the Joystick
#if defined(STM32L476xx) 
        HAL_GPIO_WritePin(LD_R_GPIO_Port, LD_R_Pin, GPIO_PIN_SET); 
#elif defined(STM32F412Zx)  
        HAL_GPIO_WritePin(LD_R_GPIO_Port, LD_R_Pin, GPIO_PIN_RESET);         
#endif
    } else {
        HAL_GPIO_WritePin(LD_R_GPIO_Port, LD_R_Pin, GPIO_PIN_RESET); 
        HAL_Delay(200);  
    }
}
void USR_Task_RunLoop(void) {
	if(JOY_L_key_is_pressed()){
		Turn_on_LD_R();
		HAL_Delay(200);
	}
	else{
		Turn_off_LD_R();
	}
}
void USR_Task_Flash_LD_R_3Times(void) {
 
	for(int i = 0; i < 9; i++) {
		HAL_GPIO_TogglePin(LD_R_GPIO_Port, LD_R_Pin); 
    HAL_Delay(200); 
	}
}