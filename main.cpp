#include <iostream>
#include "Escenario.h"
#include "Jugador.h"
#include <string>
#include <ncurses.h>
#include "Item.h"
#include "Bombas.h"
#include "Tren.h"
#include "Espina.h"
#include "V.h"
#include "Normal.h"
#include "Invisible.h"
void explotarBombas(Escenario*&);
void bombas(Escenario*&);
void ImprimirMatriz(Escenario*);
void Solo(Escenario*&,Bombas*,Jugador*&);
void movimiento(Escenario*&,Jugador*&,int);
void BombasAleatorias(Escenario*&); 
void BombaBotExplota(Escenario*&);
int main(){
	string nombre,tab;
	int ttablero;
	cout<<"Ingrese su nombre:"<<endl;
	cin>>nombre;
	cout<<"Ingrese el nombre del tablero"<<endl;
	cin>>tab;
	Escenario* scene;
	cout<<"Ingrese el tipo de tablero[1.invisible/2.Tren]"<<endl;
	cin>>ttablero;
	switch(ttablero){
		case 1:
			scene=new Invisible(tab);
			break;
		case 2:
			scene=new Tren(tab);
			break;
	}
	Jugador* player=new Jugador(0,0,'P',nombre,"Princ");
	Jugador* bot1=new Jugador(0,12,'Q',"op","bot");
	Jugador* bot2=new Jugador(10,0,'F',"pop","bot");
	Jugador* bot3=new Jugador(10,12,'Z',"pap","bot");
	Jugador* bot4=new Jugador(5,6,'X',"pup","bot");
	scene->setItem(player);
	scene->setItem(bot1);
	scene->setItem(bot2);
	scene->setItem(bot3);
	scene->setItem(bot4);
	int bom;
	cout<<"Ingrese el tipo de bomba que va a utilizar"<<endl;
	cout<<"1-Normal"<<endl;
	cout<<"2-Espina"<<endl;
	cout<<"3-V"<<endl;
	cin>>bom;
	Bombas* bo1=new Normal(0,0,'N');
	Bombas* bo2=new Espina(0,0,'E');
	Bombas* bo3=new V(0,0,'V');
	Bombas* bo4=new V(0,0,'V');
	initscr();
	cbreak();
	noecho();
	ImprimirMatriz(scene);
	int cont=0;
	while(player->isVivo()){
		move(5,50);
		printw("%d",player->getVidas());
		movimiento(scene,player,bom);
		Solo(scene,bo1,bot1);
		Solo(scene,bo2,bot2);
		Solo(scene,bo3,bot3);
		Solo(scene,bo4,bot4);
		if(scene->getEnemigas().size()<1){
			BombasAleatorias(scene);
		}
		BombaBotExplota(scene);
		bombas(scene);
		explotarBombas(scene);
	//	scene->Especial();
		ImprimirMatriz(scene);
		cont++;
		refresh();
	}
	refresh();
	getch();
	endwin();
	for(int i=0;i<11;i++){
		for(int j=0;j<13;j++){
			delete scene->getTablero()[i][j];
		}
	}
	delete scene;
}
void explotarBombas(Escenario*& scene){
	for(int i=0;i<scene->getBombas().size();i++){
		scene->getBombas()[i]->setExplota();
		if(scene->getBombas()[i]->getExplota()==0){
			scene->getBombas()[i]->Explota(scene->getTablero());
			scene->EliminarBomba(i);
		}
	}
	
}
void bombas(Escenario*& scene){
	for(int i=0;i<11;i++){
		for(int j=0;j<13;j++){
			for(int k=0;k<scene->getBombas().size();k++){
				if(i==scene->getBombas()[k]->getX()&&j==scene->getBombas()[k]->getY()){
					if(dynamic_cast<Jugador*>(scene->getTablero()[i][j])==NULL&&dynamic_cast<Bombas*>(scene->getTablero()[i][j])==NULL){
						delete scene->getTablero()[i][j];
						scene->getTablero()[i][j]=NULL;
						scene->setItem(scene->getBombas()[k]);
					}
				}
			}
			for(int k=0;k<scene->getEnemigas().size();k++){
				if(i==scene->getEnemigas()[k]->getX()&&j==scene->getEnemigas()[k]->getY()){
					if(dynamic_cast<Jugador*>(scene->getTablero()[i][j])==NULL&&dynamic_cast<Bombas*>(scene->getTablero()[i][j])==NULL){
						delete scene->getTablero()[i][j];
						scene->getTablero()[i][j]=NULL;
						scene->setItem(scene->getEnemigas()[k]);
					}
				}
			}
		}
	}
}
void movimiento(Escenario*& scene,Jugador*& player,int bomb){
	char tecla=getch();
	int x=player->getX(),y=player->getY();
	if(tecla=='a'&&player->getY()>0){
		if(scene->getTablero()[x][y-1]->getFigura()==' '){
			delete scene->getTablero()[player->getX()][player->getY()-1];
			scene->getTablero()[player->getX()][player->getY()-1]=NULL;
			player->setXY(player->getX(),player->getY()-1);
			scene->setItem(new Item(x,y,' '));
			scene->setItem(player);		
		}
	}
	if(tecla=='d'&&player->getY()<12){
		if(scene->getTablero()[x][y+1]->getFigura()==' '){
			delete scene->getTablero()[player->getX()][player->getY()+1];
			scene->getTablero()[player->getX()][player->getY()+1]=NULL;
			player->setXY(player->getX(),player->getY()+1);
			scene->setItem(new Item(x,y,' '));
			scene->setItem(player);		
		}
	}
	if(tecla=='w'&&player->getX()>0){
		if(scene->getTablero()[x-1][y]->getFigura()==' '){
			delete scene->getTablero()[player->getX()-1][player->getY()];
			scene->getTablero()[player->getX()-1][player->getY()]=NULL;
			player->setXY(player->getX()-1,player->getY());
			scene->setItem(new Item(x,y,' '));
			scene->setItem(player);	
		}	
	}
	if(tecla=='s'&&player->getX()<10){
		if(scene->getTablero()[x+1][y]->getFigura()==' '){
			delete scene->getTablero()[player->getX()+1][player->getY()];
			scene->getTablero()[player->getX()+1][player->getY()]=NULL;
			player->setXY(player->getX()+1,player->getY());
			scene->setItem(new Item(x,y,' '));
			scene->setItem(player);		
		}
	}
	if(tecla=='p'&&scene->getBombas().size()<1){
		Bombas* bom;
		switch(bomb){
			case 1:
				bom=new Normal(x,y,'N');
				break;
			case 2:
				bom=new Espina(x,y,'E');
				break;
			case 3:
				bom=new V(x,y,'V');
		}
		scene->setBombas(bom);
	}
	
}
void ImprimirMatriz(Escenario* scene){
	for(int i=0;i<11;i++){
		for(int j=0;j<13;j++){
			move(i,j*2);
			printw("%c",scene->getItem(i,j)->getFigura());
		}
		printw("%s","\n");
	}

}
void BombaBotExplota(Escenario*& scene){
	for(int i=0;i<scene->getEnemigas().size();i++){
		scene->getEnemigas()[i]->setExplota();
		if(scene->getEnemigas()[i]->getExplota()==0){
			scene->getEnemigas()[i]->Explota(scene->getTablero());
			scene->EliminarEnemigas(i);
		}
	}
}
void BombasAleatorias(Escenario*& scene){
	srand(time(NULL));
	int bombx,bomby;
	int bomba=rand() % 3 + 1;
	Bombas* bomb;
	bool hol=true;
	while(hol){
		bomby=rand()%10+0;
		bombx=rand()%12+0;
		if(scene->getTablero()[bomby][bombx]->getFigura()==' '){
			switch(bomba){
				case 1:
					bomb = new V(bomby,bombx,'V');
					break;
				case 2:
					bomb = new Normal(bomby,bombx,'N');
					break;
				case 3:
					bomb = new Espina(bomby,bombx,'E');
					break;
			}
			hol=false;
		}
	}
	scene->setEnemigas(bomb);
}


