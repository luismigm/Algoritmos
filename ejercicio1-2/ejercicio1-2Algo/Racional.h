// Clase que representa un n�mero racional mediante una fracci�n
class Racional
{
private:

	int numerador; // Numerador
	int denominador; // Denominador. Precondici�n: no puede ser 0

public:

	/* Constructor que construye un numero racional a partir de su numerador y denominador
	Par�metros:
	- Numerador: el numerador de la fracci�n
	- Denominador: el denominador de la fracci�n
	Precondici�n: el denominador debe ser distinto de 0 */
	Racional(int numerador, int denominador);

	/* Suma "sumando" y el objeto actual. Crea un nuevo racional con el resultado y lo devuelve
	Par�metro: el racional que es el segundo sumando
	Retorno: un nuevo racional, fruto de sumar "sumando" con el objeto actual
	Precondici�n: sumando.denominador > 0 && denominador > 0 */
	Racional sumar(Racional sumando);

	/* Multiplica "multiplicador" y el objeto actual. Crea un nuevo racional con el resultado y lo devuelve
	Par�metro: el racional que es el multiplicador
	Retorno: un nuevo racional, fruto de multiplicar "multiplicador" con el objeto actual
	Precondici�n: multiplicador.denominador != 0 && denominador != 0 */
	Racional multiplicar(Racional multiplicador);

	/* Obtiene el numerador del objeto racional actual
	Retorno: numerador de la fracci�n del objeto actual */
	int getNumerador();

	/* Obtiene el denominador del objeto racional actual
	Retorno: numerador de la fracci�n del objeto actual */
	int getDenominador();

	/* Simplifica al maximo la fracci�n que representa al numero racional actual,
	hayando el maximo comun denominador (MCD) del numerador y denominador, y dividiendo
	ambos entre dicho MCD */
	void simplificar();

	/* Imprime por pantalla la fracci�n que representa al numero racional actual. Formato n/d.
	Si el numerador es 0 � el denominador es 1 s�lo se escribe el numerador.
	OJO: Este es un m�todo de vista que est� en una clase de modelo => MAL */
	void escribir();

private:
	/*Calcula el m�ximo com�n divisior de dos n�meros
	precondiciones:	numeroA >= 0 && numeroB >= 0 && numeroA > numeroB*/
	int calcularMCD(int numeroA, int numeroB);

};

