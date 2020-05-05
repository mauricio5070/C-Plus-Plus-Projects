/*
* To change this license header, choose License Headers in Project Properties.
* To change this template file, choose Tools | Templates
* and open the template in the editor.
*/

/*
* File:   punto.cpp
* Authors: Georges E. Alfaro S.
*          Jennifer V. Fuentes B.
*          Karol Leitón Arrieta.
*
* Created on July 31, 2017, 11:44 PM
*/


#include "punto.h"
#include <cmath> // no usar la libreria <math.h>
#include <sstream>


punto::punto(double x, double y, string etiqueta) : _x(x), _y(y), _etiqueta(etiqueta) {
}


double punto::distancia(const punto& b) const {
	double dx = b._x - _x;
	double dy = b._y - _y;
	return sqrt(dx * dx + dy * dy);
}

double punto::distancia(const punto& a, const punto& b) { // Metodo static
	return a.distancia(b);
}

string punto::toString() const {
	stringstream r;
	if (_etiqueta != "") {
		r << _etiqueta <<" ";
	}
	r << "(";
	r << "x: " << _x << ", y: " << _y;
	r << ")";
	return r.str();
}

double punto::obtenerX() const {
	return _x;
}

double punto::obtenerY() const {
	return _y;
}

string punto::obtenerEtiqueta() const {
	return _etiqueta;
}
