Code : Maximum Frequency Number
_______________________________
Send Feedback
You are given an array of integers that contain numbers in random order. Write a program to find and return the number which occurs the maximum times in the given input.
If two or more elements contend for the maximum frequency, return the element which occurs in the array first.


#include<unordered_map>
int highestFrequency(int input[], int n) {
    
    
    unordered_map<int, int> map;
    int maxFreq = 1;
    for(int i = 0; i < n; i++){
        if(map.count(input[i]) > 0){
            map[input[i]]++;
            if(map[input[i]] > maxFreq){
                maxFreq = map[input[i]];
            }
        }
        else
        map[input[i]] = 1;
    }
    for(int i = 0; i < n; i++){
        if(map[input[i]] == maxFreq){
            return input[i];
        }
    }
}




--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


Code : Print Intersection
_________________________
Send Feedback
You have been given two integer arrays/lists (ARR1 and ARR2) of size N and M, respectively. You need to print their intersection; An intersection for this problem can be defined when both the arrays/lists contain a particular value or to put it in other words, when there is a common value that exists in both the arrays/lists.
Note :
Input arrays/lists can contain duplicate elements.

The intersection elements printed would be in the order they appear in the second array/list (ARR2).



#include <unordered_map>
#include<algorithm>
void printIntersection(int arr1[], int arr2[], int n, int m) {
    
    if(n==0 and m==0)
        return ;
    
     unordered_map<int, int> map1;
     sort(arr1,arr1+n);
    for(int i=0;i<m;i++)
    {
            map1[arr2[i]]++;
    }
    for(int i=0;i<n;i++)
    {
        if(map1.find(arr1[i])!=map1.end())
        {
            if(map1[arr1[i]]>0)
            {
                cout<<arr1[i]<<endl;

                map1[arr1[i]]--;
            }
        }
    }
        
}



---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------




Code : Pair Sum to 0
____________________
Send Feedback
Given a random integer array A of size N. Find and print the count of pair of elements in the array which sum up to 0.
Note: Array A can contain duplicate elements as well.



#include<algorithm>
#include<unordered_map>
int pairSum(int *arr, int n) 
{
	unordered_map<int,int> map;
    int count=0;
    for(int i=0;i<n;i++)
    {
        count+=map[-arr[i]];
        map[arr[i]]++;
    }
    
    return count;
}






--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


Extract Unique characters
_________________________
Send Feedback
Given a string S, you need to remove all the duplicates. That means, the output string should contain each character only once. The respective order of characters should remain same, as in the input string.




#include <unordered_map>
#include<string>
string uniqueChar(string str) {
	
    string s="";
    unordered_map<char,bool> umap;
    for(int i=0;i<str.length();i++)
    {
        if(umap.count(str[i]))
            continue;
        else
        {
            s+=str[i];
            umap[str[i]]=true;
        }
    }
    return s;
}





--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


Longest Consecutive Sequence
____________________________
Send Feedback
You are given an array of unique integers that contain numbers in random order. You have to find the longest possible sequence of consecutive numbers using the numbers from given array.
You need to return the output array which contains starting and ending element. If the length of the longest possible sequence is one, then the output array must contain only single element.
Note:
1. Best solution takes O(n) time.
2. If two sequences are of equal length, then return the sequence starting with the number whose occurrence is earlier in the array.




#include<unordered_map>
#include<vector>
vector<int> longestConsecutiveIncreasingSequence(int *arr, int n) 
{
    unordered_map<int,int> x;
    for(int i=0;i<n;i++)
    {
        x[arr[i]]=true;
    }
    vector<int> ans;
    int count=1;
    int max1=1;
    int maxs=arr[0];
    for(int i=0;i<n;i++)
    {
        if(x.find(arr[i]-1)==x.end())
        {
            int j=arr[i];
            while(x.find(j+1)!=x.end())
            {
                count++;
                j++;
            }
        }
        if(count>max1){
            max1=count;
            maxs=arr[i];
        }
        count=1;
    }
    if(max1==1)
    {
        ans.push_back(maxs);
        return ans;
    }
    ans.push_back(maxs);
    ans.push_back(max1+maxs-1);
    return ans;
}

    
    

---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


Pairs with difference K
_______________________
Send Feedback
You are given with an array of integers and an integer K. You have to find and print the count of all such pairs which have difference K.
Note: Take absolute difference between the elements of the array.


#include<unordered_map>
int getPairsWithDifferenceK(int *arr, int n, int k) {
	
    if(!n)
        return 0;
    
    unordered_map<int,int> map;
    int count=0;
    
    for(int i=0;i<n;i++)
    {
        int check1=arr[i]+k;
        int check2=arr[i]-k;
        
        count+=map[check1];
        if(k!=0)
            count+=map[check2];
        
        map[arr[i]]++;
    }
    return count;
}






---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------



Longest subset zero sum
_______________________
Send Feedback
Given an array consisting of positive and negative integers, find the length of the longest subarray whose sum is zero.


#include<unordered_map>
int lengthOfLongestSubsetWithZeroSum(int* arr, int n) {
    
    unordered_map<int,int> map;
    int sum=0;
    int max1=0;
     // map[0]=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
        if(sum==0)
        {
            max1=max(max1,i+1);
        }
        if(map.count(sum))
        {
            max1=max(max1,i-map[sum]);
        }
        else 
            map[sum]=i;
        
    }
    return max1;
}





------------------------------------------------------------------------------------------END------------------------------------------------------------------------------------------------