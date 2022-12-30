Replace Character Recursively
____________________________
Send Feedback
Given an input string S and two characters c1 and c2, you need to replace every occurrence of character c1 with character c2 in the given string.
Do this recursively.
Input Format :
Line 1 : Input String S
Line 2 : Character c1 and c2 (separated by space)
Output Format :
Updated string
Constraints :
1 <= Length of String S <= 10^6
Sample Input :
abacd
a x
Sample Output :
xbxcd

solution.....


void replaceCharacter(char input[], char c1, char c2) {
    
   if(input[0]=='\0')
       return ;
    
    if(input[0]==c1)
        input[0]=c2;
    
    replaceCharacter(input+1,c1,c2);
    
}







...........................................................................................................................................................................................


Remove Duplicates Recursively
_____________________________
Send Feedback
Given a string S, remove consecutive duplicates from it recursively.
Input Format :
String S
Output Format :
Output string
Constraints :
1 <= |S| <= 10^3
where |S| represents the length of string
Sample Input 1 :
aabccba
Sample Output 1 :
abcba
Sample Input 2 :
xxxyyyzwwzzz
Sample Output 2 :
xyzwz

solution.........

#include<cstring>
void removeConsecutiveDuplicates(char input[]) 
{
	if(input[0]=='\0')
        return ;
    
    if(input[0]==input[1])
    {
        for(int i=1;i<strlen(input);i++)
            input[i]=input[i+1];
        
        removeConsecutiveDuplicates(input);
    }
    removeConsecutiveDuplicates(input+1);
}







............................................................................................................................................................................................

Merge Sort Code
______________
Send Feedback
Sort an array A using Merge Sort.
Change in the input array itself. So no need to return or print anything.
Input format :
Line 1 : Integer n i.e. Array size
Line 2 : Array elements (separated by space)
Output format :
Array elements in increasing order (separated by space)
Constraints :
1 <= n <= 10^3
Sample Input 1 :
6 
2 6 8 5 4 3
Sample Output 1 :
2 3 4 5 6 8
Sample Input 2 :
5
2 1 5 2 3
Sample Output 2 :
1 2 2 3 5 


solution....

