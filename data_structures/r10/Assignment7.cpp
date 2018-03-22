//Author: Christian F. Sousa
// CSCI 2270 Data Structures section 104
#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
using namespace std;
int printmenue()
{
    int x;
    cout<<"======Main Menu======"<< endl;
    cout<<"1. Print Verticies"<< endl;
    cout<<"2. Vertex adjacent"<< endl;
    cout<<"3. Quit"<< endl;
}
int main(int argc, *char argv[])
{
    ifstream datafile;
    datafile.open(argv[1]);
    if(datafile.fail())
    {
        cout<< "File not found"<< endl;
    }
    string header;
    getline(datafile,header);
    vector<string>names;
    stringstream ss(header);
    string s;
    while(getline(ss,s));
    {
        names.push_back(s);
    }
    for(int i=0; i<names.size();i++)
    {
        cout<<names[i]<< end;
    }
    //int commmand;
    //commmand=printmenue();
    return 0;
}