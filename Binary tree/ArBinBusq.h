#ifndef __ARBIN_H
    #include "ArbolBin.h"
#endif

#ifndef __ARBINBUSQ_H
#define __ARBINBUSQ_H

template<class Elemento>
class ArBinBusq : public ArbolBin<Elemento>
{
    public:
        // Constructores

        ArBinBusq();

        ArBinBusq(const Elemento &infoRaiz);

        ArBinBusq(const ArBinBusq<Elemento> &orig);

        // Observadores

        bool buscar(const Elemento &elem) const;
	
	// Modificadores
	void insertar( NodoB<Elemento> a, Elemento x);

	
	
	// Recorridos
	void preorden();
	void postorden();
	void inorden();
	
        // Destructor

        ~ArBinBusq();
};

template<class Elemento>
ArBinBusq<Elemento>::ArBinBusq()
    : ArbolBin<Elemento>() {}


template<class Elemento>
ArBinBusq<Elemento>::ArBinBusq(const Elemento &infoRaiz)
    : ArbolBin<Elemento>(infoRaiz) {}


template<class Elemento>
ArBinBusq<Elemento>::ArBinBusq(const ArBinBusq<Elemento> &orig)
    : ArbolBin<Elemento>(orig) {}


template<class Elemento>
bool ArBinBusq<Elemento>::buscar(const Elemento &elem) const
{
    NodoB<Elemento> *actual;
    bool encontrado = false;

    if (this->ArBin != NULL)
    {
        actual = this->ArBin;
        while ((actual != NULL) && !encontrado)
        {
            if (actual->info == elem)
                encontrado = true;
            else if (actual->info > elem)
                actual = actual->HI;
            else
                actual = actual->HD;
        }
    }
    return encontrado;
}


template <class Elemento>
void ArBinBusq<Elemento> :: insertar( NodoB<Elemento> a, Elemento x)
{
  NodoB<Elemento> *actual;
  actual = this->ArBin;
 
  if(actual == NULL)
  {
    ArbolBin<Elemento>(infoRaiz);

  }else if(x < actual->info){
    
    insertar(actual->HI);
    
  }else if(x < this->ArBin->info){
    
    insertar(actual->HD);
  }

}

template <class Elemento>
void ArBinBusq<Elemento> :: preorden()
{
  this.preorden();
}

template <class Elemento>
void ArBinBusq<Elemento> :: postorden()
{
  this.postorden();
}


template <class Elemento>
void ArBinBusq<Elemento> :: inorden()
{
  this.inorden;
}

#endif
