#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;

class Contenedor {
private:
	int vec[10];
	int can;

public:

	Contenedor() {
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

	Iterador* creaIterador()const;
};


class Iterador {
private:

	const Contenedor* stk;  //Lega Contenedor tipo puntero
	int indice;
public:

	Iterador(const Contenedor* s) {
		stk = s;
	}

	void first() {  //Ir al primer elemento dekl Contenedor
		indice = 0;
	}

	void next() {  //Nos lleva al proximo elemento
		indice++;
	}

	bool isDone() {   //Llega al final del Contenedor
		return (indice == stk->can + 1);
	}

	int current() {  //Devuelve lo que el iterador "ve"
		return(stk->vec[indice]);
	}

};

//--------------------//----------------------------------//------------------------------//

Iterador* Contenedor::creaIterador()const {  //No Hay Error

	return new Iterador(this);  //Iterador se "incorpora" a un contenedor
}

//-----------------------------------////-----------------------------//---------------------/////---------


bool operator == (const Contenedor& l, const Contenedor& r) {
	//CREACION DE DOS ITERADORES.........
	Iterador* itl = l.creaIterador();
	Iterador* itr = r.creaIterador();
	//--------------------------------

	for (itl->first(), itr->first(); !itl->isDone(); itl->next(), itr->next()) {
		if (itl->current() != itr->current()) {//Comparo elementos
			break;  //Salto y salir del for
		}
	}

	bool resp = itl->isDone() && itr->isDone();
	delete itl;
	delete itr;
	return resp;
}



//--------------------------------------Main-----------------------------------------

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

	//system("pause");
	return 0;
}

//Tarea Moral Hacerlo Con un contenedor de personas de objetos dinamicos