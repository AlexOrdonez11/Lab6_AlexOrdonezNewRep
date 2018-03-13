#include <string>

#ifndef ITEM_H
#define ITEM_H

using namespace std;

class Item{
	private:
		int x;
		int y;
		char figura;
	public:
		Item();
		Item(int,int,char);
		virtual int getY();
		int getX();
		char getFigura();
		void setLetra(char);
		void setXY(int,int);

};
#endif
