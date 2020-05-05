#ifndef  CLINICA_H
#define  CLINICA_H
#include<iostream>
#include "coleccion.h"

class Clinica
{
private:
	Coleccion* a;
	int telefono;
	string nombre;
	

public:
	Clinica() {
		int i = 0;
		a = new Coleccion();


		a = new Coleccion();
		

		
	}

	Coleccion* getColeccion() { return a; }
	void  setColeccion(Coleccion* aa) { a = aa; }

	

	
	~Clinica() {
		delete a;
		cout << "Se ha borrado la clinica" << endl;
	}

};






#endif
