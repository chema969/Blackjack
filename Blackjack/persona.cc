#include <string>
#include "persona.h"
using namespace std;
Persona::Persona(string DNI,string nombre, string apellidos, string direccion, string localidad, string provincia,string pais){
DNI_=DNI;
nombre_=nombre;
apellidos_=apellidos;
direccion_=direccion;
localidad_=localidad;
provincia_=provincia;
pais_=pais;
}

string Persona::getApellidosyNombre(){
string cadena;
cadena+=apellidos_;
cadena+=", ";
cadena+=nombre_;
return cadena;
}
