#include "Interfaz.h"

string Interfaz::retornaString()
{
	string cadena;
	cin >> cadena;
	return cadena;
}

string Interfaz::retornaStringIgnore()
{
	string cadena;
	cin >> cadena;
	cin.ignore();
	return cadena;
}

string Interfaz::retornaStringGetLine()
{
	string cadena;
	getline(cin, cadena);
	return cadena;
}

void Interfaz::imprimeString(string a) { cout << a; }

int Interfaz::retornaInt() {
	int numero; bool num = false;
	do
	{
		if (!(cin >> numero)) {
			imprimeString("Digite solo numeros: ");
			cin.clear();
			cin.ignore(255, '\n');
		}
		else {
			num = true;
		}

	} while (num == false);
	return numero;
}

void Interfaz::imprimeInt(int a) { cout << a; }