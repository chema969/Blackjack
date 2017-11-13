#ifndef BLACKJACK_H
#define BLACKJACK_H
#include <list>
#include "jugador.h"
#include "crupier.h"
#include "baraja.h"
   void partida(Crupier c,Jugador j,int i);
   void mostrarCartas(list <Carta> carta,string categoria,int &v);
   int menu(int v);
   bool sobrepasa(int v);
#endif
