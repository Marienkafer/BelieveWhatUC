#ifndef GRAFO_H_
#define GRAFO_H_
#include <iostream>
#include "NodoVert.h"
#include "NodoAdy.h"
#include <queue>
#include "Lista.h"

using namespace std;
template <class T>
class Grafo
{
  private:
   NodoVert<T> *Vert;
   int cantvert;
   bool esdirigido;


  private:
  NodoVert<T> *getraiz() {return Vert;}
  NodoVert<T> *getvert(T v);
  void visitaDFS(NodoVert<T> *p_v1, int &tiempo);

  public:
  Grafo() : Vert(NULL), cantvert(0), esdirigido(true){};
  Grafo(bool es_dirigido): esdirigido(esdirigido), cantvert(0), Vert(NULL) {};
  Grafo(NodoVert<T> *V, int costV, bool es_dirigido) : esdirigido(esdirigido), cantvert(costV), Vert(V) {};

  /// Consultores 
  bool esvacio() const {return Vert == NULL;} // Sirve
  bool existvert(T elem); // Sirve
  bool existarc (T v1, T v2); // Sirve
  float getcostoarc(T v1, T v2); // Sirve
  int getorden();
  T getprimvert() {return Vert->getinfo();}
  bool estamarcado(T v);
  void marcarvertice(T v);
  void desmarcarvertice(T v);
  bool esconexo( T vert);
  
  Lista<T> predecesores(T v);
  Lista<T> sucesores(T v);

  /// Modificadores
  void addvert(T v); // Sirve  
  // void addvertatend( T v);// No esta hecho
  void addarc(T v1, T v2); // Sirve 
  void addarc(T v1, T v2, float cost); // Sirve
  void deletevert(T v);
  void deletearc(T v1, T v2); // Falta implemetar

  /// Busquedas
  void BFS(T elem);
  void DFS();

  /// Impresion por pantalla
  void print();
};

template <class T>
NodoVert<T> *Grafo<T> :: getvert(T v)
{
	NodoVert<T> *aux;
	
	aux = Vert;

    while(aux->getinfo() != v)
       aux=aux->getnext();

  return(aux);
}

template<class T>
void Grafo<T> :: visitaDFS(NodoVert<T> *p_v1, int &tiempo)
{
	NodoAdy<T> *p_v2;
	NodoVert<T> *aux, *padre;
	bool visitado;

	visitado = false;

	padre=p_v1->getpadre();
	visitado=p_v1->getvisitado();
	p_v1->setvisitado(true);
	tiempo++;
	p_v1->settiempo(tiempo);
	p_v2=p_v1->getady();
	while(p_v2 != NULL)
	{

	  
	  aux=p_v2->getvert();
	
		if(!(p_v2->getvert()->getvisitado()))
		{
		 
			padre=p_v2->getvert()->getpadre();
			p_v2->getvert()->setpadre(padre);
			visitaDFS(p_v2->getvert(), tiempo);
		}
		p_v2= p_v2->getnext();
	
	}

	tiempo++;
	p_v1->settiempo(tiempo);
	

}

template <class T>
bool Grafo<T> :: existvert(T elem)
{
  NodoAdy<T> *aux;

   aux=new NodoAdy<T>();
   aux=Vert->getnext();

  if((aux->getinfo() != Vert) && (aux=!NULL))
  {
    aux->setnext(aux->getnext());
  }
  else
  {
    if (aux==NULL)
      return (false);
      else
	return(true);
  }
}

template <class T>
bool Grafo<T> :: existarc( T v1, T v2)
{
  NodoVert<T> *vert1; 
  NodoAdy<T> *vert2;

     vert1 = getvert(v1);

	if(vert1 != NULL)
	{
		vert2 = vert1->getady();
		
		while(vert2->getinfo() != v2)
		{
			vert2 = vert2->getnext();
	    }
	    
	    if(vert2 == NULL) //No lo encontro
	     return(false);
	    else
	     return(true);
		
	}
}


