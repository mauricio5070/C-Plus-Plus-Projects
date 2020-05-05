#pragma once
#include<iostream>
#include<sstream>
using namespace std;

class Persona {
private:
	string cedula;
	string nombre;
	string apellido;
	int edad;
public:
	Persona();
	Persona(string, string, string, int);
	Persona(Persona& pc);
	~Persona();
	string toString();
	friend ostream&  operator << (ostream& out, Persona& p);
	Persona& operator = (Persona&);
};
// Definición de los métodos de la clase Persona..

Persona::Persona() {
	cedula = "Indef";
	nombre = "Indef";
	apellido = "Indef";
	edad = 0;
}
Persona::Persona(string ced, string nom, string ape, int ed) {
	cedula = ced;
	nombre = nom;
	apellido = ape;
	edad = ed;
}

Persona::Persona(Persona& pc) {
	this->cedula = pc.cedula;
	this->nombre = pc.nombre;
	this->apellido = pc.apellido;
	this->edad = pc.edad;
}

Persona::~Persona() {
	cout << "Eliminando Persona.." << endl;
}

string Persona::toString() {
	stringstream s;
	s << "Cedula...." << cedula << endl
		<< "Nombre..." << nombre << endl
		<< "Apellido.." << apellido << endl
		<< "Edad......" << edad << endl << endl;
	return s.str();
}

ostream& operator << (ostream& out, Persona& p) {
	return out << p.toString();
}

Persona& Persona::operator = (Persona& p) {
	Persona* per = new Persona(p.cedula, p.nombre, p.apellido, p.edad);
	return *per;
}
