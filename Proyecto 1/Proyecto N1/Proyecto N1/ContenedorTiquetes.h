#ifndef CONTENEDORTIQUETES
#define CONTENEDORTIQUETES
#include "Tiquete.h"


class ContenedorTiquetes {
private:
	Tiquete **contenedor;
	int tam;
	int cantidad;

public:
	ContenedorTiquetes();
	//~ContenedorTiquetes();
	Tiquete* getTiquete(int);
	void crearTiquete(int);
	int getCantidad();
	string mostrarTiquete(int);

};
#endif // !CONTENEDORTIQUETES
