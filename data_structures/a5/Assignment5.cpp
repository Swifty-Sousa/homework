//Author: Christian F. Sousa
// CSCI 2270 Data Structures: section 104
#include<iostream>
#include"Queue.h"
using namespace std;
void mainmenu()
{
    int x;
    cout<< "======Main Menu======"<<endl;
    cout<< "1. Enqueue Word"<< endl;
    cout<< "2. Dequeue Word"<< endl;
    cout<< "3. Print queue"<< endl;
    cout<< "4. Enqueue sentance" << endl;
    cout<< "5. Quit"<< endl;
    cin>>x;
}
int main(void)
{
    int command;
    while(true)
    {
       command=mainmenu();
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
           cout<< "Goodbye!"<< endl;
       }
    }

}