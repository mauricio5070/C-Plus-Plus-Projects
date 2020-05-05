#include "Contrato.h"
#define DELIMITA_CAMPO '\t'
#define DELIMITA_REGISTRO '\n'

Contrato::Contrato(Cliente * cli, Moto * mot, Calendario* cal)
{
	SYSTEMTIME time;
	GetLocalTime(&time);
	Dia = time.wDay;
	Mes = time.wMonth;
	Anio = time.wYear;
	cliente = cli;
	moto = mot;

	DatosEmpresa = "Nombe: Deals on Wheels\nCedula juridica: AB155Z0011\nDireccion: La Uruca, 300 mts este de la Plaza de Deportes, Calle 32 108, San Jose, 1388 1000\nTelefono: 2211-8000";

	Cal = cal;
	
}

Contrato::Contrato(Cliente * cli, Moto * mot,Pago** cont)
{
	SYSTEMTIME time;
	GetLocalTime(&time);
	Dia = time.wDay;
	Mes = time.wMonth;
	Anio = time.wYear;
	cliente = cli;
	moto = mot;
	Con = cont;
	DatosEmpresa = "Nombe: Deals on Wheels\nCedula juridica: AB155Z0011\nDireccion: La Uruca, 300 mts este de la Plaza de Deportes, Calle 32 108, San Jose, 1388 1000\nTelefono: 2211-8000";

	

}

Contrato::~Contrato()
{
}

string Contrato::toString(int ce)
{
	stringstream s;
	int c = ce;
	s << "Datos de la empresa:" << endl;
	s << DatosEmpresa << endl;
	s << endl << endl;
	s << "Datos del cliente:" << endl;
	s << cliente->toString() << endl;
	s << endl << endl;
	s << "Datos de la Moto: " << endl;
	s << moto->toString()<<endl;
	s << endl << endl;
	s << "Fecha de compra: " << Cal->getHoy() << "/" << Cal->getMes() << "/" << Cal->getAnnio() << endl;
	s << "A"<<char(164)<<"os plazo: " << Cal->getAniosPlazo() << endl;
	s << "Precio de la moto: $" << moto->getPrecio()<< endl;
	s << "Total de seguro por mes: $" << Cal->getSeguro()<< endl;
	s << "Total Final: $" << ((Cal->getSeguro())*(12*aniosPlazo))+(moto->getPrecio()) << endl<<endl;
	s << "-------------------------------Fechas de Pago----------------------------------- " << endl << endl;
	s << Cal->mostrarPagos(c) << endl; 
		return s.str();
}

int Contrato::getDia()
{
	//return Dia;
	int x = Cal->getDia();
	return x;
}

int Contrato::getMes()
{
	//return Mes;
	int x = Cal->getMes();
	return x;
}

int Contrato::getAnio()
{
	int x = Cal->getAnnio();
	return x;
	//return Anio;
}

int Contrato::getAniosPlazo()
{
	return aniosPlazo;
}

double Contrato::getMonto()
{
	return Monto;
}

Cliente * Contrato::getCliente()
{
	return cliente;
}

Calendario * Contrato::getCalendario()
{
	return Cal;
}

string Contrato::toStringNombreCedula()
{
	stringstream s;
	s << "Datos del cliente:" << endl;
	s << "Nombre: " << cliente->getNombre()<<" "<<cliente->getApellidos() <<endl<< "Cedula: " << cliente->getCedula() << endl;
	s << endl << endl;
	
	
	
	return s.str();
}

int Contrato::getCedula()
{
	return cliente->getCedula();
}

