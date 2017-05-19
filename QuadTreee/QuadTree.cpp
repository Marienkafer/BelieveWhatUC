#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

struct QuadNode{
    char data;

    struct QuadNode* father;
    int depth;

    struct QuadNode* C1;
    struct QuadNode* C2;
    struct QuadNode* C3;
    struct QuadNode* C4;

    bool visitC1;
    bool visitC2;
    bool visitC3;
    bool visitC4;
};

struct QuadNode* newNode(char data){
    
    struct QuadNode* QuadNode = (struct QuadNode*) malloc(sizeof(struct QuadNode));

    QuadNode->data = data;
    QuadNode->father = NULL;
    QuadNode->depth = 0;

    QuadNode->C1 = NULL;
    QuadNode->C2 = NULL;
    QuadNode->C3 = NULL;
    QuadNode->C4 = NULL;

    QuadNode->visitC1 = false;
    QuadNode->visitC2 = false;
    QuadNode->visitC3 = false;
    QuadNode->visitC4 = false;

    return(QuadNode);
}

struct QuadNode *buildTree( string in, int &i, QuadNode *p );
void printTree(QuadNode *p);
struct QuadNode *nulo();
bool esnulo( struct QuadNode *p);
char color(struct QuadNode *p);
struct QuadNode *Qt_union(struct QuadNode *Qt1, struct QuadNode *Qt2, struct QuadNode *Qtf, struct QuadNode *root);
int pixels_en_negro(struct QuadNode *q, int max_alt, int &value);


int main()
{

    int i=0;
    int cases = 0;
    cin >> cases;
    for(int j = 0; j < cases; j++){
      cout << "Case " << (j+1) << ":\n";
      string a;
      string b;

      cin >> a >> b;
      cout << "\ta: " << a << " : " << a.length() << "\n";
      cout << "\tb: " << b << " : " << b.length() << "\n";


      QuadNode *A = NULL;
      A = buildTree(a, i, A);
      cout << "\n";
   
      QuadNode *B = NULL;
      i=0;
      B = buildTree(b, i, B);
      cout << "\n";

      cout << "Arbol A: \n" << endl;
      printTree(A);
      
      cout << "\n";
      cout << "A es nulo? ";
      
      if(esnulo(A))
	cout<< " Verdad "<< endl;
      else
	cout << "Falso " << endl;
      
      cout << "Color de A: " << color(A) << endl;
      
      cout << "Pixeles Negros de A: ";
      int value = 0;
      cout << pixels_en_negro(A, 2, value) << endl;
      cout << "\n";
      
      cout << "Arbol B: \n " << endl;
      printTree(B);
      cout << "\n";
      cout << "B es nulo? ";
      
      if(esnulo(B))
	cout<< " Verdad "<< endl;
      else
	cout << "Falso " << endl;
      
      cout << "Color de B: " << color(B) << endl;
      cout << "Pixeles Negros de B: ";
      value = 0;
      cout << pixels_en_negro(B, 2, value) << endl;
      
      cout << "\n";
      
      struct QuadNode *C;
      
     // C = Qt_union(A, B, C);
      //printTree(C);
    }

   cout << "\n end\n";

}

struct QuadNode *buildTree( string in, int &i, QuadNode *p ){

  if(p == NULL){
    p = newNode(in[0]);
    p->depth = 0;
  }

  int longitud = in.length();
  if(i == longitud-1){
    return p;
  }

  i=i+1;
  struct QuadNode *aux2 = newNode(in[i]);
  aux2->father = p;
  aux2->depth = p->depth+1;
  if(!(p->visitC1)){
    p->C1 = aux2;
    p->visitC1 = true;

  }else if (!(p->visitC2)){
    p->C2 = aux2;
    p->visitC2 = true;

  }else if (!(p->visitC3)){
    p->C3 = aux2;
    p->visitC3 = true;

  }else if (!(p->visitC4)){
    p->C4 = aux2;
    p->visitC4=true;
    }

