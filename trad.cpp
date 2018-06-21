//////////////////////////////////////////////////////////////
// Trad_Esp                                                 //
// Libreria de traduccion de funciones basicas de Arduino.  //
// Enero 2017.                                              //
// Marcos Gimenez y Pablo (Malo) Alonso                     //
// Version Base 2.0                                         //
//////////////////////////////////////////////////////////////


#include "trad.h"

////////////////////////////////////////////
// METODOS Y FUNCIONES DEL NUCLEO ARDUINO //
////////////////////////////////////////////


//digitalWrite
void escribirDigital(int pin, int mode)
{
    digitalWrite(pin, mode);

}

//delay
void espera(int tiempo)
{
    delay(tiempo);
}

//pinMode
void modoPin(int pin, int mode)
{
    if (mode == 1) //1  = OUTPUT
    {
        mode == OUTPUT;
    } else if (mode == 0) // 0 = INPUT
    {
        mode == INPUT;
    }

    pinMode(pin, mode);
}

//digitalRead
int leerDigital(int pin)
{
    int val = digitalRead(pin);
    return val;
}

//analogRead
int leerAnalogico(int pin)
{
    int val = analogRead(pin);
    return val;
}

//analogWrite
void escribirAnalogico(int pin, int valor)
{
    analogWrite(pin, valor);
}

//Serial.begin
void iniciarSerial(int vel)
{
    Serial.begin(vel);
}

//tone
void tono(int pin, int freq, int dur){
    tone(pin, freq, dur);
}

//noTone
void noTone(int pin){
    noTone(pin);
}

//////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////
// METODOS AGREGADOS PARA SHIELDS Y COMPONENTES ESPECIFICOS//
/////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////


//---------------------------------------------------------//


// METODO PARA LEER LOS VALORES DEL ACELEROMETRO Y GIROSCOPIO - METODO PUBLICO
int leerAccelGiro(char valor)
{
	// ::: accelerometer and gyroscope :::

	// Read accelerometer and gyroscope
	uint8_t Buf[14];
	I2Cread(MPU9250_ADDRESS,0x3B,14,Buf);

	// Create 16 bits values from 8 bits data
	/*
		// Accelerometer
		int16_t ax=-(Buf[0]<<8 | Buf[1]);
		int16_t ay=-(Buf[2]<<8 | Buf[3]);
		int16_t az=Buf[4]<<8 | Buf[5];

		// Gyroscope
		int16_t gx=-(Buf[8]<<8 | Buf[9]);
		int16_t gy=-(Buf[10]<<8 | Buf[11]);
		int16_t gz=Buf[12]<<8 | Buf[13];
	*/

	// Accelerometer
	if (valor ==1)
	{
		return -(Buf[0]<<8 | Buf[1]);
	}
	if (valor ==2)
	{
		return -(Buf[2]<<8 | Buf[3]);
	}
	if (valor ==3)
	{
		return Buf[4]<<8 | Buf[5];
	}

	// Gyroscope
	if (valor ==4)
	{
		return -(Buf[8]<<8 | Buf[9]);
	}
	if (valor ==5)
	{
		return -(Buf[10]<<8 | Buf[11]);
	}
	if (valor ==6)
	{
		return Buf[12]<<8 | Buf[13];
	}

}



//{///////////////////////////////////////7 SEGMENTOS////////////////////////////////////////////////
void print7S(byte addres, String toSend)
{
  Wire.beginTransmission(addres);
  for (int i = 0; i < 4; i++)
  {
    Wire.write(toSend[i]);
  }
  Wire.endTransmission();
}

void clear7S(byte addres)
{
  Wire.beginTransmission(addres);
  Wire.write(0x76);  // Clear display command
  Wire.endTransmission();
}

// Set the displays brightness. Should receive byte with the value
//  to set the brightness to
//  dimmest------------->brightest
//     0--------127--------255
void brillo7S(byte addres, byte value)
{
  Wire.beginTransmission(addres);
  Wire.write(0x7A);  // Set brightness command byte
  Wire.write(value);  // brightness data byte
  Wire.endTransmission();
}

