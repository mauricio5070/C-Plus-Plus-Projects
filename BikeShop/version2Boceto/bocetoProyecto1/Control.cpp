#include "Control.h"

Control::Control()
{
	E = new Empresa();
	E->recuperar();

}

void Control::iniciar()
{

	Interfaz I; int opc; bool continuar = true;
	do {
		I.imprimeString("\tBienvenido al sistema de Deals on Wheels\n");
		I.imprimeString("1- Registrar Compra-cliente-contrato\n");
		I.imprimeString("2- Mostrar ventas (reportes por cliente)\n");
		I.imprimeString("3- Mostrar Datos de la Empresa\n");
		I.imprimeString("4- Mostrar Clientes\n");
		I.imprimeString("5- Catalogo de Motos\n");
		I.imprimeString("6- Realiza un pago\n");
		I.imprimeString("7- Modifica informacion de la empresa\n");
		I.imprimeString("8- Generar archivo con cobros pendientes de la empresa\n");
		I.imprimeString("9- Generar archivo con  contratos de una persona especifica\n");
		I.imprimeString("10- Generar archivo con  contratos de  personas por fecha\n");
		I.imprimeString("0- SALIR DEL SISTEMA\n");
		I.imprimeString("\tDigite una opcion: "); opc = I.retornaInt();


		switch (opc) {
		case 0:
			E->guardar();
			continuar = false;
			delete E;
			break;

		case 1:
			system("cls");
			try{
			agregarCompra();
			}
			catch (int error) {

				if (error == 0) {

					I.imprimeString("Elige un numero entre 1 y 3\n\n");
				}
			
			}
			system("pause");
			system("cls");
			break;
		case 2:
			system("cls");
			mostrarCompras();
			system("pause");
			system("cls");
			break;
		case 3:
			system("cls");
			mostrarDatosEmpresa();
			system("pause");
			system("cls");
			break;
		case 4:
			system("cls");
			mostrarClientes();
			system("pause");
			system("cls");
			break;
		case 5:
			system("cls");
			mostrarCatalogo();
			system("pause");
			system("cls");
			break;
		case 6:
			system("cls");
			realizaPagos();
			system("pause");
			system("cls");
			break;
		case 7:
			system("cls");
			modificaEmpresa();
			system("pause");
			system("cls");
			break;
		case 8:
			system("cls");
			generarPendientes();
			system("pause");
			system("cls");
			break;
		case 9:
			system("cls");
			generarEspecifico();
			system("pause");
			system("cls");
			break;
		case 10:
			system("cls");
			generarReporteFecha();
			system("pause");
			system("cls");
			break;


		default:
			system("cls");
			I.imprimeString("OPCION INVALIDA\n"); system("pause"); system("cls");

		}
	} while (continuar);
}



