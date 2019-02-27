/*
 * UART.c
 *
 * Created: 2/27/2019 2:34:28 PM
 *  Author: AVE-LAP-040
 */ 


#include "Headers/Types.h"
#include "Headers/Config_UART.h"
#include "Headers/UART.h"
#include "BitwiseOperation.h"

void UART_Init (void)
{
	
	struct UART_Config_S{
		uint32 BaudRate     = BAUD_RATE;   /* Set BaudRate */
		uint8 No_StopBits   = No_StopBits; /* Set Numbers of Stop Bits ( 1 or 2) */
		uint8 ParityMode    = ParityMode;  /* Set Parity Mode (No Parity , Even , Odd) */
		uint8 DataSize      = DataSize;    /* Set Data Size ( 5 bit, 6 bit, 7 bit, 8 bit ) */
		uint8 SpeedMode     = SpeedMode;   /* Set Speed Mode ( Normal or Double ) */
		uint8 ClockPolarity = UART_CPOL;   /* Set UART Clock Polarity ( Rising Edge or Falling Edge ) */
	};
	
	/* Set BaudRate */
	
	/* Clear URSEL Bit to Write in UBRRH Register */ 
	Clear_Bit(UBRRH,URSEL_BIT);
						              /* Set Bits (11,10,9,8) in BaudRate to UBRRH Register */
	UBRRH_REG = (uint8)((UART_Config_S.BaudRate >> EIGHT_BITS) & FIRST_FOUR_BITS ); 
	UBRRL_REG = (uint8)(UART_Config_S.BaudRate); /* Set First Eight Bits in BaudRate to UBRRL Register */
	
	/* Set URSEL Bit to Write in UCSRC Register */
	Set_Bit(UBRRH,URSEL_BIT);
	
	/* Set UART Clock Polarity*/
	switch(UART_Config_S.ClockPolarity)
	{
		case UART_RISING_POL  : Clear_Bit(UCSRC_REG,UCPOL_BIT); /* Rising Edge */
		                        break;
		case UART_FALLING_POL : Set_Bit(UCSRC_REG,UCPOL_BIT); /* Falling Edge */
		                        break;
		default:break;
	}
	
	/* Set Data Size ( 5 bit, 6 bit, 7 bit, 8 bit ) */
	
	
	
	
	/* Set Numbers of Stop Bits ( 1 or 2) */
	
	
	
	
	
	
	/* Set Parity Mode (No Parity , Even , Odd) */
	
	/* Set Speed Mode ( Normal or Double ) */
	
	/* Enable receiver and transmitter*/
	
}