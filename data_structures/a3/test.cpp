#include<iostream>
using namespace std;
using namespace std;
struct city{
    string cityName;
    string message; 
    city *next;
    city(){};
    city(string n, city *k, string m)
    {
        cityName=n;
        message=m;
        next=k;
    }
};
int main(void)
{
    city *a= new city("hello", NULL, "");
    city *a2= new city("Goodbye", NULL, "");
    city *c= new city("fail?", NULL,"");
    a->next=a2;
    city *temp=a;
    while(true)
    {
        if(temp->next==NULL)
        { 
        cout<< temp->cityName<< endl;
        temp->next=c;
        temp=temp->next;
        cout<< temp->cityName<< endl;
        break;
        }
        else
        {
        temp=temp->next;
        }
    }
}