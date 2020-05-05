#ifndef PERSONA_H
#define PERSONA_H
#include<sstream>
#include "objeto.h"
using namespace std;
class persona: public objeto {
public:
    persona(string);
    string toString()const;
    virtual ~persona();
    
    
    virtual ostream& serializar(ostream&)const;
    static persona* deserializar(istream&);


private:
    string nombre;
};

#endif /* PERSONA_H */

