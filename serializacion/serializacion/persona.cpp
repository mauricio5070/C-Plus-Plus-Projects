#include "persona.h"
#include "utiles.h"
#include <sstream>

#define DELIMITA_CAMPO '\t'
#define DELIMITA_REGISTRO '\n'

Persona::Persona(string ced, string ape, string nom, int eda, double estat) :cedula(ced), apellidos(ape), nombre(nom), edad(eda), estatura(estat) {}
Persona Persona::recuperar(istream& entrada) {
	//variables comodines
	string cedulaC, apellidosC, nombreC, edadC, estaturaC;
	getline(entrada, cedulaC, DELIMITA_CAMPO);
	getline(entrada, apellidosC, DELIMITA_CAMPO);
	getline(entrada, nombreC, DELIMITA_CAMPO);
	getline(entrada, edadC, DELIMITA_CAMPO);
	getline(entrada, estaturaC, DELIMITA_CAMPO);

	int valorEdad = convertirInt(edadC);  //funciones de libreria QUE CREAMOS
	double valorEstatura = convertirDouble(estaturaC);

	return Persona(cedulaC, apellidosC, nombreC, valorEdad, valorEstatura);
}
void Persona::guardar(ostream& salida) {
	salida<< cedula<< DELIMITA_CAMPO;
	salida<< apellidos<< DELIMITA_CAMPO;
	salida<<nombre << DELIMITA_CAMPO;
	salida<< edad<< DELIMITA_CAMPO;
	salida<< estatura<< DELIMITA_CAMPO;

}
string Persona::toString() {
	stringstream s;
	s << "{ ";
	s << cedula << ", " << apellidos << ", " << nombre<< ", " << edad << ", " << estatura;
	s << " }";
	return s.str();
}
