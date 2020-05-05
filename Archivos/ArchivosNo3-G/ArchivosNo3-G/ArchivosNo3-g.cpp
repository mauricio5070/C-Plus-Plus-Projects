#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

#define MAX_NOTAS 5

void procesarLinea(ostream&, string);

int main() {

	ifstream entrada("../datos estudiantes.txt");
	ofstream salida("../resultados notas.txt", ios::trunc);

	while (entrada.good()) {
		string linea;
		getline(entrada, linea, '\n');
		if (!linea.empty()) {
			cout << "> " << linea << endl;
			procesarLinea(salida, linea);
		}
	}
	salida.close();
	entrada.close();
	system("pause");
	return 0;
}

void procesarLinea(ostream &salida, string linea) {
	stringstream s(linea);

	string apellidos, nombre;
	int notas[MAX_NOTAS];

	getline(s, apellidos, '\t');
	getline(s, nombre, '\t');
	salida << apellidos << "\t" << nombre;

	int total = 0;
	int nota;
	for (int i = 0; i < MAX_NOTAS; i++) {
		string d;
		getline(s, d, '\t');
		stringstream t(d);
		if (t >> nota) {   // Pasar t a int que es nota:
			total += nota;
		}
	}
	salida << "\t" << (total / MAX_NOTAS);
	salida << "\n";
}
