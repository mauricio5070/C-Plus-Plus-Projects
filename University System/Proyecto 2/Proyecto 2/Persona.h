#ifndef PERSONA
#define PERSONA
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

class Persona {
protected:
	string nombre;
	string cedula;
	string telefono;
	
public:
	Persona(string, string, string);
	Persona();
	~Persona();
	void setNombre(string);
	void setCedula(string);
	void setTelefono(string);
	string getNombre();
	string getCedula();
	string getTelefono();
	virtual string toString();
	void guardarTxt(ofstream &);
	Persona *leerTxt(ifstream &);
};

#endif