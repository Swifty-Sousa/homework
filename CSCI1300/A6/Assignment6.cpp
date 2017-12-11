// Author : Christian Sousa

// TA: Thomas Lillis

#include<iostream>
using namespace std;
#include<fstream>
#include<string>

// this is my parsing function from one of the recitation activities
//parses a string at a specific separator character and fills
// into an given array
void Split(string str, char x ,string array[])
{
    int i=0;
    int j=0;
    int k=0;
    int c=0;
    int count=0;
        
    
    str= str + x;
    while(i<str.length())
    {
        if(str[i]==x)
        {
            array[c]=str.substr(j,i-j);
            j=i+1;
            c++; // this is for my placing the substrings in the array
            
        }
        i++;
    }
}











/*
This function takes in a string paramiter for the name of the file it is suppost to do calculations on amd retruns a floating point value
of the average number of characters per line.
The function opens the file with the filename provided by the user.
it then gets each line and concatonates it into one big long string.
while this is happening there is also a counter goin gon keeing track of how many lines have been read in.
the functio then does string.lenght on the string to get the total # of chars in the string (also the number of chars in the file).
it then divides that by the count (which is the total number of lines int the file)
the fuction returns this floating point value.
*/



float avgCharsPerLine(string filename)
{
	ifstream file;
	file.open(filename);
	if (file.fail())
	{
		cout<< "File "<< filename<< " failed to open"<< endl;
		return -1;
	}
string str="";
string str2="";// this will be the string that has all the contents of the file.
float count=0;
	while (!file.eof())
	{
		getline(file, str);
		str2= str2 + str;// we do this as if you do judst str the values get overwirtten as it does not auto concatonate 
		count++;
	}
file.close();

float y =str2.length();


float average= y/count;
return average;

}

/*
this functionopens takes in a filename and a 2d array
the function opens the given file if it exisits 
it then reads in values form the file one line at a time 
the function does nothing with the very first line of the file
it takes every other line one by one and converts the string into a parsed string
array by calling split, IT then converts those strings to integers and passes them into the 
2d array given at the beginning of the function.
*/


int fillArray(string filename, float array[][5])
{
ifstream datafile;
string str="";
string str2= "";
datafile.open(filename);
if (datafile.fail())
	{
		cout<< "File " <<filename<< "Failed to open"<< endl;
		return 0;
	}
getline(datafile,str);// this ignors the first line of the file as it gets
int lines =0;// overwitten by the getline inside the while loop below
string holder[5];
while (!datafile.eof())
	{
		getline(datafile,str);
		Split(str, ',', holder);// this splits the string str from getline
		
		for (int i=0; i<5; i++) 
		{
			if (holder[i] != "")
			array[lines][i]=stof(holder[i]);  // this will maybe probably work
		}
		lines++;
	}
	datafile.close();

return lines;
}




/*
This function takes in a filename and an empty array of floats
the fucntion returns the sum of the  means of all the odd number rows( the very firstr row is row 0) 
and the odd nunmber colums (the first colum is colum 0)
it achives this by opening the file and then calling fill array to fill the given array with floating 
point values so it can do math with them
it then sycles thorug each rown and collum indivudualy and calculates its mean
summing the means as it goes through the rows/colums
when it runs out of odd dumber rows and colums it returns the vriable ave which is holding the summ of the means

*/


float arrayStats(string filename, float numbers[][5])
{
int totlines= fillArray(filename, numbers);
// this finds the total number of lines in the file and returns the value
// it also fills the array "numbers" by refrence 
float ave=0;
int j1=0;
int j2=0;
float sumlines=0;
	for(int i=1; i<totlines;i+=2)
	{
		while( j1<5)
		{ 
			sumlines+= numbers[i][j1];
			j1++;
		}
		ave = ave +sumlines/5;
		sumlines=0;
		j1=0;
	
	}
	/*
no idea if this will actually work 
but im trying to do basically the same loop as above but 
i swap what i and j are equal to so i go through every odd collum and then every line
for the summ or average of each collum
*/
float sumcollums=0;
	for(int i=1; i<5; i+=2)
	{
		
		while(j2<totlines)
		{
			sumcollums=sumcollums+numbers[j2][i];	
			j2++;
		}
		ave=ave+ sumcollums/totlines;
		sumcollums=0;
		j2=0;
			
	}
	return ave;
}
// still can belive that actually worked




/*
This fuction takes in a file name, a empty string array and an empty 2d array of ints
the function open the filae and gets the lines of the fuction 
does nothing with teh very first line of the file
for other lines, checks to see if they are already in the user array,
if they are it places the value of rating in the coressponding row index(users) and colum index(book id)
if not it puts them in the user array and then places the value of rating in the coressponding row index(users) and colum index(book id)
the fonction does not return anything as it is a void.
*/


void addBookRatings(string filename, string users[], int ratings[][50])
{
	ifstream datafile;
	datafile.open(filename);
	if(datafile.fail())
	{
		cout<< "File "<< filename<< " has failed to open"<< endl;
	}
	string str;
	getline(datafile, str); // this will trash the first line of the file when  I get more lines in a while loop
	
string gline[3];
bool exists=false;
int count=0;
while (!datafile.eof())
{
	
	getline(datafile, str);
	Split(str,',',gline);// glinee gets overwritten evry time we do a getline so gline[0] will always be a username
	for (int i=0 ; i<count; i++) // this for loop and the blow if statement is how im continually checking if the user is alreadyin the array
	{
		if(users[i]==gline[0])
		{
			exists=true;
			ratings[i][stoi(gline[1])]=stoi(gline[2]);
			break;
		}
		
	}
	if(exists==false)
		{
			users[count]=gline[0];
			for(int i=0; i<50; i++)
			{
				ratings[count][i]=0;
			}
			ratings[count][stoi(gline[1])]=stoi(gline[2]);
			count++;	
		}
		
		exists=false;


}
datafile.close();
int totusr=count;

for(int i=0; i<totusr; i++)
{
	for (int j=0; j<50; j++)
	{
		if(ratings[i][j]>=0 && ratings[i][j]<=9)	
		{
			// literally do nothing 
		}
		else
		{	
		ratings[i][j]=0;
		}
	}
}

}

