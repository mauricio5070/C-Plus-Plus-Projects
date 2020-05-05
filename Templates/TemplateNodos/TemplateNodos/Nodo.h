#pragma once
#include<iostream>
#include<string>
#include<sstream>
//#include"Persona.h"
using namespace std;

template <class T>

class Nodo {
private:
	Nodo<T>* sig;
	T* info;
public:
	Nodo(Nodo<T>*, T&);
	virtual ~Nodo();
	virtual void setSiguiente(Nodo<T>*);
	virtual Nodo<T>* getSiguiente();
	virtual T* getInfo();
	virtual void setInfo(T*);
};


template<class T>
Nodo<T>::Nodo(Nodo<T>*sig, T& info): sig(sig), info(&info){}

template <class T>
Nodo<T>::~Nodo() { delete info; }

template <class T>
void Nodo<T>::setSiguiente(Nodo<T>* sigu) { sig = sigu; }

template <class T>
Nodo<T>* Nodo<T>::getSiguiente() { return sig; }

template <class T>
T* Nodo<T>::getInfo() { return info; }

template <class T>
void Nodo<T>::setInfo(T* inf) { info = inf; }
