Print Level Wise
________________
Send Feedback
Given a generic tree, print the input tree in level wise order.
For printing a node with data N, you need to follow the exact format -
N:x1,x2,x3,...,xn
where, N is data of any node present in the generic tree. x1, x2, x3, ...., xn are the children of node N. Note that there is no space in between.
You need to print all nodes in the level order form in different lines.


#include<queue>
void printLevelWise(TreeNode<int>* root) {
    
    queue<TreeNode<int>*> q;
    q.push(root);
    while(!q.empty())
    {
        TreeNode<int>* front=q.front();
        q.pop();
        cout<<front->data<<":";
        for(int i=0;i<front->children.size();i++)
        {
            if(i==front->children.size()-1)
            {
                cout<<front->children[i]->data;
                q.push(front->children[i]);
            }
            else
            {
                cout<<front->children[i]->data<<",";
                q.push(front->children[i]);
            }
            
        }
        cout<<endl;
    }
    
    
    
    
}








---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Code : Find sum of nodes
________________________
Send Feedback
Given a generic tree, find and return the sum of all nodes present in the given tree.
Input format :
The first line of input contains data of the nodes of the tree in level order form. The order is: data for root node, number of children to root
 node, data of each of child nodes and so on and so forth for each node. The data of the nodes of the tree is separated by space.   




int sumOfNodes(TreeNode<int>* root) {
    
   if(root==NULL)
       return 0;
    
    
   int sum=root->data;
    for(int i=0;i<root->children.size();i++)
    {
        sum+=sumOfNodes(root->children[i]);
    }
    return sum;
}










---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Code : Max data node
_____________________
Send Feedback
Given a generic tree, find and return the node with maximum data. You need to return the node which is having maximum data.
Return null if tree is empty.
Input format :
The first line of input contains data of the nodes of the tree in level order form. The order is: data for root node, number of children to root node, 
data of each of child nodes and so on and so forth for each node. The data of the nodes of the tree is separated by space.

#include<climits>
TreeNode<int>* maxDataNode(TreeNode<int>* root) {
    
    if(root==NULL)
        return NULL;
    
    int max=root->data;
    TreeNode<int>* node=root;
    
    for(int i=0;i<root->children.size();i++)
    {
        TreeNode<int>* temp=maxDataNode(root->children[i]);
        if(temp->data>max)
        {
            max=temp->data;
            node=temp;
        }
    }
    
    return node;
}





---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Code : Find height
__________________
Send Feedback
Given a generic tree, find and return the height of given tree.
Input Format:
The first line of input contains data of the nodes of the tree in level order form. The order is: data for root node, number of children to root node, 
data of each of child nodes and so on and so forth for each node. The data of the nodes of the tree is separated by space.  


#include<algorithm>
int getHeight(TreeNode<int>* root) 
{
    if(root==NULL)
        return 0;
    
    int max=0;
    for(int i=0;i<root->children.size();i++)
    {
        int a=getHeight(root->children[i]);
        max=std::max(a,max);
    }
    return max+1;
}







---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Code : Count leaf nodes
_______________________
Send Feedback
Given a generic tree, count and return the number of leaf nodes present in the given tree.
Input format :
The first line of input contains data of the nodes of the tree in level order form. The order is: data for root node, number of children to root node, 
data of each of child nodes and so on and so forth for each node. The data of the nodes of the tree is separated by space.  


int getLeafNodeCount(TreeNode<int>* root) 
{
    if(root==NULL)
        return 0;
    
    if(root->children.size()==0)
        return 1;
    
    int sum=0;
    for(int i=0;i<root->children.size();i++)
    {
        sum=sum+getLeafNodeCount(root->children[i]); 
    }
    return sum;
}








---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Code : PostOrder Traversal
__________________________
Send Feedback
Given a generic tree, print the post-order traversal of given tree.
The post-order traversal is: visit child nodes first and then root node.
Input format:
The first line of input contains data of the nodes of the tree in level order form. The order is: data for root node, number of children to root node, 
data of each of child nodes and so on and so forth for each node. The data of the nodes of the tree is separated by space.


#include<iostream>
using namespace std;

void printPostOrder(TreeNode<int>* root) 
{
    
    if(root==NULL)
        return ;
    
    for(int i=0;i<root->children.size();i++)
    {
        printPostOrder(root->children[i]);
    }
    cout<<root->data<<" ";
}







---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Contains x
_____________
Send Feedback
Given a generic tree and an integer x, check if x is present in the given tree or not. Return true if x is present, return false otherwise.
Input format :
The first line of input contains data of the nodes of the tree in level order form. The order is: data for root node, number of children to root node, 
data of each of child nodes and so on and so forth for each node. The data of the nodes of the tree is separated by space.  
The following line contains an integer, that denotes the value of x.


#include<queue>
bool isPresent(TreeNode<int>* root, int x) 
{
    if(root==NULL)
        return false;
    
    queue<TreeNode<int>*> q;
    q.push(root);
    if(root->data==x)
        return true;
    
    while(!q.empty())
    {
        TreeNode<int>* front=q.front();
        q.pop();
        //cout<<front->data<<":";
        for(int i=0;i<front->children.size();i++)
        {
            
               //cout<<front->children[i]->data;
                if(front->children[i]->data==x)
                    return true;
            
                q.push(front->children[i]);
            
        }
        
    }
    return false;
    
}





