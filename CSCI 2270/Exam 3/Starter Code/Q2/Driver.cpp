#include <iostream>
#include <vector>
#include "BST.hpp"

using namespace std;

void process_testcase(vector<int> tree_arr, int val, string expected = "", bool print_tree = true);

int main()
{

    /* 
        NOTE (1): Output verification not available for custom testcases. To be traced by the student.
        NOTE (2): print() method prints the rotated tree (90 degree ant-clockwise)
        NOTE (3): Creating your own testcase
            You can create your own testcases for further testing.
            Order of test_input vector represents the BST insertion order.
            Copy the following template and fill the test_input vector and val.

                int val = 10;                               // number to search
                string expected = "";                       // expected output as string (no validation)
                vector<int> test_input  = {};               // to generate the tree
                process_test(test_input, val);              // 3rd arg (optional); 4th arg (optional), print_tree (default: true)
            

    */

    // TESTCASE 1 
    int input = 15; string result = "1,2";
    vector<int> tree1 = {20,15,15,10,8,13,12,13,30,25,30,24,25,30};  // inserts node in the tree (in this order)
    process_testcase(tree1, input, result, true);

    // TESTCASE 2
    input = 30; result = "1,2,3";
    process_testcase(tree1, input, result, false);

    // TESTCASE 3
    input = 44; result = "";
    process_testcase(tree1, input, result, false);

    // TESTCASE 4
    input = 13; result = "3,4";
    process_testcase(tree1, input, result, false);


    return 0;
}

void process_testcase(vector<int> tree_arr, int val, string expected, bool print_tree)
{
    cout << "------------[TESTCASE]------------" << endl;

    // Part A: Construct the tree, formatting
    BST t; 
    for(int i = 0; i < tree_arr.size(); i++){
        t.insert(tree_arr.at(i));
    }

    cout << endl << "INPUT   : "; t.inorder(); cout << endl;
    if(print_tree) {
        t.print();
    }
    cout << endl;

    // Part B: Call the required function
    cout << ">> print_depths(" << val << ")" << endl << endl << "OUTPUT  :";

    t.print_depths(val);

    cout << endl << "EXPECTED: " << expected << endl;

    cout << endl << "------------------------------------" << endl << endl;

}

/*
Tree t as declared above:

                    ┌─────┐
               ┌────┤ 20  ├─────────────────────────────┐
               │    └─────┘                             │
            ┌──┴──┐                                  ┌──┴──┐
          ┌─┤ 15  ├───────────────┐               ┌──┤ 30  ├────────────┐
          │ └─────┘               │               │  └─────┘            │
       ┌──┴──┐                 ┌──┴──┐         ┌──┴──┐               ┌──┴──┐
  ┌────┤ 10  ├────┐            │ 15  │       ┌─┤ 25  ├──┐            | 30  ├──┐
  │    └─────┘    │            └─────┘       │ └─────┘  │            └─────┘  │
┌─┴──┐         ┌──┴──┐                    ┌──┴──┐    ┌──┴──┐               ┌──┴──┐
│ 8  │      ┌──┤ 13  ├─┐                  │ 24  │    │ 25  │               │ 30  │
└────┘      │  └─────┘ │                  └─────┘    └─────┘               └─────┘
          ┌─┴──┐    ┌──┴──┐
          │ 12 │    │ 13  │
          └────┘    └─────┘

*/