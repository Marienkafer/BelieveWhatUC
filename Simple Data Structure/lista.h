#ifndef LISTA_H
#define LISTA_H
#include <iostream>
#include "nodo.h"

using namespace std;

template <class T>
class lista
{
  private:
	nodo<T> *l;
	int tamanio;
	nodo<T> *getApuntador(int pos);
  public:
	///***Constructores***
	lista(): l(NULL),  tamanio(0){};
	lista(int tam, nodo<T> *lista) : l(lista) , tamanio(tam) {}
	lista(const lista<T> &list);
	///***Observadores***
	bool esvacia() const {return l == NULL;}
	int longitud() const {return tamanio;}
	T consultar(int pos);
	int localizar( T elemento);
        bool essublista(lista<T> sub);
	int cont_sublistas(lista<T> sub);
	///***Modificadores***
	void insertar(int pos, T elemento);
	void insertar_end( T elemento);
	void eliminar(int pos);
	void vaciar();
	lista<T> dividir_lista(T elemento);
	void compactar();

	
	///***Destructor***
	~lista();

	///***Sobrecargas***
	istream &operator>>(istream &);
	inline friend istream &operator>>(istream &is, lista &a){ return a.operator>>(is); }

	ostream &operator<<(ostream &);
	inline friend ostream &operator<<(ostream &out, lista &b) {return b.operator<<(out);}

	bool operator==(const lista &a) const;
	bool operator!=(const lista &a) const { return(!operator==(a));}
	lista &operator =(const lista &a);

};

template<class T>
lista<T> :: lista(const lista<T> &list)
{
   nodo<T> *aux, *temp;

   aux = list.l;

   if(this != &list)
   {
     if(aux != NULL)
     {
        l = temp = new nodo<T>(aux->get_info(), NULL);
        aux= aux->get_sig();
        while(aux != NULL)
        {
           temp->set_sig( new nodo<T>(aux->get_info(), NULL ));
           aux = aux->get_sig();
           temp = temp->get_sig();
         }
      }
    }
    else
       l = NULL;

    tamanio = list.tamanio;

}


template <class T>
nodo<T> *lista<T> :: getApuntador(int pos)
{
 nodo<T> *P_Pos;
 int i;

	P_Pos = NULL;

	if((pos < 1) || (pos > tamanio))
	  P_Pos=NULL;
	else
	{

	 P_Pos= l;

	 for(i=2; i <= pos; i++)
	 {
	   P_Pos = P_Pos->get_sig();
	 }
	}

	return(P_Pos);

}

template <class T>
T lista<T> :: consultar(int pos)
{
  nodo<T> *P_Pos=NULL;

	P_Pos=getApuntador(pos);

	if(P_Pos == NULL)
	{
	  nodo <T> x;
	  P_Pos = &x;
	  cout << "Error Fatal al consultar" << endl;
	}

	  return(P_Pos->get_info());
}


template <class T>
int lista<T>::localizar(T elemento)
{
	int i;
	nodo<T> *act;

	act = l;
	i = 1;
	while(act != NULL && act->get_info() != elemento)
	{
		act = act->get_sig();
		i++;
	}

	if(act == NULL)
	{
	  cout << "No se encontro el elemento " << endl ;
	  return 0;
	}
	else
		return i;
}


template <class T>
void lista<T> :: insertar(int pos, T elemento)
{
  nodo<T> *P_Pos, *temp;

if(pos >= 1 && pos <= tamanio+1)
{
   if(pos==1)
   {
	temp = new nodo<T>(elemento, l);
	l=temp;
	tamanio++;
   }
   else
   {
      P_Pos=getApuntador(pos-1);
      if(P_Pos == NULL)
        cout << "Error Fatal al insertar" << endl;
      else
      {
        P_Pos->set_sig(new nodo<T> (elemento, P_Pos->get_sig()));
        tamanio++;
      }
   }
 }else
    cout << "Error Fatal al insertar" << endl;
}



template <class T>
void lista<T> :: insertar_end( T elemento)
{
  nodo<T> *P_Pos, *temp;


   if(tamanio == 0)
   {
	temp = new nodo<T>(elemento, l);
	l=temp;
	tamanio++;
   }
   else
   {
      P_Pos=getApuntador(tamanio);
      if(P_Pos == NULL)
        cout << "Error Fatal al insertar" << endl;
      else
      {
        P_Pos->set_sig(new nodo<T> (elemento, P_Pos->get_sig()));
        tamanio++;
      }
   }
}

