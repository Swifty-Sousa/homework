//Author: Christian F. Sousa
// CSCI 2270 Data Structures: section 104
#include<iostream>
#include"MovieTree.hpp"
using namespace std;

int menu()
{
    int command;
    //couts
    cout<< "======Main Menu======"<< endl;
    cout<< "1. Find Movie"<< endl;
    cout<< "2. Rent Movie"<< endl;
    cout<< "3. Print the inventory"<< endl;
    cout<< "4. Delete a movie" << endl;
    cout<< "5. Count the movies"<< endl;
    cout<< "6. Quit"<< endl;
    cin>> command;
    return command;
}

int main(void)
{
    MovieTree a;
    int command;
    string title;
    while(true)
    {
        command=menu();
        if(command==1)
        {
            cout << "Enter title"<<endl;
            getline(cin, title);
            a.findMovie(title);
        }
        else if(command==2)
        {
            cout<< "Enter Title"<< endl;
            getline(cin, title);
        }
        else if(command==3)
        {
            a.printMovieInventory();
        }
        else if(command==4)
        {
            cout<<"Enter title"<< endl;
            getline(cin, title);
            a.deleteMovieNode(title);
        }
        else if(command==5)
        {
            cout<<"Tree contains: "<<a.countMovieNodes()<< " movies"<< endl;
        }
        else if(command==6)
        {
            cout<< "Goodbye!"<< endl;
            return 0;
        }
    }
}
