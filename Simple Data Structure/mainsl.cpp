#include <iostream>
#include "Lista.h"


int main()
{
   Lista<int> list, slist;
   
   cin >> list;
   cin >> slist;
   
   
   cout << list.essublista( slist) << endl;
return 0;
}