void Control::agregarCompra()
{
	//-------------------------------armando Moto---------------------------------
	Interfaz I;
	int op;
	

	
		I.imprimeString("Marcas de Motos\n"
			"1-Harley\n"
			"2-Honda\n"
			"3-Yamaha\n");
		I.imprimeString("Digite una opcion:");
		op = I.retornaInt();
			
			if (0 > op > 4) {  throw 0; }
	

		if (op == 1) {
			int cilindraje;
			int estilo;
			int modelo;
			string placa;
			int numSerie;
			
				I.imprimeString("Cilindraje:\n"
					"1-125cc\n"
					"2-150cc\n"
					"3-200cc\n");
				cilindraje = I.retornaInt();
				//if (0 > cilindraje> 4) { throw 0; }
				I.imprimeString("Estilo:\n"
					"1-Softail\n"
					"2-Trike\n"
					"3-CVO\n");
				estilo = I.retornaInt();

				//if (0 > cilindraje> 4) { throw 1; }
				//if (0 > estilo > 4) { throw 0; }



				if (estilo == 1) {
					I.imprimeString("Modelo:\n"
						"1-BOB\n"
						"2-SLIM\n"
						"3-Deluxe\n");
					modelo = I.retornaInt();
				}
				if (estilo == 2) {
					I.imprimeString("Modelo:\n"
						"1-Wheeler\n"
						"2-Glide\n"
						"3-Ultra\n");
					modelo = I.retornaInt();
				}
				if (estilo == 3) {
					I.imprimeString("Modelo:\n"
						"1-Street\n"
						"2-Road\n"
						"3-Limited\n");
					modelo = I.retornaInt();
				}

				I.imprimeString("Digite el numero de serie:");
				numSerie = I.retornaInt();
				I.imprimeString("Digite la placa:");
				placa = I.retornaString();
				MotoHarley* M = new MotoHarley(cilindraje, estilo, modelo, numSerie, placa);
				//-------------creando cliente-------------------------------------
				int cedula;
				string nombre;
				string apellidos;
				int anio;
				I.imprimeString("Digite el nombre de la persona: ");
				nombre = I.retornaStringIgnore();

				I.imprimeString("Digite los apellidos de la persona: ");
				apellidos = I.retornaStringGetLine();
				I.imprimeString("Digite la cedula de la persona: ");
				cedula = I.retornaInt();
				I.imprimeString("Digite anio de nacimiento de la persona: ");
				anio = I.retornaInt();
				//-------------------------------creando calendario----------------

				int aniosPlazo;
				int dia, hoy, mes, annio;

				I.imprimeString("Digite los anos plazo a los que quiere el contrato: ");
				aniosPlazo = I.retornaInt();
				I.imprimeString("Digite el dia de pago que desea(1-31): ");
				dia = I.retornaInt();
				/*	I.imprimeString("Digite la fecha de hoy\n" );
					I.imprimeString("Dia: ");
					hoy = I.retornaInt();
					I.imprimeString("Mes: ");
					 mes = I.retornaInt();
					I.imprimeString("Anio: ");
					annio = I.retornaInt();*/
				double monto = M->getPrecio();
				Calendario* cal = new Calendario(monto, aniosPlazo, dia, cedula);
				Cliente* cli = new Cliente(cedula, nombre, apellidos, anio);
				Contrato* cont = new Contrato(cli, M, cal);

				E->agregarVenta(cont);

			}


			if (op == 2) {
				int cilindraje;
				int estilo;
				int modelo;
				string placa;
				int numSerie;
				I.imprimeString("Cilindraje:\n"
					"1-125cc\n"
					"2-150cc\n"
					"3-200cc\n");
				cilindraje = I.retornaInt();
				I.imprimeString("Estilo:\n"
					"1-Sport\n"
					"2-Funcional\n"
					"3-Special\n");
				estilo = I.retornaInt();
				if (estilo == 1) {
					I.imprimeString("Modelo:\n"
						"1-Wave\n"
						"2-Elite\n"
						"3-Cargo\n");
					modelo = I.retornaInt();
				}
				if (estilo == 2) {
					I.imprimeString("Modelo:\n"
						"1-Plus\n"
						"2-Rally\n"
						"3-Tornado\n");
					modelo = I.retornaInt();
				}
				if (estilo == 3) {
					I.imprimeString("Modelo:\n"
						"1-CRF50F\n"
						"2-CRF110F\n"
						"3-CRF250R\n");
					modelo = I.retornaInt();
				}
				I.imprimeString("Digite el numero de serie:");
				numSerie = I.retornaInt();
				I.imprimeString("Digite la placa:");
				placa = I.retornaString();
				MotoHonda* M = new MotoHonda(cilindraje, estilo, modelo, numSerie, placa);
				//-------------creando cliente-------------------------------------
				int cedula;
				string nombre;
				string apellidos;
				int anio;
				I.imprimeString("Digite el nombre de la persona: ");
				nombre = I.retornaStringIgnore();

				I.imprimeString("Digite el apellido de la persona: ");
				apellidos = I.retornaStringGetLine();
				I.imprimeString("Digite la cedula de la persona: ");
				cedula = I.retornaInt();
				I.imprimeString("Digite anio de nacimiento de la persona: ");
				anio = I.retornaInt();
				//-------------------------------creando calendario----------------

				int aniosPlazo;
				int dia, hoy, mes, annio;
				I.imprimeString("Digite los anios plazo a los que quiere el contrato: ");
				aniosPlazo = I.retornaInt();
				I.imprimeString("Digite el dia de pago que desea(1-31): ");
				dia = I.retornaInt();
				/*I.imprimeString("Digite la fecha de hoy\n");
				I.imprimeString("Dia: ");
				hoy = I.retornaInt();
				I.imprimeString("Mes: ");
				 mes = I.retornaInt();
				I.imprimeString("Anio: ");
				 annio = I.retornaInt();*/
				double monto = M->getPrecio();
				Calendario* cal = new Calendario(monto, aniosPlazo, dia, cedula);
				Cliente* cli = new Cliente(cedula, nombre, apellidos, anio);
				Contrato* cont = new Contrato(cli, M, cal);
				E->agregarVenta(cont);
			}

			if (op == 3) {
				int cilindraje;
				int estilo;
				int modelo;
				string placa;
				int numSerie;
				I.imprimeString("Cilindraje:\n"
					"1-125cc\n"
					"2-150cc\n"
					"3-200cc\n");
				cilindraje = I.retornaInt();
				I.imprimeString("Estilo:\n"
					"1-Scooter\n"
					"2-Deportiva\n"
					"3-Montaniera\n");
				estilo = I.retornaInt();
				if (estilo == 1) {
					I.imprimeString("Modelo:\n"
						"1-Ray\n"
						"2-Cygnus\n"
						"3-Max\n");
					modelo = I.retornaInt();
				}
				if (estilo == 2) {
					I.imprimeString("Modelo:\n"
						"1-REV\n"
						"2-Trucer\n"
						"3-Star\n");
					modelo = I.retornaInt();
				}
				if (estilo == 3) {
					I.imprimeString("Modelo:\n"
						"1-XTZ\n"
						"2-PW50\n"
						"3-450F\n");
					modelo = I.retornaInt();
				}
				I.imprimeString("Digite el numero de serie:");
				numSerie = I.retornaInt();
				I.imprimeString("Digite la placa:");
				placa = I.retornaString();
				MotoYamaha* M = new MotoYamaha(cilindraje, estilo, modelo, numSerie, placa);
				//-------------creando cliente-------------------------------------
				int cedula;
				string nombre;
				string apellidos;
				int anio;
				I.imprimeString("Digite el nombre de la persona: ");
				nombre = I.retornaStringIgnore();
				;
				I.imprimeString("Digite el apellido de la persona: ");
				apellidos = I.retornaStringGetLine();
				I.imprimeString("Digite la cedula de la persona: ");
				cedula = I.retornaInt();
				I.imprimeString("Digite anio de nacimiento de la persona: ");
				anio = I.retornaInt();
				//-------------------------------creando calendario----------------

				int aniosPlazo;
				int dia, hoy, mes, annio;
				I.imprimeString("Digite los anios plazo a los que quiere el contrato: ");
				aniosPlazo = I.retornaInt();
				I.imprimeString("Digite el dia de pago que desea(1-31): ");
				dia = I.retornaInt();
				/*I.imprimeString("Digite la fecha de hoy\n");
				I.imprimeString("Dia: ");
				 hoy = I.retornaInt();
				I.imprimeString("Mes: ");
				mes = I.retornaInt();
				I.imprimeString("Anio: ");
				 annio = I.retornaInt();*/
				double monto = M->getPrecio();
				Calendario* cal = new Calendario(monto, aniosPlazo, dia, cedula);

				Cliente* cli = new Cliente(cedula, nombre, apellidos, anio);
				Contrato* cont = new Contrato(cli, M, cal);
				E->agregarVenta(cont);


			}

		
	
}

