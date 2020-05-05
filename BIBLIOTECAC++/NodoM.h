

#ifndef NODOM_H
#define NODOM_H

#include "Molde.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
class NodoM {

private:
	Molde *Mol;
	NodoM *Sig;
public:
	NodoM(Molde* = NULL, NodoM* = NULL);
	void setMolde(Molde*);
	Molde* getMolde();
	void setSiguiente(NodoM*);
	NodoM* getSiguiente();
	string toStringNodo();
	virtual ~NodoM();


};

#endif /* NODOM_H */

