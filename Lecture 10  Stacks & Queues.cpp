Code : Stack Using LL
_____________________
Send Feedback
Implement a Stack Data Structure specifically to store integer data using a Singly Linked List.
The data members should be private.
You need to implement the following public functions :



class Stack {
	int size;
    Node* head;
   public:
    Stack() {
        head=NULL;
        size=0;
    }

	/*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        return size;
    }

    bool isEmpty() {
        return head==NULL;
    }

    void push(int element) {
        Node* newnode=new Node(element);
        newnode->next=head;
        head=newnode;
        size++;
    }

    int pop() {
        if(size==0)
        {
            return -1;
        }
        Node* temp=head;
        int data=temp->data;
        head=head->next;
        delete temp;
        size--;
        return data;
    }

    int top() {
        if(size==0)
        {
            return -1;
        }
        return head->data;
            
    }
};









---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Code : Balanced Parenthesis
___________________________
Send Feedback
For a given a string expression containing only round brackets or parentheses, check if they are balanced or not. 
Brackets are said to be balanced if the bracket which opens last, closes first.
Example:
Expression: (()())
Since all the opening brackets have their corresponding closing brackets, we say it is balanced and hence the output will be, 'true'.
You need to return a boolean value indicating whether the expression is balanced or not.


#include <stack>
bool isBalanced(string str) 
{
    stack<char> a;
    for(auto ch:str)
    {
        switch(ch)
        {
            case '[':
            case '{':
            case '(': a.push(ch);
                      break;
            case '}': if(!a.empty() and a.top()=='{')
                      a.pop();
                      else
                          return false;
                     break;
            case ']': if(!a.empty() and a.top()==']')
                      a.pop();
                      else
                          return false;
                     break;
            case ')': if(!a.empty() and a.top()=='(')
                      a.pop();
                      else
                          return false;
                     break;
        }
    }
    if(a.empty())
        return true;
    else
        return false;
        
}







---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Code : Queue Using LL
_____________________
Send Feedback
Implement a Queue Data Structure specifically to store integer data using a Singly Linked List.
The data members should be private.
You need to implement the following public functions :



class Queue {
	Node* head;
    Node* tail;
    int size;
   public:
    Queue() {
		head=NULL;
        tail=NULL;
        size=0;
	}
	
	/*----------------- Public Functions of Stack -----------------*/

	int getSize() 
    {
		 return size;
	}

    bool isEmpty() {
		return size==0;
	}

    void enqueue(int data) 
    {
        Node* newnode=new Node(data);
        if(head==NULL)
        {
            head=newnode;
            tail=newnode;
        }else
        {
            tail->next=newnode;
            tail=newnode;
        }
		size++;
	}

    int dequeue() 
    {
        if(isEmpty())
            return -1;
        
        Node* temp=head;
        int ans=temp->data;
        head=head->next;
        delete temp;
        size--;
        return ans;
    }

    int front() 
    {
        if(isEmpty())
            return -1;
        
        return head->data;
    }
};








---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Reverse a Stack
_______________
Send Feedback
You have been given two stacks that can store integers as the data. Out of the two given stacks, one is populated and the other one is empty. 
You are required to write a function that reverses the populated stack using the one which is empty.


void reverseStack(stack<int> &input, stack<int> &extra) 
{
    
    while(!input.empty())
    {
        extra.push(input.top());
        input.pop();
    }
    
    input=extra;
}






----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Reverse Queue
_____________
Send Feedback
You have been given a queue that can store integers as the data. You are required to write a function that reverses the 
populated queue itself without using any other data structures.


#include<queue>
void reverseQueue(queue<int> &input) 
{
	if(input.empty())
    {
        return ;
    }
    
    int a=input.front();
    input.pop();

    reverseQueue(input);
    input.push(a);
}






----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Check redundant brackets
________________________
Send Feedback
For a given expression in the form of a string, find if there exist any redundant brackets or not. It is given that the expression contains only rounded brackets 
or parenthesis and the input expression will always be balanced.
A pair of the bracket is said to be redundant when a sub-expression is surrounded by unnecessary or needless brackets.


#include<stack>
bool checkRedundantBrackets(string exp) {
	// Write your code here
    stack<char> a;
    for(auto ch:exp)
    {
        if(ch!=')')
            a.push(ch);
        else
        {
            bool operator_found=false;
            while(!a.empty() and a.top()!='(')
            {
                char top=a.top();
                if(top=='+' or top=='-' or top=='*' or top=='/')
                  operator_found=true;
                
                a.pop();
            }
            a.pop();
            if(!operator_found)
                return true;
        }
            
    }
    
    return false;
}







----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Stock Span
__________
Send Feedback
Afzal has been working with an organization called 'Money Traders' for the past few years. The organization is into the money trading business. 
His manager assigned him a task. For a given array/list of stock's prices for N days, find the stock's span for each day.
The span of the stock's price today is defined as the maximum number of consecutive days(starting from today and going backwards) 
for which the price of the stock was less than today's price.
For example, if the price of a stock over a period of 7 days are [100, 80, 60, 70, 60, 75, 85], then the stock spans will be [1, 1, 1, 2, 1, 4, 6].



#include <stack>
#include <iostream>
#include <vector>
using namespace std;
int* stockSpan(int *price, int size) {
	
    int *span=new int[size];
    stack<int> stk;
    
    // first thing
    stk.push(0);
    span[0]=1;
    
    // loop for finding span //  
    for(int i=1;i<size;i++)
    {
        // 1st thing is to find the pre large
        while(!stk.empty() and price[stk.top()]<price[i])
            stk.pop();
        
        // calculate the span 
        if(stk.empty())
            span[i]=i+1;
        else
            span[i]=i-stk.top();
        
        stk.push(i);
    }
    
    return span;

}









---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Minimum bracket Reversal
________________________
Send Feedback
For a given expression in the form of a string, find the minimum number of brackets that can be reversed in order to make the expression balanced. 
The expression will only contain curly brackets.
If the expression can't be balanced, return -1.



#include<stack>
int countBracketReversals(string input) 
{
	if(input.length()%2)
        return -1;
    
    int i=0;
    stack<char> a;
    while(input[i]!='\0')
    {
        if(input[i]=='}' and !a.empty())
        {
            if(a.top()=='{')
                a.pop();
            else
                a.push(input[i]);
                i++;
        }
        else
        {
            a.push(input[i]);
                i++;
        }
    }
    
    int len=a.size();
    int n=0;
    while(!a.empty() and a.top()=='{')
    {
        a.pop();
        n++;
    }
    return (len/2)+(n%2);
}




______________________________END__________________________________________________________________________________________________________________________________________________________________