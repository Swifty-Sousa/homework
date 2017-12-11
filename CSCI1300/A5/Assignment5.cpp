//Author: Christian Sousa
// TA: Thomas Lillis 
#include<iostream>
using namespace std;
#include<math.h>

/* This funtion is suppost to take in an array of float values and the size of the array and return 
the sum of all the elements in the array as a float value.
*/
float sumArray(float Array[], int size)
{
	float count=0;	
	for(int i=0; i<size; i++) // for loop to step through the array at each individual index
	{
		count=count +Array[i]; // this is what summs the current value of what Array[] at some idex is with the previous values of the array
	}
	return count; // here I return the float value of the sum to whatever called the function. 
}
/* This function takes in an integer array, its size and a target integer.
the algorithm then steps through the array and sees if that integer matches target
if it does, the function returns the index at that time.
If the target is not found the fucntion simply returns -1
*/

int search(int array[], int size, int target)
{
	int j=0;
	while (j<size)
	{
		if (array[j]==target) // here is where the array is checked to match target 
		{
			return j;// returning the index if target is found
		}

		j++;
	}
	return -1;	// returning -1 if the target is not found
}


/*
This function takes in two integer arrays of the same size and the value of the size of the arrays 
it then does the squared difference of for each pair of integers in the arrays and adds them up
it returns that number  
*/
float calculateDifference(int a[], int b[], int size)
{
	int y=0;
	for (int i=0.0; i<size; i++)// loop to step through each part of the array 
		{
			
			y+= pow(a[i]-b[i],2);// this is where i found out that y+= meand y=y+somthing, handy little thingy
			
		}

	

	return y; // returning the value of the summed differences

}

/*
This function takes in and unsorted array and its size and sorts that array
this funtions does not return anything and therefore has the data type 
void
*/
void sortArray(float unsortedArray[], int size)
{
	int x=1;
	float holdera=0;
	float holderb=0;
	int i=0;
	while (i<size-1) // this loop iterates through and makes sure the swapping is done enough times.
	{
	 	for(int j=0; j<size-i-1; j++) // this loop iteates throught all of the 
	 	{
	 		
	 		if(unsortedArray[j]>unsortedArray[j+1]) 
	 		{
	 			holdera= unsortedArray[j]; // th is line and the two below it are the part of the algorythm that actually swap the indexs to do the bullble sort
	 			unsortedArray[j]= unsortedArray[j+1];
	 			unsortedArray[j+1]=holdera;
	 		}
	
	 	}
	i++;
	

	}	
}


/*
This fuction takes ina full array an empty array and the size of the arrays(assumed to be identical)
*/

void copyArray(float source[],int size, float dest[]) 
{
	for (int i=0; i<size; i++) // this loop sets the array at one point equal to the other at the same point 

	{
		dest[i]=source[i];// effectively this is the copy past of arrays
	}
}




/*
This fuction takes an array of integers and fills an array of string according to a chart given int
the problem.
*/


void convert(int rating[], string text[], int size)
{
	
	for( int i=0; i<size; i++) // This loop cycles throuhg each index and findes the corssponding text to put in text[]  based  on rating[]
	{
		if(rating[i]== 0)
		{
			text[i]= "Not-read"; // all the conditions here are given in the probelem
		}

		else if(rating[i]==-5)
		{
			text[i]="Terrible";
		}

		else if(rating[i]==-3)
		{
			text[i]="Disliked";
		}
		else if(rating[i]==1)
		{
			text[i]="Average";
		}
		else if(rating[i]==3)
		{
			text[i]="Good";
		}
		else if(rating[i]==5)
		{
			text[i]="Excellent";
		}
		else
		{
			text[i]="INVALID";
		}

	}
}


/*
This function takes an array that we are not allowed to modify and then copies it into another array that we is then sorted
the array is copied into a sortabel array using the previous funtion copyArray()
the array is sorted with the previous function sortArray()
the function then finds the median of that sorted array and returns the vlaue of thee median 
*/
float findMedian(float array[], int size)
{
	float sortable[size];
	copyArray(array, size, sortable);
	 sortArray(sortable, size);
	
	/*
	these if statemts are used to find the actual value of the median
	if size is even we take the average of the middle 2 vlaues in the sorted array 
	if size is odd we simply find and return the middle value of the sorted array 
	*/

	if(size%2==1)
	{
		return sortable[(size-1)/2];
	}
	
	else if (size%2==0)
	{
		return ((sortable[(size-1)/2] + sortable[(size-1)/2 +1]))/2;
	}
}













