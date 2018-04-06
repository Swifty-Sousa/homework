// Author: Christian F. Sousa
// CSCI 2270  Data structures
#include<iostream>
#include<sstream>
#include<fstream>
#include<queue>
#include<stack>
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