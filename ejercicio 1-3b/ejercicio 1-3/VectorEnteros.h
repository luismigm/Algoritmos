#pragma once

class VectorEnteros
{
private:
	int longitudVector;//longitud del vector
	int * vectorEnteros;//dirección del origen de la memoria del vector

public:
	//constructor de la clase, crea el vector y guarda su longitud
	//parámetro: longitud que debe tener el vector
	//precondición: n>=1
	VectorEnteros(int longitudVector);

	//constructor copia de la clase. El vector creado es una copia de otro
	//parámetro: referencia al vector a copiar
	VectorEnteros::VectorEnteros(VectorEnteros &original);
	
	//destructor 
	~VectorEnteros();
	
	//obtiene la longitud del vector
	//retorno: entero con la longitud del vector
	int getLongitudVector();

	//obtiene la dirección del origen del vector
	//retorno: puntero con la dirección del origen del vector
	int * getVectorEnteros();

	//ordena el vector por selección
	void ordenarSeleccion();
};

