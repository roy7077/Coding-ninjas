.......................................................................
Power
______
Send Feedback
Write a program to find x to the power n (i.e. x^n). Take x and n from the user. You need to return the answer.
Do this recursively.
Input format :
Two integers x and n (separated by space)
Output Format :
x^n (i.e. x raise to the power n)
Constraints :
0 <= x <= 30
0 <= n <= 30
Sample Input 1 :
 3 4

solution.......
int power(int x,int n)
{
    if(n==0)
        return 1;
    
    return x*power(x,n-1);
}








...............................................................................
Print Numbers
_____________
Send Feedback
Given the number 'n', write a code to print numbers from 1 to n in increasing order recursively.
Input Format :
Integer n
Output Format :
Numbers from 1 to n (separated by space)
Constraints :
1 <= n <= 10000
Sample Input 1 :
 6
Sample Output 1 :
1 2 3 4 5 6
Sample Input 2 :
 4
Sample Output 2 :
1 2 3 4

solution .............

void print(int n)
{
    if(n==0)
        return ;
    
    print(n-1);
    cout<<n<<" ";
    
}








...........................................................................

Number of Digits
________________
Send Feedback
Given the number 'n', find out and return the number of digits present in a number recursively.
Input Format :
Integer n
Output Format :
Count of digits
Constraints :
1 <= n <= 10^6
Sample Input 1 :
 156
Sample Output 1 :
3
Sample Input 2 :
 7
Sample Output 2 :
1

solution.............

int count(int n)
{
    if(n==0)
        return 0;
    
    return 1+count(n/10);
}












...............................................................................
Sum of Array
____________
Send Feedback
Given an array of length N, you need to find and return the sum of all elements of the array.
Do this recursively.
Input Format :
Line 1 : An Integer N i.e. size of array
Line 2 : N integers which are elements of the array, separated by spaces
Output Format :
Sum
Constraints :
1 <= N <= 10^3
Sample Input 1 :
3
9 8 9
Sample Output 1 :
26
Sample Input 2 :
3
4 2 1
Sample Output 2 :
7    

solution ............

int sum(int a[], int n) 
{
   if(n==0)
       return 0;
    
    return a[0]+sum(a+1,n-1);
}









...................................................................................

Check Number
____________
Send Feedback
Given an array of length N and an integer x, you need to find if x is present in the array or not. Return true or false.
Do this recursively.
Input Format :
Line 1 : An Integer N i.e. size of array
Line 2 : N integers which are elements of the array, separated by spaces
Line 3 : Integer x
Output Format :
'true' or 'false'
Constraints :
1 <= N <= 10^3
Sample Input 1 :
3
9 8 10
8
Sample Output 1 :
true
Sample Input 2 :
3
9 8 10
2
Sample Output 2 :
false

solution.............

bool checkNumber(int input[], int size, int x) 
{
   if(size==0)
       return false;
    
    if(input[0]==x)
        return true;
    
    bool is_present=checkNumber(input+1,size-1,x);
    return is_present;
}







.................................................................................

First Index of Number
_____________________
Send Feedback
Given an array of length N and an integer x, you need to find and return the first index of integer x present in the array. Return -1 if it is not present in the array.
First index means, the index of first occurrence of x in the input array.
Do this recursively. Indexing in the array starts from 0.
Input Format :
Line 1 : An Integer N i.e. size of array
Line 2 : N integers which are elements of the array, separated by spaces
Line 3 : Integer x
Output Format :
first index or -1
Constraints :
1 <= N <= 10^3
Sample Input :
4
9 8 10 8
8
Sample Output :
1

solution ....

int firstIndex(int input[], int size, int x) 
{
     if(size==0)
         return -1;
    
    if(input[0]==x)
        return 0;
    
    int a=firstIndex(input+1,size-1,x);
    if(a!=-1)
        return a+1;
    else
        return -1;
}








...................................................................................

Last Index of Number
____________________
Send Feedback
Given an array of length N and an integer x, you need to find and return the last index of integer x present in the array. Return -1 if it is not present in the array.
Last index means - if x is present multiple times in the array, return the index at which x comes last in the array.
You should start traversing your array from 0, not from (N - 1).
Do this recursively. Indexing in the array starts from 0.
Input Format :
Line 1 : An Integer N i.e. size of array
Line 2 : N integers which are elements of the array, separated by spaces
Line 3 : Integer x
Output Format :
last index or -1
Constraints :
1 <= N <= 10^3
Sample Input :
4
9 8 10 8
8
Sample Output :
3

solution.........

int lastIndex(int input[], int size, int x) {
  
    if(size==0)
        return -1;
    
    if(input[size-1]==x)
        return size-1;
    
    int a=lastIndex(input,size-1,x);
    return a;
}







