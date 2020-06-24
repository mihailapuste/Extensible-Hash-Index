#include <cstring>
#include <iostream>
#include <time.h>
#include <cmath>
#include "ExtensibleHashTable.h"
#include "Bucket.h"

using namespace std;

int main() {

    srand( time(NULL) );
    int N_INSERTIONS = 20;
    int BUCKET_SIZE = 6;
    int searchforkey = 0;

    ExtensibleHashTable * T1 = new ExtensibleHashTable(BUCKET_SIZE);

    cout << endl << "Inserting: " << N_INSERTIONS << " random keys :" << endl;

    for(int i=0; i < N_INSERTIONS; i++){
        int random_insertion = (rand() % 30) + 1;
        T1->insert(random_insertion);
    }

    T1->print();

    cout << "Remove a key: ";
    
    cin >> searchforkey; 

    cout << endl << "Removing: " <<  searchforkey << " ... status " << T1->remove(searchforkey) << endl;

    T1->print();

    delete T1;
    return 0;   
}