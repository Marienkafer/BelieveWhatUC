#ifndef NNODE_H_
#define NNODE_H_
#include <iostream>

using namespace std;

template <class T>
class NNode
{
private:
  int depth;
  T info;
  int children;
  NNode<T> *father;
  NNode<T> *nodes[];
  
public:
  
  NNode(): depth(0), info(), children(0), father(NULL), nodes(NULL) {};
  NNode(T inf): depth(0), info(inf), children(0), father(NULL), nodes(NULL) {};
  NNode(int hijos): depth(0), info(), children(hijos), father(NULL), nodes(NULL) {};

  T getinfo() {return info;}
  NNode<T> *getfather() {return father;}
  NNode<T> *getnodes() {return nodes;}
  
};

#endif