template <class T>
void Grafo<T> :: addvert(T v)
{
  NodoVert<T> *ap_nv, *act, *ant;

  ap_nv = new NodoVert<T>(v);
  
  if(Vert == NULL)
    Vert = ap_nv;
  else
  {
    act = Vert;
    while(act != NULL)
    {
    	ant = act;
    	act = act->getnext();
    }
    
    ap_nv->setnext(act);
    ant->setnext(ap_nv);
  }

  cantvert++;
}

template <class T>
void Grafo<T> :: addarc(T v1, T v2)
{
 	NodoVert<T> *actualVert;
	NodoAdy<T> *nuevoAdy, *antAdy, *sigAdy;

	nuevoAdy = new NodoAdy<T>(v2);
	
        actualVert = Vert;
	actualVert = getvert(v1);	//nuevoAdy->setvert(actualVert); (no se porque estaba aqui esto)

	antAdy = NULL;
	sigAdy = actualVert->getady();

	while(sigAdy != NULL && sigAdy->getinfo() < v2)
	{
		antAdy = sigAdy;
		sigAdy = sigAdy->getnext();
	}

	
	if(antAdy == NULL)
	{
		nuevoAdy->setnext(sigAdy);
		actualVert->setady(nuevoAdy);
	}
	else
	{
		antAdy->setnext(nuevoAdy);
		nuevoAdy->setnext(sigAdy);
	}
	
}


template <class T>
void Grafo<T> :: addarc(T v1, T v2, float cost)
{
    NodoVert<T> *actualVert;
	NodoAdy<T> *nuevoAdy, *antAdy, *sigAdy;

	nuevoAdy = new NodoAdy<T>(v2);
	nuevoAdy->setcost(cost);
	
	actualVert = Vert;
	actualVert = getvert(v1);

	antAdy = NULL;
	sigAdy = actualVert->getady();

	while(sigAdy != NULL && sigAdy->getinfo() < v2)
	{
		antAdy = sigAdy;
		sigAdy = sigAdy->getnext();
	}
	
	if(antAdy == NULL)
	{
		nuevoAdy->setnext(sigAdy);
		actualVert->setady(nuevoAdy);
	}
	else
	{
		antAdy->setnext(nuevoAdy);
		nuevoAdy->setnext(sigAdy);
	}
	
}

template <class T>
void Grafo<T>:: deletevert(T v)
{
  NodoVert<T> *actualVert, *antVert, *ant, *act;
  NodoAdy<T> *actualAdy, *antAdy, *sigactualAdy;
  bool eliminado;

  antVert=NULL;
  actualVert = Vert;
  
  while(actualVert != NULL)
  {
    if(actualVert->getinfo() != v)
    {
   
      antAdy = NULL;
      actualAdy = actualVert->getady();
      eliminado = false;
      while((!eliminado)&&(actualAdy != NULL))
      {
	 
	if(actualAdy->getvert()->getinfo() == v)
	{
	  if(antAdy == NULL)
	    actualVert->setady(actualAdy->getnext());
	  else
	    antAdy->setnext(actualAdy->getnext());
       
	    delete(actualAdy);
	    eliminado = true;
	}
	else
	{ 
	  antAdy = actualAdy;
	  actualAdy = actualAdy->getnext();
	}
      }
    }
    else
    {
     
      ant = antVert;
      act = actualVert;
    }
    antVert = actualVert;
    actualVert = actualVert->getnext();
  }
  
  if(ant == NULL)
    Vert = act->getnext();
  else
    ant->setnext( act->getnext());
  
  actualAdy = act->getady();
  while((actualAdy != NULL) && (actualAdy->getnext() != NULL))
  {
     sigactualAdy= actualAdy->getnext();
     actualAdy->setnext(sigactualAdy->getnext());
     delete(sigactualAdy);
  }
 
  if(actualAdy == NULL)
    delete(actualAdy);

  delete(act);

}
      
	
template <class T>
void Grafo<T> :: BFS(T elem)
{
    queue< NodoVert<T> * > C;
    NodoVert<T> *p_v1, *aux;
    NodoAdy<T> *p_v2;
    bool visitado;
    
    p_v1=Vert;


    while(p_v1 != NULL)
    {
  
        if(p_v1->getinfo()==elem)
        {
            C.push(p_v1);
            p_v1->setvisitado(true);
        }
        p_v1->setvisitado(false);
	    p_v1->setpadre(NULL);
        p_v1=p_v1->getnext();

    }

    while(!C.empty())
    {

        p_v1=C.front();
        C.pop();

        p_v2=p_v1->getady();
        while(p_v2!=NULL)
        {
	    if(p_v2->getvert()->getvisitado() == false)
            {
	   
               C.push(p_v2->getvert());
                p_v2->getvert()->setvisitado(true);
                p_v2->getvert()->setpadre(p_v1);
            }
            p_v2= p_v2->getnext();
        }
        
 
    }
    
}


