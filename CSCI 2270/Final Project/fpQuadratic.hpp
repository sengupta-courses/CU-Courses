//Created by Nathan Straub and Pourna Sengupta 
#ifndef FPQUADRATIC_HPP
#define FPQUADRATIC_HPP

#include <string>


using namespace std;

class HashTable
{
    private:
        int tableSize;  // No. of buckets (linked lists)
        int table[40009];
        int numOfcollision = 0;

    public:
        
        HashTable(int bsize);
        bool insert(int key);
        int hashHelper(int key);
        bool search(int key);
        void displayItem(); 
};

#endif