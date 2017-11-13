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
      cout<<"\n";
      break;
     }
    } 


}

void mostrarCartas(list <Carta> carta,string categoria,int &v){
  cout<<"Cartas de "<<categoria<<endl;
  v=0;
  list <Carta>::iterator it;
   for(it=carta.begin();it!=carta.end();++it){
     cout<<it->getPalo()<<","<<it->getFigura()<<","<<it->getColor()<<endl;
     if(it->getPalo()=="as"){
        it->setValor(0);
        while((it->getValor()!=1)&&(it->getValor()!=11)){
        cout<<"Quieres que el as valga 1 o 11: \n";
        int i;
        cin>>i;
        it->setValor(i);
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
   cout<<"Valor sobrepasado\n";
   return true;
    } 
   else{
    return false;
}
}
