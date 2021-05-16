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
  // Key value
  std::string name;
  // adjacency list
  std::vector<adjVertex> adj;

  // visited member for Breadth First Traverse
  bool visited = false;

  string color = "";
};

class Graph
{
    public:
        void addEdge(string v1, string v2);
        void addVertex(string name);
        void display();
        void color(string source);

    private:
        vector<vertex*> vertices;
};

#endif // GRAPH_H
