#include "Pago.h"
#define DELIMITA_CAMPO '\t'
#define DELIMITA_REGISTRO '\n'
Pago::Pago(int dia, int mes, int anio, double monto, char est,int id)
{
	Dia = dia;
	Mes = mes;
	Anio = anio;
	Monto= monto;
	Estado = est; // P--->Pendiente  C--->Cancelado
	ID = id;

}

Pago::~Pago()
{
}

string Pago::toString()
{
	stringstream s;

	s << "Fecha de Pago: " << Dia << "/" << Mes << "/" << Anio << endl;
	s << "Monto a cancelar: $" << Monto << endl;
	s << endl;
	return s.str();
}

string Pago::toStringConEstado()
{
	stringstream s;

	s << "Fecha de Pago: " << Dia << "/" << Mes << "/" << Anio << endl;
	s << "Monto a cancelar: $" << Monto << endl;
	s << "Estado (P=pendiente/C=cancelado): " << Estado << endl;
	s << endl;
	return s.str();
}

char Pago::getEstado()
{
	return Estado;
}

void Pago::setEstado(char e)
{ 
	Estado = e;
}

double Pago::getMonto()
{
	return Monto;
}

Pago * Pago::returnPago()
{
	return new Pago(Dia,Mes,Anio,Monto,Estado,ID);
	
}

int Pago::getDia()
{
	return Dia;
}

int Pago::getMes()
{
	return Mes;
}

int Pago::getAnio()
{
	return Anio;
}

int Pago::getId()
{
	return ID;
}

Pago * Pago::recuperarPagos(istream &entrada)
{
	string  tamC,DC, MC, AC, monC, estC, idC;

	//getline(entrada, tamC, DELIMITA_REGISTRO);
	//int valorTam = convertirInt(tamC);
	//for (int i = 0; i < valorTam; i++) {
		getline(entrada, DC, DELIMITA_CAMPO);
		getline(entrada, MC, DELIMITA_CAMPO);
		getline(entrada, AC, DELIMITA_CAMPO);
		getline(entrada, monC, DELIMITA_CAMPO);
		getline(entrada, estC, DELIMITA_CAMPO);
		getline(entrada, idC, DELIMITA_REGISTRO);

		int valorD = convertirInt(DC);
		int valorM = convertirInt(MC);
		int valorA = convertirInt(AC);
		double valorMon = convertirDouble(monC);
		char valorEst = convertirChar(estC);
		int valorId = convertirInt(idC);

		return(new Pago(valorD, valorM, valorA, valorMon, valorEst,valorId));
	//}
}






void Pago::guardarPagos(ostream & salida)
{

	//int tam = Cal->getTam();
	//salida << tam << DELIMITA_REGISTRO;
	
		int D = getDia();
		int M = getMes();
		int A = getAnio();
		double Mon = getMonto();
		char Est = getEstado();
		int I_D = getId();
		salida << D << DELIMITA_CAMPO;
		salida << M << DELIMITA_CAMPO;
		salida << A << DELIMITA_CAMPO;
		salida << Mon << DELIMITA_CAMPO;
		salida << Est << DELIMITA_CAMPO;
		salida << I_D << DELIMITA_REGISTRO;
}

void Pago::setDia(int d)
{
	Dia = d;
}

void Pago::setMes(int m)
{
	Mes = m;
}

void Pago::setAnio(int a)
{
	Anio = a;
}
