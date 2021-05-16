#include <iostream>
#include <vector>
#include "LinkedList.hpp"

using namespace std;

void process_test(vector<int> in_v, vector<int> out_v, int i);

int main()
{   
    int case_number = 1;

    /* 
        NOTE (Optional): Creating your own testcase

        You can create your own testcases for further testing.
        Copy the following template and fill the test_input, test_output vectors:

            vector<int> test_input  = {};
            vector<int> test_output = {};
            process_test(test_input, test_output, case_number++);
    */

    // TESTCASE 1
    vector<int> i1 = {1,2,5,4,8,3,9,7};
    vector<int> o1 = {2,4,8,1,5,3,9,7};
    process_test(i1, o1, case_number++);

    // TESTCASE 2
    vector<int> i2 = {1,2,3,4,5,6,7,8}; 
    vector<int> o2 = {2,4,6,8,1,3,5,7};
    process_test(i2, o2, case_number++);

    // TESTCASE 3
    vector<int> i3 = {1,3,5}; 
    vector<int> o3 = {1,3,5};
    process_test(i3, o3, case_number++);

    // TESTCASE 4
    vector<int> i4 = {2,4,8}; 
    vector<int> o4 = {2,4,8};
    process_test(i4, o4, case_number++);

    // TESTCASE 5
    vector<int> i5 = {3,0,-1,8,9,4,7,6,10};
    vector<int> o5 = {0,8,4,6,10,3,-1,9,7};
    process_test(i5, o5, case_number++);

    return 0;
}

// NOTE: DO NOT MODIFY!
void process_test(vector<int> in_v, vector<int> out_v, int case_num)
{
    // (Part A): Formatting, setting up the testcase
    cout << "------------[TESTCASE " << case_num << "]------------" << endl;
    LinkedList LL1, LL2;
    string q, r;

    for(int i = 0; i < in_v.size(); i++) {
        LL1.append(in_v.at(i));
        LL2.append(out_v.at(i));
    }

    cout << "INPUT      : "; 
    LL1.print(); cout << endl; 


    // (Part B): Calling the required function
    LL1.moveEvens();


    // (Part C): Displaying test results and decision
    cout << "EXPECTED   : "; 
    r = LL2.print(); cout << endl;

    cout << "USER OUTPUT: "; 
    q = LL1.print(); cout << endl;

    if (q == r) {
        cout << "TESTCASE PASSED!" << endl;
    }
    else {
        cout << "TESTCASE FAILED!" << endl;
    }

    cout << "------------------------------------" << endl << endl;
}