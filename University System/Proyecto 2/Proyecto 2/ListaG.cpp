#include "ListaG.h"

ListaG::ListaG()
{
	pinicio = NULL;
	pactual = NULL;
}

ListaG::~ListaG()
{
	while (pinicio != NULL) {
		pactual = pinicio;
		pinicio = pinicio->getSig();
		delete pactual;
	}
}

bool ListaG::agregar(Grupo *g)
{
	if (buscayRetorna(g->getNRC())!=NULL) {
		return false;                         //SI YA SE ENCUENTRA
	}

	pactual = new NodoG(g, NULL);
	if (pinicio == NULL) {
		pinicio = pactual;
		return true;
	}
	else {
		pactual->setSig(pinicio);
		pinicio = pactual;
		return true;
	}
}

string ListaG::toString()
{
	stringstream s;
	pactual = pinicio;
	while (pactual != NULL) {
		s << pactual->toStringNodoG() << endl << endl;
		pactual = pactual->getSig();
	}
	return s.str();
}

string ListaG::mostrarEstudiantes()
{
	stringstream s;
	pactual = pinicio;
	while (pactual!=NULL) {
		s << pactual->getGrupo()->toStringEstudiantes();
		pactual = pactual->getSig();
	}
	return s.str();
}

int ListaG::cantidadGrupos()
{
	int cont = 0;
	pactual = pinicio;
	while (pactual != NULL) {
		cont++;
		pactual = pactual->getSig();
	}
	return cont;
}

bool ListaG::elimina(string x)
{
	if (pinicio == NULL) {
		return false;
	}

	pactual = pinicio;

	if (pinicio->getGrupo()->getNRC() == x) {
		pactual = pactual->getSig();
		delete pinicio;
		pinicio = pactual;
		return true;
	}

	while ((pactual != NULL) && (pactual->getSig()->getGrupo()->getNRC() != x)) {
		pactual = pactual->getSig();
	}

	if (pactual == NULL) {
		return false;
	}

	else {
		NodoG* aux;
		aux = pactual->getSig();
		pactual->setSig(aux->getSig());
		delete aux;
		return true;
	}
}

Grupo * ListaG::buscayRetorna(string n)
{
	pactual = pinicio;
	while (pactual!=NULL) {
		if (pactual->getGrupo()->getNRC()==n) {
			return pactual->getGrupo();
		}
		pactual = pactual->getSig();
	}
	return NULL;
}

Persona * ListaG::buscayRetornaEstu(string x)
{
	pactual = pinicio;
	while (pactual!=NULL) {
		if (pactual->getGrupo()->getlistaEstudiantes()->buscayRetorna(x)!=NULL) {
			return pactual->getGrupo()->getlistaEstudiantes()->buscayRetorna(x);
		}
		pactual = pactual->getSig();
	}
	return NULL;
}

Persona * ListaG::buscayRetornaProfe(string x)
{
	pactual = pinicio;
	while (pactual != NULL) {
		if (pactual->getGrupo()->getProfesor()->getCedula()== x) {
			return pactual->getGrupo()->getProfesor();
		}
		pactual = pactual->getSig();
	}
	return NULL;
}
