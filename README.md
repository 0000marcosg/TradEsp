# TradEsp
#### Libreria de de traduccion basica para Arduino.

Esta libreria fue pensada para facilitar el uso del lenguaje Arduino en cursos de programacion orientados a estudiantes no familiarizados con el idioma ingles y los conceptos basicos de programacion.

>*TradEsp fue pensada para un uso exclusivamente pedagogico,* por esa razon la libreria no respeta algunas reglas establecidas por la comunidad Arduino para la creacion de librerias.



# Referencia
#### Funciones Soportadas

Retorna | Funcion | Equivalente
------- | ------- | -----------
|`void`| `escribirDigital()`|  `digitalWrite()` |
|`void`| `espera()`     | `delay()`  
| `void`| `modoPin()` |  `pinMode()` |
|`int`| `leerDigital()`| `digitalRead()`|
| `int`| `leerAnalogico()` | `analogRead()`|
| `void`| `escribirAnalogico()` | `analogWrite()`|
| `void`| `iniciarSerial()`| `Serial.begin()`|
| `void`| `imprimirSerial()`|`Serial.print()`|
| `void`| `tono()`|`tone()`|
| `void`| `noTono()`|`noTone()`|

#### Tipos de Datos y Constantes

##### Tipos de Datos
Tipo | Nombre en TradEsp
------- | -------
`int` | `entero`
`float` | `flotante`
`String` | `cadena`
`boolean` | `booleana`

##### Constantes
Nombre Original | Nombre en TradEsp
------- | -------
`HIGH` | `ENCENDER`
`LOW` | `APAGAR`
`INPUT` | `ENTRADA`
`OUTPUT` | `SALIDA`
`true` | `verdadero`
`false` | `falso`

##### Flujo de Datos
Nombre Original | Nombre en TradEsp
------- | -------
`if` | `Si`
`else` | `SiNo`

# Querido Blink
```Arduino
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
```
