/* 
 * File:   CRI.h
 * Author: mwauras
 *
 * Created on September 27, 2018, 3:22 PM
 */

#ifndef CRI_H
#define	CRI_H

#define VERSION ("1.1.001")
#define HIDDENEMOJI ("( 0 _ 0 )\r\n(-_-)\r\n=(\r\n")

#ifdef	__cplusplus
extern "C" {
#endif
#include <stdio.h>
#include <string.h>
#include "../Interrupt.X/timer_ms.h"
#include "../UART.X/uart.h"

    void getTest(char * str);
    void analogInputTest(char test);
    void encTest();
    void matrixTest();
    void printCommandList(); 
    

#ifdef	__cplusplus
}
#endif

#endif	/* CRI_H */

