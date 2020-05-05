#include "NodoP.h"

NodoP::NodoP(Persona *per, NodoP *sig) {
	Per = per;
	Sig = sig;
}
void NodoP::setPersona(Persona* per) {
	Per = per;
}
Persona* NodoP::getPersona() {
	return Per;
}
void NodoP::setSiguiente(NodoP* sig) {
	Sig = sig;
}
NodoP* NodoP::getSiguiente() {

	return Sig;
}

string NodoP::toStringNodo() {
	return Per->toString();
}

NodoP::~NodoP() { delete Per; }