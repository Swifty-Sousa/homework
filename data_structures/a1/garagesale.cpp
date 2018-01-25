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
// it has been slightly modifed to fit this project
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
int delete_array_pos(item array[],int index,int size)// fuction that removes a entry in the array
{
    for(int i=index;i<size;i++)
    {
        array[i]=array[i+1];
        size--;
    }
    return size;
}
bool evaluate(item dd, int index, item objects)
{
    for(int i=0; i<index;i++)
    {
        item bb=objects[i];
        if(dd.name==bb.name && dd.status+bb.status==3)//  the only way for the statuses to add to 3 is if one is for sale and one is wanted
        {
            if(dd.price+bb.price>=0)// if this is passed then the two items are a match
            {
                if(dd.status=2)
                {
                    cout<<dd.name<< " "<< dd.price<< endl;
                }
                else
                {
                    cout<< bb.name<< " "<< bb.price<< endl;
                }
                return true;
            }
        }
        return false;
    }


}
item makeitem( string holder_array)
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
    holder_str= holder_array[2].substr(1,holder_array[2].length());// this is the string that will hold the price
    holderint=stoi(holder_str);
    if(status==1)
    {
        holderint=holdering*(-1); // this will come up later to help determin a price match, see teh fuction evaluate above
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
     fstream datafile;\
     int i=0;
     int size=0;
     datafile.open(filename);
     if (datafile.fail())
     {
        cout<< "file not found"<< endl;
     }
     while(!datafile.eof())
     {
         getline(datafile, line);
         Split(line,',',data)
         item holder=makeitem(data[]);
         if(evaluate(holder,i, objects)==false)
         {
            objects[i]=holder;
            size++;
         }
         else
         {
            size=delete_array_pos(objects,i,size);  
         }
         i++;
     }
     datafile.close();
}

int main(int argc, char*argv[])
{
    item objects[100];
    item a("null",-1,-1);
    for(int i=0; i<100; i++)
    {
        objects[i]= a;
    }
    string filename= argv[1];
    getdata(filename,objects);
    //cout<< data[53]<< endl;
}