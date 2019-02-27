/*
 * Schedular.c
 *
 * Created: 2/23/2019 2:13:24 PM
 * Author : AVE-LAP-040
 */

#include "DIO.h"
#include "DIO_Definitions.h"
#include "UART.h"

int main(void)
{
	/*Set Pin Direction For Tx and Rx*/
	
	DIO_SetPinDirection(PIN24,INPUT);
	DIO_SetPinDirection(PIN25,OUTPUT);
	
	/*Initalize USART*/
	USART_Init(9600);
	
	while (1)
	{
		USART_Transmit('A');
	}
	
}

