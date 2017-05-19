#ifndef LISTA_H
#define LISTA_H
#include <iostream>
#include "Nodo.h"

using namespace std;

template <class T>
class Lista
{
  private:
	Nodo<T> *l;
	int tamanio;
	Nodo<T> *getApuntador(int pos);
  public:
	///***Constructores***
	Lista(): l(NULL),  tamanio(0){};
	Lista(int tam, Nodo<T> *lista) : l(lista) , tamanio(tam) {}
	Lista(const Lista<T> &list);
	///***Observadores***
	bool esvacia() const {return l == NULL;}
	int longitud() const {return tamanio;}
	T consultar(int pos);
	int localizar( T elemento);
	bool es_sublista(Lista<T> L2);
	///***Modificadores***
	void insertar(int pos, T elemento);
	void eliminar(int pos);
	void vaciar();
	Lista<T> dividir_lista(T elemento);
	void concatenar(Lista<T> l2);
	void eliminar_sublista(Lista <T> L2);
	///***Destructor***
	~Lista();

	///***Sobrecargas***
	istream &operator>>(istream &);
	inline friend istream &operator>>(istream &is, Lista &a){ return a.operator>>(is); }

	ostream &operator<<(ostream &);
	inline friend ostream &operator<<(ostream &out, Lista &b) {return b.operator<<(out);}

	bool operator==(const Lista &a) const;
	bool operator!=(const Lista &a) const { return(!operator==(a));}
	Lista &operator =(const Lista &a);

};

template<class T>
Lista<T> :: Lista(const Lista<T> &list)
{
   Nodo<T> *aux, *temp;

   aux = list.l;

   if(this != &list)
   {
     if(aux != NULL)
     {
        l = temp = new Nodo<T>(aux->get_info(), NULL);
        aux= aux->get_sig();
        while(aux != NULL)
        {
           temp->set_sig( new Nodo<T>(aux->get_info(), NULL ));
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
Nodo<T> *Lista<T> :: getApuntador(int pos)
{
 Nodo<T> *P_Pos;
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
T Lista<T> :: consultar(int pos)
{
  Nodo<T> *P_Pos=NULL;

	P_Pos=getApuntador(pos);

	if(P_Pos == NULL)
	{
	  Nodo <T> x;
	  P_Pos = &x;
	  cout << "Error Fatal al consultar" << endl;
	}

	  return(P_Pos->get_info());
}


template <class T>
int Lista<T>::localizar(T elemento)
{
	int i;
	Nodo<T> *act;

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
void Lista<T> :: insertar(int pos, T elemento)
{
  Nodo<T> *P_Pos, *temp;

if(pos >= 1 && pos <= tamanio+1)
{
   if(pos==1)
   {
	temp = new Nodo<T>(elemento, l);
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
        P_Pos->set_sig(new Nodo<T> (elemento, P_Pos->get_sig()));
        tamanio++;
      }
   }
 }else
    cout << "Error Fatal al insertar" << endl;
}


template <class T>
void Lista<T> :: eliminar(int pos)
{

	int i;
	Nodo<T> *aux, *act;

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
void Lista<T> :: vaciar()
{
 Nodo<T> *act;

	while(l != NULL)
	{
	  act = l;
	  l = l->get_sig();
	  delete act;
	}
tamanio = 0;
}

template <class T>
Lista<T> :: ~Lista()
{
   Nodo<T> *ant, *post;

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
istream &Lista<T>::operator>>(istream &is)
{
	Nodo<T> *nodix;
 	int largo;
	T elem;

	vaciar();
	//cout << "Tamanio de la Lista: " << endl;
 	is >> largo;

    tamanio = largo;
    is >> elem;
    nodix = new Nodo<T>(elem, NULL);
    l=nodix;
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
ostream &Lista<T>::operator<<(ostream &out)
{
  Nodo<T> *actual;

  actual = l;

  while (actual != NULL)
  {
    out<< actual->get_info() << "  ";
    actual = actual->get_sig();
  }
   return out;
}

template <class T>
bool Lista<T> :: operator==(const Lista &a) const
{
	Nodo<T> *aux, *temp;
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
Lista<T> &Lista<T> :: operator =(const Lista &a)
{
	Nodo<T> *aux, *temp;

	aux=a.l;

	if(this != &a)
	{
		vaciar();
		if(aux != NULL)
		{
			l = temp = new Nodo<T>(aux->get_info(), NULL);
			aux= aux->get_sig();

			while(aux != NULL)
			{
				temp->set_sig( new Nodo<T>(aux->get_info(), NULL ));
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
Lista<T> Lista<T> :: dividir_lista(T elemento)
{
    Nodo<T> *temp, *ant;
    int i;
    Lista<T> l2;

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
        cout << "Lista Vacia, imposible de dividir" << endl;
}

template <class T>
void Lista<T> :: concatenar(Lista<T> l2)
{
    Nodo<T> *aux, *temp;

    aux=l2.l;

     if(aux != NULL)
     {
         temp = l;
         while(temp->get_sig() != NULL)
             temp = temp->get_sig();

         while(aux->get_sig() != NULL)
         {
             temp->set_sig(new Nodo<T> (aux->get_info(), NULL));
             aux = aux->get_sig();
             temp = temp->get_sig();

            if(aux->get_sig() == NULL)
             temp->set_sig(new Nodo<T> (aux->get_info(), NULL));
         }

     }

}


#endif
