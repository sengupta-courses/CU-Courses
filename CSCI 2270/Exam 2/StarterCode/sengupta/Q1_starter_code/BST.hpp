#ifndef BST_HPP
#define BST_HPP

using namespace std;

struct Node{
    int key;
    Node * parent = nullptr;
    Node* left = nullptr;
    Node* right = nullptr;
};

class BST{

    public:
        // Core public methods:
        BST();                          // default constructor
        // NOTE: DON'T WORRY ABOUT THE DESTRUCTOR METHOD
        void addNode(int data);          // insert a node a new element into tree

        // Extra methods:
        void print2DUtil(int space);
        void decrement();  

    private:
        Node* root;
       
        // Helper functions:    
        //     Since root is a private member we need helper functions
        //     to access the root and traverse the trees recursively.

        Node* addNodeHelper(Node* currNode, int data);
        void printTreeHelper(Node* currNode);

        Node* createNode(int data); 
        Node* getRoot();                // Returns the root of the tree;
                
        void print2DUtilHelper(Node *currNode, int space);

};
#endif
