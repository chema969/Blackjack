#ifndef BARAJA_H
#define BARAJA_H
#include <list>
#include "carta.h"
class Baraja{
 private:
  list <Carta> cartas_;
 public:
  void setBaraja(string archivo,string reverso="");
  list <Carta> getBaraja(){return cartas_;}
  void mezcla();
};
#endif
