#pragma once
#include "Nodo.h"
#include <sstream>
#include <iostream>
#include "Estudiante.h"

class Nodo {
private:
	Estudiante* est;
	Nodo* sig;

public:
	Nodo(Estudiante*, Nodo*);
	~Nodo();
	void setEstudiante(Estudiante*);
	Estudiante* getEstudiante();
	void setSig(Nodo*);
	Nodo* getSig();
	string toStringNodo();
};
