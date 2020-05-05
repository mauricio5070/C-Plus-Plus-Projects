#include "Control.h"

int main() {
	/*string nombre, tel;
	char ter;

	cout << "Nombre de la empresa: "; cin >> nombre;
	cout << "Numero de telefono de la empresa " << nombre << ": "; cin >> tel;
	cout << "Terminal('A' o 'B'): "; cin >> ter;
	Empresa *A = new Empresa(nombre, tel, ter);

	cout << "\n\nRegistrar Buses\n";
	int numBus; string placa; char ubi;
	for (int i = 0; i < 5; i++) {
		numBus = i + 1;
		cout << "Numero de Bus: " << numBus << endl;
		cout << "Placa: "; cin >> placa;
		cout << "Ubicacion: "; cin >> ubi;
		cout << "\n\n";
		Bus S(numBus, placa, ubi);
		A->registrarBus(i,S);
	}

	int r;
	cout << "Ver Bus:"; cin >> r;
	r = r - 1;
	cout << A->mostrarBus(r);


	cout << "\n\nRegistar carreras\n";
	int can, numU, numcarr; string horasalida; cout << "Cantidad de carreras x agregar: "; cin >> can;
	string ruta; float precio;
	Carrera X;
	for (int t = 0; t < can; t++) {
		numcarr = t + 1;
		cout << "Carrera numero " << numcarr << endl;
		cout << "Hora de salida: "; cin >> horasalida;
		cout << "Ruta: "; cin >> ruta;
		cout << "Precio: "; cin >> precio;
		do
		{
			cout << "Digite un numero de unidad SIN ASIGNAR: "; cin >> numU;
			numU = numU - 1;

		} while (A->getBus(numU)->getAsignacion()!="Sin Asignar");

		X = Carrera(numcarr, A->getBus(numU), horasalida, ruta, precio);

		A->registrarCarrera(t, X);
		cout << endl;
	}
	cout << endl;

	int num, asi;
	bool opc = false;
	do
	{
	
	for (int r = 0; r < 5; r++) {
		cout <<endl<<endl<< A->mostrarCarrera(r)<<endl<<endl;
	}

	
	cout << "\nElija una carrera: "; cin >> num;
	num = num - 1;
	cout<<A->asientos_BusCarrera(num);
	cout << "\n\nElija un numero de asiento: "; cin >> asi;
	if (A->venderTiquete(num, asi) == true) {
		cout << "\nVendido\n";
	}
	else {
		cout << "\nNo disponible\n";
	}


	} while (opc==false);  */

	Control *X= new Control();
	X->iniciar();

	delete X;


	system("pause");
	return 0;
}