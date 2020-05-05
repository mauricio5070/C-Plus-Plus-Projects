

#include "Lista.h"

Lista::Lista() {
	pinicio = NULL;
	pactual= NULL;
}


void Lista::insertarInicio(Estudiante * e)
{
	pactual = pinicio;
	if (pinicio == NULL)
	{
		pactual = new Nodo(e, pinicio);
	}
	else
	{
		pactual = pinicio;
		while (pactual->getSig() != NULL) {
			pactual = pactual->getSig();
		}
		pactual->setSig(new Nodo(e, NULL));
	}
}


/*void Lista::insertarInicio(Estudiante * e)
{
	pactual = new Nodo(e, NULL);
	if (pinicio == NULL)
	{
		pinicio = pactual;
	}
	else
	{
		pactual->setSig(pinicio);
		pinicio = pactual;
	}
}
*/


string Lista::toString()
{
	stringstream s;
	pactual = pinicio;

	while (pactual != NULL)
	{
		s << pactual->toStringNodo();
		pactual = pactual->getSig();
	}
	return s.str();
}

void Lista::elUltimo() {
	pactual = pinicio;

		while (pactual->getSig() != NULL)
		{
			pactual = pactual->getSig();
		}

}


bool Lista::encontrado(int id) {
	
	pactual = pinicio;
	while (pactual != NULL)
	{
		if (pactual->getEstu()->getId() == id) { return true; }
		pactual = pactual->getSig();
	}
	return false;
}


bool Lista::eliminarEspecifico(int x) { //Busca por id, y elimina ese nodo
	Nodo * paux;
	pactual = pinicio;

	if (pinicio == NULL)//Si  la lista esta vacia
	{
		return false;
	}

	if (pinicio->getEstu()->getId() == x) // si es el primero
	{
		pactual = pactual ->getSig();
		delete (pinicio);
		pinicio = pactual;
		return true;
	}

//Si no es el primero, hay que avanzar para buscarlo
while (pactual != NULL &&   pactual->getSig()->getEstu()->getId() != x) {
	pactual = pactual->getSig();
}

	if (pactual == NULL) { return false; }//Si no lo encontro	
	else {// el nodo fue encontrado
		paux = pactual->getSig();
		pactual->setSig(paux->getSig());
		delete paux;
		return true;
	}
}


float Lista::promedio() {
	pactual = pinicio;
	int suma = 0;
	int con = 0;
	while (pactual != NULL)
	{
		con++;
		suma = suma + pactual->getEstu()->getNota();
		pactual = pactual->getSig();
	}
	return suma / con;
}



Lista::~Lista() {
	while (pinicio != NULL) { // voy eliminando siempre el primero
		pactual = pinicio;
		pinicio = pinicio->getSig();
		delete pactual;
	}
}




bool Lista::eliminaInicio() {
	if (pinicio == NULL) 
	{
		return false;
	}
	else
	{
		pactual = pinicio;
		pinicio = pinicio->getSig();
		delete pactual;
	}
}


int Lista::cuentaNodos() {
	pactual = pinicio;
	int can = 0;

	while (pactual != NULL)
	{
		can++;
		pactual = pactual->getSig();
	}
	return can;
}

void Lista::eliminaFinal() {
	if (pinicio != NULL && pinicio->getSig() == NULL) {
		delete pinicio;
		pinicio = NULL;
	}
	else {
		pactual = pinicio;
		while (pactual->getSig()->getSig() != NULL) {
			pactual = pactual->getSig();
		}
		delete pactual->getSig();
		pactual->setSig(NULL);
	}
}