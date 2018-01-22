// Author: Christian F. Sousa
#include<iostream>
#include<fstream>
using namespace std;
// Split is a a fuction I wrote for a previous class
// you can see it is in my resources repo on my github
//https://github.com/swiftsong/resources/blob/master/cppresources.cpp
int Split(string str, char x ,string array[])
{
    int i=0;
    int j=0;
    int k=0;
    int c=0;
    int count=0;
    if (str=="")
        {
            return 0;
        }
    str= str + x;
    while(i<str.length())
    {
        if(str[i]==x)
        {
            array[c]=str.substr(j,i-j);
            j=i+1;
            c++;
            count++;
        }
        i++;
    }
    return count;
}

// this fuction takes the data array and fills by reference
// using the file garagesale.txt
void getdata(string data[])
{
    string line;
    fstream datafile;
    int i=0;
    datafile.open("garageSale.txt");
    if (datafile.fail())
    {
        cout<< "Error, file not found"<<endl;
    }
    while(!datafile.eof())
    {
        getline(datafile, line);
        data[i]=line;
        i++;
    }

}



int main(void)
{
    string data[100];
    //struct objects[100];
    getdata(data);
    cout<< data[5]<< endl;
}