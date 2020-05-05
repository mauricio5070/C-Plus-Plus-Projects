#include "Biblioteca.h"

Biblioteca::Biblioteca(string a) {
	nombre = a;
	listaPersonas = new ListaM();
	listaLibros = new ListaM();
	listaAlquilados = new ListaM();
}

Biblioteca::~Biblioteca(){ delete listaPersonas;  delete listaLibros;}

ListaM * Biblioteca::getListaPersonas(){ return listaPersonas; }

ListaM * Biblioteca::getListaLibros(){ return listaLibros; }
ListaM * Biblioteca::getListaAlquilados() { return listaAlquilados; }

string Biblioteca::toStringPersonas(){ return listaPersonas->toString(); } 

string Biblioteca::toStringLibros(){ return listaLibros->toString(); }

string Biblioteca::toStringAlquilados() { return listaAlquilados->toString2(); }






string Biblioteca::toStringBiblioteca()
{
	stringstream s;
	s << "Nombre del Instituto: " << nombre << endl << endl;
	s <<"\tLista de Personas:" <<endl<<listaPersonas->toString() << endl;
	s <<"\tLista de Libros:"<<endl<< listaLibros->toString();
	
	return s.str();
}

bool Biblioteca::agregarAlquiler(Alquilado* a) {
	if (listaAlquilados->agregar(a)) {
		return true;
	}
	else {
		return false;
	}
}

bool Biblioteca::agregarPersonas(Persona *p) {
	if (listaPersonas->agregar(p)) {
		return true;
	}
	else {
		return false;
	}
}

bool Biblioteca::agregarLibros(Libro *l) {
	if (listaLibros->agregar(l)) {
		return true;
	}
	else {
		return false;
	}
}



bool Biblioteca::eliminaPersona(string x)
{
	if (listaPersonas->elimina(x)) {
		return true;
	}
	else {
		return false;
	}
}

bool Biblioteca::eliminaLibro(string x)
{
	if (listaLibros->elimina(x)) {
		return true;
	}
	else {
		return false;
	}
}




void Biblioteca::guardar() {
	
	
	listaPersonas->guardarPersonas();
	listaLibros->guardarLibros();
	listaAlquilados->guardarAlquilados();
	
}

void Biblioteca::cargar() {
	listaPersonas->cargarPersonas();
	listaLibros->cargarLibros();
	listaAlquilados->cargarAlquilados();
	
}