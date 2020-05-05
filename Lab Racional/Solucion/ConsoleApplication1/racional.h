
#ifndef RACIONAL_H
#define RACIONAL_H

#include<iostream>
#include<sstream>
using namespace std;

class racional {
private:
	int numerador;
	int denominador;

public:
	racional(int = 0, int = 1);
	int getNumerador();
	int getDenominador();
	string toString();
	static int mcd(int, int);// si un metodo es static, puede ser utilizado sin necesidad de un objeto
	static void simplificar(racional&);// si un metodo es static, puede ser utilizado sin necesidad de un objeto
	racional sumar(racional);
	racional restar(racional);
	racional multiplicar(racional);
	racional dividir(racional);
	bool equivalente(racional);
	int elevaNumero(int, int);
	void elevaFraccionAla(int);
};
#endif /* RACIONAL_H */