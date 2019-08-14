/* 
 * File:   pots.h
 * Author: mcfarlmt
 *
 * Created on September 20, 2018, 1:37 PM
 */

#ifndef POTS_H
#define	POTS_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#define POT1 (4) //PIN6
#define POT2 (5) //PIN7
#define POT_PINS (0x0030)
#define CONVERT2VOLT (0.00488758553)

#include <plib.h>
#include <p32xxxx.h>
#include <string.h>
#include <stdio.h>
#include "analog_in.h"



/*  
This module is created for the pic32. This allows for the pic32 to
read analog values from input pins.
*/

void pots_init();
float pot0_read();
float pot1_read();

#ifdef	__cplusplus
}
#endif

#endif	/* POTS_H */