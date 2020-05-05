#ifndef INTERFAZ
#define INTERFAZ
#include <iostream>
#include <string>
using namespace std;

class Interfaz {
public:
	string retornaString();
	string retornaStringIgnore();
	string retornaStringGetLine();
	void imprimeString(string);
	int retornaInt();
	void imprimeInt(int);
};

#endif