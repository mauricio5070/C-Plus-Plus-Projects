#include "Cliente.h"
#define DELIMITA_CAMPO '\t'
#define DELIMITA_REGISTRO '\n'
Cliente::Cliente(int ced, string nom, string ape, int ann)
{
	
	Cedula = ced;
	Nombre = nom;
	Apellidos = ape;
	AnioNacimiento = ann;
	NivelCrediticio = 3;//1,2,3-> capacidad de pago de motos segun su estilo. En este caso todos los clientes tienen capacidad de pago para cualquiera de las motos.

}

Cliente::Cliente()
{
	Cedula = 0;
	Apellidos = "";
	AnioNacimiento = 0;
	NivelCrediticio = 3;
}

Cliente::~Cliente()
{
}

int Cliente::getCedula()
{
	return Cedula;
}

string Cliente::getNombre()
{
	return Nombre;
}

string Cliente::getApellidos()
{
	return Apellidos;
}

int Cliente::getAnioNacimiento()
{
	return AnioNacimiento;
}

int Cliente::getNivelCrediticio()
{
	return NivelCrediticio;
}

string Cliente::toString()
{
	stringstream s;
	s << "Nombre: " << Nombre << endl;
	s << "Apellidos: " << Apellidos << endl;
	s << "Cedula: " << Cedula << endl;
	s << "A"<<char(164)<<"o de nacimiento: " << AnioNacimiento << endl;
	s << "Nivel Crediticio: Credito Aprovado" <<endl;
	
	return s.str();
}

Cliente * Cliente::recuperarCliente(istream &entrada)
{
	string cedulaC, nombreC, apellidosC, anioNacimientoC;
	getline(entrada, cedulaC, DELIMITA_CAMPO);
	getline(entrada, nombreC, DELIMITA_CAMPO);
	getline(entrada, apellidosC, DELIMITA_CAMPO);
	getline(entrada, anioNacimientoC, DELIMITA_CAMPO);
	int valorCedula = convertirInt(cedulaC);
	int valorNacimiento = convertirInt(anioNacimientoC);
	return (new Cliente(valorCedula, nombreC, apellidosC, valorNacimiento));
}
