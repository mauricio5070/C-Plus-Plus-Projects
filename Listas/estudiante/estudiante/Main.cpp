
#include "Estudiante.h"
#include "Lista.h"

void main()
{


	Estudiante* e1 = new Estudiante(54554, "Juan", 75, 20, 'M');
	Estudiante* e2 = new Estudiante(54884, "Marta", 62, 18, 'F');
	Estudiante* e3 = new Estudiante(54994, "Pedro", 100, 12, 'M');
	Estudiante* e4 = new Estudiante(54774, "Maria", 83, 17, 'F');
	Estudiante* e5 = new Estudiante(54664, "Oscar", 90, 25, 'M');

	Lista* lis = new Lista();

	lis->insertarInicio(e1);
	lis->insertarInicio(e2);
	lis->insertarInicio(e3);
	lis->insertarInicio(e4);
	lis->insertarInicio(e5);

	lis->eliminaFinal();


	cout << lis->toString();
	cout << "El numero de nodos es:" << endl << endl << lis->cuentaNodos() << endl << endl;
	cout << "El promedio de los estudiantes es :" << endl << endl << lis->promedio() << endl << endl;
	lis->elUltimo();
	
	//cin>>getId()
		
		
	
	system("pause");
	
	

}
