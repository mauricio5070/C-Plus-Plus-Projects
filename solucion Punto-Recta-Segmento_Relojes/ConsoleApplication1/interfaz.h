#ifndef INTERFAZ_H
#define INTERFAZ_H
#include <iostream>
using namespace std;

// Ninguna clase debe tener cin o cout, esto se lo delegamos unicamente a la clase Interfaz
class interfaz  
{              
public:
	void imprimir(double);
	void imprimir(string);
	double leerDouble( );

};

#endif