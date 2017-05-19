#include "Grafo.h"


int main()
{
   Grafo<int> G;
   
   cout << G.esvacio() << endl; /// 1 es true 0 es false 
   G.addvert(5);
   G.addvert(8);
   //G.addarc (5,8);
   G.addarc (5,8, 24);
   cout << G.existarc(5,8) << endl;
   cout << G.getcostoarc(5,8)<< endl;
   G.deletearc(5,8);
  // G.addvertatend(6);
   G.print();
	

return 0;
} 

