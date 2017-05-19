///*** Created by: Marien Sequera - 2012/01 ***/// 

#ifndef NodoB_H_
#define NodoB_H_
#ifndef __CSTDDEF_
    #include <cstddef> // definicion de NULL
#endif


#include <iostream>

using namespace std;

template <class T>
class NodoB
{
 private:
 T info;
 NodoB<T> *HD;
 NodoB<T> *HI;
 public:
   NodoB(): info(), HD(NULL), HI(NULL) {};
   NodoB(T elemento) : info(elemento), HD(NULL), HI(NULL) {};
   NodoB(T informacion, NodoB<T> *HijoD, NodoB<T> *HijoI ): info(informacion), HD(HijoD), HI(HijoI) {}; 

   T getinfo() {return info;}
   NodoB<T> *get_HI() {return HI;}
   NodoB<T> *get_HD() {return HD;}

   void setinfo(T informacion) {info=informacion;}
   void setHijoDerecho(NodoB<T> *HijoD) {HD=HijoD;}
   void setHijoIzquierdo(NodoB<T> *HijoI) {HI=HijoI;}
};

#endif











///**Copyright - MarienBSequeraM 2012 **///
