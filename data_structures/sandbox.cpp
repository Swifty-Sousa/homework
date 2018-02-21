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