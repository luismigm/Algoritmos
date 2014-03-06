#include <iostream>

 using namespace std;
 void hanoi(int n, int *origen, int *destino, int *auxiliar);
 int main()
 {
	 /*arrays de enteros, simular�n una torre de hanoy al ir de la base m�s grande, el 10, a la punta de la pir�mide, el 1*/
	int origen[10];
	int destino[10];
	int auxiliar[10];
	//inicializaamos el array de origen, damos el valor i+1 para que el m�s peque�o sea uno
	 for (int i = 0; i< 10; i++)
	 {
		 origen[i]=i+1;
	 } 

	 hanoi(10,origen, destino, auxiliar);
	 //mostramos el array destino para ver que se ha realizado el traspaso de valores correctamente
	 for (int i = 0; i< 10; i++)
	 {
		cout << destino[i] << endl;
	 }

 }
 //funci�n hanoi tal y como est� en pseudoc�digo
void hanoi(int n, int *origen, int *destino, int *auxiliar)
 {
	 if (n>0)
	 {
		 hanoi(n-1, origen, auxiliar, destino);
		 destino[n-1]=origen[n-1];//lo que carlos pone como "cambio" no deja de ser una asignaci�n de una variable a otra. 
		 hanoi(n-1, auxiliar, destino, origen);
	 }
 }

