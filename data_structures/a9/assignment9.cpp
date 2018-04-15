// Author: Christian F. Sousa
// CSCI 2270  Data structures
#include<iostream>
#include<sstream>
#include<vector>
#include<fstream>
#include<queue>
#include<stack>
#include"Graph.hpp"
using namespace std;
int mainmen()
{
    int x;
    cout<<"1. Print Verticeis"<< endl;
    cout<<"2. Find districts"<< endl;
    cout<<"3. Find shortest path"<< endl;
    cout<<"4. Find shortest wieghted path"<< endl;
    cout<<"5. Quit"<< endl;
    cin>> x;
    return x;
}


int main(int argc, char* argv[])
{
    // first we read in the file and create the graph
    Graph dis;
    fstream datafile;
    datafile.open(argv[1]);
    if(datafile.fail())
    {
        cout<< "File: "<< argv[1]<< " not found."<< endl;
    }
    string top; // this will be the holder for the first line of the text file
    getline(datafile,top);
    stringstream ss(top);
    vector<string>names;
    while(getline(ss,top,','))
    {
        dis.addVertex(ss);
    }
    string holder;
    string s;
    vector<string> vtemp;
    int ntemp;
    while(getline(datafile,holder))
    {
        stringstream aa(holder);
        while(getline(aa,s,','))
        {
            vtemp.push_back(s);
        }
        for(unsigned int i=1;i<vtemp.size();i++)
        {
            ntemp= stoi(vtemp[i]);
            if(ntemp>0)
            {
                dis.addEdge(name[i],vtemp[0],ntemp);
            }
        }
    }


    // end of setup
    // beginning of user interactions

    int command= mainmen();
    if(command==1)
    {
        dis.displayEdges();
    }
    if(command==2)
    {
        dis.assignDistricts();
        assigned=true;
    }
    if(command==3)
    {
        else
        {
            string start;
            string end;
            cout<< "Enter a starting city:"<< enld;
            getline(cin,start):
            cout<< "Enter and ending city:"<< endl;
            getline(cin,end);
            dis.shortestPath(start,end);

        }
    }
    if(command==4)
    {
        else
        {
            string start;
            string end;
            cout<< "Enter a starting city:"<< enld;
            getline(cin,start):
            cout<< "Enter and ending city:"<< endl;
            getline(cin,end);
            dis.shortestWeightedPath(start,end);
        }
    }
    if(command==5)
    {
        cout<< "Goodbye!"<< endl;
    }
}