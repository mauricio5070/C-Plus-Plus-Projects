#include "Control.h"

Control::Control()
{
	I = new Instituto();
	I->cargar();
}

void Control::iniciar()
{
	Interfaz Z; int opc; bool continuar = true;
	do {
		Z.imprimeString("\tBienvenido al sistema de matricula del Instituto\n");
		Z.imprimeString("1- Matricular Estudiante al Instituto\n");
		Z.imprimeString("2- Inscribir profesor en el Instituto\n");
		Z.imprimeString("3- Crear un nuevo curso\n");
		Z.imprimeString("4- Agregar Grupo\n");
		Z.imprimeString("5- Mostrar Estudiantes\n");
		Z.imprimeString("6- Mostrar Profesores\n");
		Z.imprimeString("7- Mostrar Cursos\n");
		Z.imprimeString("8- Listar los grupos abiertos por curso\n");
		Z.imprimeString("9- Eliminar Estudiante\n");
		Z.imprimeString("10- Elimina profesor\n");
		Z.imprimeString("11- Elimina Curso\n");
		Z.imprimeString("12- Elimina Grupo\n");
		Z.imprimeString("13- Agregar Estudiante a Grupo\n");
		Z.imprimeString("14- Listar los estudiantes matriculados por grupo\n");
		Z.imprimeString("15- Listar los cursos matriculados por estudiante\n");
		Z.imprimeString("16- Listar los cursos asignados por profesor\n");
		Z.imprimeString("0- SALIR DEL SISTEMA\n");
		Z.imprimeString("\tDigite una opcion: "); opc = Z.retornaInt();


		switch (opc) {
		case 0:
			I->guardar();
			continuar = false; 
			delete I;
			 break;

		case 1:
			system("cls");
			agregarEstudiante();
			system("pause");
			system("cls");
			break;
		case 2:
			system("cls");
			agregarProfe();
			system("pause");
			system("cls");
			break;
		case 3:
			system("cls");
			agregarCurso();
			system("pause");
			system("cls");
			break;
		case 4:
			system("cls");
			agregarGrupo();
			system("pause");
			system("cls");
			break;
		case 5:
			system("cls");
			mostrarEstudiantes();
			system("pause");
			system("cls");
			break;
		case 6:
			system("cls");
			mostrarProfes();
			system("pause");
			system("cls");
			break;
		case 7:
			system("cls");
			mostrarCursos();
			system("pause");
			system("cls");
			break;
		case 8:
			system("cls");
			mostrarGrupos();
			system("pause");
			system("cls");
			break;
		case 9:
			system("cls");
			eliminarEstudiante();
			system("pause");
			system("cls");
			break;
		case 10:
			system("cls");
			eliminarProfe();
			system("pause");
			system("cls");
			break;
		case 11:
			system("cls");
			eliminarCurso();
			system("pause");
			system("cls");
			break;
		case 12:
			system("cls");
			eliminarGrupo();
			system("pause");
			system("cls");
			break;
		case 13:
			system("cls");
			agregarEstudianteGrupo();
			system("pause");
			system("cls");
			break;
		case 14:
			system("cls");
			mostrarEstudiantesGrupo();
			system("pause");
			system("cls");
			break;
		case 15:
			system("cls");
			cursosXEstudiante();
			system("pause");
			system("cls");
			break;
		case 16:
			system("cls");
			cursosXProfesor();
			system("pause");
			system("cls");
			break;
		default:
			system("cls");
			Z.imprimeString("OPCION INVALIDA\n"); system("pause"); system("cls");

		}
	} while (continuar);
}

