#ifndef NODOC
#define NODOC
#include "Curso.h"

class NodoC {
private:
	Curso* Cur;
	NodoC* Sig;

public:
	NodoC(Curso* = NULL, NodoC* = NULL);
	~NodoC();
	void setCurso(Curso*);
	void setSig(NodoC*);
	Curso* getCurso();
	NodoC* getSig();
	string toStringNodoC();
};
#endif
