#include <iostream>
#include "BST.hpp"
using namespace std;

int main (int argc, char* argv[]){
  cout<<"------------Creating tree - test-1------------"<<endl;
  BST tree;
  int numbers[] = {5, 3, 8, 6, 15, 10, 17};
  for(int i = 0; i < 7; i++) {
    tree.addNode(numbers[i]);
  }

  cout << "before decrement " <<endl;
  tree.print2DUtil(1);
  tree.decrement();
  cout << "after decrement " <<endl;
  tree.print2DUtil(1);

  // ------------------ Test case - 1 ----------------------- 
  /* BEFORE:
              5
          /       \
        3           8
                  /   \
                6       15
                       /  \
                      10  17

  */

  /* AFTER run decrement() 1 time
              5
          /       \
        2           8
                  /   \
                5       15
                       /  \
                      9   16

  */
  
  cout<<"------------Creating tree - test-2------------"<<endl;
  BST tree_2;
  int numbers_2[] = {5, 3, 4, 1};
  for(int i = 0; i < 4; i++) {
    tree_2.addNode(numbers_2[i]);
  }

  cout << "before decrement " <<endl;
  tree_2.print2DUtil(1);
  tree_2.decrement();
  tree_2.decrement();
  cout << "after decrement() 2 times " <<endl;
  tree_2.print2DUtil(1);


  // ------------------ Test case - 2 ----------------------- 
  /* BEFORE:
            5
          /       
        3
      /   \
    1       4

  */

  /* AFTER run decrement() 2 times
            5
          /       
        3
      /   
    -1       

  */

  cout<<"------------Creating tree - test-3------------"<<endl;
  BST tree_3;
  int numbers_3[] = {7, 5, 9, 3, 6};
  for(int i = 0; i < 5; i++) {
    tree_3.addNode(numbers_3[i]);
  }

  cout << "before decrement " <<endl;
  tree_3.print2DUtil(1);
  tree_3.decrement();
  tree_3.decrement();
  tree_3.decrement();
  cout << "after decrement() 3 times " <<endl;
  tree_3.print2DUtil(1);

  
  // ------------------ Test case - 3----------------------- 
  /* BEFORE:
            7
          /   \
        5      9
      /   \
    3      6

  */

  /* AFTER run decrement() 3 times
            7
          /       
        5
      /   
    0       

  */

  

  return 0;

}

