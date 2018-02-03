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
void insert()
int main(int argc, char *argv[])
{
    string ignoreWords[50];
    int topN=stoi(argv[1])
    readfile= argv[2];
    getStopWords(argv[3],ignoreWords[50]);
    

}