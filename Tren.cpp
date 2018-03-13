#include"Tren.h"
#include"Escenario.h"
#include "Item.h"
#include"Jugador.h"
#include"Bombas.h"
#include <iostream>
Tren::Tren(){
}
Tren::Tren(string l):Escenario(l){
	crearMatrix();
	for(int i=0;i<11;i++){
		for(int j=0;j<13;j++){
			if(i%2!=0&&j%2!=0){
				getItem(i,j)->setLetra('#');
			}else{
				getItem(i,j)->setLetra(' ');
			}
		}
	}

	getTablero()[2][5]->setLetra('T');
	getTablero()[2][6]->setLetra('t');
	getTablero()[2][7]->setLetra('t');
	getTablero()[2][8]->setLetra('t');
	getTablero()[2][9]->setLetra('t');
	getTablero()[3][9]->setLetra('t');
	getTablero()[4][9]->setLetra('t');
	getTablero()[5][9]->setLetra('t');
	getTablero()[6][9]->setLetra('t');
	getTablero()[7][9]->setLetra('t');
	getTablero()[8][9]->setLetra('t');
	getTablero()[8][8]->setLetra('t');
	getTablero()[8][7]->setLetra('t');
	getTablero()[8][6]->setLetra('t');
	getTablero()[8][5]->setLetra('t');
	
}
void Tren::Especial(){
	bool letraT,entrar=false;
	if(getTablero()[2][5]->getFigura()=='T'){
		letraT=false;
	}else{
		letraT=true;
	}
	for(int i=0;i<5;i++){
		if(dynamic_cast<Jugador*>(getTablero()[2][5+i])==NULL){
			getTablero()[2][5+i]->setLetra('t');
			getTablero()[3+i][9]->setLetra('t');
			getTablero()[8][9-i]->setLetra('t');
			entrar=true;
		}
	}
	if(entrar){
		if(letraT){
			getTablero()[2][5]->setLetra('T');
		}else{
			getTablero()[8][5]->setLetra('T');
		}
	}else{
		if(letraT){
			getTablero()[8][5]->setLetra('T');
		}else{
			getTablero()[2][5]->setLetra('T');
		}
	}

	if(dynamic_cast<Jugador*>(getTablero()[2][4])!=NULL&&getTablero()[2][5]->getFigura()=='T'){
		if(getTablero()[8][4]->getFigura()==' '){
			delete getTablero()[8][4];
			getTablero()[8][4]=NULL;
			getTablero()[2][4]->setXY(8,4);
			setItem(getTablero()[2][4]);
			setItem(new Item(2,4,' '));
			for(int i=0;i<5;i++){
				
			}
		}	
	}
	if(dynamic_cast<Jugador*>(getTablero()[8][4])!=NULL&&getTablero()[8][5]->getFigura()=='T'){
		if(getTablero()[2][4]->getFigura()==' '){
			delete getTablero()[2][4];
			getTablero()[2][4]=NULL;
			getTablero()[8][4]->setXY(2,4);
			setItem(getTablero()[8][4]);
			setItem(new Item(8,4,' '));
			for(int i=0;i<5;i++){
				if(dynamic_cast<Jugador*>(getTablero()[2][5+i])!=NULL){
					dynamic_cast<Jugador*>(getTablero()[2][5+i])->setVidas();
				}
				if(dynamic_cast<Jugador*>(getTablero()[3+i][9])!=NULL){
					dynamic_cast<Jugador*>(getTablero()[3+i][9])->setVidas();
				}
				if(dynamic_cast<Jugador*>(getTablero()[8][9-i])!=NULL){
					dynamic_cast<Jugador*>(getTablero()[8][9-i])->setVidas();
				}
				if(dynamic_cast<Bombas*>(getTablero()[2][5+i])!=NULL){
					dynamic_cast<Bombas*>(getTablero()[2][5+i])->Explota(getTablero());
				}
				if(dynamic_cast<Bombas*>(getTablero()[3+i][9])!=NULL){
					dynamic_cast<Bombas*>(getTablero()[3+i][9])->Explota(getTablero());
				}
				if(dynamic_cast<Bombas*>(getTablero()[8][9-i])!=NULL){
					dynamic_cast<Bombas*>(getTablero()[8][9-i])->Explota(getTablero());
				}
				
			}
		}
	}
}
