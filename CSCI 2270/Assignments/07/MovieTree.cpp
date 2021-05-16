#include <iostream>
#include <fstream>
#include "MovieTree.hpp"

using namespace std;
MovieTree::MovieTree()
{
    //constructor 
    //set root to NULL
	root = NULL;
}

void destroyTree(TreeNode* &Node){
    //if Node is inputted
    if(Node){
        //traverse left and call helper function 
        destroyTree(Node -> leftChild); 

        //traverse right and call helper function 
        destroyTree(Node -> rightChild); 

        LLMovieNode *temp; 
        while(Node -> head != NULL){
            temp = Node -> head; 
            Node -> head = Node -> head -> next; 
            delete temp; 
        }
        delete(Node);  
    }
}

MovieTree::~MovieTree()
{
    //destructor 
    //call helper function
    destroyTree(root); 
}

//helper functions
void printHelper(LLMovieNode* head){
    LLMovieNode* movie = head; 
    while(movie != NULL){
        cout << " >> " << movie -> title << " " << movie -> rating << endl; 
        movie = movie -> next; 
    }
    // destroyMovie(movie); 
}

void printOrderHelper(TreeNode* node){
    if(node == NULL){
        //return and exit function 
        return; 
    }
    //call helper function 
    printOrderHelper(node -> leftChild); 

    if(node -> head != NULL){
        cout << "Movies starting with letter: " << node -> titleChar << endl; 
        //call helper function 
        printHelper(node -> head); 
    }
    //call helper function 
    printOrderHelper(node -> rightChild); 
}

LLMovieNode* searchHelper(string value, LLMovieNode* head){
    LLMovieNode* temp = head; 
    LLMovieNode* tempNode = NULL; 

    while(temp !=NULL){
        if(value.compare(temp -> title) > 0){
            tempNode = temp; 
        }
        temp = temp -> next; 
    }
    // destroyMovie(temp); 
    // destroyMovie(tempNode); 
    return tempNode; 
}

void addHelper(LLMovieNode* &head, int ranking, string title, int year, float rating){
    //intialize variables
    //set temporary variable equal to new struct 
    LLMovieNode *temp = new LLMovieNode(ranking, title, year, rating); 
    //call helperfunction 
    LLMovieNode *node = searchHelper(title, head); 

    if(node == NULL){
        temp -> next = head; 
        head = temp; 
    }

    else if(node -> next == NULL){
        node -> next = temp;   
    }

    else{
        temp -> next = node -> next; 
        node -> next = temp;
    }
    // destroyMovie(temp); 
    // destroyMovie(node); 
}

TreeNode* deleteHelper(TreeNode* nodeTree, string title){
    //if treeNode is NULL
    if(nodeTree == NULL){
        //print phrase 
        cout << "Movie: " << title << " not found, cannot delete." << endl; 
        //return and exit 
        return nodeTree; 
    }

    //if first char of title is less than titleChar of nodeTree 
    if(title.at(0) < nodeTree -> titleChar){
        //set left of nodeTree to helper function value 
        nodeTree -> leftChild = deleteHelper(nodeTree -> leftChild, title);
    }

    //else if first char of title is greater than titlChar of nodeTree 
    else if(title.at(0) > nodeTree -> titleChar){
        //set right of nodeTree to helper function value 
        nodeTree -> rightChild = deleteHelper(nodeTree -> rightChild, title); 
    }

    //else if first char of title is equal to titleChar of nodeTree 
    else if(title.at(0) == nodeTree -> titleChar){
        LLMovieNode* current = nodeTree -> head; 
        LLMovieNode* previous = NULL; 

        //while current is not null and compare to title is not 0 
        while(current != NULL && current -> title.compare(title) != 0){
            //set previous to current 
            previous = current; 
            //set current to next of current 
            current = current -> next; 
        }

        //if the current is NULL 
        if(current == NULL){
            //print phrase 
            cout << "Movie: " << title << " not found, cannot delete." << endl; 
            //return and exit 
            return nodeTree; 
        }

        //if previous is NULL and if next of head of nodeTree is not NULL
        if(previous == NULL && nodeTree -> head -> next != NULL){
            //set nodeTree head to next of head of nodeTree
            nodeTree -> head = nodeTree -> head -> next; 
            //return and exit 
            return nodeTree; 
        }

        //if current is not null and previous is not null 
        if(current != NULL && previous != NULL){
            //next of previous is next of current 
            previous -> next = current -> next; 
            //return and exit 
            return nodeTree; 
        }

        //if left and right of nodeTree are null 
        if(nodeTree -> leftChild == NULL && nodeTree -> rightChild == NULL){
            //delete nodeTree 
            delete nodeTree; 
            //set nodeTree to NULL 
            nodeTree = NULL; 
        }

        //else if only the left of nodeTree is NULL 
        else if(nodeTree -> leftChild == NULL){
            TreeNode *temp = nodeTree; 
            //set right parent of nodeTree to parent of nodeTree 
            nodeTree -> rightChild -> parent = nodeTree -> parent; 
            //set nodeTree to right of nodeTree 
            nodeTree = nodeTree -> rightChild; 
            //delete temp 
            delete temp; 
        }

        //else if only the right of nodeTree is NULL 
        else if(nodeTree -> rightChild == NULL){
            TreeNode *temp = nodeTree; 
            //set left parent of nodeTree to parent of nodeTree 
            nodeTree -> leftChild -> parent = nodeTree -> parent; 
            //set nodeTree to left of nodeTree 
            nodeTree = nodeTree -> leftChild; 
            //delete temp 
            delete temp; 
        }

        //else, if neither are NULL 
        else{
            TreeNode* tempNode = nodeTree -> rightChild; 
            //while left of tempNode is not null 
            while(tempNode -> leftChild != NULL){
                //set tempNode to left of tempNode 
                tempNode = tempNode -> leftChild; 
            }
            //set nodeTree head to head of tempNode 
            nodeTree -> head = tempNode -> head; 
            //set nodeTree titleChar to titleChar of tempNode 
            nodeTree -> titleChar = tempNode -> titleChar; 
            //set right of nodeTree to delete helper function 
            nodeTree -> rightChild = deleteHelper(nodeTree -> rightChild, tempNode -> head -> title);
        }
    }
    // destroyMovie(current); 
    // destroyMovie(previous); 
    //return and exit 
    return nodeTree; 
}

