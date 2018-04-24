#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<sstream>
using namespace std;

struct item
{
    int status; // one for wanted, two for selling
    string name;
    int price;
    item(){}
    item(stirng na, int s, int )
}
// reutrns true if the object is removable, false if it gets put into the objcts array;
void sell()
{
    // fuciton prints the objects sold and removes the things from the array.
    // fuction will also do the array shifting.
}
bool process(string line, item objects[], int pos);
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
    if(holder== " wanted")
    {
        p=1;
    }
    else
    {
        p=2;
    }
    item a(name,s,p);
    int index;
    for(int i=0; i< pos; i++)
    {
        if(objcts[i]->name==a->name)
        {
            // next level
            if(objects[i]->status+a->status==3)
            {
                // next level
                if(objects[i]->status==1)
                {
                    if(objects[i]->price>=a->price)
                    {
                        sell(); 
                        return true;
                    }
                }
                else
                {
                    if(a->price>=objects[i])
                    {
                        sell()
                        return true;
                    }
                }
            }
        }
    }
    return false;

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
        if(process(line, objects[], i))
        {
            // handle the case where transaction is made
        }
        else
        {
            //handle the case where it gets shoved into the objects array.
        }
    }
}