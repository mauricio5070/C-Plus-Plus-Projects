
#ifndef MOLDE_H
#define MOLDE_H
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

class Molde {
protected:
	string nombre;
	string ID;

	
public:
	Molde(string, string);
	Molde();
       ~Molde();
	void setNombre(string);
	void setID(string);
	string getNombre();
	string getID();
	virtual string toString();
	void guardarTxt(ofstream &);
	Molde *leerTxt(ifstream &);
};












#endif /* MOLDE_H */

