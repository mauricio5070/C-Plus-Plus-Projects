#pragma once
#include"NodoC.h"

class ListaC {
private:
	NodoC* pinicio;
	NodoC* pactual;
public:
	ListaC();
	bool agregar(Curso*);
	bool elimina(string);
	string toString();
	Curso* buscayRetorna(string);
	int cantidadCursos();
	void guardarCurso();
	void cargarCurso();
	bool eliminaGrupo(string);
	Grupo* buscayRetornaGrupo(string);
	int cantidadGrupos();
	string mostrarGrupos();
	string mostrarEstudiantesGrupos();
	string cursosPorEstudiante(string);
	string cursosPorProfesor(string);
	~ListaC();
};