void Solo(Escenario*& scene,Bombas* bomb,Jugador*& player){
	bool valor=false;
	srand(time(NULL));
	int action=rand()%4+1;
	int cont=0;
	while(!valor&&cont<5){
		int y=player->getY(),x=player->getX();
		switch(action){
			case 1:
				if(y>0){
					if(scene->getTablero()[x][y-1]->getFigura()==' '){
						delete scene->getTablero()[x][y-1];
						scene->getTablero()[x][y-1]=NULL;
						player->setXY(x,y-1);
						scene->setItem(new Item(x,y,' '));
						scene->setItem(player);
						valor=true;		
					}else{
						action=4;
						valor=false;
					}
				}else{
					action=4;
					valor=false;
				}
				break;
			case 2:
				if(y<12){
					if(scene->getTablero()[x][y+1]->getFigura()==' '){
						delete scene->getTablero()[x][y+1];
						scene->getTablero()[x][y+1]=NULL;
						player->setXY(x,y+1);
						scene->setItem(new Item(x,y,' '));
						scene->setItem(player);
						valor=true;		
					}else{
						action=3;
						valor=false;
					}
				}else{
					action=3;
					valor=false;
				}
				break;
			case 3:
				if(x>0){
					if(scene->getTablero()[x-1][y]->getFigura()==' '){
						delete scene->getTablero()[x-1][y];
						scene->getTablero()[x-1][y]=NULL;
						player->setXY(x-1,y);
						scene->setItem(new Item(x,y,' '));
						scene->setItem(player);
						valor=true;	
					}else{
						action=1;
						valor=false;
					}
				}else{
					action=1;
					valor=false;
				}
				break;
			case 4:
				if(x<10){
					if(scene->getTablero()[x+1][y]->getFigura()==' '){
						delete scene->getTablero()[x+1][y];
						scene->getTablero()[x+1][y]=NULL;
						player->setXY(x+1,y);
						scene->setItem(new Item(x,y,' '));
						scene->setItem(player);
						valor=true;		
					}else{
						action=2;
						valor=false;
					}
				}else{
					action=2;
					valor=false;
				}
				break;
		}
		cont++;
	}
}
