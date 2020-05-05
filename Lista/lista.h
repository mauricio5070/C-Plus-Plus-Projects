/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   lista.h
 * Author: Angelo
 *
 * Created on 11 de noviembre de 2017, 06:54 PM
 */

#ifndef LISTA_H
#define LISTA_H

#include <sstream>
#include <iostream>
using namespace std;

#include "iterador.h"

template <class T>
class iteradorLista;

template <class T>
class lista;

template <class T>
class nodo;

template <class T>
class nodo{
    public:
        nodo(T*,nodo<T>*);
       
        virtual nodo<T>* sig()const;
        virtual void fijarSiguiente(nodo<T>*);
        virtual T* info()const;
    private:
        nodo<T>* _siguiente;
        T* contenido;
};

template <class T>
class iteradorLista: public iterador<T>{
    public:
        iteradorLista(nodo<T>*);
        virtual bool masElementos()const;
        virtual T* proximoElemento();
    
    private:
        nodo<T>* cursor;
};
template <class T>
class lista {
    public:
        lista();
        ~lista();
        lista(const lista&);
        virtual lista& operator =(const lista&);
        
        virtual int numElementos()const;
        virtual void agregar(T*);
        iterador<T>* obtenerIterador()const;

        virtual string toString()const;
    private:
        nodo<T>* primero;
};

//-----------------------------------------------
template<class T>
lista<T>::lista():primero(NULL){}

template<class T>
lista<T>::lista(const lista& obj){
    nodo<T>* aux = obj.primero;
    while(aux){
        agregar(aux->info());
        aux=aux->sig();
    }
}
template <class T>
lista<T>& lista<T>::operator =(const lista& objeto){

    if(this != &objeto){
        nodo<T>* _cursor = NULL;
        while (primero) {
            _cursor = primero;
            primero = primero->sig();
            delete _cursor;
        }
        primero=NULL;
        nodo<T>* cursor = objeto.primero;
        while(cursor){
            agregar(cursor->info());
            cursor = cursor->sig();
        }
    }
    return *this;
}

template <class T>
lista<T>::~lista(){
    nodo<T>* aux =NULL;
    while(primero){
        aux=primero;
        primero=primero->sig();
        delete aux;
    }
}
template <class T>
int lista<T>::numElementos() const{
int r = 0;
    nodo<T>* aux= primero;
    while (aux != NULL) {
        r++;
        aux = aux->sig();
    }
    return r;
}

template <class T>
void lista<T>::agregar(T* ob){
    if(primero==NULL)
        primero = new nodo<T>(ob,NULL);
    else{
        nodo<T>* aux=primero;
        while(aux->sig()!=NULL){
            aux=aux->sig();
        }
        aux->fijarSiguiente(new nodo<T>(ob,NULL));
    }
}
template <class T>
iterador<T>* lista<T>::obtenerIterador()const{
    return new iteradorLista<T>(primero);
}

template <class T>
string lista<T>::toString() const{
    stringstream s;
    nodo<T>* aux= primero;
    while(aux!=NULL){
        s<<*aux->info();
        aux=aux->sig();
    }
    s<<"}";
    return s.str();
}
template<class T>
nodo<T>::nodo(T* ob, nodo<T>* _sig)
:_siguiente(_sig), contenido(ob) {
}

template <class T>
nodo<T>* nodo<T>::sig() const {
    return _siguiente;
}

template <class T>
void nodo<T>::fijarSiguiente(nodo<T>* siguiente) {
    _siguiente = siguiente;
}
template <class T>
T* nodo<T>::info() const {
    return contenido;
}

template<class T>
iteradorLista<T>::iteradorLista(nodo<T>* primero) : cursor(primero) {
}

template<class T>
bool iteradorLista<T>::masElementos() const {
    return (cursor != NULL);
}

template <class T>
T* iteradorLista<T>::proximoElemento() {
    T* r = cursor->info();
    cursor = cursor->sig();
    return r;
}


#endif /* LISTA_H */

