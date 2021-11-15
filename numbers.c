// Matthew Childs
#include "stm32l053xx.h"

void UpdateDisplay(void);
void setColumn(int);
void setPage(uint32_t);
void printnull(int,uint32_t);
void print2(int, uint32_t);
void print4(int, uint32_t);
void print8(int, uint32_t);
void print16(int, uint32_t);
void print32(int, uint32_t);
void print64(int, uint32_t);
void print128(int, uint32_t);
void print256(int, uint32_t);
void print512(int, uint32_t);
void print1024(int, uint32_t);
void printwin(void);
void printlose(void);


extern void dis_cmd_0(uint32_t com);
extern void dis_cmd_1(uint32_t com);
extern int isEmpty(struct Queue*);
extern int dequeue(struct Queue*);
extern int front(struct Queue*);\
extern void turn_off_all(void);

struct Queue {
    int front, rear, size;
    unsigned capacity;
    int* array;
};

extern struct Queue* ButtonQueue;
extern struct Queue* DisplayQueue;


void UpdateDisplay(){
	//printlose();
	volatile int slot;
	volatile int column;
	volatile uint32_t page;
	volatile int number;
	if(isEmpty(DisplayQueue)){}        // ends the fuction if there are no values to display
	else{
		//print1024(75,0);
		for (slot=1; slot<=16; slot++){                  
			number = front(DisplayQueue);              // pulls value from queue and dequeues to next item in queue     
			dequeue(DisplayQueue); 
			switch(slot){                              // switch cases set column and page to correct bit on the display
				case 1 : 
					//print1024(75,4);
					column = 3;
					page = 0;
					break;
				case 2 : 
					column = 27;
					page = 0;
					break;
				case 3 : 
					column = 51;
					page = 0;
					break;
				case 4 : 
					column = 75;
					page = 0;
					break;
				case 5 : 
					column = 3;
					page = 2;
					break;
				case 6 : 
					column = 27;
					page = 2;
					break;
				case 7 : 
					column = 51;
					page = 2;
					break;
				case 8 : 
					column = 75;
					page = 2;
					break;
				case 9 : 
					column = 3;
					page = 4;
					break;
				case 10 : 
					column = 27;
					page = 4;
					break;
				case 11 : 
					column = 51;
					page = 4;
					break;
				case 12 : 
					column = 75;
					page = 4;
					break;
				case 13 : 
					column = 3;
					page = 6;
					break;
				case 14 : 
					column = 27;
					page = 6;
					break;
				case 15 : 
					column = 51;
					page = 6;
					break;
				case 16 : 
					column = 75;
					page = 6;
					break;
				default :
					print512(75,2);					
					column =1;
					page =1;
					break;
			}	
		
			switch(number){                                            // Checks number from Queue and calls print to display based on number
				case 0 : printnull(column,page);
					break;
				case 2 : print2(column,page);
					break;
				case 4 : print4(column,page);
					break;
				case 8 : print8(column,page);
					break;
				case 16 : print16(column,page);
					break;
				case 32 : print32(column,page);
					break;
				case 64 : print64(column,page);
					break;
				case 128 : print128(column,page);
					break;
				case 256 : print256(column,page);
					break;
				case 512 : print512(column,page);
					break;
				case 1024 : print1024(column,page);
					break;
				case 2048 : printwin();
					break;
				case 99 : printlose();
					break;
				default: printnull(column,page);
					break;
			}
		}
	}
}

// Anchor Bits
// 3,0 27,0 51,0 75,0
// 3,2 27,2 51,2 75,2
// 3,4 27,4 51,4 75,4
// 3,6 27,6 51,6 75,6
	

void setColumn(int t){                                       //done 
	int x = 0;
	while (x != t) 
	{
		x++;
	}
			volatile uint32_t lsb = t & 0x0F;
			volatile uint32_t msb = ((t & 0xF0) >> 4) | 0x10;            //checks all the columns for the matching column we choose
	//finds the bits to be sent for msb and lsb
	

	
	
	dis_cmd_0(lsb);
	dis_cmd_0(msb);                                      //sets the column address based on msb and lsb
	
}


void setPage(uint32_t P){                                         //done
	volatile uint32_t pagecmd; 
	
	pagecmd = P | 0xB0;                                  //finds bits for page address
	
	dis_cmd_0(pagecmd);                                   //sets the page address
	
	
}


void printnull(int x, uint32_t y) // prints empty tile
{
	setPage(y);

	setColumn(x);
	dis_cmd_1(0xFF);
	setColumn(x+1);
	dis_cmd_1(0x01);
	setColumn(x+2);
	dis_cmd_1(0x01);
	setColumn(x+3);
	dis_cmd_1(0x01);
	setColumn(x+4);
	dis_cmd_1(0x01); 
	setColumn(x+5);
	dis_cmd_1(0x01);
	setColumn(x+6);
	dis_cmd_1(0x01);
	setColumn(x+7);
	dis_cmd_1(0x01);
	setColumn(x+8);
	dis_cmd_1(0x01);
	setColumn(x+9);
	dis_cmd_1(0x01);
	setColumn(x+10);               // print nothing
	dis_cmd_1(0x01);
	setColumn(x+11);
	dis_cmd_1(0x01);
	setColumn(x+12);  
	dis_cmd_1(0x01);
	setColumn(x+13);
	dis_cmd_1(0x01);
	setColumn(x+14); 
	dis_cmd_1(0x01); 
	setColumn(x+15);
	dis_cmd_1(0x01);
	setColumn(x+16);
	dis_cmd_1(0x01);
	setColumn(x+17);
	dis_cmd_1(0x01);
	setColumn(x+18);
	dis_cmd_1(0x01);
	setColumn(x+19);
	dis_cmd_1(0x01);
	setColumn(x+20);
	dis_cmd_1(0x01);
	setColumn(x+21);
	dis_cmd_1(0x01);
	setColumn(x+22);
	dis_cmd_1(0x01);
	setColumn(x+23);
	dis_cmd_1(0xFF);
	
	setPage(y+1);
	
	setColumn(x);
	dis_cmd_1(0xFF);
	setColumn(x+1);
	dis_cmd_1(0x80);
	setColumn(x+2);
	dis_cmd_1(0x80);
	setColumn(x+3);
	dis_cmd_1(0x80);
	setColumn(x+4);
	dis_cmd_1(0x80); 
	setColumn(x+5);
	dis_cmd_1(0x80);
	setColumn(x+6);
	dis_cmd_1(0x80);
	setColumn(x+7);
	dis_cmd_1(0x80);
	setColumn(x+8);
	dis_cmd_1(0x80);
	setColumn(x+9);
	dis_cmd_1(0x80); 
	setColumn(x+10);        //print nothing
	dis_cmd_1(0x80);
	setColumn(x+11);
	dis_cmd_1(0x80);
	setColumn(x+12);      
	dis_cmd_1(0x80);
	setColumn(x+13);
	dis_cmd_1(0x80);
	setColumn(x+14); 
	dis_cmd_1(0x80); 
	setColumn(x+15);
	dis_cmd_1(0x80);
	setColumn(x+16);
	dis_cmd_1(0x80);
	setColumn(x+17);
	dis_cmd_1(0x80);
	setColumn(x+18);
	dis_cmd_1(0x80);
	setColumn(x+19);
	dis_cmd_1(0x80);
	setColumn(x+20);
	dis_cmd_1(0x80);
	setColumn(x+21);
	dis_cmd_1(0x80);
	setColumn(x+22);
	dis_cmd_1(0x80);
	setColumn(x+23);
	dis_cmd_1(0xFF);
}

