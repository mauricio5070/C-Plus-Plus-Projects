#ifndef CONTROL
#define CONTROL
#include "Cliente.h"
#include "Interfaz.h"
#include <sstream>
#include <iostream>
#include <Windows.h>
#include "Calendario.h"
#include "Utiles.h"
#include "Moto.h"
#include "MotoHarley.h"
#include "MotoHonda.h"
#include "MotoYamaha.h"
#include "Contrato.h"
#include "Empresa.h"

class Control {
private:
	Empresa* E;
	Interfaz* I;
public:
	Control();
	void iniciar();
	void agregarCompra();
	void mostrarCompras();
	void mostrarDatosEmpresa();
	void mostrarPagosPersona();
	void mostrarClientes();
	void mostrarCatalogo();
	void realizaPagos();
	void modificaEmpresa();
	void generarPendientes();
	void generarEspecifico();
	void generarReporteFecha();

};
#endif