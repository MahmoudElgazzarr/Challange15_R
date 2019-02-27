/*
 * UART.h
 *
 * Created: 2/27/2019 1:11:51 PM
 *  Author: AVE-LAP-040
 */ 


#ifndef UART_H_
#define UART_H_

#include "Headers/Types.h"

#define UBRRL_REG (*(volatile uint8*) 0x29)
#define UCSRB_REG (*(volatile uint8*) 0x2A)
#define UCSRA_REG (*(volatile uint8*) 0x2A)
#define UDR_REG   (*(volatile uint8*) 0x2C)
#define SREG_REG  (*(volatile uint8*) 0x5F)
#define UBRRH_REG (*(volatile uint8*) 0x40)
#define UCSRC_REG (*(volatile uint8*) 0x40)


#define UART_RISING_POL  ((uint8) 0 )
#define UART_FALLING_POL ((uint8) 1 )


typedef enum{
		URSEL_BIT ((uint8) 7 ),
	}UBRRH_BITS_e;
	
	
typedef enum{
		UCPOL_BIT ((uint8) 0 ),
		UCSZ0_BIT ((uint8) 1 ),
		UCSZ1_BIT ((uint8) 2 ),
		USBS_BIT  ((uint8) 3 ),
		UPM0_BIT  ((uint8) 4 ),
		UPM1_BIT  ((uint8) 5 ),
		UMSEL_BIT ((uint8) 6 ),
		URSEL_BIT ((uint8) 7 ),
	}UCSRC_BITS_e;
	
	




#define EIGHT_BITS      ((uint8)8)
#define FIRST_FOUR_BITS ((uint8) 0x0F)



#endif /* UART_H_ */