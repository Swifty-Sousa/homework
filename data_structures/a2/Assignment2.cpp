// Author: Christian F. Sousa
// data structures section 104
#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
using namespace std;
struct wordItem{
   int count;
   string word;
   wordItem(){} 
   wordItem(string w)
    {
        word=w;
        count=1;
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
void arrayX2(wordItem *&aptr, int *size)
{
    *size=*size*2;
    wordItem *newarray= new wordItem[*size];
    for(int i=0; i<*size/2;i++)
    {
        newarray[i]=aptr[i];
    }
    delete [] aptr;
    aptr=newarray;
}
int getTotalNumberNonStopWords(wordItem list[], int length)
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
    for(int j=1;j<length;j++)
    {
        wordItem key=list[j];
        int i=j-1;
        while(i>=0&& list[i].count<key.count)
        {
            list[i+1]=list[i];
            i--;
        }
        list[i+1]=key;
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
int ismywords(wordItem *&array,string item , int numWords)
{
    for(int i=0;i< numWords; i++)
    {
        if(array[i].word==item)
        {
            return i;
        }
    }
    return -1;
}
int main(int argc, char *argv[])
{
    wordItem *mywords = new wordItem [100];
    int arraysize=100;
    int numWords=0; // this is the number of unique words in mywords[]
    int adcounter=0; // is the int that keeps track of how many times the array is doubled
    string ignoreWords[50];
    int topN=stoi(argv[1]);
    string readfile= argv[2];
    getStopWords(argv[3],ignoreWords);
    ifstream datafile;
    datafile.open(readfile);
    if(datafile.fail())
    {
        cout<< "Error file not found"<< endl;
    }
    string line;
    string item;
    int x;// used as a comparison holder a few lines down
    while(datafile>>line)
    {
       stringstream ss(line);
       while(ss.good()) 
       {
           ss>> item;
           if(isStopWord(item,ignoreWords))
           {
               continue;
           }
           x=ismywords(mywords,item,numWords);
           if(x!=-1)
           {
               mywords[x].count=mywords[x].count+1;
           }
           else
           {
               if(numWords==arraysize)
               {
                   arrayX2(mywords,&arraysize);
                   adcounter++;
               }
               mywords[numWords]=wordItem(item);
               numWords++;
           }
       }
    }
    datafile.close();
    arraySort(mywords,numWords);
    printTopN(mywords, topN);
    cout<< "#"<< endl;
    cout<< "Array doubled: "<< adcounter<< endl;
    cout<< "#"<< endl;
    cout<< "Unique non-common words: "<<numWords<< endl;
    cout<< "#"<<endl;
    cout<< "Total non-common words: "<< getTotalNumberNonStopWords(mywords, numWords)<< endl;
    return 0;
}