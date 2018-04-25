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
    item(string na, int s, int p)
    {
        name=na;
        status=s;
        price=p;
    }

};
// reutrns true if the object is removable, false if it gets put into the objcts array;
void sell(item buyer, item seller, int pos, item objects[])
{
    cout<<seller.name<< " "<< seller.price<< endl; 
    item a("", -1, -1);
    objects[pos]= a; 
    // now do the array shifting so that there are no holes in the array
    for(int i=pos; i<98; i++)
    {
        objects[i]=objects[i+1];
    }
}
bool process(string line, item objects[], int pos)
{
    string holder;
    stringstream ss(line);
    string nam;
    string p;
    int s;
    getline(ss,holder, ',');
    nam=holder;
    getline(ss,holder, ',');
    if(holder== " wanted")
    {
        s=1;
    }
    else
    {
        s=2;
    }
    getline(ss, holder, ',');
    p=holder;
    item a;
    a.name=nam;
    a.status=s;
    //cout<< "[" <<p<< "]"<< endl;
    a.price=stoi(p);
    int index;
    for(int i=0; i< pos; i++)
    {
        if(objects[i].name==a.name)
        {
            //objects have the same name
            if(objects[i].status+a.status==3)
            {
                // one object is for sale the other is wanted.
                if(objects[i].status==1)
                {
                    if(objects[i].price>=a.price)
                    {
                        //checking prices match
                        sell(objects[i],a, i,objects); 
                        return true;
                    }
                }
                else
                {
                    if(a.price>=objects[i].price)
                    {
                        //checking price matches
                        sell(a, objects[i],i,objects);
                        return true;
                    }
                }
            }
        }
    }
    objects[pos]=a;
    return false;
}
int main(int argc, char * argv[])
{
    if(argc!=2)
    {
        cout<<"program requires a filename"<< endl;
    }
    item objects[100];
    item a;
    a.name="";
    a.status=-1;
    a.price=-1;
    for(int i=0; i<100;i++)
    {
        objects[i]=a;
    }
    string filename=argv[1];
    ifstream datafile;
    datafile.open(filename);
    if(datafile.fail())
    {
        cout<< "File does not exist in current directory"<< endl;
    }
    string line;
    int i=0;
    while(getline(datafile,line))
    {
        if(!process(line, objects, i))
        {
            i++;
        }
        else
        {
            i--;
        }
    }
    //cout<< endl;
    cout<< "#"<< endl;
    //cout<< endl;

    for(int k=0; k<i; k++)
    {
        if(objects[k].status==1)
        {
            cout<< objects[k].name<< ", wanted, "<< objects[k].price<<endl;
        }
        else
        {
            cout<< objects[k].name<< ", for sale, "<< objects[k].price<<endl;
        }
    }
    cout<< "#"<< endl;
}