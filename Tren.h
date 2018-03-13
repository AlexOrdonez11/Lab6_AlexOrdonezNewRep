#ifndef TREN_H
#define TREN_H
#include "Escenario.h"
#include<string>

using namespace std;

class Tren:public Escenario{
	public:
		Tren();
		Tren(string);
		void Carrito();
		void Especial();
};
#endif
