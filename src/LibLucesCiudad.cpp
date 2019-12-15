/*
  LibLucesCiudad.cpp - Libreria para el manejo de la 
  estacion de las luces de la ciudad.
  Javier Sankowicz.
*/

#include "Arduino.h"
#include "LibLucesCiudad.h"

/* ************ Funciones de la clase Luz Piso ************ */

LuzCiudad::LuzCiudad(int pin)
{
	pinMode(pin,OUTPUT);
	_pin = pin;
	digitalWrite(_pin,LOW);
}

void LuzCiudad::encender()
{
	digitalWrite(_pin,HIGH);
}

void LuzCiudad::apagar()
{
	digitalWrite(_pin,LOW);
}

/* ********************************************************** */


/* ************ Funciones de la clase Sensor ************ */

Sensor::Sensor(int pin)
{
	pinMode(pin,INPUT);
	_pin=pin;
}

int Sensor::leer()
{
	return(digitalRead(_pin));
}

void Sensor::esperar(int estado)
{
	while(leer()!=estado);
} 

/* ********************************************************** */

/* ************ Funciones de la clase Pulsador ************** */

Pulsador::Pulsador(int pin)
{
	pinMode(pin,INPUT);
	_pin=pin;
}

int Pulsador::leer()
{
	return(digitalRead(_pin));
}

void Pulsador::esperar(int estado)
{
	while(leer()!=estado);
}

/* ********************************************************* */

/* ************Ingresar numero por puerto serie************** */

int ingresar_numero()   //devuelve un entero que va de -32768 a 32767
{
  String readString;
  
  while(!(Serial.available()>0));

  while(Serial.available()>0)
  {
    char c = Serial.read();
    readString += c;
    delay(2);
  }

  int number = readString.toInt();

  return number;
}

/* ********************************************************* */

/* ************Funciones imprimir texto********************* */

void mostrar_cartel(String text)
{
	Serial.print(text);
	Serial.print(" ");
}

void mostrar_numero(int num)
{
	Serial.println(num);
}

/* ********************************************************* */

/* *****************Inicializacion************************** */
void inicializar_sistema()
{
	Serial.begin(9600);
	
}
/* ********************************************************* */

/* ******************Finalizacion*************************** */
void finalizar()
{
	while(1);
}
/* ********************************************************* */

//Variables para manejo de sensores y pulsadores
int estado_sensor_luz=DIA;
int estado_pulsador=NO_PRESIONADO;
int numero_ingresado=0;

//Variable para contador
int contador=0;

//Variables elementos del sistema
LuzCiudad luz1(pin_luz1);
LuzCiudad luz2(pin_luz2);
LuzCiudad luz3(pin_luz3);
LuzCiudad luz4(pin_luz4);
LuzCiudad luz5(pin_luz5);
LuzCiudad luz6(pin_luz6);
LuzCiudad luz7(pin_luz7);
LuzCiudad luz8(pin_luz8);
LuzCiudad luz9(pin_luz9);
LuzCiudad luz10(pin_luz10);

Sensor sensor_luz(pin_sensor_ldr);

Pulsador pulsador(pin_pulsador);
