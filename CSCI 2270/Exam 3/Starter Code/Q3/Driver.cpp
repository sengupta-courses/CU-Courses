#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "Graph.hpp"

using namespace std;

void process_testcase(vector<string> edgelist, string node, int distance, string expected = "");

int main()
{
    /* 
        NOTE (1): Verification not provided for custom testcases. To be traced by the student.
        NOTE (2): display() method prints the Graph's adjacency list.
        NOTE (3): Creating your own testcase
            You can create your own testcases for further testing.
            Order of test_input vector represents the BST insertion order.
            Copy the following template and fill test_edgelist, node and distance.

                vector<string> test_edgelist = {};                  // an edge is a pair of node values (comma-separated)
                string node;                                        // node in vertexAtDepth(node, distance);
                int distance;                                       // distance in vertexAtDepth(node, distance);
                process_testcase(test_edgelist, node, distance)     // will call vertexAtDepth(node, distance);
        
        NOTE (4): An edge is represented by a comma-separated string (example below).
                  To insert singleton nodes, put the node string without commas; Avoid trailing/leading spaces in node values.
            
            The edge list {"A,C", "C,D", "B,D", "B,E", "F"} results in the following graph:

                    A     B --- E
                    |     |
                    C --- D     F
    */


    /*
        A -- B -- E
        | \  |  /
        |  \ | /
        C -- D    F
    */

    // TESTCASE 1 
    vector<string> test_list = {"A,B", "A,C", "A,D", "B,D", "B,E", "D,E", "F"};     
    string node = "A"; int dist = 0; 
    string expected = "A"; 
    process_testcase(test_list, node, dist, expected);  // Will call vertexAtDepth("A", 0);


    // TESTCASE 2
    node = "A"; dist = 1;
    expected = "B,C,D";
    process_testcase(test_list, "A", 1, expected);  // Will call vertexAtDepth("A", 1);


    // TESTCASE 3
    node = "A"; dist = 3;
    expected = "";
    process_testcase(test_list, node, dist, expected);  // Will call vertexAtDepth("A", 3);


    // TESTCASE 4
    test_list = {"A,C", "C,D", "B,D", "B,E", "F"};
    /*
        A     B --- E
        |     |
        C --- D     F
    */
    node = "C"; dist = 1;
    expected = "A,D"; 
    process_testcase(test_list, node, dist, expected);  // Will call vertexAtDepth("C", 1);

    return 0;
}

// DO NOT MODIFY
void process_testcase(vector<string> edgelist, string node, int distance, string expected)
{
    cout << "------------[TESTCASE]------------" << endl;

    // Part A: Construct the graph, formatting
    Graph G; string s1, s2; stringstream s;
    for(int i = 0; i < edgelist.size(); i++){
        s1 = ""; s2 = "";
        s = stringstream(edgelist.at(i));
        getline(s, s1, ',');
        getline(s, s2);

        if (s2.size()) {
            G.addEdge(s1, s2);
        }
        else {
            G.addVertex(s1);
        }
    }

    cout << endl << "INPUT   : "; G.display(); cout << endl;

    // Part B: Call the required function
    cout << ">> vertexAtDepth(" << node << ", " << distance << ")" << endl << endl << "OUTPUT  : ";

    G.vertexAtDepth(node, distance);

    cout << endl << "EXPECTED: " << expected << endl;

    cout << endl << "------------------------------------" << endl << endl;

}