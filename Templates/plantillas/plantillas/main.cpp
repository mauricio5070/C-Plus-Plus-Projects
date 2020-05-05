#include "plasntillaDeClase.h"


int main() {

	cout << "----------------------------------Trabajando con ints--------------------" << endl;
	cout << "-------------------------------------------------------------------------" << endl;
	Par<int> marcador(0, 0);
	//---------------------------los setea-----------------
	marcador.fijaElemento(1, 0);
	marcador.fijaElemento(2, 3);
	//------------------------los obtiene--------------------------
	cout << "El valor del primero es: " << marcador.obtenerElemento(1) << endl;
	cout << "El valor del segundo es: " << marcador.obtenerElemento(2) << endl;
	cout<<endl;
	cout << "----------------------------------Trabajando con chars--------------------" << endl;
	cout << "-------------------------------------------------------------------------" << endl;
	Par<char> asiento('I', 'I');

	//---------------------------los setea-----------------
	asiento.fijaElemento(1, 'A');
	asiento.fijaElemento(2, 'B');
	//------------------------los obtiene--------------------------
	cout << "El asiento del primero es: " << asiento.obtenerElemento(1) << endl;
	cout << "El asiento del segundo es: " << asiento.obtenerElemento(2) << endl;
	cout << endl;
	system("pause");
	return 0;
}

//tarea moral hacer lo mismo con personas