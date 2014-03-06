#include <iostream>

 using namespace std;
 void hanoi(int n, int *origen, int *destino, int *auxiliar);
 int main()
 {
	 /*arrays de enteros, simularán una torre de hanoy al ir de la base más grande, el 10, a la punta de la pirámide, el 1*/
	int origen[10];
	int destino[10];
	int auxiliar[10];
	//inicializaamos el array de origen, damos el valor i+1 para que el más pequeño sea uno
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
 //función hanoi tal y como está en pseudocódigo
void hanoi(int n, int *origen, int *destino, int *auxiliar)
 {
	 if (n>0)
	 {
		 hanoi(n-1, origen, auxiliar, destino);
		 destino[n-1]=origen[n-1];//lo que carlos pone como "cambio" no deja de ser una asignación de una variable a otra. 
		 hanoi(n-1, auxiliar, destino, origen);
	 }
 }

