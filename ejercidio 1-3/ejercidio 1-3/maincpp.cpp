#include <iostream> //entrada, salida
#include <stdlib.h> //métodos random
#include <time.h> //para usar las funciones de tiempo de la CPU

using namespace std;

/*Funcion para ordenar un array de enteros.
 Parámetros:
	 - arrayEntero: el array a ordenar
	 - tamano: tamaño del array*/
void ordenarArray(int * arrayEntero, int tamano);
void mostrarArray(int * arrayEntero, int tamano);

//Función principal donde creamos y ordenamos arrays
void main()
{
	int tamano = 0;//en esta variable pondremos el tamaño del array
	int timeInicio = 0;//variable donde se guarda el tiempo el que que se inicia un algoritmo
	int timeFinal = 0;//variable donde se guarda el tiempo en el finaliza un algoritmo
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
	mostrarArray(arrayEnteros, tamano);
	cout << endl;

	timeInicio=clock();
	ordenarArray(arrayEnteros, tamano);
	timeFinal=clock();

	cout << endl << "el vector ordenado: " << endl;
	mostrarArray(arrayEnteros, tamano);
	cout << endl;

	free (arrayEnteros);
}

void mostrarArray(int * arrayEntero, int tamano)
{
	for(int i = 0; i < tamano; i++)
	{
		cout << arrayEntero[i] << " ";
	}
}

void ordenarArray(int * arrayEntero, int tamano)
{
	 int minimo = 0;//variable donde guardaremos la posicion de
	 int enteroAuxiliar = 0;

     for (int i = 0 ; i < tamano -1; i++) 
     {
		 minimo = i;
		 for(int j = i+1; j < tamano; j++)
		 {
			if(arrayEntero[minimo] > arrayEntero[j])
			 {
				minimo = j;
			 }
		 }
		 enteroAuxiliar = arrayEntero[minimo];
		 arrayEntero[minimo] = arrayEntero[i];
		 arrayEntero[i] = enteroAuxiliar ;
    }
}