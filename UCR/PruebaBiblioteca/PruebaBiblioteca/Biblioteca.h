

#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H
#include"ListaM.h"
#include "Alquilado.h"
#include "Persona.h"
#include "Libro.h"

class Biblioteca {
private:
	string nombre;
	ListaM* listaPersonas;
	ListaM* listaLibros;
	ListaM* listaAlquilados;
	
public:
	Biblioteca(string = "-");
	~Biblioteca();
	ListaM* getListaPersonas();
	ListaM* getListaLibros();
	ListaM* getListaAlquilados();
	
	string toStringPersonas();
	string toStringLibros();
	string toStringAlquilados();
	
	
	string toStringBiblioteca();
	bool agregarPersonas(Persona*);
	bool agregarLibros(Libro*);
	bool agregarAlquiler(Alquilado*);



	
	bool eliminaPersona(string);
	bool eliminaLibro(string);

        
	void guardar();
	void cargar();
};


#endif /* BIBLIOTECA_H */

