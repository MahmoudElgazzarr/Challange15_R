/*
 * UART.h
 *
 * Created: 2/27/2019 1:11:51 PM
 *  Author: AVE-LAP-040
 */ 


#ifndef UART_H_
#define UART_H_


void USART_Init( unsigned int baud );

#define UBRRL_REG (*(volatile uint8*) 0x29)
#define UCSRB_REG (*(volatile uint8*) 0x2A)
#define UCSRA_REG (*(volatile uint8*) 0x2A)
#define UDR_REG (*(volatile uint8*)0x2C)
#define SREG_REG (*(volatile uint8*)0x5F)
#define UBRRH_REG (*(volatile uint8*)0x40)
#define UCSRC_REG (*(volatile uint8*)0x40)


typedef enum{
	
	x,
	}UBRRL_E;

typedef enum Baud_Rate_E
{
    BaudRate_9600 = ((uint16) 9600),
	BaudRate_115200 = ((uint16) 115200),
}Baud_Rate_E_T;

typedef enum UCSRA_E
{
	RXC = ((uint8) 0),
	TXC = ((uint8) 1),
}UCSRA_E_T;
#endif /* UART_H_ */