void Control::mostrarCompras()
{
	I->imprimeString(E->toStringVentas());
	I->imprimeString("Digite el numero de cedula de la persona: ");
	int ced;
	ced= I->retornaInt();
	system("pause");
	system("cls");
	I->imprimeString(E->buscaImprimeCliente(ced));
}

void Control::mostrarDatosEmpresa()
{
	I->imprimeString(E->stringInfoEmpresa());

}

void Control::mostrarPagosPersona()
{
	I->imprimeString(E->toStringPersonaPago());
}

void Control::mostrarClientes()
{
	I->imprimeString(E->toStringVentas());
}

void Control::mostrarCatalogo()
{
	I->imprimeString(E->catalogo());
}

void Control::realizaPagos()
{


	I->imprimeString(E->toStringVentas());
	I->imprimeString("Digite el numero de cedula de la persona: ");
	int ced;
	ced = I->retornaInt();
	system("pause");
	system("cls");
	I->imprimeString(E->buscaImprimeCliente(ced));
	I->imprimeString("Digite el numero de pago que desea realizar: ");
	int num;
	num = I->retornaInt();
	E->hacerPago(ced, num);
	I->imprimeString("Pago realizado!!!! ");
	
}

void Control::modificaEmpresa()
{

	string nombre;
	string telefono;
	string cedulaJuridica;
	string direccion;
	I->imprimeString("Ingresa el nombre de la empresa\n");
	cin.ignore();
	nombre = I->retornaStringGetLine();
	E->setNombre(nombre);
	I->imprimeString("Ingresa el telefono\n");
	telefono = I->retornaString();
	E->setTelefono(telefono);
	I->imprimeString("Ingresa la cedula juridica de la empresa\n");
	cedulaJuridica = I->retornaStringIgnore();
	E->setCedulaJuridica(cedulaJuridica);
	I->imprimeString("Ingresa la direccion de la empresa\n");
	direccion = I->retornaStringGetLine();
	E->setDireccion(direccion);



}

void Control::generarPendientes()
{

	I->imprimeString("Reporte Generado!!!..... \n");
	E->guardaPendientes();
}

void Control::generarEspecifico()
{

	I->imprimeString(E->toStringVentas());
	I->imprimeString("Digite el numero de cedula de la persona: ");
	int ced;
	ced = I->retornaInt();
	system("pause");
	system("cls");
	I->imprimeString("Reporte Generado!!!..... \n");
	E->guardaClienteEspecifico(ced);


}

void Control::generarReporteFecha()
{
	int dia;
	int mes;
	int anio;
	I->imprimeString("Digite el dia: ");
	dia = I->retornaInt();
	I->imprimeString("Digite el mes: ");
	mes = I->retornaInt();
	I->imprimeString("Digite el anio: ");
	anio = I->retornaInt();

	I->imprimeString("Reporte Generado!!!..... \n");
	E->guardarContratosPorFecha(dia, mes, anio);


}
