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
    cout<< " Enter a command"<< endl;
    cin>> command;
    return  command;
}
int main(int argc, char * argv[])
{ 
    int command;
    CommunicationNetwork a;
    a.buildNetwork();
    while(true)
    {
        int command=mainmenu();
        if(command==1)
        {
            
        }
        if(command==2)
        {

        }
        if(command==3)
        {

        }
        if(command==4)
        {

        }
        if(command==5)
        {

        }
        if(command==6)
        {
            
        }
        if(command==7)
        {
            cout<< "Goodbye!"<< endl;
        }

    }
}