Contrato* Contrato::recuperar(istream & entrada)
{
	string cilindrajeC, estiloC, modeloC, numSerieC, marcaC, placaC, montoC;
	
	Cliente* C = Cliente::recuperarCliente(entrada);
	getline(entrada, cilindrajeC, DELIMITA_CAMPO);
	getline(entrada, estiloC, DELIMITA_CAMPO);
	getline(entrada, modeloC, DELIMITA_CAMPO);
	getline(entrada, numSerieC, DELIMITA_CAMPO);
	getline(entrada, marcaC, DELIMITA_CAMPO);
	getline(entrada, placaC, DELIMITA_CAMPO);

	
	//------------------------------------------------------------------------------------------

	int valorCilindraje = convertirInt(cilindrajeC);
	int valorEstilo = convertirInt(estiloC);
	int valorModelo = convertirInt(modeloC);
	int valorNumSerie = convertirInt(numSerieC);
	int valorMarca = convertirInt(marcaC);
	

	
	if (valorMarca == 1) {

		Calendario* K = Calendario::recuperarCalendario(entrada);
		MotoHarley* F= new MotoHarley(valorCilindraje, valorEstilo, valorModelo, valorNumSerie, placaC);
			
			return(new Contrato(C, F, K));
			
	}
	if (valorMarca == 2) {
	
		MotoHonda* F = new MotoHonda(valorCilindraje, valorEstilo, valorModelo, valorNumSerie, placaC);
		Calendario* K = Calendario::recuperarCalendario(entrada);
		return(new Contrato(C, F, K));
	
	}
	if (valorMarca == 3) {
	
		MotoYamaha* F = new MotoYamaha(valorCilindraje, valorEstilo, valorModelo, valorNumSerie, placaC);
		Calendario* K = Calendario::recuperarCalendario(entrada);
		return(new Contrato(C, F, K));
		
	}



}

void Contrato::guardar(ostream & salida)
{
	//-------------------------guardar cliente-----------------------------
	int Cedula = cliente->getCedula();
	string Nombre = cliente->getNombre();
	string Apellidos = cliente->getApellidos();
	int AnioNacimiento = cliente->getAnioNacimiento();
    salida << Cedula << DELIMITA_CAMPO;
	salida << Nombre << DELIMITA_CAMPO;
	salida << Apellidos << DELIMITA_CAMPO;
	salida << AnioNacimiento << DELIMITA_CAMPO;
	//-----------------------------Guardar moto--------------------------------
	int cilindraje = moto->getCilindraje();
	int estilo = moto->getEstilo();
	int modelo = moto->getModelo();
	int numSerie = moto->getNumSerie();
	int marca = moto->getMar();
	string placa = moto->getPlaca();
	salida << cilindraje << DELIMITA_CAMPO;
	salida << estilo << DELIMITA_CAMPO;
	salida << modelo << DELIMITA_CAMPO;
	salida << numSerie << DELIMITA_CAMPO;
	salida << marca << DELIMITA_CAMPO;
	salida << placa << DELIMITA_CAMPO;
	//----------------------------guardar calendario----------------------
	double monto = Cal->getMonto();
	int AniosPlazo = Cal->getAniosPlazo();
	int Dia = Cal->getDia();
	int Hoy = Cal->getHoy();
	int Mess = Cal->getMes();
	int Annio = Cal->getAnnio();
	int Ced= cliente->getCedula();
	salida << Ced << DELIMITA_CAMPO;
	salida << monto << DELIMITA_CAMPO;
	salida << AniosPlazo << DELIMITA_CAMPO;
	salida << Dia << DELIMITA_CAMPO;
	salida << Hoy<< DELIMITA_CAMPO;
	salida << Mess << DELIMITA_CAMPO;
	salida << Annio << DELIMITA_REGISTRO;

}

string Contrato::getNom()
{
	string NOM = cliente->getNombre();

	return NOM;
}

string Contrato::getApe()
{
	string NOM = cliente->getApellidos();

	return NOM;
}

void Contrato::guardarFechas(ostream & salida)
{
	//---------------------------guardar fechas-----------------------------
	int cant = Cal->getCantidad();
	
	for (int i = 0; i < cant; i++) {
	
 int D= Cal->getDia(i);
	int M=Cal->getMes(i);
	int A= Cal->getAnio(i);
	double Mon= Cal->getMonto(i);
	char Est = Cal->getEstado(i);
	int I_D = Cal->getId(i);
	salida << D << DELIMITA_CAMPO;
	salida << M << DELIMITA_CAMPO;
	salida << A << DELIMITA_CAMPO;
	salida << Mon << DELIMITA_CAMPO;
	salida << Est << DELIMITA_CAMPO;
	salida << I_D << DELIMITA_REGISTRO;
	}
}

