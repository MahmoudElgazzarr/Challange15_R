/*
 * UART.h
 *
 * Created: 2/27/2019 1:11:51 PM
 *  Author: AVE-LAP-040
 */ 


#ifndef UART_H_
#define UART_H_

#include "Types.h"

#define UBRRL_REG (*(volatile uint8*) 0x29)
#define UCSRB_REG (*(volatile uint8*) 0x2A)
#define UCSRA_REG (*(volatile uint8*) 0x2A)
#define UDR_REG   (*(volatile uint8*) 0x2C)
#define SREG_REG  (*(volatile uint8*) 0x5F)
#define UBRRH_REG (*(volatile uint8*) 0x40)
#define UCSRC_REG (*(volatile uint8*) 0x40)



#define SIXTEEN         ((uint8) 16 )
#define ONE             ((uint8) 1 )
#define EIGHT_BITS      ((uint8)8)
#define SIXTEEN_BITS    ((uint8)16)
#define FIRST_FOUR_BITS ((uint8) 0x0F)


typedef enum{
		URSEL_BIT = ((uint8) 7 ),
	}UBRRH_BITS_e;
	
	
typedef enum{
		UCPOL_BIT = ((uint8) 0 ),
		UCSZ0_BIT = ((uint8) 1 ),
		UCSZ1_BIT = ((uint8) 2 ),
		USBS_BIT  = ((uint8) 3 ),
		UPM0_BIT  = ((uint8) 4 ),
		UPM1_BIT  = ((uint8) 5 ),
		UMSEL_BIT = ((uint8) 6 ),
	}UCSRC_BITS_e;
	
typedef enum{
		MPCM_BIT = ((uint8) 0 ),
		U2X_BIT  = ((uint8) 1 ),
		PE_BIT   = ((uint8) 2 ),
		DOR_BIT  = ((uint8) 3 ),
		FE_BIT   = ((uint8) 4 ),
		UDER_BIT = ((uint8) 5 ),
		TXC_BIT  = ((uint8) 6 ),
		RXC_BIT  = ((uint8) 7 ),
	}UCSRA_BITS_e;
	
typedef enum{
		TXB8_BIT  = ((uint8) 0 ),
		RXB8_BIT  = ((uint8) 1 ),
		UCSZ2_BIT = ((uint8) 2 ),
		TXEN_BIT  = ((uint8) 3 ),
		RXEN_BIT  = ((uint8) 4 ),
		UDRIE_BIT = ((uint8) 5 ),
		TXCIE_BIT = ((uint8) 6 ),
		RXCIE_BIT = ((uint8) 7 ),
	}UCSRB_BITS_e;	



#endif /* UART_H_ */