#include "Control.h"

void Control::iniciar() {
	iniciarEmpresa();
	system("pause");     system("cls");
	registrarBuses();
	system("pause");     system("cls");
	registarCarreras(); 
	system("pause");     system("cls");
	desarrollo();
}

void Control::desarrollo() {
	Interfaz Z; int opc; bool continuar = true;

	do {
		Z.imprimeString("\tMenu de opciones Empresa "); Z.imprimeString(A->getNombre()); Z.imprimeString("\n\n");
		Z.imprimeString("1- Consultar o actualizar datos de la Empresa.\n");
		Z.imprimeString("2- Mostrar Buses de la Empresa.\n");
		Z.imprimeString("3- Mostrar Carreras de la Empresa.\n");
		Z.imprimeString("4- Actualizar ubicacion de un Bus.\n");
		Z.imprimeString("5- Vender tiquete.\n");
		Z.imprimeString("6- Mostrar Tiquete.\n");
		Z.imprimeString("7- Lista de todos los tiquetes vendidos.\n");
		Z.imprimeString("8- Cambiar numero de asiento de un tiquete.\n");
		Z.imprimeString("9- Monto recolectado.\n");
		Z.imprimeString("0- SALIR\n");
		Z.imprimeString("\tDigite una opcion: "); opc = Z.leeInt();

		switch (opc) {
		case 0:
			continuar = false; break;
			delete A;

		case 1:
			system("cls");
			mostrar_actualizar_Empresa();
			system("pause");
			system("cls");
			break;
		case 2:
			system("cls");
			mostrarBuses();
			system("pause");
			system("cls");
			break;
		case 3:
			system("cls");
			mostrarCarreras();
			system("pause");
			system("cls");
			break;
		case 4:
			system("cls");
			actualizarEstado_Bus();
			system("pause");
			system("cls");
			break;
		case 5:
			system("cls");
			venderTicket();
			system("pause");
			system("cls");
			break;
		case 6:
			system("cls");
			mostrarTiquete();
			system("pause");
			system("cls");
			break;
		case 7:
			system("cls");
			mostrarTodosTiquetesVendidos();
			system("pause");
			system("cls");
			break;
		case 8:
			system("cls");
			cambiarTiquete();
			system("pause");
			system("cls");
			break;
		case 9:
			system("cls");
			ganancias();
			system("pause");
			system("cls");
			break;
		default:
			Z.imprimeString("OPCION INVALIDA\n");
		}
	} while (continuar);
}

void Control::iniciarEmpresa() {
	Interfaz Z;
	string nombre, telefono; char terminal;
	Z.imprimeString("\tRegistrar datos de la Empresa:\n");
	Z.imprimeString("Nombre de la Empresa:"); nombre = Z.leeString();
	Z.imprimeString("Numero de telefono: "); telefono = Z.leeString();
	terminal = Z.leeterminal();
	A = new Empresa(nombre, telefono, terminal);
}

void Control::mostrar_actualizar_Empresa() {
	Interfaz Z;
	Z.imprimeString(A->toString());
	int opc;
	Z.imprimeString("Digite '1' para actualizar los datos, o digite otro numero para volver al menu: "); opc = Z.leeInt();
	if (opc == 1) {
		string nombre, telefono; char terminal;
		Z.imprimeString("\tActualizar datos de la Empresa:\n");
		Z.imprimeString("Nombre de la Empresa:"); nombre = Z.leeString();
		Z.imprimeString("Numero de telefono: "); telefono = Z.leeString();
		Z.imprimeString("Terminal: "); terminal = Z.leeterminal();
		A->setNombre(nombre); A->setTelefono(telefono); A->setTerminal(terminal);
		Z.imprimeString("Se ha actualizado\n");
	}
}

void Control::registrarBuses() {
	Interfaz Z;
	int numBus; string placa; char ubi; Bus S;
	Z.imprimeString("\tRegistrar Buses\n\n");
	for (int i = 0; i < 5; i++) {
		numBus = i + 1;
		Z.imprimeString("Numero de Bus: "); Z.imprimeInt(numBus);
		Z.imprimeString("\nNumero de asientos: "); Z.imprimeInt(96);
		Z.imprimeString("\nPlaca: "); placa = Z.leeString();
		ubi = Z.leeUbicacion();
		S= Bus(numBus, placa, ubi);
		A->registrarBus(i, S);
		Z.imprimeString("Unidad registrada\n\n");
	}
}

void Control::mostrarBuses() {
	Interfaz Z; int opc;
	Z.imprimeString("Digite 1 para mostrar un unico Bus, digite otro numero para mostrar todas las unidades: "); opc = Z.leeInt();
	if (opc == 1) {
		Z.imprimeString("Numero de unidad: "); opc = Z.leeNum_Bus_Carrera();
		Z.imprimeString("\tEmpresa "); Z.imprimeString(A->getNombre()); Z.imprimeString("\n");
		Z.imprimeString(A->mostrarBus(opc));
	}
	else {
		Z.imprimeString("\tEmpresa "); Z.imprimeString(A->getNombre()); Z.imprimeString("\n\n");
		for (int i = 0; i < 5; i++) {
			Z.imprimeString(A->mostrarBus(i));
		}
	}
}

