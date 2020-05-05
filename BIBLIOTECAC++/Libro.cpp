#include "Libro.h"

Libro::Libro(string a, string b):Molde(a,b){

 
}

Libro::~Libro()
{
}

string Libro::toString()
{
	stringstream s;
	s << "Nombre del libro: " << Molde::getNombre() << endl;
	s << "ID del libro: " << Molde::getID() << endl;
	
	return s.str();
       
}
