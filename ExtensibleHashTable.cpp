#include "ExtensibleHashTable.h"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring>
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


void ExtensibleHashTable::insert(int key , int local_depth){ 
    
    int scenario = insertion_scenario(key);

    cout << "scenario "<< scenario << ": key: "<< key << " -> ["<<hash_function(key)<<"]"<<endl;
    
    switch (scenario) {
        case 0: /* SCENARIO [0]: No bucket found for hash value */
            
            // create a new bucket using at index of hash value.
            cout << endl <<  "--CREATING BUCKET [" << hash_function(key) << "] WITH LOCAL DEPTH: ["<<local_depth<<"]--"<< endl;
            create_new_bucket(key, local_depth);
            insert_key(key);
            break; 

        case 1: /* SCENARIO [1]: Bucket exists and NOT full. */

            // insert key in bucket found.
            insert_key(key);
            break;

        case 2: /* SCENARIO [2]: Local depth is less than global depth. */

            // split bucket without increasing directory size.
            cout << endl << "--SPLITTING BUCKET [" << hash_function(key) << "]--"<< endl;
            split_buckets(key);
            break;

        case 3: /* SCENARIO [3]: Local depth is equal to global depth. */

            // increase size of directory & global depth, and split bucket.
            cout << endl <<  "--SPLITTING BUCKET [" << hash_function(key) << "]--"<< endl;
            global_depth++;
            split_buckets(key);
            break;

    }
  
    return;

}

void ExtensibleHashTable::split_buckets(int key){
    
    int hash_value = hash_function(key);
    int insertion_values[bucket_size];
    
    buckets[hash_value]->l_depth++;
    int local_depth = buckets[hash_value]->l_depth;
 
    for(int i = 0; i < bucket_size; i++){
         insertion_values[i] = buckets[hash_value]->pop();
    }

    for(int i = 0; i < (bucket_size-1); i++){
        insert(insertion_values[i], local_depth);
    }
    insert(insertion_values[bucket_size-1], local_depth);
    insert(key, local_depth);

}

int ExtensibleHashTable::insertion_scenario(int key){
    int hash_value = hash_function(key);

    /* SCENARIO [1]: Bucket exists and NOT full. */
    if(buckets[hash_value] && !buckets[hash_function(key)]->full){ 
        return 1; // insert key in bucket found.
    }

    /* Bucket exists and FULL. */
    if(buckets[hash_value] && buckets[hash_function(key)]->full){
    
        /* SCENARIO [2]: Local depth is less than global depth. */
        if(buckets[hash_value]->l_depth < global_depth ){
            return 2; // split bucket without increasing directory size.
        }
        /* SCENARIO [3]: Local depth is equal to global depth. */
        else{
            return 3; // increase size of directory, and split bucket.
        }

    }
    
    /* SCENARIO [0]: No bucket found for hash value */
    return 0; // create a new bucket using at index of hash value.
    
}


void ExtensibleHashTable::insert_key(int key){
    int hash_value = hash_function(key);
    buckets[hash_value]->insert(key);
}

void ExtensibleHashTable::create_new_bucket(int key, int local_depth){ 
    int hash_value = hash_function(key);
    buckets[hash_value] = new Bucket(bucket_size,local_depth );
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



void ExtensibleHashTable::print(){ 
    cout << endl;
    for(int i=0; i < pow(2, global_depth); i++){
      cout << i << ": " << buckets[i] << " --> ";
      buckets[i]->print_keys();
      cout << endl;
    }
}