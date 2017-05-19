///*** Created by: Marien Sequera - 2014/02 ***///

#ifndef QUADNODE_H_
#define QUADNODE_H_
#include <iostream>

using namespace std;

template <class T>
class QuadNode
{
 private:
 QuadNode<T> *C1, *C2, *C3, *C4;
 T info;
 public:
   QuadNode(): C1(NULL), C2(NULL), C3(NULL), C4(NULL), info() {}
   QuadNode(T elem) :  C1(NULL), C2(NULL), C3(NULL), C4(NULL), info(elem) {}
   QuadNode(T inf, QuadNode<T> *cu1, QuadNode<T> *cu2, QuadNode<T> *cu3, QuadNode<T> *cu4): info(inf), C1(cu1), C2(cu2), C3(cu3), C4(cu4) {};

   T getinfo() {return info;}
   QuadNode<T> *getC1() {return C1;}
   QuadNode<T> *getC2() {return C2;}
   QuadNode<T> *getC3() {return C3;}
   QuadNode<T> *getC4() {return C4;}

   void setinfo(T inf) {info=inf;}
   void setC1(QuadNode<T> *cu1) {C1=cu1;}
   void setC2(QuadNode<T> *cu2) {C2=cu2;}
   void setC3(QuadNode<T> *cu3) {C3=cu3;}
   void setC4(QuadNode<T> *cu4) {C4=cu4;}
};

#endif