void print2(int x, uint32_t y)  //prints a 2 to the tile
{
	setPage(y);

	setColumn(x);
	dis_cmd_1(0xFF);
	setColumn(x+1);
	dis_cmd_1(0x01);
	setColumn(x+2);
	dis_cmd_1(0x01);
	setColumn(x+3);
	dis_cmd_1(0x01);
	setColumn(x+4);
	dis_cmd_1(0x01); 
	setColumn(x+5);
	dis_cmd_1(0x01);
	setColumn(x+6);
	dis_cmd_1(0x01);
	setColumn(x+7);
	dis_cmd_1(0x01);
	setColumn(x+8);
	dis_cmd_1(0x01);
	setColumn(x+9);
	dis_cmd_1(0x01); //
	setColumn(x+10);
	dis_cmd_1(0x21);
	setColumn(x+11);
	dis_cmd_1(0x11);
	setColumn(x+12);      // top 2 
	dis_cmd_1(0x11);
	setColumn(x+13);
	dis_cmd_1(0xE1);
	setColumn(x+14); //
	dis_cmd_1(0x01); 
	setColumn(x+15);
	dis_cmd_1(0x01);
	setColumn(x+16);
	dis_cmd_1(0x01);
	setColumn(x+17);
	dis_cmd_1(0x01);
	setColumn(x+18);
	dis_cmd_1(0x01);
	setColumn(x+19);
	dis_cmd_1(0x01);
	setColumn(x+20);
	dis_cmd_1(0x01);
	setColumn(x+21);
	dis_cmd_1(0x01);
	setColumn(x+22);
	dis_cmd_1(0x01);
	setColumn(x+23);
	dis_cmd_1(0xFF);
	
	setPage(y+1);
	
	setColumn(x);
	dis_cmd_1(0xFF);
	setColumn(x+1);
	dis_cmd_1(0x80);
	setColumn(x+2);
	dis_cmd_1(0x80);
	setColumn(x+3);
	dis_cmd_1(0x80);
	setColumn(x+4);
	dis_cmd_1(0x80); 
	setColumn(x+5);
	dis_cmd_1(0x80);
	setColumn(x+6);
	dis_cmd_1(0x80);
	setColumn(x+7);
	dis_cmd_1(0x80);
	setColumn(x+8);
	dis_cmd_1(0x80);
	setColumn(x+9);
	dis_cmd_1(0x80); //
	setColumn(x+10);
	dis_cmd_1(0x8C);
	setColumn(x+11);
	dis_cmd_1(0x8A);
	setColumn(x+12);       // bot 2
	dis_cmd_1(0x89);
	setColumn(x+13);
	dis_cmd_1(0x88);
	setColumn(x+14); //
	dis_cmd_1(0x80); 
	setColumn(x+15);
	dis_cmd_1(0x80);
	setColumn(x+16);
	dis_cmd_1(0x80);
	setColumn(x+17);
	dis_cmd_1(0x80);
	setColumn(x+18);
	dis_cmd_1(0x80);
	setColumn(x+19);
	dis_cmd_1(0x80);
	setColumn(x+20);
	dis_cmd_1(0x80);
	setColumn(x+21);
	dis_cmd_1(0x80);
	setColumn(x+22);
	dis_cmd_1(0x80);
	setColumn(x+23);
	dis_cmd_1(0xFF);
}	
	
