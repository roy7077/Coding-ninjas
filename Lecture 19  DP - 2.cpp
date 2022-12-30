Code : Min Cost Path
____________________
Send Feedback
An integer matrix of size (M x N) has been given. Find out the minimum cost to reach from the cell (0, 0) to (M - 1, N - 1).
From a cell (i, j), you can move in three directions:
1. ((i + 1),  j) which is, "down"
2. (i, (j + 1)) which is, "to the right"
3. ((i+1), (j+1)) which is, "to the diagonal"
The cost of a path is defined as the sum of each cell's values through which the route passes.



#include<cmath>
int minCostPath_helper(int **input,int m,int n,int x,int y,int** arr)
{
    if(x==m-1 and y==n-1)
        return input[m-1][n-1];
    
    
    if(arr[x][y]!=-1)
        return arr[x][y];
    
    if(x==m-1)
        return input[x][y]+minCostPath_helper(input,m,n,x,y+1,arr);
    if(y==n-1)
        return input[x][y]+minCostPath_helper(input,m,n,x+1,y,arr);
    
    
    int ans1=minCostPath_helper(input,m,n,x,y+1,arr);
    int ans2=minCostPath_helper(input,m,n,x+1,y+1,arr);
    int ans3=minCostPath_helper(input,m,n,x+1,y,arr);
    
    arr[x][y]=min(ans1,min(ans2,ans3))+input[x][y];
    return arr[x][y];
}
int minCostPath(int **input, int m, int n)
{
    int** arr=new int*[m];
    for(int i=0;i<m;i++)
    {
        arr[i]=new int[n];
        for(int j=0;j<n;j++)
            arr[i][j]=-1;
    }
    
	return minCostPath_helper(input,m,n,0,0,arr);
}





-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------



Code : Edit Distance
____________________
Send Feedback
Given two strings s and t of lengths m and n respectively, find the edit distance between the strings.
Edit Distance
Edit Distance of two strings is minimum number of operations required to make one string equal to other. In order to do so you can perform any of the following three operations only :
1. Delete a character
2. Replace a character with another one
3. Insert a character
Note
Strings don't contain spaces
You need to find the edit distance from input string1 to input string2.



#include<string>
#include<cmath>
#include<algorithm>
#include<climits>
int editDistance(string s1, string s2) {
	
    //base case
    if(s1.size()==0 or s2.size()==0)
        return max(s1.size(),s2.size());
    
    // if(s1==s1)
    //     return 0;
    
    // recursive call
    int min1,min2,min3,min4;
    min1=min2=min3=min4=INT_MAX;
    if(s1[0]==s2[0])
        return min1=editDistance(s1.substr(1),s2.substr(1));
    
    min2=1+editDistance(s1.substr(1),s2);
    min3=1+editDistance(s1,s2.substr(1));
    min4=1+editDistance(s1.substr(1),s2.substr(1));
    return min(min2,min(min3,min4));
}





----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------



Code : Edit Distance (Memoization and DP)
_________________________________________
Send Feedback
You are given two strings S and T of lengths M and N, respectively. Find the 'Edit Distance' between the strings.
Edit Distance of two strings is the minimum number of steps required to make one string equal to the other. In order to do so, you can perform the following three operations:
1. Delete a character
2. Replace a character with another one
3. Insert a character
Note :
Strings don't contain spaces in between.




#include<string>
#include<cmath>
#include<algorithm>
#include<climits>
int editDistance_helper(string s1,string s2,int** arr)
{
    int m=s1.size();
    int n=s2.size();
    if(s1.size()==0 or s2.size()==0)
        return max(m,n);
    
    if(arr[m][n]!=-1)
        return arr[m][n];
    
    int min1,min2,min3,min4;
    min1=min2=min3=min4=INT_MAX;
    if(s1[0]==s2[0])
    {
        min1=editDistance_helper(s1.substr(1),s2.substr(1),arr);
        arr[m][n]=min1;
        return min1;
    }
    min2=1+editDistance_helper(s1.substr(1),s2,arr);
    min3=1+editDistance_helper(s1,s2.substr(1),arr);
    min4=1+editDistance_helper(s1.substr(1),s2.substr(1),arr);
    arr[m][n]=min(min2,min(min3,min4));
    return arr[m][n];
}

int editDistance(string s1, string s2)
{
    int m=s1.size();
    int n=s2.size();
    int** arr=new int*[m+1];
    for(int i=0;i<=m;i++)
        arr[i]=new int[n+1];
    
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
            arr[i][j]=-1;
    }
    return editDistance_helper(s1,s2,arr);
}






