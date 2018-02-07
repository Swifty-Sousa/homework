// AUthor: Christian F. Sousa
// CSCI 2270 Data Strucures section 104
#include<iostream>
#include<fstream>
using namespace std;
struct node
{
    int key;
    node *next;
    node();
    node(int x)
    {
        key=x;
        next=NULL;
    }
};
void insert(int key, int value,node *head)
{
    node *now=head;
    while(now!=NULL)
    {
        if(now->key==key)
        {
            node *a= new node(value);
            a->next=now->next;
            now->next=a;
        }
        now=now->next;
    }
}
int main(void)
{
    node *head = new node(1);
    node *n= new node(2);
    head->next=n;
    node *n2= new node(3);
    n->next=n2;
    node *n3= new node(4);
    n2->next= n3;
    node *n4= new node(5);
    n3->next= n4;
    node *y= head;
    cout<< "orignial Linked list values"<<endl;
    while(y!=NULL)
    {
        cout<< y->key<<endl;
        y=y->next;
    }
    cout<< endl;
    cout<< "# # #"<< endl;
    cout<< endl;
    cout<< "Now Printing with inserts"<< endl;
    y=head;
    while(y!=NULL)
    {
        if(y->key%2==0)
        {
            insert(y->key,999,y);
        }
        y=y->next;
    }
    y=head;
    while(y!=NULL)
    {
        cout<< y->key<<endl;
        y=y->next;
    }
}
