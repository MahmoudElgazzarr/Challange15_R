/*
 * UART_Test.c
 *
 * Created: 2/27/2019 5:07:38 PM
 * Author : AVE-LAP-040
 */ 
#define F_CPU 16000000UL
#include "avr/delay.h"
#include "UART.h"
#include "UART_CFG.h"
#include "DIO_Definitions.h"
#include "DIO.h"
#include "Keypad.h"
#include "Keypad_cfg.h"
#include "LEDS.h"

int main(void)
{
	/*Set pins direction as input and output*/
	DIO_SetPinDirection(PIN24 , INPUT);
	DIO_SetPinDirection(PIN25 , OUTPUT);
	
	/*Fill Structure of baud rate */
		UART_Config_S.BaudRate      = BAUD_RATE;   /* Set BaudRate */
		UART_Config_S.No_StopBits   = UART_TwoStopBit; /* Set Numbers of Stop Bits ( 1 or 2) */
		UART_Config_S.ParityMode    = UART_DisableParityBit;  /* Set Parity Mode (No Parity , Even , Odd) */
		UART_Config_S.DataSize      = UART_8_Bits;    /* Set Data Size ( 5 bit, 6 bit, 7 bit, 8 bit ) */
		UART_Config_S.SpeedMode     = UART_NormalSpeedMode;   /* Set Speed Mode ( Normal or Double ) */
		UART_Config_S.ClockPolarity = UART_RisingPol;   /* Set UART Clock Polarity ( Rising Edge or Falling Edge ) */
		
    /* init UART */
	UART_Init ();
	
	/*intinalize keypad*/
	Keypad_init();
	/*Led init*/
	led_One_Init();
	led_Two_Init();
	
    while (1)
    {
		/*if key one pressed send A*/
		if(Keypad_getPressedKey() == 1 )
		{
			USART_Transmit('A');
			Led_One_Toggle();
		}
		/*if key two pressed send B*/
		if(Keypad_getPressedKey() == 2 )
		{
			USART_Transmit('B');
			Led_Two_Toggle();
		}
		_delay_ms(200);
    }
}

