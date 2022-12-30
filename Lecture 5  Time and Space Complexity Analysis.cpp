Find the Unique Element
_______________________
Send Feedback
You have been given an integer array/list(ARR) of size N. Where N is equal to [2M + 1].
Now, in the given array/list, 'M' numbers are present twice and one number is present only once.
You need to find and return that number which is unique in the array/list.
 Note:
Unique element is always present in the array/list according to the given condition.

#include <algorithm>
int findUnique(int *arr, int n) 
{
    sort(arr, arr + n);
    for(int i=0;i<n;i+=2)
    {
        if(arr[i]!=arr[i+1])
            return arr[i];
    }
    return arr[n-1];
}









-----------------------------------------------------------------------------------------------------


Duplicate in array
_________________
Send Feedback
You have been given an integer array/list(ARR) of size N which contains numbers from 0 to 
(N - 2). Each number is present at least once. That is, if N = 5, the array/list constitutes 
values ranging from 0 to 3, and among these, there is a single integer value that is present twice. 
You need to find and return that duplicate number present in the array.
Note :
Duplicate number is always present in the given array/list.


#include <algorithm>
int findDuplicate(int *arr, int n)
{
    sort(arr,arr+n);
    for(int i=0;i<n-1;i++)
    {
        if(arr[i]==arr[i+1])
            return arr[i];
            
    }
    return arr[n-1];
}









-------------------------------------------------------------------------------------------------------------------

Array Intersection
__________________
Send Feedback
You have been given two integer arrays/list(ARR1 and ARR2) of size N and M, respectively. You need to print their 
intersection; An intersection for this problem can be defined when both the arrays/lists contain a particular 
value or to put it in other words, when there is a common value that exists in both the arrays/lists.
Note :
Input arrays/lists can contain duplicate elements.

The intersection elements printed would be in ascending order.


#include<climits>
#include<algorithm>
void intersection(int *arr1, int *arr2, int n, int m) 
{
    
    sort(arr1,arr1+n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(arr1[i]==arr2[j])
            {
                 cout<<arr1[i]<<" ";
                 arr2[j]=INT_MIN;
                 break;
            }
               
        }
        
    }
}











-------------------------------------------------------------------------------------------------------------------------------

Pair sum in array
________________
Send Feedback
You have been given an integer array/list(ARR) and a number 'num'. Find and return the 
total number of pairs in the array/list which sum to 'num'.
Note:
Given array/list can contain duplicate elements. 


int pairSum(int *arr, int n, int num)
{
    int count=0;
	 for(int i=0;i<n-1;i++)
     {
         for(int j=i+1;j<n;j++)
         {
             if(arr[i]+arr[j]==num)
                 count++;
         }
     }
    return count;
}








-----------------------------------------------------------------------------------------------------------

Rotate array
_____________
Send Feedback
You have been given a random integer array/list(ARR) of size N. Write a function that rotates the given array/list 
by D elements(towards the left).
 Note:
Change in the input array/list itself. You don't need to return or print the elements.



void rotate(int *input, int d, int n)
{
    if(n==0)
        return ;
    int rot=d%n;
    if(rot==0)
        return ;
    
    
    int arr[rot];
    for(int i=0;i<rot;i++)
    {
        arr[i]=input[i];
        
    }
    for(int i=rot;i<n;i++)
    {
        input[i-rot]=input[i];
    }
    for(int i=n-rot;i<n;i++)
    {
        input[i]=arr[i-n+rot];
    }
    
}









----------------------------------------------------------------------------------------------------------------
Check Array Rotation
___________________
Send Feedback
You have been given an integer array/list(ARR) of size N. It has been sorted(in increasing order) and then rotated by some number 'K' in the right hand 
direction.
Your task is to write a function that returns the value of 'K', that means, the index from which the array/list has been rotated.


#include<climits>
int arrayRotateCheck(int *input, int size)
{
    int min=INT_MAX;
    for(int i=0;i<size;i++)
    {
        if(input[i]<min)
            min=input[i];
    }
    if(input[0]==min)
        return 0;
    
    for(int i=0;i<size;i++)
    {
        if(input[i]==min)
            return i;
    }
}


--------------------------------------------END----------------------------------------------------------------------------------------------------------------------------
