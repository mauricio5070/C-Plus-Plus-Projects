
#ifndef CONTROL_H
#define CONTROL_H
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "Interfaz.h"
#include "Biblioteca.h"

class Control {
private:
	Biblioteca* B;
        Interfaz* Z;
public:
	Control();
	void iniciar();
	void agregarPersona();
	void agregarLibro();
	
	void mostrarPersonas();
	void mostrarLibros();
	
        
	void eliminarPersona();
	void eliminarLibro();
	
	

};







#endif /* CONTROL_H */

