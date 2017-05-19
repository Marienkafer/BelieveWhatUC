///*** Created by: Marien Sequera - 2012/01 ***///

#ifndef ARBOLNARIO_H_
#define  ARBOLNARIO_H_
#include "NodoAN.h"
#include "Lista.h"
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
    ArbolNario(T info, Lista<ArbolNario<T> > hijos);
    ArbolNario(const ArbolNario<T> &ArbN);

    /// Consultores
    bool nulo() {return (ArbolN==NULL);}
    T raiz() const {return ArbolN.getinfo();}
    Lista<ArbolNario<T> > gethijos();
    //altura_arbol(NodoAN<T> *Arbol);

    /// Modificadores
    void setraiz(NodoAN<T> *ap_nr) {ArbolN = ap_nr;}
    void addSubarbol(ArbolNario<T> a);
    void addSubarbol(ArbolNario<T> a, int pos);
    void deleteSubarbol(int pos);
    void copy(ArbolNario<T> &a);
    void vaciar();

    ///Recorridos
    void preOrden(NodoAN<T> *ArbolN);
    void postOrden(NodoAN<T> *ArbolN);
    void inOrden(NodoAN<T> *ArbolN);
    void printAN();

    ~ArbolNario();
};

template<class T>
void ArbolNario<T> :: invaciar(NodoAN<T> *ArbN)
{
   NodoAN<T> *aux, *aux2;

   aux=ArbN->get_HI();
   
   while(aux != NULL)
   {
     aux2 = aux->get_HD();
     invaciar(aux);
     aux=aux2;
   }

   delete ArbN;

}

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
ArbolNario<T> :: ArbolNario(T info, Lista<ArbolNario<T> > hijos)
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


template <class T>
ArbolNario<T> :: ArbolNario(const ArbolNario<T> &ArbN)
{
  incopy(ArbN.ArbolN, ArbolN);
}

template <class T>
Lista<ArbolNario<T> > ArbolNario<T> :: gethijos()
{
  int n;
  Lista<ArbolNario<T> > list;
  NodoAN<T> *aux;
  ArbolNario<T> aux2;


  n=0;
  aux = ArbolN->get_HI();
  while(aux != NULL)
  {
    aux2.ArbolN = aux;
    list.insertar(n+1, aux2);
    aux = aux->get_HD();
    n++;
  }
  return(list);
}


template <class T>
void ArbolNario<T> :: addSubarbol(ArbolNario<T> a)
{

  NodoAN<T> *aux;

  incopy(a.getraiz(), aux);
  aux->setHermanoDerecho(ArbolN->get_HI());
  ArbolN->setHijoIzquierdo(aux);
}

template <class T>
void ArbolNario<T> :: addSubarbol(ArbolNario<T> a, int pos)
{
  NodoAN<T> *aux, *aux2;
  int i;

  if(pos=1)
     addSubarbol(a);
  else
  {
      aux=ArbolN->get_HI();
      for(i=2; i<= pos-1; i++)
      {
        aux=ArbolN->get_HI();
      }
          incopy(a.ArbolN, aux2);
          aux2->setHermanoDerecho(aux->get_HD());
          aux->setHermanoDerecho(aux2);

  }
}

template<class T>
void ArbolNario<T> :: deleteSubarbol(int pos)
{
   NodoAN<T> *aux, *aux2;
   int i;

   aux=ArbolN->get_HI();
   for(i=2; i<=pos-1; i++)
   {
      aux = aux->get_HD();
   }
   aux2=aux->get_HD();
   aux->setHermanoDerecho(aux2->get_HD());
   invaciar(aux2);
}

template <class T>
void ArbolNario<T> :: copy(ArbolNario<T> &a)
{
   incopy(ArbolN, a.ArbolN);
}


template<class T>
void ArbolNario<T> :: vaciar()
{
  if(ArbolN!=NULL)
     invaciar(ArbolN);
}

template<class T>
void ArbolNario<T> :: preOrden(NodoAN<T> *ArbolN)
{
    NodoAN<T> *aux;

    cout << ArbolN->getinfo() << endl;
    aux=ArbolN->get_HI();
    while(aux != NULL)
    {
        preOrden(aux);
        aux=aux->get_HD();
    }
}

template<class T>
void ArbolNario<T> :: postOrden(NodoAN<T> *ArbolN)
{
    NodoAN<T> *aux;

    aux=ArbolN->get_HI();

    while(aux != NULL)
    {
        postOrden(aux);
        aux=aux->get_HD();
    }
    cout >> ArbolN->getinfo() >> endl;
}

template<class T>
ArbolNario<T> :: ~ArbolNario()
{
 vaciar();
}

template <class T>
void ArbolNario<T> :: printAN()
{
    this->preOrden(ArbolN);
}


#endif
