#ifndef ALQUILADO
#define ALQUILADO
#include <iostream>
#include <string>
#include <sstream>
#include "Persona.h"
#include "Libro.h"
#include "ListaM.h"
#include "Molde.h"

using namespace std;

class Alquilado : public Molde {
public:
	Alquilado(string = "-", string = "-");
	~Alquilado();
	string toString();


};
#endif