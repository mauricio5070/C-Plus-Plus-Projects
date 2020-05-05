#include<iostream>
#include<string>
using namespace std;

class Contenedor {
private:
	int vec[10];
	int can;

public:

	Contenedor(){
		can = -1;
	}

	void ingresaElemento(int in) {
		vec[++can] = in;
	}

	int eliminaUltimo() {
		return vec[can--];
	}

	bool estaVacio() {
		return (can == -1);
	}

	friend class Iterador;   //Declaracion de Amistad con Iterador
};


class Iterador {
private:
	const Contenedor& stk;
	int indice;

public:

	Iterador(const Contenedor& s) : stk(s) {
		indice = 0;   //Nos posicionamos al inicio.....
	}

	void operator++() {
		indice++;  //Nos pasamos tan solo incrementando el valor del indice
	}

	bool operator()() {   //Para saber si esta dentro del rango
		return(indice != stk.can + 1);
	}

	int operator *() {
		return stk.vec[indice];
	}
};


bool operator == (const Contenedor& l, const Contenedor& r) {
	Iterador itl(l),itr(r);//Dos Iteradores para l y r.

	for(; itl();++itl,++itr){
		if (*itl != *itr) {
			break;  //Saltar del for...
		}
	}

	return !itl() && !itr();
}


int main() {
	Contenedor s1;
	int i;
	for (i = 1; i < 5; i++) {
		s1.ingresaElemento(i);
	}

	//Crear algunos contenedores y llenarlos con s1

	Contenedor s2(s1), s3(s1), s4(s1), s5(s1);

	//Alterar los contenedores excepto a s2
	s3.eliminaUltimo();
	s5.eliminaUltimo();
	s4.ingresaElemento(2);
	s5.ingresaElemento(9);
	cout << "---------------------------Salida De info---------------------------" << endl;
	cout << "------------------------------------------------------------------------" << endl;

	cout << "s1 == s2 es: " << (s1 == s2) << endl;
	cout << "s1==s3 es: " << (s1 == s3) << endl;
	cout << "s1==s4 es: " << (s1 == s4) << endl;
	cout << "s1==s5 es:" << (s1 == s5) << endl;

	system("pause");
	return 0;
}