---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------



Code : Knapsack
_______________
Send Feedback
A thief robbing a store can carry a maximal weight of W into his knapsack. There are N items, and i-th item weigh 'Wi' and the value being 'Vi.' What would be the maximum value V, that the thief can steal?



#include<algorithm>
int knapsack(int *weights, int *values, int n, int maxWeight)
{
    // base case
	if(n==0 or maxWeight==0)
        return 0;
    
    // if(maxWeight==0)
    //     return 0;
    
    if(weights[0]>maxWeight)
        return knapsack(weights+1,values+1,n-1,maxWeight);
    // recursive call
    int a=values[0]+knapsack(weights+1,values+1,n-1,maxWeight-weights[0]);
    int b=knapsack(weights+1,values+1,n-1,maxWeight);
    
    return max(a,b);
}





--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------



Code: Knapsack (Memoization and DP)
____________________________________
Send Feedback
A thief is robbing a store and can carry a maximal weight of W into his knapsack. There are N items and ith item weighs wi and is of value vi. Considering the constraints of maximum weight that knapsack can carry, you have to find and return the maximum value that thief can generate by stealing items.
Note
Space complexity should be O(W).





int knapsack(int* weights, int* values, int n, int maxWeight,int** arr)
{
    if(n==0 or maxWeight==0)
        return 0;
    
    // if(maxWeight==0)
    //     return 0;
    
    if(arr[n][maxWeight]!=-1)
        return arr[n][maxWeight];
    
    if(weights[0]>maxWeight)
    {
        arr[n][maxWeight]=knapsack(weights+1,values+1,n-1,maxWeight,arr);
        return arr[n][maxWeight];
    }
        
    // recursive call
    int a=values[0]+knapsack(weights+1,values+1,n-1,maxWeight-weights[0],arr);
    int b=knapsack(weights+1,values+1,n-1,maxWeight,arr);
    
    arr[n][maxWeight]=max(a,b);
    return max(a,b);
}

int knapsack(int* weight, int* value, int n, int maxWeight) {
	
    int** arr=new int*[n+1];
    for(int i=0;i<n+1;i++)
        arr[i]=new int[maxWeight+1];
    
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<maxWeight+1;j++)
            arr[i][j]=-1;
    }
    return knapsack(weight,value,n,maxWeight,arr);
}





---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


Loot Houses
___________
Send Feedback
A thief wants to loot houses. He knows the amount of money in each house. He cannot loot two consecutive houses. Find the maximum amount of money he can loot.




#include<algorithm>

int maxMoneyLooted_helper(int *arr,int n,int arr2[])
{
    //base case
    if(n<=0)
        return 0;
    
    // checking is it already exit
    if(arr2[n]!=-1)
        return arr2[n];
    
    // recursive call
    int a=maxMoneyLooted_helper(arr+2,n-2,arr2)+arr[0];
    int b=maxMoneyLooted_helper(arr+1,n-1,arr2);
    arr2[n]=max(a,b);
    return arr2[n];
}

int maxMoneyLooted(int *arr, int n)
{
	int arr2[n+1];
    for(int i=0;i<n+1;i++)
        arr2[i]=-1;
    
    return maxMoneyLooted_helper(arr,n,arr2);
}




---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------



Longest Increasing Subsequence
________________________________
Send Feedback
Given an array with N elements, you need to find the length of the longest subsequence in the given array such that all elements of the subsequence are sorted in strictly increasing order.


int longestIncreasingSubsequence(int* input, int n) 
{
	int* output=new int[n];
    output[0]=1;
    for(int i=1;i<n;i++)
    {
        output[i]=1;
        for(int j=i-1;j>=0;j--)
        {
            if(input[j]>=input[i])
                continue;
            
            int p=output[j]+1;
            output[i]=max(output[i],p);
        }
        
    }
    int ans=1;
    for(int i=0;i<n;i++)
    {
        if(output[i]>ans)
            ans=output[i];
    }
    return ans;
}





---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------



All possible ways
__________________
Send Feedback
Given two integers a and b. You need to find and return the count of possible ways in which we can represent the number a as the sum of unique integers raise to the power b.
For example: if a = 10 and b = 2, only way to represent 10 as sum of unique integers raised to power 2 is-
10 = 1^2 + 3^2 
Hence, answer is 1.
Note : x^y represents x raise to the power y




#include<bits/stdc++.h>

