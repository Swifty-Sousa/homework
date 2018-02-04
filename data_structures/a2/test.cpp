#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;
void arrayX2(int *&aptr, int *size)
{
    int newsize= *size*2;
    int *newarray= new int[newsize];
    for(int i=0; i<*size;i++)
    {
        newarray[i]=aptr[i];
    }
    free(aptr);
    aptr=newarray;
    *size=newsize;
}
void count(string filename)
{
    ifstream datafile;
    datafile.open(filename);
    if(datafile.fail())
    {
        cout<< "File not found"<< endl;
    }
    int count=0;
    string line;
    string word;
    while(getline(datafile, line)) 
    {
        stringstream ss(line);
        while(ss.good())
        {
            ss >> word;
            count++;
            cout<< word<< endl;
        }
    }
    cout<< "The answer is "<< count<< endl;
}
int main(void)
{
    string *array = new int[2];
    int size =2;
    int elements=0;
    string line
    ifstream datafile;
    datafile.open(test.txt);
    while(getline(datafile,line))
    {
        stringstream ss(line)
        while(ss.good())
        {
            if()
        }
    }
}