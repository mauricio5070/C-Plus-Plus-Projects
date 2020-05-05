#include "racional.h"


int main(int, char**) 
{
	racional   f1(10,5); 
	racional   f2(8,2);
	racional   f3(4); 
	racional   f4; 
	racional   faux;

	cout<<f1.toString()<<endl;
	cout<<f2.toString()<<endl;
	cout<<f3.toString()<<endl;
	cout<<f4.toString()<<endl<<endl;

	cout <<"La simplificacion de"<< f1.toString()<<"es:";
	racional::simplificar(f1); 	// El metodo simplificar es llamado sin necesidad de un objeto ya que es un método static
	cout <<f1.toString()<<endl<<endl<<endl;
	
		
	cout<<"Elevar  fraccion: "<<endl;
	cout<<f1.toString()<<"a la 2 "<<"=";
     f1.elevaFraccionAla(2);
	cout<<f1.toString()<<endl<<endl;

	cout<<"Sumar fracciones: "<<endl;
	faux= f1.sumar(f2);
	cout<<f1.toString() << "+ "<< f2.toString()<<"=" << faux.toString()<<endl<<endl;
	
	cout<<"Restar  fracciones:"<<endl;
	faux= f1.restar(f2);
	cout<<f1.toString() << "- "<< f2.toString()<<"=" << faux.toString()<<endl<<endl;
	
	cout<<endl<<"Multiplicar fracciones:"<<endl;
	faux= f1.multiplicar(f2);
	cout<<f1.toString() << " * "<< f2.toString()<<"=" <<  faux.toString()<<endl;

	cout<<endl<<"Dividir fracciones:"<<endl;
	faux= f1.dividir(f2);
	cout<<f1.toString() << "/"<< f2.toString()<<"=" <<  faux.toString()<<endl;

	cout<<endl<<"Equivalentes:"<<endl;
	cout<<f1.toString() << "equivalente a "<< f2.toString()<<"? R/" ;


	(f1.equivalente(f2) == true)  ?  cout<<"Si"<<endl : cout<<"No"<<endl;
	
	/*
	if (f1.equivalente(f2))  	 // evite estas exprensiones 
	{ cout<<"Si"<<endl;	}
	else
	{	cout<<"No"<<endl;	}
	*/
	cin.get();
}