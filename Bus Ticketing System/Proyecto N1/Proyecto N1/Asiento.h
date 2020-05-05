#ifndef ASIENTO
#define ASIENTO

#include <iostream>
#include <sstream>
using namespace std;

class Asiento {
private:
	char letra;
	int numero;
	char estado;   //Ocupado o Disponible

public:
	Asiento(char = '-', int = 0, char = '-');
	string toString();
	int getNumero();
	void setEstado(char);
	string getEstado();
	~Asiento();

};

#endif