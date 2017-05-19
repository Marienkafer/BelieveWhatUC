#include "ArbolNario.h"
#include <fstream>

int main()
{
  ArbolNario<int> A(5), B(7), C(15), D(25);
  Lista<ArbolNario<int> > list, lis2;
  
  ifstream f("entrada.in", ifstream::in );
  
  //f>> list;
  list.insertar(1,B);
  list.insertar(2,C);
  list.insertar(3,A);
  
  ArbolNario<int> W(100, list);
  ArbolNario<int> S(W);
  
  lis2 = S.gethijos();
  
  W.addSubarbol(D, 3);
 // W.deleteSubarbol(3);
  S.vaciar();
}