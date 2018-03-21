#include<iostream>
#include<vector>
#include<fstream>
#include<sstream>
#include"Graph.h"
using namespace std;
int main(void)
{
    Graph a;
    string holder;
    string filename="mat.txt";
    ifstream datafile;
    vector<string>name;
    datafile.open(filename);
    if(datafile.fail())
    {
        cout<< "you done did a goof"<< endl;
    }
    string line;
    string c;
    getline(datafile, holder);
    //cout<<holder<< endl;
    istringstream ss(holder);
    while(getline(ss,c,' '))
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
        while (getline(iss, s, ' ')) 
        {
            Vtemp.push_back(s);
        }
        while(n<Vtemp.size())
        {
            cout<< Vtemp[n]<< endl;
            int Ntemp= stoi(Vtemp[n]);
            if(Ntemp>0)
            {
                a.addEdge(name[n],Vtemp[0],Ntemp);
            }
            n++;
        }
        n=1;
    }
    //a.addVertex("boulder");
    a.displayEdges();
    return 0;
}