void print4(int x, uint32_t y)
{
	setPage(y);

	setColumn(x);
	dis_cmd_1(0xFF);
	setColumn(x+1);
	dis_cmd_1(0x01);
	setColumn(x+2);
	dis_cmd_1(0x01);
	setColumn(x+3);
	dis_cmd_1(0x01);
	setColumn(x+4);
	dis_cmd_1(0x01); 
	setColumn(x+5);
	dis_cmd_1(0x01);
	setColumn(x+6);
	dis_cmd_1(0x01);
	setColumn(x+7);
	dis_cmd_1(0x01);
	setColumn(x+8);
	dis_cmd_1(0x01);
	setColumn(x+9);
	dis_cmd_1(0x01); //
	setColumn(x+10);
	dis_cmd_1(0xF1);
	setColumn(x+11);
	dis_cmd_1(0x81);        //top 4
	setColumn(x+12);
	dis_cmd_1(0x81);
	setColumn(x+13);
	dis_cmd_1(0xF1);
	setColumn(x+14); // 
	dis_cmd_1(0x01); 
	setColumn(x+15);
	dis_cmd_1(0x01);
	setColumn(x+16);
	dis_cmd_1(0x01);
	setColumn(x+17);
	dis_cmd_1(0x01);
	setColumn(x+18);
	dis_cmd_1(0x01);
	setColumn(x+19);
	dis_cmd_1(0x01);
	setColumn(x+20);
	dis_cmd_1(0x01);
	setColumn(x+21);
	dis_cmd_1(0x01);
	setColumn(x+22);
	dis_cmd_1(0x01);
	setColumn(x+23);
	dis_cmd_1(0xFF);
	
	setPage(y+1);
	
	setColumn(x);
	dis_cmd_1(0xFF);
	setColumn(x+1);
	dis_cmd_1(0x80);
	setColumn(x+2);
	dis_cmd_1(0x80);
	setColumn(x+3);
	dis_cmd_1(0x80);
	setColumn(x+4);
	dis_cmd_1(0x80); 
	setColumn(x+5);
	dis_cmd_1(0x80);
	setColumn(x+6);
	dis_cmd_1(0x80);
	setColumn(x+7);
	dis_cmd_1(0x80);
	setColumn(x+8);
	dis_cmd_1(0x80);
	setColumn(x+9);
	dis_cmd_1(0x80); //
	setColumn(x+10);
	dis_cmd_1(0x80);
	setColumn(x+11);
	dis_cmd_1(0x80);
	setColumn(x+12);      // bot 4
	dis_cmd_1(0x80);
	setColumn(x+13);
	dis_cmd_1(0x8f);
	setColumn(x+14); //
	dis_cmd_1(0x80); 
	setColumn(x+15);
	dis_cmd_1(0x80);
	setColumn(x+16);
	dis_cmd_1(0x80);
	setColumn(x+17);
	dis_cmd_1(0x80);
	setColumn(x+18);
	dis_cmd_1(0x80);
	setColumn(x+19);
	dis_cmd_1(0x80);
	setColumn(x+20);
	dis_cmd_1(0x80);
	setColumn(x+21);
	dis_cmd_1(0x80);
	setColumn(x+22);
	dis_cmd_1(0x80);
	setColumn(x+23);
	dis_cmd_1(0xFF);
}		
	
void print8(int x, uint32_t y)
{
	setPage(y);

	setColumn(x);
	dis_cmd_1(0xFF);
	setColumn(x+1);
	dis_cmd_1(0x01);
	setColumn(x+2);
	dis_cmd_1(0x01);
	setColumn(x+3);
	dis_cmd_1(0x01);
	setColumn(x+4);
	dis_cmd_1(0x01); 
	setColumn(x+5);
	dis_cmd_1(0x01);
	setColumn(x+6);
	dis_cmd_1(0x01);
	setColumn(x+7);
	dis_cmd_1(0x01);
	setColumn(x+8);
	dis_cmd_1(0x01);
	setColumn(x+9);
	dis_cmd_1(0x01); //
	setColumn(x+10);
	dis_cmd_1(0x61);
	setColumn(x+11);
	dis_cmd_1(0x91);        //top 8
	setColumn(x+12);
	dis_cmd_1(0x91);
	setColumn(x+13);
	dis_cmd_1(0x61);
	setColumn(x+14); // 
	dis_cmd_1(0x01); 
	setColumn(x+15);
	dis_cmd_1(0x01);
	setColumn(x+16);
	dis_cmd_1(0x01);
	setColumn(x+17);
	dis_cmd_1(0x01);
	setColumn(x+18);
	dis_cmd_1(0x01);
	setColumn(x+19);
	dis_cmd_1(0x01);
	setColumn(x+20);
	dis_cmd_1(0x01);
	setColumn(x+21);
	dis_cmd_1(0x01);
	setColumn(x+22);
	dis_cmd_1(0x01);
	setColumn(x+23);
	dis_cmd_1(0xFF);
	
	setPage(y+1);
	
	setColumn(x);
	dis_cmd_1(0xFF);
	setColumn(x+1);
	dis_cmd_1(0x80);
	setColumn(x+2);
	dis_cmd_1(0x80);
	setColumn(x+3);
	dis_cmd_1(0x80);
	setColumn(x+4);
	dis_cmd_1(0x80); 
	setColumn(x+5);
	dis_cmd_1(0x80);
	setColumn(x+6);
	dis_cmd_1(0x80);
	setColumn(x+7);
	dis_cmd_1(0x80);
	setColumn(x+8);
	dis_cmd_1(0x80);
	setColumn(x+9);
	dis_cmd_1(0x80); //
	setColumn(x+10);
	dis_cmd_1(0x87);
	setColumn(x+11);
	dis_cmd_1(0x88);
	setColumn(x+12);            //bot 8
	dis_cmd_1(0x88);
	setColumn(x+13);
	dis_cmd_1(0x87);
	setColumn(x+14); //
	dis_cmd_1(0x80); 
	setColumn(x+15);
	dis_cmd_1(0x80);
	setColumn(x+16);
	dis_cmd_1(0x80);
	setColumn(x+17);
	dis_cmd_1(0x80);
	setColumn(x+18);
	dis_cmd_1(0x80);
	setColumn(x+19);
	dis_cmd_1(0x80);
	setColumn(x+20);
	dis_cmd_1(0x80);
	setColumn(x+21);
	dis_cmd_1(0x80);
	setColumn(x+22);
	dis_cmd_1(0x80);
	setColumn(x+23);
	dis_cmd_1(0xFF);
}		

