#pragma once
#include "Cliente.h"

#include <sstream>
#include <iostream>
#include <Windows.h>
#include "Calendario.h"
#include "Utiles.h"
#include "Moto.h"
#include "MotoHarley.h"
#include "MotoHonda.h"
#include "MotoYamaha.h"
using namespace std;

class Contrato {
private:
	char* DatosEmpresa;
	Cliente* cliente;
	Moto* moto;
	Calendario* Cal;
	Pago** Con;
	int Dia;
	int Mes;
	int Anio;
	int aniosPlazo;
	double Monto;
	int diaPago;
public:
	Contrato(Cliente*, Moto*,Calendario*);
	Contrato(Cliente*, Moto*,Pago**);
	~Contrato();
	string toString(int);
	int getDia();
	int getMes();
	int getAnio();
	int getAniosPlazo();
	double getMonto();
	Cliente* getCliente();
	Calendario* getCalendario();
	string toStringNombreCedula();
	int getCedula();
	static Contrato* recuperar(istream&);
	void guardar(ostream&);
	string getNom();

	string getApe();

	void guardarFechas(ostream&);
	
	void guardarPendientes(ostream&);
	
	void guardarEspecifico(ostream&);
	void guardarFechaEspecifica(ostream&);
	

};