#include "VectorEnteros.h"
#include "cstdlib" //funciones free, malloc
#include "cstring" //funciones memcopy
#include "cassert" //asserts

using namespace std;
VectorEnteros::VectorEnteros(int longitudVector)
{
	assert (longitudVector > 0);
	// asignamos la longitud del vector
	this->longitudVector = longitudVector;

	//asignamos memoria
	vectorEnteros = (int*) malloc (longitudVector * sizeof(int));

	//rellenamos con números aleatorios
	for (int i = 0; i < longitudVector; i++)
	{
		vectorEnteros[i]= rand();
	}
}

VectorEnteros::VectorEnteros(VectorEnteros &original) {

	// Introducimos longitud
	longitudVector = original.longitudVector;

	// reservamos la memoria 
	vectorEnteros = (int*) malloc (longitudVector*sizeof(int));

	// Copiamos el vector original al nuevo
	memcpy (vectorEnteros, original.vectorEnteros, longitudVector*sizeof(int));
}

VectorEnteros::~VectorEnteros()
{
	// destruimos la memoria asignada
	free(vectorEnteros);
}

int VectorEnteros::getLongitudVector()
{
	return longitudVector;
}

int * VectorEnteros::getVectorEnteros()
{
	return vectorEnteros;
}

void VectorEnteros::ordenarSeleccion()
{
	for (int i=0; i<longitudVector-1; i++) 
	{
		int minimo = vectorEnteros[i];//
		int posicionMinimo = i;
		//Buscamos él número mínimo
		for (int k=i+1; k<longitudVector; k++)
		{
			if(vectorEnteros[k] < minimo)
			{
				posicionMinimo = k;
				minimo = vectorEnteros[k];
			}
		}
		//colocamos el mínimo y asignamos lo que allí había en la posición donde estaba ese entero
			int temp = vectorEnteros[i];
			vectorEnteros[i] = minimo;
			vectorEnteros[posicionMinimo] = temp;
	}
}



