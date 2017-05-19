#ifndef NODO_H_
#define NODO_H_
#include <iostream> 

using namespace std; 

template <class T>
class Nodo
{ 
 private: 
	Nodo<T> *prox;
	T elem;
 public: 
	///Constructores
	Nodo<T>(): prox(NULL), elem() {} 
	Nodo<T>(T elemento, Nodo<T> *p): prox(p),  elem(elemento){}
	Nodo<T>(T elemento): prox(NULL), elem(elemento){}
	///Observadores
	T get_info() {return elem;}
	Nodo<T> *get_sig() {return prox;}
	/// Modificadores
	void set_info(T elemento) {elem=elemento;}
	void set_sig(Nodo<T> *p) {prox = p;}
};

#endif
