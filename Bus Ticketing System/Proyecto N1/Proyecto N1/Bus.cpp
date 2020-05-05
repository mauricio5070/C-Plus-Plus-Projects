#include "Bus.h"


Bus::Bus(int a, string b, char c, string d) : numBus(a), placa(b), ubicacion(c), asignacion(d) {
	butaca = new Asiento**[24];

	for (int i = 0; i < 24; i++) {
		butaca[i] = new Asiento*[4];
	}//SE CREAN LOS ASIENTOS DINAMICOS

	int cont = 1;
	for (int y = 0; y < 24; y++) {
		butaca[y][0] = new Asiento('V', cont, '-');             //-(Disponible)  *(Ocupado)   SE INICIALIZA TODOS EN -
		cont++;
		butaca[y][1] = new Asiento('P', cont, '-');
		cont++;
		butaca[y][2] = new Asiento('P', cont, '-');
		cont++;
		butaca[y][3] = new Asiento('V', cont, '-');
		cont++;
	}
	
}

string Bus::mostrarAsientos() {
	stringstream x;
	x << "Asientos disponibles(-), Asientos ocupados(*)\n";
	x << "Asiento al lado de la ventana(V), Asientos al lado del pasillo(P)\n\n";
	x << "Primer piso\n";
	for (int i = 0; i < 12; i++) {
		x << butaca[i][0]->toString() << "  " << butaca[i][1]->toString() << "____" << butaca[i][2]->toString() << "  " << butaca[i][3]->toString() << endl;
	}

	x << "\nSegundo piso\n";

	for (int i = 12; i < 24; i++) {
		x << butaca[i][0]->toString() << "  " << butaca[i][1]->toString() << "____" << butaca[i][2]->toString() << "  " << butaca[i][3]->toString() << endl;
	}
	return x.str();
}

bool Bus::consultaAsiento(int r) {
	
	for (int i = 0; i < 24; i++) {
		for (int p = 0; p < 4; p++) {

			if (butaca[i][p]->getNumero() ==r) {
				
				if (butaca[i][p]->getEstado() == "Disponible") {
					return true;
				}
				else {
					return false;
				}
			}
		}
	}
}

void Bus::ocuparAsiento(int a) {
	for (int p = 0; p < 24;p++) {
		for (int n = 0; n < 4; n++) {
			if ( (butaca[p][n]->getNumero()==a) ) {
				butaca[p][n]->setEstado('*');        //   * = ocupado

			}
		}
	}
}

void Bus::desOcupar_Asiento(int a) {
	for (int p = 0; p < 24; p++) {
		for (int n = 0; n < 4; n++) {
			if ((butaca[p][n]->getNumero() == a)) {
				butaca[p][n]->setEstado('-');   

			}
		}
	}
}

string Bus::toString() {
	stringstream g;
	g << "\tNumero de bus: " << numBus << endl;
	g << "Placa: " << placa << endl;
	g << "Ubicacion:" << ubicacion << endl;
	g << mostrarAsientos() << endl;
	return g.str();
}

void Bus::setAsignacion(string a) { asignacion = a; }
string Bus::getAsignacion() { return asignacion; }

void Bus::setUbicacion(char z) { ubicacion = z; }

int Bus::getnumBus() { return numBus; }

char Bus::getUbicacion() { return ubicacion; }

/*Bus::~Bus() {
	for (int y = 0; y < 23; y++) {
		for (int i = 0; i < 4; i++) {
			delete butaca[y][i];
		}

		delete[] butaca[y];
	}

	delete[] butaca;
}*/