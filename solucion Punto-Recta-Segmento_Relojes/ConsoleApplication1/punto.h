/*
* To change this license header, choose License Headers in Project Properties.
* To change this template file, choose Tools | Templates
* and open the template in the editor.
*/

/*
* File:   punto.h
* Authors: Georges E. Alfaro S.
*          Jennifer V. Fuentes B.
*          Karol Leitón Arrieta.
*
* Created on July 31, 2017, 11:44 PM
*/

//Guardas: evitan la re-definición de la clase
//#ifndef, #define y #endif

#ifndef PUNTO_H
#define PUNTO_H
// Poner en el .h unicamente las librerias estrictamente necesarias para el .h
// si  el .cpp requiere otras libreras colocar estas en el .cpp
using namespace std;
#include <string> 


class punto { // recordemos que el standard de C++, nos incida que el nombre de
	          //las clases debe ir singular y en minúscula 
private:
	double _x;
	double _y;
	string _etiqueta;

public:
	punto(double = 0, double = 0, string = "");
	//El uso del const al final de la declaración del método
	//protege el estado del objeto, es decir,
	//la implementación del método no puede modificar el 
	//valor de los atributos.
	string toString() const;
	double obtenerX() const;
	double obtenerY() const;
	string obtenerEtiqueta() const;


	//El uso del const en el parámetro proteje el estado
	//del objeto que se recibe como parámetro

	//Método de instancia
	 double distancia(const punto&) const;

	//Método de clase
	static double distancia(const punto&, const punto&);  // Cuando un miembro es static, podrá ser accedido sin necesidad de una instacia (ver invocación en el main)

};

#endif /* PUNTO_H */

