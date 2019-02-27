/*
 * Schedular.c
 *
 * Created: 2/23/2019 2:13:24 PM
 * Author : AVE-LAP-040
 */ 

#define FIVE_HUNDRED_OS_TICKS 500
#define ONE_OS_TICK 1
/*#include <avr/io.h>*/
#include "DIO.h"
#include "DIO_Definitions.h"
#include "Task.h"
#include "Schedular.h"

int main(void)
{
	/*Set Leds As OUTPUt*/
	DIO_SetPinDirection(PIN12,OUTPUT);
	DIO_SetPinDirection(PIN13,OUTPUT);
	DIO_SetPinDirection(PIN14,OUTPUT);
	DIO_SetPinDirection(PIN15,OUTPUT);
	
	/*Set Direction For Button */
	DIO_SetPinDirection(PIN10,INPUT);
	
	/*Schedular Data Structure Init*/
	scheduler_Init();
	
	/*Add Tasks*/
	scheduler_Add_Task(Task1,1000,1,0);
	scheduler_Add_Task(Task2,2000,1,1);
	scheduler_Add_Task(Task3,3000,1,2);
	scheduler_Add_Task(Task4,4000,1,3);
	scheduler_Add_Task(Task5,5000,1,4);
	
    /* Start Schedular */
	scheduler_Start(ONE_OS_TICK);
	
    while (1)
    {
		
    }
}

