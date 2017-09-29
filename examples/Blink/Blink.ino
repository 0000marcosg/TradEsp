/*
 * Clasico ejemplo Blink de Arduino.
 * 
 * Marcos Gimenez.
 * 
  */

#include <trad.h>

void setup() {
  //Definimos el pin numero 13 como SALIDA
  modoPin(13, SALIDA);

}

void loop() {
  //Escribimos el valor digital de ENCENDER en el pin numero 13
  escribirDigital(13, ENCENDER);
  //Esperamos 1000 milisegundos
  espera(1000);
  
  //Apagamos el led 13 y volvemos a esperar.
  escribirDigital(13, APAGAR);
  espera(1000);

}
