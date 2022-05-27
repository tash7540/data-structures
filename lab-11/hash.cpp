// CPP program to implement hashing with chaining
#include<iostream>
#include "hash.hpp"


using namespace std;

//CHANGE THIS TO BEFORE
nodeLL* HashTable::createNodeLL(int key, node* next)
{
    nodeLL* nw = new nodeLL;
    nw->keyLL = key;
    nw->next = next;
    return nw;
}


HashTable::HashTable(int bsize)
{

    this->tableSize= bsize;
    table = new node*[tableSize];
    for(int i=0;i<bsize;i++)
        table[i] = nullptr;
}

//function to calculate hash function
unsigned int HashTable::hashFunction(int key)
{
    return (key % tableSize);
}

// TODO Complete this function
//function to search
node* HashTable::searchItem(int key)
{
    //Compute the index by using the hash function
    int index = hashFunction(key);
    node* temp = table[index];

    //TODO: Search the list at that specific index and return the node if found
    if( temp !=NULL){
      if(temp->key == key){
        return temp;
      }
      temp = temp->next
    }
    return temp;
}

//TODO Complete this function
//function to insert
bool HashTable::insertItem(int key)
{
    if(!searchItem(key))
    {
        // TODO :
        int index = hashFunction(key);
        // Use the hash function on the key to get the index/slot,
        // create a new node with the key and insert it in this slot's list// how to insert?
        if(table[index] ==NULL){

          table[index] = createNode(key,NULL);
          return true;

        }
        else{
          table[index] = createNode(key, table[index]);
        }

     }
    else{
        cout<<"duplicate entry: "<<key<<endl;
        return false;
    }

}

//TODO Complete this function
// function to display hash table
void HashTable::printTable(){
    for (int i = 0; i < tableSize; i++) {
        cout << i <<"|| ";

        //TODO


    }

 }
