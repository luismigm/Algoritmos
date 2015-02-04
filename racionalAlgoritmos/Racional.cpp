#include "Racional.h"


Racional::Racional(int numerador, int denominador)
{

	assert(denominador != 0);
	//modificar el signo si conviene
	if (denominador < 0)
	{
		denominador *= -1;
		if (numerador != 0)
		{
			numerador *= -1;
		}
	}
	this->numerador = numerador;
	this->denominador = denominador;
}

Racional::Racional()
{
	numerador = 1;
	denominador = 1;
}

Racional::~Racional()
{
}

int Racional::getDenominador()
{
	return denominador;
}
int Racional::getNumerador()
{
	return numerador;
}

Racional Racional::sumarRacionales(Racional sumando2)
{
	int numeradorSuma = 0, denominadorSuma = 0;

	numeradorSuma = getNumerador() * sumando2.getDenominador() + sumando2.getNumerador() * getDenominador();
	denominadorSuma = getDenominador() * sumando2.getDenominador();
	Racional suma(numeradorSuma,denominadorSuma);

	return suma;
}

Racional Racional::multiplicarRacionales(Racional multiplicador)
{
	Racional multiplicacion(getNumerador() * multiplicador.getNumerador(), getDenominador() * multiplicador.getDenominador());
	return multiplicacion;
}

void Racional::simplificar()
{
}

void Racional::escribirRacional()
{
	//si el racional nos da entero mostramos solo el numerador, si el numerador es 0 mostramos el cero, si no se muestra el racional de la forma normal
	if (getDenominador() == 1)
	{
		cout << getNumerador() << endl;
	}
	else
		if (getNumerador() == 0)
		{
			cout << "0"<< endl;
		}
		else
		{
			cout << numerador << "/" << getDenominador() << endl;
		}
}