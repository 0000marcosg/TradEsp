//////////////////////////////////////////////////////////////
// Trad_Esp                                                 // 
// Libreria de traduccion de funciones basicas de Arduino.  //
// Enero 2017.                                              // 
// Marcos Gimenez y Pablo (Malo) Alonso                     //
// Version Base 2.0                                         //
////////////////////////////////////////////////////////////// 


#ifndef ARD_ESP_H
#define ARD_ESP_H

#include <Arduino.h>
#include <Wire.h> //SDA: A4 y SCL: A5


//Constantes
#define ENCENDER 1
#define APAGAR 0
#define ENTRADA 0
#define SALIDA 1

#define entero int
#define flotante float
#define Cadena String
#define booleana boolean

#define verdadero true
#define falso false

#define Si if
#define SiNo else
#define Mientras while
#define Para for

//{Constantes para Giroscopio
#define MPU9250_ADDRESS 0x68
#define MAG_ADDRESS 0x0C
 
#define GYRO_FULL_SCALE_250_DPS 0x00 
#define GYRO_FULL_SCALE_500_DPS 0x08
#define GYRO_FULL_SCALE_1000_DPS 0x10
#define GYRO_FULL_SCALE_2000_DPS 0x18
 
#define ACC_FULL_SCALE_2_G 0x00 
#define ACC_FULL_SCALE_4_G 0x08
#define ACC_FULL_SCALE_8_G 0x10
#define ACC_FULL_SCALE_16_G 0x18


//}Hasta aca giroscopio


//digitalRead
int leerDigital(int pin);

//analogRead
int leerAnalogico(int pin);

//analogWrite
void escribirAnalogico(int pin, int valor);

//digitalWrite
void escribirDigital(int pin, int mode); 

//pinModo
void modoPin(int pin, int mode);

//Serial.begin
void iniciarSerial(int vel);

//delay
void espera(int tiempo);

// Serial
  template<typename T>
  void imprimirSerial(char *definicion, T valor){
    if (log){
      Serial.print(definicion);
      Serial.print(": ");
      Serial.println(valor); 
    }
  }
  
//Sensor distancia ultrasonido
long sensorDistancia(int trig, int echo);
  
//Giroscopio y acelerometro
int leerAccelGiro(char valor);
//Estas funciones son internas para el uso del giroscopio, no tiene sentido traducirlas (metodos privados?)
void I2Cread(uint8_t Address, uint8_t Register, uint8_t Nbytes, uint8_t* Data);
void I2CwriteByte(uint8_t Address, uint8_t Register, uint8_t Data);
void configAccelGiro();


//7-SEGMENTOS
void print7S(byte addres, String toSend);
void clear7S(byte addres);
void brillo7S(byte addres, byte value);
void coma7S(byte addres, byte decimals);
void testS7S(byte addres);
void convertirD27S(char *tempString, int counter);
//Para el uso de estas funciones se debe conectar el 7S al pin RX (0) del arduino.
void setADDR(byte addrOld, byte addrNew);
void factoryRST();
  
/*                              LUGARES PANTALLA SPARKFUN
	position	 1	 2	 3	 4	 5	 6	 7	 8	 9	10	11	12	13	14	15	16
	line 1		128	129	130	131	132	133	134	135	136	137	138	139	140	141	142	143
	line 2		192	193	194	195	196	197	198	199	200	201	202	203	204	205	206	207
*/
#endif