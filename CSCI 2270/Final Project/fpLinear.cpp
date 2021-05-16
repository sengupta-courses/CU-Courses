//Created by Nathan Straub and Pourna Sengupta 
#include "fpLinear.hpp"
#include <iostream> 

using namespace std; 
HashTable::HashTable(int bsize){
    //declare variables 
    tableSize = bsize; 
    numOfcolision = 0; 
    //for loop
    for(int i = 0; i < 40009; i++)
    {
        table[i] = -1; 
    }
}

int HashTable::hashHelper(int key)
{
    //declare variable 
    int i = key % tableSize; 
    //while loop 
    while(table[i] != -1)
    {
        //add 1 to collissions 
        numOfcolision++; 
        //update i value 
        i = (i + 1) % tableSize; 
    }
    //return index
    return i; 
}

bool HashTable::insert(int key)
{
    //declare variables 
    //call helper function 
    int i = hashHelper(key); 
    //set value of table[i]
    table[i] = key; 
    //return true (item has been inserted)
    return true; 
}
bool HashTable::search(int key)
{
    //declare variables 
    int i = key % tableSize; 
    //while loop 
    while(table[i] != -1)
    {
        //find indice 
        if(table[i] == key)
        {
            //return true when found 
            return true; 
        }
        //update value of i 
        i = (i + 1) % tableSize; 
    }
    //return false 
    return false; 
}

void HashTable::displayTable()
{
    //for loop 
     for(int i = 0; i < tableSize; i++)
     {
         //print the table array 
         cout << table[i] << endl; 
     }
}