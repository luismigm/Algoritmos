#pragma once

class VectorEnteros
{
private:
	int longitudVector;//longitud del vector
	int * vectorEnteros;//direcci�n del origen de la memoria del vector

public:
	//constructor de la clase, crea el vector y guarda su longitud
	//par�metro: longitud que debe tener el vector
	//precondici�n: n>=1
	VectorEnteros(int longitudVector);

	//constructor copia de la clase. El vector creado es una copia de otro
	//par�metro: referencia al vector a copiar
	VectorEnteros::VectorEnteros(VectorEnteros &original);
	
	//destructor 
	~VectorEnteros();
	
	//obtiene la longitud del vector
	//retorno: entero con la longitud del vector
	int getLongitudVector();

	//obtiene la direcci�n del origen del vector
	//retorno: puntero con la direcci�n del origen del vector
	int * getVectorEnteros();

	//ordena el vector por selecci�n
	void ordenarSeleccion();
};

