#include "optical_encoder.h"

/**
 * Initializes the optical encoder
 */
void op_init(){
    TRISB |= ENCBITS;
    ANSELBCLR |= ENCBITS;
}

/**
 * Tracks the optical encoder turning levels to decode whether it's turning 
 * clockwise or counterclockwise
 */
void op_read(){
    if (A == 0 && B == 1){
        while (!(A == 0 && B == 0) && !(A == 1 && B == 1)){}
        while (!(A == 1 && B == 0) && !(A == 1 && B == 1)){}
        if (A == 1 && B == 0) uart_write_string("+\r\n");
    } else if (A == 1 && B == 0){
        while (!(A == 0 && B == 0) && !(A == 1 && B == 1)){}
        while (!(A == 0 && B == 1) && !(A == 1 && B == 1)){}
        if (A == 0 && B == 1) uart_write_string("-\r\n");
    }
}