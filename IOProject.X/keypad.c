#include "keypad.h"

/**
 * Initializes keypad matrix.
 */
void kp_init(){

    TRISBCLR   = ROW_BITS;    
    ANSELBCLR = ROW_BITS | COL_BITS;
    CNPUBSET = COL_BITS;
    
    //initialize state variables
    keyState    = 0;
    currCol     = 0;
    currRow     = 0;
}

/**
 * This switches output rows for scan.
 * @param ROW
 */
void setOutput(uint8_t ROW){
    PORTBSET = ROW_BITS;
    switch(ROW){
        case(3):   PORTBCLR   = ROW3MASK;break;
        case(2):   PORTBCLR   = ROW2MASK;break;
        case(1):   PORTBCLR   = ROW1MASK;break;
        case(0):   PORTBCLR   = ROW0MASK;break;
    }
}

/**
 * This method scans the input columns and returns
 * the character of the button.
 * @return 
 */
char kp_read(){
    char bar = 0;
    char str[100];
    for(currRow = 0; currRow < 4; currRow++){
        setOutput(currRow); //sets the row output to which one we're checking
        
        if(!COL0)currCol = 0;
        else if(!COL1)currCol = 1;
        else if(!COL2)currCol = 2;
        else if(!COL3)currCol = 3;
        else currCol = -1;
        if(currCol >= 0){
            if(keyState)return bar; //unique press
            bar = which_btn(currRow,currCol);
            keyState = 1;
            currRow = 0;
            currCol = 0;            
            
            return bar;   
        }
        timer_ms_delay(5); //effective debounce timing
    }

    keyState = 0;
    currRow = 0;
    currCol = 0;
    return bar;
}               

/**
 * This determines the character of the button pressed
 * from the row and column coordinates and returns that
 * char.
 * @param currRow
 * @param currCol
 * @return 
 */
char which_btn(uint8_t currRow, uint8_t currCol){

    switch(currCol){
        case(0):
            switch(currRow){
                case(0):return '1';
                case(1):return '4';
                case(2):return '7';
                case(3):return '*';
            }break;

        case(1):
            switch(currRow){
                case(0):return '2';
                case(1):return '5';
                case(2):return '8';
                case(3):return '0';
            }break;
        case(2):
            switch(currRow){
                case(0):return '3';
                case(1):return '6';
                case(2):return '9';
                case(3):return '#';
            }break;
        case(3):
            switch(currRow){
                case(0):return 'A';
                case(1):return 'B';
                case(2):return 'C';
                case(3):return 'D';
            }break;

        default: break;
    }
    return 0;
}