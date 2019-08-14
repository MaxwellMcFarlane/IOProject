#include "CRI.h"

/**
 * This method is used to interface the the user with the program tests. 
 * The user may type right a character to specify a test to run.
 * @param str
 */
void getTest(char * str){
    
    char ver[100];
    
    switch(str[0]){
        case 'a':analogInputTest(str[1]);break;
        case 'e':encTest();break;
        case 'i':
            sprintf(ver, "\n\rRUNNING VERSION: %s\n\r",VERSION);
            uart_write_string(ver);
            uart_write_string("\r\n");
            break;
        case 'm':matrixTest();break;
        case '?':printCommandList();break;
        case 'q':uart_write_string("\n\rExiting\r\n");uart_write_string(HIDDENEMOJI);break;
        default: uart_write_string("\n\rCommand not identified. Exiting...\r\n");break; 
    }
            
}

/**
 * This test runs reads the analog voltage from the potentiometers.
 * You can specify which one using a single character n (a{n}). If
 * n is greater than 1 then the program prints out all analog voltages.
 * @param test
 */
void analogInputTest(char test){
    uart_write_string("\n\rAN_INPUT_TEST\n\r");
    char str[100];
    
    switch(test){
        case('0'):
            while(uart_read_nb() != 'q'){
                sprintf(str, "POT0: %f",pot0_read());
                uart_write_string(str);
                uart_write_string("\r\n");
                }break;
        case('1'):
            while(uart_read_nb() != 'q'){
                sprintf(str, "POT1: %f",pot1_read());
                uart_write_string(str);
                uart_write_string("\r\n");
                }break;
        default:
            while(uart_read_nb() != 'q'){
                sprintf(str, "POT(0,1): %f | %f",pot0_read(),pot1_read());
                uart_write_string(str);
                uart_write_string("\r\n");
                }break;
    }
}

/**
 * This test indicates whether the optical encoder
 * is moving counter clockwise or clockwise.
 */
void encTest(){
    uart_write_string("\n\rENCODER_TEST\n\r");
    while (uart_read_nb() != 'q'){
        op_read();
    }
}

/**
 * This test prints the user input from the keypad matrix. 
 */
void matrixTest(){
    uart_write_string("\n\rKEYPAD_MATRIX_TEST\n\r");
    char str[100];
    
    while(uart_read_nb() != 'q'){
        char c = kp_read();
        if(c != 0){
            sprintf(str, "%c",c);
            uart_write_string(str);
            uart_write_string("\r\n");
        }
    }
    uart_write_string("\r\n");
}

/**
 * This command prints the list of test commands.
 */
void printCommandList(){
    uart_write_string("\n\rList of Commands: \r\n");
    uart_write_string("a{N}: Performs Analog Test on device N\r\n");
    uart_write_string("e: Performs encoder test\r\n");
    uart_write_string("i: Identifies the code that's running\r\n");
    uart_write_string("m: Performs the keypad matrix test \r\n");
}