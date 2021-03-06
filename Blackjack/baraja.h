#ifndef BARAJA_H
#define BARAJA_H
#include <list>
#include "carta.h"
class Baraja{
 private:
  list <Carta> cartas_;
 public:
  void setBaraja(string archivo);
  list <Carta> getBaraja(){return cartas_;}
  void mezcla();
  Carta devuelvePrimerElemento();
  inline void dropMiembro(){if(!cartas_.empty())cartas_.pop_front();}
  inline void devuelve_carta(Carta c){cartas_.push_back(c);}
  void devuelve_carta(list <Carta> c);
};
#endif
