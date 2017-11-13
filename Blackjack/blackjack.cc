#include <list>
#include <iostream>
#include "carta.h"
#include "jugador.h"
#include "crupier.h"
#include "baraja.h"
#include "blackjack.h"
using namespace std;

void partida(Crupier c,Jugador jugador_,int i){
  Baraja baraja_;
  int valorjugador,valorcrupier;
  string s="baraja_inglesa.txt";
  baraja_.setBaraja(s);
  baraja_.mezcla();
  jugador_.setCartasJugador(baraja_.devuelvePrimerElemento());
  baraja_.dropMiembro();
  jugador_.setCartasJugador(baraja_.devuelvePrimerElemento());
  baraja_.dropMiembro();
  c.setCartasJugador(baraja_.devuelvePrimerElemento());
  baraja_.dropMiembro();
  mostrarCartas(jugador_.getCartasJugador(),"jugador",valorjugador);
  mostrarCartas(c.getCartasJugador(),"crupier",valorcrupier);
  if(valorjugador==21){
    cout<<"BLACKJACK: se triplican tus ganancias\n";
    jugador_.setDinero(jugador_.getDinero()+i*2);
   }
  else{
  int j=1; 
 //Esta sera la parte de la partida donde el jugador puede pedir cartas o doblar la apuesta 
  while (j!=3){
   j=menu(valorjugador);
   switch(j){
     case 1:
      jugador_.setCartasJugador(baraja_.devuelvePrimerElemento());
      baraja_.dropMiembro();
      mostrarCartas(jugador_.getCartasJugador(),"jugador",valorjugador);
        if(sobrepasa(valorjugador)){
            j=3;
            cout<<"Te pasaste, perdiste "<<i<<endl;
            jugador_.setDinero(jugador_.getDinero()-i);
            c.setDinero(c.getDinero()+i);
        }
      break;
     case 2: 
      i=i*2;
      cout<<"Apuesta="<<i<<endl;
      break;
     default:
      cout<<"Te plantaste con un valor "<<valorjugador<<" y una apuesta "<<i<<"\n";
      break;
     }
    } 


if(!sobrepasa(valorjugador)){
   cout<<"\n¡Hora del crupier!\n";
    while(valorcrupier<=16){
     c.setCartasJugador(baraja_.devuelvePrimerElemento());
     baraja_.dropMiembro();
     mostrarCartas(c.getCartasJugador(),"crupier",valorcrupier);
     }

    if(valorcrupier>21){
      cout<<"El crupier se pasó\n";
      cout<<"El jugador gana\n";
      jugador_.setDinero(jugador_.getDinero()+i);
      c.setDinero(c.getDinero()-i);
      }
  else{
    cout<<"El crupier se planto con un valor "<<valorcrupier<<endl;
    if(valorcrupier>valorjugador){
      cout<<"El crupier gana\n";
      jugador_.setDinero(jugador_.getDinero()-i);
      c.setDinero(c.getDinero()+i);
     }
     else{
       if(valorcrupier<valorjugador){
       cout<<"El jugador gana\n";
        jugador_.setDinero(jugador_.getDinero()+i);
        c.setDinero(c.getDinero()-i);
        }
       else{
         if(c.tamanyoCarta()==jugador_.tamanyoCarta()) cout<<"EMPATE\n";
         else{
           if(c.tamanyoCarta()<jugador_.tamanyoCarta()){
             cout<<"Tienes mas cartas, el crupier gana\n";
             jugador_.setDinero(jugador_.getDinero()-i);
             c.setDinero(c.getDinero()+i);
            }
           else{ 
             cout<<"Tienes menos cartas,el jugador gana\n";
             jugador_.setDinero(jugador_.getDinero()+i);
             c.setDinero(c.getDinero()-i); 
            }
       }
     }
}
}
}
}
baraja_.devuelve_carta(c.getCartasJugador());
baraja_.devuelve_carta(jugador_.getCartasJugador());
}


void mostrarCartas(list <Carta> carta,string categoria,int &v){
  cout<<"Cartas de "<<categoria<<endl;
  v=0;
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
cout<<"El valor de las cartas del "<<categoria<<" es "<<v<<"\n";
cout<<"\n";
}

int menu(int v){
  int i;
  cout<<"---------------------\n";
  cout<<"| 1.Pedir carta      |\n";
  cout<<"| 2.Doblar apuesta   |\n";
  cout<<"| 3.Plantarse        |\n";
  cout<<"---------------------\n\n";
  if(v==21){return 3;}
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
