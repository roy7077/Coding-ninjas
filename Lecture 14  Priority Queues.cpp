Code : Remove Min
_________________
Send Feedback
Implement the function RemoveMin for the min priority queue class.
For a minimum priority queue, write the function for removing the minimum element present. Remove and return the minimum element.
Note : main function is given for your reference which we are using internally to test the code.



#include <vector>
#include<algorithm>
class PriorityQueue {
    vector<int> pq;

   public:
    bool isEmpty() { 
        return pq.size() == 0; 
    }

    int getSize() { 
        return pq.size(); 
    }

    int getMin() {
        if (isEmpty()) {
            return 0;
        }

        return pq[0];
    }

    void insert(int element) {
        pq.push_back(element);

        int childIndex = pq.size() - 1;

        while (childIndex > 0) {
            int parentIndex = (childIndex - 1) / 2;

            if (pq[childIndex] < pq[parentIndex]) {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            } else {
                break;
            }

            childIndex = parentIndex;
        }
    }

    int removeMin() 
    {
        if (isEmpty()) {
            return 0;
        }
        int ans=pq[0];
        swap(pq[0],pq[pq.size()-1]);
        pq.pop_back();
        int parent=0;
        int childindex1=0+1;
        int childindex2=0+2;
        
        while(childindex1<pq.size()-1 and childindex2<pq.size()-1)
        {
            if(pq[parent]<pq[childindex1] and pq[parent]<pq[childindex2])
            {
                break;
            }
            else if(pq[childindex1]<pq[parent] and pq[childindex1]<pq[childindex2])
            {
                swap(pq[parent],pq[childindex1]);
                parent=childindex1;
            }else
            {
                swap(pq[parent],pq[childindex2]);
                parent=childindex2;
            }
            childindex1=2*parent+1;
            childindex2=2*parent+2;
            
        }
        return ans;
            
    }
};







---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------



Code : Max Priority Queue
_________________________
Send Feedback
Implement the class for Max Priority Queue which includes following functions -
1. getSize -
Return the size of priority queue i.e. number of elements present in the priority queue.
2. isEmpty -
Check if priority queue is empty or not. Return true or false accordingly.
3. insert -
Given an element, insert that element in the priority queue at the correct position.
4. getMax -
Return the maximum element present in the priority queue without deleting. Return -Infinity if priority queue is empty.
5. removeMax -
Delete and return the maximum element present in the priority queue. Return -Infinity if priority queue is empty.
Note : main function is given for your reference which we are using internally to test the class.



#include<vector>
#include<climits>
class PriorityQueue {
    vector<int> pq;

   public:
    PriorityQueue() {
        // Implement the constructor here
    }

    /**************** Implement all the public functions here ***************/

    

    void insert(int element) {
      // Implement the insert() function here
      pq.push_back(element);
      int childindex = pq.size() - 1;
      while (childindex > 0) {
        int parentindex = (childindex - 1) / 2;
        if (pq[parentindex] < pq[childindex]) {
          swap(pq[parentindex], pq[childindex]);
        } else {
          break;
        }
        childindex = parentindex;
      }
    }

    int getMax() {
        if(pq.empty())
            return INT_MIN;
        
        return pq[0];
    }

    int removeMax() 
    {
        if (isEmpty()) {
            return INT_MIN;
        }
        int ans=pq[0];
        swap(pq[0],pq[pq.size()-1]);
        pq.pop_back();
        int parent=0;
        int childindex1=0+1;
        int childindex2=0+2;
        
        while(childindex1<pq.size()-1 and childindex2<pq.size()-1)
        {
            if(pq[parent]>pq[childindex1] and pq[parent]>pq[childindex2])
            {
                break;
            }
            else if(pq[childindex1]>pq[parent] and pq[childindex1]>pq[childindex2])
            {
                swap(pq[parent],pq[childindex1]);
                parent=childindex1;
            }else
            {
                swap(pq[parent],pq[childindex2]);
                parent=childindex2;
            }
            childindex1=2*parent+1;
            childindex2=2*parent+2;
            
        }
        return ans;
            
    }
    

    int getSize() { 
        return pq.size();
    }

    bool isEmpty() {
        return pq.empty();
    }
};






---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------




