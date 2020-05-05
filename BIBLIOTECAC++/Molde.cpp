#include "Molde.h"

Molde::Molde(string a, string b)
{
	nombre = a;
	ID = b;
        
	
}
Molde::Molde() {
	nombre = "";
	ID = "";
	
}

Molde::~Molde()
{
}

void Molde::setNombre(string a)
{
	nombre = a;
}

void Molde::setID(string a)
{
	ID = a;
}



string Molde::getNombre()
{
	return nombre;
}

string Molde::getID()
{
	return ID;
}



string Molde::toString()
{
	stringstream s;
	s << "Nombre: " << nombre << endl;
	s << "ID: " << ID << endl;
	return s.str();
}


void Molde::guardarTxt(ofstream &Escribe) {
	Escribe << nombre << "\n";
	Escribe << ID << "\n";
	

}

Molde* Molde::leerTxt(ifstream &Leer) {
	string a, b;
	
        Leer >> a;
	Leer >> b;
	
        
	return (new Molde(a,b));

}