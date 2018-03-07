//Author: Christian F. Sousa
// CSCI 2270 Data Structures: section 104
#include<iostream>
#include"MovieTree.hpp"
using namespace std;
MovieTree::MovieTree()
{
    root= NULL;
}
MovieTree::~MovieTree()
{
}
void MovieTree::printMovieInventory()
{

}
int MovieTree::countMovieNodes()
{

} 




// might niot need this im not sure yet.
void deleteLL(MovieNodeBST * head)
{
    * MovieNodeBST temp = head;
    while(temp!=NULL)
    {
        *MovieNodeBST temp2= temp;
        temp=temp->next;
        delete temp2
    }
    delete temp;
}
//we will see




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
void MovieTree::DeleteAll(MovieNodeBST * node)
{

}
void MovieTree::printMovieInventory(MovieNodeBST * node)
{

}
void MovieTree::countMovieNodes(MovieNodeBST * , int *c)
{

}
* MovieNodeBST MovieTree::searchBST(MovieNodeBST * rnode, string title)
{

}
* MovieNodeBST MovieTree::searchBST(MovieNodeLL * head, string title)
{

}
* MovieNodeBST MovieTree::treeMinimum(MovieNodeBST * rnode)
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

int main(void)
{
    int command;
    while(true)
    {
        command=menu();
        if(command==1)
        {
            << "Enter title"<<endl;
        }
        else if(command==2)
        {

        }
        else if(command==3)
        {

        }
        else if(command==4)
        {
            "Enter title"<< endl;
        }
        else if(command==5)
        {

        }
        else if(command==6)
        {
            cout<< "Goodbye!"<< endl;
            return;
        }
    }
}