#pragma once
#include "Persona.h"

class NodoP {

private:
	Persona *Per;
	NodoP *Sig;
public:
	NodoP(Persona* = NULL, NodoP* = NULL);
	void setPersona(Persona*);
	Persona* getPersona();
	void setSiguiente(NodoP*);
	NodoP* getSiguiente();
	string toStringNodo();
	virtual ~NodoP();


};
