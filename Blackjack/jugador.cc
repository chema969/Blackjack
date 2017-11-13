#include <string>
#include "jugador.h"
#include <list>
#include <fstream>

Jugador::Jugador(string DNI,int dinero,string nombre, string apellidos, string direccion, string localidad, string provincia,string pais):Persona(DNI,nombre,apellidos,direccion,localidad,provincia,pais){
dinero_=dinero;
}

  
  
