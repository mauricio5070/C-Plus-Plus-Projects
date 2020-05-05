#ifndef RECTA_H
#define RECTA_H

// Poner en el .h unicamente las librerias estrictamente necesarias para el .h
// si  el .cpp requiere otras libreras colocar estas en el .cpp


using namespace std;
#include <string> 
#include "segmento.h"

class recta {// recordemos que el standard de C++, nos incida que el nombre de
			 //las clases debe ir singular y en minúscula 
private:
	double _m;  // pendiente
	double _b;  // intersecion en y
	string _etiqueta;
public:
	recta(double = 1.0, double = 0.0, string = "");
	recta(segmento, string = "");
	recta(punto, punto, string = "");
	bool esParalela(recta)const;
	bool esPerpendicular(recta)const;
	string toString()const;
	double obtenerPendiente()const;
	double obtenerInterseccion() const;
	string obtenerEtiqueta()const;
	string obtenerTipo() const;
	double resolverFuncion(double ) const;
	void calcula_m_b(segmento);// bajo el entendido que si cambia uno cambia el otro

};


#endif /* RECTA_H */





