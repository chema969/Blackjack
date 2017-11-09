#include <list>
#include "carta.h"
#include "baraja.h"
#include <string>
#include <fstream>
using namespace std;
void Baraja::setBaraja(string archivo){
  string aux1,aux2,aux3;
  cartas_.clear();
  ifstream fichero;
  fichero.open(archivo);
  while(getline(fichero,aux1,',')){
    getline(fichero,aux2,',');
    getline(fichero,aux3,',');
    Carta c(stoi(aux1),aux2,aux3);
    getline(fichero,aux1,'\n');
    c.setColor(aux1);
    cartas_.push_back(c);
    }
}

void Baraja::mezcla(){
int i,j=cartas_.size(),k=0,x;
srand(time(NULL));
list <Carta>::iterator it;
it=cartas_.begin();
  for(i=0;i<rand()%j;i++){  
    cartas_.push_back(*it);
    ++it;
   cartas_.pop_front();
   }
  for(i=0;i<50;i++){
    x=rand()%j;
    it=cartas_.begin();
      for(k=0;k<x;k++){++it;}
      cartas_.erase(it);
      if(i%2){cartas_.push_back(*it);}
      else{cartas_.push_front(*it);} 
      }
 cartas_.reverse();
 }
 
