
#include "Cliente.h"
#include "Contrato.h"
#include "Calendario.h"
#include "Empresa.h"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include "Control.h"
using namespace std;



int main() {

	Control* C = new Control();
	C->iniciar();
	delete C;
	system("cls");
	system("pause");

	return 0;
}