#ifndef ESPINA_H
#define ESPINA_H
#include"Bombas.h"
#include "Item.h"
using namespace std;

class Espina:public Bombas{
	public:
		Espina();
		Espina(int,int,char);
		void Explota(Item***&);
};
#endif
