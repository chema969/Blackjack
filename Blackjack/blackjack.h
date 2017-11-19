#ifndef BLACKJACK_H
#define BLACKJACK_H
#include <list>
#include "jugador.h"
#include "crupier.h"
#include "baraja.h"
   void partida(Crupier &c,list <Jugador> &jugador_);
   int mostrarCartas(list <Carta> carta,string categoria);
   int menu();
   bool sobrepasa(int v);
   void hora_de_las_apuestas(Jugador &jugador_,Baraja &baraja_,Crupier &c);
   void inicio(Jugador &jugador_,Baraja &baraja_);
   void inicio(Crupier &c,Baraja &baraja_);
   void hora_del_crupier(Crupier &c,Baraja &baraja_);
   void revision(Crupier &c,Jugador &jugador_);
   bool blackjack(Jugador it);
#endif
