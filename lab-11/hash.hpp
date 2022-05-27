#ifndef HASH_HPP
#define HASH_HPP

#include <string>


using namespace std;

//node for LL
struct nodeLL{
    int keyLL;
    struct nodeLL* next;
};

//node for BST
/*struct nodeBST{
    int keyBST;
    nodeBST* left ;
    nodeBST* right;
};
*/

class HashTable
{
    int tableSize;  // No. of buckets (linked lists)

    // Pointer to an array containing buckets
    nodeLL* *table1;
    nodeLL* *table2;
    nodeLL* createNodeLL(int key, nodeLL* next);
public:
    HashTable();  // Constructor

    // inserts a key into hash table
    bool insertItem(int key);

    // hash function to map values to key
    unsigned int hashFunction1(int key);
    unsigned int hashFunction2(int key);


    void printTable();

    nodeLL* searchItem(int key);
};

#endif
