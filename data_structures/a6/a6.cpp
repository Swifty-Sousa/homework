#include<iostream>
#include"MovieTree.hpp"
#include<sstream>
#include<string>
// implemntaitons of class fuctions.
MovieTree::MovieTree()
{
    root= NULL;
}
MovieTree::~MovieTree()
{
    DeleteAll(root);
}
void printLL(MovieNodeLL *temp)
{
    while(temp!=NULL)
    {
        cout<<"Movie: "<< temp->title<< " "<< temp->quantity<< endl;
        temp=temp->next;
    }
}
void recursiveprintnode(MovieNodeBST *node)
{
    while(node !=NULL)
    {
        recursiveprintnode(node->leftChild);
        printLL(node);
        recursiveprintnode(node->rightChild);
    }
}
void MovieTree::printMovieInventory()
{
    MovieNodeBST *node= root;
    // now we do in order tree traversal
    // helper fuction above to print out all the elements in the LL
}
int countLLelements(MovieNodeLL * temp)
{
    int count =0;
    while(temp!=NULL)
    {
        count+=temp->quantity;
        temp =temp->next;
    }
    return count;
}

void MovieTree::countMovieNodes(MovieNodeBST *node, int *c)
{
    if(root==NULL)
    {
        c=0;
        return;
    }
    else
    {
        if(node!=NULL)
        {
            c+= countLLelements(node->head);
            countMovieNodes(node->leftChild, c);
            countMovieNodes(node->rightChild, c);
        }
    }

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
    char letter =title[0];

}
void MovieTree::addMovieNode(int ranking, string title, int ry, int q)
{

}
void MovieTree::findMovie(string title)
{
    MovieNodeBST * holder= searchBST(root, title);
    if(holder==NULL)
    {
        cout<< "Movie not found."<< endl;
        return;
    }
    MovieNodeLL* movie= searchLL(holder->head, title);
    if(movie==NULL)
    {
        cout<< "Movie not found."<<endl;
        return;
    }
    cout<< "Movie Info:"<< endl;
    cout<< "==========="<< endl;
    cout<< "Ranking:"<< movie->ranking<< endl;
    cout<< "Title:"<< movie->title<< endl;
    cout<< "Year:"<<movie->year<< endl;
    cout<< "Quantity:"<< movie->quantity<< endl;
}
void MovieTree::rentMovie(string title)
{
        MovieNodeBST * holder= searchBST(root, title);
    if(holder==NULL)
    {
        cout<< "Movie not found."<< endl;
        return;
    }
    MovieNodeLL* movie= searchLL(holder->head, title);
    if(movie==NULL)
    {
        cout<< "Movie not found."<<endl;
        return;
    }
    cout<< "Movie has been rented."<<endl;
    cout<< "Movie Info:"<< endl;
    cout<< "==========="<< endl;
    cout<< "Ranking:"<< movie->ranking<< endl;
    cout<< "Title:"<< movie->title<< endl;
    cout<< "Year:"<<movie->year<< endl;
    cout<< "Quantity:"<< (movie->quantity-1)<< endl; 
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
MovieNodeBST* MovieTree::searchBST(MovieNodeBST * node, string title)
{
    char t=title[0];
    if(node->letter==t)
    {
        //cout<< node->letter<< " compared too "<< t<< endl;
        //cout<< "found match"<< endl;
        return node;
    }
    else if(node->letter>t && node->leftChild!=NULL)
    {
        //cout<< node->letter << " compared to "<< t<< endl;
        return searchBST(node->leftChild, title);
    }
    else if(node->letter<t&& node->rightChild!=NULL)
    {
        //cout<< node->letter<< " compared too "<< t<< endl;
        return searchBST(node->rightChild, title);
    }
    else
    {
        return NULL;
    }

}
MovieNodeBST *  MovieTree::searchLL(MovieNodeLL * head, string target)
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

