#include "Graph.h"
#include <vector>
#include <iostream>

using namespace std;
// This a file that we started by the univeristy of Colorado Boulder and then
// then modified by Christian F. Sousa
Graph::Graph()
{

}

Graph::~Graph()
{
    //dtor
}
void Graph::addEdge(string v1, string v2, int weight){

    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i].name == v1){
            for(int j = 0; j < vertices.size(); j++){
                if(vertices[j].name == v2 && i != j){
                    adjVertex av;
                    av.v = &vertices[j];
                    av.weight = weight;
                    vertices[i].adj.push_back(av);
                }
            }
        }
    }
}
void Graph::addVertex(string n){
    bool found = false;
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i].name == n){
            found = true;
            cout<<vertices[i].name<<" already in the graph."<<endl;
        }
    }
    if(found == false){
        vertex v;
        v.name = n;
        vertices.push_back(v);

    }
}
int Graph::isAdjacent(string one, string two) {
    for (int i = 0; i < vertices.size(); i++) {
        if (vertices[i].name == one)
         {
            if (two== vertices[i + 1].name) 
            {
                return 1;
            }
             else if (two== vertices[i - 1].name) 
            {
                return 1;
            }
        }
    }
    return 0;
}
void Graph::displayEdges(){
    //loop through all vertices and adjacent vertices
    for(int i = 0; i < vertices.size(); i++){
        cout<<vertices[i].name<<"-->";
        for(int j = 0; j < vertices[i].adj.size(); j++)
        {
            if(j<vertices[i].adj.size()-1)
            {
            cout<<vertices[i].adj[j].v->name<<"***";
            }
            else
            {
            cout<<vertices[i].adj[j].v->name;
            }
        }
        cout<<endl;
    }

}