#pragma once
#include <iostream>
#include <string>
using namespace std;

class Persona {
private:
	string cedula;
	string apellidos;
	string nombre;
	int edad;
	double estatura;
public:
	Persona(string, string, string, int, double);
	static Persona recuperar(istream&);
	virtual void guardar(ostream&);
	virtual string toString();
};