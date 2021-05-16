#include <iostream>
#include "LinkedList.hpp"

using namespace std;

/* ----------------------------------------
TODO: Complete the method below.
      You may add helpers, headers (if necessary)
      Helper functions should not be part of the class.
*/

void LinkedList::moveEvens()
{
    // YOUR CODE HERE
    //declare variables 
    Node *end = head; 
    Node *previous = NULL; 
    Node *current = head; 
    Node *final = NULL; 

    //while loop 
    while(end -> next != NULL){
        end = end -> next; 
    }

    final = end; 

    //while loop
    //if even and not the last ndoe 
    while(current -> key % 2 != 0 && current != end){
        //move to the next node 
        final -> next = current; 
        current = current -> next; 
        //move to next node
        final -> next -> next = NULL; 
        final = final -> next; 
    }

    //for even nodes 
    //reorder even nodes 
    if(current -> key % 2 == 0){
        //set head equal to current 
        head = current; 

        //while loop 
        while(current != end){
            //traverse the list 
            //if even 
            if((current -> key) % 2 == 0){
                previous = current; 
                current = current -> next; 
            }
            //else
            else{
                previous -> next = current -> next; 
                current -> next = NULL; 
                final -> next = current; 
                final = current; 
                current = previous -> next; 
            }
        }
    }

    else{
        previous = current;
    }
    //if not at the end of the list and odd
    if(final != end && (end -> key) % 2 != 0){
        previous -> next = end -> next; 
        end -> next = NULL; 
        final -> next = end; 
    }
    return;
}

// ----------------------------------------

LinkedList::LinkedList()
{
    head = nullptr;
}


LinkedList::~LinkedList()
{
    Node* temp = head;
    while(head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}


void LinkedList::append(int key)
{
    // Function: Creates and inserts a new node at the END of list
    Node* newNode = new Node({key, nullptr});
    if (!head) {
        head = newNode;
    }
    else {
        Node* temp = head;
        while(temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}


string LinkedList::print()
{
    // Returns the same output as string for testcase verification
    Node* temp = head;
    string s = "";
    while(temp) {
        s = s + to_string(temp->key) + " -> ";
        temp = temp->next;
    }
    s = s + "NULL\n";

    cout << s;
    return s;
}