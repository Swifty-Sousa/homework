// Author: Christian F. Sousa
// CSCI2270 Data Strucrtures section 104
#include<iostream>
using namespace std;
struct city{
    string name;
    string value; 
    city ->next;
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
void BuildNetwork()
{

}
int main()
{
    int command;
    string baseCities[10];
    baseCities[0]="Los Angles":
    baseCities[1]="Pheonix";
    baseCities[2]="Denver";
    baseCities[3]="Dallas";

    command =MainMenu();
    while(true)
    {
        if(command==0)
        {
            return 0;
        }   
    }
}