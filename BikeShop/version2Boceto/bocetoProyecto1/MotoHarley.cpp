#include "MotoHarley.h"

MotoHarley::MotoHarley(int cil, int est, int mod, int num, string pla)
{
	marca = "Harley";
	cilindraje = cil;
	estilo = est;
	modelo = mod;
	numSerie = num;
	placa = pla;
	precio = 200000;
	this->setPrecio(this);
	Mar = 1;
}

MotoHarley::~MotoHarley()
{
}

string MotoHarley::toString()
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
	s << "Marca: " <<marca<< endl;
	//-------------------------------------estilo/modelo------------------------------------------
	if (getEstilo() == 1 && getModelo()==1) {
		s << "Estilo: Softail" << endl;
		s << "Modelo: BOB" << endl;
	}
	if (getEstilo() == 1 && getModelo() == 2) {
		s << "Estilo: Softail" << endl;
		s << "Modelo: Slim" << endl;
	}
	if (getEstilo() == 1 && getModelo() == 3) {
		s << "Estilo: Softail" << endl;
		s << "Modelo: Deluxe" << endl;
	}
	//-----------------------------------------------------------------------------------------------
	if (getEstilo() == 2 && getModelo() == 1) {
		s << "Estilo: Trike" << endl;
		s << "Modelo: Wheeler" << endl;
	}
	if (getEstilo() == 2 && getModelo() == 2) {
		s << "Estilo: Trike" << endl;
		s << "Modelo: Glide" << endl;
	}
	if (getEstilo() == 2 && getModelo() == 3) {
		s << "Estilo: Trike" << endl;
		s << "Modelo: Ultra" << endl;
	}
	//--------------------------------------------------------------------------------------------------
	if (getEstilo() == 3 && getModelo() == 1) {
		s << "Estilo: CVO" << endl;
		s << "Modelo: Street" << endl;
	}
	if (getEstilo() == 3 && getModelo() == 1) {
		s << "Estilo: CVO" << endl;
		s << "Modelo: Road" << endl;
	}
	if (getEstilo() == 3 && getModelo() == 1) {
		s << "Estilo: CVO" << endl;
		s << "Modelo: Limited" << endl;
	}
	//-----------------------------------------numero de serie----------------------------------
	s << "Numero de serie: " << numSerie << endl;
	//-------------------------------------numero de placa-----------------------------------
	s << "Placa: " << placa << endl;
	//-----------------------------------------------PRECIO----------------------------------
	s << "Precio total: $" << precio << endl;
	return s.str();
}

string MotoHarley::getMarca()
{
	return marca;
}

int MotoHarley::getCilindraje()
{
	return cilindraje;
}

int MotoHarley::getEstilo()
{
	return estilo;
}

int MotoHarley::getModelo()
{
	return modelo;
}

double MotoHarley::getPrecio()
{
	return precio;
}

string MotoHarley::getPlaca()
{
	return placa;
}

int MotoHarley::getNumSerie()
{
	return numSerie;
}

int MotoHarley::getMar()
{
	return Mar;
}

void MotoHarley::setPrecio(MotoHarley*m)
{
	//-------------------------------calculamos precio cilindraje---------------------------------
	//variable para cilindraje
	int A;
	if (m->getCilindraje() == 1) { A = 500; }
	else if  (m->getCilindraje() == 2) { A = 1000; }
	else if (m->getCilindraje() == 3) { A = 2000; }
	//-------------------------------calculamos precio estilo---------------------------------
	//variable para estilo
	int B;
	if (m->getEstilo() == 1) { B = 10000; }
	else if (m->getEstilo() == 2) { B = 15000; }
	else if (m->getEstilo() == 3) { B= 20000; }
	//-------------------------------calculamos precio modelo---------------------------------
	//variable para Modelo
	int C;
	if (m->getModelo() == 1) { C = 20000; }
	else if (m->getModelo() == 2) { C = 25000; }
	else if (m->getModelo() == 3) { C= 30000; }

	precio = precio + A + B + C;
}
