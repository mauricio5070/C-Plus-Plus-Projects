#ifndef  COLECCION_H
#define  COLECCION_H
#include<iostream>
#include<string> 
#include<sstream>
#include "paciente.h"
using namespace std;

class Coleccion {

private:
	Paciente *arreglo;
	int tamanio;
	int cantidad;
public:
	Coleccion(int);
	~Coleccion();
	void llenaArreglo();
	void imprimaArreglo();


	}

};

#endif