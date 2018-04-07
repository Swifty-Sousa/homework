//Author: Christian F. Sousa
// CSCI 2270 data structures, section 104
#include"Graph.hpp"
#include<iostream>
#include<stack>
#include<queue>

void Graph::Graph()
{
    // defualt contsructor
}
void Graph::~Graph()
{
    // Destructor
}
void Graph::addEdge(string first, stirng sec, int weight)
{

}
void Graph::addVertex(string name)
{

}
void Graph::displayEdges()
{

}
void Graph::assignDistricts(string start, string end)
{
	vertex * start= findVertex(start);
	vertex * end= findVertex(end);
	for(int i=0; i<vertices.size(); i++)
	{
		
	}
    // this loop reset all visited booleans to false
    for(int i=0; i<vertices.size(); i++)
    {
        if(vertices[i].visited==true)
        {
            vertices[i].visited=false;
        }
        else
        {
            continue;
        }
    }
}
void Graph::shortestPath(string start, string end)
{
	vertex * start= findVertex(start);
	vertex * end= findVertex(end);
}
void Graph::shortestWeightedPath(string start, string end)
{
	vertex * start= findVertex(start);
	vertex * end= findVertex(end);

}
vertex * Graph::findVertex(string target)
{
   for(int i=0; i<vertices.size(); i++) 
   {
       if(vertices[i].name==target)
       {
           return veticies[i];
       }
   }
   // in case the verticie does not exists.
   return NULL;
}
void Graph::DFSLable(string start, int id)
{
    vertex * temp = findVertex(start);
	if(temp->visited)
	{
		return;
	}
	temp.visited=true;
	temp.ID=id;
	for(int i=0;i<temp->adj.size();i++)
	{

	}
}