#ifndef PROFESOR
#define PROFESOR
#include "Persona.h"

class Profesor:public Persona  {
public:
	Profesor(string="-", string="-", string="-");
	~Profesor();
	string toString();
};
#endif