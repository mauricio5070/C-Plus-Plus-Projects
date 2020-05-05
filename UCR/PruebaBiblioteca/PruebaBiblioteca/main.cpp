
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

