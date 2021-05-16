#include "Graph.hpp"
#include <vector>
#include <queue>
#include <iostream>

using namespace std;


void Graph::addEdge(string v1, string v2, int num){
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i] -> name == v1){
            for(int j = 0; j < vertices.size(); j++){
                if(vertices[j] -> name == v2 && i != j){
                    adjVertex vTemp; 
                    vTemp.weight = num; 
                    vTemp.v = vertices[j]; 
                    vertices[i] -> adj.push_back(vTemp); 
                    adjVertex vTemp2; 
                    vTemp2.weight = num; 
                    vTemp2.v = vertices[i]; 
                    vertices[j] -> adj.push_back(vTemp2); 
                }
            }
        }
    }
}

void DFSHelper(vertex* &temp){
    temp -> visited = true; 
    temp -> distance++; 
    cout << temp -> name << " -> "; 
    for(int i = 0; i < temp -> adj.size(); i++){
        vertex* temp2 = temp -> adj[i].v; 
        if(!temp2 -> visited){
            DFSHelper(temp2); 
        }
    }
}

void Graph::depthFirstTraversal(string sourceVertex){
    vertex* temp = NULL; 
    for(int j = 0; j < vertices.size(); j++){
        if(vertices[j] -> name == sourceVertex){
            temp = vertices[j]; 
        }
    }
    if(temp == NULL){
        cout << " vertex " << sourceVertex << " does not exist!" << endl; 
        return; 
    }

    else{
        for(int k = 0; k < vertices.size(); k++){
            vertices[k] -> visited = false; 
        }

        DFSHelper(temp); 
    }
    cout << "DONE" << endl; 
}

void Graph::dijkstraTraverse(string start){
    vertex* dj; 

    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i] -> name == start){
            dj = vertices[i]; 
        }
    }

    for(int j = 0; j < vertices.size(); j++){
        vertices[j] -> visited = false; 
        vertices[j] -> distance = INT8_MAX; 
        vertices[j] -> pred = NULL; 
    }

    for(int k = 0; k < vertices.size(); k++){
        vertices[k] -> visited = false; 
        vertices[k] -> distance = INT8_MAX; 
        vertices[k] -> pred = NULL; 
    }

    dj -> visited = true; 
    dj -> distance = 0; 

    vector<vertex*> tempList; 
    tempList.push_back(dj); 

    bool ifSolved = false; 

    while(!ifSolved){
        int minD = INT8_MAX; 
        vertex* minV = NULL; 

        ifSolved = true; 

        for(int m = 0; m < tempList.size(); m++){
            vertex* a = tempList[m]; 
            for(int n = 0; n < a -> adj.size(); n++){
                vertex* b = a -> adj[n].v; 
                int val = a -> adj[n].weight; 
                if(!b -> visited){
                    if(minD > a -> distance + val){
                        minD = a -> distance + val; 
                        minV = b; 
                        ifSolved = false;  
                    }
                }
            }
       }

       if(!ifSolved){
           minV -> distance = minD; 
           minV -> visited = true; 
           tempList.push_back(minV); 
       }
    }
}

void Graph::shortestPath(string s1, string s2){
    vertex* begin; 
    vertex* end; 

    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i] -> name == s1){
            begin = vertices[i]; 
        }
        
        else if(vertices[i] -> name == s2){
            end = vertices[i]; 
        }
    }

    
    dijkstraTraverse(s2); 
    int count = 0; 

    for(int j = 0; j < begin -> adj.size(); j++){
        if(begin -> adj[j].v == begin -> pred){
            count = count + begin -> adj[j].weight; 
        }
    }

    cout << begin -> name << " -> "; 

    while(begin != end){
        begin = begin -> pred; 

        for(int k = 0; k < begin -> adj.size(); k++){
            if(begin -> adj[k].v == begin -> pred){
                count = count + begin -> adj[k].weight; 
            }
        }

        cout << begin -> name << " -> "; 
    }

    cout << "DONE [" << count << "]" << endl; 
}