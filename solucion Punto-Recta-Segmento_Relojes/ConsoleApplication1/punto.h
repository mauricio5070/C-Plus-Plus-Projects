/*
* To change this license header, choose License Headers in Project Properties.
* To change this template file, choose Tools | Templates
* and open the template in the editor.
*/

/*
* File:   punto.h
* Authors: Georges E. Alfaro S.
*          Jennifer V. Fuentes B.
*          Karol Leit�n Arrieta.
*
* Created on July 31, 2017, 11:44 PM
*/

//Guardas: evitan la re-definici�n de la clase
//#ifndef, #define y #endif

#ifndef PUNTO_H
#define PUNTO_H
// Poner en el .h unicamente las librerias estrictamente necesarias para el .h
// si  el .cpp requiere otras libreras colocar estas en el .cpp
using namespace std;
#include <string> 


class punto { // recordemos que el standard de C++, nos incida que el nombre de
	          //las clases debe ir singular y en min�scula 
private:
	double _x;
	double _y;
	string _etiqueta;

public:
	punto(double = 0, double = 0, string = "");
	//El uso del const al final de la declaraci�n del m�todo
	//protege el estado del objeto, es decir,
	//la implementaci�n del m�todo no puede modificar el 
	//valor de los atributos.
	string toString() const;
	double obtenerX() const;
	double obtenerY() const;
	string obtenerEtiqueta() const;


	//El uso del const en el par�metro proteje el estado
	//del objeto que se recibe como par�metro

	//M�todo de instancia
	 double distancia(const punto&) const;

	//M�todo de clase
	static double distancia(const punto&, const punto&);  // Cuando un miembro es static, podr� ser accedido sin necesidad de una instacia (ver invocaci�n en el main)

};

#endif /* PUNTO_H */

