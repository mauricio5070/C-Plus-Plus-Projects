#pragma once
#include "Estudiante.h"
class Nodo
{
private:
	Estudiante * estu;
	Nodo *sig;
public:
	Nodo(Estudiante*, Nodo*);
	~Nodo();
	void setEstu(Estudiante *);
	Estudiante * getEstu();
	void setSig(Nodo*);
	Nodo* getSig();
	string toStringNodo();
};
