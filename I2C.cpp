#include "I2C.h"

//************************Constructors************************//
I2C::I2C(){}

// Pseudo Constructor
void I2C::new_I2C(uint8_t address){
    this->_address = address;
} // End Constructor

//************************Public************************//

uint8_t I2C::readByte(uint8_t reg){
    uint8_t b;
    
    Wire.beginTransmission(_address);
    Wire.write(reg);
    Wire.endTransmission(false);
    Wire.requestFrom(_address, 1);
    b = Wire.read();
    Wire.endTransmission();
    delay(1);
    return b;
} // End-readByte

void I2C::writeByte(uint8_t reg, uint8_t data){
    Wire.beginTransmission(_address);
    Wire.write(reg);
    Wire.write(data);
    Wire.endTransmission();
    delay(1);
} // End-writeByte

void I2C::readByteStream(uint8_t reg, uint8_t numBytes, uint8_t* dataArray){
    Wire.beginTransmission(_address);
    Wire.write(reg);
    Wire.endTransmission(false);

    Wire.requestFrom(_address, numBytes);
    for (uint8_t i = 0; i < numBytes; i++){
        dataArray[i] = Wire.read();
    } // End-For

    Wire.endTransmission();
    delay(1);
} // End-read

void I2C::writeByteStream(uint8_t reg, uint16_t len, uint8_t* data){
    Wire.beginTransmission(_address);
    Wire.write(reg);

    for (uint8_t i = 0; i < len; i++){
        Wire.write(data[i]);
    } // End-For

    Wire.endTransmission();
    delay(1);
} // End-write

void I2C::maskedWriteByte(uint8_t reg, uint8_t mask,  uint8_t data){
    uint8_t original = I2C::readByte(reg);
    original &= mask; // Zero out bits to be written to
    original |= data; // Update desired bits
    writeByte(reg, original);
} // End-maskedWriteByte
