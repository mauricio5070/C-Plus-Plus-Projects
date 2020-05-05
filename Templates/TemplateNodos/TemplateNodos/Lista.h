#pragma once
#include"Nodo.h"

template <class T>

class Lista {
private:
	Nodo<T>* primerNodo;

public:
	Lista();
	Lista(Lista<T>& list);
	~Lista();
	//Lista<T>& operator = (const Lista<T>&);
	string toString()const;
	void agregaElemento(T* elem);
	bool eliminaElemento(T* elem);
	Nodo<T>* getPrimerNodo();
	bool eliminarPrimero();
	void eliminaTodos();
};

template<class T>
Lista<T>::Lista() { primerNodo = NULL; }

template<class T>
Lista<T>::Lista(Lista<T>& list) {    //Const copia
	T* elemento = NULL;      //Flecha a un objeto
	primerNodo = NULL;    //Ratificar que ppio =NULL
	Nodo<T>* actual = list.getPrimerNodo();
	//actual ve al primer elemento de la otra Lista
	while (actual != NULL) {
		elemento = new T(*(actual->getInfo()));  //Duplica objeto
		this->agregaElemento(elemento);   //Agregar elem en mi Lista
		actual = actual->getSiguiente();   //Nos pasamos de nodo en nodo
	}
}

template<class T>
Lista<T>::~Lista() {
	this->eliminaTodos();    //Elimina a todos los nodos con sus cargas
}

/*template<class T>
Lista<T>& Lista<T>::operator = (const Lista<T>&); */  //Tarea Moral

template<class T>
string Lista<T>::toString()const {
	int num = 1;
	stringstream s;
	Nodo<T>* actual = primerNodo;  //Apuntamos a ppio con actual
	if (primerNodo ==NULL) {   //La lista esta vacia
		s << "No hay elementos en la Lista" << endl;
	}
	else {  //Esto quiere decir que si hay elem en la lista
		while (actual!=NULL) {
			s << "No." << num << "\n" << *(actual->getInfo()) << endl;
			actual = actual->getSiguiente();
			num++;
		}
	}
	return s.str();
}


template<class T>
void Lista<T>::agregaElemento(T* elem) {  //Agregar elemento al Final

	Nodo<T>* nuevo = new Nodo<T>(NULL, *elem);    //Nodo nuevo con elemento

	if (getPrimerNodo() == NULL) {
		primerNodo = nuevo;
	}
	else {
		Nodo<T>* actual = NULL;
		actual = primerNodo;
		while (actual->getSiguiente() != NULL){
			actual = actual->getSiguiente();
		}

		actual->setSiguiente(nuevo);   //El ultimo lo estamos pegando a el nodo nuevo
	}
}


template<class T>
bool Lista<T>::eliminaElemento(T* elem) {
	//Tarea Moral
}

template<class T>
Nodo<T>* Lista<T>::getPrimerNodo() { return primerNodo; }


template<class T>
bool Lista<T>::eliminarPrimero() {
	if (getPrimerNodo!=NULL) {
		Nodo<T>* borrado = getPrimerNodo();
		primerNodo = borrado->getSiguiente();
		delete borrado;
		return true;
	}
	return false;
}

template<class T>
void Lista<T>::eliminaTodos() {
	while (eliminarPrimero()) {}
}

