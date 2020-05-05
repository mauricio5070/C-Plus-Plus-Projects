#pragma once
#include "Nodo.h"
class Lista 
{
private:
	Nodo* pinicio;
	Nodo* pactual;
	Nodo* psegundo;
public:
	Lista();
	void insertarInicio(Estudiante*);
	void eliminaFinal();
	void elUltimo();
	string toString();
	bool encontrado(int id);
	bool eliminarEspecifico(int x);
	float promedio();
	bool eliminaInicio();
	int cuentaNodos();
	~Lista();
};
