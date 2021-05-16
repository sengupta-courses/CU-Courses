#include "LLUSPS.hpp"
#include <fstream>
#include <iostream>

using namespace std;

//constructor sets head to NULL
LLUSPS::LLUSPS(){
    head = NULL;
}

//insert method takes a number to insert
void LLUSPS::insert(int trackingNum){
    // if we are passed an empty list, just create a new head node, and return
    if (head == NULL)
    {
        head = new Node;
        head->key = trackingNum;
        head->next = NULL;
        return;
    }

    // if it's not empty, we need to search for previous and append our node there.
    Node* previous = head;
    //while the prev->next is not NULL and prev->next->key is not one we want
    while(previous->next!=NULL && previous->next->key < trackingNum){
        //progress through the linked list
        previous = previous->next;
    }

    //once we have the previous node we can check if it should be the new head
    if(previous == NULL )
    {
        //case where it's a new head
        Node* c = new Node;
        c->key = trackingNum;
        c->next = head;
        head = c;
    //if it is not the new head it is inserted
    }else{
        Node* newTracking = new Node;
        newTracking->key = trackingNum;
        newTracking->next = previous->next;
        previous->next = newTracking;
    }
}

//search method takes in a tracking number to search for and returns a pointer to its node
bool LLUSPS::search(int trackingNum){
    // Search until the head is NULL, or we find the trackingNum
    Node* crawler = head;
    //while the crawler isnt NULL and not the tracking number
    while (crawler != NULL && crawler->key != trackingNum)
    {   
        //progress through crawlers
        crawler = crawler->next;
    }
    
    // Return with message if not found and without if found
    if(crawler != NULL){
        //cout<<"Tracking number found! YAY!"<<endl;
        return true;
    }else{
        //cout<<"Tracking number not found. SORRY."<<endl;
        return false;
    }
}

//display method will print all of the tracking numbers
void LLUSPS::display(){
    //start at the head
    Node* crawler = head;
    //go through entire LL
    while(crawler != NULL){
        //print the number and ->
        cout<<crawler->key<<" -> ";
        //advance the crawler
        crawler = crawler->next;
    }
}