void print16(int x, uint32_t y)
{
	setPage(y);

	setColumn(x);
	dis_cmd_1(0xFF);
	setColumn(x+1);
	dis_cmd_1(0x01);
	setColumn(x+2);
	dis_cmd_1(0x01);
	setColumn(x+3);
	dis_cmd_1(0x01);
	setColumn(x+4);
	dis_cmd_1(0x01); 
	setColumn(x+5);
	dis_cmd_1(0x01);
	setColumn(x+6);
	dis_cmd_1(0x01); //
	setColumn(x+7);
	dis_cmd_1(0x01);
	setColumn(x+8);
	dis_cmd_1(0x01);     // Top 1
	setColumn(x+9);
	dis_cmd_1(0xF1); 
	setColumn(x+10);
	dis_cmd_1(0x01); //
	setColumn(x+11);
	dis_cmd_1(0x01);        
	setColumn(x+12);
	dis_cmd_1(0x01);//
	setColumn(x+13);
	dis_cmd_1(0xC1);
	setColumn(x+14);
	dis_cmd_1(0x21);      // Top 6
	setColumn(x+15);
	dis_cmd_1(0x11);
	setColumn(x+16);
	dis_cmd_1(0x01);//
	setColumn(x+17);
	dis_cmd_1(0x01);
	setColumn(x+18);
	dis_cmd_1(0x01);
	setColumn(x+19);
	dis_cmd_1(0x01);
	setColumn(x+20);
	dis_cmd_1(0x01);
	setColumn(x+21);
	dis_cmd_1(0x01);
	setColumn(x+22);
	dis_cmd_1(0x01);
	setColumn(x+23);
	dis_cmd_1(0xFF);
	
	setPage(y+1);
	
	setColumn(x);
	dis_cmd_1(0xFF);
	setColumn(x+1);
	dis_cmd_1(0x80);
	setColumn(x+2);
	dis_cmd_1(0x80);
	setColumn(x+3);
	dis_cmd_1(0x80);
	setColumn(x+4);
	dis_cmd_1(0x80); 
	setColumn(x+5);
	dis_cmd_1(0x80);
	setColumn(x+6);
	dis_cmd_1(0x80); //
	setColumn(x+7);
	dis_cmd_1(0x80);
	setColumn(x+8);
	dis_cmd_1(0x80);     // Bottom 1
	setColumn(x+9);
	dis_cmd_1(0x8F); 
	setColumn(x+10);
	dis_cmd_1(0x80); //
	setColumn(x+11);
	dis_cmd_1(0x80);
	setColumn(x+12);            
	dis_cmd_1(0x80); //
	setColumn(x+13);
	dis_cmd_1(0x87);
	setColumn(x+14); 
	dis_cmd_1(0x89);      // Bottom 6
	setColumn(x+15);
	dis_cmd_1(0x89);
	setColumn(x+16);
	dis_cmd_1(0x86); // 
	setColumn(x+17);
	dis_cmd_1(0x80);
	setColumn(x+18);
	dis_cmd_1(0x80);
	setColumn(x+19);
	dis_cmd_1(0x80);
	setColumn(x+20);
	dis_cmd_1(0x80);
	setColumn(x+21);
	dis_cmd_1(0x80);
	setColumn(x+22);
	dis_cmd_1(0x80);
	setColumn(x+23);
	dis_cmd_1(0xFF);
}	


void print32(int x, uint32_t y)
{
	setPage(y);

	setColumn(x);
	dis_cmd_1(0xFF);
	setColumn(x+1);
	dis_cmd_1(0x01);
	setColumn(x+2);
	dis_cmd_1(0x01);
	setColumn(x+3);
	dis_cmd_1(0x01);
	setColumn(x+4);
	dis_cmd_1(0x01); 
	setColumn(x+5);
	dis_cmd_1(0x01);
	setColumn(x+6);
	dis_cmd_1(0x01); //
	setColumn(x+7);
	dis_cmd_1(0x11);
	setColumn(x+8);
	dis_cmd_1(0x91);     // Top 3
	setColumn(x+9);
	dis_cmd_1(0x91); 
	setColumn(x+10);
	dis_cmd_1(0x61); //
	setColumn(x+11);
	dis_cmd_1(0x01);        
	setColumn(x+12);
	dis_cmd_1(0x01);//
	setColumn(x+13);
	dis_cmd_1(0x21);
	setColumn(x+14);
	dis_cmd_1(0x11);      // Top 2
	setColumn(x+15);
	dis_cmd_1(0x11);
	setColumn(x+16);
	dis_cmd_1(0xE1);//
	setColumn(x+17);
	dis_cmd_1(0x01);
	setColumn(x+18);
	dis_cmd_1(0x01);
	setColumn(x+19);
	dis_cmd_1(0x01);
	setColumn(x+20);
	dis_cmd_1(0x01);
	setColumn(x+21);
	dis_cmd_1(0x01);
	setColumn(x+22);
	dis_cmd_1(0x01);
	setColumn(x+23);
	dis_cmd_1(0xFF);
	
	setPage(y+1);
	
	setColumn(x);
	dis_cmd_1(0xFF);
	setColumn(x+1);
	dis_cmd_1(0x80);
	setColumn(x+2);
	dis_cmd_1(0x80);
	setColumn(x+3);
	dis_cmd_1(0x80);
	setColumn(x+4);
	dis_cmd_1(0x80); 
	setColumn(x+5);
	dis_cmd_1(0x80);
	setColumn(x+6);
	dis_cmd_1(0x80); //
	setColumn(x+7);
	dis_cmd_1(0x88);
	setColumn(x+8);
	dis_cmd_1(0x88);     // Bottom 3
	setColumn(x+9);
	dis_cmd_1(0x88); 
	setColumn(x+10);
	dis_cmd_1(0x87); //
	setColumn(x+11);
	dis_cmd_1(0x80);
	setColumn(x+12);            
	dis_cmd_1(0x80); //
	setColumn(x+13);
	dis_cmd_1(0x6C);
	setColumn(x+14); 
	dis_cmd_1(0x8A);      // Bottom 2
	setColumn(x+15);
	dis_cmd_1(0x89);
	setColumn(x+16);
	dis_cmd_1(0x88); // 
	setColumn(x+17);
	dis_cmd_1(0x80);
	setColumn(x+18);
	dis_cmd_1(0x80);
	setColumn(x+19);
	dis_cmd_1(0x80);
	setColumn(x+20);
	dis_cmd_1(0x80);
	setColumn(x+21);
	dis_cmd_1(0x80);
	setColumn(x+22);
	dis_cmd_1(0x80);
	setColumn(x+23);
	dis_cmd_1(0xFF);
}	

