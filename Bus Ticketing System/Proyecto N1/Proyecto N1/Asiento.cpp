#include "Asiento.h"

Asiento::Asiento(char a, int b, char c) : letra(a), numero(b), estado(c) {}

string Asiento::toString() {
	stringstream s;
	s << estado;
	s << letra;
	s << numero;
	return s.str();
}

void Asiento::setEstado(char a) { estado = a; }

string Asiento::getEstado() {
	if (estado == '-') {
		return "Disponible";
	}
	else {
		return "Ocupado";
	}
}

char Asiento::getLetra()
{
	return letra;
}

int Asiento::getNumero() { return numero; }

Asiento::~Asiento() {}