
#include "persona.h"

persona::persona(string nom):nombre(nom) {
}
string persona::toString()const{
    stringstream s;
    s<<"Nombre: "<<nombre<<endl;
    return s.str();
}

persona::~persona() {
}

ostream& persona::serializar(ostream& salida)const{
    salida<<nombre<<"\n";
    return salida;
}

persona* persona::deserializar(istream& entrada){
    persona* aux = NULL;
    string registro;
    stringstream s;
    getline(entrada,registro);
    if(!entrada.good())
        throw -1;
    s<<registro;
    
    string nombre = leerCampo<string>(s);
    
    aux= new persona (nombre);
    return aux;
}