void print64(int x, uint32_t y)
{
	setPage(y);

	setColumn(x);
	dis_cmd_1(0xFF);
	setColumn(x+1);
	dis_cmd_1(0x01);
	setColumn(x+2);
	dis_cmd_1(0x01);
	setColumn(x+3);
	dis_cmd_1(0x01);
	setColumn(x+4);
	dis_cmd_1(0x01); 
	setColumn(x+5);
	dis_cmd_1(0x01);
	setColumn(x+6);
	dis_cmd_1(0x01); //
	setColumn(x+7);
	dis_cmd_1(0xC1);
	setColumn(x+8);
	dis_cmd_1(0x21);     // Top 6
	setColumn(x+9);
	dis_cmd_1(0x11); 
	setColumn(x+10);
	dis_cmd_1(0x01); //
	setColumn(x+11);
	dis_cmd_1(0x01);        
	setColumn(x+12);
	dis_cmd_1(0x01);//
	setColumn(x+13);
	dis_cmd_1(0xF1);
	setColumn(x+14);
	dis_cmd_1(0x81);      // Top 4
	setColumn(x+15);
	dis_cmd_1(0x81);
	setColumn(x+16);
	dis_cmd_1(0xF1);//
	setColumn(x+17);
	dis_cmd_1(0x01);
	setColumn(x+18);
	dis_cmd_1(0x01);
	setColumn(x+19);
	dis_cmd_1(0x01);
	setColumn(x+20);
	dis_cmd_1(0x01);
	setColumn(x+21);
	dis_cmd_1(0x01);
	setColumn(x+22);
	dis_cmd_1(0x01);
	setColumn(x+23);
	dis_cmd_1(0xFF);
	
	setPage(y+1);
	
	setColumn(x);
	dis_cmd_1(0xFF);
	setColumn(x+1);
	dis_cmd_1(0x80);
	setColumn(x+2);
	dis_cmd_1(0x80);
	setColumn(x+3);
	dis_cmd_1(0x80);
	setColumn(x+4);
	dis_cmd_1(0x80); 
	setColumn(x+5);
	dis_cmd_1(0x80);
	setColumn(x+6);
	dis_cmd_1(0x80); //
	setColumn(x+7);
	dis_cmd_1(0x87);
	setColumn(x+8);
	dis_cmd_1(0x89);     // Bottom 6
	setColumn(x+9);
	dis_cmd_1(0x89); 
	setColumn(x+10);
	dis_cmd_1(0x86); //
	setColumn(x+11);
	dis_cmd_1(0x80);
	setColumn(x+12);            
	dis_cmd_1(0x80); //
	setColumn(x+13);
	dis_cmd_1(0x80);
	setColumn(x+14); 
	dis_cmd_1(0x80);      // Bottom 4
	setColumn(x+15);
	dis_cmd_1(0x80);
	setColumn(x+16);
	dis_cmd_1(0x8F); // 
	setColumn(x+17);
	dis_cmd_1(0x80);
	setColumn(x+18);
	dis_cmd_1(0x80);
	setColumn(x+19);
	dis_cmd_1(0x80);
	setColumn(x+20);
	dis_cmd_1(0x80);
	setColumn(x+21);
	dis_cmd_1(0x80);
	setColumn(x+22);
	dis_cmd_1(0x80);
	setColumn(x+23);
	dis_cmd_1(0xFF);
}		


void print128(int x, uint32_t y)
{
	setPage(y);

	setColumn(x);
	dis_cmd_1(0xFF);
	setColumn(x+1);
	dis_cmd_1(0x01);
	setColumn(x+2);
	dis_cmd_1(0x01);
	setColumn(x+3);
	dis_cmd_1(0x01);
	setColumn(x+4);
	dis_cmd_1(0x01); //
	setColumn(x+5);
	dis_cmd_1(0x01);  
	setColumn(x+6);
	dis_cmd_1(0x21);      // Top 1
	setColumn(x+7);
	dis_cmd_1(0xF1);
	setColumn(x+8);
	dis_cmd_1(0x01); //    
	setColumn(x+9);
	dis_cmd_1(0x01); //
	setColumn(x+10);
	dis_cmd_1(0x21); 
	setColumn(x+11);
	dis_cmd_1(0x11);        // Top 2
	setColumn(x+12);
	dis_cmd_1(0x11);
	setColumn(x+13);
	dis_cmd_1(0xE1); //
	setColumn(x+14);
	dis_cmd_1(0x01); //     
	setColumn(x+15);
	dis_cmd_1(0x61);
	setColumn(x+16);
	dis_cmd_1(0x91);         // Top 8
	setColumn(x+17);
	dis_cmd_1(0x91);
	setColumn(x+18);
	dis_cmd_1(0x61); //
	setColumn(x+19);
	dis_cmd_1(0x01);
	setColumn(x+20);
	dis_cmd_1(0x01);
	setColumn(x+21);
	dis_cmd_1(0x01);
	setColumn(x+22);
	dis_cmd_1(0x01);
	setColumn(x+23);
	dis_cmd_1(0xFF);
	
	setPage(y+1);
	
	setColumn(x);
	dis_cmd_1(0xFF);
	setColumn(x+1);
	dis_cmd_1(0x80);
	setColumn(x+2);
	dis_cmd_1(0x80);
	setColumn(x+3);
	dis_cmd_1(0x80);
	setColumn(x+4);
	dis_cmd_1(0x80); //
	setColumn(x+5);
	dis_cmd_1(0x80);
	setColumn(x+6);
	dis_cmd_1(0x80);       // Bot 1
	setColumn(x+7);
	dis_cmd_1(0x8F);
	setColumn(x+8);
	dis_cmd_1(0x80); //
	setColumn(x+9);
	dis_cmd_1(0x80); //
	setColumn(x+10);
	dis_cmd_1(0x8C); 
	setColumn(x+11); 
	dis_cmd_1(0x8A);         // Bot 2
	setColumn(x+12);            
	dis_cmd_1(0x89); 
	setColumn(x+13);
	dis_cmd_1(0x88); //
	setColumn(x+14); 
	dis_cmd_1(0x80); //
	setColumn(x+15);
	dis_cmd_1(0x87);
	setColumn(x+16);
	dis_cmd_1(0x88);          // Bot 8
	setColumn(x+17);
	dis_cmd_1(0x88);
	setColumn(x+18);
	dis_cmd_1(0x87); //
	setColumn(x+19);
	dis_cmd_1(0x80);
	setColumn(x+20);
	dis_cmd_1(0x80);
	setColumn(x+21);
	dis_cmd_1(0x80);
	setColumn(x+22);
	dis_cmd_1(0x80);
	setColumn(x+23);
	dis_cmd_1(0xFF);
}	

