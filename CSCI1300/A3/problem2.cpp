// Author: Christian Sousa 
// Ta: Thomas Lillis

#include<iostream> 
#include<math.h>
using namespace std;

// The fuction below calculates the wind chill based on paramiters passed to it on line 41
// by returning z, i am returning the vlaue that the function windChillCalculator comes up with to main
float windChillCalculator(float a, float b)
{
		float z= 35.74 + 0.6215 * a - 35.75 * pow(b,0.16) + 0.4275 * a * pow(b,0.16);  // the actual maths, pow() is a thing that i learned,
		return z;
}
// this happy fun function takes some params given by cog (so the input variabels have to be in this order, also learned this the hard way,)
// it then goes though the loop if LWS is less than HWS and calls the windchillcal, it gets a return value and prints it out with some text.
// it then increses the value of LWS by WSS so that it does not go go through the loop when the LSW has been incremented enough to == HWS
void printWindChill(float T, float low_wind_speed, float high_wind_speed, float wind_speed_step)
{
	float c;
	
	
	while (low_wind_speed <= high_wind_speed)
	{
		
		c= windChillCalculator(T, low_wind_speed);
		cout<< "The wind chill is "<< c << " degrees F for an airtemperature of "<< T << " degrees F" << " and a wind speed of " << low_wind_speed << " mph."<< endl;
		low_wind_speed = low_wind_speed + wind_speed_step;
	}
}

// this is where the program starts running all fuctions called int manin are declared above (I learned the hard way that this is a thing that matters), I declare a bunch of variables, do some couts, 
// call some functions, get some return values and badabing badaboom i have the right answer.
int main (void)
{
	float T;
	float V;
	float low_wind_speed;
	float high_wind_speed;
	float wind_speed_step;
	cout<< "Enter the air temperature." <<endl;
	cin>> T;
	cout << "Enter the wind speed."<< endl;
	cin>> V;
	cout<< "The wind chill is " << windChillCalculator(T,V) << " degrees F. "<< endl;
	
	
}
//thank you, ill be here all week 


 