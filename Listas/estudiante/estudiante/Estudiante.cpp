

#include "Estudiante.h"

Estudiante::Estudiante(void) {
	id = 0;
	nombre = "sin definir";
	nota = 0;
	edad = 0;
}
Estudiante::Estudiante(int id, string nom, float not, int ed, char ge)
{
	this->id = id;
	this->nombre = nom;
	this->nota = not;
	this->edad = ed;
	this->genero = ge;
}
int Estudiante::getId() { return id; }
void Estudiante::setId(int id) { this->id = id; }
void Estudiante::setNombre(string nom) { nombre = nom; }
string Estudiante::getNombre() { return nombre; }
float Estudiante::getNota() { return nota; }
void Estudiante::setNota(float not) { nota = not; }

void Estudiante::setEdad(int e) { edad = e; }
int Estudiante::getEdad() { return edad; }
char Estudiante::getGenero() { return genero; }
void Estudiante::setGenero(char g) { this->genero = g; }
string Estudiante::toString() {
	stringstream s;
	s << " ------------" << endl;
	s << "ID:  " << id << endl;
	s << "Nombre:  " << nombre << endl;
	s << "edad:" << edad << endl;
	s << "Nota:" << nota << endl;
	s << " ------------" << endl << endl;
	return s.str();
}

Estudiante::~Estudiante(void) { cout << "Se ha destruido un estudiante" << endl; }