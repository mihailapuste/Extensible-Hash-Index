/* File: ExtensibleHashTable.h
* Header file for an extensible in memory hash table.
* Author: Mihai Lapuste
* Email: mlapuste(at)sfu(dot)ca
*/
class ExtensibleHashTable
{
  public:

    /* Constructors and Destructor */
    ExtensibleHashTable(); // Constructor
    ExtensibleHashTable( const ExtensibleHashTable& tp ); // Copy constructor.
    ~ExtensibleHashTable(); // Destructor.

    /* Insertion/removal functions */
    void insert( int record );
    bool remove( int record ); // searches for key; if found, removes all values & duplicates from table; returns true if the key was found and removed, else false 

    /* Search functions */
    bool find( int record ); // searches table for key; found returns true, else returns false
        
    /* Utility functions */
    void print(); // prints the contents of the directory and buckets; 




};