................................................................................

All Indices of Number
_____________________
Send Feedback
Given an array of length N and an integer x, you need to find all the indexes where x is present in the input array. Save all the indexes in an array (in increasing order).
Do this recursively. Indexing in the array starts from 0.
Input Format :
Line 1 : An Integer N i.e. size of array
Line 2 : N integers which are elements of the array, separated by spaces
Line 3 : Integer x
Output Format :
indexes where x is present in the array (separated by space)
Constraints :
1 <= N <= 10^3
Sample Input :
5
9 8 10 8 8
8
Sample Output :
1 3 4

solution........

int p=0;
int q=0;
int allIndexes(int input[], int size, int x, int output[]) 
{
  
   if(size==0)
       return 0;
    
    if(input[0]==x)
    {
        output[p]=q;
        p++;
        q++;
        return allIndexes(input+1,size-1,x,output)+1;
    }
    q++;
    return allIndexes(input+1,size-1,x,output);
    
}









......................................................................................

Multiplication (Recursive)
__________________________
Send Feedback
Given two integers M & N, calculate and return their multiplication using recursion. You can only use subtraction and addition for your calculation. No other operators are allowed.
Input format :
Line 1 : Integer M
Line 2 : Integer N
Output format :
M x N
Constraints :
0 <= M <= 1000
0 <= N <= 1000
Sample Input 1 :
3 
5
Sample Output 1 :
15
Sample Input 2 :
4 
0
Sample Output 2 :
0


solution.......

int multiplyNumbers(int m, int n) 
{
   if(n==0)
       return n;
    
    return m+multiplyNumbers(m,n-1);
}






....................................................................................

Count Zeros
___________
Send Feedback
Given an integer N, count and return the number of zeros that are present in the given integer using recursion.
Input Format :
Integer N
Output Format :
Number of zeros in N
Constraints :
0 <= N <= 10^9
Sample Input 1 :
0
Sample Output 1 :
1
Sample Input 2 :
00010204
Sample Output 2 :
2
Explanation for Sample Output 2 :
Even though "00010204" has 5 zeros, the output would still be 2 because when you convert it to an integer, it becomes 10204.
Sample Input 3 :
708000
Sample Output 3 :
4


solution......

int countZeros(int number) 
{

    if(number>=1 and number<=9)
        return 0;
    
    if(number==0)
        return 1;
    
    int n=number%10;
    if(n==0)
        return 1+countZeros(number/10);
    else
        return countZeros(number/10);
}






......................................................................................

Geometric Sum
_____________
Send Feedback
Given k, find the geometric sum i.e.
1 + 1/2 + 1/4 + 1/8 + ... + 1/(2^k) 
using recursion.
Input format :
Integer k
Output format :
Geometric sum (upto 5 decimal places)
Constraints :
0 <= k <= 1000
Sample Input 1 :
3
Sample Output 1 :
1.87500
Sample Input 2 :
4
Sample Output 2 :
1.93750
Explanation for Sample Input 1:
1+ 1/(2^1) + 1/(2^2) + 1/(2^3) = 1.87500

solution........

double geometricSum(int k) {
    
    if(k==0)
        return 1;
    double ans=1/(double)pow(2,k)+geometricSum(k-1);
    return ans;

}







.....................................................................................

Check Palindrome (recursive)
____________________________
Send Feedback
Check whether a given String S is a palindrome using recursion. Return true or false.
Input Format :
String S
Output Format :
'true' or 'false'
Constraints :
0 <= |S| <= 1000
where |S| represents length of string S.
Sample Input 1 :
racecar
Sample Output 1:
true
Sample Input 2 :
ninja
Sample Output 2:
false

solution........

#include<bits/stdc++.h>
using namespace std;
bool isPalRec(char input[],int s,int e)
{
    if(s>e)
        return true;
    
    if(input[s]!=input[e])
        return false;
    else
        return isPalRec(input,s+1,e-1);
}
    
    
bool checkPalindrome(char input[]) 
{
   if(strlen(input)==0)
       return true;
    
    return isPalRec(input,0,strlen(input)-1);
}








....................................................................................

Sum of digits (recursive)
_________________________
Send Feedback
Write a recursive function that returns the sum of the digits of a given integer.
Input format :
Integer N
Output format :
Sum of digits of N
Constraints :
0 <= N <= 10^9
Sample Input 1 :
12345
Sample Output 1 :
15
Sample Input 2 :
9
Sample Output 2 :
9


solution.....

int sumOfDigits(int n) 
{
    if(n==0)
        return 0;
    
    return n%10+sumOfDigits(n/10);
}


......................................................................................
