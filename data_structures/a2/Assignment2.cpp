// Author: Christian F. Sousa
// data structures section 104
#include<istream>
#include<fstream>
using namespace std;
struct text(){
   int count;
   string literal;
   text(){} 
   text(string w)
    {
        literal=w;
        count=0;
    }
};
void getStopWords(char *ingnoreFilename, string ignoreWords[])
// broken 
{
    ofstream datafile;
    string filename=->ingnoreFilename
    datafile.open(filename);
    if(datafile.fail())
    {
        cout<< "Error: file "<< filename<< " not found."<< enld;
        return;
    }
    string line;
    int count=0;
    while(!datafile.eof())
    {
        getline(datafile,line)        
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
int main(int argc, char *argv[])
{
    string *ReadFilename=&argv[2];
    string ingnoreFilename=argv[3];
    string ignoreWords[50];
    int topN=argv[1];

}