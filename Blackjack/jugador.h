#ifndef JUGADOR_H
#define JUGADOR_H
#include <string>
#include "persona.h"
#include <list>
#include "baraja.h"
class Jugador:public Persona{
   private:
  int dinero_,apuesta_,valor_;
  list <Carta> c_;
   public:
  Jugador(string DNI,int dinero,string nombre="", string apellidos="", string direccion="", string localidad="", string provincia="",string pais="");
  inline void setDinero(int dinero){dinero_=dinero;}
  inline int getDinero()const{return dinero_;}
  inline void setApuesta(int apuesta){apuesta_=apuesta;}
  inline int getApuesta()const{return apuesta_;}
  inline list <Carta> getCartasJugador(){return c_;}
  inline void setCartasJugador(Carta c){ c_.push_back(c);}
  inline void dropCartasJugador(){c_.clear();}
  inline int tamanyoCarta(){return c_.size();}
  inline int getValorCartas(){return valor_;}
  inline int setValorCartas(int valor){valor_=valor;}
  int setValorCartas();
};


#endif
