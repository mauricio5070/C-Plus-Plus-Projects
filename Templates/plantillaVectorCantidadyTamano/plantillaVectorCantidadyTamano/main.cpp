#pragma once
#include "vector.h"


#include <iostream>
#include <sstream>
using namespace std;

class Persona {
private:
	string nombre;
	string cedula;

public:
	Persona() :nombre(""), cedula("") {}
	Persona(string nom, string ced) :nombre(nom), cedula(ced) {}
	~Persona() {}

	friend ostream& operator << (ostream & out, Persona & p) {
		out << "CEDULA: " << p.cedula << endl << "NOMBRE: " << p.nombre << endl;
		return out;
	}


};




int main() {

	cout << "---------------------------------endteros y chars------------------" << endl;
	Vector<int> Vint;
	Vector<char> Vchar;

	for (int i = 0; i < 10; i++) {
		Vint.ingresaElemento(i*3);-
		Vchar.ingresaElemento(i + 65);
	}
	cout << "----------------------------------imprimiendo------------------------------" << endl;
	cout << Vint.toString() << endl;
	cout << Vchar.toString() << endl;

	//-------------------------------------------------personas--------------------
	Persona a1("Daniel", "111");
	Persona a2("Valeria", "222");
	Persona a3("Marcos", "333");
	Vector<Persona>* CTP = new Vector<Persona>(10);
	CTP->ingresaElemento(a1);
	CTP->ingresaElemento(a2);
	CTP->ingresaElemento(a3);
	
	
   cout << CTP->toString()<< endl;
	

	system("pause");
	return 0;
}