void print256(int x, uint32_t y)
{
	setPage(y);

	setColumn(x);
	dis_cmd_1(0xFF);
	setColumn(x+1);
	dis_cmd_1(0x01);
	setColumn(x+2);
	dis_cmd_1(0x01);
	setColumn(x+3);
	dis_cmd_1(0x01);
	setColumn(x+4);
	dis_cmd_1(0x01); //
	setColumn(x+5);
	dis_cmd_1(0x21);  
	setColumn(x+6);
	dis_cmd_1(0x11);      // Top 2
	setColumn(x+7);
	dis_cmd_1(0x11);
	setColumn(x+8);
	dis_cmd_1(0xE1); //    
	setColumn(x+9);
	dis_cmd_1(0x01); //
	setColumn(x+10);
	dis_cmd_1(0xF1); 
	setColumn(x+11);
	dis_cmd_1(0x91);        // Top 5
	setColumn(x+12);
	dis_cmd_1(0x91);
	setColumn(x+13);
	dis_cmd_1(0x11); //
	setColumn(x+14);
	dis_cmd_1(0x01); //     
	setColumn(x+15);
	dis_cmd_1(0xC1);
	setColumn(x+16);
	dis_cmd_1(0x21);         // Top 6
	setColumn(x+17);
	dis_cmd_1(0x11);
	setColumn(x+18);
	dis_cmd_1(0x01); //
	setColumn(x+19);
	dis_cmd_1(0x01);
	setColumn(x+20);
	dis_cmd_1(0x01);
	setColumn(x+21);
	dis_cmd_1(0x01);
	setColumn(x+22);
	dis_cmd_1(0x01);
	setColumn(x+23);
	dis_cmd_1(0xFF);
	
	setPage(y+1);
	
	setColumn(x);
	dis_cmd_1(0xFF);
	setColumn(x+1);
	dis_cmd_1(0x80);
	setColumn(x+2);
	dis_cmd_1(0x80);
	setColumn(x+3);
	dis_cmd_1(0x80);
	setColumn(x+4);
	dis_cmd_1(0x80); //
	setColumn(x+5);
	dis_cmd_1(0x8C);
	setColumn(x+6);
	dis_cmd_1(0x8A);       // Bot 2
	setColumn(x+7);
	dis_cmd_1(0x89);
	setColumn(x+8);
	dis_cmd_1(0x88); //
	setColumn(x+9);
	dis_cmd_1(0x80); //
	setColumn(x+10);
	dis_cmd_1(0x84); 
	setColumn(x+11); 
	dis_cmd_1(0x88);         // Bot 5
	setColumn(x+12);            
	dis_cmd_1(0x88); 
	setColumn(x+13);
	dis_cmd_1(0x87); //
	setColumn(x+14); 
	dis_cmd_1(0x80); //
	setColumn(x+15);
	dis_cmd_1(0x87);
	setColumn(x+16);
	dis_cmd_1(0x89);          // Bot 6
	setColumn(x+17);
	dis_cmd_1(0x89);
	setColumn(x+18);
	dis_cmd_1(0x86); //
	setColumn(x+19);
	dis_cmd_1(0x80);
	setColumn(x+20);
	dis_cmd_1(0x80);
	setColumn(x+21);
	dis_cmd_1(0x80);
	setColumn(x+22);
	dis_cmd_1(0x80);
	setColumn(x+23);
	dis_cmd_1(0xFF);
}	

void print512(int x, uint32_t y)
{
	setPage(y);

	setColumn(x);
	dis_cmd_1(0xFF);
	setColumn(x+1);
	dis_cmd_1(0x01);
	setColumn(x+2);
	dis_cmd_1(0x01);
	setColumn(x+3);
	dis_cmd_1(0x01);
	setColumn(x+4);
	dis_cmd_1(0x01); //
	setColumn(x+5);
	dis_cmd_1(0xF1);  
	setColumn(x+6);
	dis_cmd_1(0x91);      // Top 5
	setColumn(x+7);
	dis_cmd_1(0x91);
	setColumn(x+8);
	dis_cmd_1(0x11); //    
	setColumn(x+9);
	dis_cmd_1(0x01); //
	setColumn(x+10);
	dis_cmd_1(0x01); 
	setColumn(x+11);
	dis_cmd_1(0x21);        // Top 1
	setColumn(x+12);
	dis_cmd_1(0xF1);
	setColumn(x+13);
	dis_cmd_1(0x01); //
	setColumn(x+14);
	dis_cmd_1(0x01); //     
	setColumn(x+15);
	dis_cmd_1(0x21);
	setColumn(x+16);
	dis_cmd_1(0x11);         // Top 2
	setColumn(x+17);
	dis_cmd_1(0x11);
	setColumn(x+18);
	dis_cmd_1(0xE1); //
	setColumn(x+19);
	dis_cmd_1(0x01);
	setColumn(x+20);
	dis_cmd_1(0x01);
	setColumn(x+21);
	dis_cmd_1(0x01);
	setColumn(x+22);
	dis_cmd_1(0x01);
	setColumn(x+23);
	dis_cmd_1(0xFF);
	
	setPage(y+1);
	
	setColumn(x);
	dis_cmd_1(0xFF);
	setColumn(x+1);
	dis_cmd_1(0x80);
	setColumn(x+2);
	dis_cmd_1(0x80);
	setColumn(x+3);
	dis_cmd_1(0x80);
	setColumn(x+4);
	dis_cmd_1(0x80); //
	setColumn(x+5);
	dis_cmd_1(0x84);
	setColumn(x+6);
	dis_cmd_1(0x88);       // Bot 5
	setColumn(x+7);
	dis_cmd_1(0x88);
	setColumn(x+8);
	dis_cmd_1(0x87); //
	setColumn(x+9);
	dis_cmd_1(0x80); //
	setColumn(x+10);
	dis_cmd_1(0x80); 
	setColumn(x+11); 
	dis_cmd_1(0x80);         // Bot 1
	setColumn(x+12);            
	dis_cmd_1(0x8F); 
	setColumn(x+13);
	dis_cmd_1(0x80); //
	setColumn(x+14); 
	dis_cmd_1(0x80); //
	setColumn(x+15);
	dis_cmd_1(0x8C);
	setColumn(x+16);
	dis_cmd_1(0x8A);          // Bot 2
	setColumn(x+17);
	dis_cmd_1(0x89);
	setColumn(x+18);
	dis_cmd_1(0x88); //
	setColumn(x+19);
	dis_cmd_1(0x80);
	setColumn(x+20);
	dis_cmd_1(0x80);
	setColumn(x+21);
	dis_cmd_1(0x80);
	setColumn(x+22);
	dis_cmd_1(0x80);
	setColumn(x+23);
	dis_cmd_1(0xFF);
}	


