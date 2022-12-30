Length of LL
______________
Send Feedback
For a given singly linked list of integers, find and return its length. Do it using an iterative method.
Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

First and the only line of each test case or query contains elements of the singly linked list separated by a single space. 




int length(Node *head)
{
    Node *temp = head;
    int length = 0;
    while(temp!=NULL){
        length++;
        temp = temp->next;
    }
    
    return length;
}





----------------------------------------------------------------------------------------------------------------------------------------------

Print ith node
______________
Send Feedback
For a given a singly linked list of integers and a position 'i', print the node data at the 'i-th' position.
 Note :
Assume that the Indexing for the singly linked list always starts from 0.

If the given position 'i',  is greater than the length of the given singly linked list, then don't print anything.



void printIthNode(Node *head, int i)
{
    Node *temp = head;
    int j = 0;
    while(temp!=NULL && j<i){
        temp = temp->next;
        j++;
    }
    
    cout<<temp->data<<endl;
}






------------------------------------------------------------------------------------------------------------------------------------------------------------------

Delete node
____________
Send Feedback
You have been given a linked list of integers. Your task is to write a function that deletes a node from a given position, 'POS'.
Note :
Assume that the Indexing for the linked list always starts from 0.

If the position is greater than or equal to the length of the linked list, you should return the same linked list without any change.



Node *deleteNode(Node *head, int pos)
{
    if(head==NULL)
    return head;
    
    if(pos==0)
    {
        Node* temp1=head->next;
        delete head;
        return temp1;
    }
    
    Node* temp=deleteNode(head->next,pos-1);
    head->next=temp;
    return head;
}








-------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Length of LL (recursive)
________________________
Send Feedback
Given a linked list, find and return the length of the given linked list recursively.
Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

First and the only line of each test case or query contains elements of the singly linked list separated by a single space. 



int length(Node *head) 
{
    if(head==NULL)
        return 0;
    
    return 1+length(head->next);
}









-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Insert node (recursive)
________________________
Send Feedback
You have been given a linked list of integers. Your task is to write a function that inserts a node at a given position, 'pos'.
Note:
Assume that the Indexing for the linked list always starts from 0.

If the given position 'pos' is greater than length of linked list, then you should return the same linked list without any change.
And if position 'pos' is equal to length of input linked list, then insert the node at the last position.


Node* insertNode(Node *head, int i, int data) 
{
    if(head==NULL)
        return head;
    
	if(i==0)
    {
       Node* newnode=new Node(data);
       newnode->next=head;
       return newnode;
    }
    Node* temp1=insertNode(head->next,i-1,data);
    head->next=temp1;
    return head;
    
}










-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Delete node (recursive)
________________________
Send Feedback
Given a singly linked list of integers and position 'i', delete the node present at the 'i-th' position in the linked list recursively.
 Note :
Assume that the Indexing for the linked list always starts from 0.

No need to print the list, it has already been taken care. Only return the new head to the list.





Node *deleteNodeRec(Node *head, int pos) 
{
	if(head==NULL)
    return head;
    
    if(pos==0)
    {
        Node* temp1=head->next;
        delete head;
        return temp1;
    }
    
    Node* temp=deleteNodeRec(head->next,pos-1);
    head->next=temp;
    return head;
}








----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Find a Node in Linked List
__________________________
Send Feedback
You have been given a singly linked list of integers. Write a function that returns the index/position of integer data denoted by 'N' (if it exists). Return -1 otherwise.
Note :
Assume that the Indexing for the singly linked list always starts from 0.




int findNode(Node *head, int n)
{
    if(head==NULL)
        return -1;
    
    if(head->data==n)
        return 0;
    
    int a=findNode(head->next,n);
    if(a==-1)
        return -1;
    else
        return 1+a;
}








---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
AppendLastNToFirst
_________________
Send Feedback
You have been given a singly linked list of integers along with an integer 'N'. Write a function to append the last 'N' nodes towards the front of the 
singly linked list and returns the new head to the list.





Node *appendLastNToFirst(Node *head, int n)
{
    Node* temp=head;
    Node* temp3=NULL;
    int count=0;
    while(temp!=NULL)
    {
        temp3=temp;
        temp=temp->next;
        count++;
    }
    if(n>=count or n==0)
        return head;
    
    int i=1;
    temp=head;
    while(i<=(count-n)-1)
    {
        temp=temp->next;
        i++;
    }
    Node* temp2=temp->next;
    temp->next=NULL;
    temp3->next=head;
    return temp2;
    
}











------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Eliminate duplicates from LL
_____________________________
Send Feedback
You have been given a singly linked list of integers where the elements are sorted in ascending order. 
Write a function that removes the consecutive duplicate values such that the given list only contains unique 
elements and returns the head to the updated list.


Node *removeDuplicates(Node *head)
{
    if(head==NULL)
        return head;
    
    Node* temp=head;
    while(temp->next!=NULL)
    {
        
        if((temp->data)==((temp->next)->data))
        {
            Node* temp1=(temp->next)->next;
            delete temp->next;
            temp->next=temp1;
        }
        else
            temp=temp->next;
    }
    return head;
}











------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Print Reverse LinkedList
________________________
Send Feedback
You have been given a singly linked list of integers. Write a function to print the list in a reverse order.
To explain it further, you need to start printing the data from the tail and move towards the head of the list, printing the head data at the end.


void printReverse(Node *head)
{
    if(head==NULL)
    {
        return ;
    }
    printReverse(head->next);
    cout<<head->data<<" ";
    
}




---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Palindrome LinkedList
_____________________
Send Feedback
You have been given a head to a singly linked list of integers. Write a function check to whether the list given is a 'Palindrome' or not.


#include<stack>
bool isPalindrome(Node *head)
{
    stack<Node*> st;
    Node* temp=head;
    while(temp!=NULL)
    {
        st.push(temp);
        temp=temp->next;
    }
    temp=head;
    while(temp!=NULL)
    {
        Node* temp2=st.top();
        st.pop();
        if(temp2->data!=temp->data)
            return false;
        
        temp=temp->next;
    }
    return true;
}





-----------------------------------------------------------END-------------------------------------------------------------------------------------------------------------------------------------------------------------------------
