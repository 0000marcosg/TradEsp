//////////////////////////////////////////////////////////////
// Trad_Esp                                                 // 
// Libreria de traduccion de funciones basicas de Arduino.  //
// Enero 2017.                                              // 
// Marcos Gimenez.                                          //
// Version Base 2.0                                         //
////////////////////////////////////////////////////////////// 


#include "trad.h"

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

