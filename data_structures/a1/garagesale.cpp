// Author: Christian F. Sousa
#include<iostream>
#include<fstream>
using namespace std;

void create()
{
    fstream datafile;
    datafile.open("garagesale.txt");
    if (datfile.fail())
    {
        cout<< "Error garagesale textfile not found"<< endl;
    }
    string holder;
    while(!datafile.eof())
    {
        getline(datafile,holder);
        
    }
}



int main void()
{
    struct objects[100];
}