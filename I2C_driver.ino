
#include "I2C_driver.h"
#define TWI_SLAVE_ADDRESS 0x27 // I2C slave address

// TWI (I2C) initialization

void TWI_Init() {
    TWBR = 32;                  // Set bit rate register (Baud rate: 100kHz @ 16MHz CPU frequency)
    TWSR = 0;                   // Set prescaler bits to zero for TWI normal mode
    TWCR = (1 << TWEN);         // Enable TWI interface
}

// TWI (I2C) start condition
void TWI_Start() {
    TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);
    while (!(TWCR & (1 << TWINT)));
}

// TWI (I2C) stop condition
void TWI_Stop() {
    TWCR = (1 << TWINT) | (1 << TWSTO) | (1 << TWEN);
}

// TWI (I2C) write byte
bool TWI_Write(uint8_t data) {
    TWDR = data;
    TWCR = (1 << TWINT) | (1 << TWEN);
    while (!(TWCR & (1 << TWINT)));

    return (TWSR & 0xF8) == TW_MT_DATA_ACK;
}

// TWI (I2C) read byte
uint8_t TWI_Read(bool ack) {
    TWCR = (1 << TWINT) | (1 << TWEN) | (ack << TWEA);
    while (!(TWCR & (1 << TWINT)));

    return TWDR;
}

void i2cInit(i2cHandle_t i2cHandle)
{
	TWI_Init();
}

void i2cWrite(uint8_t data,uint8_t regAddress)
{
	    TWI_Start();

        // Write slave address with write bit
        TWI_Write((TWI_SLAVE_ADDRESS << 1) | 0);

        // Write data byte
        TWI_Write(0x42);

        // Stop TWI (I2C) communication
        TWI_Stop();
}

uint8_t i2cRead(uint8_t regAddress)
{
	return TWI_Read((bool)1);
}
