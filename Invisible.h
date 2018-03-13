#ifndef INVISIBLE_H
#define INVISIBLE_H
#include<string>
#include"Escenario.h"
using namespace std;

class Invisible:public Escenario{
	public:
		Invisible();
		Invisible(string);
		void invisibles();
		void Especial();

};
#endif

