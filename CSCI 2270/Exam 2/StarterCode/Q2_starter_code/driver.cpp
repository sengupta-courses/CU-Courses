#include <iostream>
#include <vector>
#include "Graph.hpp"
#include <string>
using namespace std;

void printMessage(bool flag) {
    if(flag) {
        cout<<"The graph is strongly connected"<<endl;
    } 
    else
    {
        cout<<"The graph is not strongly connected"<<endl;
    }
}

int main(int argc, char** argv)
{
    /*
        Test case 1
    */
    Graph g1;
    g1.addVertex("Aurora");
    g1.addVertex("Bloomington");
    g1.addVertex("Cheyenne");
    g1.addVertex("Denver");
    g1.addVertex("Fruita");
    g1.addEdge("Aurora", "Bloomington");
    g1.addEdge("Bloomington", "Cheyenne");
    g1.addEdge("Cheyenne","Denver");
    g1.addEdge("Denver","Fruita");
    g1.addEdge("Fruita", "Aurora");

    cout<<"Graph G1: "<<endl;
    g1.displayEdges();
    bool flag = g1.isStronglyConnected();
    printMessage(flag);
    cout<<endl<<endl;

    /*
        Test case 2
    */
    Graph g2;
    g2.addVertex("Amsterdam");
    g2.addVertex("Broomfield");
    g2.addVertex("Calcutta");
    g2.addVertex("Dallas");
    g2.addVertex("Fabens");
    g2.addEdge("Amsterdam", "Broomfield");
    g2.addEdge("Broomfield", "Calcutta");
    g2.addEdge("Calcutta", "Amsterdam");
    g2.addEdge("Broomfield","Dallas");
    g2.addEdge("Dallas","Fabens");
    
    cout<<"Graph G2: "<<endl;
    g2.displayEdges();
    flag = g2.isStronglyConnected();
    printMessage(flag);
    cout<<endl<<endl;

    /*
        Test case 3
    */
    Graph g3;
    g3.addVertex("Arlington");
    g3.addVertex("Brisbane");
    g3.addVertex("Chandigarh");
    g3.addVertex("Detroit");
    g3.addEdge("Arlington", "Brisbane");
    g3.addEdge("Arlington", "Chandigarh");
    g3.addEdge("Arlington", "Detroit");
    g3.addEdge("Brisbane", "Arlington");
    g3.addEdge("Brisbane", "Chandigarh");
    g3.addEdge("Brisbane", "Detroit");
    g3.addEdge("Chandigarh","Arlington");
    g3.addEdge("Chandigarh","Brisbane");
    g3.addEdge("Chandigarh", "Detroit");
    g3.addEdge("Detroit", "Arlington");
    g3.addEdge("Detroit", "Brisbane");
    g3.addEdge("Detroit", "Chandigarh");

    cout<<"Graph G3: "<<endl;
    g3.displayEdges();
    flag = g3.isStronglyConnected();
    printMessage(flag);
    cout<<endl<<endl;

    /*
        Test case 4
    */
    Graph g4;
    g4.addVertex("Arlington");
    cout<<"Graph G4: "<<endl;
    g4.displayEdges();
    flag = g4.isStronglyConnected();
    printMessage(flag);
    cout<<endl<<endl;

    return 0;
}

