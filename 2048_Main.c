// Matthew Childs, Evan Dickerson, Cory Thatcher
// functions dis_cmd_0, dis_cmd_1, unfill, and turn_off_all were adopted from  Dru Walkowski and Matthew Childs Display Lab
// This file initializes all the peripherals and the microcontroller itself
// This file also sets up the schedule for the tasks

/*
	THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR 
	IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY 
	AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
	HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, 
	EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF 
	SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER 
	CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
	(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
	EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include "stm32l053xx.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>




//funtion list for things that need to happen
void init_display(void);
void init_spi(void);
void init_gpio(void);
void dis_cmd_0(uint32_t com);
void dis_cmd_1(uint32_t com);
void unfill(uint32_t lsb,uint32_t msb);
void turn_off_all(void);
extern void UpdateKnobs(void);
extern void UpdateArray(void);
extern void UpdateDisplay(void);
extern void init_knobs();


struct Queue {
    int front, rear, size;
    unsigned capacity;
    int* array;
};

struct Queue* createQueue(unsigned capacity)
{
    struct Queue* queue = (struct Queue*)malloc(
        sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
 
    // This is important, see the enqueue
    queue->rear = capacity - 1;
    queue->array = (int*)malloc(
        queue->capacity * sizeof(int));
    return queue;
}
//checks if queue is full
int isFull(struct Queue* queue)
{
    return (queue->size == queue->capacity);
}
//checks if queue is empty
int isEmpty(struct Queue* queue)
{
    return (queue->size == 0);
}
 //add to the queue
void enqueue(struct Queue* queue, int item)
{
    if (isFull(queue))
        return;
    queue->rear = (queue->rear + 1)
                  % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
}
//remove from queue
int dequeue(struct Queue* queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1)
                   % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}

int front(struct Queue* queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    return queue->array[queue->front];
}

int rear(struct Queue* queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    return queue->array[queue->rear];
}

//Initialize display
void init_display(void)
{
	// turn on display 
	
	// has a 5ms delay from plug in
	for(volatile int32_t n = 0; n < 6; n++){}
		
	GPIOA->ODR &= (0 << 0);
	for(volatile int32_t n = 0; n < 20; n++){} // hardware reset (> 10ms)
	GPIOA->ODR |= 1 << 0;
		
	// commands
		dis_cmd_0(0x40);
		dis_cmd_0(0xA1);
		dis_cmd_0(0xC0);
		dis_cmd_0(0xA4);
		dis_cmd_0(0xA6);
		dis_cmd_0(0xA2);
		dis_cmd_0(0x2F);
		dis_cmd_0(0x27);
		dis_cmd_0(0x81);
		dis_cmd_0(0x10);
		dis_cmd_0(0xFA);
		dis_cmd_0(0x90);
		dis_cmd_0(0xAF);
		
}


void dis_cmd_0(uint32_t com)
{	
	// commands with CD/PA1 low
	GPIOA->ODR &= ~(1u << 1);
		
	GPIOA->ODR &= ~(1u << 4);
	SPI1->DR |= com;
	for(volatile int32_t n = 0; n < 3; n++){}
	while(SPI1->SR & SPI_SR_BSY){}
	GPIOA->ODR |= 1 << 4;
	
}

void dis_cmd_1(uint32_t com)
{	
	// data commands 
	GPIOA->ODR |= 1u << 1;
		
	GPIOA->ODR &= ~(1u << 4);
	SPI1->DR |= com;
	for(volatile int32_t n = 0; n < 3; n++){}
	while(SPI1->SR & SPI_SR_BSY){}
	GPIOA->ODR |= 1 << 4;
	
}
//Initialize GPIO
void init_gpio(void)
{
	// turning on the clk A
	RCC->IOPENR |= RCC_IOPENR_GPIOAEN;
	RCC->IOPENR |= RCC_IOPENR_GPIOBEN;
	
	
	// PA4, setting the select line as an output
	GPIOA->MODER &= ~(GPIO_MODER_MODE4_Msk);
	GPIOA->MODER |= 1 << (GPIO_MODER_MODE4_Pos);
	
	//PA5 set to alternate function (2), SPI clk
	GPIOA->MODER &= ~(GPIO_MODER_MODE5_Msk);
	GPIOA->MODER |= 2 << (GPIO_MODER_MODE5_Pos);
	
	//PA7 set to output (1), Data line
	GPIOA->MODER &= ~(GPIO_MODER_MODE7_Msk);
	GPIOA->MODER |= 2 << (GPIO_MODER_MODE7_Pos);
	
	//Note that these next few lines are commented due to not needing 
	// to use these registers but might have to depending on what
	// Alternate funcction(s) used.
	
	//for PA4, setting to AF0 in AFSEL4 
	//GPIOA->AFR &= ~(GPIO_AFRL_AFSEL4_Msk);
	//this isn't needed because the reset for register is 0
	//SPI is AF0 bits written to 0000
	
	// PA0 is the reset line active low, output
	GPIOA->MODER &= ~(GPIO_MODER_MODE0_Msk);
	GPIOA->MODER |= 1 << GPIO_MODER_MODE0_Pos;
	
	// PA1 is the command bit, output
	GPIOA->MODER &= ~(GPIO_MODER_MODE1_Msk);
	GPIOA->MODER |= 1 << GPIO_MODER_MODE1_Pos;
	
	//Knob Inputs
	GPIOB->MODER &= ~GPIO_MODER_MODE8_Msk;
    	GPIOB->MODER |= 0 << GPIO_MODER_MODE8_Pos; // PB8 Digital INPUT
    	GPIOB->PUPDR &= ~GPIO_PUPDR_PUPD8_Msk;
    	GPIOB->PUPDR |= 0x01 << GPIO_PUPDR_PUPD8_Pos; // Pull-up engaged
    
    	GPIOB->MODER &= ~GPIO_MODER_MODE9_Msk;
    	GPIOB->MODER |= 0 << GPIO_MODER_MODE9_Pos; // PB9 Digital INPUT
    	GPIOB->PUPDR &= ~GPIO_PUPDR_PUPD9_Msk;
    	GPIOB->PUPDR |= 0x01 << GPIO_PUPDR_PUPD9_Pos; // Pull-up engaged
			
			GPIOB->MODER &= ~GPIO_MODER_MODE4_Msk;
			GPIOB->MODER |= 0 << GPIO_MODER_MODE4_Pos; // PB4 Digital INPUT
			GPIOB->PUPDR &= ~GPIO_PUPDR_PUPD4_Msk;
			GPIOB->PUPDR |= 0x01 << GPIO_PUPDR_PUPD4_Pos; // Pull-up engaged
	
			GPIOB->MODER &= ~GPIO_MODER_MODE5_Msk;
			GPIOB->MODER |= 0 << GPIO_MODER_MODE5_Pos; // PB5 Digital INPUT
			GPIOB->PUPDR &= ~GPIO_PUPDR_PUPD5_Msk;
			GPIOB->PUPDR |= 0x01 << GPIO_PUPDR_PUPD5_Pos; // Pull-up engaged
	

}

//Function to init SPI peripherial
void init_spi(void)
{ 
	RCC->APB2ENR |= 1 << (RCC_APB2ENR_SPI1EN_Pos);
	//bit 11, 8-bit package
	//bit 9= 1, ssm
	//bit 8= 1, ssi
	//bit 7= 0, MSB first
	//bit 6= 1, SPI on
	//bits[5:3]= 0, clk divide by 2
	//bit 2= 1, MOSI
	//bit 1= 1, CPOL
	//bit 0= 1, CPHA
	SPI1->CR1 |= 1 << SPI_CR1_BR_Pos;
	SPI1->CR1 |= 1<< (SPI_CR1_SSM_Pos);
	SPI1->CR1 |= 1 << (SPI_CR1_SSI_Pos);
	SPI1->CR1 |= (1 << (SPI_CR1_MSTR_Pos));
	SPI1->CR1 |= (1 << (SPI_CR1_SPE_Pos));
	SPI1->CR1 |= 1 << SPI_CR1_CPOL_Pos;
	SPI1->CR1 |= 1 << SPI_CR1_CPHA_Pos;
	
}



void unfill(uint32_t lsb,uint32_t msb)
{
	dis_cmd_0(lsb);
	dis_cmd_0(msb);
	// turn off pixels in column
	dis_cmd_1(0x00);

}



void turn_off_all(void)
{// turning all pixels to 0
	
  for(volatile uint32_t y = 0; y < 8; y++)
	{
		// set the page address
		volatile uint32_t L = 0xB0;
		L |= y;
		
		dis_cmd_0(L);
		
		for(volatile uint32_t x = 0; x < 102; x++)
		{
			// set the column address in page (y)
			volatile uint32_t lsb = x & 0x0F;
			volatile uint32_t msb = ((x & 0xF0) >> 4) | 0x10;
			
			unfill(lsb,msb);
		}
	}
}

struct Queue* ButtonQueue;
struct Queue* DisplayQueue;

//Main Function
int main(void)

{
	//setting up the queues
	ButtonQueue = createQueue(1);
	DisplayQueue = createQueue(16);
	// gpio
	init_gpio();
	// spi
	init_spi();
	// display
	init_display();
	//GPOIA->ODR |= 1 << 0;
	init_knobs();
	turn_off_all();             //resets display bits to clear the screen
	while(1)
	{
		UpdateKnobs();
		UpdateArray();        // Schedule (note that UpdateArray and UpdateDisplay will be passed over if the queue inputs are null so most of the time is spent checking for knob updates) 
		UpdateDisplay();
	}
}
