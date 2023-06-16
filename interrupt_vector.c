typedef (void)(*funcPtr)(void) funcPtr_t;

typedef struct 
{
	uint8_t opcode;
	funcPtr_t interruptHandler;
}vectorTable_t;
	

void default_function(void)
{
	//doing nothing.......................
}

void resetHandler()
{
	main();
}

void watchdogHandler(void)
{
	
}

vectorTable_t vectorArray328P[] = 
{
   	0x94,(uint16_t)resetHnadler,
	0x94,(uint16_t)default_function,//external int0
	0x94,(uint16_t)default_function,//external int1
	0x94,(uint16_t)default_function,//pin change interrupt 0
	0x94,(uint16_t)default_function,
	0x94,(uint16_t)default_function,
	0x94,(uint16_t)watchdogHandler,//
	0x94,(uint16_t)default_function,
	0x94,(uint16_t)default_function,
	0x94,(uint16_t)default_function,
	0x94,(uint16_t)default_function,
	0x94,(uint16_t)default_function,
	0x94,(uint16_t)default_function,
	0x94,(uint16_t)default_function,
	0x94,(uint16_t)default_function,
	0x94,(uint16_t)default_function,
	0x94,(uint16_t)default_function,
	0x94,(uint16_t)default_function,
}