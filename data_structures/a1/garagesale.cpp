// Author: Christian F. Sousa
#include<iostream>
#include<fstream>
using namespace std;

struct item{
    int status; // this will be if the item is for sale or wanted, it will be either be one or two for when i am searching for wanted and for sale
    string name; // name of the object being bought or sold
    int price; // the price or price to pay of the object
    item(){}
    item(int n, int s, string na)
    {
        status=s;
        name=na;
        price=n;    
    }
};

// Split is a a fuction I wrote for a previous class
// you can see it is in my resources repo on my github
//https://github.com/swiftsong/resources/blob/master/cppresources.cpp
int Split(string str, char x ,string array[])
{
    int i=0;
    int j=0;
    int k=0;
    int c=0;
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
    while(!datafile.eof())
    {
        getline(datafile, line);
        data[i]=line;
        i++;
    }

}
 void processdata(string data[100], item objects[100])
 {
     string holder_array[3];
     int status;
     string name;
     int cost;
     string holder_str;
     for(int i=0; i<100; i++)
     {
        Split(data[i], ',', holder_array);
        name=holder_array[0];
        if(holder_array[1]== " for sale")
        {
            status=1;
        }
        else
        {
            status=2;
        }
        holder_str= holder_array[2].substr(1,holder_array[2].length());
     }

 }



int main(void)
{
    string data[100];
    item objects[100];
    getdata(data);
    processdata(data,objects);
    //cout<< data[53]<< endl;
}