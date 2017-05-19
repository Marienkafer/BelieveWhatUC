#ifndef NTREE_H_
#define NTREE_H_
#include "NNode.h"
#include "Lista.h"
#include <iostream>


template <class G>
class NTree
{
private:
  
  NNode<G> *root;
  void insert(G elem);
  void in_insert(G elem, NNode<G> *leaf);
  void destroy();
  void buscarNodo(NNode<G> *nodo, string nombre, int numHijos, NNode<G> *nombreHijos[]);   
  
  
public:
  
  void BuscarNodo(string nombre, int numhijos, NNode<G> *nombreHijos[]);
  NTree(): root(NULL){};
  //~NTree();
   
  
};


template<class G>
void NTree<G> :: in_insert(G elem, NNode<G> *leaf)
{
     int index = leaf->children;
     leaf->nodes[index] = NULL;
     leaf->nodes[index] = new NNode<G>(elem);
     leaf->nodes[index]->depth  = leaf->depth+1;
     leaf->nodes[index]->parent =  leaf;
     leaf->children = index + 1;
}


template<class G>
void NTree<G> :: buscarNodo(NNode<G> *nodo, string nombre, int numHijos, 
			    NNode<G> *nombreHijos[]){


  if(root == NULL){ //solo se ejecutara la primera vez, cuando no exista nada dentro del arbol
    
    root =new NNode<G>();
    root->padre = NULL;
    
    nodo->nodes = new NNode<G>(numHijos);
    
    for(int k = 0; k < numHijos; k++){
      root->nodes[k] = new NNode<G>();
      root->nodes[k]->info = nombreHijos[k];
      root->nodes[k]->father = root; //importantisimo !
      
    }
    return 0; //para que no siga revisando nada
    
  }
  
  //ingresamos directo
  if(nodo->info == nombre){
    
    nodo->nodes = new NNode<G>(numHijos);
    
    for(int k = 0; k < numHijos; k++){
      nodo->nodes[k] = new NNode<G>();
      nodo->nodes[k]->info = nombreHijos[k];
      root->nodes[k]->father = nodo; //mega importante!
      
    }
    return 0; //para que no siga revisando nada
    
  }
  if(nodo->nodes != NULL){
    //sino reviso los hijos
    for(int i = 0; i < nodo->numHijos; i++){
      buscarNodo(nodo->nodes[i], nombre, numHijos, nombreHijos);
      
    }
    
  }else{
    //no tiene hijos, y si llegamos hasta aca es porque no se encontro el nombre
    return NULL;
    
  }

}

template<class G>
void NTree<G> :: BuscarNodo( string nombre, int numhijos, NNode<G> *nombreHijos[]){
	
  //parto por root
  buscarNodo(root, nombre, numhijos, nombreHijos);
}


#endif