#include "ListaM.h"

ListaM::ListaM()
{
	pinicio = NULL;
	pactual = NULL;
}


bool ListaM::agregar(Molde * m)
{
	if(buscayRetorna(m->getID())!=NULL) {
		return false;                                //SI YA SE ENCUENTRA
	}

	pactual = new NodoM(m, NULL);
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
bool ListaM::alquilar(Molde * m)
{
	if (buscayRetorna(m->getNombre()) != NULL) {
		return false;                                //SI YA SE ENCUENTRA
	}

	pactual = new NodoM(m, NULL);
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

bool ListaM::elimina(string x)
{
	if (pinicio == NULL) {
		return false;
	}

	pactual = pinicio;

	if (pinicio->getMolde()->getID() == x) {
		pactual = pactual->getSiguiente();
		delete pinicio;
		pinicio= pactual;
		return true;
	}

	while ((pactual!=NULL)&& (pactual->getSiguiente()->getMolde()->getID()!= x) ) {
		pactual = pactual->getSiguiente();
	}

	if (pactual == NULL) {
		return false;
	}

	else {
		NodoM* aux;
		aux = pactual->getSiguiente();
		pactual->setSiguiente(aux->getSiguiente());
		delete aux;
		return true;
	}
	
}















string ListaM::toString()
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
string ListaM::toString2()
{
	stringstream s;
	pactual = pinicio;

	while (pactual != NULL)
	{
		s << pactual->toStringNodo2() << endl << endl;
		pactual = pactual->getSiguiente();
	}
	return s.str();
}

int ListaM::cantidadMoldes()
{
	int cont = 0;
	pactual = pinicio;
	while (pactual!=NULL) {
		cont++;
		pactual = pactual->getSiguiente();
	}
	return cont;
}

Molde * ListaM::buscayRetorna(string a)
{
	pactual = pinicio;
	while (pactual!=NULL) {
		if (pactual->getMolde()->getID()==a) {
			return pactual->getMolde();
		}
		pactual = pactual->getSiguiente();
	}
	return NULL;
}
Molde * ListaM::buscayRetorna2(string a)
{
	pactual = pinicio;
	while (pactual != NULL) {
		if (pactual->getMolde()->getNombre() == a) {
			return pactual->getMolde();
		}
		pactual = pactual->getSiguiente();
	}
	return NULL;
}


ListaM::~ListaM() {
	while (pinicio != NULL) {
		pactual = pinicio;
		pinicio = pinicio->getSiguiente();
		delete pactual;
	}
}

void ListaM::guardarPersonas() {
	NodoM *m = pinicio;
	Molde *Mol;
	ofstream Escribe("Personas.txt", ios::out);
	while (m != NULL) {
		Mol = m->getMolde();
		Mol->guardarTxt(Escribe);
		m = m->getSiguiente();
	}
	Escribe.close();

}
void ListaM::guardarLibros() {
	NodoM *m = pinicio;
	Molde *Mol;
	ofstream Escribe("Libros.txt", ios::out);
	while (m != NULL) {
		Mol = m->getMolde();
		Mol->guardarTxt(Escribe);
		m = m->getSiguiente();
	}
	Escribe.close();
}
void ListaM::guardarAlquilados() {
	NodoM *m = pinicio;
	Molde *Mol;
	ofstream Escribe("Alquilados.txt", ios::out);
	while (m != NULL) {
		Mol = m->getMolde();
		Mol->guardarTxt(Escribe);
		m = m->getSiguiente();
	}
	Escribe.close();
}

void ListaM::cargarPersonas() {
	ifstream Leer("Personas.txt", ios::in);
	Molde *Mol;
	Molde aux;
	Mol = aux.leerTxt(Leer);
	while (!Leer.eof()) {
		agregar(Mol);
		Mol = aux.leerTxt(Leer);
	}
	Leer.close();
}
void ListaM::cargarLibros() {
	ifstream Leer("Libros.txt", ios::in);
	Molde *Mol;
	Molde aux;
	Mol = aux.leerTxt(Leer);
	while (!Leer.eof()) {
		agregar(Mol);
		Mol = aux.leerTxt(Leer);
	}
	Leer.close();
}
void ListaM::cargarAlquilados() {
	ifstream Leer("Alquilados.txt", ios::in);
	Molde *Mol;
	Molde aux;
	Mol = aux.leerTxt(Leer);
	while (!Leer.eof()) {
		agregar(Mol);
		Mol = aux.leerTxt(Leer);
	}
	Leer.close();
}