void merge(int input[],int l,int m,int r)
{
    int n1=m-l+1;
    int n2=r-m;
    int L[n1],R[n2];
    
    for(int i=0;i<n1;i++)
        L[i]=input[l+i];
    
    for(int j=0;j<n2;j++)
        R[j]=input[m+1+j];
    
    int i=0;
    int j=0;
    int k=l;
    
    while(i<n1 and j<n2)
    {
        if(L[i]<=R[j])
        {
            input[k]=L[i];
            i++;
        }else
        {
            input[k]=R[j];
            j++;
        }
        k++;
    }
    
    while(i<n1)
    {
        input[k]=L[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        input[k]=R[j];
        j++;
        k++;
    }
}

void mergeSort1(int input[],int l,int r)
{
    if(l>=r)
        return ;
    
    int m=(l+r)/2;
    mergeSort1(input,l,m);
    mergeSort1(input,m+1,r);
    merge(input,l,m,r);
}
void mergeSort(int input[], int size)
{
	int r=size-1;
    int l=0;
    mergeSort1(input,l,r);
        
}









............................................................................................................................................................................................

Quick Sort Code
______________
Send Feedback
Sort an array A using Quick Sort.
Change in the input array itself. So no need to return or print anything.


Input format :
Line 1 : Integer n i.e. Array size
Line 2 : Array elements (separated by space)
Output format :
Array elements in increasing order (separated by space)
Constraints :
1 <= n <= 10^3
Sample Input 1 :
6 
2 6 8 5 4 3
Sample Output 1 :
2 3 4 5 6 8
Sample Input 2 :
5
1 5 2 7 3
Sample Output 2 :
1 2 3 5 7 

solution.......

int partition(int input[],int size)
{
    int s=input[0],cnt=0;
    for(int i=1;i<size;i++)
    {
        if(input[i]<s)
            cnt++;
    }
    input[0]=input[cnt];
    input[cnt]=s;
    return cnt;

}
void quickSort(int input[], int size) 
{
    if(size<=1)
        return ;
    
    int c=partition(input,size);
    int i=0,j=size-1;
    while(i<c and j>c)
    {
        if(input[i]>=input[c])
        {
            if(input[j]<input[c])
            {
                int temp=input[i];
                input[i]=input[j];
                input[j]=temp;
                i++;
                j--;
            }else
                j--;
        }else
            i++;
    }
   quickSort(input,c);
   quickSort(input+(c+1),size-c-1);

}





............................................................................................................................................................................................


Return Keypad Code
_________________
Send Feedback
Given an integer n, using phone keypad find out all the possible strings that can be made using digits of input n.
Return empty string for numbers 0 and 1.
Note : 1. The order of strings are not important.
2. Input and output has already been managed for you. You just have to populate the output array and return the count of elements populated in the output array.
Input Format :
Integer n
Output Format :
All possible strings in different lines
Constraints :
1 <= n <= 10^6
Sample Input:
23
Sample Output:
ad
ae
af
bd
be
bf
cd
ce
cf

solution.....

#include<string>
using namespace std;
string getstr(int numb)
{
    if(numb==2)
        return "abc";
    if(numb==3)
        return "def";
    if(numb==4)
        return "ghi";
    if(numb==5)
        return "jkl";
    if(numb==6)
        return "mno";
    if(numb==7)
        return "pqrs";
    if(numb==8)
        return "tuv";
    if(numb==9)
        return "wxyz";
    
    return  "";

    
}
int keypad(int num, string output[])
{
   if(num==0)
   {
      output[0]="";
       return 1;
   }
       
    
    int ld=num%10;
    int num1=num/10;
    int count=keypad(num1,output);
    string options=getstr(ld);
    
    for(int i=0;i<options.length()-1;i++)
    {
        for(int j=0;j<count;j++)
        {
            output[j+(i+1)*count]=output[j];
        }
    }
    
    int k=0;
    for(int i=0;i<options.length();i++)
    {
        for(int j=0;j<count;j++)
        {
            output[k]=output[k]+options[i];
            k++;
        }
    }
    
    return options.length()*count;   
}





............................................................................................................................................................................................


Print Keypad Combinations Code
______________________________
Send Feedback
Given an integer n, using phone keypad find out and print all the possible strings that can be made using digits of input n.
Note : The order of strings are not important. Just print different strings in new lines.
Input Format :
Integer n
Output Format :
All possible strings in different lines
Constraints :
1 <= n <= 10^6
Sample Input:
23
Sample Output:
ad
ae
af
bd
be
bf
cd
ce
cf

solution........

#include <iostream>
#include <string>
using namespace std;
string getstr(int numb)
{
    if(numb==2)
        return "abc";
    if(numb==3)
        return "def";
    if(numb==4)
        return "ghi";
    if(numb==5)
        return "jkl";
    if(numb==6)
        return "mno";
    if(numb==7)
        return "pqrs";
    if(numb==8)
        return "tuv";
    if(numb==9)
        return "wxyz";
    
    return  "";

    
}
void get_sub(int input,string output)
{
    if(input==0)
    {
        cout<<output<<endl;
        return ;
    }
    int ld=input%10;
    string options=getstr(ld);
    int num1=input/10;
    for(int i=0;i<options.length();i++)
    {
        get_sub(num1,options[i]+output);
    }
    
    
}
void printKeypad(int num)
{
    get_sub(num," ");
}









.........................................................................................................................................................................................


Check AB
_________
Send Feedback
Suppose you have a string, S, made up of only 'a's and 'b's. Write a recursive function that checks if the string was generated using the following rules:
a. The string begins with an 'a'
b. Each 'a' is followed by nothing or an 'a' or "bb"
c. Each "bb" is followed by nothing or an 'a'
If all the rules are followed by the given string, return true otherwise return false.
Input format :
String S
Output format :
'true' or 'false'
Constraints :
1 <= |S| <= 1000
where |S| represents length of string S.
Sample Input 1 :
abb
Sample Output 1 :
true
Sample Input 2 :
abababa
Sample Output 2 :
false
Explanation for Sample Input 2
In the above example, a is not followed by either "a" or "bb", instead it's followed by "b" which results in false to be returned.


solution...


bool checkAB(char input[])
{
    if(input[0]!='a')
    {
        return false;
    }
    if(input[0]=='a')
    {
        if(input[1]=='a')
        {
            return checkAB(input+1);
        }
        if(input[1]=='a' or input[1]=='\0')
        {
            return true;
        }
        if((input[1]=='b' and input[2]=='b'))
        {
            if(input[3]=='a' or input[3]=='\0')
            {
                return true;
            }
        }
    }
    checkAB(input+1);
    return false;
}





.........................................................................................................................................................................................


Staircase
_________
Send Feedback
A child is running up a staircase with N steps, and can hop either 1 step, 2 steps or 3 steps at a time. Implement a method to count how many possible ways the child can run up to the stairs. You need to return number of possible ways W.
Input format :
Integer N
Output Format :
Integer W
Constraints :
1 <= N <= 30
Sample Input 1 :
4
Sample Output 1 :
7
Sample Input 2 :
5
Sample Output 2 :
13


solution....

int staircase(int n)
{
   
    if(n==0)
        return 1;
    if(n==1)
        return 1;
    if(n==2)
        return 2;
    
    return staircase(n-1)+staircase(n-2)+staircase(n-3);
}






...........................................................................................................................................................................................


Binary Search (Recursive)
_________________________
Send Feedback
Given an integer sorted array (sorted in increasing order) and an element x, find the x in given array using binary search. Return the index of x.
Return -1 if x is not present in the given array.
Note : If given array size is even, take first mid.
Input format :

Line 1 : Array size

Line 2 : Array elements (separated by space)

Line 3 : x (element to be searched)

Sample Input :
6
2 3 4 5 6 8 
5 
Sample Output:
3 


solution....

int binary(int input[],int element,int low,int high)
{
    if(low>high)
        return -1;
    int mid=(low+high)/2;
    
    if(element==input[mid])
        return mid;
    
    if(element>input[mid])
       return binary(input,element,mid+1,high);
    
    
      return binary(input,element,low,mid-1);
}

int binarySearch(int input[], int size, int element) 
{
    return binary(input,element,0,size-1);

}







..........................................................................................................................................................................................


Return subset of an array
________________________
Send Feedback
Given an integer array (of length n), find and return all the subsets of input array.
Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.


Note : The order of subsets are not important.


Input format :

Line 1 : Size of array

Line 2 : Array elements (separated by space)

Sample Input:
3
15 20 12
Sample Output:
[] (this just represents an empty array, don't worry about the square brackets)
12 
20 
20 12 
15 
15 12 
15 20 
15 20 12 



solution.....



int subset(int input[], int n, int output[][20]) 
{
    if(n==0)
    {
        output[0][0]=0;
        return 1;
    }

    int count=subset(input+1,n-1,output);
    int i,j;
    for(i=0;i<count;i++)
    {
        output[count+i][0]=output[i][0]+1;
        output[count+i][1]=input[0];
    }
    for(i=0;i<count;i++)
    {
        for(j=1;j<output[count+i][0];j++)
        {
            output[count+i][j+1]=output[i][j];
        }
    }
    return 2*count;
        
}






...........................................................................................................................................................................................

Print Subsets of Array
_____________________
Send Feedback
Given an integer array (of length n), find and print all the subsets of input array.
Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.
Note : The order of subsets are not important. Just print the subsets in different lines.
Input format :
Line 1 : Integer n, Size of array
Line 2 : Array elements (separated by space)
Constraints :
1 <= n <= 15
Sample Input:
3
15 20 12
Sample Output:
[] (this just represents an empty array, don't worry about the square brackets)
12 
20 
20 12 
15 
15 12 
15 20 
15 20 12 

solution....

int helper(int input[],int size,int output[],int m)
{
    if(size==0)
    {
        for(int i=0;i<m;i++)
        {
            cout<<output[i]<<" ";
        }
        cout<<endl;
        return 1;
    }
    helper(input+1,size-1,output,m);
    int newoutput[m+1];
    for(int i=0;i<m;i++)
    {
        newoutput[i]=output[i];
    }
    newoutput[m]=input[0];
    helper(input+1,size-1,newoutput,m+1);
}


void printSubsetsOfArray(int input[], int size) 
{
	int m=0;
    int output[m];
    helper(input,size,output,m);
    
}




...........................................................................................................................................................................................


Return subsets sum to K
_______________________
Send Feedback
Given an array A of size n and an integer K, return all subsets of A which sum to K.
Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.


Note : The order of subsets are not important.


Input format :
Line 1 : Integer n, Size of input array
Line 2 : Array elements separated by space
Line 3 : K 
Constraints :
1 <= n <= 20
Sample Input :
9 
5 12 3 17 1 18 15 3 17 
6
Sample Output :
3 3
5 1


solution.....

int subsetSumToK(int input[], int n, int o[][50], int k) {
    
    if(n==0)
    {
        if(k==0)
        {
            return 1;
        }else
            return 0;
    }
    int o1[10000][50];
    int o2[10000][50];
    
    int n1=subsetSumToK(input+1,n-1,o1,k-input[0]);
    int n2=subsetSumToK(input+1,n-1,o2,k);
    
    for(int i=0;i<n1;i++)
    {
        o[i][0]=o1[i][0]+1;
        o[i][1]=input[0];
        
        for(int j=2;j<=o1[i][0]+1;j++)
        {
            o[i][j]=o1[i][j-1];
        }
    }
    for(int i=n1;i<n1+n2;i++)
    {
        o[i][0]=o2[i-n1][0];
        for(int j=0;j<=o2[i-n1][0];j++)
            o[i][j]=o2[i-n1][j];
    }
    return n1+n2;
}







.........................................................................................................................................................................................


Print Subset Sum to k
____________________
Send Feedback
Given an array A and an integer K, print all subsets of A which sum to K.
Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.
Note : The order of subsets are not important. Just print them in different lines.
Input format :
Line 1 : Size of input array
Line 2 : Array elements separated by space
Line 3 : K 
Sample Input:
9 
5 12 3 17 1 18 15 3 17 
6
Sample Output:
3 3
5 1


solution....

int helper(int input[],int size,int k,int output[],int m)
{
    if(size==0)
    {
        if(k==0)
        {
            for(int i=0;i<m;i++)
            {
                cout<<output[i]<<" ";
            }
            cout<<endl;
        }
        return 1;
    }
    
    int newoutput[m+1];
    for(int i=0;i<m;i++)
    {
        newoutput[i]=output[i];
    }
    newoutput[m]=input[0];
    helper(input+1,size-1,k-input[0],newoutput,m+1);
    helper(input+1,size-1,k,output,m);
}
void printSubsetSumToK(int input[], int size, int k) 
{
    int m=0;
    int output[m];
    helper(input,size,k,output,m);
}








...........................................................................................................................................................................................


Return all codes - String
_________________________
Send Feedback
Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. You are given a numeric string S. Write a program to return the list of all possible codes that can be generated from the given string.
Note : The order of codes are not important. And input string does not contain 0s.
Input format :
A numeric string
Constraints :
1 <= Length of String S <= 10
Sample Input:
1123
Sample Output:
aabc
kbc
alc
aaw
kw

solution....


#include <string.h>
using namespace std;
int atoi(char a)
{
    int i=a-'0';
    return i;
}
char itoa(int i)
{
    char c='a'+i-1;
    return c;
}

int getCodes(string input, string output[10000]) {
    /*
    You are given the input text and output string array. Find all possible codes and store in the output string array. Don’t print the codes.
    Also, return the number of codes return to the output string. You do not need to print anything.
    */
    
    if(input.size()==0)
    {
        output[0]="";
        return 1;
    }
    if(input.size()==1)
    {
        output[0]=itoa(atoi(input[0]));
        return 1;
    }
    string result1[10000],result2[10000];
    int size2=0;
    
    int size1=getCodes(input.substr(1),result1);
    if(input.size()>1)
    {
        if(atoi(input[0])*10+atoi(input[1])>=10 and atoi(input[0])*10+atoi(input[1])<27)
        {
            size2=getCodes(input.substr(2),result2);
        }
    }
    int k=0;
    for(int i=0;i<size1;i++)
    {
        output[k++]=itoa(atoi(input[0]))+result1[i];
    }
    for(int i=0;i<size2;i++)
    {
        output[k++]=itoa(atoi(input[0])*10+atoi(input[1]))+result2[i];
    }
    return k;
}








..........................................................................................................................................................................................


Print all Codes - String
________________________
Send Feedback
Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. You are given a numeric string S. Write a program to print the list of all possible codes that can be generated from the given string.
Note : The order of codes are not important. Just print them in different lines.
Input format :
A numeric string S
Output Format :
All possible codes in different lines
Constraints :
1 <= Length of String S <= 10
Sample Input:
1123
Sample Output:
aabc
kbc
alc
aaw
kw


solution....


#include <string.h>
using namespace std;

void helper(string input,string output)
{
    if(input.empty())
    {
        cout<<output<<endl;
        return;
    }
    char start='a'+(input[0]-'0')-1;
    helper(input.substr(1),output+start);
    char start2;
    int firstnum=10*(input[0]-'0')+(input[1]-'0');
    if(firstnum>=10 and firstnum<=26)
    {
        start2='a'+firstnum-1;
        helper(input.substr(2),output+start2);
    }
}
void printAllPossibleCodes(string input) {
    /*
    Given the input as a string, print all its possible combinations. You do not need to return anything.
    */
    string output="";
    helper(input,output);
}








..........................................................................................................................................................................................



Return Permutations - String
____________________________
Send Feedback
Given a string S, find and return all the possible permutations of the input string.
Note 1 : The order of permutations is not important.
Note 2 : If original string contains duplicate characters, permutations will also be duplicates.
Input Format :
String S
Output Format :
All permutations (in different lines)
Sample Input :
abc
Sample Output :
abc
acb
bac
bca
cab
cba


solution......


#include <string>
using namespace std;

int returnPermutations(string input, string output[]){
   	
    if(input.length()==0)
    {
        output[0]="";
        return 1;
    }
    
    int r=0;
    int size=input.length();
    for(int i=0;i<size;i++)
    {
        char A=input[i];
        string o1[10000];
        
        
        int s1=returnPermutations(input.substr(0,i)+input.substr(i+1),o1);
        for(int k=0;k<s1;k++)
        {
            output[r++]=o1[k]+A;
        }
    }
    return r;
}








........................................................................................................................................................................................


Print Permutations
__________________
Send Feedback
Given an input string (STR), print all possible permutations of the input string.
Note:
The input string may contain the same characters, so there will also be the same permutations.
The order of permutations doesn’t matter.
Input Format:
The only input line contains a string (STR) of alphabets in lower case
Output Format:
Print each permutations in a new line
Constraint:
1<=length of STR<=8
Time Limit: 1sec
Sample Input 1:
cba
Sample Output 1:
abc
acb
bac
bca
cab
cba

solution....


#include <iostream>
#include <string>
using namespace std;
void permute(string a,int l,int r)
{
    if(l==r)
        cout<<a<<endl;
    else
    {
        for(int i=l;i<=r;i++)
        {
            swap(a[l],a[i]);
            permute(a,l+1,r);
            swap(a[l],a[i]);
        }
    }
}
void printPermutations(string input){

    	permute(input,0,input.size()-1);
}






...........................................................................................................................................................................................