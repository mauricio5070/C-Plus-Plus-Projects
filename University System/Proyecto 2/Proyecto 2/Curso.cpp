#include "Curso.h"

Curso::Curso(string a, string b)
{
	nombre = a;
	codigo = b;
	listaGrupos = new ListaG();
}
Curso::Curso() {
	nombre = "";
	codigo = "";
	
}

Curso::~Curso()
{
	delete listaGrupos;
}

void Curso::setNombre(string a)
{
	nombre = a;
}

void Curso::setCodigo(string a)
{
	codigo = a;
}

string Curso::getNombre()
{
	return nombre;
}

string Curso::getCodigo()
{
	return codigo;
}

int Curso::cantidadGrupos()
{
	return listaGrupos->cantidadGrupos();
}

ListaG * Curso::getListaGrupos()
{
	return listaGrupos;
}

bool Curso::agregarGrupo(Grupo* g)
{
	if (listaGrupos->agregar(g)) {
		return true; 
	}
	else { return false; }
}

string Curso::toStringGrupos()
{
	stringstream s;
	s << "\tNombre del curso: " << nombre << endl;
	if (cantidadGrupos() == 0) {
		s << "No hay grupos en este curso" << endl << endl;
	}
	else {
			s << listaGrupos->toString() << endl;
		}
	return s.str();
}

string Curso::toString()
{
	stringstream s;
	s << "\tInformacion del Curso" << endl;
	s << "Nombre del Curso: " << nombre << endl;
	s << "Codigo del Curso: " << codigo << endl;
	s << "Cantidad de grupos abiertos: " << cantidadGrupos() << endl << endl << endl;
	return s.str();
}

bool Curso::eliminarGrupo(string x)
{
	return listaGrupos->elimina(x);
}

string Curso::mostrarEstudiantesGrupo()
{
	return listaGrupos->mostrarEstudiantes();
}

Grupo* Curso::buscayRetornaGrupo(string x)
{
	return listaGrupos->buscayRetorna(x);
}

Persona * Curso::buscayRetornaEstu(string x)
{
	return listaGrupos->buscayRetornaEstu(x);
}

Persona * Curso::buscayRetornaProfe(string x)
{
	return listaGrupos->buscayRetornaProfe(x);
}


void Curso::guardarTxt(ofstream &Escribe) {
	Escribe << nombre << "\n";
	Escribe << codigo << "\n";


}

Curso* Curso::leerTxt(ifstream &Leer) {
	string a, b;
	Leer >> a;
	Leer >> b;


	return (new Curso(a, b));

}