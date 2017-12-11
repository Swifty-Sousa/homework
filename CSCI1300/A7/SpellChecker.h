// Author: Christian Sousa
// TA: Thomas Lillis

#ifndef SPELLCHECKER_H
#define SPELLCHECKER_H
using namespace std;

class SpellChecker
{
    public:
        SpellChecker();
        SpellChecker(string);
        SpellChecker(string, string, string);

        char getStartMarker();
        char getEndMarker();
        bool setStartMarker(char);
        bool setEndMarker(char);
        bool readValidWords(string);
        bool readCorrectedWords(string);
        string language;
        string repair(string);
        string validwords[10000];
        string incorrectwords[10000];
        string correctedwords[10000];


    private:
        string filecspelling;
        string fileispelling;
        char start_marker='~';
        char end_marker= '~';
        int matches;
        int matches2;

    
}; 
#endif
