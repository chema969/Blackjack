#ifndef JUGADOR_H
#define JUGADOR_H
#include <string>
#include "persona.h"
#include <list>
#include "baraja.h"
class Jugador:public Persona{
   private:
  int dinero_;
  list <Carta> c_;
   public:
  Jugador(string DNI,int dinero,string nombre="", string apellidos="", string direccion="", string localidad="", string provincia="",string pais="");
  inline void setDinero(int dinero){dinero_=dinero;}
  inline int getDinero(){return dinero_;}
  inline list <Carta> getCartasJugador(){return c_;}
  inline void setCartasJugador(Carta c){ c_.push_back(c);}
  inline void dropCartasJugador(){c_.clear();}
  inline int tamanyoCarta(){return c_.size();}
};


#endif
