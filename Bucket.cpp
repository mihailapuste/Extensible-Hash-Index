#include "Bucket.h"
#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

Bucket::Bucket(int array_size){ // constructor
    max_n_keys = array_size; // set the max array/bucket size.
    key_array = new int[max_n_keys - 1]; // point key_array pointer to newly initialized integer array for bucket.
    for (int i=0; i<max_n_keys; i++) {
        key_array[i] = -1;    // Initialize all elements to -1.
    }
    local_depth = 1;
    n_keys = 0;
}

Bucket::~Bucket(){ // destructor
    delete [] key_array;  // Free memory allocated for the key_array.
    key_array = NULL;     // Be sure the deallocated memory isn't used.
}

void Bucket::insert(int key){
    key_array[n_keys] = key;
    if( ( n_keys + 1 ) > max_n_keys ){
        //  cout << "bucket overflow: " << key << endl;
    }
    else n_keys++;
}

bool Bucket::find(int key){
     for(int i=0; i < n_keys; i++){
         if(key == key_array[i]) return true;
     }
     return false; // if nothing is found, return false
}

void Bucket::print(){
    cout << "max size: " << max_n_keys << endl;
    cout << "[";
    for(int i=0; i < max_n_keys; i++){
        if(key_array[i] < 0) cout << "-";
        else cout << key_array[i];

        if(i < (max_n_keys-1)) {cout << ",";}
    }
    cout << "] (" << local_depth << ')' << endl;
}