#include"Queue.h"

Queue::Queue(int num)
{
    queuesize=num;
    queueHead=0;
    queueTail=0;
    queuecount=0;
    arrayQueue= new string[num];
}
