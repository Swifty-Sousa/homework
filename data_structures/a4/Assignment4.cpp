//Author: Christian F. Sousa
// CSCI 2270 data structues, section 104
#include"CommunicationNetwork.h"
#include<iostream>
using namespace std;
int mainmenu()
{
    cout<< "======Main Menu======"<< endl;
    cout<< "1. Build Network"<< endl;
    cout<< "2. Print Network Path"<< endl;
    cout<< "3. Transmit Message Coast-To-Coast-To-Coast"<< endl;
    cout<< "4. Add City"<< endl;
    cout<< "5. Delete City"<< endl; 
    cout<< "6. Clear Network"<< endl;
    cout<< "7. Quit"<< endl;
    int command;
    cin>> command;
    return  command;
}
int main(int argc, char * argv[])
{ 
    int command;
    CommunicationNetwork a;
    while(true)
    {
        int command=mainmenu();
        string prev;
        string name;
        if(command==1)
        {
            a.buildNetwork();
            a.printNetwork(); 
        }
        if(command==2)
        {
            a.printNetwork();
        }
        if(command==3)
        {
            a.transmitMsg(argv[1]);
        }
        if(command==4)
        {
            cout<< "Enter a city name:"<< endl;
            cin>>name;
            cout<<"Enter a previous city name:"<< endl;
            cin>>prev;
            a.addCity(name, prev);
        }
        if(command==5)
        {
            cout<< "Enter a city name:"<< endl;
            cin>>name;
            a.deleteCity(name);
        }
        if(command==6)
        {
           a.deleteNetwork();
        }
        if(command==7)
        {
            cout<< "Goodbye!"<< endl;
            return 0;
        }

    }
}