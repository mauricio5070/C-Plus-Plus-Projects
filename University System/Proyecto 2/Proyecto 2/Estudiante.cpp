#include "Estudiante.h"

Estudiante::Estudiante(string a, string b, string c): Persona(a,b,c){}

Estudiante::~Estudiante()
{
}

string Estudiante::toString()
{
	stringstream s;
	s << "Nombre del Estudiante: " << nombre << endl;
	s << "Cedula del Estudiante: " << cedula << endl;
	s << "Telefono del Estudiante:" << telefono << endl;
	return s.str();
}
