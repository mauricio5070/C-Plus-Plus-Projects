
#pragma once
#include"Moto.h"
#include <sstream>

class MotoYamaha : public Moto {
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
	MotoYamaha(int, int, int, int, string);
	~MotoYamaha();
	string toString();
	string getMarca();
	int getCilindraje();
	int getEstilo();
	int getModelo();
	double getPrecio();
	void setPrecio(MotoYamaha *);
	string getPlaca();
	int getNumSerie();
	int getMar();
};