#ifndef CARTA_H
#define CARTA_H
#include <string>
using namespace std;
class Carta{
  private:
    int valor_;
    string figura_,palo_,color_;
  public:
    Carta(int valor_,string palo_,string figura_,string  color_="");
    inline void setValor(int valor){valor_=valor;}
    inline int getValor() const{return valor_;}
    inline void setPalo(string palo){palo_=palo;}
    inline string getPalo() const{return palo_;}
    inline void setFigura(string figura){figura_=figura;}
    inline string getFigura() const{return figura_;}
    inline void setColor(string color){color_=color;}
    inline string getColor() const{return color_;}
};


#endif
