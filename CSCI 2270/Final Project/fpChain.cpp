#include "fpChain.hpp"
#include <iostream> 

using namespace std; 

HashTable::HashTable(int bsize)
{
    tableSize = bsize;
    for(int i = 0; i < bsize; i++)
    {
        table[i] = NULL; 
    }
}

void HashTable::insertItem(int key)
{
    int i = key % tableSize; 
    
    if (table[i] == NULL)
    {
        head = createNode(key, NULL);
        table[i] = head;
    }

    else
    {
        Node* newNode = createNode(key, NULL);
        Node* temp = table[i];
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    
}

unsigned int HashTable::hashFunction(int key)
{
    return (key % tableSize);
}

int HashTable::searchItem(int key)
{
    int i = key % tableSize;

    if (table[i] == NULL)
    {
        //cout << "NOT FOUND" << endl;
        return -1;
    }
    else
    {
        Node* temp = table[i];
        while (temp != NULL && temp->key != key)
        {
            temp = temp->next; 
        }
        if (temp == NULL)
        {
            return -1;
        }
        else
        {
            return temp->key;
        }
    }
}

void HashTable::printTable()
{
     for(int i = 0; i < tableSize; i++)
     { 
         cout << i << ": ";
         if (table[i] != NULL)
         {
            cout << table[i]->key << " -> ";
            if (table[i]->next != NULL)
            {
                while (table[i]->next != NULL)
                {
                    table[i] = table[i]->next;
                    cout << table[i]->key << " -> ";
                }
            }
         }
         cout << endl;
     }
}