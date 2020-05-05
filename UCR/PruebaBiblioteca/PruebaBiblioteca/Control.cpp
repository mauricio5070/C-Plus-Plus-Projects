#include "Control.h"

Control::Control()
{
	B = new Biblioteca();
	Z = new Interfaz();
	B->cargar();
}

void Control::iniciar()
{
	 int opc; bool continuar = true;
	do {
		Z->imprimeString("\tBienvenido al sistema de la Biblioteca\n");
		Z->imprimeString("1- Agregar Personas a la biblioteca\n");
		Z->imprimeString("2- Agregar un libro a la biblioteca\n");
		Z->imprimeString("3- Mostrar Personas\n");
		Z->imprimeString("4- Mostrar Libros\n");
		Z->imprimeString("5- Eliminar Persona\n");
		Z->imprimeString("6- Elimina Libro\n");
		Z->imprimeString("7- Alquilar\n");
		Z->imprimeString("8- Mostrar alquileres\n");
		Z->imprimeString("9- Devolver libro \n");
		Z->imprimeString("0- SALIR DEL SISTEMA\n");
		Z->imprimeString("\tDigite una opcion: "); opc = Z->retornaInt();


		switch (opc) {
		case 0:
			B->guardar();
			continuar = false; 
			delete B;
			 break;

		case 1:
			system("cls");
			agregarPersona();
			system("pause");
			system("cls");
			break;
		case 2:
			system("cls");
			agregarLibro();
			system("pause");
			system("cls");
			break;
		
		case 3:
			system("cls");
			mostrarPersonas();
			system("pause");
			system("cls");
			break;
		case 4:
			system("cls");
			mostrarLibros();
			system("pause");
			system("cls");
			break;
	
		case 5:
			system("cls");
			eliminarPersona();
			system("pause");
			system("cls");
			break;
		case 6:
			system("cls");
			eliminarLibro();
			system("pause");
			system("cls");
			break;
		case 7:
			system("cls");
			alquiler();
			system("pause");
			system("cls");
			break;
		case 8:
			system("cls");
			mostrarAlquiler();
			system("pause");
			system("cls");
			break;
		case 9:
			system("cls");
			entregarLibro();
			system("pause");
			system("cls");
			break;
	
		default:
			system("cls");
			Z->imprimeString("OPCION INVALIDA\n"); system("pause"); system("cls");

		}
	} while (continuar);
}

void Control::agregarPersona()
{
	
	string nombre, ID;
	Persona *P;
	Z->imprimeString("\tInscripcion de la Persona\n");
	Z->imprimeString("Ingrese los siguientes datos\n");
	Z->imprimeString("Nombre de la persona: "); nombre = Z->retornaString();
	Z->imprimeString("ID de la persona: "); ID = Z->retornaString();
	
	P = new Persona(nombre, ID);
	if (B->agregarPersonas(P)) {
		Z->imprimeString("Se he inscrito a la persona correctamente\n");
		B->guardar();
	}
	else {
		Z->imprimeString("La persona ya se encuentra en el sitema\n");
	}
}

void Control::mostrarPersonas()
{

	if (B->getListaPersonas()->cantidadMoldes()>0) {
		Z->imprimeString(B->toStringPersonas());
	}
	else {
		Z->imprimeString("No hay Personas\n");
	}
}

void Control::agregarLibro()
{
	
	string nombre,ID;
	Libro *L;
	Z->imprimeString("\tAgrega un libro->->->\n");
	Z->imprimeString("Ingrese los siguientes datos\n");
	Z->imprimeString("Nombre del Libro: "); nombre = Z->retornaString();
	Z->imprimeString("ID del libro: "); ID = Z->retornaString();
	
	L = new Libro(nombre,ID);
	if (B->agregarLibros(L)) {
		Z->imprimeString("Se ha registrado el libro correctamente\n");
		B->guardar();
	}
	else {
		Z->imprimeString("El libro ya se encuentra en el sistema\n");
	}
}
void Control::mostrarLibros()
{
	
	if (B->getListaLibros()->cantidadMoldes()>0) {
		Z->imprimeString(B->toStringLibros());
	}
	else {
		Z->imprimeString("No hay Libros\n");
	}
}