Code : In-place heap sort
_________________________
Send Feedback
Given an integer array of size N. Sort this array (in decreasing order) using heap sort.
Note: Space complexity should be O(1).




#include<algorithm>
void insert_heap(int arr[],int n)
{
    for(int i=1;i<n;i++)
    {
        int childIndex=i;
        int parentIndex=0;
        while (childIndex > 0) 
        {
            int parentIndex=(childIndex-1)/2;

            if (arr[childIndex]<arr[parentIndex]) 
            {
                int temp=arr[childIndex];
                arr[childIndex]=arr[parentIndex];
                arr[parentIndex]=temp;
            } 
            else 
              break;
             
            childIndex = parentIndex;
        }
    }
}
void heap_sort(int pq[],int n)
{
    
    int size = n;

	while(size > 1) {
		int temp = pq[0];
		pq[0] = pq[size - 1];
		pq[size-1] = temp;

		size--;

		int parentIndex = 0;
		int leftChildIndex = 2 * parentIndex + 1;
		int rightChildIndx = 2 * parentIndex + 2;

		while(leftChildIndex < size) {
			int minIndex = parentIndex;
			if(pq[minIndex] > pq[leftChildIndex]) {
				minIndex = leftChildIndex;
			}
			if(rightChildIndx < size && pq[rightChildIndx] < pq[minIndex]) {
				minIndex = rightChildIndx;
			}
			if(minIndex == parentIndex) {
				break;
			}
			int temp = pq[minIndex];
			pq[minIndex] = pq[parentIndex];
			pq[parentIndex] = temp;

			parentIndex = minIndex;
			leftChildIndex = 2 * parentIndex + 1;
			rightChildIndx = 2 * parentIndex + 2;
		}
    
}
  
  }




void heapSort(int arr[], int n) 
{
    insert_heap(arr,n);
    heap_sort(arr,n);
}







--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------



Code : K smallest Elements
__________________________
Send Feedback
You are given with an integer k and an array of integers that contain numbers in random order. Write a program to find k smallest numbers from given array. You need to save them in an array and return it.
Time complexity should be O(n * logk) and space complexity should not be more than O(k).
Note: Order of elements in the output is not important.




#include<vector>
#include<queue>
vector<int> kSmallest(int arr[], int n, int k) {
    
    vector<int> v;
    priority_queue<int> pq;
    for(int i=0;i<k;i++)
    {
        pq.push(arr[i]);
    }
    for(int i=k;i<n;i++)
    {
        if(pq.top()>arr[i])
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }
    for(int i=0;i<k;i++)
    {
        v.push_back(pq.top());
        pq.pop();
    }
    return v;
}





-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


Code : K largest elements
_________________________
Send Feedback
You are given with an integer k and an array of integers that contain numbers in random order. Write a program to find k largest numbers from given array. You need to save them in an array and return it.
Time complexity should be O(nlogk) and space complexity should be not more than O(k).
Order of elements in the output is not important.
Input Format :
Line 1 : Size of array (n)
Line 2 : Array elements (separated by space)
Line 3 : Integer k



#include<vector>
#include<queue>
vector<int> kLargest(int arr[], int n, int k){
   
    vector<int> v;
    priority_queue<int,vector<int>,greater<int>>pq;
    for(int i=0;i<k;i++)
    {
        pq.push(arr[i]);
    }
    for(int i=k;i<n;i++)
    {
        if(pq.top()<arr[i])
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }
    for(int i=0;i<k;i++)
    {
        v.push_back(pq.top());
        pq.pop();
    }
    return v;
}







--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------



Check Max-Heap
______________
Send Feedback
Given an array of integers, check whether it represents max-heap or not. Return true if the given array represents max-heap, else return false.



bool isMaxHeap(int arr[], int n) {
    
    if(arr==NULL)
        return false;
    
		for(int i=0;i<n;i++)
        {
            int parent=i;
            int childindex1=2*i+1;
            int childindex2=2*i+2;
            
            if(childindex1<n and arr[childindex1]>arr[parent] or childindex2<n and arr[childindex2]>arr[parent])
            {
                return false;
            }
        }
		return true;
        
        
  
}




--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------



Kth largest element
___________________
Send Feedback
Given an array A of random integers and an integer k, find and return the kth largest element in the array.
Note: Try to do this question in less than O(N * logN) time.




