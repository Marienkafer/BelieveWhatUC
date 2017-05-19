#ifndef COLA_H_
#define COLA_H_
#include <iostream>
#include "Nodo.h"


using namespace std;

template <class T> 
class cola
{
  private:
    Nodo<T> *principio, *final;
  public:
  ///***Contructores***
    cola(): principio(NULL), final(NULL) {}
    cola(Nodo<T> *first, Nodo<T> *last): principio(first) , final(last) {} 
  ///***Observadores***
    bool es_vacia() {return principio == NULL;} 
    T getfrente() {return principio->get_info();}
  ///***Modificadores***
    void encolar(T elemento);
    void desencolar();
    void vaciar();
  
    ///***Destructor***
    //~cola();

    ///***Sobrecarga***
    istream &operator>>(istream &);
    inline friend istream &operator>>(istream &is, cola &a){ return a.operator>>(is); }
    
    ostream &operator<<(ostream &);
    inline friend ostream &operator<<(ostream &out, cola &b) {return b.operator<<(out);}
    
    bool operator==(const cola &a) const;
    bool operator!=(const cola &a) const { return(!operator==(a));}
    cola<T> &operator =(const cola &a);
	
};

 
template <class T>
void cola<T> :: encolar(T elemento) 
{
  Nodo<T> *nuevo;
  
  nuevo = new Nodo<T>();	
  nuevo->set_info(elemento);

  final = principio;
  while(final->get_sig() != NULL)
  {
    final = final->get_sig();
  }
  
  if(principio== NULL)
      principio = nuevo;
  else
    final->set_sig(nuevo);

   final=nuevo;
  
}

template <class T>
void cola<T> :: desencolar()
{
  Nodo<T> *temp;
  
  temp=principio;
  principio=principio->get_sig();
  if(principio == NULL)
  {
    final=NULL;
     delete temp;
  }
}

template <class T>
void cola<T>::vaciar()
{
  Nodo<T> *aux;

  while(principio != NULL)
  {
    aux = principio;
    principio = principio->get_sig();
    delete aux;
  }
	
	final = NULL;
}


template <class T>
istream &cola<T>::operator>>(istream &is)
{
	Nodo<T> *nodix;
 	int largo;
	T elem;

	vaciar();
	cout << " Tamaño de la cola " << endl;
 	is >> largo;
	is >> elem;
	principio = nodix = new Nodo<T>(elem, NULL);
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
ostream &cola<T>::operator<<(ostream &out)
{
  Nodo<T> *actual;
 
  actual = principio;

  while (actual != NULL)
  { 
    out<< actual->get_info() << "  ";
    actual = actual->get_sig();
  }
   return out;
}


template <class T>
bool cola<T> :: operator==(const cola &a) const
{
Nodo<T> *aux, *temp;
bool band;

band = true;


temp=a.principio;
aux =principio;

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
cola<T> &cola<T> :: operator =(const cola &a)
{
	Nodo<T> *aux, *temp;

	aux=a.principio;

	if(this != &a)
	{
		vaciar();
		if(aux != NULL)
		{
			principio = temp = new Nodo<T>(aux->get_info(), NULL);
			aux= aux->get_sig();

			while(aux != NULL)
			{	
				temp->set_sig( new Nodo<T>(aux->get_info(), NULL ));
				aux = aux->get_sig();
				temp = temp->get_sig();

			}
		}
		else
		principio = NULL;

	}
	return(*this);
}



#endif

