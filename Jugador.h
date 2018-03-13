#include<string>
#ifndef JUGADOR_H
#define JUGADOR_H
#include"Item.h"
#include "Escenario.h"
#include"Bombas.h"
using namespace std;

class Jugador:public Item{
	private:
		bool botbom;
		string nombre;
		bool vivo;
		int vidas;
		string tipo;
	public:
		Jugador();
		Jugador(int ,int ,char,string, string);
		string getNombre();
		bool isVivo();
		void setVidas();
		int getVidas();
		void setBomb(bool);
		bool isBomb();
		string getTipo();
		void Solo(Escenario*&,Bombas*,Jugador*&);
};
#endif

