#ifndef CONTROL
#define CONTROL
#include "Empresa.h"
#include "Interfaz.h"

class Control {
private:
	Empresa *A;

public:
	void iniciar();
	void desarrollo();
	void iniciarEmpresa();
	void mostrar_actualizar_Empresa();
	void registrarBuses();
	void mostrarBuses();
	void registarCarreras();
	void mostrarCarreras();
	void mostrarAsientos_Bus_Carrera();
	void actualizarEstado_Bus();
	void venderTicket();
	void cambiarTiquete();
	void mostrarTiquete();
	void mostrarTodosTiquetesVendidos();
	void ganancias();
};

#endif