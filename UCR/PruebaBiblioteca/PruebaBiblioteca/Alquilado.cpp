#include "Alquilado.h"

Alquilado::Alquilado(string a, string b) :Molde(a, b) {}

Alquilado::~Alquilado()
{
}

string Alquilado::toString()
{
	stringstream s;
	s << "Nombre de la Persona: " << Molde::getNombre() << endl;
	s << "Nombre del Libro: " << Molde::getNombre() << endl;

	return s.str();
}