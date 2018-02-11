// Author: Christian F. Sousa
// CSCI2270 Data Strucrtures section 104
#include<iostream>
#include<fstream>
#include<sstream>
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
int MainMenu()
{
    cout<< "======Main Menu======"<< endl;
    cout<< "1. Build Network"<< endl;
    cout<< "2. Print Network Path"<<endl;
    cout<< "3. Transmit Message Coast-to-Coast"<< endl;
    cout<< "4. Add City"<< endl;
    cout<< "5. Quit"<< endl;
    int x;
    cin>>x;
    return x;
}
city *buildNetwork()
{
    city *x0= new city("Los Angeles", NULL, "");
    city *x1= new city("Phoenix",NULL,"");
    x0->next=x1;
    city *x2= new city("Denver", NULL, "");
    x1->next=x2;
    city *x3=new city("Dallas", NULL, "");
    x2->next=x3;
    city *x4= new city("St. Louis",NULL, "");
    x3->next=x4;
    city *x5= new city("Chicago",NULL,"");
    x4->next=x5;
    city *x6= new city("Atlanta",NULL,"");
    x5->next=x6;
    city *x7 = new city("Washington, D.C.",NULL,"");
    x6->next=x7;
    city *x8= new city("New York",NULL, "");
    x7->next =x8;
    city *x9 =new city ("Boston", NULL, "");
    x8->next= x9;
    return x0;
}
void printPath(city *head)
{
    cout<<"===Current Path==="<< endl;
    city *temp=head;
    string arrow=" -> ";
    while(temp!=NULL)
    {
        cout<< temp->cityName<<arrow;
        temp=temp->next;
    }
    cout<< "NULL"<< endl;
    cout<<"=================="<<endl;

}
void transmitMsg(city *head)
{
    ifstream datafile;
    datafile.open("messageIn.txt");
    if(datafile.fail())
    {
        cout<< "everything you know is a lie"<< endl;
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
            city *temp=head;
            while(temp!=NULL)
            {
                temp->message=item;
                cout<< temp->cityName<< " received "<<temp->message<< endl;
                temp->message="";
                temp=temp->next;
            }
        }
    }
    datafile.close();
}
city *addCity(city *head, city *previous, string cityName)
{
    city *insert= new city (cityName, NULL, "");
    if (head==nullptr)
    {
        head= insert;
    }
    else if(previous==nullptr)
    {
        insert->next=head;
        head=insert;
    }
    else
    {
        insert->next=previous->next;
        previous->next= insert;
    }
    return head;
}
city * search(city *head)
{

}
int main()
{
    int command;
    city *head;
    while(true)
    {
        command= MainMenu();
        cout<< "Command is "<< command<< endl;
        if(command==5)
        {
            cout<< "Goodbye!"<< endl;
            return 0;
        }
        else if (command==1)   
        {
           head= buildNetwork();
        }
        else if (command ==2)
        {
            printPath(head);
        }
        else if(commad==3)
        {

        }
        else if(command=4)
        {
            
        }
    }
}