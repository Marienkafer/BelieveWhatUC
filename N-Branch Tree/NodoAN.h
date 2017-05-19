///*** Created by: Marien Sequera - 2012/01 ***/// 

#ifndef NODOAN_H_
#define NODOAN_H_
#include <iostream>

using namespace std;

template <class T>
class NodoAN
{
 private:
 NodoAN<T> *HD;
 NodoAN<T> *HI;
 T info;
 public:
   NodoAN(): info(), HD(NULL), HI(NULL) {};
   NodoAN(T informacion, NodoAN<T> *HermanoD, NodoAN<T> *HijoI ): info(informacion), HD(HermanoD), HI(HijoI) {}; 
   NodoAN(T informacion): info(informacion), HD(NULL), HI(NULL) {};


   T getinfo() {return info;}
   NodoAN<T> *get_HI() {return HI;}
   NodoAN<T> *get_HD() {return HD;}

   void setinfo(T informacion) {info=informacion;}
   void setHermanoDerecho(NodoAN<T> *HijoD) {HD=HijoD;}
   void setHijoIzquierdo(NodoAN<T> *HijoI) {HI=HijoI;}
};

#endif



///**Copyright - MarienBSequeraM 2012 **///
