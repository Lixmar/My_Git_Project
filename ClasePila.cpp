/*
	Implementación de la estructura de datos Pila,
	utilizando la estructura arreglo.
*/
#include <iostream>
using namespace std;

// Temaño máximo de la pila
#define MAX 10

// Clase Pila empleando plantilla
template <class T>
class Pila
{
	public:
		Pila(); 
		// Funciones
		bool PilaVacia(); 
		bool PilaLLena();
		// Procedimientos
		void Push(T);
		void Pop(T *);
		// Funciones útiles para la toma de decisiones
		int PushBool(T);
		int PopBool(T *);
		// Sobrecarga de operadores
		void operator + (T);
		void operator - (T *);
	private:
		int Tope;
		T Datos[MAX];
};

template <class T>
Pila<T>::Pila(): Tope(-1)
{}

// Nos dice si la pila acepta un "Pop" más.
template <class T>
bool Pila<T>::PilaVacia()
{
	if(Tope == -1)
		return 1;
	else
		return 0;
}

// Así sabemos si en la pila podemos hacer un Push válido.
template <class T>
bool Pila<T>::PilaLLena()
{
	if(Tope == MAX - 1)
		return 1;
	else
		return 0;
}

/*
	Los siguientes métodos estás especializados para sólo
	hacer lo que les corresponde, es decir, los independizamos.
	Pero se ha considerado el que verifiquen el estado de la
	pila mediante llamadas a los métodos auxiliares PilaVacia
	y PilaLLena, que se han desabilitado en comentario.
*/
template <class T>
void Pila<T>::Push(T Dato)
{
	/*
		if(PilaLLena() == 1)
			cout << "\aPeligro de desbordamiento - Pila llena!\n";
		else 
	*/
	Datos[++Tope] = Dato;
	// cout << Dato << " ";
}

template <class T>
void Pila<T>::Pop(T* Dato)
{
	/*
		if(!PilaVacia())
	*/
	*Dato = Datos[Tope--];
	/*
		else
			cout << "Peligro de subdesbordamiento - Pila Vacia\n";
	*/
}

/* 
	Con el operador :: especificamos de qué clase procede tal método.
	Además con la variable Res, nos ahorramos el else. 
*/
template <class T>
int Pila<T>::PushBool(T Dato)
{
	int Res = 0;
	if(!Pila::PilaLLena())
	{
		Datos[++Tope] = Dato;
		return 1;
	}
	return Res;
}

template <class T>
int Pila<T>::PopBool(T* Dato)
{
	int Res = 0;
	if(!Pila::PilaVacia())
	{
		*Dato = Datos[Tope--];
		Res = 1;
	}
	return Res;
}

/*
	También podemos oprtar por llevar a cabo las operaciones
	Push y Pop con sobrecargando nuestro operadores + y -
*/
template <class T>
void Pila<T>::operator + (T Dato)
{
	Tope ++;
	Datos[Tope] = Dato;
}

template <class T>
void Pila<T>::operator - (T* Dato)
{
	*Dato = Datos[Tope];
	Tope --;
}

void FuncionUsaPila()
{
	int ValorDesapilado = 0;
	Pila<int> ObjPila;
	
	// Esto refleja que no necesariamente tiene que ser igual a 0,
	// !ObjPila.PilaLLena(), basta con que sea diferente de 1.
	while(ObjPila.PilaLLena() != 1)
		ObjPila.Push(++ValorDesapilado); // 1 2 3 4 5 6 7 8 9 10
	
	cout << endl;
	
	while(!ObjPila.PilaVacia())
	{
		ObjPila.Pop(&ValorDesapilado);
		cout << ValorDesapilado << endl; // 10 9 8 7 6 5 4 3 2 1 
	}
}

void UsaSobrecargaOperadores()
{
	int Indice = 0;
	Pila<int> ObjPila;
	
	if(!ObjPila.PilaLLena())
		for(Indice = 1; Indice < MAX; Indice ++)
		{
			ObjPila + 2 * Indice; 
		}
	
	while(!ObjPila.PilaVacia())
	{
		ObjPila - &Indice;
		cout << '\t' << Indice << endl;
	}
}

int
main()
{	// Vemos la salida de nuestro programa.
	FuncionUsaPila();
	
	cout << endl;
	
	UsaSobrecargaOperadores();
	
	cout << endl;

	return 0;
}