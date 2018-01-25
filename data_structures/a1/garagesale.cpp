// Author: Christian F. Sousa
#include<iostream>
#include<fstream>
using namespace std;

struct item{
    int status; // this will be if the item is for sale or wanted, it will be either be one or two for when i am searching for wanted and for sale
    string name; // name of the object being bought or sold
    int price; // the price or price to pay of the object
    item(){}
    item(string na, int s, int p)
    {
        status=s;
        name=na;
        price=p;    
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
    int count=0;
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
int delete_array_pos(array[],index,size)// fuction that removes a entry in the array
{
    for(i=index;i<size;i++)
    {
        array[i]=array[x+1];
        size--;
    }
    return size;
}
bool evaluate(item dd, int index)
{
    for


}
item makeitem(holder_array)
{
    int status;
    string name;
    int cost;
    string holder_str;
    name=holder_array[0];
    if(holder_array[1]== " for sale")
    {
        status=1;
    }
    else
    {
        status=2;
    }
    holder_str= holder_array[2].substr(1,holder_array[2].length());// this is the strign that will hold the price
    holderint=stoi(holder_str);
    if(status==1)
    {
        holderint=holdering*(-1); // this will come up later to help determin a price match
    }
    item a(name,status,stoi(holder_str))
    return a;

}
// this fuction reads each line parses it and then creates a struct with the line
// then the struct is passes to evaluate
void getdata(string filename, item objects)
{
     string line;
     string data[3];
     fstream datafile;
     int i=0;
     datafile.open(filename);
     if (datafile.fail())
     while(!datafile.eof())
     {
         getline(datafile, line);
         Split(line,',',data)
         item holder=makeitem(data[]);
         if(evaluate(holder,i, objects)==false)
         {
             objects[i]=holder;
         }
         i++;
     }
     datafile.close();
}

int main(int argc, char *argv[])
{
    item objects[100];
    string filename= argv[1];
    getdata(filename,objects);
    //cout<< data[53]<< endl;
}