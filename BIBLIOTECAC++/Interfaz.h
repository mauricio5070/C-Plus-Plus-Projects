
#ifndef INTERFAZ_H
#define INTERFAZ_H

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

class Interfaz {
public:
	string retornaString();
	void imprimeString(string);
	int retornaInt();
	void imprimeInt(int);
};

#endif /* INTERFAZ_H */

