#include "usr_tasks.h"
#include "stdbool.h"
#include "math.h"
#include "stdlib.h"

// Definitions used to handle different MCUs
#if defined(STM32L476xx) 
    extern int32_t                      RecBuff[2048];
    extern uint32_t                     DmaRecHalfBuffCplt;
    extern uint32_t                     DmaRecBuffCplt;
    #define LED_red LED4 
    #define LED_grn LED5 
    extern SAI_HandleTypeDef            SaiHandle;
    #define LOOP_STATE1 40000
    #define LOOP_STATE2 40000
    #define LOOP_STATE3 40000
    #define AUDIO_STATE1 1 << 4
    #define AUDIO_STATE2 1 << 4
    #define AUDIO_STATE3 1 << 4
#elif defined(STM32F412Zx)  
    extern int32_t                      LeftRecBuff[2048];
    extern int32_t                      RightRecBuff[2048];
    extern uint32_t                     DmaLeftRecHalfBuffCplt;
    extern uint32_t                     DmaLeftRecBuffCplt;
    extern uint32_t                     DmaRightRecHalfBuffCplt;
    extern uint32_t                     DmaRightRecBuffCplt;
    #define LED_red LED3 
    #define LED_grn LED1       
    extern I2S_HandleTypeDef            haudio_i2s;   
    #define LOOP_STATE1 130000
    #define LOOP_STATE2 65000
    #define LOOP_STATE3 32500
    #define AUDIO_STATE1 1000 << 4
    #define AUDIO_STATE2 2045 << 4
    #define AUDIO_STATE3 10000 << 4   
#endif

extern int16_t                      PlayBuff[4096];
extern AUDIO_DrvTypeDef            *audio_drv;
extern uint32_t                     PlaybackStarted;


/* Private macro -------------------------------------------------------------*/
#define SaturaLH(N, L, H) (((N)<(L))?(L):(((N)>(H))?(H):(N)))


/* Prototypes of private functions */
void play_sound(void);
int find_audio_max(void);
void operate_red_LED(int max_value);
void copy_from_rec_to_play(void);


// Global variables 
enum progState{State0 = 0, State1, State2, State3};
enum progState currentState = State0;
bool stateChanged = true;
bool playSound = false;


int loop_num = 0;
int led_loop_END = LOOP_STATE1;
int audio_THRESHOLD = AUDIO_STATE1;
int i;


// Public function
void USR_Task_RunLoop(void) {
   
	// update the state of the state machine
    switch (currentState) {
    case State0:
        if (stateChanged) {
            // Initialize user LEDs
            BSP_LED_Init(LED_grn);
            BSP_LED_Off(LED_grn);
            // Initialize the red LED as well here 
            BSP_LED_Init(LED_red);
            BSP_LED_Off(LED_red);
    
            // Configure all Joy keys
            BSP_JOY_Init(JOY_MODE_GPIO);
            
            currentState = State1;
            led_loop_END = LOOP_STATE1;
            audio_THRESHOLD = AUDIO_STATE1;
        }
        break;
        
    case State1: 
        if (BSP_JOY_GetState() == JOY_SEL) {
            currentState = State2;
            led_loop_END = LOOP_STATE2;
            audio_THRESHOLD = AUDIO_STATE2;
        }
        else if (BSP_JOY_GetState() == JOY_RIGHT) {
            currentState = State3;
            led_loop_END = LOOP_STATE3;
            audio_THRESHOLD = AUDIO_STATE3;
        }
        break;
        
    case State2: 
        if (BSP_JOY_GetState() == JOY_LEFT) {
            currentState = State1;
            led_loop_END = LOOP_STATE1;
            audio_THRESHOLD = AUDIO_STATE1;
        } 
        else if (BSP_JOY_GetState() == JOY_RIGHT) {
            currentState = State3;
            led_loop_END = LOOP_STATE3;
            audio_THRESHOLD = AUDIO_STATE3;
        }
        break;
        
    case State3:        
        if (BSP_JOY_GetState() == JOY_LEFT) {
            currentState = State1;
            led_loop_END = LOOP_STATE1;
            audio_THRESHOLD = AUDIO_STATE1;
        }  
        else if (BSP_JOY_GetState() == JOY_SEL) {
            currentState = State2;
            led_loop_END = LOOP_STATE2;
            audio_THRESHOLD = AUDIO_STATE2;
        }
        break; 
        
    default:
        while (1); 
    }
    
    // Update the state indicating LED, the green LED
    if (loop_num++ > led_loop_END) {
        loop_num = 0;
        BSP_LED_Toggle(LED_grn);
    }

    copy_from_rec_to_play();
    
    if (playSound) {
        // Play the data from Play buff
        play_sound();

        // Process the audio signal to find the max value and turn on the red LED as needed
        int audio_max = find_audio_max();
        operate_red_LED(audio_max);
        playSound = false;
   }
		/*
	if((DmaLeftRecHalfBuffCplt == 1) && (DmaRightRecHalfBuffCplt == 1))
    {
      //Store values on Play buff 
      for(i = 0; i < 1024; i++)
      {
        PlayBuff[2*i]     = SaturaLH((LeftRecBuff[i] >> 8), -32768, 32767);
        PlayBuff[(2*i)+1] = SaturaLH((RightRecBuff[i] >> 8), -32768, 32767);
      }
      if(PlaybackStarted == 0)
      {
        if(0 != audio_drv->Play(AUDIO_I2C_ADDRESS, (uint16_t *) &PlayBuff[0], 4096))
        {
          Error_Handler();
        }
        if(HAL_OK != HAL_I2S_Transmit_DMA(&haudio_i2s, (uint16_t *) &PlayBuff[0], 4096))
        {
          Error_Handler();
        }
        PlaybackStarted = 1;
      }
      DmaLeftRecHalfBuffCplt  = 0;
      DmaRightRecHalfBuffCplt = 0;
    }
    if((DmaLeftRecBuffCplt == 1) && (DmaRightRecBuffCplt == 1))
    {
     // Store values on Play buff
      for(i = 1024; i < 2048; i++)
      {
        PlayBuff[2*i]     = SaturaLH((LeftRecBuff[i] >> 8), -32768, 32767);
        PlayBuff[(2*i)+1] = SaturaLH((RightRecBuff[i] >> 8), -32768, 32767);
      }
      DmaLeftRecBuffCplt  = 0;
      DmaRightRecBuffCplt = 0;
    }
		*/
}
		
