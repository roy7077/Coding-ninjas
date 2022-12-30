Code: Midpoint of LL
____________________
Send Feedback
For a given singly linked list of integers, find and return the node present at the middle of the list.
Note :
If the length of the singly linked list is even, then return the first middle node.

Example: Consider, 10 -> 20 -> 30 -> 40 is the given list, then the nodes present at the middle with respective 
data values are, 20 and 30. We return the first node with data 20.



Node* midPoint(Node* head)
{
    if(head==NULL)
        return NULL;
    
    Node* slow=head;
    Node* fast=head;
    
    while((fast)->next!=NULL and (fast->next)->next!=NULL)
    {
        slow=(slow)->next;
        fast=((fast)->next)->next;
    }
    return (slow);
}







---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Code : Reverse LL (Recursive)
_____________________________
Send Feedback
Given a singly linked list of integers, reverse it using recursion and return the head to the modified list. 
You have to do this in O(N) time complexity where N is the size of the linked list.
 Note :
No need to print the list, it has already been taken care. Only return the new head to the list.



Node *reverseLinkedListRec(Node *head)
{
    if(head==NULL or head->next==NULL)
        return head;
    
    Node* temp=reverseLinkedListRec(head->next);
    head->next->next=head;
    head->next=NULL;
    return temp;
}








----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Code: Reverse LL (Iterative)
____________________________
Send Feedback
Given a singly linked list of integers, reverse it iteratively and return the head to the modified list.
 Note :
No need to print the list, it has already been taken care. Only return the new head to the list.



Node *reverseLinkedList(Node *head) {
    if(head==NULL or head->next==NULL)
        return head;
    
    Node* pre=NULL;
    Node* current=head;
    Node* next=NULL;
    
    while(current!=NULL)
    {
        next=current->next;
        current->next=pre;
        pre=current;
        current=next;
    }
    return pre;
     
}







----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Find a node in LL (recursive)
_____________________________
Send Feedback
Given a singly linked list of integers and an integer n, find and return the index for the first occurrence of 'n' in the linked list. -1 otherwise.
Follow a recursive approach to solve this.
Note :
Assume that the Indexing for the linked list always starts from 0.



int findNodeRec(Node *head, int n)
{
    if(head==NULL)
        return -1;
    
    if(head->data==n)
        return 0;
    
    int i= findNodeRec(head->next,n);
    if(i<0)
        return -1;
    else
        return i+1;
}








----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Even after Odd LinkedList
_________________________
Send Feedback
For a given singly linked list of integers, arrange the elements such that all the even numbers are placed after the odd numbers. 
The relative order of the odd and even terms should remain unchanged.
Note :
No need to print the list, it has already been taken care. Only return the new head to the list.


Node *evenAfterOdd(Node *head)
{
	//write your code here
   if(head==NULL)
       return NULL;
    
    Node* oddh=NULL;
    Node* oddt=NULL;
    Node* evenh=NULL;
    Node* event=NULL;
    
    Node* temp=head;
    while(temp!=NULL)
    {
        if((temp->data)%2!=0)
        {
            if(oddh==NULL)
            {
                oddh=temp;
                oddt=temp;
            }else
            {
                oddt->next=temp;
                oddt=temp;
            }
        }else
        {
            if(evenh==NULL)
            {
                evenh=temp;
                event=temp;
            }else
            {
                event->next=temp;
                event=temp;
            }
        }
        temp=temp->next;
    }
    if(oddh!=NULL)
    oddt->next=NULL;
    if(event!=NULL)
    event->next=NULL;
    
    if(oddh!=NULL and evenh!=NULL)
    {
        oddt->next=evenh;
        return oddh;
    }else if(oddh==NULL)
    {
        return evenh;
    }
    else
        return oddh;
}










----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Delete every N nodes
____________________
Send Feedback
You have been given a singly linked list of integers along with two integers, 'M,' and 'N.' Traverse the linked list such that you retain the 'M' nodes, 
then delete the next 'N' nodes. Continue the same until the end of the linked list.
To put it in other words, in the given linked list, you need to delete N nodes after every M nodes.
Note :
No need to print the list, it has already been taken care. Only return the new head to the list.


Node *skipMdeleteN(Node *head, int M, int N)
{
    if(head==NULL)
        return head;
    if(M==0)
        return NULL;
    
	Node* temp=head;
    while(temp!=NULL)
    {
        Node* pre=NULL;
        int i=0;
        while(temp!=NULL and i<M)
        {
            pre=temp;
            temp=temp->next;
            i++;
        }
        int j=0;
        while(temp!=NULL and j<N)
        {
            Node* temp2=temp;
            pre->next=temp2->next;
            temp=temp->next;
            delete temp2;
            j++;
        }
    }
    return head;
}








---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
kReverse
________
Send Feedback
Given a singly linked list of integers, reverse the nodes of the linked list 'k' at a time and return its modified list.
 'k' is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of 'k,' 
then left-out nodes, in the end, should be reversed as well.
Example :
Given this linked list: 1 -> 2 -> 3 -> 4 -> 5

For k = 2, you should return: 2 -> 1 -> 4 -> 3 -> 5

For k = 3, you should return: 3 -> 2 -> 1 -> 5 -> 4



Node *kReverse(Node *head, int k)
{
	//Write your code here
    if(k==0 || k==1)
        return head;
    
    Node* current=head;
    Node* fwd=NULL;
    Node* prev=NULL;
    
    int count=0;
    while(count<k and current!=NULL)
    {
        fwd=current->next;
        current->next=prev;
        prev=current;
        current=fwd;
        count++;
    }
    if(fwd!=NULL)
        head->next=kReverse(fwd,k);
    return prev;
}








--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Bubble Sort (Iterative) LinkedList
__________________________________
Send Feedback
Given a singly linked list of integers, sort it using 'Bubble Sort.'
Note :
No need to print the list, it has already been taken care. Only return the new head to the list.


Node* bubbleSort(Node* head)
{
    //write your code here
    Node * i=head;
    
    while(i){
        Node *j=head;
        Node *prev=head;
        while(j->next){
            Node* temp=j->next;
            if(j->data>temp->data){
                if(j==head){
                    j->next=temp->next;
                    temp->next=j;
                    prev=temp;
                    head=prev;
                }
                else{
                    j->next=temp->next;
                    temp->next=j;
                    prev->next=temp;
                    prev=temp;
                }
                continue;
            }
            prev=j;
            j=j->next;
            
        }
        i=i->next;
    }
    return head;
}




--------------------------------------------------------END----------------------------------------------------------------------------------------------------------------------------------