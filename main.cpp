#include <cstring>
#include <iostream>
#include "ExtensibleHashTable.h"
#include "Bucket.h"
using namespace std;

int main() {

    int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13 , 14, 15, 16, 17};//, 18, 19 ,20 }; //21, 22, 23, 24, 25, 26, 27, 28};
    int key = 102;

    ExtensibleHashTable * T1 = new ExtensibleHashTable();
   
    for(int i=0; i < (sizeof(a)/sizeof(*a)); i++){
        T1->insert(a[i]);
    }

    T1->print();

  

    delete T1;
    return 0;   
}