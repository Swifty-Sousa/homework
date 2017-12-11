// Author: Christian Sousa
// Thomas Lillis
#include<iostream>
#include"SpellChecker.h"
#include"WordCounts.h"
using namespace std;
// as always im doing the thing where i comment out the test cases
// I am not currently useing
int main()
{
SpellChecker esto("english", "test.txt" , "test2.txt");

cout<< "Testing Readvaid words"<< endl;
if(esto.readValidWords("test2.txt")==true)
{
    cout<< "success"<< endl;
}
else
{
    cout<< "failed"<< endl;
}
cout<< "testing read corrected words"<< endl;
if (esto.readCorrectedWords("test.txt")==true)
{
    cout<< "success"<< endl;
}
else 
{
    cout<< "failed"<< endl;
}

cout<< "testing repair"<< endl;
string x=esto.repair("hi !!tod!!ayy helo ha");
cout << x << endl;
/*
cout<< "testing tallywords" << endl;

WordCounts test;
test.tallyWords("hello hello !!!!five five five three");

string Words[3];
int Counts[3];
cout<< "testing motsatimes"<< endl;
test.mostTimes(Words, Counts, 3);
test.mostTimes(Words, Counts, 3);
i*/


return 0;
}