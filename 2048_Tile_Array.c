// Cory Thatcher, Evan Dickerson, Matthew Childs
#include "stm32l053xx.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function List
int main(void);
void Moving(void);
void SpawnRandom2(void);
void UpdateArray(void);
void CheckLose(void);
int static TA[16]= {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};


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

void UpdateArray(void)
{
	//printwin();
	if(isEmpty(ButtonQueue)){}       //if no input from knobs then skips the task
	else{
		//print4(51,0);
		CheckLose();
		//print8(51,0);
		Moving();
		//print16(51,0);
		SpawnRandom2();
		//print32(51,0);
		for(int i=0; i<=16; i++){
			enqueue(DisplayQueue, TA[i]);
			//print32(51,0);
		}
	}
}


void SpawnRandom2(void)
{
	//print4(51,0);
	int TileArray2[16];
	//print8(51,0);
	//print4(51,0);
	for (int i =0; i<16;i++)
	{
	    //print8(51,0);
		if (TA[i]==0){
			TileArray2[i]=i;
		}
		
	}
	//print16(51,2);
   int Length = sizeof(TileArray2)/sizeof(TA[0]);
	int random_number= rand() % Length;
	TA[TileArray2[random_number]]=2;
	//print64(51,4);


}


void CheckLose(void)
{
	if ( TA[12]==TA[8] && TA[4]==TA[0])
	{
		TA[8]= TA[12]+TA[8];
		TA[0]= TA[4]+TA[0];
	}
	else if (TA[12]==TA[8])
	{
		TA[8]=TA[12]+TA[8];
	}
	else if (TA[8]==TA[4])
	{
		TA[4]=TA[8]+TA[4];
	}
	else if (TA[4]==TA[0])
	{
		TA[0]=TA[4]+TA[0];
	}
	else if (TA[13]==TA[9] && TA[5]==TA[1])
	{
		TA[9]=TA[13]+TA[9];
		TA[1]=TA[5]+TA[1];
	}
	else if (TA[13]==TA[9])
	{
		TA[9]=TA[13]+TA[9];
	}
	else if (TA[9]==TA[5])
	{
		TA[5]=TA[9]+TA[5];
	}
	else if (TA[5]==TA[1])
	{
		TA[1]=TA[5]+TA[1];
	}
	else if (TA[14]==TA[10] && TA[6]==TA[2])
	{
		TA[10]=TA[14]+TA[10];
		TA[2]=TA[6]+TA[2];
	}
	else if (TA[14]==TA[10])
	{
		TA[10]=TA[14]+TA[10];
	}
	else if (TA[10]==TA[6])
	{
		TA[6]=TA[10]+TA[6];
	}
	else if (TA[6]==TA[2])
	{
		TA[2]=TA[6]+TA[2];
	}
	else if (TA[15]==TA[11] && TA[7]==TA[3])
	{
		TA[11]=TA[15]+TA[11];
		TA[3]=TA[7]+TA[3];
	}
	else if (TA[15]==TA[11])
	{
		TA[11]=TA[15]+TA[11];
	}
	else if (TA[11]==TA[7])
	{
		TA[7]=TA[11]+TA[7];
	}
	else if (TA[7]==TA[3])
	{
		TA[3]=TA[7]+TA[3];
	}
	else if ( TA[3]==TA[2] && TA[1]==TA[0])
	{
		TA[3]= TA[3]+TA[2];
		TA[1]= TA[1]+TA[0];
	}
	else if (TA[3]==TA[2])
	{
		TA[3]=TA[2]+TA[3];
	}
	else if (TA[2]==TA[1])
	{
		TA[2]=TA[1]+TA[2];
	}
	else if (TA[1]==TA[0])
	{
		TA[1]=TA[1]+TA[0];
	}
	else if (TA[7]==TA[6] && TA[5]==TA[4])
	{
		TA[7]=TA[7]+TA[6];
		TA[5]=TA[5]+TA[4];
	}
	else if (TA[7]==TA[6])
	{
		TA[7]=TA[7]+TA[6];
	}
	else if (TA[6]==TA[5])
	{
		TA[6]=TA[6]+TA[5];
	}
	else if (TA[5]==TA[4])
	{
		TA[5]=TA[5]+TA[4];
	}
	else if (TA[11]==TA[10] && TA[9]==TA[8])
	{
		TA[11]=TA[11]+TA[10];
		TA[9]=TA[9]+TA[8];
	}
	else if (TA[11]==TA[10])
	{
		TA[11]=TA[11]+TA[10];
	}
	else if (TA[10]==TA[9])
	{
		TA[10]=TA[10]+TA[9];
	}
	else if (TA[9]==TA[8])
	{
		TA[9]=TA[9]+TA[8];
	}
	else if (TA[15]==TA[14] && TA[13]==TA[12])
	{
		TA[15]=TA[14]+TA[13];
		TA[13]=TA[13]+TA[12];
	}
	else if (TA[15]==TA[14])
	{
		TA[15]=TA[15]+TA[14];
	}
	else if (TA[14]==TA[13])
	{
		TA[14]=TA[14]+TA[13];
	}
	else if (TA[13]==TA[12])
	{
		TA[13]=TA[12]+TA[13];
	}
	else if ( TA[3]==TA[2] && TA[1]==TA[0])
	{
		TA[2]= TA[3]+TA[2];
		TA[0]= TA[1]+TA[0];
	}
	else if (TA[3]==TA[2])
	{
		TA[2]=TA[2]+TA[3];
	}
	else if (TA[2]==TA[1])
	{
		TA[1]=TA[1]+TA[2];
	}
	else if (TA[1]==TA[0])
	{
		TA[0]=TA[1]+TA[0];
	}
	else if (TA[7]==TA[6] && TA[5]==TA[4])
	{
		TA[6]=TA[7]+TA[6];
		TA[4]=TA[5]+TA[4];
	}
	else if (TA[7]==TA[6])
	{
		TA[6]=TA[7]+TA[6];
	}
	else if (TA[6]==TA[5])
	{
		TA[5]=TA[6]+TA[5];
	}
	else if (TA[5]==TA[4])
	{
		TA[4]=TA[5]+TA[4];
	}
	else if (TA[11]==TA[10] && TA[9]==TA[8])
	{
		TA[10]=TA[11]+TA[10];
		TA[8]=TA[9]+TA[8];
	}
	else if (TA[11]==TA[10])
	{
		TA[10]=TA[11]+TA[10];
	}
	else if (TA[10]==TA[9])
	{
		TA[9]=TA[10]+TA[9];
	}
	else if (TA[9]==TA[8])
	{
		TA[8]=TA[9]+TA[8];
	}
	else if (TA[15]==TA[14] && TA[13]==TA[12])
	{
		TA[14]=TA[15]+TA[14];
		TA[12]=TA[13]+TA[12];
	}
	else if (TA[15]==TA[14])
	{
		TA[14]=TA[15]+TA[14];
	}
	else if (TA[14]==TA[13])
	{
		TA[13]=TA[14]+TA[13];
	}
	else if (TA[13]==TA[12])
	{
		TA[12]=TA[12]+TA[13];
	}
	else if ( TA[12]==TA[8] && TA[4]==TA[0])
	{
		TA[12]= TA[12]+TA[8];
		TA[4]= TA[4]+TA[0];
	}
	else if (TA[12]==TA[8])
	{
		TA[12]=TA[12]+TA[8];
	}
	else if (TA[8]==TA[4])
	{
		TA[8]=TA[8]+TA[4];
	}
	else if (TA[4]==TA[0])
	{
		TA[4]=TA[4]+TA[0];
	}
	else if (TA[13]==TA[9] && TA[5]==TA[1])
	{
		TA[13]=TA[13]+TA[9];
		TA[5]=TA[5]+TA[1];
	}
	else if (TA[13]==TA[9])
	{
		TA[13]=TA[13]+TA[9];
	}
	else if (TA[9]==TA[5])
	{
		TA[9]=TA[9]+TA[5];
	}
	else if (TA[5]==TA[1])
	{
		TA[5]=TA[5]+TA[1];
	}
	else if (TA[14]==TA[10] && TA[6]==TA[2])
	{
		TA[14]=TA[14]+TA[10];
		TA[6]=TA[6]+TA[2];
	}
	else if (TA[14]==TA[10])
	{
		TA[14]=TA[14]+TA[10];
	}
	else if (TA[10]==TA[6])
	{
		TA[10]=TA[10]+TA[6];
	}
	else if (TA[6]==TA[2])
	{
		TA[6]=TA[6]+TA[2];
	}
	else if (TA[15]==TA[11] && TA[7]==TA[3])
	{
		TA[15]=TA[15]+TA[11];
		TA[6]=TA[6]+TA[3];
	}
	else if (TA[15]==TA[11])
	{
		TA[15]=TA[15]+TA[11];
	}
	else if (TA[11]==TA[7])
	{
		TA[11]=TA[11]+TA[7];
	}
	else if (TA[7]==TA[3])
	{
		TA[7]=TA[7]+TA[3];
	}
	else{
	    TA[0]=99;
	}
}

void Moving(void)
{
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
								else {}
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
								else{}
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
								else {}
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
								else {}
									
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
								else{}
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
								else{}
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
								else{}
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
								else{}
									
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
								else{}
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
								else{}
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
								else{}
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
								else {}
									
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
								else{}
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
								else{}
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
								else{}
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
								else{}
									
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
