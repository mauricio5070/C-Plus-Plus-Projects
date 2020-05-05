#pragma once
#include "Pago.h"
#include "Utiles.h"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <Windows.h>
using namespace std;
class Calendario {
private:
	Pago **contenedor;
	int cedula;
	int tam;
	int cantidad;
	int Dia;
	int Mes;
	int Anio;
	int Hoy;
	int AniosPlazo;
	double Monto;
	double Seguro;
	int ced;
public:
	Calendario(double, int, int,int);
	Calendario(int, double, int, int, int, int, int);
	//~Calendario();
	//Pago* getPago();
	void crearPagos();
	
	double getSeguro();
	double getMonto();
	int getAniosPlazo();
	int getDia();
	Pago* getContenedorPago(int);
	void guardarPagosPersona(ostream&);
	string mostrarPagos(int);
	int getHoy();
	int getMes();
	int getAnnio();
	int getTam();
	int getCantidad();

	void agregarPago(Pago*);
	int getDia(int);
	int getMes(int);
	int getAnio(int);
	int getId(int);
	double getMonto(int);
	char getEstado(int);
	static Calendario* recuperarCalendario(istream&);
	void recuperarPagos(int);
};