#include "Empresa.h"

Empresa::Empresa(string a, string b, char c) :nombre(a), telefono(b), terminal(c) {
	flotilla = new Bus*[5];
	carrera = new Carrera*[5];
	for (int i = 0; i < 5;i++ ) {
		flotilla[i] = new Bus();
		carrera[i]= new Carrera();
	}
}

string Empresa::toString() {
	stringstream f;
	f << "\tDatos de la empresa:\n";
	f << "Nombre: " << nombre << endl;
	f << "Telefono: " << telefono << endl;
	f << "Terminal: " << terminal << endl;
	return f.str();
}

void Empresa::setNombre(string a) { nombre = a; }
string Empresa::getNombre() { return nombre; }
void Empresa::setTelefono(string b) { telefono = b; }
void Empresa::setTerminal(char c) { terminal = c; }

void Empresa::registrarBus(int S, Bus A) { *flotilla[S] = A; }

void Empresa::registrarCarrera(int V, Carrera C) { *carrera[V] = C; }

string Empresa::mostrarBus(int e) { return flotilla[e]->toString(); }

Bus* Empresa::getBus(int r) { return flotilla[r]; }

string Empresa::mostrarCarrera(int n) { return carrera[n]->toString(); }

string Empresa::asientos_BusCarrera(int s) { return carrera[s]->mostrarAsientosBus(); }

void Empresa::actualizarEstadoBus(int a, char b) { flotilla[a]->setUbicacion(b); }

int Empresa::venderTiquete(int a, int u) { return carrera[a]->vender(u); }

bool Empresa::cambiarTicket(int c, int a, int b) { return carrera[c]->cambiarTiquete(a, b); }

string Empresa::info_Tiquete(int a, int r) {
	return carrera[a]->infoTiquete(r);
}

string Empresa::mostrarTiquetesvendidos() {
	stringstream n;
	n << "\tLista de tiquetes vendidos: \n\n";
	for (int c = 0; c < 5; c++) {
		n << "\tEn Carrera numero " << c + 1 << ": \n\n";
		n << carrera[c]->mostrarTodosTiquetes() << endl;
	}

	return n.str();
}

float Empresa::montoRecolectado(int a) {
	return carrera[a]->montorecolectado();
}

Empresa::~Empresa() {
	for (int i = 0; i < 5; i++) {
		delete flotilla[i];
		delete carrera[i];
	}

	delete[] flotilla;
	delete[] carrera;
}