void print1024(int x, uint32_t y)
{
	setPage(y);

	setColumn(x);
	dis_cmd_1(0xFF); 
	setColumn(x+1);
	dis_cmd_1(0x01); // 
	setColumn(x+2);
	dis_cmd_1(0x01);
	setColumn(x+3);
	dis_cmd_1(0x21);      //Top 1
	setColumn(x+4);
	dis_cmd_1(0xF1); 
	setColumn(x+5);
	dis_cmd_1(0x01); //
	setColumn(x+6);
	dis_cmd_1(0x01); //     
	setColumn(x+7);
	dis_cmd_1(0xE1);
	setColumn(x+8);
	dis_cmd_1(0x11);      //Top 0
	setColumn(x+9);
	dis_cmd_1(0x11); 
	setColumn(x+10);
	dis_cmd_1(0xE1); //
	setColumn(x+11);
	dis_cmd_1(0x01);        
	setColumn(x+12);
	dis_cmd_1(0x01); //
	setColumn(x+13);
	dis_cmd_1(0x21); 
	setColumn(x+14);
	dis_cmd_1(0x11);   // Top 2
	setColumn(x+15);
	dis_cmd_1(0x11);
	setColumn(x+16);
	dis_cmd_1(0xE1); //
	setColumn(x+17);
	dis_cmd_1(0x01); //
	setColumn(x+18);
	dis_cmd_1(0xF1); 
	setColumn(x+19);
	dis_cmd_1(0x81);     // Top 4
	setColumn(x+20);
	dis_cmd_1(0x81);
	setColumn(x+21);
	dis_cmd_1(0xF1); //
	setColumn(x+22);
	dis_cmd_1(0x01);
	setColumn(x+23);
	dis_cmd_1(0xFF);
	
	setPage(y+1);
	
	setColumn(x);
	dis_cmd_1(0xFF);
	setColumn(x+1);
	dis_cmd_1(0x80); //
	setColumn(x+2);
	dis_cmd_1(0x80);
	setColumn(x+3);
	dis_cmd_1(0x80);     // Bot 1
	setColumn(x+4);
	dis_cmd_1(0x8F); 
	setColumn(x+5);
	dis_cmd_1(0x80); //
	setColumn(x+6);
	dis_cmd_1(0x80); //
	setColumn(x+7);
	dis_cmd_1(0x87);
	setColumn(x+8);
	dis_cmd_1(0x88);      // Bot 0
	setColumn(x+9);
	dis_cmd_1(0x88); 
	setColumn(x+10);
	dis_cmd_1(0x87); //
	setColumn(x+11); 
	dis_cmd_1(0x80);         
	setColumn(x+12);            
	dis_cmd_1(0x80); //
	setColumn(x+13);
	dis_cmd_1(0x8C); 
	setColumn(x+14); 
	dis_cmd_1(0x8A);      // Bot 2
	setColumn(x+15);
	dis_cmd_1(0x89);
	setColumn(x+16);
	dis_cmd_1(0x88); //   
	setColumn(x+17);
	dis_cmd_1(0x80); //
	setColumn(x+18);
	dis_cmd_1(0x80); 
	setColumn(x+19);
	dis_cmd_1(0x80);       // Bot 4
	setColumn(x+20);
	dis_cmd_1(0x80);
	setColumn(x+21);
	dis_cmd_1(0x8F); //
	setColumn(x+22);
	dis_cmd_1(0x80);
	setColumn(x+23);
	dis_cmd_1(0xFF);
}

