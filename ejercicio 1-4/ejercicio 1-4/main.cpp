#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <ctime>
#include <cassert>

using namespace std;


//función que usa el qsort() para comparar dos elementos
//parámetros: NumeroA, NumeroB. Elementos a comparar
//retorno: un entero con el resultado de la comparación, <0 a es menor que b, 0 iguales, >1 a es mayor que b
//preconcidión: numeroA != NULL && numero B != NULL
int comparaMayor (const void * numeroA, const void * numeroB);

//función que usa el qsort() para comparar dos elementos
//parámetros: a, b. Elementos a comparar
//retorno: un entero con el resultado de la comparación, <0 a es mayor que b, 0 iguales, >1 a es menor que b
//preconcidión: numeroA != NULL && numero B != NULL
int comparaMenor (const void * numeroA, const void * numeroB);

//imprime por pantalla un vector de enteros.
//Parámetros:
//	*vector: el puntero del vector a mostrar
//	longitud: longitud del vector
// Precondiciones: longitud > 0
void escribir(int *vector, int longitud);


// Ordena un vector de enteros por el algoritmo de inserción
// Parámetros:
//	vector: el puntero del vector a ordenar
//	n: longitud del vector
// Precondiciones: vector != NULL, n > 0
void ordenarInsercion (int *vector, int n);

int main()
{
	int n = 0;//numero de componentes de los arrays
	int cantidadArraysParaMedia = 0;//numero de arrays aleatorios para sacar el caso medio
	srand(time(NULL));//generamos la semilla
	clock_t numeroClicksInicio, numeroClicksFin;//clicks de reloj al inicio y al final de cada ejecución
	float segundosTranscurridos;//segundos transcurridos entre el inicio y el final de la ejecución


	do
	{
	cout << "Numnero de componentes de los arrays (> = 1): " ;
	cin >> n;
	}while (n<1);

	do
	{
		cout << "Cantidad de arrays aleatorios para el caso medio (>= 1): ";
		cin >> cantidadArraysParaMedia;
	}while (n<1);

	//Creamos dos arrays de punteros que apunten a los arrays de enteros que vamos a utlizar para 
	//la media, uno se usara para el método de inserción y el otro por Qsort
	int **arraysInsercion = (int**) malloc (cantidadArraysParaMedia * sizeof(int*));
	int **arraysQsort = (int**) malloc (cantidadArraysParaMedia * sizeof(int*));

	//llenaamos los arrays
	for(int i = 0; i < cantidadArraysParaMedia; i++)
	{
		//reservamos memoria para cada array
		arraysInsercion[i] = (int*) malloc (n * sizeof(int));
		arraysQsort[i] = (int*) malloc (n * sizeof(int));
		//rellenamos los arrays creados con el mismo valor
		for (int j = 0; j < n; j++)
		{
			arraysInsercion[i][j] = arraysQsort[i][j] = rand();
		}
	}

	//creamos dos arrays iguales para el caso mejor con números aleatorios 
	int *arrayCasoMejorInsercion = (int *) malloc (n * sizeof (int));//para el método deinsercion
	int *arrayCasoMejorQsort = (int *) malloc (n * sizeof (int));//para el método de qsort
	for (int i = 0; i < n; i++)
	{
		arrayCasoMejorInsercion[i] = rand(); // Rellenamos aleatoriamente uno de ellos
	}
	qsort (arrayCasoMejorInsercion, n, sizeof(int), comparaMenor); // Lo ordenamos de menor a mayor
	for (int i = 0; i < n; i++) // Copiamos los valores al otro array
	{
		arrayCasoMejorQsort[i] = arrayCasoMejorInsercion[i];
	}
	
	//creamos dos arrays iguales para el caso peor con números aleatorios 
	int *arrayCasoPeorInsercion = (int *) malloc (n * sizeof (int));//para el método deinsercion
	int *arrayCasoPeorQsort = (int *) malloc (n * sizeof (int));//para el método de qsort
	for (int i = 0; i < n; i++)
	{
		arrayCasoPeorInsercion[i] = rand(); // Rellenamos aleatoriamente uno de ellos
	}
	qsort (arrayCasoPeorInsercion, n, sizeof(int), comparaMayor); // Lo ordenamos de mayor
	for (int i = 0; i < n; i++) // Copiamos los valores al otro array
	{
		arrayCasoPeorQsort[i] = arrayCasoPeorInsercion[i];
	}

	// Imprimimos los arrays
	cout << "\nArray para calcular el caso mejor:\n   ";
	escribir(arrayCasoMejorQsort, n);
	cout << "\nArray para calcular el caso peor:\n   ";
	escribir(arrayCasoPeorQsort, n);
	cout << "\nArrays para calcular caso medio:\n";
	for (int i = 0; i < cantidadArraysParaMedia; i++) 
	{
		escribir(arraysInsercion[i], n);
		cout << endl;
	}


	//Calculamos los tiempos

	// Tiempos para el caso mejor
	cout << endl << "Tiempos para el caso mejor: " << endl;
	//por inserción
	numeroClicksInicio = clock();
	ordenarInsercion(arrayCasoMejorInsercion, n);
	numeroClicksFin = clock();
	segundosTranscurridos = ((float)(numeroClicksFin - numeroClicksInicio)) / CLOCKS_PER_SEC; 
	printf ("Insercion: %.3f segundos\n   ", segundosTranscurridos);
	//por qsort
	numeroClicksInicio = clock();
	qsort(arrayCasoMejorQsort, n, sizeof(int), comparaMenor);
	numeroClicksFin = clock();
	segundosTranscurridos = ((float)(numeroClicksFin - numeroClicksInicio)) / CLOCKS_PER_SEC; 
	printf ("QuickSort: %.3f segundos", segundosTranscurridos);

	// Tiempos para el caso peor
	cout << endl << "Tiempos para el caso peor:" << endl;
	//por inserción
	numeroClicksInicio = clock();
	ordenarInsercion(arrayCasoPeorInsercion, n);
	numeroClicksFin = clock();
	segundosTranscurridos = ((float)(numeroClicksFin - numeroClicksInicio)) / CLOCKS_PER_SEC; 
	printf ("Insercion: %.3f segundos\n   ", segundosTranscurridos);
	//por qsort
	numeroClicksInicio = clock();
	qsort(arrayCasoPeorQsort, n, sizeof(int), comparaMenor);
	numeroClicksFin = clock();
	segundosTranscurridos = ((float)(numeroClicksFin - numeroClicksInicio)) / CLOCKS_PER_SEC; 
	printf ("QuickSort: %.3f segundos", segundosTranscurridos);

	// Tiempos para el caso medio
	cout << "\nTiempos para el caso medio:\n   ";
	numeroClicksInicio = clock();
	//por insercion
	for (int i = 0; i < cantidadArraysParaMedia; i++) 
	{
		ordenarInsercion(arraysInsercion[i], n);		
	}
	numeroClicksFin = clock();
	segundosTranscurridos = ((float)(numeroClicksFin - numeroClicksInicio)) / CLOCKS_PER_SEC; 
	printf ("Insercion: %.3f segundos (de media)\n   ", segundosTranscurridos/cantidadArraysParaMedia);
	numeroClicksInicio = clock();
	//por qsort
	for (int i=0; i<cantidadArraysParaMedia; i++) 
	{
		qsort(arraysQsort[i], n, sizeof(int), comparaMenor);
	}
	numeroClicksFin = clock();
	segundosTranscurridos = ((float)(numeroClicksFin - numeroClicksInicio)) / CLOCKS_PER_SEC; 
	printf ("QuickSort: %.3f segundos (de media)\n", segundosTranscurridos/cantidadArraysParaMedia);

	
	// Imprimimos los arrays ordenados
	cout << endl << "Arrays para calcular el caso mejor:" << endl;
	cout << "Insercion: ";
	escribir(arrayCasoMejorInsercion, n);
	cout << endl << "QuickSort: ";
	escribir(arrayCasoMejorQsort, n);
	cout << endl << "Arrays para calcular el caso peor: " << endl;
	cout <<  "Insercion: ";
	escribir(arrayCasoPeorInsercion, n);
	cout << endl << "QuickSort: ";
	escribir(arrayCasoPeorQsort, n);
	cout << endl << "Arrays para calcular caso medio:" << endl;
	cout << "Insercion:" << endl;
	for (int i = 0; i < cantidadArraysParaMedia; i++) 
	{
		escribir(arraysInsercion[i], n);
		cout << endl;
	}
	cout << "QuickSort:" << endl;
	for (int i = 0; i < cantidadArraysParaMedia; i++) 
	{
		escribir(arraysQsort[i], n);
		cout << endl;
	}
	cout << endl;

	
	cout << getch();



}

