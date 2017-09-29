/*
 * Se maneja el brillo de dos leds con un potenciometro y se encienden o no dependiendo del valor de un sensor de luz.
 * 
 * Marcos Gimenez.
*/
#include <trad.h>

//Definimos las variables como entero.
entero valor_pote;
entero valor_luz;

void setup() {
  
  //Se definen los pines como SALIDA
  modoPin(9, SALIDA);
  modoPin(10, SALIDA);

  //Se inicia la comunicacion Serial.
  iniciarSerial(9600);

}

void loop() {

  //Igualamos las variables a los valores analogicos que leemos del pin A0 y A1
  valor_pote = leerAnalogico(0);
  valor_luz = leerAnalogico(1);

  //Se imprime el valor en la consola.
  imprimirSerial("potenciometro: ", valor_pote);
  imprimirSerial("sensor de luz: ", valor_luz);

  
  Si(valor_luz < 200) {

    //Escribimos el valor del potenciometro escalado para que se ajuste al rango de valores analogicos del led.
    escribirAnalogico(9, valor_pote/4);
    escribirAnalogico(10, 0);
    espera(valor_pote);
    
    escribirAnalogico(10, valor_pote/4);
    escribirAnalogico(9, 0);
    espera(valor_pote);
    
  }
  
  SiNo {
    escribirDigital(9, APAGAR);
    escribirDigital(10, APAGAR);

  }
  

  
}
