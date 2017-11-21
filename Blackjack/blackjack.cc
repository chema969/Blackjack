#include <list>
#include <iostream>
#include "carta.h"
#include "jugador.h"
#include "crupier.h"
#include "baraja.h"
#include "blackjack.h"
using namespace std;

void partida(Crupier &c,list <Jugador> &jugador){
  Baraja baraja;
  list <Jugador>::iterator it;
  string s="baraja_inglesa.txt";
   baraja.setBaraja(s);
   baraja.mezcla();
  for(it=jugador.begin();it!=jugador.end();it++){
   cout<<"Cartas del jugador "<<it->getNombre()<<endl;
   inicio(*it,baraja);
   it->setValorCartas(mostrarCartas(it->getCartasJugador(),it->getNombre()));
   }
    inicio(c,baraja);

   c.setValorCartas(mostrarCartas(c.getCartasJugador(),"crupier"));

for(it=jugador.begin();it!=jugador.end();it++){  
   if (blackjack(*it)){
        cout<<"BLACKJACK de "<<it->getNombre()<<": se triplican tus ganancias\n";
        it->setDinero(it->getDinero()+it->getApuesta()*2);
     }
   else hora_de_las_apuestas(*it,baraja,c);
  }
hora_del_crupier(c,baraja);
 
for(it=jugador.begin();it!=jugador.end();it++){ 
  if(!sobrepasa(it->getValorCartas())&&(!blackjack(*it))){
    cout<<"\nHora de "<<it->getNombre()<<endl;    
    revision(c,*it);
   }
  it->dropCartasJugador();
}
c.dropCartasJugador();
}

int mostrarCartas(list <Carta> carta,string categoria){
  cout<<"Cartas de "<<categoria<<endl;
  int v=0;
  list <Carta>::iterator it;
   for(it=carta.begin();it!=carta.end();++it){
     cout<<it->getPalo()<<","<<it->getFigura()<<","<<it->getColor()<<endl;
     if(it->getPalo()=="as"){
      if(it->getValor()==0){
       if(v<11) it->setValor(11);
       else it->setValor(1);
      }
     }
    v=v+it->getValor();
}
cout<<"El valor de las cartas de "<<categoria<<" es "<<v<<"\n";
cout<<"\n";
return v;
}

int menu(){
  int i;
  cout<<"---------------------------------\n";
  cout<<"| 1.Pedir carta                 |\n";
  cout<<"| 2.Doblar apuesta              |\n";
  cout<<"| 3.Plantarse y levantar cartas |\n";
  cout<<"---------------------------------\n\n";
  cin>>i;
  return i;
  }


bool sobrepasa(int v){
  if(v>21){
   return true;
    } 
   else{
    return false;
}
}

void inicio(Jugador &jugador,Baraja &baraja){
jugador.setCartasJugador(baraja.devuelvePrimerElemento());
  baraja.dropMiembro();
  jugador.setCartasJugador(baraja.devuelvePrimerElemento());
  baraja.dropMiembro();
}

void inicio(Crupier &c,Baraja &baraja){
 c.setCartasJugador(baraja.devuelvePrimerElemento());
   baraja.dropMiembro();
}


void hora_de_las_apuestas(Jugador &jugador,Baraja &baraja,Crupier &c){
  
  int j=1; 
 //Esta sera la parte de la partida donde el jugador puede pedir cartas o doblar la apuesta 
  while (j!=3){
   cout<<"Jugador "<<jugador.getNombre()<<endl;
   j=menu();
   switch(j){
     case 1:
      jugador.setCartasJugador(baraja.devuelvePrimerElemento());
      baraja.dropMiembro();
      cout<<"Tienes "<<jugador.tamanyoCarta()<<" cartas"<<endl;
      break;
     case 2: 
      if(!jugador.setApuesta(jugador.getApuesta()*2))cout<<"no puedes doblar la apuesta!"<<endl;
     else{
     jugador.setApuesta(jugador.getApuesta()*2);
      cout<<"Apuesta="<<jugador.getApuesta()<<endl;}
      break;
     case 3:
      jugador.setValorCartas(mostrarCartas(jugador.getCartasJugador(),jugador.getNombre()));
        if(sobrepasa(jugador.getValorCartas())){
            j=3;
            cout<<"Te pasaste, perdiste "<<jugador.getApuesta()<<endl;
            jugador.setDinero(jugador.getDinero()-jugador.getApuesta());
            c.setDinero(c.getDinero()+jugador.getApuesta());
        }
      cout<<"Te plantaste con un valor "<<jugador.getValorCartas()<<" y una apuesta "<<jugador.getApuesta()<<"\n";
      break;
      default: 
        cout<<"Valor fuera del menu"<<endl;
    } 

}
}

void revision(Crupier &c,Jugador &jugador){
    if(c.getValorCartas()>21){
      cout<<"El crupier se pasó\n";
      cout<<"El jugador "<<jugador.getNombre()<< " gana\n";
      jugador.setDinero(jugador.getDinero()+jugador.getApuesta());
      c.setDinero(c.getDinero()-jugador.getApuesta());
      }
  else{
    cout<<"El crupier se planto con un valor "<<c.getValorCartas()<<endl;
    if(c.getValorCartas()>jugador.getValorCartas()){
      cout<<"El crupier gana al jugador "<<jugador.getNombre()<< "\n";
      jugador.setDinero(jugador.getDinero()-jugador.getApuesta());
      c.setDinero(c.getDinero()+jugador.getApuesta());
     }
     else{
       if(c.getValorCartas()<jugador.getValorCartas()){
        cout<<"El jugador "<<jugador.getNombre()<< " gana\n";
        jugador.setDinero(jugador.getDinero()+jugador.getApuesta());
        c.setDinero(c.getDinero()-jugador.getApuesta());
        }
       else{
         if(c.tamanyoCarta()==jugador.tamanyoCarta()) cout<<"EMPATE\n";
         else{
           if(c.tamanyoCarta()<jugador.tamanyoCarta()){
             cout<<"El jugador "<<jugador.getNombre()<<" tiene mas cartas, el crupier gana\n";
             jugador.setDinero(jugador.getDinero()-jugador.getApuesta());
             c.setDinero(c.getDinero()+jugador.getApuesta());
            }
           else{ 
            cout<<"El jugador "<<jugador.getNombre()<<" tiene menos cartas,el jugador gana\n";
             jugador.setDinero(jugador.getDinero()+jugador.getApuesta());
             c.setDinero(c.getDinero()-jugador.getApuesta()); 
            }
       }
     }
}
}
}

void hora_del_crupier(Crupier &c,Baraja &baraja){
cout<<"\n¡Hora del crupier!\n";
    while(c.getValorCartas()<=16){
     c.setCartasJugador(baraja.devuelvePrimerElemento());
     baraja.dropMiembro();
     c.setValorCartas(mostrarCartas(c.getCartasJugador(),"crupier"));
     }
}

bool blackjack(Jugador it){
if((it.getValorCartas()==21)&&(it.tamanyoCarta()==2))
    return true;
return false;
}
