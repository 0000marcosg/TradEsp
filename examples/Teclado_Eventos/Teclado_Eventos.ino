/*

                                      +-----+
         +----[PWR]-------------------| USB |--+
         |                            +-----+  |
         |         GND/RST2  [ ][ ]            |
         |       MOSI2/SCK2  [ ][ ]  A5/SCL[ ] |   .
         |          5V/MISO2 [ ][ ]  A4/SDA[ ] |   .
         |                             AREF[ ] |
         |                              GND[ ] |
         | [ ]N/C                    SCK/13[ ] |   .
         | [ ]IOREF                 MISO/12[ ] |   .
         | [ ]RST                   MOSI/11[ ]~|   .
         | [ ]3V3    +---+               10[ ]~|   .
         | [ ]5v    -| A |-               9[ ]~|   .
         | [ ]GND   -| R |-               8[ ] |   7#
         | [ ]GND   -| D |-                    |
         | [ ]Vin   -| U |-               7[ ] |   6
         |          -| I |-               6[ ]~|   5
         | [ ]A0    -| N |-               5[ ]~|   4
         | [ ]A1    -| O |-               4[ ] |   3
         | [ ]A2     +---+           INT1/3[ ]~|   2
         | [ ]A3                     INT0/2[ ] |   1*
         | [ ]A4/SDA  RST SCK MISO     TX>1[ ] |   .
         | [ ]A5/SCL  [ ] [ ] [ ]      RX<0[ ] |   .
         |            [ ] [ ] [ ]              |
         |  UNO_R3    GND MOSI 5V  ____________/
          \_______________________/

		  http://busyducks.com/ascii-art-arduinos

      */

#include <Keypad.h>
#include <trad.h>

constante byte FILA = 4; //four rows
constante byte COLUMNA = 3; //three columns
caracter teclas[FILA][COLUMNA] = {
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'},
    {'*','0','#'}
};

byte filaPins[FILA] = {2, 3, 4, 5}; //connect to the row pinouts of the keypad
byte colPins[COLUMNA] = {6, 7, 8}; //connect to the column pinouts of the keypad

Keypad miTeclado = Keypad( configTeclas(teclas), filaPins, colPins, FILA, COLUMNA);

void setup(){
    iniciarSerial(9600);           // Turn the LED on.
    keypad.dispararEvento(eventoPropio); // Add an event listener for this keypad
}

void loop(){
    caracter tecla = miTeclado.teclaPresionada();
}

// Taking care of some special events.
void eventoPropio(EventoKey tecla){
    cambio (miTeclado.estado()){
    caso PRESIONADA:
        Si (tecla == '#') {
          imprimirSerial("Tecla presionada", tecla);
        }
        salir;

    caso SUELTA:
        Si (tecla == '#') {
          imprimirSerial("Tecla suelta", tecla);
        }
        salir;

    caso PRESIONANDO:
        Si (tecla == '#') {
          imprimirSerial("Tecla presionando", tecla);
        }
        salir;
    }
}
