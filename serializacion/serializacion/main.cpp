#include <cstdlib>
#include <iostream>
#include <fstream>
#include "persona.h"
using namespace std;

int main(){
	string rutaArchivo = "../personas2.txt"; //nombre del archivo a usar
	//-------------------------------------------------
	Persona** gente = new Persona*[4];
	gente[0] = new Persona("11111", "Vega Silva", "Ana", 23,2.34);
	gente[1] = new Persona("222211", "Perez Seras", "Maria",34, 4.56 );
	gente[2] = new Persona("33333", "Armando Tortas", "Juan",45,5.76 );
	gente[3] = new Persona("14444", "Cubero Silva", "Pedro",56, 6.78 );

	for (int i = 0; i < 4; i++)
		cout << "gente[" << i << " ]: " << gente[i]->toString() << endl;
	cout << endl << "--------------Guardando info-------------------" << endl << "------------------------------------------" << endl;
	ofstream salida;
	salida.open(rutaArchivo.c_str());
	for (int i = 0; i < 4; i++)
		gente[i]->guardar(salida);
	cout << endl;
	salida.close();


	cout << endl << "--------------Recuperando info-------------------" << endl << "------------------------------------------" << endl;
	ifstream entrada(rutaArchivo.c_str());
	int k = 0;
	while (entrada.good()) {
		Persona p = Persona::recuperar(entrada);
		if (entrada.good()) {
			k++;
			cout << "Persona de Archivo...." << p.toString() << endl;
		}
	}
	entrada.close();
	cout << "se leyeron datos de " << k << " personas."<< endl<<endl;

	//eliminar o borrar a los objetos creados
	for (int i = 0; i < 4; i++)
		delete gente[i];
	delete[] gente;
	cout << "-------------GAME OVER------------" << endl;

	system("pause");
	return 0;
}