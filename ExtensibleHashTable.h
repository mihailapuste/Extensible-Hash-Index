/* File: ExtensibleHashTable.h
* Header file for an extensible in memory hash table.
* Author: Mihai Lapuste
* Email: mlapuste(at)sfu(dot)ca
*/

class ExtensibleHashTable
{
  private:
    int n_buckets;
    int hash_function(int key); // takes an input key as an input, calculates and returns hash index value (int) using global depth.
    bool bucket_exists(int hash_value); // if bucket exists, return true, else return false;
    void create_new_bucket(int key);
    void insert_key(int key);

  public:
    /* Constructors and Destructor */
    ExtensibleHashTable(int b_size = 4); // Constructor, default bucket size is 4 keys. 
    ExtensibleHashTable( const ExtensibleHashTable& tp ); // Copy constructor.
    ~ExtensibleHashTable(); // Destructor.

    /* Insertion/removal functions */
    void insert( int key );
    bool remove( int key ); // searches for key; if found, removes all values & duplicates from table; returns true if the key was found and removed, else false 

    /* Search functions */
    bool find( int key ); // searches table for key; found returns true, else returns false
        
    /* Utility functions */
    void print(); // prints the contents of the directory and buckets; 

    /* Public variables */
    int bucket_size; // size of buckets
    int global_depth;
    void *directory;


};
 
