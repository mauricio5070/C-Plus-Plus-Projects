#include <iostream>
using namespace std;
#include "stdio.h"
#include <sstream>

#include "time.h"
#include <ctime>
#include "conio.h"


int main()
	
{
/*	
	time_t   t,i;
	
	char *p;
	
	
	i = time (&t);
	
	p = ctime (&i);  /* igual a: p = ctime (&t); */
	
	/*printf ("%s\n",p);*/
		
		

	time_t now = time(0);
	tm* time = localtime(&now);
	int Dia = time->tm_mday;
	int Mes = time->tm_mon + 1;
	int Anio = time->tm_year+ 1900;
	cout << "Fecha de compra: " << Dia << "/" << Mes << "/" << Anio << endl;
	cout<<endl<<endl;
	cout<<"$"<<endl;
	//ñ
	cout << "Estilo: Monta"<<char(164)<<"era" << endl;
	
	char* a= new char[50];
	cout << "Digite apellidos" << endl;
	cin.getline(a,50);
	cout << a<<endl;
	getch();
	return 0;
	
}
