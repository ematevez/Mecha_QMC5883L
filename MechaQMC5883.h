#ifndef Mecha_QMC5883
#define Mecha_QMC5883

#include "Arduino.h"
#include "Wire.h"

#define QMC5883_ADDR 0x0D


//REG CONTROL

//0x09

#define Mode_Standby    0b00000000
#define Mode_Continuous 0b01000000

#define ODR_10Hz        0b00000000
#define ODR_50Hz        0b00010000
#define ODR_100Hz       0b00100000
#define ODR_200Hz       0b00110000

#define RNG_2G          0b00000000
#define RNG_8G          0b00000100

#define OSR_512         0b00000000
#define OSR_256         0b00000001
#define OSR_128         0b00000010
#define OSR_64          0b00000011


class MechaQMC5883{
public:


void setAddress(uint8_t addr);

void init(); //init qmc5883

void setMode(uint16_t mode,uint16_t odr,uint16_t rng,uint16_t osr); // setting

void softReset(); //soft RESET

void read(uint16_t* x,uint16_t* y,uint16_t* z); //reading

private:

void WriteReg(uint8_t Reg,uint8_t val);

uint8_t address = QMC5883_ADDR;

};



#endif