-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Count nodes
____________
Send Feedback
Given a tree and an integer x, find and return the number of nodes which contains data greater than x.
Input format:
The first line of input contains data of the nodes of the tree in level order form. The order is: data for root node, number of children to root node, 
data of each of child nodes and so on and so forth for each node. The data of the nodes of the tree is separated by space.  
The following line contains an integer, that denotes the value of x. 



int getLargeNodeCount(TreeNode<int>* root, int x) {
    
    if(root==NULL)
        return 0;
    
    int count=0;
    if(root->data>x)
        count=1;
    
    for(int i=0;i<root->children.size();i++)
    {
        count=count+getLargeNodeCount(root->children[i],x);
    }
    return count;
}





---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Node with maximum child sum
____________________________
Send Feedback
Given a generic tree, find and return the node for which sum of its data and data of all its child nodes is maximum. In the sum, 
data of the node and data of its immediate child nodes has to be taken.
Input format :
The first line of input contains data of the nodes of the tree in level order form. The order is: data for root node, number of children to root node, 
data of each of child nodes and so on and so forth for each node. The data of the nodes of the tree is separated by space. 

#include<climits>
#include<algorithm>
#include<queue>
TreeNode<int>* maxSumNode(TreeNode<int>* root) 
{
    if(root==NULL)
        return NULL;
    
    queue<TreeNode<int>*> q;
    q.push(root);
    
    int max=INT_MIN;
    TreeNode<int>* node=root;
    while(!q.empty())
    {
        TreeNode<int>* front=q.front();
        int sum=front->data;
        q.pop();
        for(int i=0;i<front->children.size();i++)
        {
            sum=sum+front->children[i]->data;
            q.push(front->children[i]);
        }
        if(sum>max)
        {
            max=sum;
            node=front;
        } 
        
        
    }
    return node;

}










-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Structurally identical
______________________
Send Feedback
Given two generic trees, return true if they are structurally identical. Otherwise return false.
Structural Identical
If the two given trees are made of nodes with the same values and the nodes are arranged in the same way, then the trees are called identical.  


#include<queue>
#include<vector>
vector<int> node(TreeNode<int>* root)
{
    vector<int> v;
    if(root==NULL)
        return v;
    
    queue<TreeNode<int>*> q;
    q.push(root);
    v.push_back(root->data);
    v.push_back(root->children.size());
    while(!q.empty())
    {
        TreeNode<int>* front=q.front();
        q.pop();
        for(int i=0;i<front->children.size();i++)
        {
            v.push_back(front->children[i]->data);
            q.push(front->children[i]);
        }
    }
    return v;
}
bool areIdentical(TreeNode<int> *root1, TreeNode<int> * root2) 
{
    vector<int> v1=node(root1);
    vector<int> v2=node(root2);
    for(int i=0;i<v1.size();i++)
    {
        if(v1[i]!=v2[i])
            return false;
    }
    return true;
}







------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Next larger
___________
Send Feedback
Given a generic tree and an integer n. Find and return the node with next larger element in the tree i.e. find a node with value just greater than n.
Note: Return NULL if no node is present with the value greater than n.
Input format :
The first line of input contains data of the nodes of the tree in level order form. The order is: data for root node, number of children to root node, 
data of each of child nodes and so on and so forth for each node. The data of the nodes of the tree is separated by space.  
The following line contains an integer, that denotes the value of n.


#include<climits>
TreeNode<int>* getNextLargerElement(TreeNode<int>* root, int x) 
{
    TreeNode<int>* ans=root;
    if(root->data>x)
        return ans;
    
   
    for(int i=0;i<root->children.size();i++)
    {
        TreeNode<int>* ans=getNextLargerElement(root->children[i],x);
        return ans;
    }
    return NULL;
}





---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Second Largest Element In Tree
______________________________
Send Feedback
Given a generic tree, find and return the node with second largest value in given tree.
Note: Return NULL if no node with required value is present.
Input format :
The first line of input contains data of the nodes of the tree in level order form. The order is: data for root node, number of children to root node, 
data of each of child nodes and so on and so forth for each node. The data of the nodes of the tree is separated by space.

#include<queue>
TreeNode<int>* getSecondLargestNode(TreeNode<int>* root){
    
    if(root->children.size()==0)
        return NULL;
    
    queue<TreeNode<int>*> q;
    int data=0;
    q.push(root);
    TreeNode<int>* f1=root	,*s1=NULL;
    while(!q.empty())
    {
        TreeNode<int>* front=q.front();
        q.pop();
        for(int i=0;i<front->children.size();i++)
        {
            q.push(front->children[i]);
        }
        
        if(front->data>data)
        {
            if(front->data>f1->data)
            {
                s1=f1;
                data=f1->data;
                f1=front;
            }
            else if(front->data<f1->data)
            {
                s1=front;
                data=s1->data;
            }
        }
    }
    return s1;
}




-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Replace with depth
_________________
Send Feedback
You are given a generic tree. You have to replace each node with its depth value. You just have to update the data of each node, there is no need to return or print anything.
Input format :
The first line of input contains data of the nodes of the tree in level order form. The order is: data for root node, number of children to root node, 
data of each of child nodes and so on and so forth for each node. The data of the nodes of the tree is separated by space. 

void replace(TreeNode<int>* root,int k)
{
    if(root==NULL)
        return ;
    
    root->data=k;
    for(int i=0;i<root->children.size();i++)
    {
        replace(root->children[i],k+1);
    }
}
void replaceWithDepthValue(TreeNode<int>* root) {
    
    replace(root,0);
    
}





---------------------------------------------------------------------------------END----------------------------------------------------------------------------------------------------------