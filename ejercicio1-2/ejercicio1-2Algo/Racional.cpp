#include "Racional.h"
#include "iostream" // Para utilizar "cout"
#include "cassert" // Para utilizar la macro "assert()"
#include "cmath"
using namespace std;


Racional::Racional(int numerador, int denominador) {
	assert(denominador != 0); // Denominador distinto de cero

	// Calculamos el signo de la fracci�n y lo ponemos en el numerador
	// Por lo tanto hacemos que el denominador siempre sea positivo
	if (denominador < 0) {
		denominador = -denominador;
		numerador = -numerador;
	}

	// Guardamos el numerador y el denominador en el objeto actual
	this->numerador = numerador;
	this->denominador = denominador;
}

Racional Racional::sumar(Racional sumando) {
	// Los denominadores no pueden ser 0 ni negativos
	assert(sumando.denominador > 0);
	assert(denominador > 0);

	// Sumamos dos fracciones: la del objeto actual (this) y la pasada como par�metro
	// Para simplificar, las llamaremos numerador1/denominador1 y numerador2/denominador2
	int numerador1 = numerador;
	int denominador1 = denominador;
	int numerador2 = sumando.numerador;
	int denominador2 = sumando.denominador;

	int nuevoDenominador; // Nuevo denominador de la fraccion resultante
	int nuevoNumerador;   // Nuevo numerador de la fracci�n resultante

	// El nuevo denominador com�n del resultado idealmente seria el m�nimo comun m�ltiplo, pero
	// para simplificar hacemos que sea la multiplicaci�n de ambos denominadores
	nuevoDenominador = denominador1 * denominador2;

	// A partir del nuevo denominador com�n, calculamos los nuevos numeradores de los sumandos
	numerador1 = numerador1 * denominador2;
	numerador2 = numerador2 * denominador1;

	// Calculamos el numerador del resultado
	nuevoNumerador = numerador1 + numerador2;

	// Calculamos el resultado y lo devolvemos
	Racional resultado(nuevoNumerador, nuevoDenominador);
	return (resultado);
}



Racional Racional::multiplicar(Racional multiplicador) {
	// Los denominadores tienen que ser distintos de 0
	assert(multiplicador.denominador != 0 && denominador != 0);

	int nuevoNumerador = numerador * multiplicador.numerador;
	int nuevoDenominador = denominador * multiplicador.denominador;

	Racional resultado(nuevoNumerador, nuevoDenominador);
	return (resultado);
}



int Racional::getNumerador() {
	return(numerador);
}

int Racional::getDenominador() {
	return(denominador);
}

void Racional::simplificar() {
	int mcd = 0; //mcd que aplicaremos al numerador y denominador para simplificar

	//si el numerador es 0 no hacemos nada
	if (numerador != 0)
	{
		//pasaremos el valor absoluto del numerador, tenemos definido que el denominador es positivo;
		mcd = calcularMCD(abs(numerador), denominador);

		numerador /= mcd;
		denominador /= mcd;
	}
}

void Racional::escribir() {
	if (numerador == 0 || denominador == 1) cout << getNumerador();
	else cout << numerador << "/" << getDenominador();
}

int Racional::calcularMCD(int numeroA, int numeroB)
{
	assert(numeroA >= 0);
	assert(numeroB >= 0);

	//utilizamos el algoritmo de euclides para averiguar el mcd
	while (numeroB != 0)
	{
		int resto = numeroA % numeroB;
		numeroA = numeroB;
		numeroB = resto;
	}
	return numeroA;
}

/*
int Racional::calcularMCD(int divisorA, int divisorB)
{
	if (divisorB == 0)
	{
		return divisorA;
	}
	else
	{
		calcularMCD(divisorB, divisorA%divisorB);
	}
}*/