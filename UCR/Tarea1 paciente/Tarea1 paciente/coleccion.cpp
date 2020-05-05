#include"coleccion.h"
#include"paciente.h"
Coleccion::Coleccion(int n) {
	arreglo = new Paciente[n];
	tamanio = n;
	cantidad =1000;
}
Coleccion::~Coleccion() {

}

void Coleccion::llenaArreglo() {
	int ann,
		float alt, pes;
	string nom, ape, gen, san;

	char letra = 's';
	while (letra == 's') {
		cout << "Digite el nombre:";
		cin >> nom;
		cout << "Digite el apellido:";
		cin >> ape;
		cout << "Digite el género:";
		cin >> gen;
		cout << "Digite el año de nacimiento:";
		cin >> ann;
		cout << "Digite la altura:";
		cin >> alt;
		cout << "Digite el peso:";
		cin >> pes;
		cout << "Digite el tipo de sangre:";
		cin >> san;
		arreglo[cantidad] = Paciente(nom, ape, gen, ann, alt, pes, san);
		cantidad++;
		cout << "¿Desea agregar un nuevo paciente?(s/n)";
		cin >> letra;

	}
}
	void Coleccion::imprimaArreglo() {
		for (int i = 0; i < cantidad; i++)
			cout << arreglo[i].toString() << endl;

	}
