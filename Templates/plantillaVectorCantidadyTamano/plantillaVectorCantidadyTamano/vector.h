#pragma once
#include <iostream>

using namespace std;
//plantilla vector que genera contenedores tipo contenedor


template<class T>
class Vector {
private:
	T * vec;
	int can;
	int tam;
public:
	Vector(int=10);//constructor con parametros
	Vector(int, const T[]); //recibe tamano y vector
	//Vector(const Vector&);// constructor copia, tarea moral
	~Vector();
	virtual bool ingresaElemento(const T&);
	//virtual bool eliminaElemento(int lug); //taream moral
	virtual string toString();


};

template<class T>
 Vector<T>::Vector(int n) :tam(n), can(0)
{
	vec = new T[tam];
}

template<class T>
 Vector<T>::Vector(int tamanio, const T a[])
{
	vec = new T[tamanio];
	for (int i = 0; i < tamanio; i++) {
		vec[i] = a[i];    //necesita sobrecarga del operador asignacion
	
	}
}

template<class T>
 Vector<T>::~Vector()
{
	//delete vec []
}

template<class T>
 bool Vector<T>::ingresaElemento(const T &obj)
{
	if (can < tam) {
		vec[can++] = obj;
		return true;
	}
	else {
		return false;
	}
}

template<class T>
 string Vector<T>::toString()
{
	stringstream s;
	for (int i = 0; i < can; i++){
		s << vec[i] << endl;
	}

	return s.str();
}
