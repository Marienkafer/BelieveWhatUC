#ifndef NODOADY_H_
#define NODOADY_H_
#include <iostream>
#include "NodoVert.h"

using namespace std;

template <class T>
class NodoVert;

template <class Elem>
class NodoAdy
{
  private:

   Elem info;
   float cost;
   NodoVert<Elem> *vert;
   NodoAdy<Elem> *next;

  public:

  inline NodoAdy(): next(NULL), vert(NULL), info(), cost(0.0) {};
  NodoAdy(Elem &elem): next(NULL), vert(NULL), info(elem), cost(0.0) {};
  NodoAdy(Elem &elem, float costo, NodoAdy<Elem> *sig, NodoVert<Elem> *v): info(elem), vert(v), next(sig), cost(costo){};
  
  
  inline Elem getinfo() {return info;} // el problema era aqui.... tengo cuidado con ese info tienes que estar 
  float getcost() {return cost;}
  NodoAdy<Elem> *getnext() {return next;}
  NodoVert<Elem> *getvert() {return vert;}
  
  inline void setinfo(const Elem &informacion) {vert->setinfo(informacion);}
  void setcost(float costo) {cost=costo;}
  void setvert(NodoVert<Elem> *v) {vert=v;}
  void setnext(NodoAdy<Elem> *sig) {next=sig;}

};

#endif

