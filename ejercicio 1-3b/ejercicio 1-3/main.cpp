#include "iostream"
#include "conio.h" //para usar getchar()
#include "ctime" //para usar srand() y clock()
#include "VectorEnteros.h" 

using namespace std;

//función que usa el qsort() para comparar dos elementos
//parámetros: a, b. Elementos a comparar
//retorno: un entero con el resultado de la comparación, <0 a es menor que b, 0 iguales, >1 a es mayor que b
int compare (const void * a, const void * b);

//imprime por pantalla un vector de enteros.
//Parámetros:
//	int *vector: el puntero del vector a mostrar
//	int longitud: longitud del vector
void escribir(int *vector, int longitud);

int main()
{
	int longitudVector = 0;//tamaño del array
	// Se inicializa el generador de numeros aleatorios
	srand(time(NULL));
	
	//Introducimos longitud del vector, mínimo uno
	do
	{
	cout << "Introduce el tamano del vector (numero mayor o igual que 1): " << endl;
	cin >> longitudVector;
	}while(longitudVector < 1);
	
	//creamos el vector original y sus copias para ordenarlas
	VectorEnteros a (longitudVector);
	VectorEnteros copiaA(a);
	VectorEnteros copiaB(a);

	//mostramos el vector original
	cout << endl << "El vector original es el siguiente:" << endl;
	escribir(a.getVectorEnteros(), a.getLongitudVector());

	//ordenamos el vector copiaA por seleccion y calculamos el tiempo transcurrido mostrando los resultados
	clock_t tiempoInicial = clock();
	cout << endl << endl << "Clocks de inicio con ordenacion por seleccion: " << tiempoInicial << endl;
	copiaA.ordenarSeleccion();
	clock_t tiempoFinal = clock();
	cout << "Clocks de fin con ordenacion por seleccion:    " << tiempoFinal << endl;
	cout << "CLOCK_PER_SEC:                                 " << CLOCKS_PER_SEC << endl;
	float tiempo = ((float)(tiempoFinal - tiempoInicial)) / CLOCKS_PER_SEC;
	printf ("Con ordenacion por seleccion he tardado %.3f segundos en ordenarlo.\nEl vector resultado es:\n", tiempo);
	escribir(copiaA.getVectorEnteros(), copiaA.getLongitudVector());

	//ordenamos el vector copiaB por qsort y calculamos el tiempo transcurrido mostrando los resultados
	tiempoInicial = clock();
	cout << endl << endl << "Clocks de inicio con ordenacion por QuickSort: " << tiempoInicial << endl;
	qsort (copiaB.getVectorEnteros(), copiaB.getLongitudVector(), sizeof(int), compare);
	tiempoFinal = clock();
	cout << "Clocks de fin con ordenacion por QuickSort:    " << tiempoFinal << endl;
	cout << "CLOCK_PER_SEC:                                 " << CLOCKS_PER_SEC << endl;
	tiempo = ((float)(tiempoFinal - tiempoInicial)) / CLOCKS_PER_SEC;
	printf ("Con ordenacion por QuickSort he tardado %.3f segundos en ordenarlo.\nEl vector resultado es:\n", tiempo);
	escribir(copiaB.getVectorEnteros(), copiaB.getLongitudVector());

	cout << getch();
}

int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

void escribir(int *vector, int longitud) {
	// Solo lo mostramos por pantalla si el tamaño es mayor que 10
	if (longitud <= 10)
	{
		for (int i=0; i<longitud; i++)
		{
			cout << vector[i] << " ";
		}
		cout << endl;
	}
	else
	{
		cout << "El vector es muy grande para mostrarse" << endl;
	}
}