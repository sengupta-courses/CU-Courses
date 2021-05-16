//Created by Nathan Straub and Pourna Sengupta 

#include <iostream>
#include "fpBST.hpp"
using namespace std;
#define COUNT 10

Node* BST:: createNode(int data)
{
    Node* newNode = new Node;
    newNode->key = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

BST::BST()
{

}

BST::BST(int data)
{
    root = createNode(data);
}

Node* BST::getRoot()
{
    return root;
}

Node* BST:: insertHelper(Node* currNode, int data)
{
    if(currNode == NULL){
        return createNode(data);
    }
    else if(currNode->key < data){
        currNode->right = insertHelper(currNode->right,data);
    }
    else if(currNode->key > data){
        currNode->left = insertHelper(currNode->left,data);
    }
    return currNode;

}

void BST:: insert(int data)
{
    root = insertHelper(root, data);
}

void BST:: displayTreeHelper(Node* currNode)
{
     if(currNode)
     {
        displayTreeHelper(currNode->left);
        cout << " "<< currNode->key;
        displayTreeHelper(currNode->right);
     }
 }

void BST:: displayTree()
{
     displayTreeHelper(root);
     cout<<endl;
}

Node* BST::searchHelper(Node* currNode, int data)
{
    if(currNode == NULL)
        return NULL;

    if(currNode->key == data)
        return currNode;

    if(currNode->key > data)
        return searchHelper(currNode->left, data);

    return searchHelper (currNode->right, data);
}

bool BST::search(int key)
{
    Node* tree = searchHelper(root, key);
    if(tree != NULL) 
    {
        return true;
    }
    cout << "Key not present in the tree" << endl;
    return false;
}