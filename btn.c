#include "stm32l053xx.h"
#include <stdint.h>
#include "btn.h"
#include <assert.h>
extern void init_gpio(void);

// Initializer:
void init_btn(uint32_t mask_for_btn, 
              volatile uint32_t *pin_ptr, 
              struct btn_struct *pb)  
{
    init_gpio();
    pb->state = UP;
    pb->mask_for_btn = mask_for_btn;
    pb->pin_ptr = pin_ptr;
 }

enum btn_level read_btn(struct btn_struct *pb) // Correct for ACTIVE-LOW.
 {
    if ((*(pb->pin_ptr) & pb->mask_for_btn) == 0) return BTN_ACTIVE;
    else return BTN_INACTIVE;
 }

enum btn_edge update_btn(struct btn_struct *pb)
{
	
  enum btn_level b = read_btn(pb);
	enum btn_edge e = INACTIVE; 
    switch(pb->state)
    {
    case (UP):    
        if (b == BTN_ACTIVE) { pb->state = MAYBE_PRESSED; e = INACTIVE;}
        else                 { pb->state = UP; e = INACTIVE;}
        break;
        case (MAYBE_PRESSED):
                if (b == BTN_ACTIVE){ pb->state = DOWN; e = ACTIVATING_EDGE;}
                else                { pb->state = UP; e = INACTIVE;}
        break;
        case (DOWN):
                if (b == BTN_ACTIVE) { pb->state = DOWN; e = ACTIVE;}
                else                 { pb->state = MAYBE_RELEASED; e = ACTIVE;}
        break;
        case (MAYBE_RELEASED):
                if (b == BTN_ACTIVE) { pb->state = DOWN; e = ACTIVE;}
                else                 { pb->state = UP; e = DEACTIVATING_EDGE;}
        break;
        default:  
             pb->state = UP; // 
			 e = INACTIVE;
             assert(0 && "Unhandled special enum constant!"); 
    }
	return e;
 }


