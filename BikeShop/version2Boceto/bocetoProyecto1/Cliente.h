#pragma once
#include <iostream>
#include <sstream>
#include "Moto.h"
#include "Utiles.h"
using namespace std;

class Cliente {
private:
	int Cedula;
	string Nombre;
	string Apellidos;
	int AnioNacimiento;
	int  NivelCrediticio;
	
public:
	Cliente(int, string, string, int);
	Cliente();
	~Cliente();
	int getCedula();
	string getNombre();
	string getApellidos();
	int getAnioNacimiento();
	int getNivelCrediticio();
	string toString();
	static Cliente* recuperarCliente(istream&);
};