#include"Lista.h"
#include "Persona.h"

int main() {
	Persona num;
	cout << "-----------------Trabajando con la clase template-------------" << endl;
	cout << "--------------------------------------------------------------" << endl;
	cout << "Crea un contenedor de personas con Ayuda de la Plantilla" << endl;
	Lista<Persona>* ListaEnt = new Lista<Persona>;
	cout << "Crear los elementos enteros para la lista..." << endl;
	Persona* x = new Persona("1111","Jose","Manson",6);
	Persona* y = new Persona("22222","Juan", "Perez", 7);
	Persona* z = new Persona("3333","Ana","Ataques",8);
	Persona* w = new Persona("4444","Ariel","Arroyo", 3);

	cout << "Ingresar estos elementos persona a la Lista..." << endl;
	/*ListaEnt->agregaElemento(x);
	ListaEnt->agregaElemento(y);
	ListaEnt->agregaElemento(z);
	ListaEnt->agregaElemento(w);
	*/
	cout << "Imprimiendo Lista......." << endl;
	cout << ListaEnt->toString() << endl;
	Lista<Persona>* ListaX = new Lista<Persona>;
	ListaX = ListaEnt;
	cout << "Imprimiendo Lista X......." << endl;
	cout << ListaX->toString() << endl;
	system("pause");
	return 0;
}