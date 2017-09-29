//////////////////////////////////////////////////////////////
// Trad_Esp                                                 // 
// Libreria de traduccion de funciones basicas de Arduino.  //
// Enero 2017.                                              // 
// Marcos Gimenez.                                          //
// Version Base 2.0                                         //
////////////////////////////////////////////////////////////// 


#ifndef ARD_ESP_H
#define ARD_ESP_H

#include <Arduino.h>


//Constantes
#define ENCENDER 1
#define APAGAR 0
#define ENTRADA 0
#define SALIDA 1

#define entero int
#define flotante float
#define cadena String
#define booleana boolean

#define verdadero true
#define falso false

#define Si if
#define SiNo else 



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
  
#endif
