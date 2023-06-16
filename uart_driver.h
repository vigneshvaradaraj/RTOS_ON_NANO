typedef struct
{
	int baurdrate;
	void (*callBackFunc)(void);
}uartHandle_t;

#define SETBIT(X,Y) X = (1<<Y)
#define CLEARBIT(X,Y) X = ~(1<<Y)

void enableUartInterrupt(void);
void uartRead(uint8_t*);