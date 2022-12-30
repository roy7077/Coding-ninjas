Code : Min Steps to 1
_____________________
Send Feedback
Given a positive integer 'n', find and return the minimum number of steps that 'n' has to take to get reduced to 1. You can perform any one of the following 3 steps:
1.) Subtract 1 from it. (n = n - ­1) ,
2.) If its divisible by 2, divide by 2.( if n % 2 == 0, then n = n / 2 ) ,
3.) If its divisible by 3, divide by 3. (if n % 3 == 0, then n = n / 3 ).  
Write brute-force recursive solution for this.


#include<climits>
int countMinStepsToOne_helper(int arr[],int n)
{
    if(n==1 or n==0)
        return 0;
    
    if(arr[n]!=-1)
        return arr[n];
    
    int a,b,c;
    a=b=c=INT_MAX;
    
       a=countMinStepsToOne_helper(arr,n-1);
    if(n%2==0)
    b=countMinStepsToOne_helper(arr,n/2);
    if(n%3==0)
    c=countMinStepsToOne_helper(arr,n/3);
    
    arr[n]=min({a,b,c})+1;
    
    return min({a,b,c})+1;
}
int countMinStepsToOne(int n)
{
    int arr[n+1];
    for(int i=0;i<n+1;i++)
        arr[i]=-1;
    
    return countMinStepsToOne_helper(arr,n);
    
}






---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------



Code : Min Steps to 1 using DP
Send Feedback
Given a positive integer 'n', find and return the minimum number of steps that 'n' has to take to get reduced to 1. You can perform any one of the following 3 steps:
1.) Subtract 1 from it. (n = n - ­1) ,
2.) If n is divisible by 2, divide by 2.( if n % 2 == 0, then n = n / 2 ) ,
3.) If n is divisible by 3, divide by 3. (if n % 3 == 0, then n = n / 3 ).  




#include<climits>
int countStepsToOne(int n)
{
	int arr[n+1];
    arr[0]=0;
    arr[1]=0;
    arr[2]=2;
    arr[3]=2;
    for(int i=3;i<n+1;i++)
    {
        int min1,min2,min3;
        min1=min2=min3=INT_MAX;
        
        min1=arr[i-1]+1;
        if(i%2==0)
            min2=arr[i/2]+1;
        if(i%3==0)
            min3=arr[i/3]+1;
        
        arr[i]=min(min1,min(min2,min3));
    }
    return arr[n];
}






--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------



Code : Staircase using Dp
_________________________
Send Feedback
A child is running up a staircase with n steps and can hop either 1 step, 2 steps or 3 steps at a time. Implement a method to count how many possible ways the child can run up to the stairs. You need to return all possible number of ways.
Time complexity of your code should be O(n).
Since the answer can be pretty large print the answer % mod(10^9 +7)



#include<bits/stdc++.h>
using namespace std;
int MOD=((int)pow(10,9))+7;
long min_steps(int n)
{
     long *arr=new long[n+1];
    if(n==0)
        return 1;
    
    if(n==1 or n==2)
        return n;
        
    
    arr[0]=1;
    arr[1]=1;
    arr[2]=2;
    for(int i=3;i<n+1;i++)
    {
        arr[i]=((long)(arr[i-1]%MOD)+(long)(arr[i-2]%MOD)+(long)(arr[i-3]%MOD));
    }
        return arr[n];
    
}
int main()
{
    
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        long ans=min_steps(n);
        cout<<ans%MOD<<endl;
    }
}







--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


Code : Minimum Count
____________________
Send Feedback
Given an integer N, find and return the count of minimum numbers required to represent N as a sum of squares.
That is, if N is 4, then we can represent it as : {1^2 + 1^2 + 1^2 + 1^2} and {2^2}. The output will be 1, as 1 is the minimum count of numbers required to represent N as sum of squares.











int minC(vector<int> &dp,int n){

  /*  Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Return output and don't print it.
   *  Taking input and printing output is handled automatically.
   */
    int sq=floor(sqrt(n));
    
    if(sq*sq == n)return 1;
    
    if(dp[n]!=0)
        return dp[n];
    
    int temp=INT_MAX;
    for(int i=1;i<=floor(sqrt(n));i++){
        temp=min(temp,minC(dp,n-(i*i)));
       
    }
    
    dp[n]=1+temp;
    return dp[n];
    


}

int minCount(int n){
    
    /*  Don't write main().
     *  Don't read input, it is passed as function argument.
     *  Return output and don't print it.
     *  Taking input and printing output is handled automatically.
     */
    
    vector <int> dp(n+1);
    int ans=minC(dp,n);
    return ans;
      
}






---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------



Code : No. of balanced BTs
___________________________
Send Feedback
Given an integer h, find the possible number of balanced binary trees of height h. You just need to return the count of possible binary trees which are balanced.
This number can be huge, so, return output modulus 10^9 + 7.
Write a simple recursive solution.



#include<cmath>
int mod=(int)(pow(10,9))+7;
int balancedBTs(int n) 
{
    if(n==0 or n==1)
        return 1;
    
    int x=balancedBTs(n-1);
    int y=balancedBTs(n-2);
    
    int temp1=(int)(((long)(x)*x)%mod);
    int temp2=(int)((2* (long)x * y)%mod);
    return (temp1+temp2)%mod;
}





---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------



Code : No. of balanced BTs using DP
____________________________________
Send Feedback
Given an integer h, find the possible number of balanced binary trees of height h. You just need to return the count of possible binary trees which are balanced.
This number can be huge, so, return output modulus 10^9 + 7.
Time complexity should be O(h).



#include<bits/stdc++.h>
int mod=(int)(pow(10,9))+7;
using namespace std;
long balancedBTS_helper(int n,long arr[])
{

    if(n==0 or n==1)
        return 1;
    
    if(arr[n]!=-1)
        return arr[n];
    
    int x=balancedBTS_helper(n-1,arr);
    int y=balancedBTS_helper(n-2,arr);
    
    int temp1=(int)(((long)(x)*x)%mod);
    int temp2=(int)((2* (long)x * y)%mod);
    arr[n]=(temp1+temp2)%mod;
    return arr[n];
    
}
long balancedBTs(int n)
{
  
    long arr[n+1];
    for(int i=0;i<n+1;i++)
        arr[i]=-1;
    
    return balancedBTS_helper(n,arr);
    
}





-------------------------------------------------------------------------------------END-----------------------------------------------------------------------------------------------------