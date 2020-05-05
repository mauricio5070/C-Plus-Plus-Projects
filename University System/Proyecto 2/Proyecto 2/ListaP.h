#pragma once
#include"NodoP.h"

class ListaP {
private:
	NodoP* pinicio;
	NodoP* pactual;
public:
	ListaP();
	bool agregar(Persona*);
	bool elimina(string);
	void guardarEstudiantes();
	void guardarProfesores();
	void cargarEstudiante();
	void cargarProfesor();
	string toString();
	int cantidadPersonas();
	Persona* buscayRetorna(string);
    ~ListaP();
};
