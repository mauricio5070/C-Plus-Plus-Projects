#include "MotoYamaha.h"

MotoYamaha::MotoYamaha(int cil, int est, int mod, int num, string pla)
{
	marca = "Honda";
	cilindraje = cil;
	estilo = est;
	modelo = mod;
	numSerie = num;
	placa = pla;
	precio = 50000;
	this->setPrecio(this);
	Mar=3;
}

MotoYamaha::~MotoYamaha()
{
}

string MotoYamaha::toString()
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
		s << "Estilo: Scooter" << endl;
		s << "Modelo: Ray" << endl;
	}
	if (getEstilo() == 1 && getModelo() == 2) {
		s << "Estilo: Scooter" << endl;
		s << "Modelo: Cygnus" << endl;
	}
	if (getEstilo() == 1 && getModelo() == 3) {
		s << "Estilo: Scooter" << endl;
		s << "Modelo: Max" << endl;
	}
	//-----------------------------------------------------------------------------------------------
	if (getEstilo() == 2 && getModelo() == 1) {
		s << "Estilo: Deportiva" << endl;
		s << "Modelo: REV" << endl;
	}
	if (getEstilo() == 2 && getModelo() == 2) {
		s << "Estilo: Deportiva" << endl;
		s << "Modelo: Trucer" << endl;
	}
	if (getEstilo() == 2 && getModelo() == 3) {
		s << "Estilo: Deportiva" << endl;
		s << "Modelo: Star" << endl;
	}
	//--------------------------------------------------------------------------------------------------
	if (getEstilo() == 3 && getModelo() == 1) {
		s << "Estilo: Monta" << char(164) << "era" << endl;
		s << "Modelo: XT2" << endl;
	}
	if (getEstilo() == 3 && getModelo() == 2) {
		s << "Estilo: Monta" << char(164) << "era" << endl;
		s << "Modelo: PW50" << endl;
	}
	if (getEstilo() == 3 && getModelo() == 3) {
		s << "Estilo: Monta"<< char(164)<<"era" << endl;
		s << "Modelo: 450F" << endl;
	}
	//-----------------------------------------numero de serie----------------------------------
	s << "Numero de serie: " << numSerie << endl;
	//-------------------------------------numero de placa-----------------------------------
	s << "Placa: " << placa << endl;
	//-----------------------------------------------PRECIO----------------------------------
	s << "Precio total: $" << precio << endl;
	return s.str();
}

string MotoYamaha::getMarca()
{
	return marca;
}

int MotoYamaha::getCilindraje()
{
	return cilindraje;
}

int MotoYamaha::getEstilo()
{
	return estilo;
}

int MotoYamaha::getModelo()
{
	return modelo;
}

double MotoYamaha::getPrecio()
{
	return precio;
}

void MotoYamaha::setPrecio(MotoYamaha*m)
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

string MotoYamaha::getPlaca()
{
	return placa;
}

int MotoYamaha::getNumSerie()
{
	return numSerie;
}

int MotoYamaha::getMar()
{
	return Mar;
}
