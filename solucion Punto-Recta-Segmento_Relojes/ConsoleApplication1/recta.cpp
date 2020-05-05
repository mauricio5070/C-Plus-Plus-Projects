
#include <sstream>
#include "recta.h"


recta::recta(double m, double b, string etiqueta) : _m(m), _b(b), _etiqueta(etiqueta) {
}
//----------------------------------------------
recta::recta(segmento s, string etiqueta) : _etiqueta(etiqueta) {
	double dx = s.obtenerB().obtenerX() - s.obtenerA().obtenerX();
	//	if (dx == 0) {  //
	//		throw - 1; // No es posible crear la instancia de la recta..
	//	}
	calcula_m_b(s);
}
//----------------------------------------------------------
recta::recta(punto p1, punto p2, string etiqueta) : _etiqueta(etiqueta) {
	double dx = p2.obtenerX() - p1.obtenerX();
	//	if (dx == 0) {  //
	//		throw - 1; // No es posible crear la instancia de la recta..
	//	}
	calcula_m_b(segmento(p1, p2));
}
//--------------------------------------------------------
void  recta::calcula_m_b(segmento s) { // si cambia _m cambia _b
	// Obtenemos  mediante  la formula, la  pendiente _m,  
	double dy = s.obtenerB().obtenerY() - s.obtenerA().obtenerY();
	double dx = s.obtenerB().obtenerX() - s.obtenerA().obtenerX();

	//	if (dx == 0) {  //
	//		throw - 1; // No es posible crear la instancia de la recta..
	//	}

	_m = dy / dx;
	// Obtenemos mediante  la formula, la  intersección en y (b)
	_b = s.obtenerA().obtenerY() - _m * s.obtenerA().obtenerX();
}
//----------------------------------------------
string recta::toString()const {
	stringstream r;
	if (_etiqueta != "") {
		r << _etiqueta << ": ";
	}
	r << "{" << "m: " << _m << ",b: " << _b << "}";
	return r.str();
}
//----------------------------------------------
bool recta::esParalela(recta r2) const {
	return _m == r2._m;
}
//----------------------------------------------
bool recta::esPerpendicular(recta r2) const {
	return _m == -r2._m;
}
//----------------------------------------------
double recta::obtenerPendiente()const {
	return _m;
}
//----------------------------------------------
double recta::obtenerInterseccion() const {
	return _b;
}

string recta::obtenerEtiqueta() const {
	return _etiqueta;
}
//----------------------------------------------
string recta::obtenerTipo() const {

	string r = "indefinada";
	if (_m < 0.0) {
		r = "decreciente";
	}
	else if (_m == 0.0) {
		r = "horizontal";
	}
	else { // _m > 0.0
		r = "creciente";
	}
	return r;
}

//-------------------------------------
double recta::resolverFuncion(double x) const
{
	return _m * x + _b;
}