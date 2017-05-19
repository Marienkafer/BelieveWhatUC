///*** Created by: Marien Sequera - 2012/01 ***///
///*** Last modified 05/2014 ***////

#ifndef ARBOLB_H_
#define ARBOLB_H_
#include "NodoB.h"
#include <iostream>
#include "Lista.h"

using namespace std;

template <class T>
class ArbolBin
{
 private:
    NodoB<T> *ArBin;

 private:
    void copy(NodoB<T> *OTree, NodoB<T> *NewTree);
    void destroy(NodoB<T> *Tree);
    int buscar(Lista<T> l, int inic, int fin, T info );
    NodoB<T> *inCrearArbol( Lista<T> preOrd, Lista<T> inOrd, int &inic, int &last, int &i);
    int inaltura(NodoB<T> *p, int &cant1, int &cant2);
    void addHijoIzq(ArbolBin<T> &HijoIzq);
    void addHijoDer(ArbolBin<T> &HijoDer);
    int incantnodos(NodoB<T> *p);
    void preOrden(NodoB<T> *ArBin);
    void postOrden(NodoB<T> *ArBin);
    void inOrden(NodoB<T> *ArBin);
    void setRaiz(NodoB<T> *r);
   

 public:
   
   //Creadores
   ArbolBin(): ArBin() {};
   ArbolBin(const T info) {ArBin = new NodoB<T>(info);}
   ArbolBin(T info, ArbolBin<T> &HijoI, ArbolBin<T> &HijoD);
   ArbolBin(const ArbolBin<T> &orig);
   ArbolBin<T> CrearArbol(Lista<T> preOrd, Lista<T> inOrd, int inic, int last);

    
   ///Consultores
   bool nulo() {return (ArBin==NULL);}
   T raiz() const {return ArBin->getinfo();}
   ArbolBin<T> getHijoIzquierdo() const {return ArBin->get_HI();}
   ArbolBin<T> getHijoDerecho() const {return ArBin->get_HD();}
   int  altura();
   int cantnodos();
    
    
   /// Recorrido
   void preorden();
   void postorden();
   void inorden();
    
   /// Destructor
    ~ArbolBin();
};


template<class T>
void ArbolBin<T> :: setRaiz(NodoB<T> *r) { ArBin = r; }


template <class T>
void ArbolBin<T> :: destroy(NodoB<T> *Tree)
{
  if(Tree)
  {
    destroy(Tree->get_HI());
    destroy(Tree->get_HD());
    delete(Tree);
    Tree=NULL;
  }
}

template <class T>
void ArbolBin<T>::copy(NodoB<T> *OTree, NodoB<T> *NewTree)
{
    // Recorrido en Preorden
    if (OTree != NULL)
    {
        NewTree = new NodoB<T>(OTree->getinfo());

        copy(OTree->get_HI(), NewTree->get_HI());
        copy(OTree->get_HD(), NewTree->get_HD());
    }
    else
        NewTree = NULL;
}

template<class T>
int ArbolBin<T> :: buscar(Lista<T> l, int inic, int fin, T info )
{
  int j;
  for(j = inic; j <= fin; j++)
  {
    if(l.consultar(j)== info)
      return j;
  }
 
}


template<class T>
NodoB<T> *ArbolBin<T> :: inCrearArbol( Lista<T> preOrd, Lista<T> inOrd, int &inic, int &last, int &i)
{
  
   //int i = 1;
   if(inic>last)
     return NULL;
   
   
   else{
   
     NodoB<T> *p = new NodoB<T>(preOrd.consultar(i++));
  
     if(inic == last){
       return(p);
      
     }
     
      int aux = buscar(inOrd, inic, last, p->getinfo());
      cout << p->getinfo() << " " << aux << endl; 
      
      int aux1=aux-1;
      int aux2=aux+1;
      
      p->setHijoIzquierdo(inCrearArbol(preOrd, inOrd , inic, aux1, i));
      p->setHijoDerecho(inCrearArbol(preOrd, inOrd , aux2, last, i));
     
      return(p);
    }
}

