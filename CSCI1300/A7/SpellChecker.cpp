//Author: Christian Sousa
// Ta: Thomas Lillis
#include<iostream>
using namespace std;
#include<fstream>
#include<string>
#include"SpellChecker.h"

SpellChecker::SpellChecker()
{
    matches=0;
    matches2=0;
}// default constructor

SpellChecker::SpellChecker(string ilang) 
// ilnag is the imput language,  this is the second constructor   
{
    language=ilang;
    matches=0;
    matches2=0;
}
SpellChecker::SpellChecker(string ilang, string cspelling, string ispelling)
// gives language and filenames
{
    language=ilang;
    filecspelling= cspelling;
    fileispelling= ispelling;
    matches=0;
    matches2=0;

}
// this fuction takes in no paramiter and returns the charater that the start maker is set to 
char SpellChecker::getStartMarker()
{
    return start_marker;
}
// this fuction takes in no parameters and returns the character that the end maker is set to 
char SpellChecker::getEndMarker()
{
    return end_marker;
}
// this fuction takes in a charater and sets the startmarker to that charater
// then the fuction returns true
bool SpellChecker::setStartMarker(char isc)
{
    start_marker= isc;
    return true;
}
// this fuction takes in a character and sets the end marker to that char
// then returns 
bool SpellChecker::setEndMarker(char iec)
{
    end_marker=iec;
    return true;
}
/* this fuction takes in a file name
it opens the file and reads in each line (that is always one word);
closes the file
then it puts each linee(word) in an array and returns true;
returns false if the file fails to open
*/
bool SpellChecker::readValidWords(string filename)
{

    ifstream datafile;
    datafile.open(filename);
    if (datafile.fail())
    {
        return false;
    }
    string str;
    int linenumber=0;
    while(!datafile.eof())
    {
        getline(datafile, str);
        for(int i=0; i<str.length(); i++)
        {
        str[i]=tolower(str[i]);
        }
        validwords[matches]=str;
        matches++;
    }
    datafile.close();
    return true;

}

//this is a support I copy pasted from MY ANSWER to one of the recitaion activities
int Split(string str, char x ,string array[],int size)
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
    size= size + 1;
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
/*
this fuction take in a filename 
reads in each line
parses each line on the tab character 
puts the first word in an array 
puts the second one in another array at the corresponding index
returns true
returns falsee if the file fails to open
*/
bool SpellChecker::readCorrectedWords(string filename)
{
    string holderA[2];
    string str;
    int count;
    // this split algorithm is from one of the recitation activites
    
    ifstream datafile;
    datafile.open(filename);
    if(datafile.fail())
    {
        return false;
    }
   
    while(!datafile.eof())
    {
        getline(datafile, str);
        for(int i=0; i<str.length(); i++)
        {   
            if(str[i]!='\t')
            str[i]=tolower(str[i]);
        }
        Split(str,'\t' , holderA, count);
        correctedwords[matches2]=holderA[1];
        incorrectwords[matches2]=holderA[0];
        matches2++;        
    }
    datafile.close();
    return true;
}

/*this fuction takes in a string 
convers everything to lowercase
counts how many words are int the sentace by counting spaces
removes all punctuation 
pareses the sentace at spaces and puts it in an array 
for each indivdial word in the sentace(in an array at this point)
{
    compares to all the vlaid words
        if it is the same as any of the valid words
            puts the word int a string with a space charater before it
            breaks
    compares  to all the misspelled words
        if it is the same as any of these words
            puts the corrected word in the final string with a space character in front\
            
    if it has not done either of the fuctions above it puts the word in the final string between the start char and end char
    erases the first charater of the final strinf (will always be a space character)
    returns the final string;
}
*/


string SpellChecker::repair(string sentance)
{


for(int i=0; i<sentance.length(); i++)// this converts everything in the string to lowercase
    {
        sentance[i]= tolower(sentance[i]);
    }
int wordcount=1;
for(int i=0; i<sentance.length();i++)
    {
       if(sentance[i]== ' ')
       {
           wordcount++; // this counts the total number of words in the string
       } 
    }
    string punct=".,!$*&^%${}:-";
for(int i=0; i<sentance.length(); i++) // this removes the puctuation
    {
        for(int j=0; j<punct.length();j++)
        {
            if(sentance[i]==punct[j])
            {
                sentance.erase(i,1);
            }
        }
    }
string temp[wordcount];
Split(sentance,' ',temp, 3);
string finalstring="";
bool isvalid= false;
for(int i=0; i<wordcount; i++) 
    {
       for(int j=0; j<matches; j++)
        {
            isvalid=false;
           if(temp[i]==validwords[j])
           {
               finalstring=finalstring+ ' '+temp[i];
               isvalid=true;
               break;
           }
        }
        bool iscorrected=false;
        if(isvalid==false)
        {   
            
            for(int k=0; k < matches2; k++)
            {
                //cout << incorrectwords[k] << endl;
               if(temp[i]==incorrectwords[k])
               {
                   finalstring =finalstring + ' '+correctedwords[k];
                   iscorrected=true;
               }

            }
        }
        //cout << isvalid << endl;
        //cout << iscorrected << endl;
        if (isvalid==false && iscorrected==false)
        {
            finalstring=finalstring + ' '+ start_marker + temp[i] +  end_marker;
        }
    }

finalstring.erase(0,1);
return finalstring;

}
















