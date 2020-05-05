/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   iterador.h
 * Author: Angelo
 *
 * Created on 11 de noviembre de 2017, 09:02 PM
 */

#ifndef ITERADOR_H
#define ITERADOR_H

template <class T>
class iterador {
public:
    virtual bool masElementos()const = 0;
    virtual T* proximoElemento()=0;

};

#endif /* ITERADOR_H */

