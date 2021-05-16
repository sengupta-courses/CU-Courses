#ifndef LLUSPS_HPP
#define LLUSPS_HPP
#include <iostream>

struct Node{
    int key;
    Node* next;
} ;



// class for storing and manipulating tracking numbers
class LLUSPS{
    private:
        // pointer to head of linked-list of countries
        Node* head;
    public:
        // See writeup for method descriptions
        LLUSPS();
        void insert(int);
        bool search(int);
        void display();
};

#endif