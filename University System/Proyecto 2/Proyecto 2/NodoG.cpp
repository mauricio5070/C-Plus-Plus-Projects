#include "NodoG.h"

NodoG::NodoG(Grupo *a, NodoG *b)
{
	Grup = a;
	Sig = b;
}

NodoG::~NodoG()
{
	delete Grup;
}

void NodoG::setGrupo(Grupo *a)
{
	Grup = a;
}

void NodoG::setSig(NodoG *a)
{
	Sig = a;
}

Grupo * NodoG::getGrupo()
{
	return Grup;
}

NodoG * NodoG::getSig()
{
	return Sig;
}

string NodoG::toStringNodoG()
{
	return Grup->toString();
}