    if(p->visitC4)
    {
      if(p->father != NULL)
      {
          p = p->father;
      }
    }

    if(aux2->data == 'p'){
      aux2->depth = p->depth+1;
      buildTree(in, i, aux2);
    }


    return(buildTree(in, i, p));
}

void printTree(QuadNode *p){

  if( p != NULL)
  {
    if(p->data == 'p')
    {
      cout << "Raiz " << endl;
    }
   
    cout << p->data << " nivel " << p->depth << endl;
  

    printTree(p->C1);
    printTree(p->C2);
    printTree(p->C3);
    printTree(p->C4);
  }
}

struct QuadNode *nulo()
{
   struct QuadNode *q = NULL;
}

bool esnulo( struct QuadNode *p)
{
  if(p == NULL)
    return true;
  else
    return false;
}

char color(struct QuadNode *p)
{
  return(p->data);
}

int valor(int nivel)
{
  int value;
  
  switch(nivel)
  {
    case 0:{
      value = 64;
      break;
      
    }
    case 1: {
      value = 16;
      break;
    }
    case 2: {
      value = 4;
      break;
    }
    case 3: {
      value = 1;
      break;
    }
  }
  
  return(value);
}
int pixels_en_negro(struct QuadNode *q, int max_alt, int &value)
{
  //int cont = 0;
   
  if(q != NULL)
  {
    if(q->data == 'f')
    {
      //cont++;
      value = value + valor(q->depth);
      
    }else
    {
      if(q->depth <= max_alt)
      {
	pixels_en_negro(q->C1, max_alt, value);
	pixels_en_negro(q->C2, max_alt, value);
	pixels_en_negro(q->C3, max_alt, value);
	pixels_en_negro(q->C4, max_alt, value);
      }
      
    }
  
  }
  return(value);
}

struct QuadNode *Qt_union(struct QuadNode *Qt1, struct QuadNode *Qt2, struct QuadNode *Qtf, struct QuadNode *root)
{
 // Qtf = Qt1;
  struct QuadNode *aux;
  char comparar1, comparar2;
  
  comparar1 = Qt1->data;
  comparar2 = Qt2->data;
  
  if(Qt1 == NULL)
    comparar1=comparar2;
  else if(Qt2 == NULL)
    comparar2=comparar1;
  
    
  if(Qtf == NULL)
  {
    if((comparar1 == 'f')&&(comparar2 == 'e'))
    {
      Qtf = newNode (comparar1);
      Qtf->depth = Qt1->depth;
    }else if ((comparar1 == 'f')&&(comparar2 == 'p'))
    {
      Qtf = newNode (comparar1);
      Qtf->depth = Qt1->depth;
    }else if((comparar1 == 'e')&&(comparar2 == 'f'))
    {
      Qtf = newNode (comparar2);
      Qtf->depth = Qt2->depth;
    }else if ((comparar1 == 'e')&&(comparar2 == 'p'))
    {
      Qtf = newNode (comparar2);
      Qtf->depth = Qt2->depth;
    }else if((comparar1 == 'p')&&(comparar2 == 'f'))
    {
      Qtf = newNode (comparar2);
      Qtf->depth = Qt2->depth;
    }else if ((comparar1 == 'p')&&(comparar2 == 'e'))
    {
      Qtf = newNode (comparar1);
      Qtf->depth = Qt1->depth;
    }else
    {
      Qtf = newNode (comparar1);
      Qtf->depth = Qt1->depth;
    }
    
     Qtf->father = root;
    
  }
    
     Qtf->C1 =Qt_union(Qt1->C1, Qt2->C1, Qtf->C1, root);
     Qtf->C2 =Qt_union(Qt1->C2, Qt2->C2, Qtf->C2, root);
     Qtf->C3 =Qt_union(Qt1->C3, Qt2->C3, Qtf->C3, root);
     Qtf->C4 =Qt_union(Qt1->C4, Qt2->C4, Qtf->C4, root);
    
}