/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   objeto.cpp
 * Author: Angelo
 * 
 * Created on 11 de noviembre de 2017, 07:40 PM
 */

#include "objeto.h"


objeto::objeto() {
}

objeto::~objeto() {
}

ostream& operator << (ostream& salida,const objeto& p){
    salida <<p.toString();
    return salida;
}
