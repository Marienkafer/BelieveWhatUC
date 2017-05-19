#include "ArbolBin.h"
#include "ArBinBusq.h"
#include <fstream>

using namespace std;

int main()
{
  //FILE *fentrada;
  ArbolBin<int> A(69), B(5);
  ArbolBin<char> D, F;
  ArbolBin<int> C(7, A, B);
  //ArbolBin<int> W(C);
  Lista<char> preorden, inorden;
  int last;

  
   ifstream f("entrada.in", ifstream::in );
   
  
   cout << C.nulo() << endl;
   cout << C.raiz() << endl;

   
   f>> preorden;
   f>> inorden;

   last = inorden.longitud();
   int i = 1;
   cout << C.altura() << endl;
 
  // D.CrearArbol(preorden, inorden, i, last);
   C.preorden();
   cout << "\n";

   return 0;
}

