//This code contains parts from our knob lab given to us by Dr.Carrol.
//This code in conjunction with the btn.c and btn.h files manages updating the states of the two knobs used to control the game board movements.
//The Knobs based on Direcciton they are turning send unique numbers to the ButtonQueue that will communicate with the Tile Array file to command movement.
//The UpdateKnobs() function is the task that is run in main to update the knobs 
#include "stm32l053xx.h"
#include "stdint.h"
#include "btn.h"

void init_knobs(void);
void UpdateKnobs(void);
extern void enqueue(struct Queue*, int);


		struct Queue {
    			int front, rear, size;
    			unsigned capacity;
    			int* array;
			};
				extern struct Queue* ButtonQueue;



				static struct btn_struct btn_a = {.mask_for_btn= 0<<8, 
                                      .pin_ptr = &(GPIOA->IDR),
                                      .state = UP};  
				
		    		static struct btn_struct btn_b = {.mask_for_btn= 0<<9, 
                                      .pin_ptr = &(GPIOA->IDR),
                                      .state = UP};  
				
				static struct btn_struct btn_c = {.mask_for_btn= 0<<4, 
                                      .pin_ptr = &(GPIOA->IDR),
                                      .state = UP};  	
				
				static struct btn_struct btn_d = {.mask_for_btn= 0<<5, 
                                      .pin_ptr = &(GPIOA->IDR),
                                      .state = UP};  
																			
				static enum btn_edge ea;
				static enum btn_edge eb;
				static enum btn_edge ec;
				static enum btn_edge ed;
																			
																			
	void init_knobs()
		{
									  
    		init_btn(1 << 8, &(GPIOB->IDR), &btn_a); // Init state machine for PB8
		init_btn(1 << 9, &(GPIOB->IDR), &btn_b); // Init state machine for PB9
		init_btn(1 << 4, &(GPIOB->IDR), &btn_c); // Init state machine for PA2
		init_btn(1 << 5, &(GPIOB->IDR), &btn_d); // Init state machine for PA3			
		}

    
	void UpdateKnobs(){
    		ea = update_btn(&btn_a);
		eb = update_btn(&btn_b);
		ec = update_btn(&btn_c);
		ed = update_btn(&btn_d);
	
		//Send a 0 to the queue for down movement
		if (ea == ACTIVATING_EDGE && eb == INACTIVE){
			enqueue(ButtonQueue, 0);
		}

		//Send a 3 to the queue for up movement
		if (ea==ACTIVATING_EDGE && eb==ACTIVE){
			enqueue(ButtonQueue, 3);
		}
	    
	    	//Send a 1 to the queue for right movement
		if (ec==ACTIVATING_EDGE && ed==INACTIVE){
			enqueue(ButtonQueue, 2);
		}
		
	   	//Send a 2 to the queue for left movement
		if (ec==ACTIVATING_EDGE && ed==ACTIVE){
			enqueue(ButtonQueue, 1);
		}
}

