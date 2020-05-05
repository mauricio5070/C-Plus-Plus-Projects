#ifndef EMPRESA
#define EMPRESA
#include "Cliente.h"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <Windows.h>
#include "Calendario.h"
#include "Utiles.h"
#include "Moto.h"
#include "MotoHarley.h"
#include "MotoHonda.h"
#include "MotoYamaha.h"
#include "Contrato.h"
#include "Pago.h"
using namespace std;


class Empresa {
private:

	string nombre;
	string telefono;
	string cedulaJuridica;
	string direccion;
	Contrato** ventas;
	Pago** pagosPersona;
	int cantidad;
	int can;
public:
	Empresa();
	~Empresa();
	string stringInfoEmpresa();
	void hacerPago(int,int);
	void agregarVenta(Contrato*);
	string toStringVentas();
	int getCantidad();
	string buscaImprimeCliente(int);
	void guardar();
	void recuperar();
	string catalogo();

	void agregarPagosPersona(Pago*);

	//void guardarPagosPersona(ostream&);
	string toStringPersonaPago();

	void sobreescribeFechas();

	void setNombre(string);
	void setTelefono(string);
	void setCedulaJuridica(string);
	void setDireccion(string);

	void guardaPendientes();

	void guardaClienteEspecifico(int);
	void guardarContratosPorFecha(int, int, int);
	string stringConvierteFecha(int);
};

#endif