#include "fpList.hpp"
#include <string>
#include <iostream>

using namespace std;

Node* LinkedList::getHead()
{
    return head;
}

void LinkedList::insertList(int key)
{
    if(head == NULL)
    {
        head = new Node;
        head->key = key;
        head->next = NULL;
    }
    else
    {
        Node* newNode = new Node;
        newNode->key = key;
        Node* temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = NULL;
    }
}

Node* LinkedList::searchList(int key)
{
    Node* currNode = head;
    while (currNode != NULL && currNode->key != key)
    {
        currNode = currNode->next;
    }
    return currNode;
}

void LinkedList::displayList()
{
    Node* temp = head;

    while(temp->next != NULL)
    {
        cout << temp->key << " -> ";
        temp = temp->next;
    }

    cout<<temp->key<<endl;

}