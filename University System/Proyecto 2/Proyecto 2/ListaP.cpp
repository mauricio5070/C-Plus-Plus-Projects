#include "ListaP.h"

ListaP::ListaP()
{
	pinicio = NULL;
	pactual = NULL;
}

bool ListaP::agregar(Persona * p)
{
	if(buscayRetorna(p->getCedula())!=NULL) {
		return false;                                //SI YA SE ENCUENTRA
	}

	pactual = new NodoP(p, NULL);
	if (pinicio == NULL)
	{
		pinicio = pactual;

		return true;
	}
	else
	{
		pactual->setSiguiente(pinicio);
		pinicio = pactual;

		return true;
	}
}

bool ListaP::elimina(string x)
{
	if (pinicio == NULL) {
		return false;
	}

	pactual = pinicio;

	if (pinicio->getPersona()->getCedula() == x) {
		pactual = pactual->getSiguiente();
		delete pinicio;
		pinicio= pactual;
		return true;
	}

	while ((pactual!=NULL)&& (pactual->getSiguiente()->getPersona()->getCedula()!= x) ) {
		pactual = pactual->getSiguiente();
	}

	if (pactual == NULL) {
		return false;
	}

	else {
		NodoP* aux;
		aux = pactual->getSiguiente();
		pactual->setSiguiente(aux->getSiguiente());
		delete aux;
		return true;
	}
	
}

string ListaP::toString()
{
	stringstream s;
	pactual = pinicio;

	while (pactual != NULL)
	{
		s << pactual->toStringNodo() << endl << endl;
		pactual = pactual->getSiguiente();
	}
	return s.str();
}

int ListaP::cantidadPersonas()
{
	int cont = 0;
	pactual = pinicio;
	while (pactual!=NULL) {
		cont++;
		pactual = pactual->getSiguiente();
	}
	return cont;
}

Persona * ListaP::buscayRetorna(string a)
{
	pactual = pinicio;
	while (pactual!=NULL) {
		if (pactual->getPersona()->getCedula()==a) {
			return pactual->getPersona();
		}
		pactual = pactual->getSiguiente();
	}
	return NULL;
}


ListaP::~ListaP() {
	while (pinicio != NULL) {
		pactual = pinicio;
		pinicio = pinicio->getSiguiente();
		delete pactual;
	}
}

void ListaP::guardarEstudiantes() {
	NodoP *p = pinicio;
	Persona *Per;
	ofstream Escribe("Estudiantes.txt", ios::out);
	while (p != NULL) {
		Per = p->getPersona();
		Per->guardarTxt(Escribe);
		p = p->getSiguiente();
	}
	Escribe.close();

}
void ListaP::guardarProfesores() {
	NodoP *p = pinicio;
	Persona *Per;
	ofstream Escribe("Profesores.txt", ios::out);
	while (p != NULL) {
		Per = p->getPersona();
		Per->guardarTxt(Escribe);
		p = p->getSiguiente();
	}
	Escribe.close();
}

void ListaP::cargarEstudiante() {
	ifstream Leer("Estudiantes.txt", ios::in);
	Persona *Per;
	Persona aux;
	Per = aux.leerTxt(Leer);
	while (!Leer.eof()) {
		agregar(Per);
		Per = aux.leerTxt(Leer);
	}
	Leer.close();
}
void ListaP::cargarProfesor() {
	ifstream Leer("Profesores.txt", ios::in);
	Persona *Per;
	Persona aux;
	Per = aux.leerTxt(Leer);
	while (!Leer.eof()) {
		agregar(Per);
		Per = aux.leerTxt(Leer);
	}
	Leer.close();
}