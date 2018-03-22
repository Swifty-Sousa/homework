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
    cin>>x;
    return x;
}
int main(int argc, char* argv[])
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
    //this for loop starts at one so that 
    // we dont include the word "cities in the vector for city names"
    while(getline(ss,s,','))
    {
        names.push_back(s);
    }
    int commmand;
    while(true)
    {
        commmand=printmenue();
        if(commmand==1)
        {

        }
        else if(commmand==2)
        {

        }
        else if(commmand==3)
        {
            cout<< "Goodbye!"<< endl;
            return 0;
        }
    }
}