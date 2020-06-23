/* File: Bucket.h
* Header file for a Bucket object class.
* Author: Mihai Lapuste
* Email: mlapuste(at)sfu(dot)ca
*/

class Bucket
{
   

    public:
        Bucket() {}; // default constructor
        Bucket(int max_array_size, int local_depth=1); // Constructor
        // Bucket( const Bucket& bp ); // Copy constructor.
        ~Bucket(); // Destructor
    
        /* Insertion/removal functions */
        bool insert( int key );
        bool remove( int key ); 

        /* Search functions */
        bool find( int key ); // searches bucket for key; found returns true, else returns false

        /* Print functions */
        void print();

        /* Public variables */
        int l_depth; // local depth
        bool full;
        int n_keys; // keeps track of number of keys currently in bucket.

    private:

        /* Private variables */
        int *key_array; // pointer to the array of keys.
        int max_n_keys; // the max number of keys in an array - the size of the bucket.
        
};