void Control::agregarEstudiante()
{
	Interfaz Z;
	string nombre, cedula, telefono;
	Estudiante *P;
	Z.imprimeString("\tMatricula de estudiante\n");
	Z.imprimeString("Ingrese los siguientes datos\n");
	Z.imprimeString("Nombre del estudiante: "); nombre = Z.retornaString();
	Z.imprimeString("Cedula del estudiante: "); cedula = Z.retornaString();
	Z.imprimeString("Numero de telefono del estudiante: "); telefono = Z.retornaString();
	P = new Estudiante(nombre, cedula, telefono);
	if (I->agregarEstudiante(P)) {
		Z.imprimeString("Se ha matriculado estudiante al Instituto\n");
		I->guardar();
	}
	else {
		Z.imprimeString("El estudiante ya se encuentra matriculado\n");
	}
}

void Control::mostrarEstudiantes()
{
	Interfaz Z;
	if (I->getListaEstudiantes()->cantidadPersonas()>0) {
		Z.imprimeString(I->toStringEstudiantes());
	}
	else {
		Z.imprimeString("No hay estudiantes\n");
	}
}

void Control::agregarProfe()
{
	Interfaz Z;
	string nombre, cedula, telefono;
	Profesor *P;
	Z.imprimeString("\tMatricula de estudiante\n");
	Z.imprimeString("Ingrese los siguientes datos\n");
	Z.imprimeString("Nombre del profesor: "); nombre = Z.retornaString();
	Z.imprimeString("Cedula del profesor: "); cedula = Z.retornaString();
	Z.imprimeString("Numero de telefono del profesor: "); telefono = Z.retornaString();
	P = new Profesor(nombre, cedula, telefono);
	if (I->agregarProfesores(P)) {
		Z.imprimeString("Se ha registrado al profesor\n");
		I->guardar();
	}
	else {
		Z.imprimeString("El profesor ya se encuentra registrado\n");
	}
}
void Control::mostrarProfes()
{
	Interfaz Z;
	if (I->getListaProfes()->cantidadPersonas()>0) {
		Z.imprimeString(I->toStringProfes());
	}
	else {
		Z.imprimeString("No hay Profesores\n");
	}
}

void Control::agregarCurso()
{
	Interfaz Z;
	string nombre, codigo;
	Curso *C;
	Z.imprimeString("\tMatricula de estudiante\n");
	Z.imprimeString("Ingrese los siguientes datos\n");
	Z.imprimeString("Nombre del curso: "); nombre = Z.retornaString();
	Z.imprimeString("Codigo del curso: "); codigo = Z.retornaString();
	
	C = new Curso(nombre, codigo);
	if (I->agregarCurso(C)) {
		Z.imprimeString("Se ha guardado el curso\n");
		I->guardar();
	}
	else {
		Z.imprimeString("El curso ya existe\n");
	}
}
void Control::agregarGrupo()
{
	Interfaz Z;
	string codigo, cedula, horario, nrc; int cupo, aula;
	if (I->getListaCursos()->cantidadCursos()<=0) {
		Z.imprimeString("No se puede agregar Grupo porque no hay cursos\n");
	}
	else {
		if (I->getListaProfes()->cantidadPersonas() > 0) {
			mostrarProfes();
			Z.imprimeString("Digite el numero de cedula del profesor por agregar al grupo: "); cedula = Z.retornaString();
			if (I->getListaProfes()->buscayRetorna(cedula) != NULL) {
				Z.imprimeString("Digite el Horario: "); horario = Z.retornaString();
				Z.imprimeString("Digite el NRC: "); nrc = Z.retornaString();
				Z.imprimeString("Digite el Cupo: "); cupo = Z.retornaInt();
				Z.imprimeString("Digite el numero aula: "); aula = Z.retornaInt();
				Grupo* g = new Grupo(I->getListaProfes()->buscayRetorna(cedula), horario, nrc, cupo, aula);
				Z.imprimeString("\n");
				system("cls");
				mostrarCursos();
				Z.imprimeString("Digite el codigo del curso al que desea agregar el grupo: "); codigo = Z.retornaString();
				if (I->getListaCursos()->buscayRetorna(codigo) != NULL) {

					if (I->getListaCursos()->buscayRetorna(codigo)->agregarGrupo(g)) {
						Z.imprimeString("Se ha creado grupo\n");
					}
					else {
						Z.imprimeString("No se ha podido crear grupo");
					}
				}
				else {
					Z.imprimeString("No existe curso\n");
				}
			}
			else {
				Z.imprimeString("No existe profesor\n");
			}
		}
		else {
			Z.imprimeString("No se puede agregar Grupo porque no hay profesores\n");
		}
	}
	
}
void Control::mostrarCursos()
{
	Interfaz Z;
	if (I->getListaCursos()->cantidadCursos()>0) {
		Z.imprimeString(I->toStringCursos());
	}
	else {
		Z.imprimeString("No hay Cursos\n");
	}
}

