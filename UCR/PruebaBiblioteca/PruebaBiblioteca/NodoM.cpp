#include "NodoM.h"

NodoM::NodoM(Molde *mol, NodoM *sig) {
	Mol = mol;
	Sig = sig;
}
void NodoM::setMolde(Molde* mol) {
	Mol = mol;
}
Molde* NodoM::getMolde() {
	return Mol;
}
void NodoM::setSiguiente(NodoM* sig) {
	Sig = sig;
}
NodoM* NodoM::getSiguiente() {

	return Sig;
}

string NodoM::toStringNodo() {
	return Mol->toString();
}
string NodoM::toStringNodo2() {
	return Mol->toString2();
}
NodoM::~NodoM() { delete Mol; }