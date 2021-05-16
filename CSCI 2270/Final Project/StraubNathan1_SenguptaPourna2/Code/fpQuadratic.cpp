//Created by Nathan Straub and Pourna Sengupta 
#include "fpQuadratic.hpp"
#include <iostream> 

using namespace std; 
HashTable::HashTable(int bsize)
{
    //declare variables 
    tableSize = bsize; 
    numOfcollision = 0; 
    //for loop 
    for(int i = 0; i < 40009; i++)
    {
        table[i] = -1; 
    }
}
int HashTable::hashHelper(int key)
{
    //declare variables 
    int i = key % tableSize; 
    int temp = i; 
    int val = 1; 
    //while loop 
    while(table[temp] != -1)
    {
        //update variable temp 
        temp = ((i + (val*val)) % tableSize); 
        //add 1 to val 
        val++; 
        //add 1 to numOfcollision
        numOfcollision++;
    }

    //return temp
    return temp; 
}

bool HashTable::insert(int key){
    //declare variables 
    //call helper function 
    int i = hashHelper(key);
    //set table[i] to key 
    table[i] = key;  
    //return true (has been inserted)
    return true; 
}

bool HashTable::search(int key){
    //declare variables 
    int i = key % tableSize; 
    int temp = i; 
    int val = 1; 

    //while loop 
    while(table[temp] != -1)
    {
        //if value of table[temp] is equal to key 
        if(table[temp] == key)
        {
            //return true (found)
            return true;
        }
        //update value of temp 
        temp = ((i + (val*val)) % tableSize); 
        //add 1 to val 
        val++; 
    }
    //return false 
    return false; 
}

void HashTable::displayItem()
{
    //for loop
    for(int i = 0; i < tableSize; i++)
    {
        //print table 
        cout << table[i] << ", " << endl; 
    }
}