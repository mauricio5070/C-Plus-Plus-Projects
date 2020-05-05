

#ifndef LIBRO_H
#define LIBRO_H

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

#include "Molde.h"

class Libro:public Molde  {
public:
	Libro(string="-", string="-");
	~Libro();
	string toString();
};

#endif /* LIBRO_H */

