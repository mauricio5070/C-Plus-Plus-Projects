#include"racional.h"



/*CONSTRUCTOR CON DOS PARAMETROS
El siguiente constructor funciona para las siguientes alternativas:
1- Env�o de 0 par�metros, en este caso el numerador ser� 0 y el denominador 1  (seg�n se indica en el prototipo del m�todo)
2- Env�o de 1 par�metro, en este caso el numerador asumir� el valor del par�metro recibido y el denominador el valor
de cero (seg�n se indica en el prototitpo del m�todo)
3- Env�o de 2 par�metros, en este caso el numerador y el denominador asumiran los valores recibidos por parametro.
*/
//-------------------------------------------------------------
racional::racional(int num, int den) : numerador(num), denominador(den) {
}


// Este siguiente constructor en comentarios, es exactamente el mismo anterior
// simplemente cambia la sintaxis pero la funcionalidad es la misma

//Racional::Racional(int num, int den){
//numerador=num;
//denominador=den;
//}

/*
Aclaracion importante:
Siempre en todo programa, debemos preocupar porque los  objetos nunca posean estados invalidos en nungun
momento de la ejecuci�n, sin embargo el constructor con par�metros  que se ha implementado, no impide la asignaci�n
de  cero en el denominador, la cual seria claramente un valor invalido.
Para solucionar este problema en forma eficiente se requiere el uso de excepciones el cual es un tema se ver� mas adelante en la carrera.
*/
//-------------------------------------------------------------
int racional::getNumerador() { return numerador; }
//-------------------------------------------------------------
int racional::getDenominador() { return denominador; }
//-------------------------------------------------------------
string racional::toString() {
	stringstream s;
	s << " " << numerador << "/" << denominador << " ";
	return s.str();
}
//-------------------------------------------------------------
int racional::mcd(int m, int n) {
	return (n == 0) ? m : mcd(n, m % n);
}

/*
En la soluci�n del metodo mcd, se presenta uso del   operador ternario, el cual es una condicional b�sica que todo programador deber�a
conocer, su funcionalidad es la misma que  un if-else, pero con una sintaxis diferente.

Este  operador condicional es el �nico operador ternario que se presenta en el lenguaje C++ y nos permite  para tomar decisiones,
proporcionando un  resultado entre dos posibilidades seg�n una condici�n determinada.

Sintaxis del operador ternario (?:):
expresi�n1 ? expresi�n2 : expresi�n3

Se eval�a la expresi�n1, y si su resultado es verdadero, entonces se eval�a y devuelve como resultado la expresi�n2. Si expresi�n1
es falso, se eval�a y devuelve expresi�n3. En este caso, es equivalente a escribir:


if (expresi�n1) {
expresi�n2;
} else {
expresi�n3;
}
*/
//-------------------------------------------------------------
void racional::simplificar(racional&  fra) {
	if (fra.numerador == 0) {
		fra.denominador = 1;
	}
	else {
		int m = mcd(abs(fra.numerador), fra.denominador);
		fra.numerador /= m;
		fra.denominador /= m;
	}
}
//-------------------------------------------------------------
bool racional::equivalente(racional q2) {
	return ((numerador * q2.denominador) == (q2.numerador * denominador));
}
//-------------------------------------------------------------
racional racional::sumar(racional  obj) {
	racional res;
	res.numerador = getNumerador()*obj.getDenominador() + getDenominador()*obj.getNumerador();
	res.denominador = getDenominador()*obj.getDenominador();
	simplificar(res);
	return res;
}
//-------------------------------------------------------------
racional racional::restar(racional  obj) {
	racional res;
	res.numerador = getNumerador()*obj.getDenominador() - getDenominador()*obj.getNumerador();
	res.denominador = getDenominador()*obj.getDenominador();
	simplificar(res);
	return res;
}
//-------------------------------------------------------------
racional racional::multiplicar(racional  obj) {
	racional res;
	res.numerador = getNumerador()*obj.getNumerador();
	res.denominador = getDenominador()*obj.getDenominador();
	simplificar(res);
	return res;
}
//-------------------------------------------------------------
racional racional::dividir(racional  obj) {
	racional res;
	res.numerador = getNumerador()*obj.getDenominador();
	res.denominador = getDenominador()*obj.getNumerador();
	simplificar(res);
	return res;
}
//-------------------------------------------------------------
int racional::elevaNumero(int a, int n) {
	int i = 1, resultado = 1;
	while (i <= n) {
		resultado = resultado * a;
		i++;
	}
	return resultado;
}
//-------------------------------------------------------------
void racional::elevaFraccionAla(int p) {
	numerador = elevaNumero(numerador, p);
	denominador = elevaNumero(denominador, p);
}


//----------------------------------------------------------------
