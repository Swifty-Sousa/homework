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
    }
}
void Queue::enqueue()
{

}
void Queue::enqueueSentence()
{
    if(queueIsFull())
    {
        cout<< "Queue is full"<< endl;
    }
}
void Queue::dequeue()
{
    if(queueIsEmpty())
    {
        cout<<"Queue si empty"<< endl;
        return;
    }
}
