#include "Tiquete.h"

Tiquete::Tiquete(int a, int b):numTiquete(a), numAsiento(b) {}

string Tiquete::toString() {
	stringstream f;
	f << "Numero de tiquete: " << this->numTiquete << endl;
	f << "Numero de asiento: " << this->numAsiento << endl;
	return f.str();
}

int Tiquete::getNum() {
	return numAsiento;
}

void Tiquete::setNum(int a) {
	numAsiento = a;
}

Tiquete::~Tiquete(){}