#ifndef CARRERA
#define CARRERA
#include "Bus.h"
#include "ContenedorTiquetes.h"

class Carrera {
private:
	int numCarrera;
	Bus *unidad;
	int horaSalida;
	string ruta;
	float precio;
	ContenedorTiquetes *tiquetes;

public:
	Carrera(int = 0, Bus* = new Bus() , int = 0, string = "-", float = 0);
	//~Carrera();
	string mostrarAsientosBus();
	string infoTiquete(int);
	string mostrarTodosTiquetes();
	int vender(int);
	float montorecolectado();
	string toString();
	bool cambiarTiquete(int,int);
};

#endif