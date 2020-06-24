#include "Bucket.h"
#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

Bucket::Bucket(int max_array_size, int local_depth){ // constructor
    full = false;
    max_n_keys = max_array_size; // set the max array/bucket size.
    key_array = new int[max_n_keys - 1]; // point key_array pointer to newly initialized integer array for bucket.
    for (int i=0; i<max_n_keys; i++) {
        key_array[i] = -1;    // Initialize all elements to -1.
    }
    l_depth = local_depth;
    n_keys = 0;
}

Bucket::~Bucket(){ // destructor
    delete [] key_array;  // Free memory allocated for the key_array.
    key_array = NULL;     // Be sure the deallocated memory isn't used.
}

bool Bucket::insert(int key){
    if(n_keys < max_n_keys){
        for(int i=0; i < max_n_keys; i++){
            if(key_array[i] == -1){ // if empty spot in bucket found.
                key_array[i] = key; // insert key in empty spot.
                if(n_keys < max_n_keys-1) n_keys++;
                else{ full = true; return false;}
                return true;
            }
        }
    } 
    full = true;
    return false;
}

bool Bucket::find(int key){
     for(int i=0; i < n_keys; i++){
         if(key == key_array[i]) return true;
     }
     return false; // if nothing is found, return false
}

bool Bucket::remove(int key){
     if(find(key)){
        for(int i=0; i < max_n_keys; i++){
            if(key == key_array[i]){
                key_array[i] = -1;
                n_keys--;
            }
        }
        return true;
     } 
     else return false; // if nothing is found, return false
}

int Bucket::pop(){
    if(n_keys >=0){
        full = false;
        int pop_value = key_array[n_keys]; // store pop value
        key_array[n_keys] = -1; // clear slot of popped value in array
        if(n_keys > 0) n_keys--; // dont decrement pass 0
        return pop_value; 
    } else return -1; // negative return value means array is empty
}

void Bucket::print_keys(){
    // cout << "max size: " << max_n_keys << endl;
    cout << "[";
    for(int i=0; i < max_n_keys; i++){
        if(key_array[i] < 0) cout << "-";
        else cout << key_array[i];

        if(i < (max_n_keys-1)) {cout << ",";}
    }
    cout << "] (" << l_depth << ")";
}