#include <cstring>
#include <iostream>
#include "ExtensibleHashTable.h"
#include "Bucket.h"
using namespace std;

int main() {

    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int key = 102;

    ExtensibleHashTable * T1 = new ExtensibleHashTable();

    for(int i=0; i < (sizeof(a)/sizeof(*a)); i++){
        T1->insert(a[i]);
    }


    delete T1;
    return 0;   
}