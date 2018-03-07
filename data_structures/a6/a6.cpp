//Author: Christian F. Sousa
// CSCI 2270 Data Structures: section 104
#include<iostream>
#include"MovieTree.hpp"
using namespace std;
// implemntaitons of class fuctions.
MovieTree::MovieTree()
{
    root= NULL;
}
MovieTree::~MovieTree()
{
    DeleteAll(root);
}
void MovieTree::printMovieInventory()
{

}
int countLLelements(movieNodeLL * temp)
{
    int count=0;
    while(temp->Next !=NULL)
    {
        count++;
    }
    return count;
}
int summ(*MovieNodeBST star)
{
    return (countLLelements(star->leftchild)+ countLLelements(star->rightchild))
}
int MovieTree::countMovieNodes()
{
    int count;`
    * MovieNodeBST temp= treeMinimum(root);
    temp=temp->parent;
    while(true)
    {
        cout+=summ(temp);
        if(temp==root)
        {
            break;
        }
        temp=temp->parent;
    }
    // at this point we summed the right left side and 
    //the root so now for the right side
    while(temp->rightchild!=NULL)
    {
        temp=temp->rightchild;
    }
    // now we are at the bottom right
    temp=temp->parent;
    while(temp!=root)
    {
        count+= summ(temp);
        temp=temp->parent;
    }
    return count;

} 
// might not need this im not sure yet.
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
* MovieNodeBST MovieTree::searchLL(MovieNodeLL * head, string target)
{
    MovieNodeLL *temp= head;
    while(temp->next == NULL)
    {
        if(temp->title==target)
        {
            return temp;
        }
        temp=temp->next;
    }
    return NULL;
}
* MovieNodeBST MovieTree::treeMinimum(MovieNodeBST * rnode)
{
    while(rnode->leftchild!=NULL)
    {
        rnode=rnode->leftchild;
    }
    return rnode;
}


// below is the main menu for coderunner to take in.
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
            cout << "Enter title"<<endl;
        }
        else if(command==2)
        {

        }
        else if(command==3)
        {

        }
        else if(command==4)
        {
            cout<<"Enter title"<< endl;
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