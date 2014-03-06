#include <iostream>
#include <vector>
 using namespace std;
 void hanoi(int n, int *origen, int *destino, int *auxiliar);
 int main()
 {
	int origen[10];
	int destino[10];
	int auxiliar[10];
	 for (int i = 0; i< 10; i++)
	 {
		 origen[i]=i+1;
	 } 
	 hanoi(10,origen, destino, auxiliar);
	  for (int i = 0; i< 10; i++)
	 {
		cout << destino[i] << endl;
	 }

 }

void hanoi(int n, int *origen, int *destino, int *auxiliar)
 {
	 if (n>0)
	 {
		 hanoi(n-1, origen, auxiliar, destino);
		 destino[n-1]=origen[n-1];
		 hanoi(n-1, auxiliar, destino, origen);
	 }
 }

