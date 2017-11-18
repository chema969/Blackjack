#include <string>
#include "jugador.h"
#include <list>
#include <iostream>
#include "carta.h"

Jugador::Jugador(string DNI,int dinero,string nombre, string apellidos, string direccion, string localidad, string provincia,string pais):Persona(DNI,nombre,apellidos,direccion,localidad,provincia,pais){
dinero_=dinero;
}

  
int Jugador::setValorCartas(){
   list <Carta>::iterator it;
   int v=0;
   for(it=c_.begin();it!=c_.end();++it){
     cout<<it->getPalo()<<","<<it->getFigura()<<","<<it->getColor()<<endl;
     if(it->getPalo()=="as"){
      if(it->getValor()==0){
       if(v<11) it->setValor(11);
       else it->setValor(1);
      }
     }
    v=v+it->getValor();
}
return v;
}
