#include "Graph.hpp"
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

void Graph::addEdge(string source, string target){
    for(unsigned int i = 0; i < vertices.size(); i++){
        if(vertices[i]->name == source){
            for(unsigned int j = 0; j < vertices.size(); j++){
                if(vertices[j]->name == target && i != j){
                    adjVertex av;
                    av.v = vertices[j];
                    vertices[i]->adj.push_back(av);
                }
            }
        }
    }
}

void Graph::addVertex(string vName){
    bool found = false;
    for(unsigned int i = 0; i < vertices.size(); i++){
        if(vertices[i]->name == vName){
            found = true;
            cout<<vertices[i]->name<<" found."<<endl;
        }
    }
    if(found == false){
        vertex * v = new vertex;
        v->name = vName;
        v->distance = 0;
        vertices.push_back(v);
    }
}

void Graph::displayEdges(){
    for(unsigned int i = 0; i < vertices.size(); i++){
        cout<<vertices[i]->name<<":"<<endl;
        for(unsigned int j = 0; j < vertices[i]->adj.size(); j++){
            cout<<" --> "<< vertices[i]->adj[j].v->name <<endl;
        }
        cout<<endl;
    }
}


bool Graph::isStronglyConnected(){
    int count = 0; 
    for(int i = 0; i < vertices.size(); i++){
        for(int j = 0; j < vertices.size(); j++){
            vertices[j] -> visited = false; 
        }
        queue < vertex* > q; 
        q.push(vertices[i]); 
        //cout << "Starting vertex (root): " << vertices[i] -> name << "-> "; 
        while(!q.empty()){
            vertex* current = q.front(); 
            q.pop(); 
            for(int i = 0; i < current -> adj.size(); i++){
                if(!(current -> adj[i].v) -> visited){
                    count++; 
                    (current -> adj[i].v) -> distance = current -> distance + 1; 
                    (current -> adj[i].v) -> visited = true; 
                    //cout << current -> adj[i].v -> name << "(" << current -> adj[i].v -> distance << ")" << " "; 
                    q.push(current -> adj[i].v); 
                }
            }
            //current -> visited = true; 
        }
        if(count != vertices.size() - 1){
            return false; 
        }
    }

    return true; 
}


