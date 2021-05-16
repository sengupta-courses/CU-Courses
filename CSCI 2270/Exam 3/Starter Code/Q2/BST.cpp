#include "BST.hpp"
#include <iostream>

using namespace std;

//Helper Functions 

void checkHelper(Node* n, int h, int key, int o){
    //if n is NULL
    if(n == NULL){
        //return
        return;
    }
    //if the height is 1
    if(h == 1 && n -> key == key){
        cout << o - 1 << " "; 
    }
    //if the height is larger than 1 
    else if(h > 1){
        //call function for right and left nodes 
        checkHelper(n -> left, h - 1, key, o); 
        checkHelper(n -> right, h -1, key, o); 
    }
}


int heightHelper(Node* n){
    //if n is NULL
    if(n == NULL){
        return 0; 
    }
    else{
        //declare variable 
        int left = 1; 
        //change value of left height by calling function 
        left += heightHelper(n -> left); 

        //declare variable 
        int right = 1; 
        //change value of right height by calling function 
        right += heightHelper(n -> right); 

        //compare left and right heighy 
        if(left > right){
            return (left + 1); 
        }
        //if right height is larger 
        else{
            return (right + 1); 
        }
    }
}

void orderHelper(Node* n, int key){
    int h = heightHelper(n); 
    for(int i = 1; i < h; ++i){
        checkHelper(n, i, key, i);
    }

/* ----------------------------------------
TODO: Complete the method below.
      You may add helpers, headers (if necessary)
      Helper functions should not be part of the class.
*/

void BST::print_depths(int val)
{
    // YOUR CODE HERE
    orderHelper(root, val); 
    return;
}

// ----------------------------------------

BST::BST()
{
    root = nullptr;
}

BST::~BST()
{
    recursive_destroy(root);
    root = nullptr;
}

void BST::print()
{
    print2DUtil(root);
}

void BST::insert(int val)
{
    root = recursive_insert(root, val);
}


Node* BST::search(int val)
{
    return recursive_search(root, val);
}


void BST::inorder()
{
    recursive_inorder(root);
}

// ----------------- 
// RECURSIVE HELPERS 
// ----------------- 
void recursive_destroy(Node* n)
{
    if (n) {
        recursive_destroy(n->left);
        recursive_destroy(n->right);
        delete n;
    }

}

Node* recursive_insert(Node* n, int val)
{
    if (n == nullptr) {
        Node* tmp = new Node({val, nullptr, nullptr});
        return tmp;
    }
    else if (val >= n->key) {
        n->right = recursive_insert(n->right, val);
    }
    else {
        n->left = recursive_insert(n->left, val);
    }

    return n;
}

Node* recursive_search(Node* n, int val)
{
    if (!n) {
        return nullptr;
    }

    if (val == n->key) {
        return n;
    }
    else if (val > n->key) {
        return recursive_search(n->right, val);
    }
    else {
        return recursive_search(n->left, val);
    }
}

void recursive_inorder(Node* n)
{
    if (n) {
        recursive_inorder(n->left);
        cout << n->key << " ";
        recursive_inorder(n->right);
    }
}

void print2DUtil(Node *n, int space, int COUNT)  
{  
    if (n == NULL)  
        return;  
  
    space += COUNT;  
    
    print2DUtil(n->right, space);  
    cout<<endl;  
    for (int i = COUNT; i < space; i++)  
        cout<<" ";  
    cout<<n->key<<"\n";  
  
    print2DUtil(n->left, space);  
}  