#include<queue>
int kthLargest(int* arr, int n, int k) 
{
    
    priority_queue<int> pq;
    for(int i=0;i<n;i++)
    {
        pq.push(arr[i]);
    }
    for(int i=0;i<k-1;i++)
    {
         pq.pop();
    }
    return pq.top();
}






--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


Merge K sorted arrays
_____________________
Send Feedback
Given k different arrays, which are sorted individually (in ascending order). You need to merge all the given arrays such that output array should be sorted (in ascending order).
Hint : Use Heaps.




#include<vector>
#include<queue>
vector<int> mergeKSortedArrays(vector<vector<int>*> input) {
    
    priority_queue<int,vector<int>,greater<int>> pq;
    
    for(int i=0;i<input.size();i++)
    {
        
        for(int j=0;j<input[i]->size();j++)
        {
            pq.push(input[i]->at(j));
            
        }
     
    }
    
    vector<int> v;
    while(!pq.empty())
    {
        v.push_back(pq.top());
        pq.pop();
    }
    return v;
    
}







--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------



Running Median
______________
Send Feedback
You are given a stream of 'N' integers. For every 'i-th' integer added to the running list of integers, print the resulting median.
Print only the integer part of the median.



#include<queue>
void findMedian(int *arr, int n)
{
    // max heap to store the smaller half elements
    if(n==0)
        return ;
    
    priority_queue<int> s;
 
    // min heap to store the greater half elements
    priority_queue<int,vector<int>,greater<int> > g;
 
    int med = arr[0];
    s.push(arr[0]);
 
    cout << med <<" ";
 
    // reading elements of stream one by one
    /*  At any time we try to make heaps balanced and
        their sizes differ by at-most 1. If heaps are
        balanced,then we declare median as average of
        min_heap_right.top() and max_heap_left.top()
        If heaps are unbalanced,then median is defined
        as the top element of heap of larger size  */
    for (int i=1; i < n; i++)
    {
        int x = arr[i];
 
        // case1(left side heap has more elements)
        if (s.size() > g.size())
        {
            if (x < med)
            {
                g.push(s.top());
                s.pop();
                s.push(x);
            }
            else
                g.push(x);
 
            med = (s.top() + g.top())/2;
        }
 
        // case2(both heaps are balanced)
        else if (s.size()==g.size())
        {
            if (x < med)
            {
                s.push(x);
                med = s.top();
            }
            else
            {
                g.push(x);
                med = g.top();
            }
        }
 
        // case3(right side heap has more elements)
        else
        {
            if (x > med)
            {
                s.push(g.top());
                g.pop();
                g.push(x);
            }
            else
                s.push(x);
 
            med = (s.top() + g.top())/2;
        }
 
        cout << med <<" ";
    }
}





-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------



Buy the ticket
_____________
Send Feedback
You want to buy a ticket for a well-known concert which is happening in your city. But the number of tickets available is limited. Hence the sponsors of the concert decided to sell tickets to customers based on some priority.
A queue is maintained for buying the tickets and every person is attached with a priority (an integer, 1 being the lowest priority).
The tickets are sold in the following manner -
1. The first person (pi) in the queue requests for the ticket.
2. If there is another person present in the queue who has higher priority than pi, then ask pi to move at end of the queue without giving him the ticket.
3. Otherwise, give him the ticket (and don't make him stand in queue again).
Giving a ticket to a person takes exactly 1 second and it takes no time for removing and adding a person to the queue. And you can assume that no new person joins the queue.
Given a list of priorities of N persons standing in the queue and the index of your priority (indexing starts from 0). Find and return the time it will take until you get the ticket.



#include<queue>
int buyTicket(int *arr, int n, int k) {
    
   queue<int> q;
   priority_queue<int> pq;
    for(int i=0;i<n;i++)
    {
        q.push(i);
        pq.push(arr[i]);
    }
    int j=0;
    while(!q.empty())
    {
        if(pq.top()==arr[q.front()])
        {
            if(q.front()==k)
            {
                j++;
                return j;
            }
                
            
            j++;
            pq.pop();
            q.pop();
        }
        else
        {
            q.push(q.front());
            q.pop();
        }
    }
}




---------------------------------------------------------------------------------------END--------------------------------------------------------------------------------------------------