#include "Nodo.h"


Nodo::Nodo(Estudiante* e, Nodo* s)
{
	estu = e;
	sig = s;
}


Nodo::~Nodo()
{
	delete estu;
}




void Nodo::setEstu(Estudiante *e) {
	estu = e;
}

Estudiante* Nodo::getEstu() {
	return estu;
}

void Nodo::setSig(Nodo* s) { sig = s; }
Nodo* Nodo::getSig() { return sig; }



string Nodo::toStringNodo() {
	return estu->toString();
}