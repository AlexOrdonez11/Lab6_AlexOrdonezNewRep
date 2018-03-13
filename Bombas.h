#include <string>
#ifndef BOMBAS_H
#define BOMBAS_H
#include"Item.h"

using namespace std;

class Bombas:public Item{
	private:
		int explota;
	public:
		Bombas();
		Bombas(int,int,char);
		virtual void setExplota();
		int getExplota();
		virtual void Explota(Item***& ) = 0;
};
#endif
