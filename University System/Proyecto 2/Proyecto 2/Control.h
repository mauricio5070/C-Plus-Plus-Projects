#pragma once
#include "Interfaz.h"
#include "Instituto.h"

class Control {
private:
	Instituto* I;
public:
	Control();
	void iniciar();
	void agregarEstudiante();
	void agregarProfe();
	void agregarCurso();
	void agregarGrupo();
	void mostrarEstudiantes();
	void mostrarProfes();
	void mostrarCursos();
	void mostrarGrupos();
	void eliminarEstudiante();
	void eliminarProfe();
	void eliminarCurso();
	void eliminarGrupo();
	void agregarEstudianteGrupo();
	void mostrarEstudiantesGrupo();
	void cursosXEstudiante();
	void cursosXProfesor();

};
