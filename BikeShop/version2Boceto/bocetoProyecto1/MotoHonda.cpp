#include "MotoHonda.h"

MotoHonda::MotoHonda(int cil, int est, int mod, int num, string pla)
{
	marca = "Honda";
	cilindraje = cil;
	estilo = est;
	modelo = mod;
	numSerie = num;
	placa = pla;
	precio = 100000;
	this->setPrecio(this);
	Mar = 2;
}

MotoHonda::~MotoHonda()
{
}

string MotoHonda::toString()
{
	stringstream s;
	//-----------------------------cilindraje----------------------------
	if (getCilindraje() == 1) {
		s << "Cilindraje: 125cc" << endl;
	}
	if (getCilindraje() == 2) {
		s << "Cilindraje: 150cc" << endl;
	}
	if (getCilindraje() == 3) {
		s << "Cilindraje: 200cc" << endl;
	}
	//--------------------------------------marca-----------------------------
	s << "Marca: " << marca << endl;
	//-------------------------------------estilo/modelo------------------------------------------
	if (getEstilo() == 1 && getModelo() == 1) {
		s << "Estilo: Sport" << endl;
		s << "Modelo: Wave" << endl;
	}
	if (getEstilo() == 1 && getModelo() == 2) {
		s << "Estilo: Sport" << endl;
		s << "Modelo: Cargo" << endl;
	}
	if (getEstilo() == 1 && getModelo() == 3) {
		s << "Estilo: Sport" << endl;
		s << "Modelo: Elite" << endl;
	}
	//-----------------------------------------------------------------------------------------------
	if (getEstilo() == 2 && getModelo() == 1) {
		s << "Estilo: Funcional" << endl;
		s << "Modelo: Plus" << endl;
	}
	if (getEstilo() == 2 && getModelo() == 2) {
		s << "Estilo: Funcional" << endl;
		s << "Modelo: Rally" << endl;
	}
	if (getEstilo() == 2 && getModelo() == 3) {
		s << "Estilo: Funcional" << endl;
		s << "Modelo: Tornado" << endl;
	}
	//--------------------------------------------------------------------------------------------------
	if (getEstilo() == 3 && getModelo() == 1) {
		s << "Estilo: Special" << endl;
		s << "Modelo: CRF50F" << endl;
	}
	if (getEstilo() == 3 && getModelo() == 2) {
		s << "Estilo: Special" << endl;
		s << "Modelo: CRF110F" << endl;
	}
	if (getEstilo() == 3 && getModelo() == 3) {
		s << "Estilo: Special" << endl;
		s << "Modelo: CRF250F" << endl;
	}
	//-----------------------------------------numero de serie----------------------------------
	s << "Numero de serie: " << numSerie << endl;
	//-------------------------------------numero de placa-----------------------------------
	s << "Placa: " << placa << endl;
	//-----------------------------------------------PRECIO----------------------------------
	s << "Precio total: $" << precio << endl;
	return s.str();
}

string MotoHonda::getMarca()
{
	return marca;
}

int MotoHonda::getCilindraje()
{
	return cilindraje;
}

int MotoHonda::getEstilo()
{
	return estilo;
}

int MotoHonda::getModelo()
{
	return modelo;
}

double MotoHonda::getPrecio()
{
	return precio;
}

void MotoHonda::setPrecio(MotoHonda*m)
{
	//-------------------------------calculamos precio cilindraje---------------------------------
	//variable para cilindraje
	int A;
	if (m->getCilindraje() == 1) { A = 500; }
	else if (m->getCilindraje() == 2) { A = 1000; }
	else if (m->getCilindraje() == 3) { A = 2000; }
	//-------------------------------calculamos precio estilo---------------------------------
	//variable para estilo
	int B;
	if (m->getEstilo() == 1) { B = 10000; }
	else if (m->getEstilo() == 2) { B = 15000; }
	else if (m->getEstilo() == 3) { B = 20000; }
	//-------------------------------calculamos precio modelo---------------------------------
	//variable para Modelo
	int C;
	if (m->getModelo() == 1) { C = 20000; }
	else if (m->getModelo() == 2) { C = 25000; }
	else if (m->getModelo() == 3) { C = 30000; }

	precio = precio + A + B + C;
}

string MotoHonda::getPlaca()
{
	return placa;
}

int MotoHonda::getNumSerie()
{
	return numSerie;
}

int MotoHonda::getMar()
{
	return Mar;
}
