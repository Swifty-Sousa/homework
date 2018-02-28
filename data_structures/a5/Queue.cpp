#include"Queue.h"
#include<iostream>

Queue::Queue(int num)
{
    queueSize=num;//  maximum size of the Queue
    queueHead=0;//index for the beginning of the Queue
    queueTail=0;// index for the tail of the queue
    queueCount=0;// count of current items in the Queue
    arrayQueue= new string[num];
}
Queue::~Queue()
{
    delete arrayQueue;
    arrayQueue=NULL;
}
bool Queue::queueIsEmpty()
{
    if(queueCount==0)
    {
        return true;
    }
    else
    return false;
}
bool Queue::queueIsFull()
{
    if(queueCount==queueSize)
    {
        return true;
    }
    return false;
}
void Queue::printQueue()
{
    if(queueIsEmpty())
    {
        cout<< "Empty"<< endl;
        return;
    }
    if(queueHead==queueTail)
    {
        cout<<queueHead<<": "<< arrayQueue[queueHead]<< endl;
    }
    int temp=queueHead;
    while(temp!=queueTail)
    {
        cout<< temp<< ": "<<arrayQueue[temp]<< endl;
        if(temp>=queueCount)
        {
            temp=0;
        }
        temp++;
    }

}
int increment(int a, int b)
{
   a++;
   if(a>b) 
   {
       return 0;
   }
   else
   {
       return a;
   }
}
void Queue::enqueue(string word)
{
    if(queueIsFull())
    {
        cout<< "Queue is full."<< endl;
        return;
    }
    arrayQueue[queueTail]=word;
    queueCount++;
    queueTail++;
    if(queueTail>=queueSize)
    {
        queueTail=0;
    }
    cout<< "E: "<< word<< endl;
    cout<< "H: "<< queueHead<< endl;
    cout<< "T: "<< queueTail<< endl;
}


void Queue::dequeue()
{
    if(queueIsEmpty())
    {
        cout<<"Queue is empty."<< endl;
        return;
    }
    cout<< "H: "<< increment(queueHead,queueCount)<< endl;
    cout<< "T: "<< queueTail<< endl;
    cout<< "word: "<< arrayQueue[queueHead]<< endl;
    queueHead= increment(queueHead, queueCount);
    queueCount--;
}
