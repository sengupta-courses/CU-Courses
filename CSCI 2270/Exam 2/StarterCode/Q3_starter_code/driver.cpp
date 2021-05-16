#include <iostream>
#include <vector>
#include "Graph.hpp"
#include <string>
using namespace std;

int main(int argc, char** argv)
{
    Graph g1;
    g1.addVertex("G");
    g1.addVertex("Z");
    g1.addVertex("L");
    g1.addVertex("M");
    g1.addVertex("Q");
    g1.addVertex("I");


    g1.addEdge("G", "Z");
    g1.addEdge("G", "L");
    g1.addEdge("Z","M");
    g1.addEdge("L","M");
    g1.addEdge("M", "Q");
    g1.addEdge("Q", "I");

    cout<< "Vertices before coloring - Graph1"<<endl;

    g1.display();
    g1.color("G");
    cout<<endl;

    cout<< "Vertices after coloring - Graph1"<<endl;

    g1.display();
    cout<< "---------------------------------"<<endl;
    cout<<endl;
    Graph g2;
    g2.addVertex("L");
    g2.addVertex("M");
    g2.addVertex("N");
    g2.addVertex("O");
    g2.addVertex("P");


    g2.addEdge("L", "M");
    g2.addEdge("L", "P");
    g2.addEdge("L","N");
    g2.addEdge("M","N");
    g2.addEdge("P", "O");
    g2.addEdge("O", "N");

    cout<< "Vertices before coloring - Graph2"<<endl;

    g2.display();
    g2.color("L");
    cout<<endl;

    cout<< "Vertices after coloring - Graph2"<<endl;
    cout<<endl;

    g2.display();
    cout<< "---------------------------------"<<endl;

    Graph g3;
    g3.addVertex("Q");
    g3.addVertex("R");
    g3.addVertex("S");
    g3.addVertex("T");
    g3.addVertex("U");


    g3.addEdge("Q", "R");
    g3.addEdge("R", "S");
    g3.addEdge("S","T");
    g3.addEdge("T","U");

    cout<< "Vertices before coloring - Graph3"<<endl;

    g3.display();
    g3.color("Q");
    cout<<endl;

    cout<< "Vertices after coloring - Graph3"<<endl;
    cout<<endl;

    g3.display();
    return 0;

}
