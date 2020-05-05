
#ifndef CONTROL_H
#define CONTROL_H
#include <iostream>
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
	void alquiler();
	
	void mostrarAlquiler();
	void mostrarPersonas();
	void mostrarLibros();
	
        
	void eliminarPersona();
	void eliminarLibro();
	void entregarLibro();
	
	

};







#endif /* CONTROL_H */

