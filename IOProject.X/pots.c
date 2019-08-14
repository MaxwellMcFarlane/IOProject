#include "pots.h"


/**
 * Initializes potentiometers on pic32 device.
 */
void pots_init(){
    TRISB   |= POT_PINS;
    ANSELB  |= POT_PINS;
    analog_in_init();
}

/**
 * This code returns the analog voltage from potentiometer 1.
 * @return 
 */
float pot0_read(){
    float voltage0 = CONVERT2VOLT*analog_in_read(POT1);
    return voltage0;
}

/**
 * This code returns the analog voltage from potentiometer 2.
 * @return 
 */
float pot1_read(){
    float voltage1 = CONVERT2VOLT*analog_in_read(POT2);
    return voltage1;
}