void printwin()
{
	turn_off_all();
	int x = 42;
	uint32_t y = 2;
	
	setPage(y); 

	setColumn(x);
	dis_cmd_1(0x00); //
	setColumn(x+1);
	dis_cmd_1(0x03); 
	setColumn(x+2);
	dis_cmd_1(0x04);
	setColumn(x+3);
	dis_cmd_1(0x78);      // Y
	setColumn(x+4);
	dis_cmd_1(0x04); 
	setColumn(x+5);
	dis_cmd_1(0x03); //
	setColumn(x+6);
	dis_cmd_1(0x00); //     
	setColumn(x+7);
	dis_cmd_1(0x7E);
	setColumn(x+8);
	dis_cmd_1(0x41);      // O
	setColumn(x+9);
	dis_cmd_1(0x41); 
	setColumn(x+10);
	dis_cmd_1(0x41); 
	setColumn(x+11);
	dis_cmd_1(0x7E); //       
	setColumn(x+12);
	dis_cmd_1(0x00); //
	setColumn(x+13);
	dis_cmd_1(0x7F); 
	setColumn(x+14);
	dis_cmd_1(0x40);   // Top U
	setColumn(x+15);
	dis_cmd_1(0x40);
	setColumn(x+16);
	dis_cmd_1(0x40); 
	setColumn(x+17);
	dis_cmd_1(0x7F); //
	setColumn(x+18);
	dis_cmd_1(0x00); 
	
	setPage(y+1); 

	setColumn(x);
	dis_cmd_1(0x00); //
	setColumn(x+1);
	dis_cmd_1(0x3F); 
	setColumn(x+2);
	dis_cmd_1(0x40);
	setColumn(x+3);
	dis_cmd_1(0x30);      // W
	setColumn(x+4);
	dis_cmd_1(0x40); 
	setColumn(x+5);
	dis_cmd_1(0x3F); //
	setColumn(x+6);
	dis_cmd_1(0x00); //     
	setColumn(x+7);
	dis_cmd_1(0x00);
	setColumn(x+8);
	dis_cmd_1(0x41);      // I
	setColumn(x+9);
	dis_cmd_1(0x7F); 
	setColumn(x+10);
	dis_cmd_1(0x41); 
	setColumn(x+11);
	dis_cmd_1(0x00); //       
	setColumn(x+12);
	dis_cmd_1(0x00); //
	setColumn(x+13);
	dis_cmd_1(0x7F); 
	setColumn(x+14);
	dis_cmd_1(0x04);   // N
	setColumn(x+15);
	dis_cmd_1(0x18);
	setColumn(x+16);
	dis_cmd_1(0x20); 
	setColumn(x+17);
	dis_cmd_1(0x7F); //
	setColumn(x+18);
	dis_cmd_1(0x00); 
	
	setPage(y+2); 

	setColumn(x);    //
	dis_cmd_1(0xC2); 
	setColumn(x+1);
	dis_cmd_1(0xA1); 
	setColumn(x+2);           // 2
	dis_cmd_1(0x91);
	setColumn(x+3);
	dis_cmd_1(0x8E); //     
	setColumn(x+4);
	dis_cmd_1(0x00); //
	setColumn(x+5);
	dis_cmd_1(0x7E);
	setColumn(x+6);
	dis_cmd_1(0x81);          // 0
	setColumn(x+7);
	dis_cmd_1(0x81);
	setColumn(x+8);
	dis_cmd_1(0x7E); //     
	setColumn(x+9);
	dis_cmd_1(0x00); //
	setColumn(x+10);
	dis_cmd_1(0x0F); 
	setColumn(x+11);
	dis_cmd_1(0x08);       // 4 
	setColumn(x+12);
	dis_cmd_1(0x08); 
	setColumn(x+13);
	dis_cmd_1(0xFF); //
	setColumn(x+14);
	dis_cmd_1(0x00); //
	setColumn(x+15);
	dis_cmd_1(0x76);
	setColumn(x+16);
	dis_cmd_1(0x89);        // 8
	setColumn(x+17);
	dis_cmd_1(0x89); 
	setColumn(x+18);
	dis_cmd_1(0x76); //
}
	
void printlose()
{
	turn_off_all();
	int x = 42;
	uint32_t y = 3;
	
	setPage(y); 

	setColumn(x);
	dis_cmd_1(0x00); //
	setColumn(x+1);
	dis_cmd_1(0x03); 
	setColumn(x+2);
	dis_cmd_1(0x04);
	setColumn(x+3);
	dis_cmd_1(0x78);      // Y
	setColumn(x+4);
	dis_cmd_1(0x04); 
	setColumn(x+5);
	dis_cmd_1(0x03); //
	setColumn(x+6);
	dis_cmd_1(0x00); //     
	setColumn(x+7);
	dis_cmd_1(0x7E);
	setColumn(x+8);
	dis_cmd_1(0x41);      // O
	setColumn(x+9);
	dis_cmd_1(0x41); 
	setColumn(x+10);
	dis_cmd_1(0x41); 
	setColumn(x+11);
	dis_cmd_1(0x7E); //       
	setColumn(x+12);
	dis_cmd_1(0x00); //
	setColumn(x+13);
	dis_cmd_1(0x7F); 
	setColumn(x+14);
	dis_cmd_1(0x40);   //  U
	setColumn(x+15);
	dis_cmd_1(0x40);
	setColumn(x+16);
	dis_cmd_1(0x40); 
	setColumn(x+17);
	dis_cmd_1(0x7F); //
	setColumn(x+18);
	dis_cmd_1(0x00);  
	
	setPage(y+1); 

	setColumn(x);    //
	dis_cmd_1(0xFE); 
	setColumn(x+1);
	dis_cmd_1(0x80); 
	setColumn(x+2);         // L
	dis_cmd_1(0x80);
	setColumn(x+3);
	dis_cmd_1(0x80); //     
	setColumn(x+4);
	dis_cmd_1(0x00); //
	setColumn(x+5);
	dis_cmd_1(0x7C); 
	setColumn(x+6);
	dis_cmd_1(0x82);     // O
	setColumn(x+7);
	dis_cmd_1(0x82);
	setColumn(x+8);
	dis_cmd_1(0x7C); //
	setColumn(x+9);
	dis_cmd_1(0x00); // 
	setColumn(x+10);
	dis_cmd_1(0x8C); 
	setColumn(x+11);
	dis_cmd_1(0x92);      // S
	setColumn(x+12);
	dis_cmd_1(0x92); 
	setColumn(x+13);
	dis_cmd_1(0x62); //
	setColumn(x+14);
	dis_cmd_1(0x00); //
	setColumn(x+15);
	dis_cmd_1(0xFE);
	setColumn(x+16);
	dis_cmd_1(0x92);      //E
	setColumn(x+17);
	dis_cmd_1(0x92); 
	setColumn(x+18);
	dis_cmd_1(0x82); //
	
}