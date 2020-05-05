#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;

int main() {

	ifstream entrada("../datos prueba.txt");

	int k = 0;
	int m1, m2;
	int s = 0;
	int x;

	while (entrada.good()) { // El archivo puede ser leído..
		if (entrada >> x) { // ¿Se hizo la lectura correctamente?
			cout << ++k << ": " << x << endl;
			s += x;

			if (k == 1) { // ¿Es el primer elemento?
				m1 = m2 = x;
			}
			else {
				if (x < m1) {
					m1 = x;
				}
				if (m2 < x) {
					m2 = x;
				}
			}
		}
	}
	entrada.close();

	ofstream salida("../resultados.txt");
	if (k > 0) {
		salida << "k = cantidad  =\t" << k << "\n";
		salida << "s = sumatoria =\t" << s << "\n";
		salida << "m1 = menor    =\t" << m1 << "\n";
		salida << "m2 = mayor    =\t" << m2 << "\n";
		salida << "p =  promedio =\t" << (s / k) << "\n";
	}
	else {
		salida << "No se leyeron valores del archivo.\n";
	}

	salida.close();
	system("pause");
	return 0;
}
