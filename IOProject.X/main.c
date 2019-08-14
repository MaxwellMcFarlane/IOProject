#pragma config FNOSC = FRCPLL, POSCMOD = OFF
#pragma config FPLLIDIV = DIV_2, FPLLMUL = MUL_20
#pragma config FPBDIV = DIV_1, FPLLODIV = DIV_2
#pragma config FWDTEN = OFF, JTAGEN = OFF, FSOSCEN = OFF

#include <stdio.h>
#include <stdlib.h>
#include "../UART.X/uart.h"
#include "keypad.h"
#include "optical_encoder.h"
#include "pots.h"

/*
 * 
 */
void main() {
    uart_init();
    timer_ms_init();
    op_init();
    pots_init();
    kp_init();
    
    while(1){
        uart_write_string("Command>");
        getTest(uart_read_line());
    }
    return;
}