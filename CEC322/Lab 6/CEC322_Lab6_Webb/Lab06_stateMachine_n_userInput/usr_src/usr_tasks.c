#include "usr_tasks.h"
#include "stdbool.h"
// 2 seconds = 2000 ms
///////////////////////////////////////////////

#if defined(STM32F412Zx)

#define LED_ON GPIO_PIN_RESET
#define LED_OFF GPIO_PIN_SET
#define LD_R_ON HAL_GPIO_WritePin(LD_R_GPIO_Port, LD_R_Pin, LED_ON)
#define LD_G_ON HAL_GPIO_WritePin(LD_R_GPIO_Port, LD_G_Pin, LED_ON)
#define LD_R_OFF HAL_GPIO_WritePin(LD_R_GPIO_Port, LD_R_Pin, LED_OFF)
#define LD_G_OFF HAL_GPIO_WritePin(LD_G_GPIO_Port, LD_G_Pin, LED_OFF)
#define LD_R_TOGGLE HAL_GPIO_TogglePin(LD_R_GPIO_Port, LD_R_Pin)
#define LD_G_TOGGLE HAL_GPIO_TogglePin(LD_G_GPIO_Port, LD_G_Pin)
#define JOY_C_IS_PRESSED HAL_GPIO_ReadPin(JOY_C_GPIO_Port, JOY_C_Pin)
#define JOY_L_IS_PRESSED HAL_GPIO_ReadPin(JOY_L_GPIO_Port, JOY_L_Pin)
#define JOY_R_IS_PRESSED HAL_GPIO_ReadPin(JOY_R_GPIO_Port, JOY_R_Pin)

#endif

//Given Code
enum progState{State0 = 0, State1 = 1, State2 = 2, State3 = 3, State4 = 4};
enum progState currentState = State1;
bool stateChanged = true;
uint32_t bDelay = 100;

void LD_R_G_flash(void);

void USR_Task_RunLoop(void) {
switch (currentState) {
//State0
case State0:
if (stateChanged) {
	currentState = State1;
	stateChanged = true;
}
break;
//State 1
case State1:
	if (stateChanged) {
		LD_R_G_flash();
		stateChanged = false;
	}
	if (JOY_C_IS_PRESSED) {
		currentState = State2;
		stateChanged = true;
		HAL_Delay(bDelay);
		break;
	}
	LD_R_ON;
	LD_G_OFF;
	break;
//State 2
case State2:
	if (stateChanged) {
		LD_R_G_flash();
		stateChanged = false;
		LD_G_ON;
		LD_R_ON;
	}
	if (JOY_L_IS_PRESSED) {
	// provide your code to handle the left Joy key input.
		currentState = State1;
		stateChanged = true;
		HAL_Delay(bDelay);

		break;
	}
	if (JOY_R_IS_PRESSED) {
	// provide your code to handle the right Joy key input.
		currentState = State3;
		stateChanged = true;
		HAL_Delay(bDelay);
		break;
	}
	// provide your code for LED control
	LD_G_ON;
	LD_R_ON;
	break;
//State 3
case State3:
	if(stateChanged) {
		LD_R_G_flash();
		stateChanged = false;
		// provide your code
		// note that you need also provide your code so that the
		// LEDs will blink alternately.
		LD_R_ON;
		LD_R_TOGGLE;
		LD_G_TOGGLE;
		HAL_Delay(bDelay);
	}
	if(JOY_L_IS_PRESSED) {
	// provide your code to handle the left Joy key input.
		currentState = State1;
		stateChanged = true;
		HAL_Delay(bDelay);
		break;
	}
		LD_R_TOGGLE;
		LD_G_TOGGLE;
		HAL_Delay(bDelay);
		break;
		default:
		LD_R_OFF;
		LD_G_OFF;
		break;
	}
}

void LD_R_G_flash(void) {
	for (int i = 0; i < 3; i++) {
		LD_R_OFF;
		LD_G_OFF;
		HAL_Delay(100);
		LD_R_ON;
		LD_G_ON;
		HAL_Delay(100);
	}
	LD_R_OFF;
	LD_G_OFF;
	HAL_Delay(500);
}