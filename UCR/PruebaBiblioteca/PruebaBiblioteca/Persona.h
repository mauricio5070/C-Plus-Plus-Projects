

#ifndef PERSONA_H
#define PERSONA_H

#include "Molde.h"

class Persona:public Molde  {
public:
	Persona(string="-", string="-");
	~Persona();
	string toString();
};


#endif /* PERSONA_H */

