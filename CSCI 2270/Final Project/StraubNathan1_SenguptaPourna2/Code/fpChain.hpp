#ifndef HASH_HPP
#define HASH_HPP

#include <string>


using namespace std;

struct Node
{
    int key;
    Node* next;
};

class HashTable
{
    int tableSize;  // No. of buckets (linked lists)

    // Pointer to an array containing buckets
    Node* table[40009];
    Node* head;
    Node* createNode(int key, Node* next)
    {
        Node* newNode = new Node;
        newNode->key = key;
        newNode->next = next;
    }

    public:
        HashTable(int bsize);  // Constructor

        // inserts a key into hash table
        void insertItem(int key);

        // hash function to map values to key
        unsigned int hashFunction(int key);

        void printTable();

        Node* searchItem(int key);
};

#endif