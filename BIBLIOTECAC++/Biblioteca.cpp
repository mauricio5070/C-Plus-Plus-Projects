
#include "Biblioteca.h"

Biblioteca::Biblioteca(string a) {
	nombre = "Carlos Monge";
	listaPersonas = new ListaM();
	listaLibros = new ListaM();
	
}

Biblioteca::~Biblioteca(){ delete listaPersonas;  delete listaLibros;}

ListaM * Biblioteca::getListaPersonas(){ return listaPersonas;}

ListaM * Biblioteca::getListaLibros(){ return listaLibros; }


string Biblioteca::toStringPersonas(){ return listaPersonas->toString(); } 

string Biblioteca::toStringLibros(){ return listaLibros->toString(); }





string Biblioteca::toStringBiblioteca()
{
	stringstream s;
	s << "Nombre de la Biblioteca: " << nombre << endl << endl;
	s <<"\tLista de Personas:" <<endl<<listaPersonas->toString() << endl;
	s <<"\tLista de Libros:"<<endl<< listaLibros->toString();
	
	return s.str();
}

bool Biblioteca::agregarPersonas(Persona *p) {
	if (listaPersonas->agregar(p)) {
		return true;
	}
	else {
		return false;
	}
}

bool Biblioteca::agregarLibros(Libro* l) {
	if (listaLibros->agregar(l)) {
		return true;
                cout<<"se esta agregando el libro de forma correcta"<<endl;
	}
	else {
		return false;
                cout<<"se esta agregando el libro de forma incorrecta"<<endl;
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
	
}

void Biblioteca::cargar() {
	listaPersonas->cargarPersonas();
	listaLibros->cargarLibros();
	
}