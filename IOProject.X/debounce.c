
#include "debounce.h"
#define CLK_SPEED       (40e6)
#define TIMER_PRESCALER (8)
#define COUNT2MS        (CLK_SPEED/(1000*TIMER_PRESCALER)) //should be 5000

void debounce_init(){
    T1CON = 0x8030;
    TMR1 = 0;
}