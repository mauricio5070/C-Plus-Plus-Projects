#ifndef NODOG
#define NODOG
#include "Grupo.h"

class NodoG {
private:
	Grupo* Grup;
	NodoG* Sig;

public:
	NodoG(Grupo* = NULL, NodoG* = NULL);
	~NodoG();
	void setGrupo(Grupo*);
	void setSig(NodoG*);
	Grupo* getGrupo();
	NodoG* getSig();
	string toStringNodoG();
};
#endif
