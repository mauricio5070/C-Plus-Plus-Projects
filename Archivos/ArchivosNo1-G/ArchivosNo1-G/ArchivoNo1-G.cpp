#include <cstdlib>
#include <iostream>
#include <fstream>
#include<string>
using namespace std;
int main() {

	// El constructor de la clase abre el archivo de salida.
	// También es posible declarar la instancia de la clase
	// sin parámetros y utilizar el método open() para abrir
	// el archivo.
	// Cuando se utiliza la clase fstream, se deberá indicar el
	// modo del archivo (entrada/salida) por medio de los valores
	// constantes ios::in o ios::out.
	// Si se emplean las clases ofstream o ifstream, el archivo se
	// abre por defecto en modo de salida o entrada, respectivamente.
	//
	// Si se utiliza una variable de tipo string para especificar el
	// nombre del archivo, se debe usar la función c_str() para convertir
	// la hilera en un arreglo de caracteres (char*), que es el tipo
	// requerido por la mayoría de las funciones.

	ofstream salida("../lineas.txt", ios::trunc);
	for (int i = 0; i < 20; i++) {
		salida << "Linea " << i << "\n";
	}
	salida.close();
	cout << endl;
	fstream entrada;
	string rutaArchivo = "../lineas.txt";
	entrada.open(rutaArchivo.c_str(), ios::in);

	while (entrada.good()) {
		string linea;
		getline(entrada, linea);
		if (entrada.good()) {
			cout << "> " << linea << endl;
		}
	}
	entrada.close();
	cout << endl;
	system("pause");
	return 0;
}