// Turn on any, none, or all of the decimals.
//  The six lowest bits in the decimals parameter sets a decimal
//  (or colon, or apostrophe) on or off. A 1 indicates on, 0 off.
//  [MSB] (X)(X)(Apos)(Colon)(Digit 4)(Digit 3)(Digit2)(Digit1)
void coma7S(byte addres, byte decimals)
{
  Wire.beginTransmission(addres);
  Wire.write(0x77);
  Wire.write(decimals);
  Wire.endTransmission();
}

void testS7S(byte addres)
{
  Wire.beginTransmission(addres);
  Wire.write(0x76);  // Clear the display
  delay(1000);
  Wire.write('t');
  Wire.write('e');
  Wire.write('s');
  Wire.write('t');
  Wire.endTransmission();
}

void convertirD27S(char *tempString, int counter)
{
	sprintf(tempString, "%4d", counter);
}


void setADDR(byte addrOld, byte addrNew)////////ESTO ES PARA CONFIGURAR EL DISPLAY PERO SE DEBE HACER CON HARDWARE SERIAL
{
  int baudRates[12] = {2400, 4800, 9600, 14400, 19200, 38400,
                       57600, 76800, 115200, 250000, 500000, 1000000
                      };
  for (int i = 0; i < 12; i++)
  {
    Serial.begin(baudRates[i]);  // Set new baud rate
    delay(10);  // Arduino needs a moment to setup serial
    Serial.write(0x80);  // I2C Address Config command
    Serial.write(addrNew);  // Set 7-bit address to 0x42
  }
  addrOld = addrNew;
  Serial.begin(9600);
  delay(10);  // Arduino needs a moment to setup serial
  Serial.write(0x76);  // Clear the display
  delay(10);
  Serial.write('t');
  delay(10);
  Serial.write('e');
  delay(10);
  Serial.write('s');
  delay(10);
  Serial.write('t');
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void factoryRST()////////ESTO ES PARA CONFIGURAR EL DISPLAY PERO SE DEBE HACER CON HARDWARE SERIAL
{
  int baudRates[12] = {2400, 4800, 9600, 14400, 19200, 38400,
                       57600, 76800, 115200, 250000, 500000, 1000000
                      };
  for (int i = 0; i < 12; i++)
  {
    Serial.begin(baudRates[i]);  // Set new baud rate
    delay(10);  // Arduino needs a moment to setup serial
    Serial.write(0x81);  // Send factory reset command
  }

  Serial.begin(9600);
  delay(10);  // Arduino needs a moment to setup serial
  Serial.write(0x76);  // Clear the display
  Serial.write('t');
  delay(10);
  Serial.write('e');
  delay(10);
  Serial.write('s');
  delay(10);
  Serial.write('t');
}

//////////////////////////////////////////////////////////////////////////////////////////////////}

//{/////////////////////////////////SENSOR DISTANCIA ULTRASONIDO/////////////////////////////////////
long sensorDistancia(int trig,int echo)
{
	long distancia;
	long tiempo;

	digitalWrite(trig,LOW); // Por cuestión de estabilización del sensor
	delayMicroseconds(5);
	digitalWrite(trig, HIGH); // envío del pulso ultrasónico
	delayMicroseconds(10);

	// Función para medir la longitud del pulso entrante. Mide el tiempo que transcurrido entre el envío
	// del pulso ultrasónico y cuando el sensor recibe el rebote, es decir: desde que el pin 12 empieza
	// a recibir el rebote, HIGH, hasta que deja de hacerlo, LOW, la longitud del pulso entrante
	tiempo=pulseIn(echo, HIGH);

	distancia= int(0.017*tiempo); /*fórmula para calcular la distancia obteniendo un valor entero*/

	return distancia;
}
////////////////////////////////////////FIN SENSOR DISTANCIA ULTRASONIDO//////////////////////////////////}
