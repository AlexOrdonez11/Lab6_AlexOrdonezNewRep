#include <string>
#include "Item.h"

Item::Item(){

}
Item::Item(int x,int y,char figura){
	this->x=x;
	this->y=y;
	this->figura=figura;
}
int Item::getX(){
	return x;
}
int Item::getY(){
	return y;
}
char Item::getFigura(){
	return figura;
}
void Item::setLetra(char l){
	figura=l;
}
void Item::setXY(int x,int y){
	this->x=x;
	this->y=y;
}
