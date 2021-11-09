// Cory Thatcher, Evan Dickerson, Matthew Childs
#include "stm32l053xx.h"
#include "2048 Main.c"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// Function List
int main(void);
void Moving(void);
void SpawnRandom2(void);
int static TA[16]= {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};



void SpawnRandom2(void)
{
	int TileArray2[16];
	srand(time(NULL));
	for (int i =0; i<16;i++)
	{
	    
		if (TA[i]==0){
			TileArray2[i]=i;
		}
		
	}
   int Length = sizeof(TileArray2)/sizeof(TA[0]);
	int random_number= rand() % Length+1;
	TA[TileArray2[random_number]]=2;


}
void Moving(void)
{
int move = front(ButtonQueue);
switch (move) {
            case 0: //UP
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
								if (TA[13]==TA[9] && TA[5]==TA[1])
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
								if (TA[14]==TA[10] && TA[6]==TA[2])
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
								if (TA[15]==TA[11] && TA[7]==TA[3])
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
                break;
            case 1: // Right
                if ( TA[3]==TA[2] && TA[1]==TA[0])
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
								if (TA[7]==TA[6] && TA[5]==TA[4])
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
								if (TA[11]==TA[10] && TA[9]==TA[8])
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
								if (TA[15]==TA[14] && TA[13]==TA[12])
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
                break;
            case 2: // Left
                if ( TA[3]==TA[2] && TA[1]==TA[0])
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
								if (TA[7]==TA[6] && TA[5]==TA[4])
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
								if (TA[11]==TA[10] && TA[9]==TA[8])
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
								if (TA[15]==TA[14] && TA[13]==TA[12])
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
                break;
	   case 3: // Down
		if ( TA[12]==TA[8] && TA[4]==TA[0])
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
								if (TA[13]==TA[9] && TA[5]==TA[1])
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
								if (TA[14]==TA[10] && TA[6]==TA[2])
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
								if (TA[15]==TA[11] && TA[7]==TA[3])
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
							break;
						
            default:
                
                break;
        }  

}
