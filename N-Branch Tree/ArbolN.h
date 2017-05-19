//*** Created by: Marien Sequera - 2012/01 ***///

#ifndef ARBOLNARIO_H_
#define  ARBOLNARIO_H_
#include "NodoAN.h"
#include <list>
#include <iostream>


template <class T>
class ArbolNario
{
 private:
    NodoAN<T> *ArbolN;

 private:
     NodoAN<T> *getraiz() {return ArbolN;}
     void invaciar(NodoAN<T> *ArbN);
     void incopy (NodoAN<T> *ArbolN_O, NodoAN<T> * &ArbolN_D);

 public:
    ArbolNario(): ArbolN(NULL) {};
    ArbolNario(const T &info) {ArbolN = new NodoAN<T>(info);}
    ArbolNario(T info, list<ArbolNario<T> > hijos);
    ArbolNario(const ArbolNario<T> &ArbN);

    bool nulo() {return (ArbolN==NULL);}
    T raiz() const {return ArbolN.getinfo();}
    list<ArbolNario<T> > gethijos();

    void setraiz(NodoAN<T> *ap_nr) {ArbolN = ap_nr;}
    void addSubarbol(ArbolNario<T> a);
    void addSubarbol(ArbolNario<T> a, int pos);
    void deleteSubarbol(int pos);
    void copy(ArbolNario<T> &a);
    void vaciar();
    void preOrden(NodoAN<T> *ArbolN);
    void postOrden(NodoAN<T> *ArbolN);
    void inOrden(NodoAN<T> *ArbolN);
    void printAN();

    ~ArbolNario();
};



template <class T>
void ArbolNario<T> :: incopy (NodoAN<T> *ArbolN_O, NodoAN<T> * &ArbolN_D)
{
   NodoAN<T> *aux, *aux2, *aux3;


   if(ArbolN_O != NULL)
   {
   	ArbolN_D = new NodoAN<T>(ArbolN_O->getinfo());

   	if(ArbolN_O->get_HI() != NULL)
   	{
     	  aux = ArbolN_O->get_HI();
     	  incopy(aux,aux2);
     	  ArbolN_D->setHijoIzquierdo(aux2);
     	  while(aux->get_HD() != NULL)
     	  {
     	    aux=aux->get_HD();
       	    incopy(aux, aux3);
       	    aux2->setHermanoDerecho(aux3);
       	    aux2=aux3;
     	  }
    	}
    }
    else
    	ArbolN_D = NULL;

}

template <class T>
ArbolNario<T> :: ArbolNario(T info, list<ArbolNario<T> > hijos)
{
  NodoAN<T> *aux, *aux2;

  ArbolN = new NodoAN<T>(info);


  if(!hijos.esvacia())
  {
    incopy(hijos.consultar(1).getraiz(), aux);
    hijos.eliminar(1);
    ArbolN->setHijoIzquierdo(aux);
    while (!hijos.esvacia())
    {
        incopy( hijos.consultar(1).getraiz(), aux2);
	hijos.eliminar(1);
	aux->setHermanoDerecho(hijos.consultar(1).ArbolN);
	hijos.eliminar(1);
	aux->setHermanoDerecho(aux2);
	aux=aux2;
    }
  }
}
