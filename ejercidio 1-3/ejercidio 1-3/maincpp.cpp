#include <iostream> //entrada, salida
#include <stdlib.h> //métodos random
#include <time.h> //para usar las funciones de tiempo de la CPU

using namespace std;

/*Funcion para ordenar un array de enteros.
 Parámetros:
	 - arrayEntero: el array a ordenar
	 - tamano: tamaño del array*/
void ordenarSeleccion(int * arrayEntero, int tamano);

/*Funcion para mostrar en pantalla un array de enteros.
 Parámetros:
	 - arrayEntero: el array a mostrar
	 - tamano: tamaño del array*/
void mostrarArray(int * arrayEntero, int tamano);

//funcion necesaria para usar el qsort
int compare (const void * a, const void * b);
//funcion para copiar arrays de enteros
int * copiarEnteros(int const * arrayEntero, int tamano);

//Función principal donde creamos y ordenamos arrays
void main()
{
	int tamano = 0;//en esta variable pondremos el tamaño del array
	float timeInicio = 0;//variable donde se guarda el tiempo el que que se inicia un algoritmo
	float timeFinal = 0;//variable donde se guarda el tiempo en el finaliza un algoritmo
	float timeResultado = 0;//variable donde guardamos la diferencia de tiempo en segundos. 

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
		arrayEnteros[i] = rand();
	}

	/*mostramos el array*/
	cout << endl << "El vector original es el siguiente: " << endl;
	//mostrarArray(arrayEnteros, tamano);
	cout << endl;


	//creamos un array auxiliar para ordenarlo por selección y dejar el original para futuros usos
	int * arrayAuxiliar = copiarEnteros(arrayEnteros, tamano);
	
	//ordenamos el array auxiliar por selección y comprobamos cuanto tiempo ha tardado en hacerlo mostrándolo por pantalla
	timeInicio=clock();
	ordenarSeleccion(arrayAuxiliar, tamano);
	timeFinal=clock();
	timeResultado= (timeFinal-timeInicio)/1000;
	
	cout << "Cloks de inicio con ordenacion por seleccion: " << timeInicio << endl;
	cout << "Cloks de fin con ordenacion por seleccion: " << timeFinal << endl;
	cout << "CLOCKS_PER_SEC: " << CLOCKS_PER_SEC << endl; 
	cout << "Con ordenacion por seleccion he tardado " << timeResultado << " segundos en ordenarlo." << endl;
	cout <<  "El vector resultado es: " << endl;
	//mostrarArray(arrayAuxiliar, tamano);
	cout << endl << endl;

	//liberamos la memoria que hemos utilizado con el array auxiliar
	free(arrayAuxiliar);

	//volvemos a copiar el array original
	arrayAuxiliar = copiarEnteros(arrayEnteros, tamano);

	//ordenamos el array auxiliar por QuickSort y comprobamos cuanto tiempo ha tardado en hacerlo mostrándolo por pantalla
	timeInicio=clock();
	qsort (arrayAuxiliar, tamano, sizeof(int), compare);
	timeFinal=clock();
	timeResultado= (timeFinal-timeInicio)/1000;
	
	cout << "Cloks de inicio con ordenacion por QuickSort: " << timeInicio << endl;
	cout << "Cloks de fin con ordenacion por QuickSort: " << timeFinal << endl;
	cout << "CLOCKS_PER_SEC: " << CLOCKS_PER_SEC << endl; 
	cout << "Con ordenacion por QuickSort he tardado " << timeResultado << " segundos en ordenarlo." << endl;
	cout <<  "el vector resultado es: " << endl;
	//mostrarArray(arrayAuxiliar, tamano);
	cout << endl << endl;

	free (arrayEnteros);
	free(arrayAuxiliar);
}

void mostrarArray(int * arrayEntero, int tamano)
{
	for(int i = 0; i < tamano; i++)
	{
		cout << arrayEntero[i] << " ";
	}
}

void ordenarSeleccion(int * arrayEntero, int tamano)
{
	 int minimo = 0;//variable donde guardaremos la posicion del entero mínimo de esa iteracción
	 int enteroAuxiliar = 0;//variable para poder intercambiar valores

	 /*metodo de ordenación por selección. En cada iteracción buscamos el entero minimo y lo guardamos 
	 en la posición i del array. En las siguientes iteracciones buscamos desde i+1 para no usar el último 
	 mínimo. */
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

//funcion necesaria para usar el qsort
int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

//funcion para copiar arrays de enteros
int * copiarEnteros(int const * arrayEntero, int tamano)
{
   int * punterocopia =  (int *) malloc (tamano*sizeof(int));
   memcpy(punterocopia, arrayEntero, tamano * sizeof(int));
   return punterocopia;
}