///*** Created by: Marien Sequera - 2014/02 ***///

#ifndef QUADTREE_H_
#define QUADTREE_H_
#include "QuadNode.h"
#include "Lista.h"
#include <iostream>



template <class color>
class QuadTree
{
    private:
    QuadNode<color> *QT;
    QuadNode<color> *getraiz() {return QT;} /// Era necesario, y listo
   // QuadNode<char> *increar(Lista<char> Color, QuadNode<char> * aux, int i);

    public:
    QuadTree<color> nulo() {QT = NULL;} /// Listo
    bool esnulo(QuadTree<color> A) {return(A.getraiz() == NULL);} /// 1 True - 0 False
    QuadTree<color> crear(Lista<char> Color); /// NO ESTA LISTO MIERDA
    color Color(QuadTree A) {(QT->getinfo());} /// Listo
    QuadTree qtunion(QuadTree<color> A1, QuadTree<color> A2); /// ** Falta **
    int  pixelesnegros(QuadTree<color> A, int max_alt); /// ** Falta **
    void verQuadTree(); ///** Debe arreglarse
   // QuadTree<color> QuadTreeBasico();

};


template <class color>
QuadNode<char> *QuadTree<color> :: increar(Lista<char> Color, QuadNode<char> *aux, int i)
{
    if(aux== NULL)
     aux = new QuadNode<char>(Color.consultar(i));

    if(i == Color.longitud())
     return aux;

    QuadNode<char> *nodo = new QuadNode<char>(Color.consultar(i));
    if(nodo->getinfo() == 'p')
    {
        if(aux->getC1() == NULL)
           nodo->setC1(increar(Color, nodo, i));
       else if (aux->getC2() == NULL)
          nodo->setC2(increar(Color, nodo, i));
       else if (aux->getC3() == NULL)
          nodo->setC3(increar(Color, nodo, i));
       else if (aux->getC4() == NULL)
            nodo->setC4(increar(Color, nodo, i));
    }else
    {
       if(aux->getC1() == NULL)
       {
           aux->setC1(nodo);
           cout << "C1 " << aux->getC1()->getinfo() << endl;
       }else if (aux->getC2() == NULL)
       {
            aux->setC2(nodo);
            cout << "C2 " << aux->getC2()->getinfo() << endl;
       }else if (aux->getC3() == NULL)
       {
            aux->setC3(nodo);
            cout << "C3 " << aux->getC3()->getinfo() << endl;
       }else if (aux->getC4() == NULL)
       {
            aux->setC4(nodo);
            cout << "C4 " << aux->getC4()->getinfo() << endl;
       }

       increar(Color,aux,i++);
    }
}

template <class color>
QuadTree<color> QuadTree<color>:: crear(Lista<char> Color)
{
    QT = increar(Color, QT, 1);
}

/*

template <class color>
QuadNode<color> QuadTree<color>:: crear(Lista<char> Color, QuadNode<char> *aux, int i)
{
  QuadNode<char> *p, *aux;

  p = new QuadNode<char> (Color.consultar(i));

  if(i==Color.longitud())
    return aux;
  else

  if(p->getinfo() == 'p')
  {
    bandC1= bandC2 = bandC3= bandC4 = false;
    aux = p;
    delete p;

   }

   if(!bandC1)
   {aux->setC1(p);
    bandC1=true;
   }else if(!band2)
   {aux->setC2(p);
    bandC2=true;
   }else if(!band3)
   {aux->setC3(p);
    bandC3=true;
   }else if(!band4)
   {aux->setC4(p);
    bandC4=true;
    }

     crear(Color, aux, i++);
}


template <class color>
QuadTree<color> QuadTree<color>:: crear(Lista<char> Color)
{
    QuadNode<color> *root, *aux, *leaf;
    int i; i=1;

    root = new QuadNode<color>(Color.consultar(i));

    cout << "Aqui si funciona mientras se llena " << endl;
    cout << "Raiz "<< root->getinfo()<< endl;
    aux=root;

    for(i=2;i<=Color.longitud();i++)
    {
        if(Color.consultar(i)== 'p')
        {

            if(aux->getC1() == NULL)
            {
                aux->setC1(leaf);
                aux= aux->getC1();
                cout << "raiz C1 " << aux->getinfo() << endl;
            }else if (aux->getC2() == NULL)
            {
                aux->setC2(leaf);
                aux= aux->getC2();
                cout << "raiz C2 " << aux->getinfo() << endl;
            }else if (aux->getC3() == NULL)
            {
                aux->setC3(leaf);
                aux= aux->getC3();
                cout << "raiz C3 " << aux->getinfo() << endl;
            }else if (aux->getC4() == NULL)
            {
                aux->setC4(leaf);
                aux= aux->getC4();
                cout << "raiz C4 " << aux->getinfo() << endl;
            }

        }else
        {

            leaf = new QuadNode<color>(Color.consultar(i));

            if(aux->getC1() == NULL)
            {
                aux->setC1(leaf);
                cout << "C1 " << aux->getC1()->getinfo() << endl;
            }
            else if (aux->getC2() == NULL)
            {
                aux->setC2(leaf);
                cout << "C2 " << aux->getC2()->getinfo() << endl;
            }
            else if (aux->getC3() == NULL)
            {
                aux->setC3(leaf);
                cout << "C3 " << aux->getC3()->getinfo() << endl;
            }
            else if (aux->getC4() == NULL)
            {
                aux->setC4(leaf);
                cout << "C4 " << aux->getC4()->getinfo() << endl;
            }

            delete leaf;
        }

        if(aux->getC4() != NULL)
             aux = root;
    }

    QT = root;

           cout << "Aqui no sirve deberia imprimir raiz p, c1 e, c2 f, c3 e, c4 p y lo que imprime es:" << endl;
           cout << "Raiz - " << aux->getinfo() << endl;
           cout << "C1 - " << aux->getC1()->getinfo() << endl;
           cout << "C2 - " << aux->getC2()->getinfo() << endl;
           cout << "C3 - " << aux->getC3()->getinfo() << endl;
           cout << "C4 - " << aux->getC4()->getinfo() << endl;
}





Falta arreglar, ya que no se llena bien el imprimir es worthless
template<class color>
void QuadTree<color> :: verQuadTree()
{
    QuadNode<color> *aux, *leaf1;
    bool visitC1, visitC2, visitC3, visitC4;
    int i;

    visitC1 = visitC2 = visitC3 = visitC4 = false;

    cout << "Raiz" << QT->getinfo() << endl;
    aux= QT->getC1();
    cout << "Nodo 1 " << QT->getC1()->getinfo() << endl;
    cout << "Nodo 2 " << QT->getC2()->getinfo() << endl;
    visitC1=true;
     for(i=1;i<=4;i++)
     {
        if(aux != NULL)
          {
            cout << "raiz " << aux->getinfo() << endl;
            leaf1=aux->getC1();
            cout << "nodo 1 " << leaf1->getinfo() << endl;
            cout << "nodo 2 " << aux->getC2()->getinfo() << endl;
            cout << "nodo 3 " << aux->getC3()->getinfo() << endl;
            cout << "nodo 4 " << aux->getC4()->getinfo() << endl;

            if(visitC2 == false)
              {
                cout << "hola" << endl;
                aux = QT->getC2();
                visitC2=true;
            }else if(visitC3 ==false)
            {
                aux = QT->getC3();
                visitC3=true;
            }else if(visitC4 == false)
            {
                aux = QT->getC4();
                visitC4=true;
            }
        }


   }

}
*/

#endif
