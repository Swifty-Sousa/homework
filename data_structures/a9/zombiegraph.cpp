//Author: Christian F. Sousa
// CSCI 2270 data structures, section 104
#include"Graph.hpp"
#include<iostream>
#include<stack>
#include<queue>
#include<limits>

void Graph::Graph()
{
    // defualt contsructor
}
void Graph::~Graph()
{
    // Destructor
}
void Graph::addEdge(string first, string sec, int weight)
{
    return;
}
void Graph::addVertex(string name)
{
    return;
}
void Graph::displayEdges()
{
    return;
}

void Graph::shortestPath(string begin, string endd)
{
    // this is a standard BFS
    // loop below sets everything to zero and visited to false
    // as to not get issues with running this multiple times with 
    // the same graph.
    for(unsigned int i=0; i<vertices.size(); i++)
    {
        vertices[i].visited=false;
        vertices[i].unweightedDistance=INT_MAX;
    }
	vertex * start= findVertex(begin);
	vertex * end= findVertex(endd);
    if(start==NULL || end==NULL)
    {
        cout<< "One or more cities doesn't exist"<< endl;
        return;
    }
    if(start->districtID!=end->districtID)
    {
        cout<<"No safe path between cities"<< endl;
        return;
    }
    queue<vertex*> q;
    q.push(start);
    start->unweightedDistance=0;
    vertex * holder;
    while(!q.empty())
    {
        holder=q.front();
        q.pop();
        if(holder->visited)
        {
            continue;
        }
        holder->visited=true;
        for(unsigned int i=0; i<holder->adj.size();i++)
        {
            if(!holder->adj[i].v->visited)
            {
                q.push(holder->adj[i].v);
                //holder->adj[i].v->parent=holder;
            }
            if(holder->unweightedDistance+1<holder->adj[i].v->unweightedDistance)
            {
                holder->adj[i].v->unweightedDistance=holder->unweightedDistance+1;
                holder->adj[i].v->parent=holder;
            }

        }
    }
    // now for the print statements
    vector<vertex*>p;
    vertex * temp=end;
    //cout<< "end = "<< end->name<< endl;
    while(temp->parent!=NULL)
    {
        //cout<<temp->name<<endl;
        p.push_back(temp);
        temp=temp->parent;
    }
    cout<<end->unweightedDistance<< ", "<<start->name<<", ";
    for(int i=p.size()-1; i>=0;i--)
    {
        cout<<p[i]->name;
        if(i>0)
        {
            cout<<", ";
        }
    }
    cout<<endl;
}
void Graph::shortestWeightedPath(string begin, string endd)
{
    // this is a standard BFS
    // loop below sets everything to zero and visited to false
    // as to not get issues with running this multiple times with 
    // the same graph.
    for(unsigned int i=0; i<vertices.size(); i++)
    {
        vertices[i].visited=false;
        vertices[i].weightedDistance=INT_MAX;
    }
	vertex * start= findVertex(begin);
	vertex * end= findVertex(endd);
    if(start==NULL || end==NULL)
    {
        cout<< "One or more cities doesn't exist"<< endl;
        return;
    }
    if(start->districtID!=end->districtID)
    {
        cout<<"No safe path between cities"<< endl;
        return;
    }
    if(start->districtID==-1 || end->districtID==-1)
    {
        cout<<"Please identify the districts before checking distances"<< endl;
        return;
    }
    queue<vertex*> q;
    q.push(start);
    start->weightedDistance=0;
    vertex * holder;
    while(!q.empty())
    {
        holder=q.front();
        q.pop();
        if(holder->visited)
        {
            continue;
        }
        holder->visited=true;
        for(unsigned int i=0; i<holder->adj.size();i++)
        {
            if(!holder->adj[i].v->visited)
            {
                q.push(holder->adj[i].v);
                //holder->adj[i].v->parent=holder;
            }
            if(holder->weightedDistance+ holder->adj[i].weight<holder->adj[i].v->weightedDistance)
            {
                holder->adj[i].v->weightedDistance=holder->weightedDistance+holder->adj[i].weight;
                holder->adj[i].v->parent=holder;
            }

        }
    }
    // now for the print statements
    vector<vertex*>p;
    vertex * temp=end;
    //cout<< "end = "<< end->name<< endl;
    while(temp->parent!=NULL)
    {
        //cout<<temp->name<<endl;
        p.push_back(temp);
        temp=temp->parent;
    }
    cout<<end->weightedDistance<< ", "<<start->name<<", ";
    for(int i=p.size()-1; i>=0;i--)
    {
        cout<<p[i]->name;
        if(i>0)
        {
            cout<<", ";
        }
    }
    cout<<endl;
}
vertex * Graph::findVertex(string target)
{
   for(int i=0; i<vertices.size(); i++) 
   {
       if(vertices[i].name==target)
       {
           return &vertices[i];
       }
   }
   // in case the verticie does not exist.
   return NULL;
}
void Graph::assignDistricts()
{
    // this loop reset all visited booleans to false
    //cout<< vertices[1].name<< " "<< vertices[1].ID<< endl;
    for(int i=0; i<vertices.size(); i++)
    {
        if(vertices[i].visited==true)
        {
            vertices[i].visited=false;
        }
    }
    int currentDist=1;
	for(int i=0; i<vertices.size(); i++)
	{
        if(vertices[i].visited)
        {
            continue;
        }
        //cout<< "this is actually happening"<< endl;
        vertices[i].visited=true;
        vertices[i].districtID=currentDist;
        DFSLabel(vertices[i].name,currentDist);
        currentDist++;
	}
}
void Graph::DFSLabel(string begin, int id)
{
    stack<vertex*>s;
    vertex *start=findVertex(begin);
    s.push(start);
    vertex * holder;
    while(!s.empty())
    {
        holder=s.top();
        s.pop();
        holder->visited=true;
        for(int i=0; i<holder->adj.size(); i++)
        {
            if(holder->adj[i].v->visited)
            {
                continue;
            }
            s.push(holder->adj[i].v);
            holder->adj[i].v->districtID=id;
        }
    }
}