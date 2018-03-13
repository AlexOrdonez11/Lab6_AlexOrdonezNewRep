#include<string>
#include<vector>
#ifndef ESCENARIO_H
#define ESCENARIO_H
#include"Item.h"
#include"Bombas.h"
using namespace std;

class Escenario{
	private:
		Item*** tablero;
		vector<Bombas*> bombas;
		string nombre;
		vector<Bombas*> enemigas;
	public:
		Item***& getTablero();
		vector<Bombas*> getBombas();
		void EliminarBomba(int);
		void setBombas(Bombas*);
		Escenario();
		void setEnemigas(Bombas*);
		vector<Bombas*> getEnemigas();
		void EliminarEnemigas(int);
		virtual Item* getItem(int x, int y);
		void setItem(Item*);
		Escenario(string);
		string getNombre();
		void crearMatrix();
		virtual void Especial()=0;
		~Escenario();
};
#endif
