//////////////////////////////////////////////////////////////
// Trad_Esp                                                 //
// Libreria de traduccion de funciones basicas de Arduino.  //
// Enero 2017.                                              //
// Marcos Gimenez y Pablo (Malo) Alonso                     //
// Version Base 2.0                                         //
//////////////////////////////////////////////////////////////


#include "trad.h"

/////////////////////////////////////////////////////////////
// METODOS PRIVADOS PARA EL FUNCIONAMIENTO DEL GIROSCOPIO //
////////////////////////////////////////////////////////////

void I2Cread(uint8_t Address, uint8_t Register, uint8_t Nbytes, uint8_t* Data)
{
	// Set register address
	Wire.beginTransmission(Address);
	Wire.write(Register);
	Wire.endTransmission();

	// Read Nbytes
	Wire.requestFrom(Address, Nbytes);
	uint8_t index=0;
	while (Wire.available())
	Data[index++]=Wire.read();
}

void I2CwriteByte(uint8_t Address, uint8_t Register, uint8_t Data)
{
	// Set register address
	Wire.beginTransmission(Address);
	Wire.write(Register);
	Wire.write(Data);
	Wire.endTransmission();
}

void configAccelGiro()
{

	// CONFIGURACION DE LAS CONSTANTES Y FUNCIONES//
	Wire.begin();
	// Set accelerometers low pass filter at 5Hz
	I2CwriteByte(MPU9250_ADDRESS,29,0x06);
	// Set gyroscope low pass filter at 5Hz
	I2CwriteByte(MPU9250_ADDRESS,26,0x06);
	// Configure gyroscope range
	I2CwriteByte(MPU9250_ADDRESS,27,GYRO_FULL_SCALE_1000_DPS);
	// Configure accelerometers range
	I2CwriteByte(MPU9250_ADDRESS,28,ACC_FULL_SCALE_4_G);
	// Set by pass mode for the magnetometers
	I2CwriteByte(MPU9250_ADDRESS,0x37,0x02);

	 /*
	// Request continuous magnetometer measurements in 16 bits
	 I2CwriteByte(MAG_ADDRESS,0x0A,0x16);
	 pinMode(13, OUTPUT);
	 Timer1.initialize(10000); // initialize timer1, and set a 1/2 second period
	 Timer1.attachInterrupt(callback); // attaches callback() as a timer overflow interrupt
  */
}
