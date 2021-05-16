//Created by Nathan Straub and Pourna Sengupta 
#ifndef FPHASH_HPP
#define FPHASH_HPP

#include <string>


using namespace std;

class HashTable
{
    private:
        int tableSize;
        int table[40009];
        int numOfcolision = 0;

    public:
        HashTable(int bsize);  // Constructor
        bool insert(int key);
        int hashHelper(int key);
        bool search(int key);
        void displayTable();
};

#endif