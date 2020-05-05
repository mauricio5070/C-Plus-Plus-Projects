#ifndef ESTUDIANTE
#define ESTUDIANTE
#include "Persona.h"

class Estudiante :public Persona {
public:
	Estudiante(string="-", string="-", string="-");
	~Estudiante();
	string toString();
};
#endif
