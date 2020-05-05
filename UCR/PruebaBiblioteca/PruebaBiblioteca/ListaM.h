
#ifndef LISTAM_H
#define LISTAM_H
#include "NodoM.h"


class ListaM {
private:
	NodoM* pinicio;
	NodoM* pactual;
public:
	ListaM();
	bool agregar(Molde*);
	bool alquilar(Molde*);
	bool elimina(string);
	void guardarPersonas();
	void guardarAlquilados();
	void guardarLibros();
	void cargarAlquilados();
	void cargarPersonas();
	void cargarLibros();
	string toString();
	string toString2();
	int cantidadMoldes();
	Molde* buscayRetorna(string);
	Molde* buscayRetorna2(string);
    ~ListaM();
};

#endif /* LISTAM_H */