#if defined(STM32L476xx) 
void copy_from_rec_to_play(void) {
    // Process the sound from the microphone
    if(DmaRecHalfBuffCplt == 1) {
        /* Store values on Play buff */
        for(i = 0; i < 1024; i++) {
            PlayBuff[2*i]     = SaturaLH((RecBuff[i] >> 8), -32768, 32767);
            // Add code to copy the "right channel"
        }
        DmaRecHalfBuffCplt  = 0;
    }
    
    if(DmaRecBuffCplt == 1) {
        /* Store values on Play buff */
        for(i = 1024; i < 2048; i++) {
            PlayBuff[2*i]     = SaturaLH((RecBuff[i] >> 8), -32768, 32767);
            // Add code to copy the "right channel"
        }
        DmaRecBuffCplt  = 0;
        
        playSound = true;
    }
}    
#elif defined(STM32F412Zx) 
void copy_from_rec_to_play(void) {
    if((DmaLeftRecHalfBuffCplt == 1) && (DmaRightRecHalfBuffCplt == 1)) {
        /* Store values on Play buff */
        for(i = 0; i < 1024; i++) {
            PlayBuff[2*i]     = SaturaLH((LeftRecBuff[i] >> 8), -32768, 32767);
            // Add code to copy the "right channel"
					PlayBuff[(2*i)+1]      = SaturaLH((RightRecBuff[i] >> 8), -32768, 32767);

        }
        DmaLeftRecHalfBuffCplt  = 0;
        DmaRightRecHalfBuffCplt = 0;
    }
    
    if((DmaLeftRecBuffCplt == 1) && (DmaRightRecBuffCplt == 1)) {
        /* Store values on Play buff */
        for(i = 1024; i < 2048; i++) {
            PlayBuff[2*i]     = SaturaLH((LeftRecBuff[i] >> 8), -32768, 32767);
            // Add code to copy the "right channel"
						PlayBuff[(2*i)+1]     = SaturaLH((RightRecBuff[i] >> 8), -32768, 32767);
				}
        DmaLeftRecBuffCplt  = 0;
        DmaRightRecBuffCplt = 0;
        
        playSound = true;
    }
}             
#endif

int find_audio_max(void) {
    int max_value = 0;
		max_value = PlayBuff[0];
    // Add code to find the maximul absolute value of the left and right channels.
    for (i = 0; i < 4096; i++) {
				if(abs(PlayBuff[i]) > max_value){
					  // Add code here
				max_value = abs(PlayBuff[i]);
				}
    }
    return max_value;
}

void operate_red_LED(int max) {
    if (max > audio_THRESHOLD) {
        BSP_LED_On(LED_red);
    } else {
        BSP_LED_Off(LED_red);
    }
}
        
void play_sound(void) {
    if(PlaybackStarted == 0) {
        if(0 != audio_drv->Play(AUDIO_I2C_ADDRESS, (uint16_t *) &PlayBuff[0], 4096)) {
            Error_Handler();
        }
#if defined(STM32L476xx) 
        if(HAL_OK != HAL_SAI_Transmit_DMA(&SaiHandle, (uint8_t *) &PlayBuff[0], 4096)) {
#elif defined(STM32F412Zx) 
        if(HAL_OK != HAL_I2S_Transmit_DMA(&haudio_i2s, (uint16_t *) &PlayBuff[0], 4096)) {       
#endif
            Error_Handler();
        }
        PlaybackStarted = 1;
    }  
}
