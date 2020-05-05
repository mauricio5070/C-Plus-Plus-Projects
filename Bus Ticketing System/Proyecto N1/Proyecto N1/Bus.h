#ifndef BUS
#define BUS

#include "Asiento.h"
using namespace std;

class Bus {

private:

	int numBus;
	string placa;
	Asiento ***butaca;
	char ubicacion;
	string asignacion;

public:

	Bus(int = 0, string = "-", char = '-', string= "Sin Asignar");
	//~Bus();
	void setAsignacion(string);
	string getAsignacion();
	void setUbicacion(char);
	char getUbicacion();
	int getnumBus();
	string mostrarAsientos();
	void desOcupar_Asiento(int);
	bool consultaAsiento(int);
	void ocuparAsiento(int);
	string toString();

};

#endif