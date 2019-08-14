/* 
 * File:   debounce.h
 * Author: mcfarlmt
 *
 * Created on October 3, 2018, 11:43 AM
 */

#ifndef DEBOUNCE_H
#define	DEBOUNCE_H

#ifdef	__cplusplus
extern "C" {
#endif


#include<plib.h>
#include <p32xxxx.h>
#include "../Interrupt.X/timer_ms.h"
    void debounce_init();
    
#ifdef	__cplusplus
}
#endif

#endif	/* DEBOUNCE_H */

