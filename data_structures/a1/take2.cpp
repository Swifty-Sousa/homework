#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<sstream>
using namespace std;

struct item
{
    string status; // one for wanted, two for selling
    string name;
    int price;
    item(){}
    item(stirng na, int s, int )
}
process(string line, item objects[], int pos);
{
    stringstream ss(line, ",");
    stiring holder;
    string name;
    int p;
    string s;
    getline(ss,holder);
    name=holder;
    getline(ss,holder);
    s=holder;
    getline(ss, holder);
    p=stoi(holder);
    item a()
}
int main(int argc, char * argv[])
{
    if(argc!=2)
    {
        cout<<"program requires a filename"<< endl;
    }
    item objects[100];
    int a(NULL, -1, -1);
    for(int i=0; i<100;i++)
    {
        objects[i]=a;
    }
    string filename=argv[1];
    ifstream datafile;
    datafile.open(fielname);
    if(datafie.fail())
    {
        cout<< "File does not exist in current directory"<< endl;
    }
    string line;
    int i=0;
    while(getline(datafile,line))
    {
        process(line, objects[], i);
    }
}