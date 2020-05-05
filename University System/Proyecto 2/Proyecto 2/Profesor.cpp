#include "Profesor.h"

Profesor::Profesor(string a, string b, string c):Persona(a,b,c){}

Profesor::~Profesor()
{
}

string Profesor::toString()
{
	stringstream s;
	s << "Nombre del Profesor: " << Persona::getNombre() << endl;
	s << "Cedula del Profesor: " << Persona::getCedula() << endl;
	s << "Telefono del profesor: " << Persona::getTelefono() << endl;
	return s.str();
}
