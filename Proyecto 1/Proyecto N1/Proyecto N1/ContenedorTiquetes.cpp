#include "ContenedorTiquetes.h"

ContenedorTiquetes::ContenedorTiquetes() {
	cantidad = 0;
	tam = 96;
	contenedor = new Tiquete*[tam];
}

int ContenedorTiquetes::getCantidad() { return cantidad; }

void ContenedorTiquetes::crearTiquete(int a) {
	int t = cantidad + 1;
	if (cantidad < tam) {
		contenedor[cantidad] = new Tiquete(t, a);
		cantidad = cantidad + 1;
	}
}

string ContenedorTiquetes::mostrarTiquete(int a) {
	stringstream c;
	c<<contenedor[a]->toString();

	return c.str();
}

/*ContenedorTiquetes::~ContenedorTiquetes() {
	for (int a = 0; a < tam; a++) {
		delete contenedor[a];
	}

	delete[] contenedor;
}*/

Tiquete* ContenedorTiquetes::getTiquete(int y) {
	int num = y - 1;
	return contenedor[num];
}
