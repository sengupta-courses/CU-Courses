#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <string>
#include <iostream>

using namespace std;

//Node struct that will be stored in the LinkedList
struct Node
{
    //data in specific location of linked list 
    int key; 
    //data to the right of location in linked list 
    Node* next;
};

//class for storing and manipulating linked list of data
class LinkedList
{

    private:
        //pointer to head of linked list of data
        Node* head;

    public:
        //constructor 
        LinkedList()
        {
            head = NULL;
        } 
        //function to find average run time when inserting 100 data variables
        Node* getHead(); 
        void insertList(int key); 
        Node* searchList(int key);
        void displayList(); 
    
};

#endif