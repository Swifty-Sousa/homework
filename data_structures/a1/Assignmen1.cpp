// Author: Christian F. Sousa
// CSCI 2270 Data structures
// section 104(i think)
#include<iostream>
#include<fstream>
#include<stdlib.h>
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
bool evaluate(item dd, int index, item objects[])
{
    for(int i=0; i<index;i++)
    {
        item bb=objects[i];
        if(dd.name==bb.name && dd.status+bb.status==3)//  the only way for the statuses to add to 3 is if one is for sale and one is wanted
        {
            if(dd.price+bb.price>=0)// this is where having a negative price comes in, if the summation come out >=0 then the items can be sold
            {
                if(dd.status==2)
                {
                    cout<<dd.name<< " "<< dd.price<< endl;
                }
                else
                {
                    cout<< bb.name<< " "<< bb.price<< endl;
                }
                return true;
            }
        }// if either of the above comparisons fail then the items are not a match and the program returns false
    }
    return false;
}
item makeitem(string holder_array[])
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
    int holderint=stoi(holder_str);
    if(status==1)
    {
        holderint=holderint*(-1); // this will come up later to help determin a price match, see the fuction evaluate above
    }
    item a(name,status,stoi(holder_str));
    return a;

}
// this fuction reads each line parses it and then creates a struct with the line
// then the struct is passes to evaluate
int getdata(string filename, item objects[])
{
     string line;
     string data[3];
     fstream datafile;
     int i=0;// these two are for keeping track of incecies in the arrays
     int size=0;
     datafile.open(filename);
     if (datafile.fail())
     {
        cout<< "file not found"<< endl;// my way of cheacking if a file fails to open
        return -1;
     }
     while(!datafile.eof())
     {
         getline(datafile, line);
         Split(line,',',data);
         item holder=makeitem(data);
         if(evaluate(holder,i, objects)==false)
         {
            objects[i]=holder;
            size++;
            i++;
         }
         else
         {
            size=delete_array_pos(objects,i,size);  
            i--;
         }
         
     }
     datafile.close();
     return size;
     
}

int main(int argc, char*argv[])
{
    item objects[100];
    item a("null", -1,-1);
    for(int i=0;i<100;i++)
    {
        objects[i]=a;
    }
    string filename= argv[1];
    int size=getdata(filename,objects);
    if(size==-1)// if the file fails to open getedata retuns -1 and then the rest is terminated as well
    {
        return 0;
    }
    cout<< "#"<< endl;
    for(int i=0; i<100; i++) // this loop prints out the remaining things in the array
    {
        if(objects[i].status==a.status)
        {
            continue;
        }
        else if(objects[i].status==1)
        {
            cout<<objects[i].name<<", for sale, "<<abs(objects[i].price)<< endl;
        }// above i made items with status 1 have a negartive price so i have to abs(price) for the cout
        else
        {
            cout<<objects[i].name<< ", wanted, "<< objects[i].price<< endl;
        }
    }
    cout<<"#"<< endl;
    return 0;
}