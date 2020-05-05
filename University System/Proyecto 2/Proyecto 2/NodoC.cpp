#include "NodoC.h"

NodoC::NodoC(Curso *a, NodoC *b) : Cur(a), Sig(b){}

NodoC::~NodoC() { delete Cur; }

void NodoC::setCurso(Curso* a) { Cur = a; }

void NodoC::setSig(NodoC *a) { Sig = a; }

Curso * NodoC::getCurso() { return Cur; }

NodoC* NodoC::getSig() { return Sig; }

string NodoC::toStringNodoC() {
	return Cur->toString();
}
