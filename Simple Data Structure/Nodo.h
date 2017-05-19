#ifndef NODO_H_
#define NODO_H_
#include <iostream> 

using namespace std; 

template <class T>
class nodo
{ 
 private: 
	nodo<T> *prox;
	T elem;
 public: 
	///Constructores
	nodo<T>(): prox(NULL) {} 
	nodo<T>(T elemento, nodo<T> *p): elem(elemento) , prox(p) {}
	///Observadores
	T get_info() {return elem;}
	nodo<T> *get_sig() {return prox;}
	/// Modificadores
	void set_info(T elemento) {elem=elemento;}
	void set_sig(nodo<T> *p) {prox = p;}
};

#endif
