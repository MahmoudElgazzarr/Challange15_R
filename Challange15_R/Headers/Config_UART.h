/*
 * UART_cng.h
 *
 * Created: 2/27/2019 3:16:24 PM
 *  Author: AVE-LAP-049
 */ 

#ifndef CONFIG_UART_H_
#define CONFIG_UART_H_


#define BAUD_RATE    ((uint32) 9600)
#define NO_STOP_BITS ((uint8)  2   )
#define PARITY_MODE  ((uint8)  1   )
#define DATA_SIZE    ((uint8)  8   )
#define SPEED_MODE   ((uint8)  1   )
#define UART_CPOL    ((uint8)  0   ) 

#define FOSC	((uint32) 16000000)

typedef struct{
	uint32 BaudRate;
	uint8 No_StopBits;
	uint8 ParityMode;
	uint8 DataSize;
	uint8 SpeedMode;
	uint8 ClockPolarity;
}UART_Config;

typedef enum{
		UART_RisingPol  = ((uint8) 0 ),
		UART_FallingPol = ((uint8) 1 ),
	}UART_ClockPolarity_e;


typedef enum{
		UART_OneStopBit  = ((uint8) 0 ),
		UART_TwoStopBit  = ((uint8) 1 ),
	}UART_NoStopBits_e;

typedef enum{
		UART_DisableParityBit = ((uint8) 0 ),
		UART_EvenParityBit    = ((uint8) 1 ),
		UART_OddParityBit     = ((uint8) 2 ),
	}UART_ClockParity_e;

typedef enum{
		UART_5_Bits = ((uint8) 5 ),
		UART_6_Bits = ((uint8) 6 ),
		UART_7_Bits = ((uint8) 7 ),
		UART_8_Bits = ((uint8) 8 ),
	}UART_DataSize_e;

typedef enum{
		UART_NormalSpeedMode  = ((uint8) 0 ),
		UART_DoubleSpeedMode  = ((uint8) 1 ),
	}UART_SpeedMode_e;

#endif