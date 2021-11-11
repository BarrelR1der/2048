#include "stm32l053xx.h"
#include "stdint.h"
#include "btn.h"

void init_knobs(void);
void UpdateKnobs(void);
void init_knobs()
{
				static struct btn_struct btn_a = {.mask_for_btn= 0<<8, 
                                      .pin_ptr = &(GPIOA->IDR),
                                      .state = UP};  
				
		    static struct btn_struct btn_b = {.mask_for_btn= 0<<9, 
                                      .pin_ptr = &(GPIOA->IDR),
                                      .state = UP};  
				
				static struct btn_struct btn_c = {.mask_for_btn= 0<<2, 
                                      .pin_ptr = &(GPIOA->IDR),
                                      .state = UP};  	
				
				static struct btn_struct btn_d = {.mask_for_btn= 0<<3, 
                                      .pin_ptr = &(GPIOA->IDR),
                                      .state = UP};  
																			
				enum btn_edge ea;
				enum btn_edge eb;
				enum btn_edge ec;
				enum btn_edge ed;
									  
    init_btn(1 << 8, &(GPIOB->IDR), &btn_a); // Init state machine for PB8
		init_btn(1 << 9, &(GPIOB->IDR), &btn_b); // Init state machine for PB9
		init_btn(1 << 2, &(GPIOA->IDR), &btn_c); // Init state machine for PA2
		init_btn(1 << 3, &(GPIOA->IDR), &btn_d); // Init state machine for PA3			
    
    void UpdateKnobs(){
        	ea = update_btn(&btn_a);
		eb = update_btn(&btn_b);
		ec = update_btn(&btn_c);
		ed = update_btn(&btn_d);
	    
		//Send a 1 to the queue for right movement
		if (ea == ACTIVATING_EDGE && eb == INACTIVE){
			enqueue(ButtonQueue, 1);
		}

		//Send a 3 to the queue for left movement
		if (ea==ACTIVATING_EDGE && eb==ACTIVE){
			enqueue(ButtonQueue, 3);
		}
	    
	    	//Send a 0 to the queue for up movement
		if (ec==ACTIVATING_EDGE && ed==INACTIVE){
			enqueue(ButtonQueue, 0);
		}
		
	   	//Send a 2 to the queue for down movement
		if (ec==ACTIVATING_EDGE && ed==ACTIVE){
			enqueue(ButtonQueue, 2);
		}
    }
	}