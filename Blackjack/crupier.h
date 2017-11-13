#ifndef CRUPIER_H
#define CRUPIER_H
#include <string>
#include "persona.h"
class Crupier:public Jugador{
private:
  string codigo_;
  int dinero_;
public:
  Crupier(string DNI,string codigo,int dinero=100000,string nombre="", string apellidos="", string direccion="", string localidad="", string provincia="",string pais=""):Jugador(DNI,dinero,nombre,apellidos,direccion,localidad,provincia,pais){codigo_=codigo;}
  inline void setCodigo( string codigo){codigo_=codigo;}
  inline  string getCodigo(){return codigo_;}
};
#endif