void Control::mostrarGrupos()
{
	Interfaz Z;
	if (I->getListaCursos()->cantidadGrupos() > 0) {
		Z.imprimeString(I->toStringGrupos());
	}
	else {
		Z.imprimeString("No hay grupos\n");
	}
}

void Control::eliminarEstudiante()
{
	Interfaz Z; string cedula;
	if (I->getListaEstudiantes()->cantidadPersonas() > 0) {
		mostrarEstudiantes();
		Z.imprimeString("Digite el numero de cedula del estudiante por eliminar: "); cedula = Z.retornaString();
		if (I->getListaEstudiantes()->buscayRetorna(cedula)) {
			if (I->getListaEstudiantes()->elimina(cedula)) {
				Z.imprimeString("Se ha eliminado\n");
			}
			else {
				Z.imprimeString("No se ha podido eliminar\n");
			}
		}
		else {
			Z.imprimeString("El estudiante no existe\n");
		}
	}
	else {
		Z.imprimeString("No hay estudiantes\n");
	}
}

void Control::eliminarProfe()
{
	Interfaz Z; string cedula;
	if (I->getListaProfes()->cantidadPersonas() > 0) {
		mostrarProfes();
		Z.imprimeString("Digite el numero de cedula del profesor por eliminar: "); cedula = Z.retornaString();
		if (I->getListaProfes()->buscayRetorna(cedula)) {
			//I->getListaCursos()->eliminaGruposProfesor(cedula);
			if (I->getListaProfes()->elimina(cedula)) {
				Z.imprimeString("Se ha eliminado\n");
			}
			else {
				Z.imprimeString("No se ha podido eliminar\n");
			}
		}
		else {
			Z.imprimeString("El profesor no existe\n");
		}
	}
	else {
		Z.imprimeString("No hay profesores\n");
	}
}

void Control::eliminarCurso()
{
	Interfaz Z; string codigo;
	if (I->getListaCursos()->cantidadCursos() > 0) {
		mostrarCursos();
		Z.imprimeString("Digite el codigo del curso por eliminar: "); codigo = Z.retornaString();
		if (I->getListaCursos()->buscayRetorna(codigo) != NULL) {
			if (I->getListaCursos()->elimina(codigo)) {
				Z.imprimeString("Se ha eliminado\n");
			}
			else {
				Z.imprimeString("No se ha podido eliminar\n");
			}
		}
		else {
			Z.imprimeString("El curso no existe\n");
		}
	}
	else {
		Z.imprimeString("No hay Cursos\n");
	}
}

void Control::eliminarGrupo()
{
	Interfaz Z; string nrc;
	if (I->getListaCursos()->cantidadGrupos() > 0) {
		mostrarGrupos();
		Z.imprimeString("Digite el nrc del grupo por eliminar: "); nrc = Z.retornaString();
		if (I->getListaCursos()->buscayRetornaGrupo(nrc) != NULL) {
	
			if (I->getListaCursos()->eliminaGrupo(nrc)) {
				Z.imprimeString("Se ha eliminado\n");
			}
			else {
				Z.imprimeString("No se ha podido eliminar\n");
			}
		}
		else {
			Z.imprimeString("El grupo no existe\n");
		}
	}
	else {
		Z.imprimeString("No hay Grupos\n");
	}
}

