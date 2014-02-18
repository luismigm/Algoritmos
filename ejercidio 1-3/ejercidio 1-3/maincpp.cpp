#include <iostream> //entrada, salida
#include <stdlib.h> //métodos random
#include <time.h> //para usar la hora

using namespace std;

void main()
{
	int tamano = 0;//en esta variable pondremos el tamaño del array
	/*el usuario introduce el tamaño del array*/
	do
	{
		cout << "Introduce el tamano del vector (numero mayor o igual que 1): ";
		cin >> tamano;
		cout << endl;
	}while (tamano == 0);
	
	int *arrayEnteros = (int *) malloc (tamano*sizeof(int));//creamos el array

	srand (time(NULL)); //generamos la semilla para los números aleatorios

	/*rellenamos el array con números aleatorios*/
	for(int i = 0; i < tamano; i++)
	{
		arrayEnteros[i]=rand();
	}

	/*mostramos el array*/
	cout << endl << "el vector original es el siguiente: " << endl;
	for(int i = 0; i < tamano; i++)
	{
		cout << arrayEnteros[i] << " ";
	}
	cout << endl;
	free (arrayEnteros);
}