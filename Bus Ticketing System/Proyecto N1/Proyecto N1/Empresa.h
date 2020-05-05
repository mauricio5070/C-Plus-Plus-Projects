#ifndef EMPRESA
#define EMPRESA
#include "Bus.h"
#include "Carrera.h"

class Empresa {
private:
	string nombre;
	string telefono;
	char terminal;
	Bus **flotilla;
	Carrera **carrera;

public:
	Empresa(string = "-", string = "-", char = '-');
	~Empresa();
	void setNombre(string);
	string getNombre();
	void setTelefono(string);
	void setTerminal(char);
	string toString();
	void registrarBus(int,Bus);
	void registrarCarrera(int,Carrera);
	string mostrarBus(int);
	Bus* getBus(int);
	string mostrarCarrera(int);
	string asientos_BusCarrera(int);
	void actualizarEstadoBus(int,char);
	int venderTiquete(int, int);
	bool cambiarTicket(int, int, int);
	string info_Tiquete(int,int);
	string mostrarTiquetesvendidos();
	float montoRecolectado(int);


};
#endif
