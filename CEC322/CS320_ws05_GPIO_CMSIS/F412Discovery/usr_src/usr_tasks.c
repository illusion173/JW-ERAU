#include "usr_tasks.h"
#include <stdbool.h>
#if defined(STM32L476xx)
#define LED_ON GPIO_PIN_SET
#define LED_OFF GPIO_PIN_RESET
#elif defined(STM32F412Zx)
#define LED_ON GPIO_PIN_RESET
#define LED_OFF GPIO_PIN_SET
#define GPIO_NUMBER	16U
#endif
// Prototype of static (private) functions
static bool JOY_L_Is_Pressed(void);
static bool JOY_R_Is_Pressed(void);
static void LD_R_Toggle(void);
static void LD_G_Toggle(void);
static void LD_R_On(void);
static void LD_R_Off(void);
static void LD_G_On(void);
static void LD_G_Off(void);

/* original Functions I had
static bool JOY_L_Is_Pressed(void) {
return HAL_GPIO_ReadPin(JOY_L_GPIO_Port, JOY_L_Pin);
}
static bool JOY_R_Is_Pressed(void){
	
	return HAL_GPIO_ReadPin(JOY_R_GPIO_Port, JOY_R_Pin);
}
static void LD_R_On(void) {
	HAL_GPIO_WritePin(LD_R_GPIO_Port, LD_R_Pin, LED_ON);
}

static void LD_R_Off(void) {
	HAL_GPIO_WritePin(LD_R_GPIO_Port, LD_R_Pin, LED_OFF);
}

static void LD_G_On(void) {
	HAL_GPIO_WritePin(LD_G_GPIO_Port, LD_G_Pin, LED_ON);
}
static void LD_G_Off(void) {
	HAL_GPIO_WritePin(LD_G_GPIO_Port, LD_G_Pin, LED_OFF);
}

static void LD_R_Toggle(){
	
HAL_GPIO_TogglePin(LD_R_GPIO_Port, LD_R_Pin);
}

static void LD_G_Toggle(){
	HAL_GPIO_TogglePin(LD_G_GPIO_Port, LD_G_Pin);
}
*/ 

//CMSIS Operations
static void CMS_GPIO_WritePin(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, GPIO_PinState PinState) {
if(PinState != GPIO_PIN_RESET) {
	GPIOx->ODR |= (uint32_t)GPIO_Pin;
} else {
	GPIOx->ODR &= ~((uint32_t)GPIO_Pin);
}
}
void CMS_GPIO_TogglePin(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
{
  assert_param(IS_GPIO_PIN(GPIO_Pin));
  if ((GPIOx->ODR & GPIO_Pin) == GPIO_Pin)
  {
    GPIOx->BSRR = (uint32_t)GPIO_Pin << GPIO_NUMBER;
  }
  else
  {
    GPIOx->BSRR = GPIO_Pin;
  }
}

GPIO_PinState CMS_GPIO_ReadPin(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
{
  GPIO_PinState bitstatus;
  assert_param(IS_GPIO_PIN(GPIO_Pin));

  if((GPIOx->IDR & GPIO_Pin) != (uint32_t)GPIO_PIN_RESET)
  {
    bitstatus = GPIO_PIN_SET;
  }
  else
  {
    bitstatus = GPIO_PIN_RESET;
  }
  return bitstatus;
}

static bool JOY_L_Is_Pressed(void) {
return CMS_GPIO_ReadPin(JOY_L_GPIO_Port, JOY_L_Pin);
}
static bool JOY_R_Is_Pressed(void){
	
	return CMS_GPIO_ReadPin(JOY_R_GPIO_Port, JOY_R_Pin);
}
static void LD_R_On(void) {
	CMS_GPIO_WritePin(LD_R_GPIO_Port, LD_R_Pin, LED_ON);
}

static void LD_R_Off(void) {
	CMS_GPIO_WritePin(LD_R_GPIO_Port, LD_R_Pin, LED_OFF);
}

static void LD_G_On(void) {
	CMS_GPIO_WritePin(LD_G_GPIO_Port, LD_G_Pin, LED_ON);
}
static void LD_G_Off(void) {
	CMS_GPIO_WritePin(LD_G_GPIO_Port, LD_G_Pin, LED_OFF);
}

static void LD_R_Toggle(){
	
CMS_GPIO_TogglePin(LD_R_GPIO_Port, LD_R_Pin);
}

static void LD_G_Toggle(){
	CMS_GPIO_TogglePin(LD_G_GPIO_Port, LD_G_Pin);
}

void USR_Task_RunLoop(void) {
	
if (JOY_L_Is_Pressed()) {
	
		LD_R_On();
		LD_G_Off();
	
}else if (JOY_R_Is_Pressed()) {
	
	LD_G_On();
	LD_R_Off();
	
}else {
	
		LD_R_Toggle();
		HAL_Delay(50);
		LD_G_Toggle();
		HAL_Delay(50);
	
		}
}
