#ifndef NODOVERT_H_
#define NODOVERT_H_
#include <iostream>

#include "NodoAdy.h"

using namespace std;


template <class Elem >
class NodoAdy;



template <class T>
class NodoVert
{
  private:

   NodoVert<T> *next;
   NodoAdy<T> *ady;
   T info;
   bool visitado;
   int tiempo, componentes_conexas;
   NodoVert<T> *padre;
   

  public:

  inline NodoVert(): next(NULL), ady(NULL), info(), visitado(false), tiempo(0), componentes_conexas(0), padre(NULL)  {};
  inline NodoVert(T elem): next(NULL), ady(NULL), info(elem),  visitado(false), tiempo(0), componentes_conexas(0), padre(NULL) {};
  inline NodoVert( T elem, NodoVert<T> *sig, NodoAdy<T> *adyacente): next(sig), ady(adyacente), info(elem) {};
 
  int gettiempo() { return tiempo;}
  int getcomponenteconexas () {return componentes_conexas;}
  bool getvisitado() {return visitado;}
  T getinfo() {return info;}
  NodoVert<T> *getnext() {return next;}
  NodoAdy<T> *getady() {return ady;}
  
  void setinfo(T informacion) {info=informacion;}
  void setnext(NodoVert<T> *sig) {next=sig;}
  void setady(NodoAdy<T> *adyacencia) {ady=adyacencia;}
  void setvisitado(bool esta) { visitado = esta;}
  void setpadre(NodoVert<T> *p) {padre=p;}
  void settiempo(int times) { tiempo=times;}
  NodoVert<T> *getpadre() { return padre;}
  

};

#endif

