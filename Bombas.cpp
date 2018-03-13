#include "Bombas.h"
#include "Item.h"

Bombas::Bombas(){

}
Bombas::Bombas(int x,int y,char letra):Item(x,y,letra){
	explota=4;
}
void Bombas::setExplota(){
	explota=explota-1;
}
int Bombas::getExplota(){
	return explota;
}
