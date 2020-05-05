#include "Carrera.h"

Carrera::Carrera(int a, Bus *b, int c, string d, float e) :numCarrera(a), unidad(b), horaSalida(c), ruta(d), precio(e) {   //CONSTRUCTOR

	tiquetes = new ContenedorTiquetes;
}


string Carrera::mostrarAsientosBus() { return unidad->mostrarAsientos(); }


int Carrera::vender(int a){

	if (unidad->consultaAsiento(a)==true) {

		tiquetes->crearTiquete(a);
		unidad->ocuparAsiento(a);
		return tiquetes->getCantidad();
	}
	else { return 0; }
}


string Carrera::infoTiquete(int a) {
	int b = a - 1;
	stringstream d;
	d << "\tInformacion del tiquete\n";
	if ((tiquetes->getCantidad() > b) && (b >= 0) ) {
		d << tiquetes->mostrarTiquete(b);
		d << toString();
	}
	else {
		d << "Numero de tiquete invalido\n";
	}
	return d.str();

}

string Carrera::mostrarTodosTiquetes() {
	stringstream s;
	for (int y = 0; y < tiquetes->getCantidad(); y++) {
		s<<tiquetes->mostrarTiquete(y);
		s << toString() << endl << endl;
	}
	return s.str();
}

string Carrera::toString() {
	stringstream c;
	c << "Numero de carrera: " << numCarrera << endl;
	c << "Numero de unidad: " << unidad->getnumBus() << endl;
	c << "Hora de salida: " << horaSalida << endl;
	c << "Ruta: " << ruta << endl;
	c << "Precio: " << precio << endl;
	return c.str();

}

float Carrera::montorecolectado() {
	float monto;
	monto = tiquetes->getCantidad()*precio;
	return monto;
}

bool Carrera::cambiarTiquete(int a, int r) {
	if (tiquetes->getCantidad() >= a) {
		int b = tiquetes->getTiquete(a)->getNum();
		unidad->desOcupar_Asiento(b);
		unidad->ocuparAsiento(r);
		tiquetes->getTiquete(a)->setNum(r);
		return true;

	}
	else {
		return false;
	}
}

/*Carrera::~Carrera() {
	delete tiquetes;
}*/