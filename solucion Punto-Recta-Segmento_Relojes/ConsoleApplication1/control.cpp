#include "control.h"
#include "interfaz.h"
#include "punto.h"

#include <string>
#include <sstream>

// Ninguna clase debe tener cin o cout, esto se lo delegamos unicamente a la clase Interfaz
void control::iniciar()
{
	interfaz inter;
	recta  r1;
	recta  r2;
	inter.imprimir ("\n<<<<<<<<< Producto #1 >>>>>>>>\n");
	r1= datosProducto();
	inter.imprimir("\n<<<<<<<<< Producto #2 >>>>>>>>\n");
	r2 = datosProducto();
	comparaRectas(r1, r2);
}

//----------------------------------------------------------

recta control::datosProducto()
{  
	interfaz inter;
	double  pre1, can1, pre2, can2, x, res;
	inter.imprimir("Ingrese un precio anterior:");
	pre1 = inter.leerDouble();
	inter.imprimir("Ingrese la cantidad vendida con ese precio:");
	 can1= inter.leerDouble();
	inter.imprimir("Ingrese otro precio anterior:");
	pre2 = inter.leerDouble();
	inter.imprimir("Ingrese la cantidad vendida con ese precio:");
	can2 = inter.leerDouble();
	inter.imprimir("Digite el precio sobre el cual desea especular la demanda:");
	 x = inter.leerDouble();

	segmento seg1(punto(pre1, can1), punto(pre2, can2));
	recta rec(seg1);
	res = rec.resolverFuncion(x);
	stringstream s;

	s <<"Si cobra el precio de " << x <<" la demanda sera de: " << res<< "\n\n";
	inter.imprimir(s.str());
	return rec;
}  



//----------------------------------------------------------

 void  control::comparaRectas(recta rec1, recta rec2)
{  
   interfaz inter;
   if (rec1.esParalela(rec2) == true)
   {
	  inter.imprimir("El comportamiento de ambos productos es proporcionalmente equivalente (rectas paralelas)\n");
	  inter.imprimir("La demanda de ambos productos es igualmente sencible al precio \n" );
   }
  else
   {
	  inter.imprimir("\nEl comportamiento de ambos productos NO es proporcionalmente equivalente (NO son rectas paralelas)\n");
	  inter.imprimir("\nEl producto mas sencible al cambio del mercado es el producto #: ");
	  inter.imprimir(rec1.obtenerPendiente() > rec2.obtenerPendiente() ? 1 : 2);
  } 
   
}

