#include <cstring>
#include <iostream>
#include "ExtensibleHashTable.h"
#include "Bucket.h"
using namespace std;

int main() {

Bucket * b1 = new Bucket(5, 20);

int a[] = {1202, 102, 232, 102, 102, 12, 19};

int key = 102;

for(int i=0; i < (sizeof(a)/sizeof(*a)); i++){
    b1->insert(a[i]);
}

b1->print();

cout << b1->remove(key) << endl;

b1->print();



delete b1;

return 0;
}