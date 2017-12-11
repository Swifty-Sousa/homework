#include<iostream>
using namespace std;
#include"Assignment6.cpp"
#include<fstream>
#include<string>
// as always I have my classic commented out main so i can test each fucntion indivudually and therefore the main does 
// not have any sort of fluididty 

int main(void)
{
 /*
string x;
float y;
cout<< "Enter a file name"<< endl;
cin>> x;
y= avgCharsPerLine(x);
cout<< y<< endl;
return y;

string filen2;
float array[5][5];
cout<< "Enter a file name"<< endl;
cin>>filen2;
cout<< fillArray(filen2, array)<< endl;
return 0;

// for number 3
float numbers[5][5];
string filename;
cout<< "Enter File name"<< endl;
cin>> filename;
cout<< arrayStats(filename, numbers)<< endl;
*/

string users[6];
int ratings[6][50];
string filename;
cout<< "Enter File name"<< endl;
cin>> filename;
addBookRatings(filename, users, ratings);




}

