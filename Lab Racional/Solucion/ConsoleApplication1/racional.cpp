#include"racional.h"



/*CONSTRUCTOR CON DOS PARAMETROS
El siguiente constructor funciona para las siguientes alternativas:
1- Envío de 0 parámetros, en este caso el numerador será 0 y el denominador 1  (según se indica en el prototipo del método)
2- Envío de 1 parámetro, en este caso el numerador asumirá el valor del parámetro recibido y el denominador el valor
de cero (según se indica en el prototitpo del método)
3- Envío de 2 parámetros, en este caso el numerador y el denominador asumiran los valores recibidos por parametro.
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
momento de la ejecución, sin embargo el constructor con parámetros  que se ha implementado, no impide la asignación
de  cero en el denominador, la cual seria claramente un valor invalido.
Para solucionar este problema en forma eficiente se requiere el uso de excepciones el cual es un tema se verá mas adelante en la carrera.
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
En la solución del metodo mcd, se presenta uso del   operador ternario, el cual es una condicional básica que todo programador debería
conocer, su funcionalidad es la misma que  un if-else, pero con una sintaxis diferente.

Este  operador condicional es el único operador ternario que se presenta en el lenguaje C++ y nos permite  para tomar decisiones,
proporcionando un  resultado entre dos posibilidades según una condición determinada.

Sintaxis del operador ternario (?:):
expresión1 ? expresión2 : expresión3

Se evalúa la expresión1, y si su resultado es verdadero, entonces se evalúa y devuelve como resultado la expresión2. Si expresión1
es falso, se evalúa y devuelve expresión3. En este caso, es equivalente a escribir:


if (expresión1) {
expresión2;
} else {
expresión3;
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
