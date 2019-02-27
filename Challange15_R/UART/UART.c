/*
 * UART.c
 *
 * Created: 2/27/2019 2:34:28 PM
 *  Author: AVE-LAP-040
 */ 


#include "Types.h"
#include "UART.h"
#include "Config_UART.h"
#include "BitwiseOperation.h"

void UART_Init (void)
{
	uint32 UBRR_temp;
	
	
	UART_Config UART_Config_S;
	
	UART_Config_S.BaudRate      = BAUD_RATE;   /* Set BaudRate */
	UART_Config_S.No_StopBits   = NO_STOP_BITS; /* Set Numbers of Stop Bits ( 1 or 2) */
	UART_Config_S.ParityMode    = PARITY_MODE;  /* Set Parity Mode (No Parity , Even , Odd) */ 
	UART_Config_S.DataSize      = DATA_SIZE;    /* Set Data Size ( 5 bit, 6 bit, 7 bit, 8 bit ) */
	UART_Config_S.SpeedMode     = SPEED_MODE;   /* Set Speed Mode ( Normal or Double ) */
	UART_Config_S.ClockPolarity = UART_CPOL;   /* Set UART Clock Polarity ( Rising Edge or Falling Edge ) */
	
	/* Set BaudRate */
	/* Clear URSEL Bit to Write in UBRRH Register */ 
	Clear_Bit(UBRRH_REG,URSEL_BIT);
	
	UBRR_temp = (FOSC / (SIXTEEN * UART_Config_S.BaudRate)) - ONE  ;

						              /* Set Bits (11,10,9,8) in BaudRate to UBRRH Register */
	UBRRH_REG = (uint8)( UBRR_temp >> EIGHT_BITS );
	UBRRL_REG = (uint8)(UBRR_temp); /* Set First Eight Bits in BaudRate to UBRRL Register */
	
	/* Set URSEL Bit to Write in UCSRC Register */
	Set_Bit(UCSRC_REG,URSEL_BIT);
	
	/* Set UART Clock Polarity*/
	switch(UART_Config_S.ClockPolarity)
	{
		case UART_RisingPol  : Clear_Bit(UCSRC_REG,UCPOL_BIT); /* Rising Edge */
		                        break;
		case UART_FallingPol : Set_Bit(UCSRC_REG,UCPOL_BIT); /* Falling Edge */
		                        break;
		default:break;
	}
	
	/* Set Data Size ( 5 bit, 6 bit, 7 bit, 8 bit ) */
	switch(UART_Config_S.DataSize)
	{
		case UART_5_Bits :  Clear_Bit(UCSRC_REG,UCSZ0_BIT); /* Clear UCSZ0 BIT and Clear UCSZ1  */
							Clear_Bit(UCSRC_REG,UCSZ1_BIT); /* Data Size 5 Bits */
							break;
		case UART_6_Bits :  Set_Bit(UCSRC_REG,UCSZ0_BIT);   /* Set UCSZ0 BIT and Clear UCSZ1  */
		                    Clear_Bit(UCSRC_REG,UCSZ1_BIT); /* Data Size 6 Bits */
							break;
		case UART_7_Bits :  Clear_Bit(UCSRC_REG,UCSZ0_BIT); /* Clear UCSZ0 BIT and Set UCSZ1  */
		                    Set_Bit(UCSRC_REG,UCSZ1_BIT);   /* Data Size 7 Bits */
							break;
		case UART_8_Bits :  Set_Bit(UCSRC_REG,UCSZ0_BIT);  /* Set UCSZ0 BIT and Set UCSZ1  */
		                    Set_Bit(UCSRC_REG,UCSZ1_BIT);  /* Data Size 8 Bits */
							break;
		default:break;
		
	}
	
	
	/* Set Numbers of Stop Bits ( 1 or 2) */
	switch(UART_Config_S.No_StopBits)
	{
		case UART_OneStopBit : Clear_Bit(UCSRC_REG,USBS_BIT); /* Clear USBS Bit for one stop bit */
		                       break;
		case UART_TwoStopBit : Set_Bit(UCSRC_REG,USBS_BIT);   /* Set USBS Bit for two stop bit */
		                       break;
		default:break;
	}
	
	/* Set Parity Mode (No Parity , Even , Odd) */
	switch (UART_Config_S.ParityMode)
	{
		case UART_DisableParityBit : Clear_Bit(UCSRC_REG,UPM0_BIT); /* Clear UPM0_BIT and Clear UPM1 BIT for Disable Parity Bit */
									 Clear_Bit(UCSRC_REG,UPM1_BIT);
									 break;
		case UART_EvenParityBit    : Clear_Bit(UCSRC_REG,UPM0_BIT); /* Clear UPM0_BIT and Set UPM1 BIT for Disable Parity Bit */
									 Set_Bit(UCSRC_REG,UPM1_BIT);
									 break;
		case UART_OddParityBit     : Set_Bit(UCSRC_REG,UPM0_BIT);   /* Set UPM0_BIT and Set UPM1 BIT for Disable Parity Bit */
									 Set_Bit(UCSRC_REG,UPM1_BIT);
									 break;
		default:break;
	}
	
	/* Set Speed Mode ( Normal or Double ) */
	switch(UART_Config_S.SpeedMode)
	{
		case UART_NormalSpeedMode : Clear_Bit(UCSRA_REG,U2X_BIT); /* Clear U2X Bit for Normal Speed Mode */
		                            break;
		case UART_DoubleSpeedMode : Set_Bit(UCSRA_REG,U2X_BIT);  /* Set U2X Bit for Double Speed Mode */
		                            break;
		default:break;
	}
	
	/* Enable receiver and transmitter*/
	
	Set_Bit(UCSRB_REG,TXEN_BIT);  /* Set TXEN  Bit For Enable Transmitter */
	Set_Bit(UCSRB_REG,RXEN_BIT);  /* Set RXEN  Bit For Enable Receiver */
	Set_Bit(UCSRB_REG,RXCIE_BIT); /* Set RXCIE Bit For Enable Interrupt Receiver */
	
}