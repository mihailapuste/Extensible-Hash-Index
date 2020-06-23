#include "ExtensibleHashTable.h"
#include <iostream>
#include <iomanip>
#include <cmath>
#include "Bucket.h"

using namespace std;

Bucket *buckets[0];

ExtensibleHashTable::ExtensibleHashTable(int b_size){ // constructor
    bucket_size = b_size;
    global_depth = 1; 
    n_buckets = 0;
}

ExtensibleHashTable::~ExtensibleHashTable(){ // Destructor
  for(int i=0; i < n_buckets; i++){
      buckets[i] -> ~Bucket();
    }
}


void ExtensibleHashTable::insert(int key){ 
    
    if(buckets[hash_function(key)]){

        if(buckets[hash_function(key)]->n_keys == bucket_size){
            cout<< "bucket "<< hash_function(key) << ": is full."<<endl;
            if(buckets[hash_function(key)]->l_depth < global_depth){
                // create_new_bucket(hash_function(key));
                // make new bucket, assign pointer to it, and split bucket, increase local depth ++
            }
            else{
                global_depth++;
                // create_new_bucket(key);
                // insert_key(key);
                return;
                //increase directory size, make new bucket, assign pointer to it, and split bucket, increase local depth ++
            }
        }
        insert_key(key);
        return;
    }
    else {
        create_new_bucket(key);
        insert_key(key);
        return;
    }
    
}

void ExtensibleHashTable::insert_key(int key){
    int hash_value = hash_function(key);
    cout<< "bucket "<< hash_value << ": ";
    buckets[hash_value]->insert(key);
    buckets[hash_value]->print();
}

void ExtensibleHashTable::create_new_bucket(int key){ 
    int hash_value = hash_function(key);
    cout<< "bucket "<< hash_value <<": created" << endl;
    buckets[hash_value] = new Bucket(bucket_size);
    n_buckets++;
}




int ExtensibleHashTable::hash_function(int key){ 
    // key --> [binary] --> [extract bucket value] --> [convert to decimal] --> directory bucket index
    int binary_key[64]; // array of integers representing the binary string of the key
    int hash_value = 0; // final decimal value after refercing global depth
        
    for(int i = 0; key > 0; i++){ // decimal to binary
        binary_key[i] = key%2;  
        key = key/2;  
    }    

    for(int i = 0; i < global_depth; i++){ // binary to decimal referencing global depth
        hash_value += binary_key[i] * pow(2, i);
    }
    
    return hash_value;    

}

