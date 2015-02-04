#include "Racional.h"
#include "conio.h"

int main()
{
	int numerador = 0;//numerador de un racional que se introducirá por teclado
	int denominador = 0;//denominador de un racional que se introducirá por teclado

	//introducir y mostrar el Racional a
	do
	{
		cout << "Introduzca numerador y denominador (separado por espacios) del racional a." << endl << "El denominador debe ser distinto de cero: ";
		cin >> numerador >> denominador;
	} 
	while (denominador == 0);
	Racional racionalA(numerador, denominador);
	cout << "Racional a:  ";
	racionalA.escribirRacional();
	
	//Introducir y mostrar el Racional b
	do
	{
		cout << "Introduzca numerador y denominador (separado por espacios) del racional b." << endl << "El denominador debe ser distinto de cero: ";
		cin >> numerador >> denominador;
	} 
	while (denominador == 0);
	Racional racionalB(numerador, denominador);
	cout << "racional b: ";
	racionalB.escribirRacional();

	//sumar los dos racionales y mostrarlos por pantalla
	Racional racionalSuma = racionalA.sumarRacionales(racionalB);
	cout << "Racional a+b: ";
	racionalSuma.escribirRacional();

	//multiplicar los dos racionales y mostrarlo por pantalla
	Racional racionalMultiplicacion = racionalA.multiplicarRacionales(racionalB);
	cout << "Racional a*b: ";
	racionalMultiplicacion.escribirRacional();

	cout << getch();
}