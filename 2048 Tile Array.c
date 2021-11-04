// Cory Thatcher, Evan Dickerson, Matthew Childs
#include "stm32l053xx.h"

// Function List
void Moving(uint32_t direction);

int static TA[16]= {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};


void Moving(uint32_t direction)
{
int move = Queue[0];
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
                
                break;
            case 2: // Left
                
                break;
						case 3: // Down
							
							break;
						
            default:
                printf("Out of range");
                break;
        }
        return 0;

}
