/////////////////////////////////////////////////////////////////////////////  Estudiante. ///////////////////////////////////////////////////////////////

#pragma once

using namespace std;
#include <iostream>
#include <string>
#include<sstream> 


class Estudiante
{
private:
	int id;
	string nombre;
	int edad;
	float nota;
	char genero;

public:
	Estudiante(void);
	Estudiante(int, string, float, int, char);
	int getId();
	void setId(int);
	void setNombre(string);
	string getNombre();
	void setEdad(int);
	int getEdad();
	float getNota();
	void setNota(float);
	char getGenero();
	void setGenero(char);
	string toString();
	~Estudiante(void);
};
