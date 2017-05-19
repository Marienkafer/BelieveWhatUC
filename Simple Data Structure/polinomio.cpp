#include <iostream>
#include "nodo.h"
#include "lista.h"

struct monomio{
  int e;
  float c;
  
};

lista<monomio> suma(lista<monomio> l1, lista<monomio> l2);

lista<monomio> multiplicacion(lista<monomio> l1, lista<monomio> l2);


int main()
{
  
  int coef1=10, coef2=10;
  int exp1=10, exp2=10;
  int k; // numero de casos 
  int i=1, j=1, w=1; 
  lista<monomio> polinomio1, polinomio2, polinomiofinal;
  monomio mon1, mon2;
  cin >> k;
  
  while(k>0)
  {
    
    //cout << k << endl;
    
    cin >> coef1;
    cin >> exp1;
   
    while( exp1 != -1)
    {
      mon1.c = coef1;
      mon1.e = exp1;
      
      polinomio1.insertar(i,mon1);
           
      cin >> coef1;
      cin >> exp1;
      
      cout << polinomio1.consultar(i).c << " " << polinomio1.consultar(i).e << " ";
      
      i++;
    }
    cout << "\n";
    
    cin >> coef2;
    cin >> exp2;
    while( exp2 != -1)
    {
      
      
      mon2.c = coef2;
      mon2.e = exp2;
      
      polinomio2.insertar(j,mon2);
           
      cin >> coef2;
      cin >> exp2;
      
      cout << polinomio2.consultar(j).c << " " << polinomio2.consultar(j).e << " ";
      
      j++;
    }
    
    cout << "\n" << endl;
    
    polinomiofinal = suma(polinomio1, polinomio2);
    
    //if(polinomiofinal)
    while(w<= polinomiofinal.longitud())
    {
      cout << polinomiofinal.consultar(w).c << " " << polinomiofinal.consultar(w).e << " ";
      w++;
    }
    
    polinomiofinal.vaciar();
   
    cout << "\n" << endl;
    k--;
    

    
  }
  
}


lista<monomio> suma(lista<monomio> l1, lista<monomio> l2)
{
  lista<monomio> lf;
  int i=1, j=1, k=1;
  int tam1, tam2;
  monomio monf;
  
  tam1 = l1.longitud();
  tam2 = l2.longitud();

  
  while(i <= tam1 && j <=tam2)
  {
    if(l1.consultar(i).e == l2.consultar(j).e)
    {
     
      monf.c = l1.consultar(i).c + l2.consultar(j).c;
    //  cout << "Sumando " << l1.consultar(i).c << " + " << l2.consultar(j).c << endl;
      monf.e = l1.consultar(i).e;
      
      if(monf.c != 0)
      {
	//cout << "Monomio suma " << monf.c << endl;
	lf.insertar(k++, monf);
      }
	//cout << "holi" << endl;
      
      
      i++;
      j++;
      
    }else if(l1.consultar(i).e < l2.consultar(j).e)
    {
      //cout << " entra1 " << endl;
      monf.c = l2.consultar(j).c;
      monf.e = l2.consultar(j).e;
      //cout << "Inserta con L2 mayor " <<  l2.consultar(j).c << " "<< l2.consultar(j).e << endl;
      lf.insertar(k++, monf);
      
      if(i == tam1 && j ==tam2)
      {
  
	if(l1.consultar(i).e == 0 && l2.consultar(j).e == 1)
	  lf.insertar(k++, l1.consultar(i));
	else if (l2.consultar(j).e == 0 && l1.consultar(i).e == 1)
	  lf.insertar(k++, l2.consultar(j));
      }
      
      j++;
      
    }else if(l1.consultar(i).e > l2.consultar(j).e)
    {
      //cout << " entra2 " << endl;
      monf.c = l1.consultar(i).c;
      monf.e = l1.consultar(i).e;
      
      //cout << "Inserta con L1 mayor " <<  l1.consultar(i).c << " "<< l1.consultar(i).e << endl;
      lf.insertar(k++, monf);
      
      if(i == tam1 && j ==tam2)
      {
  
	if(l1.consultar(i).e == 0 && l2.consultar(j).e == 1)
	  lf.insertar(k++, l1.consultar(i));
	else if (l2.consultar(j).e == 0 && l1.consultar(i).e == 1)
	  lf.insertar(k++, l2.consultar(j));
      }
      
      i++;
    }
   
  }
  
  l1.vaciar();
  l2.vaciar();
  return(lf);
  
}