/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   objeto.h
 * Author: Angelo
 *
 * Created on 11 de noviembre de 2017, 07:40 PM
 */

#ifndef OBJETO_H
#define OBJETO_H

#include <sstream>
using namespace std;

class objeto {
public:
    objeto();
    virtual ~objeto();
    virtual string toString() const = 0;
    
    //Autor. Georges E. Alfaro S.
    template <typename T> static T leerCampo(stringstream&);
};

ostream& operator << (ostream&,const objeto&);

//Autor. Georges E. Alfaro S.
template <typename T>
T objeto::leerCampo(stringstream& s) {
    T r;
    if (!(s >> r)) {
        throw -1;
    }
    return r;
}
#endif /* OBJETO_H */

