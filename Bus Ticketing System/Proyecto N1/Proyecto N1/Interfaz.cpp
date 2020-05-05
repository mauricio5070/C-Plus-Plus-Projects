#include "Interfaz.h"

void Interfaz::imprimeString(string a) { cout << a; }

void Interfaz::imprimeChar(char b) { cout << b; }

void Interfaz::imprimeInt(int c) { cout << c; }

void Interfaz::imprimeFloat(float d) { cout << d; }

string Interfaz::leeString() {
	string cadena = "-";
	cin>>cadena;
	return cadena;
}

string Interfaz::leeRuta(){
	string a;
	do
	{
		cout << "Ruta, (A-B) o (B-A): "; cin>>a;
		for (int i = 0; i < a.length();i++) {
			a[i] = toupper(a[i]);
		}

	} while ((a!=("A-B")) &&(a!=("B-A")));
	return a;
}

char Interfaz::leeterminal() {
	char a = '-';
	do
	{
		cout << "Digite el numero de terminal('A' o 'B'): "; cin >> a;
		a= toupper(a);
	} while ((a != 'A') && (a != 'B'));
	return a;
}

int Interfaz::leehora() {
	int a = 0; bool continuar = false;
	do {
		cout << "Digite una hora de salida(En formato de 24 h ): ";
		if (!(cin >> a)) {
			cout << "Digite solo numeros\n";
			cin.clear();
			cin.ignore(255, '\n');
		}
		else {
			if ((a < 25) && (a >= 0)) {
				continuar = true;
			}
		}
	} while (continuar == false);
	return a;
}

float Interfaz::leeFloat() {
	float r = 0; bool continuar = false;
	do {
		if (!(cin >> r)) {
			cout << "Digite solo numeros\n";
			cin.clear();
			cin.ignore(255, '\n');
		}
		else {
			continuar = true;
		}
	} while (continuar == false);

	return r;
}

int Interfaz::leeInt() {
	int r = 0; bool continuar = false;
	do{
		if (!(cin >> r)) {
			cout << "Digite solo numeros\n";
			cin.clear();
			cin.ignore(255, '\n');
		}
	else {
		continuar = true;
	}
	}while (continuar==false);

	return r;
}

char Interfaz::leeUbicacion() {
	char a;
	do
	{
		cout << "Digite la Ubicacion de la unidad, Terminal('A' o 'B'), En ruta(R), En mantenimiento(M): "; cin >> a;
		a= toupper(a);
	} while ((a!='A')&&(a!='B')&&(a!='R')&&(a!='M'));
	return a;
}

int Interfaz::leeAsiento_Tiquete() {
	bool continuar = false;
	int numero;
	do
	{
		if (!(cin >> numero)) {
			cout << "Digite solo numeros\n";
			cin.clear();
			cin.ignore(255,'\n');
		}
		if ((numero > 0) && (numero <= 96)) {
			continuar = true;
		}
		else {
			cout << "No disponible, digite otro: ";
		}

	} while (continuar==false);

	return numero;
}


int Interfaz::leeNum_Bus_Carrera() {
	bool continuar = false;
	int numero;
	do
	{
		if (!(cin >> numero)) {
			cout << "Digite solo numeros\n";
			cin.clear();
			cin.ignore(255, '\n');
		}
		if ((numero > 0) && (numero <= 5)) {
			continuar = true;
		}
		else {
			cout << "No disponible, digite otro: ";
		}

	} while (continuar == false);

	return numero - 1;
}

Interfaz::~Interfaz(){}