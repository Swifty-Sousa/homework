// Author: Christian F. Sousa
// data structures section 104
#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
using namespace std;
struct wordItem(){
   int count;
   string word;
   wordItem(){} 
   wordItem(string w)
    {
        word=w;
        count=0;
    }
};
void getStopWords(char *ingnoreFilename, string ignoreWords[])
// works
{
    ifstream datafile;
    string filename=ingnoreFilename;
    datafile.open(filename);
    if(datafile.fail())
    {
        cout<< "Error: file "<< filename<< " not found."<< endl;
        return;
    }
    string line;
    int count=0;
    int i=0;
    while(!datafile.eof())
    {
        getline(datafile,line);        
        ignoreWords[i]=line;
        i++;
    }
    datafile.close();
}
bool isStopWord(string word, string ignoreWords[])
// works
{
    for(int i=0; i<50; i++)
    {
        if(word==ignoreWords[i])
        {
            return true;
        }
    }
    return false;
}
void arrayX2(int *&aptr, int *size)
// works
{
    int newsize= *size*2;
    int *newarray= new int[newsize];
    for(int i=0; i<*size;i++)
    {
        newarray[i]=aptr[i];
    }
    free(aptr);
    aptr=newarray;
    *size=newsize;
}
int getTotalNumberNonStopWords(wordItem list[], int length)
// works
{
    int count=0;
    for(int i=0;i<length; i++)
    {
        count+= list[i].count;
    }
    return count;
}
void arraySort(wordItem list[], int length)
{
    wordItem holder1;
    wordItem holder2;
    for(int i=0; i<lengthi-1; i++)
    {
        if(list[i].count<list[i+1].count)
        {
            holder1=list[i];
            holder2=list[i+1];
            list[i]=holder2;
            list[i+1]=holder1;
            i=-1;
        }
    }
}

void printTopN(wordItem list[], int N)
// works
{
    for(int i=0; i<N; i++)
    {
        cout<< list[i].count<<" - "<< list[i].word<< endl;
    }
}
int ismywords(wordItem *&array[],string item , int numWords)
{
    for(int i=0;i< numWords; i++)
    {
        if(array[i].word=item)
        {
            return i;
        }
    }
    return -1;
}
int main(int argc, char *argv[])
{
    if(argc!=3)
    {
        return -1;
    }
    wordItem *mywords = new wordItem [100];
    int arraysize=100;
    int numWords=0; // this is the number of unique words in mywords[]
    string ignoreWords[50];
    int topN=stoi(argv[1])
    readfile= argv[2];
    getStopWords(argv[3],ignoreWords[50]);
    ifstream datafile;
    datafile.open();
    if(datafile.fail())
    {
        cout<< "Error file not found"<< enld;
    }
    string line;
    string item;
    int hold;
    while(getline(datafile, line)
    {
        stiringstream ss(line)
       while(ss.good()) 
       {
           ss>> item;
           if(isStopWord(item,ignoreWords))
           {
               continue;
           }
           x=ismywords(mywords[],item,numWords);
           else if(x!=-1)
           {
               mywords[x].count++;
           }
           else
           {
               if(numWords==arraysize)
               {
                   arrayX2(mywords[],&arraysize);
               }
               mywords[numWords+1]=wordItem(item);
           }

       }
    }

    

}