//Created by Nathan Straub and Pourna Sengupta 
#ifndef fpBST_HPP
#define fpBST_HPP

using namespace std;

struct Node
{
    int key;
    Node* left ;
    Node* right;
};

class BST
{
    private:
        Node* root;
        Node* createNode(int data);
        Node* insertHelper(Node*, int);
        void displayTreeHelper(Node*);
        Node* searchHelper(Node*, int);

    public:
        Node* getRoot();
        void insert(int);
        bool search(int);
        void displayTree();
        BST();
        BST(int data);
};
#endif
