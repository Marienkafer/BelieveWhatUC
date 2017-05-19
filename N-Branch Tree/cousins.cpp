#include "NNode.h"
#include "NTree.h"

using namespace std;

int main()
{
  
  NTree<string> familia();
  
  while(!cin.eof()){
    string nombre = "";
    
    cin >> nombre;
    if(nombre == "***"){
      cin >> nombre; //leemos el nombre
     //buscarPrimo(nombre);
      continue; //volvemos al principio del while
      
    }
    
    int numHijos = 0;
    cin >> numHijos; //leo el nombre y el numero de hijos
    string nombresHijos[numHijos];
    for(int j = 0; j < numHijos; j++){
      cin >> nombresHijos[j];
      
    }
     //le entrego nombre, numero y nombres de hijos
   familia.BuscarNodo(nombre, numHijos, nombresHijos);
    
  }
}