void escribir(int *vector, int longitud) 
{
	assert(longitud > 0);
	// Solo lo mostramos por pantalla si el tamaño es mayor que 10
	if (longitud <= 10)
	{
		for (int i = 0; i < longitud; i++)
		{
			cout << vector[i] << " ";
		}
		cout << endl;
	}
	else
	{
		cout << "Demasiados componentes para mostrar" << endl;
	}
}

int comparaMayor (const void *numeroA, const void *numeroB) 
{
	assert (numeroA != NULL && numeroB != NULL);
	int *punteroNumero1 = (int*) numeroA; // Puntero a entero del primer número
	int *punteroNumero2 = (int*) numeroB; // Puntero a entero del segundo número
	return (*punteroNumero2 - *punteroNumero1);
}
int comparaMenor (const void *numeroA, const void *numeroB) 
{
	assert (numeroA != NULL && numeroB != NULL);
	int *punteroNumero1 = (int*) numeroA; // Puntero a entero del primer número
	int *punteroNumero2 = (int*) numeroB; // Puntero a entero del segundo número
	return (*punteroNumero1 - *punteroNumero2);
}
void ordenarInsercion (int *vector, int n) 
{
	assert(vector != NULL);
	assert(n > 0);

	int indice = 0; // Posicion del indice
	int posicion = 0; //posicion donde recolocar el número
	int numero; // numero a ordenar

	// desde la posicion 
	for (indice = 1; indice < n; indice++) 
	{
		numero = vector[indice]; // Guardamos el numero a ordenar
		posicion = indice-1; // posicion donde colocar el numero si es menor

		// Buscamos el lugar en donde insertar el elemento. 
		while (posicion >= 0 && numero < vector[posicion]) 
		{
			vector[posicion+1] = vector[posicion]; // Creamos un hueco copiando su conteniendo a su celda de la derecha
			posicion--;
		}

		vector[posicion+1] = numero; // Finalmente, copiamos el elemento al hueco adecuado encontrado
	}
}