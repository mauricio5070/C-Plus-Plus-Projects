#pragma once
#pragma once
#include"Moto.h"
#include <sstream>

class MotoHarley : public Moto {
private:
	string marca;
	int cilindraje;
	int estilo;
	int modelo;
	double precio;
	string placa;
	int numSerie;
	int Mar;
public:
	MotoHarley(int,int,int,int,string);
	 ~MotoHarley();
	 string toString();
	string getMarca();
	int getCilindraje();
	int getEstilo();
	int getModelo();
	double getPrecio();
	string getPlaca();
	int getNumSerie();
	int getMar();

	void setPrecio(MotoHarley *);
};