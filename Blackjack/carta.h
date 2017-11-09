#ifndef CARTA_H
#define CARTA_H
#include <string>
using namespace std;
class Carta{
  private:
    int valor_,orden_;
    string figura_,color_,anverso_,reverso_;
  public:
    Carta(int valor_,string figura_,int orden_,string anverso_="", string reverso="",string  color_="");
    inline void setValor(int valor){valor_=valor;}
    inline int getValor() const{return valor_;}
    inline void setOrder(int orden){orden_=orden;}
    inline int getOrden() const{return orden_;}
    inline void setFigura(string figura){figura_=figura;}
    inline string getFigura() const{return figura_;}
    inline void setColor(string color){color_=color;}
    inline string getColor() const{return color_;}
    inline void setAnverso(string anverso){anverso_=anverso;}
    inline string getAnverso() const{return anverso_;}
    inline void setReverso(string reverso){reverso_=reverso;}
    inline string getReverso() const{return reverso_;}    

};


#endif