template <class T>
void Grafo<T> :: DFS()
{
    int tiempo;
    NodoVert<T> *p_v1;

    
    p_v1=Vert;
    

    while(p_v1!=NULL)
    {
        p_v1->setvisitado(false);
	p_v1->setpadre(NULL);
	
        p_v1=p_v1->getnext();
    }

    tiempo = 0;
    p_v1=Vert;
    while(p_v1!=NULL)
    {
     
        if(!p_v1->getvisitado())
        {    
            visitaDFS(p_v1 , tiempo);
        }
        p_v1=p_v1->getnext();
    }
    
}

template <class T>
bool Grafo<T> :: esconexo(T vert)
{
    NodoVert<T> *p_vert, *p_aux;
    bool conexo;
    conexo = true;
    p_vert = getvert(vert);
   
    DFS();
      
      if(p_vert->getvisitado() == true)
      {
	while(p_vert->getvisitado() == true  && p_vert->getnext() != NULL)
	{
	    p_vert=p_vert->getnext();
	}
      }
      else
	conexo = false;
   
    return(conexo);


}

template <class T>
Lista<T> Grafo<T> :: predecesores(T v)
{
	NodoVert<T> *vact;
	NodoAdy<T> *act;
	Lista<T> list;
	bool encontrado;
	int i;
	
	i = 1;
	vact = Vert;
	
	while(vact!= NULL)
	{
		act = vact->getady();
		encontrado = false;
		while((act != NULL)&&(!encontrado))
		{
			if(act->getinfo() == v)
			{
				list.insertar(i, vact->getinfo());
				i++;
			}
			act = act->getnext();
		}
		vact = vact->getnext();
	}
	
	return(list);
	
}

template <class T>
Lista<T> Grafo<T> :: sucesores(T v)
{
	NodoVert<T> *vact;
	NodoAdy<T> *act;
	Lista<T> list;
	int i;
	
	vact = getvert(v);
	i = 1;
	act = vact->getady();
	
	while(act != NULL)
	{
		list.insertar(i, act->getinfo());
		i++;
		act = act->getnext();
	}
	
	return(list);
}

template <class T>
void Grafo<T> :: print()
{
  NodoVert<T> *aux;
  NodoAdy<T> *auxady;
  
  aux = Vert;
  auxady = aux->getady();
  while(aux != NULL)
  {
    cout << aux->getinfo() <<"-";
    
    while(auxady != NULL)
    {
      cout << auxady->getinfo() << " ";
      auxady = auxady->getnext();
    }
    aux = aux->getnext();
  }
  
}
 
template <class T>
bool Grafo<T> :: estamarcado(T v)
{
  NodoVert<T> *vert;
	  
  vert = getvert(v);
	  
  if(vert->getvisitado())
	return(true);
  else
    return(false);
	  
}

template <class T>
void Grafo<T> :: marcarvertice(T v)
{
   NodoVert<T> *vert;
	  
   vert = getvert(v);
	  
   vert->setvisitado(true);
	  
}
 
template <class T>
void Grafo<T> :: desmarcarvertice(T v)
{
   NodoVert<T> *vert;
	  
   vert = getvert(v);
	  
   vert->setvisitado(false);
	  
}

template <class T> 
float Grafo<T> :: getcostoarc(T v1, T v2)
{
	NodoVert<T> *vert;
	NodoAdy<T> *act;
	float costo;
	
	vert = getvert(v1);
	
	act=vert->getady();
	while(act->getinfo() != v2)
	{
		act = act->getnext();
	}
	
	costo=act->getcost();
	
	return(costo);
}

#endif
