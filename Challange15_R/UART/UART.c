/*
 * UART.c
 *
 * Created: 2/27/2019 2:34:28 PM
 *  Author: AVE-LAP-040
 */
#include "Types.h" 
#include "UART.h"
#include "Config_UART.h"

void USART_Init( uint32 baud )
{
	/* Set baud rate */
	UBRRH_REG = (uint8)(baud>>8);
	UBRRL_REG = (uint8)baud;
	/* Enable receiver and transmitter */
	UCSRB_REG = (1<<RXEN)|(1<<TXEN);
	/* Set frame format: 8data, 2stop bit */
	UCSRC_REG = (1<<URSEL)|(1<<USBS)|(3<<UCSZ0);
}

void USART_Transmit( uint8 data )
{
	/* Wait for empty transmit buffer */
	while ( !( UCSRA_REG & (1<<UDRE)) )
	;
	/* Put data into buffer, sends the data */
	UDR_REG = data;
}

uint8 USART_Receive( void )
{
	/* Wait for data to be received */
	while ( !( UCSRA_REG & (1 << (RXC))));
	
	/* Get and return received data from buffer */
	return UDR_REG;
}