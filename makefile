temp:	main.o Jugador.o Escenario.o Bombas.o Item.o Tren.o Invisible.o Espina.o V.o Normal.o
	g++ main.o Jugador.o Escenario.o Bombas.o Item.o Tren.o Invisible.o Espina.o V.o Normal.o -o temp -lncurses
main.o:	main.cpp Jugador.h Escenario.h Bombas.h Item.h Tren.h Invisible.h Espina.h V.h Normal.h
	g++ -c main.cpp
Jugador.o:	Jugador.h Item.h Jugador.cpp Escenario.h Bombas.h
	g++ -c Jugador.cpp
Escenario.o:	Escenario.h Escenario.cpp Item.h Bombas.h
	g++ -c Escenario.cpp
Bombas.o:	Bombas.h Item.h Bombas.cpp 
	g++ -c Bombas.cpp
Item.o:	Item.h Item.cpp
	g++ -c Item.cpp
Tren.o:	Tren.h Tren.cpp Escenario.h Item.h Bombas.h Jugador.h
	g++ -c Tren.cpp
Invisible.o:	Invisible.cpp Invisible.h Escenario.h Espina.h V.h Normal.h
	g++ -c Invisible.cpp
Espina.o:	Espina.h Espina.cpp Bombas.h Item.h Jugador.h 
	g++ -c Espina.cpp
V.o:	V.cpp V.h Bombas.h Item.h Jugador.h 
	g++ -c V.cpp
Normal.o:	Normal.cpp Normal.h Bombas.h Item.h Jugador.h 
	g++ -c Normal.cpp	
