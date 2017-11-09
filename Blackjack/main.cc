#include <iostream>
#include "baraja.h"
#include "carta.h"
#include <list>
void imprime(list<Carta> c);
int main(){
  Baraja j;
  list <Carta> c;
  list <Carta>::iterator it;
  string i="baraja_inglesa.txt";
  j.setBaraja(i);
  c=j.getBaraja();
  //imprime(c);
  j.mezcla();
  c=j.getBaraja();
  imprime(c);
  }


void imprime(list<Carta> c){
  list <Carta>::iterator it;
   for(it=c.begin();it!=c.end();++it){
     cout<<it->getValor()<<","<<it->getFigura()<<","<<it->getColor()<<","<<it->getPalo()<<" ,\n";
    }
 }
