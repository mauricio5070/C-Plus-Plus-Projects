#include "Nodo.h"
Nodo::Nodo(Estudiante* e, Nodo* s) {
	est= e;
	sig = s;

}

Nodo::~Nodo() {

	delete est;
}

void Nodo::setEstudiante(Estudiante *e) {

	est = e;
}

Estudiante* Nodo::getEstudiante() {
	return est;
}

void Nodo::setSig(Nodo *s) {
	sig = s;
}
Nodo* Nodo::getSig() {
	return sig;
}

string Nodo::toStringNodo() {

	return est->toString();

}