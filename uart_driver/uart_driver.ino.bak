//to write flas 

/*const uint8_t myData[] PROGMEM = {0x01, 0x02, 0x03, 0x04, 0x05};
void setup() {
  uint8_t value = pgm_read_byte(&myData[0]);
  // Use the read value as needed
}*/

#include "uart.h"

void (*callBackFunction)(void);

void uartInit(uartHandle_t handle)
{

	
// Set baud rate to 9600
  UBRR0H = 0;
  UBRR0L = 103;
  
  // Enable transmitter and receiver
  UCSR0B |= (1 << TXEN0) | (1 << RXEN0);

  // Set frame format: 8 data bits, no parity, 1 stop bit
  UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
  
  //syncrhronous uart
  SETBIT(UCSR0C,6);
  CLEARBIT(UCSR0C,7);
  
  callBackFunction = handle.callBackFunc;
}

void enableUartInterrupt()
{
	SETBIT(UCSR0B,RXCIE0); //enable Reciever interrupt
}

ISR(USART_RX_vect)
{
	callBackFunction();
}

void uartRead(uint8_t* data)
{
	*data = UDR0;
}

void uartWrite(void)
{
	//needs to be impi
}
