#include<vector>
#include<iostream>

using namespace std;

struct vertex;

struct adjVertex{
    vertex *v;
};

struct vertex{
    string name;
    bool visited;
    int distance;
    vector<adjVertex> adj;
};

class Graph
{
    private:
        std::vector<vertex*> vertices;

    public:
        void vertexAtDepth(string start, int k);
        void addVertex(string name);
        void addEdge(string v1, string v2, bool create_node=true);  // will create the vertex if it doesn't exist
        void display();

        void setVisitedFalse();                     // set visited to false for ALL nodes
        void setDistanceZero();                     // set distance to 0 for ALL nodes
        void setDistanceInfinity();                 // set distance to infinity (practically) for ALL nodes
        vertex* findVertexPointer(string toFind);   // returns the pointer to the node with given string
};