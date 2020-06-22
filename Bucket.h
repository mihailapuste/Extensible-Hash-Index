/* File: Bucket.h
* Header file for a Bucket object class.
* Author: Mihai Lapuste
* Email: mlapuste(at)sfu(dot)ca
*/

class Bucket
{
    private:
        int local_depth; 
        int max_n_keys; // the max number of keys in an array - the size of the bucket.
        int *key_array; // pointer to the array of keys.
        int n_keys; // keeps track of number of keys currently in bucket.

    public:

        Bucket(int array_size); // Constructor
        Bucket( const Bucket& bp ); // Copy constructor.
        ~Bucket(); // Destructor
    

        /* Insertion/removal functions */
        void insert( int key );
        bool remove( int key ); 

        /* Search functions */
        bool find( int key ); // searches bucket for key; found returns true, else returns false

        /* Print functions */
        void print();

};