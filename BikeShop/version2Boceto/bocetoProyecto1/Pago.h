#pragma once
#include <sstream>
#include <iostream>
#include "Utiles.h"
using namespace std;

class Pago {
private:
	int Dia;
	int Mes;
	int Anio;
	char Estado;
	double Monto;
	int ID;
public:
	Pago(int, int, int, double,char,int);
	~Pago();
	string toString();
	string toStringConEstado();
	char getEstado();
	void setEstado(char);
	double getMonto();
	Pago* returnPago();
	int getDia();
	int getMes();
	int getAnio();
	int getId();
	static Pago* recuperarPagos(istream&);
	void guardarPagos(ostream&);
	void setDia(int);
	void setMes(int);
	void setAnio(int);
	//void setMonto(double);
};