void Control::registarCarreras() {
	Interfaz Z;
	int numCarrera, numUnidad; float precio; string ruta; int horaSalida; Carrera S;
	Z.imprimeString("\tRegistrar las carreras del dia\n\n");
	for (int r = 0; r < 5; r++) {
		numCarrera = r + 1;
		Z.imprimeString("Numero de carrera "); Z.imprimeInt(numCarrera); Z.imprimeString("\n\n");
		horaSalida = Z.leehora(); 
		ruta = Z.leeRuta();
		Z.imprimeString("Precio: "); precio = Z.leeFloat();
		do
		{
			Z.imprimeString("Digite un numero de unidad SIN ASIGNAR: "); numUnidad=Z.leeNum_Bus_Carrera();

		} while (A->getBus(numUnidad)->getAsignacion() != "Sin Asignar");
		A->getBus(numUnidad)->setAsignacion("Asignado");

		S = Carrera(numCarrera, A->getBus(numUnidad), horaSalida, ruta, precio);
		A->registrarCarrera(r, S);
		Z.imprimeString("Carrera Registrada\n\n");
	}
}

void Control::mostrarCarreras() {
	Interfaz Z; int opc;
	Z.imprimeString("Digite 1 para mostrar una unica Carrera, o digite otro numero para mostrar todas las Carreras: "); opc = Z.leeInt();
	if (opc == 1) {
		Z.imprimeString("Numero de Carrera: "); opc = Z.leeNum_Bus_Carrera();
		Z.imprimeString("\tEmpresa "); Z.imprimeString(A->getNombre()); Z.imprimeString("\n");
		Z.imprimeString(A->mostrarCarrera(opc));
	}
	else {
		Z.imprimeString("\tEmpresa "); Z.imprimeString(A->getNombre()); Z.imprimeString("\n\n");
		for (int i = 0; i < 5; i++) {
			Z.imprimeString(A->mostrarCarrera(i));
			Z.imprimeString("\n\n");
		}
	}
}

void Control::mostrarAsientos_Bus_Carrera() {
	Interfaz Z; int num;
	Z.imprimeString("Numero de carrera: "); num = Z.leeNum_Bus_Carrera();
	Z.imprimeString(A->asientos_BusCarrera(num));
}

void Control::actualizarEstado_Bus() {
	int a, b; Interfaz Z;
	Z.imprimeString("Numero de bus: "); a = Z.leeNum_Bus_Carrera();
	b = Z.leeUbicacion();
	A->actualizarEstadoBus(a, b);
}

void Control::venderTicket() {
	int numCarrera, numAsiento; Interfaz Z;
	for (int n = 0; n < 5; n++) {
		Z.imprimeString(A->mostrarCarrera(n));
		Z.imprimeString("\n\n");
	}
	Z.imprimeString("Elija numero de carrera: "); numCarrera = Z.leeNum_Bus_Carrera(); Z.imprimeString("\n");
	Z.imprimeString("Asientos del bus de la carrera "); Z.imprimeInt(numCarrera + 1); Z.imprimeString("\n");
	Z.imprimeString(A->asientos_BusCarrera(numCarrera)); Z.imprimeString("\n");
	Z.imprimeString("Elija numero de asiento: "); numAsiento = Z.leeAsiento_Tiquete();
	
	int a = A->venderTiquete(numCarrera, numAsiento);
	if ( a > 0) {
		Z.imprimeString(A->info_Tiquete(numCarrera, a));
		Z.imprimeString("Vendido\n");
	}
	else {
		Z.imprimeString("No disponible\n");
	}

}

void Control::cambiarTiquete() {
	Interfaz Z;
	int numC, numT, numA;
	Z.imprimeString("Numero de carrera del tiquete: "); numC = Z.leeNum_Bus_Carrera();
	Z.imprimeString("Numero de tiquete: "); numT = Z.leeAsiento_Tiquete();
	Z.imprimeString(A->asientos_BusCarrera(numC)); Z.imprimeString("\n");
	Z.imprimeString("Nuevo numero de asiento: "); numA = Z.leeAsiento_Tiquete();

	if (A->cambiarTicket(numC, numT, numA) == true) {
		Z.imprimeString("Se ha cambiado\n");
	}
	else {
		Z.imprimeString("No disponible o el numero de tiquete no existe.\n");
	}
}

void Control::mostrarTiquete() {
	Interfaz Z;
	int carrera, tiquete;
	Z.imprimeString("Numero de carrera del tiquete: "); carrera = Z.leeNum_Bus_Carrera();
	Z.imprimeString("Numero de tiquete: "); tiquete = Z.leeAsiento_Tiquete();
	Z.imprimeString(A->info_Tiquete(carrera, tiquete));
}

void Control::mostrarTodosTiquetesVendidos() {
	Interfaz Z;
	Z.imprimeString(A->mostrarTiquetesvendidos());
}

void Control::ganancias() {
	int opc; Interfaz Z;
	Z.imprimeString("1- Ganancias por carrera.\n");
	Z.imprimeString("2- Ganancias totales.\n");
	Z.imprimeString("Digite una opcion: "); opc = Z.leeInt();
	float monto = 0;

	switch (opc)
	{
	case 1:
		int carrera;
		Z.imprimeString("\nDigite el numero de carrera: "); carrera = Z.leeNum_Bus_Carrera();
		Z.imprimeString("El monto recolectado por la carrera es de: "); Z.imprimeFloat(A->montoRecolectado(carrera)); Z.imprimeString(" colones\n\n"); break;
	case 2:
		
		for (int t = 0; t < 5; t++) {
			monto = monto + A->montoRecolectado(t);
		}
		Z.imprimeString("El monto total es de  "); Z.imprimeFloat(monto); Z.imprimeString(" colones\n\n"); break;
	default:
		Z.imprimeString("OPCION INVALIDA\n");
		break;
	}
}
