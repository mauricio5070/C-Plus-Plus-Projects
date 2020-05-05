#include "Instituto.h"

Instituto::Instituto(string a) {
	nombre = a;
	listaProfes = new ListaP();
	listaEstudiantes = new ListaP();
	listaCursos = new ListaC();
}

Instituto::~Instituto(){ delete listaProfes;  delete listaEstudiantes; delete listaCursos;}

ListaP * Instituto::getListaProfes(){ return listaProfes; }

ListaP * Instituto::getListaEstudiantes(){ return listaEstudiantes; }

ListaC * Instituto::getListaCursos() { return listaCursos; }

string Instituto::toStringProfes(){ return listaProfes->toString(); } 

string Instituto::toStringEstudiantes(){ return listaEstudiantes->toString(); }

string Instituto::toStringCursos(){ return listaCursos->toString(); }

string Instituto::toStringGrupos()
{
	return listaCursos->mostrarGrupos();
}

string Instituto::toStringInstituto()
{
	stringstream s;
	s << "Nombre del Instituto: " << nombre << endl << endl;
	s <<"\tLista de Profesores:" <<endl<<listaProfes->toString() << endl;
	s <<"\tLista de Estudiantes:"<<endl<< listaEstudiantes->toString();
	s <<"\tLista de Cursos:"<<endl<<listaCursos->toString() << endl;
	return s.str();
}

bool Instituto::agregarEstudiante(Estudiante *e) {
	if (listaEstudiantes->agregar(e)) {
		return true;
	}
	else {
		return false;
	}
}

bool Instituto::agregarProfesores(Profesor *p) {
	if (listaProfes->agregar(p)) {
		return true;
	}
	else {
		return false;
	}
}

bool Instituto::agregarCurso(Curso* c) {
	if (listaCursos->agregar(c)) {
		return true;
	}
	else {
		return false;
	}
}

bool Instituto::eliminaEstudiante(string x)
{
	if (listaEstudiantes->elimina(x)) {
		return true;
	}
	else {
		return false;
	}
}

bool Instituto::eliminaProfesor(string x)
{
	if (listaProfes->elimina(x)) {
		return true;
	}
	else {
		return false;
	}
}

bool Instituto::eliminaCurso(string x)
{
	if (listaCursos->elimina(x)) {
		return true;
	}
	else {
		return false;
	}
}


void Instituto::guardar() {
	
	
	listaEstudiantes->guardarEstudiantes();
	listaProfes->guardarProfesores();
	listaCursos->guardarCurso();
}

void Instituto::cargar() {
	listaEstudiantes->cargarEstudiante();
	listaProfes->cargarProfesor();
	listaCursos->cargarCurso();
}