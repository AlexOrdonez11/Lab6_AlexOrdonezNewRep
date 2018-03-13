#include "Normal.h"
#include"Bombas.h"
#include"Item.h"
#include"Jugador.h"
Normal::Normal(){

}
Normal::Normal(int x,int y,char letra):Bombas(x,y,letra){
	setAlcance();
}
void Normal::setAlcance(){
	srand(time(NULL));
	alcance=rand()% 4+1;
}
int Normal::getAlcance(){
	return alcance;
}
void Normal::Explota(Item***& matriz){
	int x=getX(),y=getY();
	delete matriz[x][y];
	matriz[x][y]=NULL;
	matriz[x][y]=new Item(x,y,' ');
	for(int i=0;i<this->alcance;i++){
		if(x+i<11&&x+1<11){
			if(dynamic_cast<Jugador*>(matriz[x+i][y])!=NULL&&matriz[x+1][y]->getFigura()!='#'){
				dynamic_cast<Jugador*>(matriz[x+i][y])->setVidas();
			}
		}
		if(x-i>0&&x-1>0){
			if(dynamic_cast<Jugador*>(matriz[x-i][y])!=NULL&&matriz[x-1][y]->getFigura()!='#'){
				dynamic_cast<Jugador*>(matriz[x-i][y])->setVidas();
			}
		}
		if(y+i<13&&y+1<13){
			if(dynamic_cast<Jugador*>(matriz[x][y+i])!=NULL&&matriz[x][y+1]->getFigura()!='#'){
				dynamic_cast<Jugador*>(matriz[x][y+i])->setVidas();
			}
		}
		if(y-i>0&&y-1>0){
			if(dynamic_cast<Jugador*>(matriz[x][y-i])!=NULL&&matriz[x][y-1]->getFigura()!='#'){
				dynamic_cast<Jugador*>(matriz[x][y-i])->setVidas();		
			}
		}
		if(x+i<11&&x+1<11){
			if(dynamic_cast<Bombas*>(matriz[x+i][y])!=NULL&&matriz[x+1][y]->getFigura()!='#'){
				dynamic_cast<Bombas*>(matriz[x+i][y])->Explota(matriz);
			}
		}
		if(x-i>0&&x-1>0){
			if(dynamic_cast<Bombas*>(matriz[x-i][y])!=NULL&&matriz[x-1][y]->getFigura()!='#'){
				dynamic_cast<Bombas*>(matriz[x-i][y])->Explota(matriz);
			}
		}
		if(y+i<11&&y+1<13){
			if(dynamic_cast<Bombas*>(matriz[x][y+i])!=NULL&&matriz[x][y+1]->getFigura()!='#'){
				dynamic_cast<Bombas*>(matriz[x][y+i])->Explota(matriz);
			}
		}
		if(y-i>0&&y-1>0){
			if(dynamic_cast<Bombas*>(matriz[x][y-i])!=NULL&&matriz[x][y-1]->getFigura()!='#'){
				dynamic_cast<Bombas*>(matriz[x][y-i])->Explota(matriz);		
			}
		}	

	}
}
