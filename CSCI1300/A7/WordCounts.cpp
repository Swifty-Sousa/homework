// Author: Christian Sousa
// TA: Thomas Lillis 
#include "WordCounts.h"
#include<iostream>
#include<string>
#include<array>
using namespace std;
// this constructor sets all the values in the int array 
// initially to 0 so there is no left over from random memory
WordCounts::WordCounts()
{
for(int i=0; i<10000; i++)
    {
        counts[i]=0; 
    }
}
WordCounts::~WordCounts(){};
// my deconstructor
// Split is my parse function from one of the recitattion activities
// is a support fuction for some other class member fuctions

int Split(string str, char x ,string array[])
{
    int i=0;
    int j=0;
    int k=0;
    int c=0;
    int count=0;
    if (str=="")
        {
            return 0;
        }
        
    
    str= str + x;
    while(i<str.length())
    {
        if(str[i]==x)
        {
            array[c]=str.substr(j,i-j);
            j=i+1;
            c++;
            count++;
        }
        i++;
    }
    return count;
}
/* this fuction takes in a string, and figures out how many words are in it
by counting the number of spaces with an initial count of 1
*/
int countspaces(string sentance)
{
    int spaces=1;
    for(int i=0; i<sentance.length(); i++)
    {
        if(sentance[i]== ' ')
        {
            spaces++;
        
        }
    }
    return spaces;
}

/* this fuction takes in a string, 
removes all the puctiation
checks to see if the words in the string all ready exsist in the word array;
if they exsist, incremests the value of and int array at the corresponding index
if it does not exsits it add thee word to the words array and increments the count at the corresponding 
point in the int array
*/
void WordCounts::tallyWords(string sentance)
{
    string punct=".,!$*?&^%${}:-";
    for(int i=0; i<sentance.length(); i++) // this removes all the puctuation
    {
        for(int j=0; j<punct.length();j++)
        {
            if(sentance[i]==punct[j])
            {
                sentance.erase(i,1);
                i=0;
            }
        }    
    }
    for(int i=0; i<sentance.length(); i++)
    {
        sentance[i]=tolower(sentance[i]);
    }
    bool flag=false;
    int spaces=countspaces(sentance);
    string addwords[spaces];// this is the array of words trying to add
    Split(sentance,' ', addwords);
    for(int i=0; i<spaces; i++)
    {
        for(int j=0; j<arraysize; j++)
        {
        //cout<< addwords[i]<< ' '<< arraysize<<" "<< counts[j]<<endl; 
            if(wordstotally[j]==addwords[i])
            {
                counts[j]+=1;
                flag=true;
                //cout<< "@@@"<< wordstotally[j]<<counts[j]<<endl;
                break;
              
            }
            
        }
        if(flag==false)
        {
            wordstotally[arraysize-1]=addwords[i];
            counts[arraysize-1]+=1;
            arraysize++;
        }
        flag=false;
    }

}
// this ffuction takes in a string and finds it in the array 
//returns the count that corresponds to that word
// will no do anything if word is not in the array 
int WordCounts::getTally(string something)
{
    for(int i=0; i<10000; i++)
    {
        if(wordstotally[i]== something)
        {
            return counts[i];
        }
    }
    return 0;
}
// this fuction resets all the counts to zero
void WordCounts::resetTally()
{
    for(int i=0; i<10000; i++)
    {
        counts[i]=0;
    }
}
// this fuction bubble storts the arrays by highest count,
// it them fills the given arrays to the n points
//if the fuction is given n=0 it immediatly returns zero
// the fiction still returns zero otherwise bucause
// thats what cog wants.
int WordCounts::mostTimes(string outputwords[], int outputcount[], int n)
{
    if(n==0)
    {
        return 0;
    }
    int Acountsholder;
    int Bcountsholder;
    string AWordstotoallyholder;
    string BWordstotallyholder;
    for(int i=0; i<10000; i++)
    {
        if(counts[i]<counts[i+1])
        {
            Acountsholder= counts[i];
            Bcountsholder= counts[i+1];
            AWordstotoallyholder= wordstotally[i];
            BWordstotallyholder= wordstotally[i+1];
            counts[i]=Bcountsholder;
            counts[i+1]= Acountsholder;
            wordstotally[i]= BWordstotallyholder;
            wordstotally[i+1]= AWordstotoallyholder;
        }
    }
    for(int i=0; i <n; i++)
    {
        outputwords[i]=wordstotally[i];
        outputcount[i]=counts[i];
    }




return 0;
}