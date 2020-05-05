#include "Calendario.h"
#define DELIMITA_CAMPO '\t'
#define DELIMITA_REGISTRO '\n'

Calendario::Calendario(double monto,int aniosPlazo, int diaPago, int ced)
{
	SYSTEMTIME time;
	GetLocalTime(&time);
	Dia = diaPago;
	Hoy = time.wDay;
	Mes = time.wMonth;
	Anio =time.wYear;
	AniosPlazo = aniosPlazo;
	cantidad = 0;
	cedula = ced;
	tam = (AniosPlazo * 12); //maximo 5 años plazo
	for (int i = 0; i < tam; i++) {
		contenedor = new Pago*[tam];
		contenedor[i] = NULL;

	}
	
	Monto = monto;
	Seguro = Monto*0.001;
	
	
		this->crearPagos();

}

Calendario::Calendario(int id, double monto, int aniosPlazo, int diaPago, int hoy, int mes, int anio)
{
	cantidad = 0;
	Dia = diaPago;
	Hoy = hoy;
	Mes = mes;
	ced = id;
	Anio = anio;
	AniosPlazo = aniosPlazo;
	Monto = monto;
	Seguro = Monto*0.001;
	tam = (AniosPlazo * 12); //maximo 5 años plazo
	for (int i = 0; i < tam; i++) {
		contenedor = new Pago*[tam];
		contenedor[i] = NULL;

	}
	this->recuperarPagos(ced);

	
}


void Calendario::recuperarPagos(int c)
{
	int ced = c;
	string Archivo = "../PagosPersona.txt";
	ifstream entra(Archivo.c_str());
	while (entra.good()) {
		Pago* p = Pago::recuperarPagos(entra);
		if (entra.good()) {
			if (cantidad < 1000) {
				if (p->getId() == ced) {
					contenedor[cantidad] = p;
					cantidad++;
				}
			}
		}

	}

	entra.close();


}







/*Pago * Calendario::getPago()
{
	return pago;
}*/

void Calendario::agregarPago(Pago *p)
{
	int cantida = 0;


	contenedor[cantida] = p;
	
	cantida++;
}


void Calendario::crearPagos()
{
	double pagoMensual = (Monto / tam)+ Seguro;
	int d = Dia;
	int m = Mes;
	int a = Anio;
	int c = cedula;


	

	
	while (cantidad < tam) {
		Pago* P = new Pago(d, m, a, pagoMensual, 'P', c);

		if ((P->getDia() > 28) &&( P->getMes()==2)) {
			
			P->setDia(28);
		contenedor[cantidad] = new Pago(28,m,a,pagoMensual, 'P',c);
			//contenedor[cantidad] = P;
		}

		else if ((P->getDia() == 31) && ((P->getMes() == 4) || (P->getMes() == 6) || (P->getMes() == 9) || (P->getMes() == 11))){
				
				contenedor[cantidad] = new Pago(30, m, a, pagoMensual, 'P',c);
			P->setDia(30);

			//contenedor[cantidad] = P;
		}


			
			
		else { contenedor[cantidad] = P; }

			if (m == 12) { m = 0; a++; }
			if (m < 13) { m++; }

			

			cantidad++;
		}

	

}

double Calendario::getSeguro()
{
	return Seguro;
}

double Calendario::getMonto()
{
	return Monto;
}

int Calendario::getAniosPlazo()
{
	return AniosPlazo;
}

int Calendario::getDia()
{
	return Dia;
}

Pago * Calendario::getContenedorPago(int i)
{
	//for (int i = 0; i < cantidad; i++) {
		//Pago* p = contenedor[i]->returnPago();

		return contenedor[i];
	//}
}

void Calendario::guardarPagosPersona(ostream &sali)
{

	double monto = getMonto();
	int AniosPlazo = getAniosPlazo();
	int Dia = getDia();
	int Hoy = getHoy();
	int Mes = getMes();
	int Annio = getAnnio();
	for (int i = 0; i < cantidad; i++) {
		char estado = contenedor[i]->getEstado();
	}
	sali << monto << DELIMITA_CAMPO;
	sali << AniosPlazo << DELIMITA_CAMPO;
	sali << Dia << DELIMITA_CAMPO;
	sali << Hoy << DELIMITA_CAMPO;
	sali << Mes << DELIMITA_CAMPO;
	sali << Annio << DELIMITA_REGISTRO;
	//sali <<estado<< DELIMITA_REGISTRO;
	
}

string Calendario::mostrarPagos(int c)
{
	stringstream s;
	int ced= c;
	for (int i = 0; i < cantidad; i++) {
		if (contenedor[i]->getId() == ced) {
			s <<i+1<<"): "<< contenedor[i]->toStringConEstado();
		}
	}
	return s.str();
}

int Calendario::getHoy()
{
	return Hoy;
}

int Calendario::getMes()
{
	return Mes;
}

int Calendario::getAnnio()
{
	return Anio;
}

int Calendario::getTam()
{
	return tam;
}

int Calendario::getCantidad()
{
	return cantidad;
}


int Calendario::getDia(int i)
{
	int a=contenedor[i]->getDia();
	return a;
}

int Calendario::getMes(int i)
{
	int a = contenedor[i]->getMes();
	return a;
}

int Calendario::getAnio(int i)
{
	int a = contenedor[i]->getAnio();
	return a;
}

int Calendario::getId(int i)
{
	int a = contenedor[i]->getId();
	return a;
}

double Calendario::getMonto(int i)
{
	double a = contenedor[i]->getMonto();
	return a;
}

char Calendario::getEstado(int i)
{
	char a = contenedor[i]->getEstado();
	return a;
}

Calendario * Calendario::recuperarCalendario(istream &entrada)
{
	string cedC, montoC, aniosPlazoC, diaC, hoyC, mesC, annioC, tamC, DC, MC, AC, monC, estC;
	
	getline(entrada, cedC, DELIMITA_CAMPO);
	getline(entrada, montoC, DELIMITA_CAMPO);
	getline(entrada, aniosPlazoC, DELIMITA_CAMPO);
	getline(entrada, diaC, DELIMITA_CAMPO);
	getline(entrada, hoyC, DELIMITA_CAMPO);
	getline(entrada, mesC, DELIMITA_CAMPO);
	getline(entrada, annioC, DELIMITA_REGISTRO);
	//getline(entrada, tamC, DELIMITA_REGISTRO);

	double valorMonto = convertirDouble(montoC);
	int valorAniosPlazo = convertirInt(aniosPlazoC);
	int valorDia = convertirInt(diaC);
	int valorHoy = convertirInt(hoyC);
	int valorMes = convertirInt(mesC);
	int valorAnnio = convertirInt(annioC);
	int valorCed = convertirInt(cedC);

	



				return(new Calendario(valorCed,valorMonto, valorAniosPlazo, valorDia, valorHoy, valorMes, valorAnnio));

	
}

