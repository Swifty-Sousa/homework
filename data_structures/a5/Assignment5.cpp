//Author: Christian F. Sousa
// CSCI 2270 Data Structures: section 104
#include<iostream>
#include"Queue.h"
using namespace std;
int mainmenu()
{
    int x;
    cout<< "======Main Menu====="<<endl;
    cout<< "1. Enqueue word"<< endl;
    cout<< "2. Dequeue word"<< endl;
    cout<< "3. Print queue"<< endl;
    cout<< "4. Enqueue sentence" << endl;
    cout<< "5. Quit"<< endl;
    cin>>x;
    return x;
}
int main(void)
{
    Queue esto(10);
    int command;
    string word;
    while(true)
    {
       command=mainmenu();
       if(command==1)
       {
        cout<< "word: ";
        cin>> word;
        esto.enqueue(word);
       }
       else if(command==2)
       {
        esto.dequeue();
       }
       else if(command==3)
       {
        esto.printQueue();   
       }
       else if(command==4)
       {
           string sentence;
        cout<< "sentence: ";
        getchar();
        getline(cin,sentence);
        esto.enqueueSentence(sentence);
       }
       else if(command==5)
       {
           cout<< "Goodbye!"<< endl;
           return 0;
       }
    }

}