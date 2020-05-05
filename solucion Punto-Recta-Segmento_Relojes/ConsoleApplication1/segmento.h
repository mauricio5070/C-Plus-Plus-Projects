#ifndef SEGMENTO_H
#define SEGMENTO_H
// Poner en el .h unicamente las librerias estrictamente necesarias para el .h
// si  el .cpp requiere otras libreras colocar estas en el .cpp
#include "punto.h"
#include <string> 
using namespace std;

class segmento {// recordemos que el standard de C++, nos incida que el nombre de
	          //las clases debe ir singular y en minúscula 
private:
	punto _a;
	punto _b;
	string _etiqueta;

public:
	 segmento(punto, punto, string = "");
	 string toString() const;
	 double longitud() const;
	 punto obtenerPuntoMedio() const;
	 punto obtenerA();   
	 punto obtenerB();
	 string obtenerEtiqueta() const;
};

#endif /* SEGMENTO_H */

