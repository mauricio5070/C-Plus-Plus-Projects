#include  <iostream> 
#include<string>
using namespace std;

class  Persona {
protected:
	// contenido de persona 

public:
	virtual void food(){}
};


class  Empleado : public  Persona {
private:
	string  nombre;
	string  apellido;
	double  salario;
public:
	Empleado(string fName, string lName, double sal) {
		nombre = fName;
		apellido = lName;
		salario = sal;
	}

	string primerNombre() {
		return nombre;
	}
	double getSueldo() {
		return salario;
	}

	void mostrar() {
		cout << "Primer Nombre: " << nombre << " Apellido: "
			<< apellido << " Salario: " << salario << endl;
	}

	void agregarBono(double bono)
	{
		salario += bono;
	}

	virtual void food() {}
};

class  Administrador : public  Empleado {
private:
	double  commision;
public:
	Administrador(string fName, string lName, double sal, double comm)
		: Empleado(fName, lName, sal) {
		commision = comm;
	}

	double getComm() {
		return  commision;
	}
};

class  Secretario : public  Empleado {
private:
	Administrador * admin;
public:
	Secretario(string fName, string lName, double sal, Administrador * man)
		: Empleado(fName, lName, sal) {
		admin = man;
	}

	Administrador * getAdministrador() {
		return admin;
	}
};

void felicite(Empleado * emp) {
	cout << "Feliz Cumpleaños !!!" << endl;
	emp->agregarBono(200);
	emp->mostrar();
};

int main() {
	// puntero a la clase de base del objeto 
	Empleado * emp;

	// objeto de la clase derivada 
	Administrador m1("Pedro", "Perez", 3000, 2);
	Secretario c1("Marilyn", "Manson", 1000, &m1);

	// upcasting implícito 
	// Upcasting es un proceso de tratamiento de un 
	// puntero o una referencia de objeto de clase 
	// derivada como puntero de clase base. 
	// Sólo tiene que asignar puntero clase derivada
	// (o de referencia) al puntero de clase base :
	emp = &c1;

	// Está bien 
	cout << emp->primerNombre() << endl;
	cout << emp->getSueldo() << endl;

	// Falla porque upcasting se utiliza 
	//cout << emp->getComm();

	felicite(&c1);
	felicite(&m1);

	cout << "Administrador de " << c1.primerNombre() << " es " << c1.getAdministrador()->primerNombre();
	// Downcasting es un proceso inverso de upcasting.
	// Convierte puntero de clase base al puntero de 
	// la clase derivada.Downcasting debe hacerse 
	// manualmente.Esto significa que usted tiene que 
	// especificar el tipo de conversión explícita.
	// Downcasting no es seguro como upcasting.
	// Usted sabe que un objeto de clase derivada 
	// puede ser siempre tratado como objeto de la 
	// clase base.Sin embargo, lo contrario no es 
	// correcto.
	// Por ejemplo, un gerente es siempre una persona; 
	// Sin embargo, una persona no siempre es un 
	// Administrador.Podría ser un secretario también.
	// Usted tiene que utilizar una conversión 
	// explícita para downcasting :
	cout << endl << endl;
	cout << "<<<<< Ejemplo del DownCasting >>>" << endl;
	Empleado e1("Pedro", "verde", 1400);

	// intenta convertir un empleado en Administrador 

	Administrador * m3 = (Administrador *)(&e1);
	cout << m3->primerNombre() << " --> " << m3->getComm() << endl;

	//e1 objeto no es un objeto de la clase Administrador. 
	// No contiene ninguna información acerca de la comisión. 
	// Por eso una operación de este tipo puede producir 
	// resultados inesperados.
	// Este es el principal peligro de downcasting.

	// Se puede utilizar un molde de seguridad que pueden 
	// ayudarle a saber, si un tipo se puede convertir 
	// correctamente a otro tipo.

	// dynamic_cast es un operador que convierte de manera 
	// segura un tipo a otro tipo.En el caso, la conversación 
	// es posible y seguro, devuelve la dirección del objeto 
	// que se convierte.De lo contrario, devuelve nullptr.

	//dynamic_cast tiene la siguiente sintaxis


	//   dynamic_cast <NEW_TYPE>  (objeto)

	//Si se desea utilizar el elenco dinamico para Downcasting entonces 
	//la clase base debe ser polimorfica, debe tener por lo menos una funcion virtual 
	//Entonces hay que modificar la clase base mediante la adicion de una funcion virtual

	//virtual void food() la q sea
	//Ahora se puede utilizar para convertir downcasting, punteros de la clase 
	//de los empleados a punteros de clases derivadas

	Empleado e2("Peter", "Green", 1400);
	Administrador* m4= dynamic_cast <Administrador*>(& e2);
	if (m4) { cout << endl<<m4->getComm() << endl; }
	else { cout <<endl<< "No se pudo realizar la conversion de tipo" << endl; }


	system("pause");
	return 0;
}
	