void Control::eliminarPersona()
{
	 string ID;
	if (B->getListaPersonas()->cantidadMoldes() > 0) {
		mostrarPersonas();
		Z->imprimeString("Digite el numero de ID de la persona por eliminar: "); ID = Z->retornaString();
		if (B->getListaPersonas()->buscayRetorna(ID)) {
			if (B->getListaPersonas()->elimina(ID)) {
				Z->imprimeString("Se ha eliminado\n");
			}
			else {
				Z->imprimeString("No se ha podido eliminar\n");
			}
		}
		else {
			Z->imprimeString("La persona no existe\n");
		}
	}
	else {
		Z->imprimeString("No hay personas\n");
	}
}

void Control::eliminarLibro()
{
	 string ID;
	if (B->getListaLibros()->cantidadMoldes() > 0) {
		mostrarLibros();
		Z->imprimeString("Digite el ID de libro por eliminar: "); ID = Z->retornaString();
		if (B->getListaLibros()->buscayRetorna(ID)) {
		
			if (B->getListaLibros()->elimina(ID)) {
				Z->imprimeString("Se ha eliminado\n");
			}
			else {
				Z->imprimeString("No se ha podido eliminar\n");
			}
		}
		else {
			Z->imprimeString("El libro no existe\n");
		}
	}
	else {
		Z->imprimeString("No hay libros\n");
	}
}


void Control::alquiler() 
{
	Z->imprimeString("\t-----------PERSONAS EN EL SISTEMA-------------\n");
	mostrarPersonas();
	Z->imprimeString("\t-----------LIBROS EN EL SISTEMA-------------\n");
	mostrarLibros();
	Z->imprimeString("\t-------------------------------------------------------------------------\n\n\n");
	string nombre1, nombre2;
	Alquilado* A;
	
	Z->imprimeString("\t-----------Alquiler-------------\n");
	Z->imprimeString("Ingrese los siguientes datos\n");
	Z->imprimeString("Nombre de la persona: "); nombre1 = Z->retornaString();
	Z->imprimeString("Nombre del Libro: "); nombre2 = Z->retornaString();
	if ((B->getListaPersonas()->buscayRetorna2(nombre1)) && (B->getListaLibros()->buscayRetorna2(nombre2))) {
		A = new Alquilado(nombre1, nombre2);


		if (B->agregarAlquiler(A)) {
			Z->imprimeString("Se ha alquilado el libro correctamente\n");
			B->guardar();
		}
		else {
			Z->imprimeString("El libro ya se encuentra alquilado\n");
		}
	}
}


void Control::mostrarAlquiler()
{

	if (B->getListaAlquilados()->cantidadMoldes()>0) {
		Z->imprimeString(B->toStringAlquilados());
	}
	else {
		Z->imprimeString("No hay Alquilados\n");
	}
}

void Control::entregarLibro()
{
	Z->imprimeString("\t-----------Alquiler-------------\n");
	mostrarAlquiler();
	Z->imprimeString("\t-------------------------------------------------------------------------\n\n\n");
	string nom;
	if (B->getListaAlquilados()->cantidadMoldes() > 0) {
		
		Z->imprimeString("Digite el nombre del libro que desea devolver: "); nom = Z->retornaString();
		if (B->getListaAlquilados()->buscayRetorna(nom)) {
			if (B->getListaAlquilados()->elimina(nom)) {
				Z->imprimeString("Se ha devuelto el libro\n");
			}
			else {
				Z->imprimeString("No se ha podido devolver, revisa la lista\n");
			}
		}
		else {
			Z->imprimeString("El libro no se muestra como alquilado\n");
		}
	}
	else {
		Z->imprimeString("No hay alquileres\n");
	}
}