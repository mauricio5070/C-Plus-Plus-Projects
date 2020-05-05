/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   empresa.cpp
 * Author: Angelo
 * 
 * Created on 11 de noviembre de 2017, 09:50 PM
 */

#include "empresa.h"

empresa::empresa():empleados(new lista<persona>()) {
}

empresa::empresa(const empresa& orig) {
}

empresa::~empresa() {

}
void empresa:: agregarEmpleado(persona* p){
    empleados->agregar(p);
}

string empresa::toString()const{
    stringstream s;
    s<<"empleados"<<endl;
    s<<empleados->toString();
    return s.str();
}
 ostream& empresa::serializar(ostream& salida)const{
     persona* aux =NULL;
     iterador<persona>* it = empleados->obtenerIterador();
     
     salida<<empleados->numElementos()<<"\n";
     while(it->masElementos()){
         aux=it->proximoElemento();
         aux->serializar(salida);
     }
     return salida;
     
 }
 empresa* empresa::deserializar(istream& entrada){
     empresa* emp =NULL;
     persona* p = NULL;
     
     string registro;
     stringstream s;
     getline(entrada,registro);
     if(!entrada.good())
         throw -1;
     s<<registro;     
     int can = leerCampo<int>(s);
     
     emp= new empresa();
     for(unsigned int i=0; i<can;i++){
         p= persona::deserializar(entrada);
         emp->agregarEmpleado(p);
     }
     return emp;
    
 }