template <class T>
int ArbolBin<T> :: inaltura(NodoB<T> *p, int &cant1, int &cant2)
{
  if((p->get_HI() == NULL)&&(p->get_HD()==NULL))
  {
    if(cant1>=cant2)
      return cant1;
    else
      return cant2;
  }else
  {
    cant1++;
    inaltura(p->get_HI(), cant1, cant2);
    cant2++;
    inaltura(p->get_HD(), cant1, cant2);
  }
  
}

// Pre: cant = 0 o -1

template<class T>
int ArbolBin<T> :: incantnodos(NodoB<T> *p)
{
  if(p=NULL)
    return(0);
  else
  {
    return(1+incantnodos(p->get_HI()) + incantnodos(p->get_HD()));
  }
}

template<class T>
void ArbolBin<T>::addHijoIzq(ArbolBin<T> &HijoI)
{
    if ((ArBin != NULL) && (ArBin->get_HI() == NULL))
    {
        ArBin->setHijoIzquierdo(HijoI.ArBin);
        HijoI.ArBin=NULL;
    }
}

template<class T>
void ArbolBin<T>::addHijoDer(ArbolBin<T> &HijoD)
{
    if ((ArBin != NULL) && (ArBin->get_HD() == NULL))
    {
        ArBin->setHijoDerecho(HijoD.ArBin);
        HijoD.ArBin=NULL;
    }
}


template <class T>
void ArbolBin<T> :: preorden()
{
  preOrden(ArBin);
}


template <class T>
void ArbolBin<T> :: postorden()
{
  postOrden(ArBin);
}


template <class T>
void ArbolBin<T> :: inorden()
{
  inOrden(ArBin);
}

/// *** Metodos Publicos ** ///

template <class T>
ArbolBin<T> :: ArbolBin(T info, ArbolBin<T> &HijoI, ArbolBin<T> &HijoD)
{
  ArBin = new NodoB<T>(info);
  addHijoIzq(HijoI);
  addHijoDer(HijoD);
}

template<class T>
ArbolBin<T> :: ArbolBin( const ArbolBin<T> &orig)
{
  copy(orig.ArBin, ArBin);
}

template<class T>
int  ArbolBin<T> :: altura()
{
  int cant1, cant2;
  
  cant1=cant2=0;
  
  return(inaltura(ArBin, cant1, cant2));
}

template <class T>
int ArbolBin<T> :: cantnodos()
{
  
  return(incantnodos(ArBin));
}

template<class T>
ArbolBin<T> ArbolBin<T> :: CrearArbol(Lista<T> preOrd, Lista<T> inOrd, int inic, int last)
{
  int i=1;
  ArBin = inCrearArbol( preOrd, inOrd, inic, last, i);
}

template <class T>
void ArbolBin<T> :: preOrden(NodoB<T> *ArBin)
{
  if(ArBin != NULL)
  {
    cout << " " << ArBin->getinfo();
    preOrden(ArBin->get_HI());
    preOrden(ArBin->get_HD());
  }
}

template <class T>
void ArbolBin<T> :: postOrden(NodoB<T> *ArBin)
{
  if(ArBin != NULL)
  {
    postOrden(ArBin->get_HI());
    postOrden(ArBin->get_HD());
    cout << " " << ArBin->getinfo();
  }
}


template <class T>
void ArbolBin<T> :: inOrden(NodoB<T> *ArBin)
{
  if(ArBin != NULL)
  {
    inOrden(ArBin->get_HI());
    cout << " " << ArBin->getinfo();
    inOrden(ArBin->get_HD());
  }
}



template <class T>
ArbolBin<T> :: ~ArbolBin()
{
   destroy(ArBin);
}

#endif










///**Copyright - MarienBSequeraM 2012 **///