template <class T>
void lista<T> :: eliminar(int pos)
{

	int i;
	nodo<T> *aux, *act;

	if (pos==1)
	{

	  aux=l;
	  l=aux->get_sig();
	  delete aux;

	}else
	{

	  act = l;
	  i = 1;
	  while(i < pos-1)
	  {
	    act = act->get_sig();
	    i++;
	   }
	    aux = act->get_sig();
	    act->set_sig(aux->get_sig());
	    delete aux;
	 }

    tamanio--;
}


template <class T>
void lista<T> :: vaciar()
{
 nodo<T> *act;

	while(l != NULL)
	{
	  act = l;
	  l = l->get_sig();
	  delete act;
	}
tamanio = 0;
}

template <class T>
lista<T> :: ~lista()
{
   nodo<T> *ant, *post;

    if(tamanio > 0)
    {
       ant = l;
       post = ant->get_sig();
       while(post != NULL)
	{
	  delete ant;
	  ant=post;
	  post=post->get_sig();
	}
	delete ant;
    }
}



template <class T>
istream &lista<T>::operator>>(istream &is)
{
	nodo<T> *nodix;
 	int largo;
	T elem;

	vaciar();
	//cout << "Tamanio de la lista: " << endl;
 	is >> largo;

    tamanio = largo;
    is >> elem;
    nodix = new nodo<T>(elem, NULL);
    l=nodix;
    largo --;
    while(largo != 0)
    {
        is >> elem;
        nodix->set_sig(new nodo<T> (elem, NULL));
        nodix = nodix->get_sig();
        largo--;
    }

     return is;


}

template <class T>
ostream &lista<T>::operator<<(ostream &out)
{
  nodo<T> *actual;

  actual = l;

  while (actual != NULL)
  {
    out<< actual->get_info() << "  ";
    actual = actual->get_sig();
  }
   return out;
}

template <class T>
bool lista<T> :: operator==(const lista &a) const
{
	nodo<T> *aux, *temp;
	bool band(false);

	if(tamanio == a.tamanio)
	{
		temp=a.l;
		aux=l;
		while((aux != NULL) && (temp != NULL) &&  (aux->get_info() == temp->get_info()))
		{
			aux=aux->get_sig();
			temp=temp->get_sig();
		}
		band = aux == NULL;
	}
	return(band);
}

template <class T>
lista<T> &lista<T> :: operator =(const lista &a)
{
	nodo<T> *aux, *temp;

	aux=a.l;

	if(this != &a)
	{
		vaciar();
		if(aux != NULL)
		{
			l = temp = new nodo<T>(aux->get_info(), NULL);
			aux= aux->get_sig();

			while(aux != NULL)
			{
				temp->set_sig( new nodo<T>(aux->get_info(), NULL ));
				aux = aux->get_sig();
				temp = temp->get_sig();

			}
		}
		else
			l = NULL;
		tamanio = a.tamanio;
	}
	return(*this);

}
template <class T>
lista<T> lista<T> :: dividir_lista(T elemento)
{
    nodo<T> *temp, *ant;
    int i;
    lista<T> l2;

    if(l->get_sig() != NULL)
    {
        temp = l;
        while(temp != NULL)
        {
            if(temp->get_info() != elemento)
            {
                ant = temp;
                temp = temp->get_sig();
            }else
            {
                ant->set_sig(NULL);
                l2.l = temp;
                return(l2);

            }
        }
            delete(temp);
            delete(ant);


    }else
        cout << "lista Vacia, imposible de dividir" << endl;
}

template <class T>
void lista<T> :: compactar()
{
  int i;//  cout << "Hola" << endl;

  T info;
  nodo<T> *aux, *next;

  if(l != NULL)
  { 	
	aux = l;
	
    while(aux != NULL)
    {
	i=1;
	info = aux->get_info();
	next = aux->get_sig();
	while((next != NULL)  && (next->get_info() == info))
	{
	   next = next->get_sig();
	   i++;	 
	}
	
	cout << info <<" "<<  i << endl;
	aux = next;
     }

  }else
	cout << "lista Vacia, imposible de compactar" << endl;
}
/*
template <class T>
bool lista<T> :: essublista(lista<T> sub)
{
   nodo<T> *subl;
   aux = l;
   bool band;

   band = false;
   subl = sub.l;
   
   while(subl != NULL) 
   {
     if(aux != NULL)
     {
	if(subl->getinfo() == aux->getinfo())
      	{ 
          subl = subl->get_sig();
	  band = true;
        }else
        { 
           subl = sub.l;
	   band = false;
        }
	
	aux = aux->get_sig();
      }else
      {
	subl = NULL;
      }
 
    }

    return(band);
}
*/
#endif
