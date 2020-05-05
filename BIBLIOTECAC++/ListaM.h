
#ifndef LISTAM_H
#define LISTAM_H
#include "NodoM.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
class ListaM {
private:
	NodoM* pinicio;
	NodoM* pactual;
public:
	ListaM();
	bool agregar(Molde*);
	bool elimina(string);
	void guardarPersonas();
	void guardarLibros();
	void cargarPersonas();
	void cargarLibros();
	string toString();
	int cantidadMoldes();
	Molde* buscayRetorna(string);
    ~ListaM();
};

#endif /* LISTAM_H */

