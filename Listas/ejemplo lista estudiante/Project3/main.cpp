using namespace std;
#include <string>
#include "Estudiante.h"
#include "Lista.h"

void main()
{
	Estudiante* e1 = new Estudiante(121, "Juan", 100, 20, 'm');
	Estudiante* e2 = new Estudiante(122, "Maria", 50, 21, 'f');
	Estudiante* e3 = new Estudiante(123, "Pedro", 89, 18, 'm');
	Estudiante* e4 = new Estudiante(124, "Luis", 100, 20, 'm');
	Estudiante* e5 = new Estudiante(125, "Miguel", 100, 29, 'm');
	Estudiante* e6 = new Estudiante(126, "Arturi", 100, 31, 'm');
	Lista* lis = new Lista();
	lis->insertarInicio(e1);
	lis->insertarInicio(e2);
	lis->insertarInicio(e3);
	lis->insertarInicio(e4);
	cout << lis->toString();
	cout <<"Promedio: "<< lis->promedio();
	lis->cuentaNodos();
	cin.get();
}