void Contrato::guardarPendientes(ostream &salida)
{



	int cant = Cal->getCantidad();
	//salida << tam << DELIMITA_REGISTRO;
	for (int i = 0; i < cant; i++) {
		string Nombre = cliente->getNombre();
		string Apellidos = cliente->getApellidos();
		salida << Nombre << DELIMITA_CAMPO;
		salida << Apellidos << DELIMITA_REGISTRO;
		if (Cal->getEstado(i) == 'P') {
			int D = Cal->getDia(i);
			int M = Cal->getMes(i);
			int A = Cal->getAnio(i);
			double Mon = Cal->getMonto(i);
			char Est = Cal->getEstado(i);
			int I_D = Cal->getId(i);
			salida << D << DELIMITA_CAMPO;
			salida << M << DELIMITA_CAMPO;
			salida << A << DELIMITA_CAMPO;
			salida << Mon << DELIMITA_CAMPO;
			salida << Est << DELIMITA_CAMPO;
			salida << I_D << DELIMITA_REGISTRO;
		
			SYSTEMTIME time;
			GetLocalTime(&time);
			int diaActual = time.wDay;
			int mesActual = time.wMonth;
			int anioActual = time.wYear;
		if((M<=mesActual)&&(diaActual>D)){
			double recargo = Mon*0.05;
			int atraso = diaActual - D;
		
			salida << "Recargo por atraso-->"<<recargo << DELIMITA_CAMPO;
			salida <<"Dias de atraso--> "<<atraso<< DELIMITA_REGISTRO;
		
		}
		
		
		}


	}

}

void Contrato::guardarEspecifico(ostream &salida)
{

	//-------------------------guardar cliente-----------------------------
	int Cedula = cliente->getCedula();
	string Nombre = cliente->getNombre();
	string Apellidos = cliente->getApellidos();
	int AnioNacimiento = cliente->getAnioNacimiento();
	salida << Cedula << DELIMITA_CAMPO;
	salida << Nombre << DELIMITA_CAMPO;
	salida << Apellidos << DELIMITA_CAMPO;
	salida << AnioNacimiento << DELIMITA_CAMPO;
	//-----------------------------Guardar moto--------------------------------
	int cilindraje = moto->getCilindraje();
	int estilo = moto->getEstilo();
	int modelo = moto->getModelo();
	int numSerie = moto->getNumSerie();
	int marca = moto->getMar();
	string placa = moto->getPlaca();
	salida << cilindraje << DELIMITA_CAMPO;
	salida << estilo << DELIMITA_CAMPO;
	salida << modelo << DELIMITA_CAMPO;
	salida << numSerie << DELIMITA_CAMPO;
	salida << marca << DELIMITA_CAMPO;
	salida << placa << DELIMITA_CAMPO;
	//----------------------------guardar calendario----------------------
	double monto = Cal->getMonto();
	int AniosPlazo = Cal->getAniosPlazo();
	int Dia = Cal->getDia();
	int Hoy = Cal->getHoy();
	int Mess = Cal->getMes();
	int Annio = Cal->getAnnio();
	int Ced = cliente->getCedula();
	salida << Ced << DELIMITA_CAMPO;
	salida << monto << DELIMITA_CAMPO;
	salida << AniosPlazo << DELIMITA_CAMPO;
	salida << Dia << DELIMITA_CAMPO;
	salida << Hoy << DELIMITA_CAMPO;
	salida << Mess << DELIMITA_CAMPO;
	salida << Annio << DELIMITA_REGISTRO;
	salida << "------------------------------------------------------------------------------------" << DELIMITA_REGISTRO;
	salida << "Dia" << DELIMITA_CAMPO;
	salida << "Mes" << DELIMITA_CAMPO;
	salida << "Anio" << DELIMITA_CAMPO;
	salida << "Monto" << DELIMITA_CAMPO;
	salida << "Estado" << DELIMITA_CAMPO;
	salida << "Cedula" << DELIMITA_REGISTRO;
	salida << "------------------------------------------------------------------------------------" << DELIMITA_REGISTRO;
	int cant = Cal->getCantidad();

	for (int i = 0; i < cant; i++) {

		int D = Cal->getDia(i);
		int M = Cal->getMes(i);
		int A = Cal->getAnio(i);
		double Mon = Cal->getMonto(i);
		char Est = Cal->getEstado(i);
		int I_D = Cal->getId(i);
		salida << D << DELIMITA_CAMPO;
		salida << M << DELIMITA_CAMPO;
		salida << A << DELIMITA_CAMPO;
		salida << Mon << DELIMITA_CAMPO;
		salida << Est << DELIMITA_CAMPO;
		salida << I_D << DELIMITA_REGISTRO;
	}

}

