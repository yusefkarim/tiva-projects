#include <stdint.h>
#include "tm4c123gh6pm.h"
#include "Nokia5110.h"
#include "SysTick.h"
#include "PLL.h"
#include "Switches.h"

//----------------------------Global variables---------------------------//
//When a button is pressed, this is set to 1, moves from startup screen
unsigned char GameStart = 0;

//----------------------------Interrupt Handlers---------------------------//
void SysTick_Handler(void);
void PortE_Handler(void);

void PortF_Init(void);

//-----------------------------Main Program--------------------------------//
int main(void)
{
    PLL_Init();                     //80 Mhz Clock
    Nokia5110_Init();				//initialize Nokia5110 LCD
    Switches_Init();
    PortF_Init();

    //Clock is set to 80 MHz, each SysTick takes 1/80MHz = 12.5 ns
    //Divide: 80MHz/30Hz = 2666667 = value we need to pass to reload register
    SysTick_Init(16000000);	        //initialize SysTick for 30 Hz interrupts

    //Clear junk from previous instance
    Nokia5110_Clear();

    //Output game start screen to Nokia5110 LCD
    Nokia5110_SetCursor(2, 0);
    Nokia5110_OutString("Storm The");
    Nokia5110_SetCursor(3, 1);
    Nokia5110_OutString("Castle!");
    Nokia5110_SetCursor(2, 3);
    Nokia5110_OutString("Press any");
    Nokia5110_SetCursor(3, 4);
    Nokia5110_OutString("button");
    Nokia5110_SetCursor(0, 0);

    while(1)
    {

    }
}


void SysTick_Handler(void)
{
    if(GameStart)
    {
        //Start game, dur
    }
}

void PortE_Handler(void)
{
    if((WalkButton || BlockButton || AttackButton) && (GameStart == 0))
    {
        Nokia5110_Clear();  //Clear start screen
        GameStart = 1;      //Let interrupt know the game has started
    }

    //Reads interrupt status, if interrupt detected does something
    if(WalkButton)
    {
        WalkButtonClear;    //Acknowledges and clears respective interrupt flag
        GPIO_PORTF_DATA_R ^= 0x04;
    }
    else if(BlockButton)
    {
        BlockButtonClear;
        GPIO_PORTF_DATA_R ^= 0x02;
    }
    else if(AttackButton)
    {
        AttackButtonClear;
        GPIO_PORTF_DATA_R ^= 0x08;
    }
}

//Setup port F
//------------PortF_Init------------//
void PortF_Init(void)
{
    volatile unsigned long delay;
    SYSCTL_RCGC2_R |= 0x00000020;   //F clock
    delay = SYSCTL_RCGC2_R;         //delay
    GPIO_PORTF_LOCK_R = 0x4C4F434B; //Unlock Port F
    GPIO_PORTF_CR_R |= 0x1F;        //Allow changes to PF4-0
    GPIO_PORTF_AMSEL_R &= ~0x1F;    //Disable analog functions
    GPIO_PORTF_PCTL_R &= ~0x1F;     //GPIO clear bit PCTL
    GPIO_PORTF_DIR_R |= 0x1F;       //PF4-0 output
    GPIO_PORTF_AFSEL_R &= ~0x1F;    //Clear alt functions
    GPIO_PORTF_DEN_R |= 0x1F;       //Enable digital pin PF4, PF0 and PF2-1
}

