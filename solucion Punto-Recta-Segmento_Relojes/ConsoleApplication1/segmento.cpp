#include "segmento.h"
#include <sstream>


segmento::segmento(punto a, punto b, string etiqueta) : _a(a), _b(b), _etiqueta(etiqueta) {
}


double segmento::longitud()  const {
	return _a.distancia(_b);
}


punto segmento::obtenerPuntoMedio() const {
	double x = (_a.obtenerX() + _b.obtenerX()) / 2;
		double y = (_a.obtenerY() + _b.obtenerY()) / 2;
	return punto(x, y);

}
string segmento::toString() const {
	stringstream r;
	if (_etiqueta != "") {
		r << _etiqueta << ": ";
	}
	r << "[";
	r  << _a.toString() << ", " << _b.toString();
	r << "]";
	return r.str();
}

punto segmento::obtenerA() {
	return _a;
}

punto segmento::obtenerB() {
	return _b;
}

string segmento::obtenerEtiqueta() const {
	return _etiqueta;
}
