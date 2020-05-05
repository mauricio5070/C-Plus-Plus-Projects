#ifndef GRUPO
#define GRUPO
#include <iostream>
#include <string>
#include <sstream>
#include "Profesor.h"
#include "ListaP.h"
using namespace std;

class Grupo {
private:
	Persona* prof;
	string horario;
	string nrc;
	int cupo;
	int aula;
	ListaP* listaEstudiantes;
public:
	Grupo(Persona* = NULL, string = "-", string = "-", int = 0, int = 0);
	~Grupo();
	void setProfesor(Persona*);
	void setHorario(string);
	void setNRC(string);
	void setCupo(int);
	void setAula(int);
	Persona* getProfesor();
	ListaP* getlistaEstudiantes();
	string getHorario();
	string getNRC();
	int getCupo();
	int getAula();
	string toString();
	string toStringEstudiantes();
	int cantidadEstudiantes();
	bool agregarEstudiante(Persona*);
	//void guardarTxt(ofstream &);
	//Grupo *leerTxt(ifstream &);
};
#endif
