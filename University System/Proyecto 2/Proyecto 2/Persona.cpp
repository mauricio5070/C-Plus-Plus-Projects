#include "Persona.h"

Persona::Persona(string a, string b, string c)
{
	nombre = a;
	cedula = b;
	telefono = c;
}
Persona::Persona() {
	nombre = "";
	cedula = "";
	telefono="";
}

Persona::~Persona()
{
}

void Persona::setNombre(string a)
{
	nombre = a;
}

void Persona::setCedula(string a)
{
	cedula = a;
}

void Persona::setTelefono(string a)
{
	telefono = a;
}

string Persona::getNombre()
{
	return nombre;
}

string Persona::getCedula()
{
	return cedula;
}

string Persona::getTelefono()
{
	return telefono;
}

string Persona::toString()
{
	stringstream s;
	s << "Nombre: " << nombre << endl;
	s << "Cedula: " << cedula << endl;
	s << "Telefono: " << telefono << endl;
	return s.str();
}


void Persona::guardarTxt(ofstream &Escribe) {
	Escribe << nombre << "\n";
	Escribe << cedula << "\n";
	Escribe << telefono << "\n";

}

Persona* Persona::leerTxt(ifstream &Leer) {
	string a, b, c;
	Leer >> a;
	Leer >> b;
	Leer >> c;

	return (new Persona(a, b, c));

}