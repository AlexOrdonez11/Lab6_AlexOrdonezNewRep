#include <string>
#include"Escenario.h"
#include "Item.h"
#include"Bombas.h"
#include <iostream>

Escenario::Escenario(){

}
Escenario::Escenario(string nombre){
	this->nombre=nombre;
}
string Escenario::getNombre(){
	return nombre;
}
vector<Bombas*> Escenario::getBombas(){
	return bombas;
}
Item***& Escenario::getTablero(){
	return tablero;
}
void Escenario::setBombas(Bombas* bomb){
	bombas.push_back(bomb);
}
void Escenario::EliminarBomba(int i){
	bombas.erase(bombas.begin()+i);
}
void Escenario::setItem(Item* item){
	tablero[item->getX()][item->getY()]=item;
}
Item* Escenario::getItem(int x, int y){
	return tablero[x][y];
}
void Escenario::crearMatrix(){
	tablero=new Item**[11];
	for(int i=0;i<11;i++){
		tablero[i]=new Item*[13];
		for(int j=0;j<13;j++)
			tablero[i][j]=new Item(i,j,' ');
	}

}
Escenario::~Escenario(){
	for(int i=0;i<11;i++)
		delete tablero[i];
	delete[] tablero;
}
void Escenario::setEnemigas(Bombas* bomb){
	enemigas.push_back(bomb);
}
vector<Bombas*> Escenario::getEnemigas(){
	return enemigas;
}
void Escenario::EliminarEnemigas(int i){
	enemigas.erase(enemigas.begin());
	
}
