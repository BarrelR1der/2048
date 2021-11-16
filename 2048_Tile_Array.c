// Cory Thatcher, Evan Dickerson, Matthew Childs
#include "stm32l053xx.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function List
int main(void);
void Moving(void);
void SpawnRandom(void);
void UpdateArray(void);
void CheckLose(void);
int static TA[16]= {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int static Count;


extern int isEmpty(struct Queue*);
extern int dequeue(struct Queue*);
extern int front(struct Queue*);
extern void enqueue(struct Queue*, int );

extern struct Queue* ButtonQueue;
extern struct Queue* DisplayQueue;



struct Queue {
    int front, rear, size;
    unsigned capacity;
    int* array;
};

void UpdateArray(void)// Update virtual TileArray 
{
	if (Count==0){
		Moving();
		SpawnRandom();
		CheckLose();
		for(int i=0; i<=16; i++){
			enqueue(DisplayQueue, TA[i]);
		}
	}
	Count++;
	if(isEmpty(ButtonQueue)){}       //if no input from knobs then skips the task
	else{
		Moving();
		SpawnRandom();
		CheckLose();
		for(int i=0; i<=16; i++){
			enqueue(DisplayQueue, TA[i]);
		}
	}
}


void SpawnRandom(void)
{
	int exit = 0;
	while(exit ==0){
		int RandomSlot = Count%16;
		if(TA[RandomSlot] == 0){
			TA[RandomSlot]=2;
			exit =1;
		}
		else{
			Count = Count + 3;
		}
	}
}


void CheckLose(void)// Checks the TileArray for possible lose scenarios 
{
	//Checks if combinations are available
	if ( TA[12]==TA[8] && TA[4]==TA[0]){}
	else if (TA[12]==TA[8]){}
	else if (TA[8]==TA[4]){}
	else if (TA[4]==TA[0]){}
	else if (TA[13]==TA[9] && TA[5]==TA[1]){}
	else if (TA[13]==TA[9]){}
	else if (TA[9]==TA[5]){}
	else if (TA[5]==TA[1]){}
	else if (TA[14]==TA[10] && TA[6]==TA[2]){}
	else if (TA[14]==TA[10]){}
	else if (TA[10]==TA[6]){}
	else if (TA[6]==TA[2]){}
	else if (TA[15]==TA[11] && TA[7]==TA[3]){}
	else if (TA[15]==TA[11]){}
	else if (TA[11]==TA[7]){}
	else if (TA[7]==TA[3]){}
	else if ( TA[3]==TA[2] && TA[1]==TA[0]){}
	else if (TA[3]==TA[2]){}
	else if (TA[2]==TA[1]){}
	else if (TA[1]==TA[0]){}
	else if (TA[7]==TA[6] && TA[5]==TA[4]){}
	else if (TA[7]==TA[6]){}
	else if (TA[6]==TA[5]){}
	else if (TA[5]==TA[4]){}
	else if (TA[11]==TA[10] && TA[9]==TA[8]){}
	else if (TA[11]==TA[10]){}
	else if (TA[10]==TA[9]){}
	else if (TA[9]==TA[8]){}
	else if (TA[15]==TA[14] && TA[13]==TA[12]){}
	else if (TA[15]==TA[14]){}
	else if (TA[14]==TA[13]){}
	else if (TA[13]==TA[12]){}
	else if ( TA[3]==TA[2] && TA[1]==TA[0]){}
	else if (TA[3]==TA[2]){}
	else if (TA[2]==TA[1]){}
	else if (TA[1]==TA[0]){}
	else if (TA[7]==TA[6] && TA[5]==TA[4]){}
	else if (TA[7]==TA[6]){}
	else if (TA[6]==TA[5]){}
	else if (TA[5]==TA[4]){}
	else if (TA[11]==TA[10] && TA[9]==TA[8]){}
	else if (TA[11]==TA[10]){}
	else if (TA[10]==TA[9]){}
	else if (TA[9]==TA[8]){}
	else if (TA[15]==TA[14] && TA[13]==TA[12]){}
	else if (TA[15]==TA[14]){}
	else if (TA[14]==TA[13]){}
	else if (TA[13]==TA[12]){}
	else if ( TA[12]==TA[8] && TA[4]==TA[0]){}
	else if (TA[12]==TA[8]){}
	else if (TA[8]==TA[4]){}
	else if (TA[4]==TA[0]){}
	else if (TA[13]==TA[9] && TA[5]==TA[1]){}
	else if (TA[13]==TA[9]){}
	else if (TA[9]==TA[5]){}
	else if (TA[5]==TA[1]){}
	else if (TA[14]==TA[10] && TA[6]==TA[2]){}
	else if (TA[14]==TA[10]){}
	else if (TA[10]==TA[6]){}
	else if (TA[6]==TA[2]){}
	else if (TA[15]==TA[11] && TA[7]==TA[3]){}
	else if (TA[15]==TA[11]){}
	else if (TA[11]==TA[7]){}
	else if (TA[7]==TA[3]){}
	//checks if shift are possible
	else if (TA[12] != 0 && TA[8] == 0 && TA[4] == 0 && TA[0] ==0){}
	else if (TA[12] != 0 && TA[8] == 0 && TA[4] == 0){}
	else if (TA[12] != 0 && TA[8] == 0){}
	else if (TA[13] != 0 && TA[9] == 0 && TA[5] == 0 && TA[1] ==0 ){}
	else if (TA[13] != 0 && TA[9] == 0 && TA[5] == 0 ){}
	else if (TA[13] != 0 && TA[9] == 0  ){}
	else if (TA[14] != 0 && TA[10] == 0 && TA[6] == 0 && TA[2] ==0 ){}
	else if (TA[14] != 0 && TA[10] == 0 && TA[6] == 0 ){}
	else if (TA[14] != 0 && TA[10] == 0  ){}
	else if (TA[15] != 0 && TA[11] == 0 && TA[7] == 0 && TA[3] ==0 ){}
	else if (TA[15] != 0 && TA[11] == 0 && TA[7] == 0 ){}
	else if (TA[15] != 0 && TA[11] == 0  ){}
	else if (TA[8] != 0 && TA[4] == 0 && TA[0] == 0){}
	else if (TA[8] != 0 && TA[4] == 0  ){}
	else if (TA[9] != 0 && TA[5] == 0 && TA[1] == 0){}
	else if (TA[9] != 0 && TA[5] == 0  ){}
	else if (TA[10] != 0 && TA[6] == 0 && TA[2] == 0){}
	else if (TA[10] != 0 && TA[6] == 0  ){}
	else if (TA[11] != 0 && TA[7] == 0 && TA[3] == 0){}
	else if (TA[11] != 0 && TA[7] == 0){}
	else if (TA[4] != 0 && TA[0] == 0){}
	else if (TA[5] != 0 && TA[1] == 0){}
	else if (TA[6] != 0 && TA[2] == 0){}
	else if (TA[7] != 0 && TA[3] == 0){}
	else if (TA[0] != 0 && TA[1] == 0 && TA[2] == 0 && TA[3] ==0 ){}
	else if (TA[0] != 0 && TA[1] == 0 && TA[2] == 0 ){}
	else if (TA[0] != 0 && TA[1] == 0  ){}
	else if (TA[4] != 0 && TA[5] == 0 && TA[6] == 0 && TA[7] ==0 ){}
	else if (TA[4] != 0 && TA[5] == 0 && TA[6] == 0 ){}
	else if (TA[4] != 0 && TA[5] == 0  ){}
	else if (TA[8] != 0 && TA[9] == 0 && TA[10] == 0 && TA[11] ==0 ){}
	else if (TA[8] != 0 && TA[9] == 0 && TA[10] == 0 ){}
	else if (TA[8] != 0 && TA[9] == 0  ){}
	else if (TA[12] != 0 && TA[13] == 0 && TA[14] == 0 && TA[15] ==0 ){}
	else if (TA[12] != 0 && TA[13] == 0 && TA[14] == 0 ){}
	else if (TA[12] != 0 && TA[13] == 0  ){}
	else if (TA[1] != 0 && TA[2] == 0 && TA[3] == 0 ){}
	else if (TA[1] != 0 && TA[2] == 0  ){}
	else if (TA[5] != 0 && TA[6] == 0 && TA[6] == 0 ){}
	else if (TA[5] != 0 && TA[6] == 0  ){}
	else if (TA[9] != 0 && TA[10] == 0 && TA[11] == 0 ){}
	else if (TA[9] != 0 && TA[10] == 0  ){}
	else if (TA[13] != 0 && TA[14] == 0 && TA[15] == 0 ){}
	else if (TA[13] != 0 && TA[14] == 0  ){}
	else if (TA[2] != 0 && TA[3] == 0  ){}
	else if (TA[6] != 0 && TA[7] == 0  ){}
	else if (TA[10] != 0 && TA[11] == 0  ){}	
	else if (TA[3] != 0 && TA[2] == 0 && TA[1] == 0 && TA[0] ==0 ){}
	else if (TA[3] != 0 && TA[2] == 0 && TA[1] == 0 ){}
	else if (TA[3] != 0 && TA[2] == 0  ){}
	else if (TA[7] != 0 && TA[5] == 0 && TA[6] == 0 && TA[4] ==0 ){}
	else if (TA[7] != 0 && TA[5] == 0 && TA[6] == 0 ){}
	else if (TA[7] != 0 && TA[6] == 0  ){}
	else if (TA[11] != 0 && TA[9] == 0 && TA[10] == 0 && TA[8] ==0 ){}
	else if (TA[11] != 0 && TA[9] == 0 && TA[10] == 0 ){}
	else if (TA[11] != 0 && TA[10] == 0  ){}
	else if (TA[15] != 0 && TA[13] == 0 && TA[14] == 0 && TA[12] ==0 ){}
	else if (TA[15] != 0 && TA[13] == 0 && TA[14] == 0 ){}
	else if (TA[15] != 0 && TA[14] == 0  ){}
	else if (TA[2] != 0 && TA[1] == 0 && TA[0] == 0 ){}
	else if (TA[2] != 0 && TA[1] == 0  ){}
	else if (TA[6] != 0 && TA[5] == 0 && TA[4] == 0 ){}
	else if (TA[6] != 0 && TA[5] == 0  ){}
	else if (TA[10] != 0 && TA[9] == 0 && TA[8] == 0 ){}
	else if (TA[10] != 0 && TA[9] == 0  ){}
	else if (TA[14] != 0 && TA[13] == 0 && TA[12] == 0 ){}
	else if (TA[14] != 0 && TA[13] == 0 ){}
	else if (TA[1] != 0 && TA[0] == 0  ){}
	else if (TA[5] != 0 && TA[4] == 0  ){}
	else if (TA[9] != 0 && TA[8] == 0  ){}
	else if (TA[13] != 0 && TA[12] == 0  ){}	
	else if (TA[0] != 0 && TA[4] == 0 && TA[8] == 0 && TA[12] ==0 ){}
	else if (TA[0] != 0 && TA[4] == 0 && TA[8] == 0 ){}
	else if (TA[0] != 0 && TA[4] == 0  ){}
	else if (TA[1] != 0 && TA[5] == 0 && TA[9] == 0 && TA[13] ==0 ){}
	else if (TA[1] != 0 && TA[5] == 0 && TA[9] == 0 ){}
	else if (TA[1] != 0 && TA[5] == 0  ){}
	else if (TA[2] != 0 && TA[6] == 0 && TA[10] == 0 && TA[14] ==0 ){}
	else if (TA[2] != 0 && TA[6] == 0 && TA[10] == 0 ){}
	else if (TA[2] != 0 && TA[6] == 0  ){}
	else if (TA[3] != 0 && TA[7] == 0 && TA[11] == 0 && TA[15] ==0 ){}
	else if (TA[3] != 0 && TA[7] == 0 && TA[11] == 0 ){}
	else if (TA[3] != 0 && TA[7] == 0  ){}
	else if (TA[4] != 0 && TA[8] == 0 && TA[12] == 0 ){}
	else if (TA[4] != 0 && TA[8] == 0  ){}
	else if (TA[5] != 0 && TA[9] == 0 && TA[13] == 0 ){}
	else if (TA[5] != 0 && TA[9] == 0  ){}
	else if (TA[6] != 0 && TA[10] == 0 && TA[14] == 0 ){}
	else if (TA[6] != 0 && TA[10] == 0  ){}
	else if (TA[7] != 0 && TA[11] == 0 && TA[15] == 0 ){}
	else if (TA[7] != 0 && TA[11] == 0  ){}
	else if (TA[8] != 0 && TA[12] == 0  ){}
	else if (TA[9] != 0 && TA[13] == 0  ){}
	else if (TA[10] != 0 && TA[14] == 0  ){}
	else if (TA[11] != 0 && TA[15] == 0  ){}
	else{
	    TA[0]=99; //putting a 99 in the queue will result in a "you lose" screen
	}
}

void Moving(void)// This is the main combinational logic function of the virtual TileArray which allows movement of up,down,left,right		 
{                // Function checks the queue for 0"UP" 1"Right" 2"Left" and 3"Down" and then checks for combination and sliding of numbers in all rows/columns based on direction
int move = front(ButtonQueue);
dequeue(ButtonQueue);
switch (move) {
            case 0: //UP
                if ( TA[12]==TA[8] && TA[4]==TA[0])
								{
									TA[8]= TA[12]+TA[8];
									TA[12] = 0;
									TA[0]= TA[4]+TA[0];
									TA[4] = 0;
								}
								else if (TA[12]==TA[8])
								{
									TA[8]=TA[12]+TA[8];
									TA[12]=0;
								}
								else if (TA[8]==TA[4])
								{
									TA[4]=TA[8]+TA[4];
									TA[8]=0;
								}
								else if (TA[4]==TA[0])
								{
									TA[0]=TA[4]+TA[0];
									TA[4]=0;
								}
								if (TA[13]==TA[9] && TA[5]==TA[1])
								{
									TA[9]=TA[13]+TA[9];
									TA[13]=0;
									TA[1]=TA[5]+TA[1];
									TA[5]=0;
								}
								else if (TA[13]==TA[9])
								{
									TA[9]=TA[13]+TA[9];
									TA[13]=0;
								}
								else if (TA[9]==TA[5])
								{
									TA[5]=TA[9]+TA[5];
									TA[9]=0;
								}
								else if (TA[5]==TA[1])
								{
									TA[1]=TA[5]+TA[1];
									TA[5]=0;
								}
								if (TA[14]==TA[10] && TA[6]==TA[2])
								{
									TA[10]=TA[14]+TA[10];
									TA[14]=0;
									TA[2]=TA[6]+TA[2];
									TA[14]=0;
								}
								else if (TA[14]==TA[10])
								{
									TA[10]=TA[14]+TA[10];
									TA[14]=0;
								}
								else if (TA[10]==TA[6])
								{
									TA[6]=TA[10]+TA[6];
									TA[10]=0;
								}
								else if (TA[6]==TA[2])
								{
									TA[2]=TA[6]+TA[2];
									TA[6]=0;
								}
								if (TA[15]==TA[11] && TA[7]==TA[3])
								{
									TA[11]=TA[15]+TA[11];
									TA[15]=0;
									TA[3]=TA[7]+TA[3];
									TA[7]=0;
								}
								else if (TA[15]==TA[11])
								{
									TA[11]=TA[15]+TA[11];
									TA[15]=0;
								}
								else if (TA[11]==TA[7])
								{
									TA[7]=TA[11]+TA[7];
									TA[11]=0;
								}
								else if (TA[7]==TA[3])
								{
									TA[3]=TA[7]+TA[3];
									TA[7]=0;
								}
									
								if (TA[12] != 0 && TA[8] == 0 && TA[4] == 0 && TA[0] ==0){ TA[0] = TA[12]; TA[12] = 0;}
								else if (TA[12] != 0 && TA[8] == 0 && TA[4] == 0){ TA[4] = TA[12]; TA[12] = 0;}
								else if (TA[12] != 0 && TA[8] == 0){TA[8] = TA[12]; TA[12] = 0;}

								if (TA[13] != 0 && TA[9] == 0 && TA[5] == 0 && TA[1] ==0 ){TA[1] = TA[13] ; TA[13] = 0;}
								else if (TA[13] != 0 && TA[9] == 0 && TA[5] == 0 ){ TA[5] = TA[13] ; TA[13] = 0;}
								else if (TA[13] != 0 && TA[9] == 0  ){ TA[9] = TA[13] ; TA[13] = 0;}

								if (TA[14] != 0 && TA[10] == 0 && TA[6] == 0 && TA[2] ==0 ){TA[2] = TA[14] ; TA[14] = 0;}
								else if (TA[14] != 0 && TA[10] == 0 && TA[6] == 0 ){ TA[6] = TA[14] ; TA[14] = 0;}
								else if (TA[14] != 0 && TA[10] == 0  ){ TA[10] = TA[14] ; TA[14] = 0;}

								if (TA[15] != 0 && TA[11] == 0 && TA[7] == 0 && TA[3] ==0 ){TA[3] = TA[15] ; TA[15] = 0;}
								else if (TA[15] != 0 && TA[11] == 0 && TA[7] == 0 ){TA[7] = TA[15] ; TA[15] = 0;}
								else if (TA[15] != 0 && TA[11] == 0  ){TA[11] = TA[15] ; TA[15] = 0;}

								if (TA[8] != 0 && TA[4] == 0 && TA[0] == 0){TA[0] = TA[8] ; TA[8] = 0;}
								else if (TA[8] != 0 && TA[4] == 0  ){ TA[4] = TA[8] ; TA[8] = 0;}

								if (TA[9] != 0 && TA[5] == 0 && TA[1] == 0){TA[1] = TA[9] ; TA[9] = 0;}
								else if (TA[9] != 0 && TA[5] == 0  ){ TA[5] = TA[9] ; TA[9] = 0;}

								if (TA[10] != 0 && TA[6] == 0 && TA[2] == 0){TA[2] = TA[10] ; TA[10] = 0;}
								else if (TA[10] != 0 && TA[6] == 0  ){ TA[6] = TA[10] ; TA[10] = 0;}

								if (TA[11] != 0 && TA[7] == 0 && TA[3] == 0){ TA[3] = TA[11] ; TA[11] = 0;}
								else if (TA[11] != 0 && TA[7] == 0){ TA[7] = TA[11] ; TA[11] = 0;}

								if (TA[4] != 0 && TA[0] == 0){ TA[0] = TA[4] ; TA[4] = 0;}

								if (TA[5] != 0 && TA[1] == 0){ TA[1] = TA[5] ; TA[5] = 0;}

								if (TA[6] != 0 && TA[2] == 0){ TA[2] = TA[6] ; TA[6] = 0;}

								if (TA[7] != 0 && TA[3] == 0){ TA[3] = TA[7] ; TA[7] = 0;}
                break;
            case 1: // Right
                if ( TA[3]==TA[2] && TA[1]==TA[0])
								{
									TA[3]= TA[3]+TA[2];
									TA[2]=0;
									TA[1]= TA[1]+TA[0];
									TA[0]=0;
								}
								else if (TA[3]==TA[2])
								{
									TA[3]=TA[2]+TA[3];
									TA[2]=0;
								}
								else if (TA[2]==TA[1])
								{
									TA[2]=TA[1]+TA[2];
									TA[1]=0;
								}
								else if (TA[1]==TA[0])
								{
									TA[1]=TA[1]+TA[0];
									TA[0]=0;
								}
								
								if (TA[7]==TA[6] && TA[5]==TA[4])
								{
									TA[7]=TA[7]+TA[6];
									TA[6]=0;
									TA[5]=TA[5]+TA[4];
									TA[4]=0;
								}
								else if (TA[7]==TA[6])
								{
									TA[7]=TA[7]+TA[6];
									TA[6]=0;
								}
								else if (TA[6]==TA[5])
								{
									TA[6]=TA[6]+TA[5];
									TA[5]=0;
								}
								else if (TA[5]==TA[4])
								{
									TA[5]=TA[5]+TA[4];
									TA[4]=0;
								}
								if (TA[11]==TA[10] && TA[9]==TA[8])
								{
									TA[11]=TA[11]+TA[10];
									TA[10]=0;
									TA[9]=TA[9]+TA[8];
									TA[8]=0;
								}
								else if (TA[11]==TA[10])
								{
									TA[11]=TA[11]+TA[10];
									TA[10]=0;
								}
								else if (TA[10]==TA[9])
								{
									TA[10]=TA[10]+TA[9];
									TA[9]=0;
								}
								else if (TA[9]==TA[8])
								{
									TA[9]=TA[9]+TA[8];
									TA[8]=0;
								}
								if (TA[15]==TA[14] && TA[13]==TA[12])
								{
									TA[15]=TA[14]+TA[15];
									TA[14]=0;
									TA[13]=TA[13]+TA[12];
									TA[12]=0;
								}
								else if (TA[15]==TA[14])
								{
									TA[15]=TA[15]+TA[14];
									TA[14]=0;
								}
								else if (TA[14]==TA[13])
								{
									TA[14]=TA[14]+TA[13];
									TA[13]=0;
								}
								else if (TA[13]==TA[12])
								{
									TA[13]=TA[12]+TA[13];
									TA[12]=0;
								}
									
									if (TA[0] != 0 && TA[1] == 0 && TA[2] == 0 && TA[3] ==0 ){ TA[3] = TA[0] ; TA[0] = 0;}
								else if (TA[0] != 0 && TA[1] == 0 && TA[2] == 0 ){ TA[2] = TA[0] ; TA[0] =0;}
								else if (TA[0] != 0 && TA[1] == 0  ){ TA[1] = TA[0]; TA[0] = 0;}

								if (TA[4] != 0 && TA[5] == 0 && TA[6] == 0 && TA[7] ==0 ){ TA[7] = TA[4] ; TA[4] = 0;}
								else if (TA[4] != 0 && TA[5] == 0 && TA[6] == 0 ){ TA[6] = TA[4] ; TA[4] = 0;}
								else if (TA[4] != 0 && TA[5] == 0  ){ TA[5] = TA[4] ; TA[4] = 0;}

								if (TA[8] != 0 && TA[9] == 0 && TA[10] == 0 && TA[11] ==0 ){ TA[11] = TA[8] ; TA[8] = 0;}
								else if (TA[8] != 0 && TA[9] == 0 && TA[10] == 0 ){ TA[10] = TA[8] ; TA[8] = 0;}
								else if (TA[8] != 0 && TA[9] == 0  ){ TA[9] = TA[8] ; TA[8] = 0;}

								if (TA[12] != 0 && TA[13] == 0 && TA[14] == 0 && TA[15] ==0 ){ TA[15] = TA[12] ; TA[12] = 0;}
								else if (TA[12] != 0 && TA[13] == 0 && TA[14] == 0 ){ TA[14] = TA[12] ; TA[12] = 0;}
								else if (TA[12] != 0 && TA[13] == 0  ){ TA[13] = TA[12] ; TA[12] = 0;}

								if (TA[1] != 0 && TA[2] == 0 && TA[3] == 0 ){ TA[3] = TA[1] ; TA[1] = 0;}
								else if (TA[1] != 0 && TA[2] == 0  ){ TA[2] = TA[1] ; TA[1] = 0;}

								if (TA[5] != 0 && TA[6] == 0 && TA[6] == 0 ){ TA[6] = TA[5] ; TA[5] = 0;}
								else if (TA[5] != 0 && TA[6] == 0  ){ TA[5] = TA[5] ; TA[5] = 0;}

								if (TA[9] != 0 && TA[10] == 0 && TA[11] == 0 ){ TA[11] = TA[9] ; TA[9] = 0;}
								else if (TA[9] != 0 && TA[10] == 0  ){ TA[10] = TA[9] ; TA[9] = 0;}

								if (TA[13] != 0 && TA[14] == 0 && TA[15] == 0 ){ TA[15] =TA[13] ; TA[13] = 0;}
								else if (TA[13] != 0 && TA[14] == 0  ){ TA[14] = TA[13] ; TA[13] = 0;}

								if (TA[2] != 0 && TA[3] == 0  ){ TA[3] = TA[2] ; TA[2] = 0;}

								if (TA[6] != 0 && TA[7] == 0  ){ TA[7] = TA[6] ; TA[6] = 0;}

								if (TA[10] != 0 && TA[11] == 0  ){ TA[11] = TA[10] ; TA[10] = 0;}
								
								if (TA[13] != 0 && TA[14] == 0  ){ TA[14] = TA[13] ; TA[13] = 0;}
                break;
								
            case 2: // Left
                if ( TA[3]==TA[2] && TA[1]==TA[0])
								{
									TA[2]= TA[3]+TA[2];
									TA[3]=0;
									TA[0]= TA[1]+TA[0];
									TA[1]=0;
								}
								else if (TA[3]==TA[2])
								{
									TA[2]=TA[2]+TA[3];
									TA[3]=0;
								}
								else if (TA[2]==TA[1])
								{
									TA[1]=TA[1]+TA[2];
									TA[2]=0;
								}
								else if (TA[1]==TA[0])
								{
									TA[0]=TA[1]+TA[0];
									TA[1]=0;
								}
								if (TA[7]==TA[6] && TA[5]==TA[4])
								{
									TA[6]=TA[7]+TA[6];
									TA[7]=0;
									TA[4]=TA[5]+TA[4];
									TA[5]=0;
								}
								else if (TA[7]==TA[6])
								{
									TA[6]=TA[7]+TA[6];
									TA[7]=0;
								}
								else if (TA[6]==TA[5])
								{
									TA[5]=TA[6]+TA[5];
									TA[6]=0;
								}
								else if (TA[5]==TA[4])
								{
									TA[4]=TA[5]+TA[4];
									TA[5]=0;
								}
								if (TA[11]==TA[10] && TA[9]==TA[8])
								{
									TA[10]=TA[11]+TA[10];
									TA[11]=0;
									TA[8]=TA[9]+TA[8];
									TA[9]=0;
								}
								else if (TA[11]==TA[10])
								{
									TA[10]=TA[11]+TA[10];
									TA[11]=0;
								}
								else if (TA[10]==TA[9])
								{
									TA[9]=TA[10]+TA[9];
									TA[10]=0;
								}
								else if (TA[9]==TA[8])
								{
									TA[8]=TA[9]+TA[8];
									TA[9]=0;
								}
								if (TA[15]==TA[14] && TA[13]==TA[12])
								{
									TA[14]=TA[15]+TA[14];
									TA[15]=0;
									TA[12]=TA[13]+TA[12];
									TA[13]=0;
								}
								else if (TA[15]==TA[14])
								{
									TA[14]=TA[15]+TA[14];
									TA[15]=0;
								}
								else if (TA[14]==TA[13])
								{
									TA[13]=TA[14]+TA[13];
									TA[14]=0;
								}
								else if (TA[13]==TA[12])
								{
									TA[12]=TA[12]+TA[13];
									TA[13]=0;
								}
									
								if (TA[3] != 0 && TA[2] == 0 && TA[1] == 0 && TA[0] ==0 ){ TA[0] = TA[3] ; TA[3] = 0;}
								else if (TA[3] != 0 && TA[2] == 0 && TA[1] == 0 ){ TA[1] = TA[3] ; TA[3] = 0;}
								else if (TA[3] != 0 && TA[2] == 0  ){ TA[2] = TA[3] ; TA[3] = 0;}

								if (TA[7] != 0 && TA[5] == 0 && TA[6] == 0 && TA[4] ==0 ){ TA[4] = TA[7] ; TA[7] = 0;}
								else if (TA[7] != 0 && TA[5] == 0 && TA[6] == 0 ){ TA[5] = TA[7] ; TA[7] = 0;}
								else if (TA[7] != 0 && TA[6] == 0  ){ TA[6] = TA[7] ; TA[7] = 0;}

								if (TA[11] != 0 && TA[9] == 0 && TA[10] == 0 && TA[8] ==0 ){ TA[8] = TA[11] ; TA[11] = 0;}
								else if (TA[11] != 0 && TA[9] == 0 && TA[10] == 0 ){ TA[9] = TA[11] ; TA[11] = 0;}
								else if (TA[11] != 0 && TA[10] == 0  ){ TA[10] = TA[11] ; TA[11] = 0;}

								if (TA[15] != 0 && TA[13] == 0 && TA[14] == 0 && TA[12] ==0 ){ TA[12] = TA[15] ; TA[15] = 0;}
								else if (TA[15] != 0 && TA[13] == 0 && TA[14] == 0 ){ TA[13] = TA[15] ; TA[15] = 0;}
								else if (TA[15] != 0 && TA[14] == 0  ){ TA[14] = TA[15] ; TA[15] = 0;}

								if (TA[2] != 0 && TA[1] == 0 && TA[0] == 0 ){ TA[0] = TA[2] ; TA[2] = 0;}
								else if (TA[2] != 0 && TA[1] == 0  ){ TA[1] = TA[2] ; TA[2] = 0;}

								if (TA[6] != 0 && TA[5] == 0 && TA[4] == 0 ){ TA[4] = TA[6] ; TA[6] = 0;}
								else if (TA[6] != 0 && TA[5] == 0  ){ TA[5] = TA[6] ; TA[6] = 0;}

								if (TA[10] != 0 && TA[9] == 0 && TA[8] == 0 ){ TA[8] = TA[10] ; TA[10] = 0;}
								else if (TA[10] != 0 && TA[9] == 0  ){ TA[9] = TA[10] ; TA[10] = 0;}

								if (TA[14] != 0 && TA[13] == 0 && TA[12] == 0 ){ TA[12] = TA[14] ; TA[14] = 0;}
								else if (TA[14] != 0 && TA[13] == 0 ){ TA[13] = TA[14] ; TA[14] = 0;}

								if (TA[1] != 0 && TA[0] == 0  ){ TA[0] = TA[1]; TA[1] = 0;}

								if (TA[5] != 0 && TA[4] == 0  ){ TA[4] = TA[5] ; TA[5] = 0;}

								if (TA[9] != 0 && TA[8] == 0  ){ TA[8] = TA[9] ; TA[9] = 0;}

								if (TA[13] != 0 && TA[12] == 0  ){ TA[12] = TA[13] ; TA[13] = 0;}

                break;
	   case 3: // Down
		if ( TA[12]==TA[8] && TA[4]==TA[0])
								{
									TA[12]= TA[12]+TA[8];
									TA[8]=0;
									TA[4]= TA[4]+TA[0];
									TA[0]=0;
								}
								else if (TA[12]==TA[8])
								{
									TA[12]=TA[12]+TA[8];
									TA[8]=0;
								}
								else if (TA[8]==TA[4])
								{
									TA[8]=TA[8]+TA[4];
									TA[4]=0;
								}
								else if (TA[4]==TA[0])
								{
									TA[4]=TA[4]+TA[0];
									TA[0]=0;
								}
								if (TA[13]==TA[9] && TA[5]==TA[1])
								{
									TA[13]=TA[13]+TA[9];
									TA[9]=0;
									TA[5]=TA[5]+TA[1];
									TA[1]=0;
								}
								else if (TA[13]==TA[9])
								{
									TA[13]=TA[13]+TA[9];
									TA[9]=0;
								}
								else if (TA[9]==TA[5])
								{
									TA[9]=TA[9]+TA[5];
									TA[5]=0;
								}
								else if (TA[5]==TA[1])
								{
									TA[5]=TA[5]+TA[1];
									TA[1]=0;
								}
								if (TA[14]==TA[10] && TA[6]==TA[2])
								{
									TA[14]=TA[14]+TA[10];
									TA[10]=0;
									TA[6]=TA[6]+TA[2];
									TA[2]=0;
								}
								else if (TA[14]==TA[10])
								{
									TA[14]=TA[14]+TA[10];
									TA[10]=0;
								}
								else if (TA[10]==TA[6])
								{
									TA[10]=TA[10]+TA[6];
									TA[6]=0;
								}
								else if (TA[6]==TA[2])
								{
									TA[6]=TA[6]+TA[2];
									TA[2]=0;
								}
								if (TA[15]==TA[11] && TA[7]==TA[3])
								{
									TA[15]=TA[15]+TA[11];
									TA[11]=0;
									TA[6]=TA[6]+TA[3];
									TA[3]=0;
								}
								else if (TA[15]==TA[11])
								{
									TA[15]=TA[15]+TA[11];
									TA[11]=0;
								}
								else if (TA[11]==TA[7])
								{
									TA[11]=TA[11]+TA[7];
									TA[7]=0;
								}
								else if (TA[7]==TA[3])
								{
									TA[7]=TA[7]+TA[3];
									TA[3]=0;
								}
									
								if (TA[0] != 0 && TA[4] == 0 && TA[8] == 0 && TA[12] ==0 ){ TA[12] = TA[0] ; TA[0] = 0;}
								else if (TA[0] != 0 && TA[4] == 0 && TA[8] == 0 ){ TA[8] = TA[0] ; TA[0] = 0;}
								else if (TA[0] != 0 && TA[4] == 0  ){ TA[4] = TA[0] ; TA[0] = 0;}

								if (TA[1] != 0 && TA[5] == 0 && TA[9] == 0 && TA[13] ==0 ){ TA[13] = TA[1] ; TA[1] = 0;}
								else if (TA[1] != 0 && TA[5] == 0 && TA[9] == 0 ){ TA[9] = TA[1] ; TA[1] = 0;}
								else if (TA[1] != 0 && TA[5] == 0  ){ TA[5] = TA[1] ; TA[1] = 0;}

								if (TA[2] != 0 && TA[6] == 0 && TA[10] == 0 && TA[14] ==0 ){ TA[14] = TA[2] ; TA[2] = 0;}
								else if (TA[2] != 0 && TA[6] == 0 && TA[10] == 0 ){ TA[10] = TA[2] ; TA[2] = 0;}
								else if (TA[2] != 0 && TA[6] == 0  ){ TA[6] = TA[2] ; TA[2] = 0;}

								if (TA[3] != 0 && TA[7] == 0 && TA[11] == 0 && TA[15] ==0 ){ TA[15] = TA[3] ; TA[3] = 0;}
								else if (TA[3] != 0 && TA[7] == 0 && TA[11] == 0 ){ TA[11] = TA[3] ; TA[3] = 0;}
								else if (TA[3] != 0 && TA[7] == 0  ){ TA[7] = TA[3] ; TA[3] = 0;}

								if (TA[4] != 0 && TA[8] == 0 && TA[12] == 0 ){ TA[12] = TA[4] ; TA[4] = 0;}
								else if (TA[4] != 0 && TA[8] == 0  ){ TA[8] = TA[4] ; TA[4] = 0;}

								if (TA[5] != 0 && TA[9] == 0 && TA[13] == 0 ){ TA[13] = TA[5] ; TA[5] = 0;}
								else if (TA[5] != 0 && TA[9] == 0  ){ TA[9] = TA[5] ; TA[5] = 0;}

								if (TA[6] != 0 && TA[10] == 0 && TA[14] == 0 ){ TA[14] = TA[6] ; TA[6] =0;}
								else if (TA[6] != 0 && TA[10] == 0  ){ TA[10] = TA[6] ; TA[6] = 0;}

								if (TA[7] != 0 && TA[11] == 0 && TA[15] == 0 ){ TA[15] = TA[7] ; TA[7] = 0;}
								else if (TA[7] != 0 && TA[11] == 0  ){ TA[11] = TA[7] ; TA[7] = 0;}

								if (TA[8] != 0 && TA[12] == 0  ){ TA[12] = TA[8] ; TA[8] = 0;}

								if (TA[9] != 0 && TA[13] == 0  ){ TA[13] = TA[9] ; TA[9] = 0;}

								if (TA[10] != 0 && TA[14] == 0  ){ TA[14] = TA[10] ; TA[10] = 0;}

								if (TA[11] != 0 && TA[15] == 0  ){ TA[15] = TA[11] ; TA[11] = 0;}
							break;
						
            default:
                
                break;
        }  

}
