#include "V.h"
#include"Bombas.h"
#include "Item.h"
#include "Jugador.h"
V::V(){

}
V::V(int x,int y,char l):Bombas(x,y,l){

}
void V::Explota(Item***& matriz){
	int x=getX(),y=getY();
	delete matriz[x][y];
	matriz[x][y]=NULL;
	matriz[x][y]=new Item(x,y,' ');
	for(int i=0;i<13;i++){
		if(x+i<11&&y+i<13){
			if(dynamic_cast<Jugador*>(matriz[x+i][y+i])!=NULL){
				dynamic_cast<Jugador*>(matriz[x+i][y+i])->setVidas();
			}
		}
		if(x-i>0&&y-i>0){	
			if(dynamic_cast<Jugador*>(matriz[x-i][y-i])!=NULL){
				dynamic_cast<Jugador*>(matriz[x-i][y-i])->setVidas();
			}
		}
		if(y+i<13&&x-i>0){
			if(dynamic_cast<Jugador*>(matriz[x-i][y+i])!=NULL){
				dynamic_cast<Jugador*>(matriz[x-i][y+i])->setVidas();
			}
		}
		if(y-i>0&&x+i<11){
			if(dynamic_cast<Jugador*>(matriz[x+i][y-i])!=NULL){
				dynamic_cast<Jugador*>(matriz[x+i][y-i])->setVidas();		
			}
		}
		if(x+i<11&&y+i<13){
			if(dynamic_cast<Bombas*>(matriz[x+i][y+i])!=NULL){
				dynamic_cast<Bombas*>(matriz[x+i][y+i])->Explota(matriz);
			}
		}
		if(x-i>0&&y-i>0){
			if(dynamic_cast<Bombas*>(matriz[x-i][y-i])!=NULL){
				dynamic_cast<Bombas*>(matriz[x-i][y-i])->Explota(matriz);
			}
		}
		if(y+i<13&&x-i>0){
			if(dynamic_cast<Bombas*>(matriz[x-i][y+i])!=NULL){
				dynamic_cast<Bombas*>(matriz[x-i][y+i])->Explota(matriz);
			}
		}
		if(y-i>0&&x+i<11){
			if(dynamic_cast<Bombas*>(matriz[x+i][y-i])!=NULL){
				dynamic_cast<Bombas*>(matriz[x+i][y-i])->Explota(matriz);		
			}
		}
	}
}
