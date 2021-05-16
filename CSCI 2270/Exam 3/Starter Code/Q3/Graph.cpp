#include <vector>
#include <iostream>
#include <queue>
#include "Graph.hpp"

using namespace std;

/* ----------------------------------------
TODO: Complete the method below.
      You may add helpers, headers (if necessary)
      Helper functions should not be part of the class.
*/

void Graph::vertexAtDepth(string start, int k)
{
    // YOUR CODE HERE
    return;
}

// ----------------------------------------

void Graph::addEdge(string s1, string s2, bool create_node)
{
    // arg: create_node (default: true) creates the nodes if they don't exist in graph
    // assumes user won't insert duplicate edges

    vertex* v1 = findVertexPointer(s1);
    vertex* v2 = findVertexPointer(s2);

    if (!v1 && create_node) {
        addVertex(s1);
        v1 = findVertexPointer(s1);
    }

    if (!v2 && create_node) {
        addVertex(s2);
        v2 = findVertexPointer(s2);
    }

    if(v1 && v2 && v1 != v2) {
        adjVertex av1, av2;

        // edge from v2 to v1
        av1.v = v1;
        v2->adj.push_back(av1);

        // edge from v1 to v2
        av2.v = v2;
        v1->adj.push_back(av2);
    }
}


void Graph::addVertex(string n){
    vertex* exists = findVertexPointer(n);
    if(!exists){
        vertex* v = new vertex;
        v->name = n;
        vertices.push_back(v);
    }
}


void Graph::display(){
    cout << endl << endl;
    for(int i = 0; i < vertices.size(); i++) {
        cout << vertices[i]->name << " : ";
        for(int j = 0; j < vertices[i]->adj.size(); j++) {
            cout << vertices[i]->adj[j].v->name << " -> ";
        }
        cout << "NULL" << endl;
    }
    cout << endl;
}


vertex* Graph::findVertexPointer(string toFind)
{
    for(int i = 0; i < vertices.size(); i++) {
        if(vertices[i]->name == toFind) {
            return vertices[i];
        }
    }

    return nullptr;
}

void Graph::setDistanceZero()
{
    for(int i = 0; i < vertices.size(); i++) {
        vertices[i]->distance = 0;
    }
}

void Graph::setDistanceInfinity()
{
    for(int i = 0; i < vertices.size(); i++) {
        vertices[i]->distance = 1000000;
    }
}

void Graph::setVisitedFalse()
{
    for(int i = 0; i < vertices.size(); i++) {
        vertices[i]->visited = false;
    }
}
