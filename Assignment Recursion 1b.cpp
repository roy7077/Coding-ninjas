Replace pi (recursive)
_____________________
Send Feedback
Given a string, compute recursively a new string where all appearances of "pi" have been replaced by "3.14".
Constraints :
1 <= |S| <= 50
where |S| represents the length of string S. 
Sample Input 1 :
xpix
Sample Output :
x3.14x
Sample Input 2 :
pipi
Sample Output :
3.143.14
Sample Input 3 :
pip
Sample Output :
3.14p
Constraints:-
1<=|S|<=50


solution....

#include<cstring>
void replacePi(char input[])
{
    if(input[0]=='\0')
        return ;
    
    if(input[0]=='p' and input[1]=='i')
    {
        for(int i=strlen(input);i>=0;i--)
            input[i+2]=input[i];
        
        input[0]='3';
        input[1]='.';
        input[2]='1';
        input[3]='4';
    }
    replacePi(input+1);
}





.......................................................................................................
Remove X
________
Send Feedback
Given a string, compute recursively a new string where all 'x' chars have been removed.
Input format :
String S
Output format :
Modified String
Constraints :
1 <= |S| <= 10^3
where |S| represents the length of string S. 
Sample Input 1 :
xaxb
Sample Output 1:
ab
Sample Input 2 :
abc
Sample Output 2:
abc
Sample Input 3 :
xx
Sample Output 3:

solution.....

#include<cstring>
void removeX(char input[]) 
{
    if(input[0]=='\0')
        return ;
    
    if(input[0]=='x')
    {
        for(int i=0;i<strlen(input);i++)
            input[i]=input[i+1];
        
        removeX(input);
    }
    removeX(input+1);
}








...........................................................................................................
String to Integer
_________________
Send Feedback
Write a recursive function to convert a given string into the number it represents. That is input will be a numeric string that contains only numbers, you need to convert the string into corresponding integer and return the answer.
Input format :
Numeric string S (string, Eg. "1234")
Output format :
Corresponding integer N (int, Eg. 1234)
Constraints :
0 < |S| <= 9
where |S| represents length of string S.
Sample Input 1 :
00001231
Sample Output 1 :
1231
Sample Input 2 :
12567
Sample Output 2 :
12567


solution.....

#include<cstring>
#include<cmath>
int count=0;
int stringToNumber(char input[]) 
{
    int n=strlen(input);
    if(n==1)
        return input[0]-'0';
    
    int a=input[0]-'0';
    return a*pow(10,n-1)+stringToNumber(input+1);
}







........................................................................................

Pair Star
__________
Send Feedback
Given a string S, compute recursively a new string where identical chars that are adjacent in the original string are separated from each other by a "*".
Input format :
String S
Output format :
Modified string
Constraints :
0 <= |S| <= 1000
where |S| represents length of string S.
Sample Input 1 :
hello
Sample Output 1:
hel*lo
Sample Input 2 :
aaaa
Sample Output 2 :
a*a*a*a


solution...

#include<cstring>
void pairStar(char input[]) 
{
    if(input[0]=='\0')
        return ;
    
    if(input[0]==input[1])
    {
        for(int i=strlen(input);i>0;i--)
            input[i+1]=input[i];
        input[1]='*';
    }
    pairStar(input+1);
}








........................................................................................

Tower of Hanoi
______________
Send Feedback
Tower of Hanoi is a mathematical puzzle where we have three rods and n disks. The objective of the puzzle is to move all disks from source rod to destination rod using third rod (say auxiliary). The rules are :
1) Only one disk can be moved at a time.
2) A disk can be moved only if it is on the top of a rod.
3) No disk can be placed on the top of a smaller disk.
Print the steps required to move n disks from source rod to destination rod.
Source Rod is named as 'a', auxiliary rod as 'b' and destination rod as 'c'.
Input Format :
Integer n
Output Format :
Steps in different lines (in one line print source and destination rod name separated by space)
Constraints :
0 <= n <= 20
Sample Input 1 :
2
Sample Output 1 :
a b
a c
b c
Sample Input 2 :
3
Sample Output 2 :
a c
a b
c b
a c
b a
b c
a c


solution....

void towerOfHanoi(int n, char source, char auxiliary, char destination) {
    if(n==0)
        return;
    
    if(n>0)
    {
        towerOfHanoi(n-1,source,destination,auxiliary);
        cout<<source<<" "<<destination<<endl;
        towerOfHanoi(n-1,auxiliary,source,destination);
    }

}


.........................................................................................