/*
  LibLucesCiudad.h - Libreria para el manejo de la 
  estacion de las luces de la ciudad.
  Javier Sankowicz.
*/

#ifndef LibLucesCiudad_h
#define LibLucesCiudad_h

#include "Arduino.h"

#define PRESIONADO HIGH
#define NO_PRESIONADO LOW

#define NOCHE 0
#define DIA 1

#define REPETIR(X) for(int i=0;i<X;i++)

const int pin_luz1 = 2;
const int pin_luz2 = 3;
const int pin_luz3 = 4;
const int pin_luz4 = 5;
const int pin_luz5 = 6;
const int pin_luz6 = 7;
const int pin_luz7 = 8;
const int pin_luz8 = 9;
const int pin_luz9 = 12;
const int pin_luz10 = 13;

const int pin_pulsador = 11;
const int pin_sensor_ldr = 10;

extern void mostrar_cartel(String);
extern void mostrar_numero(int num);
extern int ingresar_numero();
extern void inicializar_sistema();
extern void finalizar();


//Variables para manejo de sensores y pulsadores
extern int estado_sensor_luz;
extern int estado_pulsador;
extern int numero_ingresado;

//Variable Contador
extern int contador;


class LuzCiudad {
	public:
		LuzCiudad(int pin);
		void encender();
		void apagar();
	private:
		int _pin;
};

class Sensor
{
	public:
		Sensor(int pin);
		int leer();
		void esperar(int estado);
	private:
		int _pin;
	
};

class Pulsador
{
	public:
		Pulsador(int pin);
		int leer();
		void esperar(int estado);
	private:
		int _pin;
};



//Variables elementos del sistema
extern LuzCiudad luz1;
extern LuzCiudad luz2;
extern LuzCiudad luz3;
extern LuzCiudad luz4;
extern LuzCiudad luz5;
extern LuzCiudad luz6;
extern LuzCiudad luz7;
extern LuzCiudad luz8;
extern LuzCiudad luz9;
//extern LuzCiudad luz10;

extern Sensor sensor_luz;

extern Pulsador pulsador;


#endif
