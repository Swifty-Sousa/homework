//Author: Christian F. Sousa
// CSCI 2270 Data Structures: section 104
#include<iostream>
#include"MovieTree.hpp"
using namespace std;
MovieTree::MovieTree()
{

}
MovieTree::~MovieTree()
{
    // idk how to do this till I actually write the class
}
void MovieTree::printMovieInventory()
{

}
int MovieTree::countMovieNodes()
{

}
void MovieTree::deleteMovieNode(string title)
{

}
void MovieTree::addMovieNode(int ranking, string title, int ry, int q)
{

}
void MovieTree::findMovie(string title)
{

}
void MovieTree::rentMovie(string title)
{
    
}
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
    return command
}
int main(void)
{
    int command;
    while(true)
    {
        command=menu();
        if(command==1)
        {

        }
        else if(command==2)
        {

        }
        else if(command==3)
        {

        }
        else if(command==4)
        {

        }
        else if(command==5)
        {

        }
        else if(command==6)
        {
            return;
        }
    }
}