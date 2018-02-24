// this is a sandbox for doing midterm practice problems, there will not be comments or explanation
// this is just where i wrote everything and then pasted it into the autor grader beacause i like vim plugins
void findMax()
{
    Node *temp=head;
    int chigh=0;
    while(temp!=NULL)
    {
        if(temp->key>chigh)
        {
            chigh=temp->key;
        }
        temp=temp->next;
    }
    cout<< chigh<< endl;
}
void Queue::enqueue(node *newnode)
{
    if(head==NULL)
    {
        head=newnode;
        tail=newnode;
    }
    tail->next=newnode;
    newnode->next=NULL;
    tail=newnode;
}
int ShiftArray(Product array[],int size,int target)
{
    for(int i=0;i<size;i++)
    {
        if(array[i].price==target)
        {
            for(int k=i;k<size-1;k++)
            {
                array[k]=array[k+1];
            }
            size--;
        }
    }
    return size;
}
string commonRepeatingElement(Product array[], int leng)
{
    string words[leng];
    int counts[leng];
    int icounter=0;
    int max=0;
    int index;
    bool found=false;
    for(int i=0;i<leng;i++)
    {
        for(int k=0;k<leng;k++)
        {
            if(array[i].pname==words[k])
            {
                counts[k]++;
                found=true;
            }

        }
        if(!found)
        {
            words[icounter]=array[i].pname;
            counts[icounter]=1;
        }
    }
    for(int i=0; i<leng;i++)
    {
        if(counts[i]>max)
        {
            max=counts[i];
            index=i;
        }
    }
    return words[index];

}
int *CopyArray(int array[], int leng, int val)
{
    int count=0;
    for(int i=0; i<leng;i++)
    {
        if(array[i]==val)
        {
            count++;
        }
    }
    int size=leng-count;
    int holder=0;
    int *arrayb[size];
    for(int i=0;i<leng;i++)
    {
        if(array[i]==val)
        {
            holder++;
            continue;
        }
        else
        {
            *arrayb[i]=array[i-holder];
        }
    }
    return *arrayb;
}