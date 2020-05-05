#include "Empresa.h"
#define DELIMITA_CAMPO '\t'
#define DELIMITA_REGISTRO '\n'

Empresa::Empresa()
{
	nombre="Deals on Wheels";
	telefono = "2211-8000";
	cedulaJuridica="AB155Z0011";
	direccion ="Direccion: La Uruca, 300 mts este de la Plaza de Deportes, Calle 32 108, San Jose, 1388 1000";
	ventas = new Contrato*[100];
	for (int i = 0; i < 100; i++) {
		ventas[i] = NULL;
	}

	pagosPersona = new Pago*[1000];
	for (int i = 0; i < 1000; i++) {
		pagosPersona[i] = NULL;
	}
	cantidad = 0;
	can = 0;
}

Empresa::~Empresa()
{
}

string Empresa::stringInfoEmpresa()
{
	stringstream s;
	s <<"Nombre: "<< nombre << endl;
	s <<"Telefono: " <<telefono << endl;
	s <<"Cedula juridica: "<< cedulaJuridica << endl;
	s << direccion << endl;
	return s.str();
}






void Empresa::agregarVenta(Contrato *c)
{

	if (cantidad < 100) {
		ventas[cantidad] = c;
		cantidad++;
	}
	
}

string Empresa::toStringVentas()
{
	stringstream s;
	for (int i = 0; i < cantidad; i++) {
		s <<"Cliente Numero: "<<i+1<<endl<< ventas[i]->toStringNombreCedula();
		
	}
	
	return s.str();

	
}

string Empresa::toStringPersonaPago()
{
	stringstream s;
	for (int j = 0; j < cantidad; j++) {
		s << "-----------------------------------------Persona Numero: " << j + 1 << "----------------------------------------" << endl<<endl;
		//s << ventas[j]->toString();

		
	}

	return s.str();


}


int Empresa::getCantidad()
{
	return cantidad;
}

string Empresa::buscaImprimeCliente(int c)
{

	stringstream s;
	int ced=c;
	
	for (int i = 0; i < cantidad; i++) {
		if (ventas[i]->getCedula() == ced) {
			 s<<ventas[i]->toString(ced);
			 return s.str();
		}
		
	}
	
}
void Empresa::hacerPago(int c,int n)
{
	int ced = c;
	int num = n - 1;

	for (int i = 0; i < cantidad; i++) {
		if (ventas[i]->getCedula() == ced) {
			ventas[i]->getCalendario()->getContenedorPago(num)->setEstado('C');
			
		}

	}





}



void Empresa::guardar()
{

	string rutaArchivo = "../Datos.txt";
	ofstream salida;
	salida.open(rutaArchivo.c_str());
	for (int i = 0; i < cantidad; i++) {
		ventas[i]->guardar(salida);
	}
	salida.close();
	//---------------------------------------------------------------
	string rutaArchi = "../PagosPersona.txt";
	ofstream sali;
	sali.open(rutaArchi.c_str());
	for (int i = 0; i < cantidad; i++) {
		ventas[i]->guardarFechas(sali);
	}
	sali.close();
}



void Empresa::guardaPendientes() {
	string rutaArchivo = "../CobrosPendientes.txt";
	ofstream salida;
	salida.open(rutaArchivo.c_str());
	for (int i = 0; i < cantidad; i++) {
		ventas[i]->guardarPendientes(salida);
	}
	salida.close();

}

void Empresa::guardaClienteEspecifico(int c)
{
	int ced = c;

	for (int i = 0; i < cantidad; i++) {
		if (ventas[i]->getCedula() == ced) {
			string n = ventas[i]->getNom();
			string a = ventas[i]->getApe();
			
			
			string s = "../"+n+a+"Contrato.txt";
			
			string rutaArchivo = s;
			ofstream salida;
			salida.open(rutaArchivo.c_str());
			
	    	ventas[i]->guardarEspecifico(salida);
			
			salida.close();
		}

	}
}

void Empresa::guardarContratosPorFecha(int d, int m, int a)
{


	for (int i = 0; i < cantidad; i++) {
		int dia = d;
		int mes = m;
		int anio = a;
		if ((ventas[i]->getDia()==dia)&& (ventas[i]->getMes() == mes) && (ventas[i]->getAnio() == anio)) {
		int x =ventas[i]->getDia();
			int y = ventas[i]->getMes();
			int z= ventas[i]->getAnio();
			string di = stringConvierteFecha(x);
			string me = stringConvierteFecha(y);
			string an = stringConvierteFecha(z);
			cout << dia;


			string s = "../"+di+"/"+me+"/"+an+"Contratos.txt";
			cout << s;
			string rutaArchivo = "../Contratos.txt";
			ofstream salida;
			salida.open(rutaArchivo.c_str());

			ventas[i]->guardarFechaEspecifica(salida);

			salida.close();
		}

	}




}

