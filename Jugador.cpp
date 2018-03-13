#include <string>
#include "Jugador.h"
#include"Item.h"
#include <time.h>
#include<stdlib.h>
#include"Escenario.h"
#include "Bombas.h"
#include<iostream>
Jugador::Jugador(){
	
}
Jugador::Jugador(int x,int y,char l,string nombre,string tipo):Item(x,y,l){
	this->nombre=nombre;
	this->tipo=tipo;
	srand(time(NULL));
	this->vidas=rand() % 3+1 ;
	botbom=false;
}
string Jugador::getNombre(){
	return nombre;
}
string Jugador::getTipo(){
	return tipo;
}
void Jugador::setVidas(){
	vidas=vidas-1;
	if(vidas<0){
		vidas=0;
	}
}
int Jugador::getVidas(){
	return vidas;
}
bool Jugador::isBomb(){
	return botbom;
}
void Jugador::setBomb(bool bom){
	botbom=bom;
}
bool Jugador::isVivo(){
	if(vidas==0){
		return false;
	}else{
		return true;
	}
}
