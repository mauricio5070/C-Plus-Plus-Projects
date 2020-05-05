#ifndef INSTITUTO
#define INSTITUTO
#include"ListaP.h"
#include "ListaC.h"
#include "Estudiante.h"
#include "Profesor.h"

class Instituto {
private:
	string nombre;
	ListaP* listaProfes;
	ListaP* listaEstudiantes;
	ListaC* listaCursos;
public:
	Instituto(string = "-");
	~Instituto();
	ListaP* getListaProfes();
	ListaP* getListaEstudiantes();
	ListaC* getListaCursos();
	string toStringProfes();
	string toStringEstudiantes();
	string toStringCursos();
	string toStringGrupos();
	string toStringInstituto();
	bool agregarEstudiante(Estudiante*);
	bool agregarProfesores(Profesor*);
	bool agregarCurso(Curso*);
	bool eliminaEstudiante(string);
	bool eliminaProfesor(string);
	bool eliminaCurso(string);
	void guardar();
	void cargar();
};
#endif