string Empresa::stringConvierteFecha(int x)
{
	int xx = x;
	stringstream s;
	s << xx;
	return s.str();

}




void Empresa::sobreescribeFechas()
{
	string rutaArchivo = "../PagosPersona.txt";
	ofstream salida;
	salida.open(rutaArchivo.c_str());
	for (int i = 0; i < can; i++) {
		pagosPersona[i]->guardarPagos(salida);
	}
	salida.close();
}

void Empresa::setNombre( string n)
{
	nombre = n;
}

void Empresa::setTelefono(string t)
{
	telefono = t;
}

void Empresa::setCedulaJuridica(string cd)
{
	cedulaJuridica = cd;
}

void Empresa::setDireccion(string d)
{
	direccion = d;
}

void Empresa::recuperar()
{
	string rutaArchivo = "../Datos.txt";
	ifstream entrada(rutaArchivo.c_str());
	while (entrada.good()) {
	Contrato* c= Contrato::recuperar(entrada);
	if (entrada.good()) {
		if (cantidad < 100) {
			ventas[cantidad] = c;
			cantidad++;
		}
	}

	}

	entrada.close();
	//-------------------------pagos----------------------------------------
	/*string Archivo = "../PagosPersona.txt";
	ifstream entra(Archivo.c_str());
	while (entra.good()) {
		Pago* p = Pago::recuperarPagos(entra);
		if (entra.good()) {
			if (can < 1000) {
				pagosPersona[can] = p;
				can++;
			}
		}

	}
	entra.close();*/

}

string Empresa::catalogo()
{
	stringstream s;
	s << "-------------------Cilindrajes--------------------" << endl;
	s << "125cc-->$500\n150cc\-->$1000\n200cc-->$2000" << endl<<endl;

	s << "-----------------------Harley---------------------" << endl;
	s << "Precio Base-->$200,000" << endl<<endl;
	s << "Estilos:    | Softtail: |  Trike: | CVO :" << endl;
	s << "1) +$30,000 |  Bob      | Wheeler | Street" << endl;
	s << "2) +$35,000 |  Slim     | Glide   | Road" << endl;
	s << "3) +$45,000 |  Deluxe   | Ultra   | Limited" << endl<<endl<<endl;

	s << "------------------------Honda---------------------" << endl;
	s << "Precio Base-->$100,000" << endl << endl;
	s << "Estilos:    | Sport:  | Funcional: | Special: " << endl;
	s << "1) +$30,000 |  Wave   |   Plus     | CRF50F" << endl;
	s << "2) +$35,000 |  Elite  |   Rally    | CRF110F" << endl;
	s << "3) +$45,000 |  Cargo  |   Tornado  | CRF250R" << endl << endl << endl;

	s << "----------------------Yamaha----------------------" << endl;
	s << "Precio Base-->$50,000" << endl << endl;
	s << "Estilos:    | Scooter: | Deportiva: | Montaniera: " << endl;
	s << "1) +$30,000 |  Ray     |   REV      | XTZ" << endl;
	s << "2) +$35,000 |  Cygnus  |   Trucer   | PW50" << endl;
	s << "3) +$45,000 |  Max     |   Star     | 450F" << endl << endl << endl;

	return s.str();
}

void Empresa::agregarPagosPersona(Pago *p)
{

	if (can < 1000) {
		pagosPersona[can] = p;
		can++;
	}
}



/*void Empresa::guardarPagosPersona(ostream & salida)
{
for(int i=0;i<can;i++){

	double monto = pagosPersona[i]->getMonto();
	int AniosPlazo = pagosPersona[i]->getAniosPlazo();
	int Dia = pagosPersona[i]->getDia();
	//char estado = pagosPersona[i]->getContenedorPago[i]->getEstado();
	salida << monto << DELIMITA_CAMPO;
	salida << AniosPlazo << DELIMITA_CAMPO;
	salida << Dia << DELIMITA_REGISTRO;
	//salida << estado << DELIMITA_REGISTRO;
	can++;
}
}*/
