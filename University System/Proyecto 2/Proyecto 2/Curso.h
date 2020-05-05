#ifndef CURSO
#define CURSO
#include <iostream>
#include <string>
#include <sstream>
#include "ListaG.h"
using namespace std;

class Curso {
private:
	string nombre;
	string codigo;
	ListaG* listaGrupos;

public:
	Curso(string, string);
	Curso();
	~Curso();
	void setNombre(string);
	void setCodigo(string);
	string getNombre();
	string getCodigo();
	int cantidadGrupos();
	ListaG* getListaGrupos();
	bool agregarGrupo(Grupo*);
	string toStringGrupos();
	string toString();
	bool eliminarGrupo(string);
	string mostrarEstudiantesGrupo();
	Grupo* buscayRetornaGrupo(string);
	Persona* buscayRetornaEstu(string);
	Persona* buscayRetornaProfe(string);
	void guardarTxt(ofstream &);
	Curso *leerTxt(ifstream &);
};
#endif
