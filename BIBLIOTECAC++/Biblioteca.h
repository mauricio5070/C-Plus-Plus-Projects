

#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H
#include"ListaM.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "Persona.h"
#include "Libro.h"

class Biblioteca {
private:
	string nombre;
	ListaM* listaPersonas;
	ListaM* listaLibros;
	
public:
	Biblioteca(string = "-");
	~Biblioteca();
	ListaM* getListaPersonas();
	ListaM* getListaLibros();
	
	string toStringPersonas();
	string toStringLibros();
	
	
	string toStringBiblioteca();
	bool agregarPersonas(Persona*);
	bool agregarLibros(Libro*);
	
	bool eliminaPersona(string);
	bool eliminaLibro(string);

        
	void guardar();
	void cargar();
};


#endif /* BIBLIOTECA_H */

