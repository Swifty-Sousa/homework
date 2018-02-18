#include "CommunicationNetwork.h"
#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;
// Author: Christian F. Sousa
// CSCI 2270 data structures section 104
CommunicationNetwork::CommunicationNetwork(){}
// this is the default constructor
CommunicationNetwork::~CommunicationNetwork()
{
    deleteNetwork();
}
// this is the deconstructor I have made
void CommunicationNetwork::addCity(string cityn, string prev)
{
    City *newc= new City(cityn, NULL, NULL, "");
    City *temp=head;
    if(head== NULL)
    {
        head=newc;
        tail=head;
    }
    else if (prev=="")
    {
        tail->next=newc;
        newc->previous=tail;
        tail=newc;
    }
    else if(prev=="First")
    {
        head->previous=newc;
        newc->next=head;
        head=newc;
    }
    else
    {
        while(temp!=NULL)
        {
            if(temp->cityName==prev)
            {
                newc->next=temp->next;
                newc->previous=temp;
                temp->next->previous=newc;
                temp->next=newc;
                break;
            }
            temp=temp->next;
        }
    }
}
void CommunicationNetwork::buildNetwork()
{
    head= new City("Los Angeles",NULL,NULL, "");
    head-> previous=NULL;
    City *x= new City("Phoenix", NULL,NULL,"");
    head->next=x;
    x->previous=head;
    City *x1= new City("Denver", NULL,NULL,"");
    x1->previous=x;
    x->next= x1;
    City *x2=new City("Dallas", NULL,NULL,"");
    x1->next=x2;
    x2-> previous=x1;
    City *x3= new City("St. Louis", NULL,NULL,"");
    x2-> next=x3;
    x3->previous=x2;
    City *x4= new City("Chicago", NULL,NULL,"");
    x3 ->next= x4;
    x4->previous= x3;
    City *b1= new City("Atlanta", NULL, NULL, "");
    x4-> next=b1;
    b1-> previous=x4;
    City *x5= new City("Washington, D.C.", NULL,NULL,"");
    b1->next=x5;
    x5->previous=b1;
    City *x6= new City("New York", NULL,NULL,""); 
    x5->next=x6;
    x6->previous= x5;
    City *x7= new City("Boston", NULL,NULL,"");
    x6-> next=x7;
    x7-> previous=x6;
    tail=x7;
} 
void CommunicationNetwork::transmitMsg(char * filename)
{
    if(head==NULL)
    {
        cout<< "Empty list"<< endl;
        return;
    }
    ifstream datafile;
    datafile.open(filename);
    if (datafile.fail())
    {
        cout<< "file not found"<< endl;
    }
    string line;
    string item;
    while(datafile>>line)
    {
        stringstream ss(line);
        ss<<line;
        while(ss.good())
        {
            ss>>item;
            City *temp=head;
            while(temp->next!=NULL)
            {
                cout<<temp->cityName<< " received "<< item<< endl;
                temp=temp->next;
            }
             cout<< temp->cityName<< " received "<< item<< endl;
            temp=temp->previous;
            while(temp->previous!=NULL)
            {
                cout<<temp->cityName<< " received "<< item<< endl;
                temp=temp->previous;
            }
            cout<< temp->cityName<< " received "<< item << endl;
        }
    }
}
void CommunicationNetwork::printNetwork()
{
    City *temp=head;
    string ar= "<->";
    cout<< "===CURRENT PATH==="<<endl;
    cout<< "NULL <-";
    while(temp!= tail)
    {
        cout<<" "<<temp->cityName<< " " << ar;
        temp=temp->next;
    }
    cout<< " " <<tail->cityName<< " -> NULL"<< endl;
    cout<< "=================="<< endl;

}
void CommunicationNetwork::deleteCity(string target)
{
   bool found=false;
   City *temp=head;
   while(temp!=NULL) 
   {
       if(temp->cityName==target && temp->previous==NULL)
       {
           head=temp->next;
           temp->next->previous=NULL;
           delete temp;
           found=true;
           break;
       }
       else if(temp->cityName==target&& temp->next==NULL)
       {
           tail=temp->previous;
           temp->previous->next=NULL;
           delete temp;
           found=true;
           break;
       }
       else if(temp->cityName==target)
       {
          temp->previous->next=temp->next;
          temp->next->previous=temp->previous;
          delete temp;
          found=true;
          break;
       }
       temp=temp->next;
   }
   if(found==false)
   {
       cout<< target<< " not found"<< endl;
   }
}
void CommunicationNetwork::deleteNetwork()
{
    City *temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
        cout<<"deleting "<< temp->previous->cityName<< endl;
        deleteCity(temp->previous->cityName);
    }
    cout<< "deleting "<< temp->cityName<< endl;
    deleteCity(temp->cityName);
}
