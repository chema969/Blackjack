#include <iostream>
#include "crupier.h"
#include "blackjack.h"
#include "jugador.h"
#include <list>
#include <string>
using namespace std;
int main(){
  int i,k;
  list <Jugador> j;
  string aux1,aux2;
  bool l=true; 
  Crupier c("33","33");
  while(l==true){
    cout<<"Nombre del jugador "<<endl;
    cin>>aux1;
    cout<<"DNI del jugador "<<endl;
    cin>>aux2;
    cout<<"Dinero del jugador "<<endl; 
    cin>>k;
    Jugador aux(aux2,k,aux1);
    j.push_back(aux);
    cout<<"¿Quiere añadir nuevo jugador? Ponga si o no "<<endl;
    cin>>aux1;
    if(aux1=="no") l=false;
     }

   
   while(l==false){
    list<Jugador>::iterator it=j.begin();
    if(j.empty())l=true;
    else{
    while(it!=j.end()){
     if(it->getDinero()==0){
      cout<<it->getNombre()<<",estas arruinado, chaval,fuera de mi casino"<<endl;
       list<Jugador>::iterator arruinado=it;
       it++;
      j.erase(arruinado);
       }
     else{
      cout<<"Introduce apuesta del jugador "<<it->getNombre()<<": ";
      cin>>i;
      if(i<=it->getDinero()){
      it->setApuesta(i);
      it++;}
      else cout<<"No apuestes mas que el dinero que tienes"<<endl;
      }
     }
    cout<<"\n";
   if(!j.empty()){ partida(c,j);
    cout<<"\n¿Quieres jugar otra partida? Ponga si o no"<<endl;
    cin>>aux1;
    if(aux1=="no")l=true; 
     }
    }
   }

  }

