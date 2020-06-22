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


private:
    // Deque Node Class
    class node  // node type for the linked list
    {
    public:
        node(int new_data, node * prev_node, node * next_node ){
            data = new_data ;
            prev = prev_node ;
            next = next_node ;
        }

        int data ;
        node * prev ;// pointer to pevious node, or NULL.
        node * next ;// pointer to next node, or NULL.
    };

    /* Instance Variables */
    node * left_p ; // Points to left end node, or NULL if Deque is empty.
    node * rear_p ; // Points to right end node, or NULL if Deque is empty.
    int current_size ; // current number of elements in the queue.
    node * cursor ; // pointer to "current" node (or NULL if deque is empty).

};