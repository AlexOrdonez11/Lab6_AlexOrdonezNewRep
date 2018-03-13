#ifndef V_H
#define V_H
#include"Bombas.h"
#include "Item.h"
using namespace std;

class V:public Bombas{
	public:
		V();
		V(int,int,char);
		void Explota(Item***&);
};
#endif
