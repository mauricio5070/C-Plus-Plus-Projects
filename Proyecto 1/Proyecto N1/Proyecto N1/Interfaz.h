#ifndef INTERFAZ
#define INTERFAZ
#include <iostream>
#include <string>
using namespace std;

class Interfaz {

	public:
	~Interfaz();
	void imprimeString(string a);
	void imprimeChar(char b);
	void imprimeInt(int c);
	void imprimeFloat(float d);
	string leeString();
	int leehora();
	int leeInt();
	char leeUbicacion();
	float leeFloat();
	char leeterminal();
	string leeRuta();
	int leeAsiento_Tiquete();
	int leeNum_Bus_Carrera();
};

#endif