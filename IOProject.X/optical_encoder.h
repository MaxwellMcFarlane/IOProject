/* 
 * File:   uart.h
 * Author: mcfarlmt
 *
 */

#ifndef OPTICAL_ENCODER_H
#define	OPTICAL_ENCODER_H

#ifdef	__cplusplus
extern "C" {
#endif
#include <p32xxxx.h>
#include "../UART.X/uart.h"
#include <string.h>
#include <stdio.h>
#include <plib.h>
    
#define A   (PORTBbits.RB4) //pin11
#define B   (PORTBbits.RB5) //pin14
#define ENCBITS 0x000C    
    
/*  
This module is created for the pic32. This allows for the pic32 to
read direction values from an optical encoder.
*/
    
void op_init();
void op_read(); //returns the direction of the optical encoder

#ifdef	__cplusplus
}
#endif

#endif	/* OPTICAL_ENCODER_H */