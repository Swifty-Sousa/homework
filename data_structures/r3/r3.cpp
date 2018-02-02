// author: Christian F. Sousa
// CSCI 2270: data structures, section 104
#include<iostream>
#include<fstream>
using namespace std;
void doublearray(int *&ptr, int *s)
{
    int capacity=*s *2;
    int *new_array;
    new_array=new int[capacity];
    for(int i=0;i<*s;i++)
    {
        new_array[i]=*array[i];
    }
    new_array=&array;
    //delete [] array;
    *s=capacity;
}
int main(int argc, char *argv[])
{
    int *p = new int[10];
    for( int i=0; i<10;i++)
    {
        array[i]=-10;
    }
    int *arrayptr=array;
    if(argc!=2)
    {
        cout<<"Error code 1"<< endl;
    }
    string filename=argv[1];
    fstream datafile;
    int i=0;
    int size=5;
    string line;
    datafile.open(filename);
    if(datafile.fail())
    {
        cout<< "file not found"<< endl;
    }
    while(!datafile.eof())
    {
        //cout<< "we are at getline"<< endl;
    getline(datafile, line);
        if(array[i]!=-10)
        {            
            doublearray(array,&size);
            array[i]=stoi(line);
        }
        else
        {
            array[i]=stoi(line);
        }
    i++;
    }
    datafile.close();
}