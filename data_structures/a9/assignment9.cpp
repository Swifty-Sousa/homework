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
    //string line;
    cout<<"======Main Menu======"<< endl;
    cout<<"1. Print vertices"<< endl;
    cout<<"2. Find districts"<< endl;
    cout<<"3. Find shortest path"<< endl;
    cout<<"4. Find shortest weighted path"<< endl;
    cout<<"5. Quit"<< endl;
    //getline(cin,line);
    cin>>x;
    return x;
}


int main(int argc, char* argv[])
{
    // first we read in the file and create the graph
    Graph dis;
    ifstream datafile;
    datafile.open(argv[1]);
    if(datafile.fail())
    {
        cout<< "File: "<< argv[1]<< " not found."<< endl;
    }
    string holder;
    vector<string>name;
    string line;
    string c;
    getline(datafile, holder);
    //cout<<holder<< endl;
    istringstream ss(holder);
    while(getline(ss,c,','))
    {
        //cout<< c<<endl;
        name.push_back(c);
    }
    int n=1;
    while(n<name.size())
    {
        dis.addVertex(name[n]);
        //cout<< name[n]<< endl;
        n++;
    }
    n=1;
    while(getline(datafile,holder))
    {
        istringstream iss(holder);
        string s;
        vector<string> Vtemp;
        //getline(iss,s,',');
        //cout<< "s is now "<< s<< endl;
        while (getline(iss, s, ',')) 
        {
            Vtemp.push_back(s);
        }
        while(n<Vtemp.size())
        {
            //cout<< Vtemp[n]<< endl;
            //cout<<Vtemp[n]<< endl;
            int Ntemp= stoi(Vtemp[n]);
            if(Ntemp>-1)
            {
                dis.addEdge(name[n],Vtemp[0],Ntemp);
            }
            n++;
        }
        n=1;
    }

    // end of setup
    // beginning of user interactions
    while(true)
    {
        int command= mainmen();
        if(command==1)
        {
            dis.displayEdges();
        }
        if(command==2)
        {
            dis.assignDistricts();
        }
        if(command==3)
        {
                string start;
                string end;
                cout<< "Enter a starting city:"<< endl;
                getchar();
                getline(cin,start);
                cout<< "Enter an ending city:"<< endl;
                //getchar();
                getline(cin,end);
                //cout<< " Start is:"<< start<< endl;
                //cout<< " End is :"<< end << endl;
                dis.shortestPath(start,end);
        }
        if(command==4)
        {
                string start;
                string end;
                cout<< "Enter a starting city:"<< endl;
                getchar();
                getline(cin,start);
                cout<< "Enter an ending city:"<< endl;
                //getchar();
                getline(cin,end);
                //cout<< " Start is:"<< start<< endl;
                //cout<< " End is :"<< end << endl;
                dis.shortestWeightedPath(start,end);
        }
        if(command==5)
        {
            cout<< "Goodbye!"<< endl;
            break;
        }
    }
}