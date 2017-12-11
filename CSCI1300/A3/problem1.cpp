// Author: Christian Sousa 
// Ta : Thomas Lillis 



#include <iostream>
using namespace std;

// this function askes for user inputs and saves tehm to a variabel, then it outputs them in a cout with some text
void story1(void)
{
	string a;
	string b;
	string c;
	string d;

	
	cout<< "Enter a plural noun:"<<endl;
	cin>> a;
	cout<< "Enter a occupation:"<<endl;
	cin>> b;
	cout<< "Enter an animal name:"<<endl;
	cin>> c;
	cout << "Enter a place:"<<endl;
	cin>> d;

	cout<<"In the book War of the "<<a<< ", the main character is an anonymous "<<b<< " who records the arrival of the " <<c<< "s in "<< d<<"."<< endl;
	
}
// does literally the same as story ine but with different text input and output
void story2(void)
{	
	string a;
	string b;
	string c;
	

	cout<< "Enter a name:"<<endl;
	cin>> a;
	cout << "Enter a State/Country:"<<endl;
	cin>> b;
	cout <<a<< ", I've got a feeling we're not in "<<b<<" anymore."<<endl;
	
}
// see line 31, i dont feel like typing that again 
void story3(void)
{
	string a;
	string b;
	string c;

	cout<<"Enter first name:"<<endl;
	cin>>a ;
	cout<< "Enter a relative:"<<endl;
	cin>> b;
	cout<<"Enter a verb:"<<endl;
	cin>> c;
	cout << "Hello. My name is "<<a<< ". You killed my "<<b<<". Prepare to "<<c<< "."<<endl;
	
}

// oh boy the function you have all been wating for. Ladies adn gentlemen. VOID MENU(VOID)
// this function tales in the user input for x and enters the while loop NO MATTER WHAT
// if the user input is 1,2 or 3 they are promtes with a story and asked for a new x input and they g thouhg the loop again as the variable exit is still 0
// if they enter something random like t or smellywaffles they are told they did not select a valid choice and are given the opprtunity to change the value of x
// if they enter q exit is changed to 1 so it does not go thorough the loop and it continues down to the function prints out the exit messege and ends the proccess
void menu(void)
{
	string x;
	string Test;
	int exit=0;

	 cout << "Which Story would you like to play? Enter the number of the story (1,2 or 3) or type q to quit:"<<endl;
	 cin>> x;
	while (exit==0)
	{
		if (x=="1")
		{
			story1();
			cout << "Which Story would you like to play? Enter the number of the story (1,2 or 3) or type q to quit:"<<endl;
	 		cin>> x;
		}
		
		else if (x=="2")
		{
			story2();
			cout << "Which Story would you like to play? Enter the number of the story (1,2 or 3) or type q to quit:"<<endl;
	 		cin>> x;	
		}
		
		else if (x=="3")
		{
			story3();
			cout << "Which Story would you like to play? Enter the number of the story (1,2 or 3) or type q to quit:"<<endl;
	 		cin>> x;
		}
		else if (x=="q")
		{
			exit=1;
		}
		else if (x!="1" && x!= "2" && x!="3" && x!="q")
		{
			cout<< "Valid choice not selected" << endl;
			cout << "Which Story would you like to play? Enter the number of the story (1,2 or 3) or type q to quit:"<<endl;
	 		cin>> x;
		}
	
	}	


cout<< "good bye" << endl; 
}
// main just calls menu so menu is working as int main (more or less)
int main(void)
{
	menu();


}






