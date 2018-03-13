#include "Invisible.h"
#include"Escenario.h"
#include"V.h"
#include "Normal.h"
#include"Espina.h"
#include <iostream>

Invisible::Invisible(){

}
Invisible::Invisible(string nombre):Escenario(nombre){
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
}
void Invisible::Especial(){
	for(int i=0;i<getEnemigas().size();i++){
		if(i%2==0){
			getEnemigas()[i]->setLetra(' ');
		}else{
			if(dynamic_cast<Normal*>(getEnemigas()[i])!=NULL)
				getEnemigas()[i]->setLetra('N');
			if(dynamic_cast<Espina*>(getEnemigas()[i])!=NULL)
				getEnemigas()[i]->setLetra('E');
			if(dynamic_cast<V*>(getEnemigas()[i])!=NULL)
				getEnemigas()[i]->setLetra('V');	
		}
	}
}
