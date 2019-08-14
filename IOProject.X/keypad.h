/* 
 * File:   keypad.h
 * Author: mcfarlmt
 *
 * Created on September 20, 2018, 1:37 PM
 */

#ifndef KEYPAD_H
#define	KEYPAD_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#define COL0    (PORTBbits.RB15)    //pin26
#define COL1    (PORTBbits.RB14)    //pin25
#define COL2    (PORTBbits.RB13)    //pin24
#define COL3    (PORTBbits.RB11)    //pin22

#define COL0MASK  0x8000            //pin26
#define COL1MASK  0x4000            //pin25
#define COL2MASK  0x2000            //pin24
#define COL3MASK  0x0800            //pin22
    
#define ROW0    (PORTBbits.RB10)    //pin21
#define ROW1    (PORTBbits.RB9)     //pin18
#define ROW2    (PORTBbits.RB8)     //pin17
#define ROW3    (PORTBbits.RB7)     //pin16

#define ROW0MASK   0x0400         //pin21
#define ROW1MASK   0x0200         //pin18
#define ROW2MASK   0x0100         //pin17
#define ROW3MASK   0x0080         //pin16
        
#define ROW_BITS    (ROW0MASK | ROW1MASK | ROW2MASK | ROW3MASK)
#define COL_BITS    (COL0MASK | COL1MASK | COL2MASK | COL3MASK)

#include <p32xxxx.h>
#include <string.h>
#include <stdio.h>
#include <plib.h>
#include "../UART.X/uart.h"
#include <inttypes.h>
#include "../Interrupt.X/timer_ms.h"
/*  
This module is created for the pic32. This allows for the pic32 to
read input values from a 4x4 keypad matrix.
*/

void kp_init();
char kp_read();
void setOutput(uint8_t ROW);                        //sets the output pins while reading
char which_btn(uint8_t currRow, uint8_t currCol);   //checks/returns which btn is pressed (only called when a btn is pressed)
void kp_param();                                    //test: ouTput of key to console, debounce, unique press.
void kp_test();

//global variables

uint8_t keyState;
int8_t currCol;
int8_t currRow;

#ifdef	__cplusplus
}
#endif

#endif	/* KEYPAD_H */