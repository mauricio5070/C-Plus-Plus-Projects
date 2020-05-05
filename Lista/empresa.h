/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   empresa.h
 * Author: Angelo
 *
 * Created on 11 de noviembre de 2017, 09:50 PM
 */

#ifndef EMPRESA_H
#define EMPRESA_H
#include "lista.h"
#include "persona.h"
#include "objeto.h"

class empresa:public objeto {
public:
    empresa();
    empresa(const empresa& orig);
    virtual void agregarEmpleado(persona*);
    virtual string toString()const;
    
    virtual ostream& serializar(ostream&)const;
    static empresa* deserializar(istream&);
    
    virtual ~empresa();
private:
    lista<persona>* empleados;
};

#endif /* EMPRESA_H */

