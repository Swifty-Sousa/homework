int * makeNewArray(int input[], int is,int target)
{
    int count=0;
    for(int i=0;i<is;i++)
    {
        if(input[i]>target)
        {
            count++;
        }
    }
    int holder=0;
    int *array=new int[count];
    for(int i=0;i<is;i++)
    {
        if(input[i]>target)
        {
            array[holder]=input[i];
            holder++;
        }
    }
    return array;
}
node * AddNewNodeSum(node *head,int target)
{
    int sum=0;
    node *temp=head;
    node *insert;
    while(temp!=NULL)
    {
        if(temp->value==target)
        {
            sum= temp->next->value +temp->prev->value;
            insert->next=temp->next;
            temp->next->prev=insert;
            cout<< "here"<< endl;
            insert->prev=temp;
            temp->next=insert;
            insert->value=sum;
            break;
        }
        temp=temp->next;
    }
    return head;
}