#include "Lista.h"
#include "Estudiante.h"


Lista::Lista() {
	pinicio = NULL;
	pactual = NULL;
}
Lista::~Lista() {
	while (pactual != NULL) {
		pactual = pinicio;
		pinicio = pinicio->getSig();

		delete pactual;
	}
}

/*Lista::~Lista() {
	if(pinicio==NULL){
	return false}
	else
	{pactual= peinicio;
	pinicio = pinicio->getSig();
	delete pactual;
	}
}



otra forma de hacer el destructor
*/





	void Lista::insertarInicio(Estudiante * e)
	{
		pactual = pinicio;
		if (pinicio == NULL)
		{
			pinicio = new Nodo(e, pinicio);
		}
		else
		{
			pactual = pinicio;
			while (pactual->getSig() != NULL) {
				pactual = pactual->getSig();
			}
			pactual->setSig(new Nodo(e, NULL));
		}
	}

string Lista::toString() {
	stringstream s;
	pactual = pinicio;
	while (pactual != NULL) {
		s << pactual->toStringNodo();
		pactual = pactual->getSig();
	
	}
	return s.str();
}

float Lista::promedio() {
	pactual = pinicio;
	int suma = 0;
	int con = 0;
	while (pactual != NULL) {
		con++;
		suma = suma + pactual->getEstudiante()->getNota();
		pactual = pactual->getSig();
	}
	return suma / con;


}
bool Lista::eliminarInicio() {
if (pinicio== NULL) {
	return false;
	}
else {
	pactual = pinicio;
		pinicio = pinicio->getSig();
	delete pactual;
}

}

int Lista::cuentaNodos() {
	pactual = pinicio;
	int can = 0;
	while(pactual != NULL) {
		can++;
			pactual = pactual->getSig();
	}
	return can;
}

void Lista::elUltimo() {
	pactual = pinicio;
	while (pactual->getSig() != NULL) {
		pactual = pactual->getSig();
	}
}




void Lista::eliminaFinal() {
	if (pinicio != NULL && pinicio->getSig() == NULL) {
		delete pinicio;
		pinicio = NULL;
	}
	else {
		pactual = pinicio;
		while (pactual->getSig()->getSig() != NULL) {
			pactual = pactual->getSig();
		}
		delete pactual->getSig();
		pactual->setSig(NULL);
	}
}
/*bool Lista::encontrado(int id) {
	pactual = pinicio;
	while (pactual != NULL) {
		if (pactual->getEstudiante()->getId == id) {
			return true;
		}
		pactual = pactual->getSig();
	}
	return false;
}
*/

/*bool Lista::borrarEspecifico() {
	Nodo * paux;
	pactual = pinicio;
		if(pinicio==NULL) {
			return false;
		}
		else {

			if()
		}

}*/