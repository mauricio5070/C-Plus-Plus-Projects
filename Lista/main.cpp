/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Angelo
 *
 * Created on 11 de noviembre de 2017, 09:01 PM
 */

#include <cstdlib>
#include "persona.h"
#include <sstream>
#include <iostream>
#include <fstream>

#include "empresa.h"

using namespace std;

int main(int argc, char** argv) {
    
    //string rutaArchivo = "persona.txt";
    
   // ofstream salida(rutaArchivo.c_str());
    empresa* em = new empresa();
    
    persona* p1= new persona("angelo");
    persona* p2 = new persona("p2");
    persona* p4 = new persona("p4");
    persona* p3 = new persona("p3");
    em ->agregarEmpleado(p1);
    em ->agregarEmpleado(p2);
    em ->agregarEmpleado(p3);
    em ->agregarEmpleado(p4);
    //em->serializar(salida);
    
   // salida.close();
    
   
   // ifstream entrada(rutaArchivo.c_str());
    
   // empresa* aux= empresa::deserializar(entrada);
   // cout<<*aux;
    //entrada.close();
	cout<<em->toString();

	system("pause");

    return 0;
}

