#include<iostrem>
#include"MovieTree.hpp"
#include<sstring>
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
void MovieTree::printMovieInventory()
{

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