void Contrato::guardarFechaEspecifica(ostream & salida)
{
	//-------------------------guardar cliente-----------------------------
	int Cedula = cliente->getCedula();
	string Nombre = cliente->getNombre();
	string Apellidos = cliente->getApellidos();
	int AnioNacimiento = cliente->getAnioNacimiento();
	salida << Cedula << DELIMITA_CAMPO;
	salida << Nombre << DELIMITA_CAMPO;
	salida << Apellidos << DELIMITA_CAMPO;
	salida << AnioNacimiento << DELIMITA_CAMPO;
	//-----------------------------Guardar moto--------------------------------
	int cilindraje = moto->getCilindraje();
	int estilo = moto->getEstilo();
	int modelo = moto->getModelo();
	int numSerie = moto->getNumSerie();
	int marca = moto->getMar();
	string placa = moto->getPlaca();
	salida << cilindraje << DELIMITA_CAMPO;
	salida << estilo << DELIMITA_CAMPO;
	salida << modelo << DELIMITA_CAMPO;
	salida << numSerie << DELIMITA_CAMPO;
	salida << marca << DELIMITA_CAMPO;
	salida << placa << DELIMITA_CAMPO;
	//----------------------------guardar calendario----------------------
	double monto = Cal->getMonto();
	int AniosPlazo = Cal->getAniosPlazo();
	int Dia = Cal->getDia();
	int Hoy = Cal->getHoy();
	int Mess = Cal->getMes();
	int Annio = Cal->getAnnio();
	int Ced = cliente->getCedula();
	salida << Ced << DELIMITA_CAMPO;
	salida << monto << DELIMITA_CAMPO;
	salida << AniosPlazo << DELIMITA_CAMPO;
	salida << Dia << DELIMITA_CAMPO;
	salida << Hoy << DELIMITA_CAMPO;
	salida << Mess << DELIMITA_CAMPO;
	salida << Annio << DELIMITA_REGISTRO;
	salida << "------------------------------------------------------------------------------------" << DELIMITA_REGISTRO;
	salida << "Dia" << DELIMITA_CAMPO;
	salida << "Mes" << DELIMITA_CAMPO;
	salida << "Anio" << DELIMITA_CAMPO;
	salida << "Monto" << DELIMITA_CAMPO;
	salida << "Estado" << DELIMITA_CAMPO;
	salida << "Cedula" << DELIMITA_REGISTRO;
	salida << "------------------------------------------------------------------------------------" << DELIMITA_REGISTRO;
	int cant = Cal->getCantidad();

	for (int i = 0; i < cant; i++) {

		int D = Cal->getDia(i);
		int M = Cal->getMes(i);
		int A = Cal->getAnio(i);
		double Mon = Cal->getMonto(i);
		char Est = Cal->getEstado(i);
		int I_D = Cal->getId(i);
		salida << D << DELIMITA_CAMPO;
		salida << M << DELIMITA_CAMPO;
		salida << A << DELIMITA_CAMPO;
		salida << Mon << DELIMITA_CAMPO;
		salida << Est << DELIMITA_CAMPO;
		salida << I_D << DELIMITA_REGISTRO;
	}
}
