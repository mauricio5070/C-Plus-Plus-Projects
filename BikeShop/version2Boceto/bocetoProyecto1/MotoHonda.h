
#pragma once
#include"Moto.h"
#include <sstream>

class MotoHonda : public Moto {
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
	MotoHonda(int, int, int, int, string);
	~MotoHonda();
	string toString();
	string getMarca();
	int getCilindraje();
	int getEstilo();
	int getModelo();
	double getPrecio();
	void setPrecio(MotoHonda *);
	string getPlaca();
	int getNumSerie();
	int getMar();
};