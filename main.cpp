#include <cstring>
#include <iostream>
#include <time.h>
#include "ExtensibleHashTable.h"
#include "Bucket.h"

using namespace std;

int main() {

    int a[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13 , 14, 15, 16, 17, 18, 19 ,20, 21, 22, 23, 24, 25, 26, 27, 28};
    int key = 102;
    srand( time(NULL) );

    ExtensibleHashTable * T1 = new ExtensibleHashTable();
   
    for(int i=0; i < 20; i++){
        int random_insertion = (rand() % 100) + 1;
        cout <<random_insertion <<" ";
        T1->insert(random_insertion);
    }

    T1->print();

  

    delete T1;
    return 0;   
}