void Control::agregarEstudianteGrupo()
{
	Interfaz Z;
	if (I->getListaEstudiantes()->cantidadPersonas() > 0) {
		if (I->getListaCursos()->cantidadGrupos()> 0) {
			mostrarEstudiantes();
			string cedula;
			Z.imprimeString("Digite la cedula del estudiante por agregar a Grupo: ");
			cedula = Z.retornaString();
			if (I->getListaEstudiantes()->buscayRetorna(cedula) != NULL) {
				system("cls");
				Persona* estu = I->getListaEstudiantes()->buscayRetorna(cedula);
				string codigo;
				mostrarCursos();
				Z.imprimeString("Digite el codigo del curso al que quiere matricular estudiante: ");
				codigo = Z.retornaString();
				if (I->getListaCursos()->buscayRetorna(codigo)!=NULL) {
					system("cls");
					if (I->getListaCursos()->buscayRetorna(codigo)->cantidadGrupos() > 0) {
						Curso* cur = I->getListaCursos()->buscayRetorna(codigo);
						Z.imprimeString(cur->toStringGrupos());
						string nrc;
						Z.imprimeString("Digite el NRC del Grupo en el que desea agregar estudiante: ");
						nrc = Z.retornaString();
						if (cur->getListaGrupos()->buscayRetorna(nrc) != NULL) {
							system("cls");
							if (cur->getListaGrupos()->buscayRetorna(nrc)->agregarEstudiante(estu)) {
								Z.imprimeString("Se ha matriculado estudiante al grupo\n");
							}
							else {
								Z.imprimeString("El grupo esta lleno o el estudiante ya ha sido registrado\n");
							}
						}
						else {
							Z.imprimeString("No existe grupo\n");
						}
					}
					else {
						Z.imprimeString("No hay Grupos\n");
					}
				}
				else {
					Z.imprimeString("No existe curso\n");
				}
			}
			else {
				Z.imprimeString("No existe estudiante\n");
			}
		}
		else {
			Z.imprimeString("No hay grupos\n");
		}
	}
	else {
		Z.imprimeString("No hay estudiantes\n");
	}
}

void Control::mostrarEstudiantesGrupo()
{
	Interfaz Z;
	if (I->getListaCursos()->cantidadGrupos()>0) {
		Z.imprimeString(I->getListaCursos()->mostrarEstudiantesGrupos());
	}
	else {
		Z.imprimeString("No hay Grupos\n");
	}
}

void Control::cursosXEstudiante()
{
	Interfaz Z; string cedula;
	mostrarEstudiantes();
	Z.imprimeString("Digite la cedula del estudiante por consultar: "); cedula = Z.retornaString();
	if (I->getListaEstudiantes()->buscayRetorna(cedula)!=NULL) {
		system("cls");
		Z.imprimeString(I->getListaEstudiantes()->buscayRetorna(cedula)->toString());
		Z.imprimeString("\n\tEl estudiante ha sido matriculado en los siguientes cursos:\n\n");
		Z.imprimeString(I->getListaCursos()->cursosPorEstudiante(cedula));
	}
	else {
		Z.imprimeString("El estudiante no existe\n");
	}
}

void Control::cursosXProfesor()
{
	Interfaz Z; string cedula;
	mostrarProfes();
	Z.imprimeString("Digite la cedula del Profesor por consultar: "); cedula = Z.retornaString();
	if (I->getListaProfes()->buscayRetorna(cedula) != NULL) {
		system("cls");
		Z.imprimeString(I->getListaProfes()->buscayRetorna(cedula)->toString());
		Z.imprimeString("\n\tEl profesor tiene asignado los siguientes cursos:\n\n");
		Z.imprimeString(I->getListaCursos()->cursosPorProfesor(cedula));
	}
	else {
		Z.imprimeString("El profesor no existe\n");
	}
}
