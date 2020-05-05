
#include<iostream>
using namespace std;
#include"fraccion.h"


void main() {
	Fraccion::Fraccion(); {
		cout << "Nueva Fraccion" << endl;
	}

	void Fraccion::setNumerador(int n); {
		this->numerador = n;
	}
	void Fraccion::setDenominador(int d) {
		this->denominador = d;
	}

	int Fraccion::getNumerador() {
		return this->numerador;
	}
	int Fraccion::getDenominador() {
		return this->denominador;
	}


	Fraccion::~Fraccion() {
		cout << "Fraccion eliminada" << endl;
	}
}