#pragma once
#pragma once
#include<string>
#include<sstream>
using namespace std;

class Moto {
protected:
	string marca;
	int cilindraje;
	int estilo;
	int modelo;
	double precio;
	string placa;
	int numSerie;

public:
	virtual ~Moto(){};
	virtual string toString() = 0;
	virtual double getPrecio() = 0;
	virtual int getCilindraje() = 0;
	virtual int getEstilo() = 0;
	virtual int getModelo()=0;
	virtual int getMar() = 0;
	virtual int getNumSerie() = 0;
	virtual string getPlaca() = 0;


};