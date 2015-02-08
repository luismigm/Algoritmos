// ejercicio1-2: programa que hace algunas operaciones con fracciones
#include "iostream"
#include "Racional.h"
#include "conio.h"

using namespace std;

/* Método donde sobrecargamos el operador del flujo de salida << para mostrar por pantalla 
el objeto racional. Si el número es entero o 0 lo mostramos de forma entera
Parámetros:
	salida: referencia del flujo de salida
	racional: el número racional que se pretende escribir por pantalla
Retorno: flujo de salida*/
ostream& operator << (ostream &salida, Racional racional);


void main()
{
	// Variables para guardar numerador y denominador que capturamos por teclado
	int numerador, denominador;

	// Variable para guardar el resultado de las sucesivas operaciones
	Racional resultado(1, 1); // Inicializado a 1,1 sin ningun motivo especial

	// Pedimos y creamos el primer racional
	do {
		cout << "Introduzca numerador y denominador (separado por espacios) del racional a.\nEl denominador debe ser distinto de cero: ";
		cin >> numerador;
		cin >> denominador;
	} while (denominador == 0);
	Racional a(numerador, denominador);
	cout << "Racional a: ";
	cout << a;
	a.simplificar();
	cout << " (simplificado : ";
	cout << a;
	cout << " )";
	cout << endl;

	cout << getch();

}

ostream& operator << (ostream &salida, Racional racional) 
{
	if (racional.getNumerador() == 0 || racional.getDenominador() == 1)
	{
		salida << racional.getNumerador();
	}
	else 
	{
		salida << racional.getNumerador() << "/" << racional.getDenominador();
	}
	return salida;
}
