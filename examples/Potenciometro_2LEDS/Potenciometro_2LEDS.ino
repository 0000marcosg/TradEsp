/*
Ejemplo para encender un LED u otro dependiendo del valor del potenciometro.

Marcos Gimenez.
*/


#include <trad.h>

//Se define una variable de tipo entero
entero valor;

void setup() {
  //Se definen los pines como SALIDA
  modoPin(9, SALIDA);
  modoPin(10, SALIDA);

  //Se prepara la comunicacion SERIAL
  iniciarSerial(9600);

}

void loop() {

  //Leemos el valor del potenciometro y lo imprimimos en el monitor.
  //La funcion imprimirSerial requiere dos parametros, el primero es un string que 
  //funciona como etiqueta y el segundo el valor a imprimir 
  valor = leerAnalogico(0);
  imprimirSerial("potenciometro: ", valor);
  
  //Si el valor es menor a 500
  Si(valor < 500) {
    escribirDigital(9, ENCENDER);
    escribirDigital(10, APAGAR);
  } 
  //Si el valor no es mayor a 500
  SiNo {
    escribirDigital(9, APAGAR);
    escribirDigital(10, ENCENDER);
  }
}
