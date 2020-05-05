#include "Persona.h"

Persona::Persona(string a, string b):Molde(a,b){}

Persona::~Persona()
{
}

string Persona::toString()
{
	stringstream s;
	s << "Nombre de la persona: " <<    Molde::getNombre() << endl;
	s << "ID de la persona: " << Molde::getID() << endl;
	
	return s.str();
}
