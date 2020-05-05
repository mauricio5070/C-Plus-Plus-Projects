#ifndef TIQUETE
#define TIQUETE
#include <iostream>
#include <sstream>
using namespace std;

class Tiquete {
private:
		int numTiquete;
		int numAsiento;

public:
	Tiquete(int,int);
	~Tiquete();
	string toString();
	int getNum();
	void setNum(int);

};

#endif