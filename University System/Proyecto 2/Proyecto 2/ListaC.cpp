#include "ListaC.h"

ListaC::ListaC()
{
	pinicio = NULL;
	pactual = NULL;
}

bool ListaC::agregar(Curso *c)
{
	if (buscayRetorna(c->getCodigo())!=NULL) {   //SI YA SE ENCUENTRA
		return false;
	}

	pactual = new NodoC(c, NULL);
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

bool ListaC::elimina(string x)
{
	if (pinicio == NULL) {
		return false;
	}

	pactual = pinicio;

	if (pinicio->getCurso()->getCodigo() == x) {
		pactual = pactual->getSig();
		delete pinicio;
		pinicio = pactual;
		return true;
	}

	while ((pactual != NULL) && (pactual->getSig()->getCurso()->getCodigo() != x)) {
		pactual = pactual->getSig();
	}

	if (pactual == NULL) {
		return false;
	}

	else {
		NodoC* aux;
		aux = pactual->getSig();
		pactual->setSig(aux->getSig());
		delete aux;
		return true;
	}
}

Curso * ListaC::buscayRetorna(string x)
{
	pactual = pinicio;
	while (pactual != NULL) {
		if (pactual->getCurso()->getCodigo() == x) {
			return pactual->getCurso();
		}
		pactual = pactual->getSig();
	}
	return NULL;
}

string ListaC::toString()
{
	stringstream s;
	pactual = pinicio;
	while (pactual != NULL) {
		s << pactual->toStringNodoC();
		pactual = pactual->getSig();
	}
	return s.str();
}

ListaC::~ListaC()
{
	while (pinicio != NULL) {
		pactual = pinicio;
		pinicio = pinicio->getSig();
		delete pactual;
	}
}

void ListaC::guardarCurso() {
	NodoC *c = pinicio;
	Curso *Cur;
	ofstream Escribe("Cursos.txt", ios::out);
	while (c != NULL) {
		Cur = c->getCurso();
		Cur->guardarTxt(Escribe);
		c = c->getSig();
	}
	Escribe.close();
}

void ListaC::cargarCurso() {
	ifstream Leer("Cursos.txt", ios::in);
	Curso *Cur;
	Curso aux;
	Cur = aux.leerTxt(Leer);
	while (!Leer.eof()) {
		agregar(Cur);
		Cur = aux.leerTxt(Leer);
	}
	Leer.close();
}

bool ListaC::eliminaGrupo(string x)
{
	pactual = pinicio;
	while (pactual!=NULL) {
		if (pactual->getCurso()->eliminarGrupo(x)) {
			return true;
		}
		pactual = pactual->getSig();
	}
	return false;
}

Grupo* ListaC::buscayRetornaGrupo(string x)
{
	pactual = pinicio;
	while (pactual!=NULL) {
		if (pactual->getCurso()->buscayRetornaGrupo(x)) {
			return pactual->getCurso()->buscayRetornaGrupo(x);
		}
		pactual = pactual->getSig();
	}
	return NULL;
}

int ListaC::cantidadGrupos()
{
	int cont = 0;
	pactual = pinicio;
	while (pactual!=NULL) {
		cont+=pactual->getCurso()->cantidadGrupos();
		pactual = pactual->getSig();
	}
	return cont;
}

string ListaC::mostrarGrupos()
{
	stringstream s;
	pactual = pinicio;
	while (pactual!=NULL) {
		s << pactual->getCurso()->toStringGrupos();
		pactual = pactual->getSig();
	}
	return s.str();
}

string ListaC::mostrarEstudiantesGrupos()
{
	stringstream s;
	pactual = pinicio;
	while (pactual!=NULL) {
		s << pactual->getCurso()->mostrarEstudiantesGrupo();
		pactual = pactual->getSig();
	}
	return s.str();
}

string ListaC::cursosPorEstudiante(string x)
{
	stringstream s;
	pactual = pinicio;
	while (pactual!=NULL) {
		if (pactual->getCurso()->buscayRetornaEstu(x)!=NULL) {
			s << "Nombre del curso : " << pactual->getCurso()->getNombre() << endl;
			s << "Codigo del curso : " << pactual->getCurso()->getCodigo() << endl << endl;
		}
		pactual = pactual->getSig();
	}
	return s.str();
}

string ListaC::cursosPorProfesor(string x)
{
	stringstream s;
	pactual = pinicio;
	while (pactual != NULL) {
		if (pactual->getCurso()->buscayRetornaProfe(x) != NULL) {
			s << "Nombre del curso : " << pactual->getCurso()->getNombre() << endl;
			s << "Codigo del curso : " << pactual->getCurso()->getCodigo() << endl << endl;
		}
		pactual = pactual->getSig();
	}
	return s.str();
}

int ListaC::cantidadCursos()
{
	int cont = 0;
	pactual = pinicio;
	while (pactual != NULL) {
		cont++;
		pactual = pactual->getSig();
	}
	return cont;
}