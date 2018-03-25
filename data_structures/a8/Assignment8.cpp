//Author: Christian F. Sousa
// CSCI 2270 Data Structures section 104
#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include"Graph.h"
using namespace std;
int printmenue()
{
    int x;
    cout<<"======Main Menu======"<< endl;
    cout<<"1. Print vertices"<< endl;
    cout<<"2. Vertex adjacent"<< endl;
    cout<<"3. Quit"<< endl;
    cin>>x;
    return x;
}

int main(int argc, char * argv[])
{
    Graph a;
    string holder;
    string filename=argv[1];
    ifstream datafile;
    vector<string>name;
    datafile.open(filename);
    if(datafile.fail())
    {
        cout<< "File does not exist in current directory"<< endl;
    }
    string line;
    string c;
    getline(datafile, holder);
    //cout<<holder<< endl;
    istringstream ss(holder);
    while(getline(ss,c,','))
    {
        //cout<< holder<<endl;
        name.push_back(c);
    }
    int n=1;
    while(n<name.size())
    {
        a.addVertex(name[n]);
        //cout<< name[n]<< endl;
        n++;
    }
    n=1;
    while(getline(datafile,holder))
    {
        istringstream iss(holder);
        string s;
        vector<string> Vtemp;
        while (getline(iss, s, ',')) 
        {
            Vtemp.push_back(s);
        }
        while(n<Vtemp.size())
        {
            int Ntemp= stoi(Vtemp[n]);
            if(Ntemp>0)
            {
                a.addEdge(name[n],Vtemp[0],Ntemp);
            }
            n++;
        }
        n=1;
    }
    int commmand;
    while(true)
    {
        commmand=printmenue();
        if(commmand==1)
        {
            a.displayEdges();
        }
        else if(commmand==2)
        {
            string one;
            string two;
            cout<< "Enter first city:"<< endl;
            cin >> one;
            cout<< "Enter second city:" <<endl;
            cin>>two;
            int condition=a.isAdjacent(one,two);
            if(condition==1)
            {
                cout<< "True"<<endl;
            }
            else
            {
                cout<< "False"<< endl;
            }
        }
        else if(commmand==3)
        {
            cout<< "Goodbye!"<< endl;
            return 0;
        }
    }
}