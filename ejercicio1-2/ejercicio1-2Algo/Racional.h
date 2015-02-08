// Clase que representa un número racional mediante una fracción
class Racional
{
private:

	int numerador; // Numerador
	int denominador; // Denominador. Precondición: no puede ser 0

public:

	/* Constructor que construye un numero racional a partir de su numerador y denominador
	Parámetros:
	- Numerador: el numerador de la fracción
	- Denominador: el denominador de la fracción
	Precondición: el denominador debe ser distinto de 0 */
	Racional(int numerador, int denominador);

	/* Suma "sumando" y el objeto actual. Crea un nuevo racional con el resultado y lo devuelve
	Parámetro: el racional que es el segundo sumando
	Retorno: un nuevo racional, fruto de sumar "sumando" con el objeto actual
	Precondición: sumando.denominador > 0 && denominador > 0 */
	Racional sumar(Racional sumando);

	/* Multiplica "multiplicador" y el objeto actual. Crea un nuevo racional con el resultado y lo devuelve
	Parámetro: el racional que es el multiplicador
	Retorno: un nuevo racional, fruto de multiplicar "multiplicador" con el objeto actual
	Precondición: multiplicador.denominador != 0 && denominador != 0 */
	Racional multiplicar(Racional multiplicador);

	/* Obtiene el numerador del objeto racional actual
	Retorno: numerador de la fracción del objeto actual */
	int getNumerador();

	/* Obtiene el denominador del objeto racional actual
	Retorno: numerador de la fracción del objeto actual */
	int getDenominador();

	/* Simplifica al maximo la fracción que representa al numero racional actual,
	hayando el maximo comun denominador (MCD) del numerador y denominador, y dividiendo
	ambos entre dicho MCD */
	void simplificar();

	/* Imprime por pantalla la fracción que representa al numero racional actual. Formato n/d.
	Si el numerador es 0 ó el denominador es 1 sólo se escribe el numerador.
	OJO: Este es un método de vista que está en una clase de modelo => MAL */
	void escribir();

private:
	/*Calcula el máximo común divisior de dos números
	precondiciones:	numeroA >= 0 && numeroB >= 0 && numeroA > numeroB*/
	int calcularMCD(int numeroA, int numeroB);

};

