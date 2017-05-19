#ifndef PILA_H
#define PILA_H
#include <iostream>
#include "Nodo.h"

using namespace std; 

template <class T>
class pila
{
private:
  Nodo<T> *tope;
  int tam;
  
public:
  ///***Constructores***
  pila(): tope(NULL), tam(0) {}
  pila(Nodo<T> *top, int tama) : tope(top), tam(tama) {}
  ///***Observadores***
  bool es_vacia() {return tope == NULL;}
  int longitud()  {return tam;}
  T Gettope();
  ///***Modificadores***
  void apilar(T elemento);
  void desapilar();
  void vaciar();

  ///***Destructores***		
  //~pila();
    
 ///***Sobrecarga***
    istream &operator>>(istream &);
    inline friend istream &operator>>(istream &is, pila &a){ return a.operator>>(is); }
    
    ostream &operator<<(ostream &);
    inline friend ostream &operator<<(ostream &out, pila &b) {return b.operator<<(out);}
    
    bool operator==(const pila &a) const;
    bool operator!=(const pila &a) const { return(!operator==(a));}
    pila<T> &operator =(const pila &a);
	
};

template <class T>
T pila<T> :: Gettope()
{
  T aux;
  
  if(es_vacia())
    cout << "Es Vacia" << endl;
  else
    aux = tope->get_info();
  
  return(aux);
}

template <class T>
void pila<T> :: apilar(T elemento)
{
  Nodo<T> *nuevo;
  
  nuevo = new Nodo<T>(elemento, tope);
  tope = nuevo;
  
  tam++;
}

template <class T>
void pila<T> :: desapilar()
{
  Nodo<T> *temp;
  
  if(es_vacia())
    cout << "Es Vacia" << endl;
  else
  {
    temp = tope;
    tope = tope->get_sig();
    delete temp;
  }
  
  tam--;
}

template <class T>
void pila<T>::vaciar()
{
	Nodo<T> *aux;
	
	while(tope != NULL)
	{
		aux = tope;
		tope = tope->get_sig();
		delete aux;
	}
	
	tam = 0;
}

template <class T>
istream &pila<T>::operator>>(istream &is)
{
	Nodo<T> *nodix;
 	int largo;
	T elem;

	vaciar();
 	is >> largo;
	tam = largo;
	is >> elem;
	tope = nodix = new Nodo<T>(elem, NULL);
	largo --;
	while(largo != 0)
	{
	  is >> elem;
          nodix->set_sig(new Nodo<T> (elem, NULL));
	  nodix = nodix->get_sig();
	  largo--;
	}

	return is;
}

template <class T> 
ostream &pila<T>::operator<<(ostream &out)
{
  Nodo<T> *actual;
 
  actual = tope;

  while (actual != NULL)
  { 
    out<< actual->get_info() << "  " << endl;
    actual = actual->get_sig();
  }
   return out;
}


template <class T>
bool pila<T> :: operator==(const pila &a) const
{
Nodo<T> *aux, *temp;
bool band;

band = true;


temp=a.tope;
aux =tope;

while(((aux->get_sig() != NULL) && (temp->get_sig() != NULL)) && band)
{
  if( aux->get_info() != temp->get_info())
  {
	band = false;
  }
	
  aux=aux->get_sig();
  temp=temp->get_sig();
   
 return(band);
}

}
  
template <class T>
pila<T> &pila<T> :: operator =(const pila &a)
{
  Nodo<T> *aux, *temp;

	aux=a.tope;

	if(this != &a)
	{
		vaciar();
		if(aux != NULL)
		{
			tope = temp = new Nodo<T>(aux->get_info(), NULL);
			aux= aux->get_sig();

			while(aux != NULL)
			{	
				temp->set_sig( new Nodo<T>(aux->get_info(), NULL ));
				aux = aux->get_sig();
				temp = temp->get_sig();

			}
		}
		else
		tope = NULL;

	}
	return(*this);
}




/*
template <class T>
pila<T> :: ~pila()
{
 
}
*/
#endif
