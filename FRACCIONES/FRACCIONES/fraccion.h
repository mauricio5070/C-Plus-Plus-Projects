#include <string>
#include<sstream>
#ifndef FRACCION_H
#define FRACCION_H
#endif // !FRACCION_H
using namespace std;

class Fraccion
{
private:

	int numerador;
	int denominador;


public:
	Fraccion();
	void setNumerador(int);
	void setDenominador(int);
	int getNumerador();
	int getDenominador();
	~Fraccion();
};
