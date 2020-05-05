#include "Control.h"

Control::Control()
{  
	Biblioteca* B = new Biblioteca();
        Interfaz* Z = new Interfaz();
	B->cargar();
        cout<<B->toStringPersonas()<<endl;
        cout<<B->toStringBiblioteca()<<endl;
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
		Z->imprimeString("0- SALIR DEL SISTEMA\n");
		Z->imprimeString("\tDigite una opcion: "); opc = Z->retornaInt();


		switch (opc) {
                   
		case 0:
			B->guardar();
			continuar = false; 
			delete B;
			 break;

		/*case 1:
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
			break;*/
		
		case 3:
			//system("cls");
			mostrarPersonas();
			//system("pause");
			//system("cls");
			break;
		/*case 4:
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
			break;*/
	
		default:
			system("cls");
			Z->imprimeString("OPCION INVALIDA\n"); system("pause"); system("cls");

		}
	} while (continuar);
}

/*void Control::agregarPersona()
{
	Interfaz Z;
	string nombre, ID;
	Persona *P;
	Z.imprimeString("\tInscripcion de la Persona\n");
	Z.imprimeString("Ingrese los siguientes datos\n");
	Z.imprimeString("Nombre de la persona: "); nombre = Z.retornaString();
	Z.imprimeString("ID de la persona: "); ID = Z.retornaString();
	
	P = new Persona(nombre, ID);
	if (B->agregarPersonas(P)) {
		Z.imprimeString("Se he inscrito a la persona correctamente\n");
		B->guardar();
	}
	else {
		Z.imprimeString("La persona ya se encuentra en el sitema\n");
	}
}*/

void Control::mostrarPersonas()
{
   //Interfaz Z;
	/*
	if (B->getListaPersonas()->cantidadMoldes()>0){
		Z->imprimeString(B->toStringPersonas());
	}
	else {
		Z->imprimeString("No hay Personas\n");
	}
        */
    Z->imprimeString(B->toStringPersonas());
 
    
   
}
/*
void Control::agregarLibro()
{
	Interfaz Z;
	string nombre,ID;
	Libro *L;
	Z.imprimeString("\tAgrega un libro...\n");
	Z.imprimeString("Ingrese los siguientes datos\n");
	Z.imprimeString("Nombre del Libro: "); nombre = Z.retornaString();
	Z.imprimeString("ID del libro: "); ID = Z.retornaString();
	
	 L = new Libro(nombre,ID);
	if (B->agregarLibros(L)) {
		Z.imprimeString("Se ha registrado el libro correctamente\n");
		B->guardar();
	}
	else {
		Z.imprimeString("El libro ya se encuentra en el sistema\n");
	}
}
void Control::mostrarLibros()
{
	Interfaz Z;
	if (B->getListaLibros()->cantidadMoldes()>0) {
		Z.imprimeString(B->toStringLibros());
	}
	else {
		Z.imprimeString("No hay Libros\n");
	}
}




void Control::eliminarPersona()
{
	Interfaz Z; string ID;
	if (B->getListaPersonas()->cantidadMoldes() > 0) {
		mostrarPersonas();
		Z.imprimeString("Digite el numero de ID de la persona por eliminar: "); ID = Z.retornaString();
		if (B->getListaPersonas()->buscayRetorna(ID)) {
			if (B->getListaPersonas()->elimina(ID)) {
				Z.imprimeString("Se ha eliminado\n");
			}
			else {
				Z.imprimeString("No se ha podido eliminar\n");
			}
		}
		else {
			Z.imprimeString("La persona no existe\n");
		}
	}
	else {
		Z.imprimeString("No hay personas\n");
	}
}

void Control::eliminarLibro()
{
	Interfaz Z; string ID;
	if (B->getListaLibros()->cantidadMoldes() > 0) {
		mostrarLibros();
		Z.imprimeString("Digite el ID de libro por eliminar: "); ID = Z.retornaString();
		if (B->getListaLibros()->buscayRetorna(ID)) {
		
			if (B->getListaLibros()->elimina(ID)) {
				Z.imprimeString("Se ha eliminado\n");
			}
			else {
				Z.imprimeString("No se ha podido eliminar\n");
			}
		}
		else {
			Z.imprimeString("El libro no existe\n");
		}
	}
	else {
		Z.imprimeString("No hay libros\n");
	}
}


*/
