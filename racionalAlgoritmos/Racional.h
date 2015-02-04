#pragma once
#include "assert.h" 
#include "iostream"

using namespace std;

class Racional
{
	protected:
		int numerador;//numerador del racional
		int denominador;//denominador del racional

	public:
		//Constructor por defecto, crea un Racional con numerador y denominador 1
		Racional();

		//Constructor donde se introduce el numerador y denominador por par�metro
		//Precondici�n: denominador no puede ser cero
		//Par�metros:
		//	int numerador, el numerador del racional
		//	int denominador, el denominador del racional
		Racional(int numerador, int denominador);

		//Destructor
		~Racional();

		//Devuelve numerador
		int getNumerador();

		//Devuelve denominador
		int getDenominador();

		//Suma un racional al objeto
		//Par�metro: Racional sumando2, el racional a sumar;
		//Devuelve un nuevo objeto Racional con el resultado de la suma
		Racional sumarRacionales(Racional sumando2);

		//multiplica un racional al objeto
		//Par�metro: Racional multiplicador, el racional multiplicador;
		//Devuelve un nuevo objeto Racional con el resultado de la multiplicaci�n
		Racional multiplicarRacionales(Racional multiplicador);

		void simplificar();

		//escribe por pantalla el racional
		void escribirRacional();

};
