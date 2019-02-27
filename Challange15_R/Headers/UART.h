/*
 * UART.h
 *
 * Created: 2/27/2019 1:11:51 PM
 *  Author: AVE-LAP-040
 */ 



#ifndef UART_H_
#define UART_H_

#define UBRRL_REG (*(volatile uint8*) 0x29)
#define UCSRB_REG (*(volatile uint8*) 0x2A)
#define UCSRA_REG (*(volatile uint8*) 0x2A)
#define UDR_REG (*(volatile uint8*) 0x2C)
#define SREG_REG (*(volatile uint8*)0x5F)
#define UBRRH_REG (*(volatile uint8*)0x40)
#define UCSRC_REG (*(volatile uint8*)0x40)

void USART_Init( uint32 baud );
uint8 USART_Receive( void );
void USART_Transmit( uint8 data );

enum UBRRH_Bits
{
	URSEL = ((uint8) 7),
};
enum USBS_Bits
{
	USBS = ((uint8) 3),
};
enum UCSRC_Bits
{
	UCSZ0 = ((uint8) 1),
};
enum UCSRA_Bits
{
	RXC = ((uint8) 0),
	TXC = ((uint8) 1),
	UDRE = ((uint8) 5),
};

enum UCSRB_Bits
{
	TXEN = ((uint8) 3),
	RXEN = ((uint8) 4),
};
#endif /* UART_H_ */