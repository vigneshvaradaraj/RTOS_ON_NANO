typedef void (*callbackFunc_t)(void);

typdef struct
{
	uint8_t diviceAddress;
	uint8_t systemClkFrequency;
	uint8_t bitRate;
	callbackFunc_t i2cCallBackFunck;
}i2cHandle_t;
