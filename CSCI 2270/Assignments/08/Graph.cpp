#include "Graph.hpp"
#include <vector>
#include <queue>
#include <iostream>

using namespace std;


void Graph::addVertex(string vName){
    bool temp = false; 
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i] -> name == vName){
            temp = true; 
        }
    }
    if(temp == false){
        vertex * vTemp = new vertex; 
        vTemp -> name = vName; 
        vertices.push_back(vTemp); 
    }
}

void Graph::addEdge(string v1, string v2){
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i] -> name == v1){
            for(int j = 0; j < vertices.size(); j++){
                if(vertices[j] -> name == v2 && i != j){
                    adjVertex vTemp; 
                    vTemp.v = vertices[j]; 
                    vertices[i] -> adj.push_back(vTemp); 
                    adjVertex vTemp2; 
                    vTemp2.v = vertices[i]; 
                    vertices[j] -> adj.push_back(vTemp2); 
                }
            }
        }
    }
}

void Graph::displayEdges(){
    for(int i = 0; i < vertices.size(); i++){
        cout << vertices[i] -> name << " -->"; 
        for(int j = 0; j < vertices[i] -> adj.size(); j++){
            cout << " " << vertices[i] -> adj[j].v -> name;  
        }
        cout << endl; 
    }
}

void Graph::breadthFirstTraverse(string sourceVertex){
    vertex *sv = NULL; 
    for(int val = 0; val < vertices.size(); val++){
        if(vertices[val] -> name == sourceVertex){
            sv = vertices[val];
        }
    }
    sv -> visited = true; 
    sv -> distance = 0; 
    queue < vertex* > q; 
    q.push(sv); 
    cout << "Starting vertex (root): " << sv -> name << "-> "; 
    while(!q.empty()){
        vertex* current = q.front(); 
        q.pop(); 
        for(int i = 0; i < current -> adj.size(); i++){
            if(!(current -> adj[i].v) -> visited){
                (current -> adj[i].v) -> distance = current -> distance + 1; 
                (current -> adj[i].v) -> visited = true; 
                cout << current -> adj[i].v -> name << "(" << current -> adj[i].v -> distance << ")" << " "; 
                q.push(current -> adj[i].v); 
            }
        }
        current -> visited = true; 
    }
}

void connectedHelper(vertex* vTemp){
    if(vTemp -> visited == false){
        vTemp -> visited = true; 
        for(int i = 0; i < vTemp -> adj.size(); i++){
            connectedHelper(vTemp -> adj[i].v); 
        }
    }
}

int Graph::getConnectedComponents(){
    int i = 0; 
    for(int j = 0; j < vertices.size(); j++){
        if(vertices[j] -> visited == false){
            connectedHelper(vertices[j]); 
            i++; 
        }
    }
    return i; 
}