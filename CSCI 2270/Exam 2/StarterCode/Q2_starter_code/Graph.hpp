#ifndef GRAPH_H
#define GRAPH_H
#include<vector>
#include<iostream>
using namespace std;

struct vertex;
struct adjVertex{
    vertex *v;
};

struct vertex{
    string name;
    bool visited = false;
    int distance = 0;
    vertex *pred = NULL;
    vector<adjVertex> adj;
};

class Graph
{
    private:
        vector<vertex*> vertices;
    public:
        void addEdge(string v1, string v2);
        void addVertex(string name);
        void displayEdges();
        bool isStronglyConnected();
};

#endif // GRAPH_H
