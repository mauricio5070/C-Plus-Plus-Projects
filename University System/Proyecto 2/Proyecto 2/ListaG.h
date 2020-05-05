#pragma once
#include "NodoG.h"

class ListaG {
private:
	NodoG* pactual;
	NodoG* pinicio;

public:
	ListaG();
	~ListaG();
	bool agregar(Grupo*);
	string toString();
	string mostrarEstudiantes();
	int cantidadGrupos();
	bool elimina(string);
	Grupo* buscayRetorna(string);
	Persona* buscayRetornaEstu(string);
	Persona* buscayRetornaProfe(string);
};
