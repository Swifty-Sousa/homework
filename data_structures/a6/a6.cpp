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
MovieNodeBST * MovieTree::treeMinimum(MovieNodeBST * rnode)
{
    rnode=rnode->rightChild;
    while(rnode->leftChild!=NULL)
    {
        rnode=rnode->leftChild;
    }
    return rnode;
} 
int deleteBSTnode(MovieNodeBST * node, MovieNodeBST * root)
{
	// child
    MovieNodeBST * minimum= treeMinimum(node);
    // it hurts that we have to account for this.
    if(node==root)
    {
        if(node->rightChild==NULL && node->leftChild== NULL)
        {
			delete node;
			return 0;
        }
		else if(node->rightChild==NULL && node->leftChild!=NULL)
		{
			root=node->leftChild;
			root->parent==NULL;
			delete node;
			return 0;
		}
		else if(node->rightChild!=NULL && node->leftChild==NULL)
		{
			root=node->rightChild;
			root->parent=NULL;
			delete node;
			return 0;
		}
		else
		{
			if(root->rightChild==minimum)	
			{
				root->leftChild->parent=root->rightChild;
				root=root->rightChild;
				root->parent=NULL;
				delete node;
				return 0;
			}
			else if(minimum->rightChild==NULL)
			{
				minimum->parent->leftChild=NULL;
				minimum->parent=NULL;
				minimum->leftChild=root->leftChild;
				root->leftChild->parent=minimum;
				minimum->rightChild=root->rightChild;
				minimum->rightChild->parent=minimum;
				root=minimum;
				delete node;
				return 0;
			}
			else
			{
				minimum->rightChild->parent=minimum->parent;
				minimum->rightChild=minimum->parent->leftChild;
				minimum->parent=NULL;
				minimum->rightChild=root->rightChild;
				root->rightChild->parent=minimum;
				minimum->leftChild=root->leftChild;
				root->leftChild->parent=minimum;
				minimum=root;
				delete node;
				return 0;
			}
		}
    }
    // if the node to be deleted has no child
    if(node->rightChild==NULL && node->leftChild== NULL)
    {
        if(node->parent->leftChild== node)
        {
            node->parent->leftChild=NULL;
            delete node;
            return 0;
        }
        else
        {
            node->parent->rightChild=NULL;
            delete node;
            return 0;
        } 
    }
    // if the node to be deleted has a leftchild but not a rightchild
    else if(node->rightChild==NULL &&node->leftChild!=NULL)
    {
        if(node->parent->leftChild== node)
        {
            node->parent->leftChild=node->leftChild;
            node->leftChild->parent=node->parent;
            delete node;
            return 0;
        }
        else
        {
            node->parent->rightChild=node->leftChild;
            node->leftChild->parent=node->parent;
            delete node;
            return 0;
        }    
    }
    //if the node to be deleted has a rightchild but not a leftchild
    else if(node->rightChild!=NULL &&node->leftChild==NULL)
    {
        if(node->parent->leftChild== node)
        {
            node->parent->leftChild=node->rightChild;
            node->rightChild->parent=node->parent;
            delete node;
            return 0;
        }
        else
        {
            node->parent->rightChild=node->rightChild;
            node->rightChild->parent=node->parent;
            delete node;
            return 0;
        }    
    }
    // node to be deleted has both left and right children
    else
    {
        //case one with two children
        if(node->leftChild==minimum)       
        {
            if(node->parent->leftChild=node)
            {
                node->parent->leftChild=node->rightChild;
                node->rightChild->parent=node->parent;
            }
            else
            {
                node->parent->rightChild=node->rightChild;
                node->rightChild->parent=node->parent;
            }
            minimum->leftChild=node->leftChild;
            node->leftChild->parent=minimum;
            delete node;
            return 0;
        }
        //case two with two children
        else if(minimum->rightChild==NULL)
        {
            if(node->parent->leftChild=node)
            {
                node->parent->leftChild=minimum;
                minimum->parent=node->parent;
            }
            else
            {
                node->parent->rightChild=minimum;
                minimum->parent=node->parent;
            }
			minimum->parent->leftChild=NULL;//as to not create and infinte loop when searching 
			minimum->rightChild=node->rightChild;
			node->rightChild->parent=minimum;
			minimum->leftChild=node->leftChild;
			node->leftChild->parent=minimum;
			delete node;
			return 0;
        }
		// case 3 with two childrem
		else
		{
			minimum->parent->leftChild=minimum->rightChild;
			minimum->rightChild->parent=minimum->parent;
            if(node->parent->leftChild=node)
            {
                node->parent->leftChild=minimum;
                minimum->parent=node->parent;
            }
            else
            {
                node->parent->rightChild=minimum;
                minimum->parent=node->parent;
            }
			minimum->rightChild=node->rightChild;
			node->rightChild->parent=minimum;
			minimum->leftChild=node->leftChild;
			node->leftChild->parent=minimum;
			return 0;
		}
    }
}

void MovieTree::deleteMovieNode(string title)
{
    MovieNodeBST * holder= searchBST(root, title);
    if(holder==NULL)
    {
        cout<< "Movie not found."<< endl;
        return;
    }
    else if (holder->head->next==NULL)
    {
        deleteBSTnode(holder, root);
    }
    MovieNodeLL* tail=holder->head;
    MovieNodeLL* tip =tail-> next;
    if(holder->head->title==title)
    {
        holder->head=tip;
        delete tail;
        return;
    }
    bool found=false;
    while(tip!=NULL)
    {
        if(tip->title==title)
        {
            found==true;
            break;
        }
        tail==tip;
        tip==tip->next;
    }
    if(!found)
    {
        cout<<"Movie not found." << endl;
        return;
    }
    else if(tip->next ==NULL)
    {
        delete tip;
        return;
    }
    else
    {
        tail->next=tip->next;
        tip->next =NULL;
        delete tip;
        return;
    }
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
