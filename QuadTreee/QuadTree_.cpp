#include "QuadTree.h"
#include <string>
#include<stdlib.h>
#include "Lista.h"
#include <fstream>

int main()
{
    char tree[1000];
    int i, j; i=0; j=1;
    Lista<char> treelist;
    QuadTree<char> QT;
    //bool asd;


    ifstream f("entrada.txt", ifstream::in );
    f >> tree;


    while(tree[i] != '\0')
    {
        treelist.insertar(j, tree[i]);
        i++;
        j++;
    }



    //QT.crear(treelist);
    //cout << QT.Color(QT) << endl;
    // cout << QT.esnulo(QT) << endl;
    // QT.verQuadTree();

}
