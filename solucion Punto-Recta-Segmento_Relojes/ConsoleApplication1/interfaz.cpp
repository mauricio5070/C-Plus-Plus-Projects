#include "interfaz.h"
#include <string>

   void interfaz::imprimir(double  cadena)
   {
	cout << cadena;
   }

	void interfaz::imprimir(string  cadena)
	{
		cout << cadena;
	}

	double interfaz::leerDouble()
	{
		double num;
		cin >> num;

	// aqui se debe  validar  el ingreso de unicamente  numeros
		return num;
	}