int getAllWays_helper(int a,int b,int curNum,int cursum)
{
    int result=0;
    int p=pow(curNum,b);
    while(p+cursum<a)
    {
        result+=getAllWays_helper(a,b,curNum+1,p+cursum);
        curNum++;
        p=pow(curNum,b);
    }
    if(p+cursum==a)
        result++;
    
    return result;
}


int getAllWays(int a, int b) {
    return  getAllWays_helper(a,b,1,0);
}






--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------



Ways To Make Coin Change
________________________
Send Feedback
For the given infinite supply of coins of each of denominations, D = {D0, D1, D2, D3, ...... Dn-1}. You need to figure out the total number of ways W, in which you can make the change for Value V using coins of denominations D.
Return 0 if the change isn't possible




#include<algorithm>
#include<climits>
#include<bits/stdc++.h>

int countWaysToMakeChange(int denominations[], int numDenominations, int value){

    int table[value+1];
    memset(table,0,sizeof(table));
    table[0]=1;
    
    for(int i=0;i<numDenominations;i++)
    {
        for(int j=denominations[i];j<=value;j++)
        {
            table[j]+=table[j-denominations[i]];
        }
    }
    return table[value];

}







----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------



Matrix Chain Multiplication
__________________________
Send Feedback
Given a chain of matrices A1, A2, A3,.....An, you have to figure out the most efficient way to multiply these matrices. In other words, determine where to place parentheses to minimize the number of multiplications.
You will be given an array p[] of size n + 1. Dimension of matrix Ai is p[i - 1]*p[i]. You need to find minimum number of multiplications needed to multiply the chain.





#include <bits/stdc++.h>
using namespace std;

int f(vector<vector <int> > &dp,int *p,int s,int e){
    if(e-s==1)
        return 0;
    
    if(dp[s][e])
        return dp[s][e];
    
    int ans=INT_MAX;
    for(int k=s+1;k<e;k++){
        int temp=f(dp,p,s,k)+f(dp,p,k,e)+p[s]*p[k]*p[e];
        ans=min(ans,temp);
    }
    dp[s][e]=ans;
    return ans;
}

int matrixChainMultiplication(int* p, int n){

  /* Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Return output and don't print it.
   *  Taking input and printing output is handled automatically.
  */
    
    vector <vector <int> > dp(n+1,vector<int>(n+1,0));
    int ans=f(dp,p,0,n);
    return ans;
    
    
    


}






----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


Maximum Square Matrix With All Zeros
_____________________________________
Send Feedback
Given an NxM matrix that contains only 0s and 1s, find out the size of the maximum square sub-matrix with all 0s. You need to return the size of the square matrix with all 0s.





#include <bits/stdc++.h>
using namespace std;
int findMaxSquareWithAllZeros(int** arr, int row, int col){
    
    if(row==0 and col==0)
        return 0;
    
    int dp[row][col];
    for(int i=0;i<row;i++)
      dp[i][0]=arr[i][0]^1;
    
    for(int i=0;i<col;i++)
        dp[0][i]=arr[0][i]^1;
    
    int max_final=INT_MIN;
    for(int i=1;i<row;i++)
    {
        for(int j=1;j<col;j++)
        {
            if(arr[i][j]==0)
                dp[i][j]=1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
            else
                dp[i][j]=0;
            
            max_final=max(max_final,dp[i][j]);
        }
    }
    return max_final;
}






---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------



Shortest Subsequence
_____________________
Send Feedback
Gary has two string S and V. Now, Gary wants to know the length shortest subsequence in S, which is not a subsequence in V.
Note: The input data will be such that there will always be a solution.




#include <bits/stdc++.h>
using namespace std;

int ss(vector < vector <int> > &dp,string s,string v){
    
    if(s.size()==0)
        return 1550;
    
    if(v.size()<=0)
        return 1;
    
    if(dp[s.size()][v.size()])
        return dp[s.size()][v.size()];
    int i;
    for(i=0;i<v.size();i++){
        
        if(s[0]==v[i])
            break;
    }
    if(i==v.size())
        return 1;
    
    int option1=ss(dp,s.substr(1),v);
    int option2=1+ss(dp,s.substr(1),v.substr(i+1));
    
    int ans=min(option1,option2);
    
    dp[s.size()][v.size()]=ans;
    return ans;
}


int solve(string S,string V)
{
	// Write your code here.
    vector < vector <int> > dp(S.size()+1,vector<int>(V.size()+1,0));
    int ans=ss(dp,S,V);
    
    return ans;
    
}




------------------------------------------------------------------------------------------------END-------------------------------------------------------------------------------------------