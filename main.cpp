#include <cstring>
#include <iostream>
#include "ExtensibleHashTable.h"
#include "Bucket.h"
using namespace std;

int main() {

Bucket * b1 = new Bucket(5);

int a[] = {102, 223, 13, 182, 990, 12, 19};

int searchfor = 12;

for(int i=0; i < (sizeof(a)/sizeof(*a)); i++){
    b1->insert(a[i]);
}

b1->print();

cout << b1->find(searchfor) << endl;


delete b1;

return 0;
}