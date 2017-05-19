#include "Lista.h"
#include "Cola.h"
#include "Pila.h"


int buscar_max_elem(Lista<int> C, int &pos)
{
    Lista<int> aux;
    int max, num, i;

    aux = C;
    max = -1000;
    i = 1;

    while(!aux.esvacia())
    {
        num = aux.consultar(1);
	aux.eliminar(1);

        if(max < num )
            max = num;

        i++;
    }

    pos = C.localizar(max);
   
    return(max);
}

bool esta_alfinal(Lista<int> C, int elem)
{
  int end;
  
  end = C.consultar(C.longitud());
  
  if(end == elem)
    return(true);
  else
    return(false);

}

void voltear_pile( Lista<int> &L, int elem, int pos)
{

  Lista<int> aux;
  int i, w;

  w = 0;
  
  if( pos == 1)
  {

    elem = L.consultar(L.longitud()); 
  }
  
  while( w != elem)
  {
      w = L.consultar(1);
      aux.insertar_end(w);
      L.eliminar(1);
  }
  
  
 
  while(!aux.esvacia())
  {
      L.insertar(1, aux.consultar(1));
      aux.eliminar(1);
  }
 
}


void sort_pile(Lista<int> L)
{
    int elem, pos;
    Pila<int> P;
    Lista<int> aux;
    
    aux = L;
    //inicio
    pos = 0;

    cout << L << endl;

    while(!aux.esvacia())
    {
        elem = buscar_max_elem(aux, pos); // Busca el mayor elemento en toda la pila ; "pos" por referencia guarda la posicion donde esta el mayor elemento y se dara vuelta ahi
       
	
	if(esta_alfinal(aux, elem)) // Si ese elemento esta al final
        {

	   P.apilar(elem); // Apila dicho elemento
           aux.eliminar(aux.longitud()); // Y lo elimina de la cola principal
	   
        } else // Si no
	{  
          cout << pos+P.longitud() << " "; 
	  voltear_pile(aux, elem, pos); // Voltea la pila y lo coloca de primero, y luego vuelve a entrar y lo coloca de ultimo             
	 
        }
     
   }
   
   if(aux.esvacia())
   {
     cout << 0 << endl;
   }
   
     
}

int main ()
{
    Lista<int> L;

    cin >> L;

    sort_pile(L);


}
