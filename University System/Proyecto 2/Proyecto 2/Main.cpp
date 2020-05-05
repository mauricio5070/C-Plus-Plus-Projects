#include "Control.h"

int main() {
	/*Profesor* p1 = new Profesor("Virolo", "2087", "82637672");
	Profesor* p2 = new Profesor("David", "2343", "82637672");
	Profesor* p3 = new Profesor("Ariel", "2087", "82637672");

	Estudiante* e1 = new Estudiante("Pepa", "2079", "8293");
	Estudiante* e2 = new Estudiante("Mario", "2287", "3973");
	Estudiante* e3 = new Estudiante("Rocio", "0182", "2818");

	Curso* c1 = new Curso("Fundamentos", "EIF200");
	Curso* c2 = new Curso("Programacion", "EIF201");
	Curso* c3 = new Curso("Soporte", "EIF202");


	Instituto* Ins = new Instituto("Ambientalista");
	Ins->agregarProfesores(p1);
	Ins->agregarProfesores(p2);
	Ins->agregarProfesores(p3);

	Ins->agregarEstudiante(e1);
	Ins->agregarEstudiante(e2);
	Ins->agregarEstudiante(e3);

	Ins->agregarCurso(c1);
	Ins->agregarCurso(c2);
	Ins->agregarCurso(c3);


	//Agregar grupo a curso
	cout << Ins->toStringProfes();
	string codigo, cedula, horario, nrc; int cupo, aula;
	cout << "Digite el numero de cedula del profesor por agregar al grupo: "; cin >> cedula;
	if (Ins->getListaProfes()->buscayRetorna(cedula) != NULL) {
		cout << "Horario: "; cin >> horario; cout << "NRC: "; cin >> nrc;
		cout << "Cupo: "; cin >> cupo; cout << "Aula: "; cin >> aula;
		Grupo* g = new Grupo(Ins->getListaProfes()->buscayRetorna(cedula), horario, nrc, cupo, aula);
		cout << Ins->toStringCursos();
		cout << "Digite el codigo del curso desea al que desea agregar el grupo: "; cin >> codigo;

		if (Ins->getListaCursos()->buscayRetorna(codigo) != NULL) {

			Ins->getListaCursos()->buscayRetorna(codigo)->agregarGrupo(g);
			cout << Ins->getListaCursos()->buscayRetorna(codigo)->getListaGrupos()->toString();
			system("pause");
		}
		else {
			cout << "No existe curso";
			exit(0);
		}
	}
	else
	{
		cout << "Cedula equivocada";
		exit(0);
	}


	cout << Ins->toStringCursos();

	cout << Ins->getListaCursos()->muestraGrupos();

	//Agregar estudiante a grupo
	int opc = 0;
	while (opc == 0) {

		cout << Ins->toStringEstudiantes();
		cout << "Digite el numero de cedula del estudiante por agregar: "; cin >> cedula;
		if (Ins->getListaEstudiantes()->buscayRetorna(cedula) != NULL) {
			cout << Ins->toStringCursos();
			cout << "Digite el codigo del curso al que desea ingresar estudiante: "; cin >> codigo;
			if (Ins->getListaCursos()->buscayRetorna(codigo) != NULL) {

				if (Ins->getListaCursos()->buscayRetorna(codigo)->cantidadGrupos() != 0) {

					cout << Ins->getListaCursos()->buscayRetorna(codigo)->toStringGrupos();
					cout << "Digite el NRC del grupo que desea ingresar el estudiante "; cin >> nrc;
					if (Ins->getListaCursos()->buscayRetorna(codigo)->getListaGrupos()->buscayRetorna(nrc) != NULL) {

						if (Ins->getListaCursos()->buscayRetorna(codigo)->getListaGrupos()->buscayRetorna(nrc)->agregarEstudiante(Ins->getListaEstudiantes()->buscayRetorna(cedula))) {
							cout << "Se ha metido estudiante en el grupo" << endl;
						}
						else {
							cout << "El grupo esta lleno o el estudiante ya ha sido registrado" << endl;
						}
					}
					else {
						cout << "No existe grupo" << endl;
					}
				}

				else {
					cout << "No hay grupos en este curso" << endl;
				}
			}

		else {
			cout << "No existe curso" << endl;
		}
		}
		else {
			cout << "El estudiante no esta matriculado en el instituto" << endl;
		}

	}

	


	Profesor* p1 = new Profesor("Virolo", "2800", "82637672");
	Profesor* p2 = new Profesor("David", "208", "82637672");
	Profesor* p3 = new Profesor("Ariel", "2080", "82637672");

	Estudiante* e1 = new Estudiante("Pepa", "180", "829379372");
	Estudiante* e2 = new Estudiante("Mario", "223", "397386133");
	Estudiante* e3 = new Estudiante("Rocio", "018", "2818912");
	
	Curso* c1 = new Curso("Fundamentos", "EIF200");
	Curso* c2 = new Curso("Programacion", "EIF201");
	Curso* c3 = new Curso("Soporte", "EIF202");


	Instituto* Ins = new Instituto("Ambientalista");
	Ins->cargar();
	Ins->agregarProfesores(p1);
	Ins->agregarProfesores(p2);
	Ins->agregarProfesores(p3);

	Ins->agregarEstudiante(e1);
	Ins->agregarEstudiante(e2);
	Ins->agregarEstudiante(e3);

	
	Ins->agregarCurso(c1);
	Ins->agregarCurso(c2);
	Ins->agregarCurso(c3);

	cout << Ins->toStringCursos();

	Ins->eliminaCurso("EIF200");

	cout << Ins->toStringCursos();
	cout << Ins->toStringEstudiantes() << endl << endl << endl;
	cout << Ins->toStringProfes();
	
	Ins->guardar();
	delete Ins;*/
Control* C= new Control();
C->iniciar();

delete C;
/*Instituto *i=new Instituto();
Estudiante* e1 = new Estudiante("Pepa", "180", "829379372");
i->agregarEstudiante(e1);
cout << i->toStringEstudiantes();*/

	//system("pause");
	return 0;

}
