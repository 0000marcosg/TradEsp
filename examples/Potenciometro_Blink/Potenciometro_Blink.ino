#include <trad.h>

//Definimos una variable de tipo entero
entero valor;

void setup() {
  //Definimos el pin 13 como SALIDA
  modoPin(13, SALIDA);
  //Iniciamos la comunicacion Serial
  iniciarSerial(9600);

}

void loop() {
  //Encendemos el pin 13, esperamos, apagamos el pin 13 y volvemos a esperar.
  escribirDigital(13, ENCENDER);
  espera(valor);
  escribirDigital(13, APAGAR);
  espera(valor);

  //El valor de espera corresponde al valor extraido del potenciometro en un rango de 0 a 1024
  valor = leerAnalogico(0);

  //La funcion imprimirSerial requiere dos parametros: El primero un string (cadena de texto) que representa una etiqueta.
  //El segundo, el valor a imprimir.
  imprimirSerial("potenciometro: ", valor);
}
