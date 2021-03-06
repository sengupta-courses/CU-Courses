#include "LinkedList.h"

using namespace std;

// Add a new node to the list
void LinkedList::insert(Node* prev, int newKey){

  //Check if head is Null i.e list is empty
  if(head == NULL){
    head = new Node;
    head->key = newKey;
    head->next = NULL;
  }

  // if list is not empty, look for prev and append our node there
  else if(prev == NULL)
  {
      Node* newNode = new Node;
      newNode->key = newKey;
      newNode->next = head;
      head = newNode;
  }

  else{

      Node* newNode = new Node;
      newNode->key = newKey;
      newNode->next = prev->next;
      prev->next = newNode;

    }
  }


// TODO: SILVER PROBLEM
// Delete node at a particular index
bool LinkedList::deleteAtIndex(int n)
{
  bool isDeleted = false;

  if(head == NULL){
    cout<< "List is already empty"<<endl;
    return isDeleted;
  }

 Node* temp; 

  // Special case to delete the head
    if (n == 0) {
        //TODO
        temp = head; 
        head = head -> next; 
        delete temp; 

        isDeleted = true; 
        return isDeleted; 
    }

  Node *pres = head;
	Node *prev = NULL;

    // TODO
    for(int i = 0; i<n; i++){
      prev = pres; 
      pres = pres -> next; 
    }
    if(pres == NULL){
      cout << "Invlaid" << endl; 
      return isDeleted; 
    }

    prev -> next = pres -> next; 

    free(pres); 

    isDeleted = true; 


	return isDeleted;
}


// TODO: GOLD PROBLEM
// Swap the first and last nodes (don't just swap the values)
bool LinkedList::swapFirstAndLast()
{
    bool isSwapped = false;

    if(head == NULL) {
        cout << "List is empty. Cannot swap" << endl;
        return false;
    }

    // TODO (take care of the edge case when your linkedlist has just 2 nodes)
    // while(pres -> next -> next != NULL){
    //   pres = pres -> next; 
    // }
    // Node* temp; 
    // //secondLast = 1
    // Node* secondLast = temp; 
    // //last = 2 
    // Node* last = secondLast -> next;
    // //temp = 2
    // temp = last;  
    // //last = 1
    // last = secondLast;
    // secondLast = temp;  

    return isSwapped;
}

// Print the keys in your list
void LinkedList::printList(){
  Node* temp = head;

  while(temp->next != NULL){
    cout<< temp->key <<" -> ";
    temp = temp->next;
  }

  cout<<temp->key<<endl;
}

// Search for a specified key and return a pointer to that node
Node* LinkedList::searchList(int key) {

    Node* ptr = head;
    while (ptr != NULL && ptr->key != key)
    {
        ptr = ptr->next;
    }
    return ptr;
}
