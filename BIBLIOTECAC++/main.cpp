
#include "Control.h"
#include <iostream>
#include <cstdlib>

using namespace std;



int main() {
Control* C= new Control();
C->iniciar();

delete C;
system("pause");    
return 0;
}

/*int main(){
    
    
  Persona* p1 = new Persona("Laura", "50769");
    Persona* l2 = new Persona("Megan","5288");
   Persona* k2 = new Persona("Oscar","8288");
    Biblioteca* bib = new Biblioteca();
    */
  /* bib->agregarPersonas(p1);
    bib->agregarPersonas(l2);
    bib->agregarPersonas(k2);*/
   /* bib->cargar();
    //bib->guardar();
    
    cout<<bib->toStringPersonas()<<endl;
   cout<<bib->toStringLibros()<<endl;
    //cout<<bib->toStringBiblioteca()<<endl;
    
    delete bib;
return 0;   
}*/