#pragma once
#include "Nodo.h"
#include <sstream>
#include <iostream>
using namespace std;
class Lista {

private:
	Nodo *pinicio;
	Nodo *pactual;
public:
	Lista();
	~Lista();
	void insertarInicio(Estudiante*);
	bool eliminarInicio();
	string toString();
	float promedio();
	int cuentaNodos();
	void elUltimo();
	void eliminaFinal();
	//bool encontrado(int);
	//bool borrarEspecifico();


};
