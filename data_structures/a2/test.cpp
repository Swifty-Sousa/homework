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
    /*
    int *array = new int[2];
    int size =2;
    array[0]=0;
    array[1]=0;
    cout<< "current array size "<<size<< endl;
    for(int i=0; i<size;i++)
    {
        cout<< "Array at inex " << i<< " is "<< array[i]<< endl;
    }
    cout <<"doubling array"<< endl;
    arrayX2(array,&size);
    array[2]=7;
    array[3]=7;
    cout<< "array Doubled"<< endl;
    cout<< "array size is now "<< size<< endl;
    */
    count("test.txt");
}