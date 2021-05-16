#include "MovieTree.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

// MovieNode: node struct that will be stored in the MovieTree BST

MovieTree::MovieTree() {
  //write your code
}

MovieTree::~MovieTree() {
  //write your code
}

void movieHelp(MovieNode *Node){
  if(Node){
    movieHelp(Node -> left); 
    cout << "Movie: " << Node -> title << " " << Node -> rating << endl; 
    movieHelp(Node -> right); 
  }
}
void MovieTree::printMovieInventory() {
   //write your code
   if(root == NULL){
     cout << "Tree is Empty. Cannot print" << endl; 
  }
  else{
    movieHelp(root); 
  }
}

void MovieTree::addMovieNode(int ranking, string title, int year, float rating) {
  //write your code
  MovieNode *Node = new MovieNode(ranking, title, year, rating); 
  if(root == NULL){
    root = Node; 
  }

  else{
    MovieNode* temp = root; 
    while(temp != NULL) {
      if(title.compare(temp -> title) < 0){
        if(temp -> left != NULL){
          temp = temp -> left; 
        }
        else{
          temp -> left = Node; 
          temp = NULL; 
        }
      }
      else{
        if(temp -> right != NULL){
          temp = temp -> right; 
        }
        else{
          temp -> right = Node; 
          temp = NULL; 
        }
      }
    }
  }
}

void MovieTree::findMovie(string title) {
  //write your code
  MovieNode *find = root; 

  while(find != NULL){
        if(title.compare(find -> title) < 0){
          find = find -> left; 
        }
    
        else if(title.compare(find -> title) > 0){
          find = find -> right; 
        }
    
        else if(title.compare(find -> title) == 0){
          cout << "Movie Info: " << endl; 
          cout << "==================" << endl; 
          cout << "Ranking:" << find -> ranking << endl; 
          cout << "Title  :" << find -> title << endl; 
          cout << "Year   :" << find -> year << endl; 
          cout << "rating :" << find -> rating << endl; 
          return; 
        }
    }
    cout << "Movie not found." << endl; 
    return; 
}

void helpQuery(MovieNode* m, float rating, int year){
    if(m == NULL){
        return; 
    }
    
    else{
        if((m -> year > year) && (m -> rating >= rating)){
            cout << m -> title << "(" << m-> year << ") " << m -> rating << endl; 
        }
        
        helpQuery(m -> left, rating, year); 
        helpQuery(m -> right, rating, year); 
    }
    return; 
}

void MovieTree::queryMovies(float rating, int year){
    if(root == NULL){
        cout << "Tree is Empty. Cannot query Movies" << endl; 
    }
    
    else{
        cout << "Movies that came out after " << year << " with rating at least " << rating << ":" << endl; 
        helpQuery(root, rating, year); 
    }
}

int size(MovieNode* s){
    int temp = 0; 
    if(s == NULL){
        return 0; 
    }
    
    else{
        temp = (1 + size(s -> left) + size(s -> right)); 
        return temp; 
    }
}

float sum(MovieNode* s){
    float temp = 0.0; 
    if(s == NULL){
        return 0; 
    }
    
    float leftS = sum(s -> left); 
    float rightS = sum (s -> right); 
    
    temp = leftS + rightS + (s -> rating); 
    
    return temp; 
}

void MovieTree::averageRating(){
    if(root == NULL){
        cout << "Average rating:0.0" << endl; 
    }
    
    else{
        int count = size(root); 
        float temp = sum(root); 
        
        cout << "Average rating:" << (temp/count) << endl; 
    }
}

void levNodes(MovieNode* lev, int level){
    if(lev == NULL){
        return; 
    }
    
    if(level == 0){
        cout << "Movie: " << lev -> title << " " << lev -> rating << endl; 
    }
    
    else if(level > 0){
        levNodes(lev -> left, level - 1); 
        levNodes(lev -> right, level -1); 
    }
}
void MovieTree::printLevelNodes(int level)
{
    // Your code here
    if(root != NULL){
        levNodes(root, level); 
    }
}