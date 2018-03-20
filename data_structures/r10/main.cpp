#include<iostream>
#include<vector>
#include<fstream>
#include<sstream>
#include"Graph.h"

int main(void)
{
    string filename="mat.txt";
    ifstream datafile;
    datafile.open(filename);
    if(datafile.fail())
    {
        cout<< "you done did a goof"<< endl;
    }
    string line;
    stringstream ss;
    while(!datafile.eof())
    {
        getline(datafile,line);
        ss<<line;
        while
    }
}