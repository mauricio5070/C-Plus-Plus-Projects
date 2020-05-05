#include "Grupo.h"

Grupo::Grupo(Persona *a, string b, string c, int d, int e): prof(a), horario(b), nrc(c), cupo(d), aula(e){
	listaEstudiantes = new ListaP();
	prof = a;
	horario = b;
	nrc = c;
	cupo = d;
	aula = e;
}

Grupo::~Grupo()
{
}

void Grupo::setProfesor(Persona *a) { prof = a; }

void Grupo::setHorario(string a) { horario = a; }

void Grupo::setNRC(string a) { nrc = a; }

void Grupo::setCupo(int a) { cupo = a; }

void Grupo::setAula(int a) { aula = a; }

Persona * Grupo::getProfesor() { return prof; }

ListaP * Grupo::getlistaEstudiantes()
{
	return listaEstudiantes;
}

string Grupo::getHorario() { return horario; }

string Grupo::getNRC() { return nrc; }

int Grupo::getCupo() { return cupo; }

int Grupo::getAula() { return aula; }

string Grupo::toString() {
	stringstream s;
	s << "\tGrupo" << endl;
	s << "Informacion del Profesor:" << endl;
	s << prof->toString();
	s << "Horario del Grupo: " << horario << endl;
	s << "NRC del Grupo: " << nrc << endl;
	s << "Cupo del Grupo: " << cupo << endl;
	s << "Aula: " << aula << endl;
	s << "Cantidad de estudiantes en el grupo: " << cantidadEstudiantes() << endl;
	return s.str();
}

string Grupo::toStringEstudiantes()
{
	stringstream s;
	s << toString() << endl;
	if (listaEstudiantes->cantidadPersonas()>0) {
		s << "\tLista de estudiantes:\n";
		s << listaEstudiantes->toString() << endl;
	}
	return s.str();
}

int Grupo::cantidadEstudiantes()
{
	return listaEstudiantes->cantidadPersonas();
}

bool Grupo::agregarEstudiante(Persona *a)
{
	if ((cupo > cantidadEstudiantes())&&(listaEstudiantes->buscayRetorna(a->getCedula())==NULL)) {
		listaEstudiantes->agregar(a);
		return true;
	}
	else {
		return false;
	}
}


