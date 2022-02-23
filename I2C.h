#ifndef I2C_h
#define I2C_h

/*
#ifdef __AVR__
#include <avr/pgmspace.h>
#endif
#if (ARDUINO >= 100)
#include "Arduino.h"
#endif
*/

#include <Arduino.h>
#include <Wire.h>

class I2C {
    private:
        uint8_t _address;
    public:
        I2C();

        // Pseudo Constructor
        void new_I2C(uint8_t address);

        uint8_t readByte(uint8_t reg);
        void writeByte(uint8_t reg, uint8_t data);
        void readByteStream(uint8_t reg, uint8_t numBytes, uint8_t* dataArray);
        void writeByteStream(uint8_t reg, uint16_t len, uint8_t* data);
        void maskedWriteByte(uint8_t reg, uint8_t mask,  uint8_t data);
    };
#endif /* I2C_h */
