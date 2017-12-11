// Author: Christian Sousa
// TA: Thomas Lillis 
#include<string>
#include<iostream>
using namespace std;
#ifndef WORDCOUNTS_H
#define WORDCOUNTS_H

class WordCounts
{
    public:
        WordCounts();
        ~WordCounts();
       void tallyWords(string);
       int getTally(string);
       void resetTally();
       int mostTimes(string [] ,int [] ,int ); 
        string wordstotally[10000];
        int counts[10000];
        int wordcounter=0;
        int arraysize=1;// used for size of array on line 189 in this file
};
#endif
