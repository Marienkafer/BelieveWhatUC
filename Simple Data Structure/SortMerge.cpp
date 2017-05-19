#include <iostream>
#include "Lista.h"

using namespace std;

Lista<int> merge( Lista<int> &left,  Lista<int> &right)
{
    Lista<int> result;
    int left_it = 1, right_it = 1;

    while((left_it <= left.longitud()) && (right_it <= right.longitud()))
    {

        if(left.consultar(left_it) < right.consultar(right_it))
        {
            result.insertar( result.longitud()+1, left.consultar(left_it));
            left_it++;
        }
        else
        {

            result.insertar( result.longitud()+1, right.consultar(right_it));
            right_it++;
        }
    }


    while(left_it <= left.longitud())
    {
        result.insertar( result.longitud()+1, left.consultar(left_it));
        left_it++;
    }

    while(right_it <= right.longitud())
    {
        result.insertar( result.longitud()+1, right.consultar(right_it));
        right_it++;
    }

    return result;
}


Lista<int> merge_sort(Lista<int> &vec)
{
    int middle;
    Lista<int> left;
    Lista<int> right;
    int i,j,k;

    if(vec.longitud() == 1)
    {
        return vec;
    }

    middle =(vec.longitud() / 2);



    for(i=1; i<= middle; i++)
    {
        left.insertar(i, vec.consultar(i));
    }

    i=1;
    j=middle;

    while(j != vec.longitud())
    {
        right.insertar(i, vec.consultar(j+1));
        i++;
        j++;
    }

    left = merge_sort(left);
    right = merge_sort(right);

    return merge(left, right);
}

int main()
{
    Lista<int> l, l1, list;
    bool esvacia;
    int a, pos;

    cin >> l;

    cout << "lista: " << l << endl;

    list = merge_sort(l);

    cout << list << endl;



}


