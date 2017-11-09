#ifndef JUGADOR_H
#define JUGADOR_H
#include <string>
#include "persona.h"
#include <list>
class Jugador:public Persona{
   private:
  int dinero_;
  string codigo_;
   public:
  Jugador(string DNI,string codigo,int dinero,string nombre="", string apellidos="", string direccion="", string localidad="", string provincia="",string pais="");
  inline void setCodigo( string codigo){codigo_=codigo;}
  inline  string getCodigo(){return codigo_;}
  inline void setDinero(int dinero){dinero_=dinero;}
  inline int getDinero(){return dinero_;}
};


#endif