/* ------------------------------------------------------ */


void MovieTree::printMovieInventory()
{
    //call helper function 
    printOrderHelper(root); 
}


void MovieTree::addMovie(int ranking, string title, int year, float rating)
{
    //new variable char key, equal to 0 index of title array 
    char key = title[0]; 
    TreeNode *temp = root; 
    TreeNode *parent = temp; 

    //while loop 
    while(temp != NULL){
        //set parent equal to temp 
        parent = temp; 
        //if the key is the same at the titleChar of temp 
        if(key == temp -> titleChar){
            //call helper function 
            addHelper(temp -> head, ranking, title, year, rating); 
            //return and exit function 
            return; 
        }

        //else if the key is less than the titleChar of temp 
        else if(key < temp -> titleChar){
            //set temp equal to the left node of temp 
            temp = temp -> leftChild; 
        }

        else{
            //set temp equal to the right node of temp 
            temp = temp -> rightChild; 
        }
    }

    TreeNode *tempNode = new TreeNode; 
    //set tempNodes titleChar to key 
    tempNode -> titleChar = key; 

    //if parent is null 
    if(parent == NULL){
        //set root equal to tempNode
        root = tempNode; 
    }

    //else if the key is less than the parents titleChar 
    else if(key < parent -> titleChar){
        //set left node of parent equal to tempNode 
        parent -> leftChild = tempNode; 
        //set parent of tempNode to parent 
        tempNode -> parent = parent; 
    }

    else{
        //set right node of parent equal to tempNode
        parent -> rightChild = tempNode; 
        //set parent of tempNode to parent 
        tempNode -> parent = parent; 
    }

    //call helper function 
    addHelper(tempNode -> head, ranking, title, year, rating); 
    // destroyTree(temp); 
    // destroyTree(parent); 
    // destroyTree(tempNode); 
}

void MovieTree::deleteMovie(std::string title)
{
    //set root to helper function value 
    root = deleteHelper(root, title);
}

void MovieTree::leftRotation(TreeNode* curr)
{
    TreeNode *temp = curr -> rightChild; 
    //right of curr equals left of temp 
    curr -> rightChild = temp -> leftChild; 
    //if left of temp is not NULL 
    if(temp -> leftChild != NULL){
        //left parent of temp equals curr 
        temp -> leftChild -> parent = curr; 
    }

    //temp parent is curr parent 
    temp -> parent = curr -> parent; 

    //if curr parent is null
    if(curr -> parent == NULL){
        //set root equal to temp 
        root = temp; 
    }

    //else if curr is equal to the parent left of curr
    else if(curr == curr -> parent -> leftChild){
        //set curr parent left to temp
        curr -> parent -> leftChild = temp; 
    }

    else{
        //set curr parent right to temp 
        curr -> parent -> rightChild = temp; 
    }

    //set tmep left to curr 
    temp -> leftChild = curr; 
    //set curr parent to temp 
    curr -> parent = temp; 
    // destroyTree(temp); 
}

//------ Given Methods--------//
void _grader_inorderTraversal(TreeNode * root)
{
	if (root == NULL) {
		return;
	}

	_grader_inorderTraversal(root->leftChild);
	cout << root->titleChar << " ";
	_grader_inorderTraversal(root->rightChild);
}


void MovieTree::inorderTraversal() {
	_grader_inorderTraversal(root);
	cout << endl;
}



TreeNode* searchCharHelper(TreeNode* curr, char key)
{
    if (curr == NULL)
        return curr;
    else if(curr->titleChar == key)
        return curr;
    else if (curr->titleChar > key)
        return searchCharHelper(curr->leftChild, key);
    else
        return searchCharHelper(curr->rightChild, key);
}

TreeNode* MovieTree::searchChar(char key)
{
    return searchCharHelper(root, key);
}

