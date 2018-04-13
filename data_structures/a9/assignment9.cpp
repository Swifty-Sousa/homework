// Author: Christian F. Sousa
// CSCI 2270  Data structures
#include<iostream>
#include<sstream>
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
    fstream datafile;
    datafile.open(argv[1]);
    if(datafile.fail())
    {
        cout<< "File: "<< argv[1]<< " not found."<< endl;
    }
    string top; // this will be the holder for the first line of the text file
    getline(datafile,top);
    stringstream ss(top);
    int command= mainmen();
    if(command==1)
    {

    }
    if(command==2)
    {

    }
    if(command==3)
    {

    }
    if(command==4)
    {

    }
    if(command==5)
    {
        cout<< "Goodbye!"<< endl;
    }
}