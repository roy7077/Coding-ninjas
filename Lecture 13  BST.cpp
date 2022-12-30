Code: Search in BST
___________________
Send Feedback
Given a BST and an integer k. Find if the integer k is present in given BST or not. You have to return true, if node with data k is present, return false otherwise.
Note: Assume that BST contains all unique elements.

bool searchInBST(BinaryTreeNode<int> *root , int k) 
{
	if(root==NULL)
        return false;
    
    if(root->data==k)
        return true;
    
    if(k>root->data)
        return searchInBST(root->right,k);
    
    if(k<root->data)
        return searchInBST(root->left,k);
}




--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


Code: Print Elements in Range
_____________________________
Send Feedback
Given a Binary Search Tree and two integers k1 and k2, find and print the elements which are in range k1 and k2 (both inclusive).
Print the elements in increasing order.



void elementsInRangeK1K2(BinaryTreeNode<int>* root, int k1, int k2) 
{
    
   
	if(root==NULL)
        return ;
    
    if(root->data>=k1 and root->data<=k2)
    {
        elementsInRangeK1K2(root->left,k1,k2);
        cout<<root->data<<" ";
        elementsInRangeK1K2(root->right,k1,k2);
    }
    else if(root->data<k1)
        elementsInRangeK1K2(root->right,k1,k2);
    else if(root->data>k2)
        elementsInRangeK1K2(root->left,k1,k2);
        
}






--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Check if a Binary Tree is BST
_____________________________
Send Feedback
Given a binary tree with N number of nodes, check if that input tree is BST (Binary Search Tree). If yes, return true, return false otherwise.
Note: Duplicate elements should be kept in the right subtree.





#include<climits>
bool check_bst(BinaryTreeNode<int>* root,int min=INT_MIN,int max=INT_MAX)
{
    if(root==NULL)
        return true;
    
    if(root->data<min || root->data>max)
        return false;
    
    bool i=check_bst(root->left,min,root->data-1);
    bool j=check_bst(root->right,root->data,max);
    return i and j;
}
bool isBST(BinaryTreeNode<int> *root) 
{
	return check_bst(root);
}







---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


Code: Construct BST from a Sorted Array
_______________________________________
Send Feedback
Given a sorted integer array A of size n, which contains all unique elements. You need to construct a balanced BST from this input array. Return the root of constructed BST.
Note: If array size is even, take first mid as root.




BinaryTreeNode<int>* constructTree_helper(int *input, int s,int e) 
{
	if(s>e)
    return NULL;
    
    int mid=(s+e)/2;
    BinaryTreeNode<int>* root=new BinaryTreeNode<int>(input[mid]);
    root->left=constructTree_helper(input,s,mid-1);
    root->right=constructTree_helper(input,mid+1,e);
    return root;   
}
BinaryTreeNode<int>* constructTree(int *input, int n) 
{
	return constructTree_helper(input,0,n-1);
}





--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------




Find Path in BST
________________
Send Feedback
Given a BST and an integer k. Find and return the path from the node with data k and root (if a node with data k is present in given BST) in a list. Return empty list otherwise.
Note: Assume that BST contains all unique elements.








vector<int>* getPath(BinaryTreeNode<int> *root , int data) 
{
	if(root==NULL)
        return NULL;
    
    if(root->data==data)
    {
        vector<int>* v=new vector<int>;
        v->push_back(root->data);
        return v;
    }
    
    vector<int>* v1=getPath(root->left,data);
    if(v1!=NULL)
    {
        v1->push_back(root->data);
        return v1;
    }
    
    vector<int>* v2=getPath(root->right,data);
    if(v2!=NULL)
    {
        v2->push_back(root->data);
        return v2;
    }
    
    return NULL;
}







--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------



Code: BST Class
______________
Send Feedback
Implement the BST class which includes following functions -
1. insert -
Given an element, insert that element in the BST at the correct position. If element is equal to the data of the node, insert it in the left subtree.
2. search
Given an element, find if that is present in BST or not. Return true or false.
3. delete -
Given an element, remove that element from the BST. If the element which is to be deleted has both children, replace that with the minimum element from right sub-tree.
4. printTree (recursive) -
Print the BST in in the following format -
For printing a node with data N, you need to follow the exact format -
N:L:x,R:y
where, N is data of any node present in the binary tree. x and y are the values of left and right child of node N. Print the children only if it is not null.
There is no space in between.
You need to print all nodes in the recursive format in different lines.




class BST {
	// Complete this class
    public:
    BinaryTreeNode<int>* root;
    
    private:
    bool search(int key,BinaryTreeNode<int>* node){
        if(node==NULL)
            return false;
        if(node->data==key)
            return true;
        
        bool ans;
        if(key<node->data)
            ans=search(key,node->left);
        else
            ans=search(key,node->right);
        
        return ans;
    }
    
    BinaryTreeNode<int>* ins(int key,BinaryTreeNode<int>* node){
        
        if(node==NULL){
            BinaryTreeNode<int>* inode=new BinaryTreeNode<int>(key);
            return inode;
        }
        if(key>node->data)
            node->right=ins(key,node->right);
        else
            node->left=ins(key,node->left);
        
        return node;
    }
    
    BinaryTreeNode<int>* findMin(BinaryTreeNode<int>* node){
        if(node->left==NULL)
            return node; 
        return findMin(node->left);
    }
    
    BinaryTreeNode<int>* del(int key,BinaryTreeNode<int>* node){
        
        if(node==NULL)
            return NULL;
        
        if (key>node->data)
            node->right=del(key,node->right);
        else if(key<node->data)
            node->left=del(key,node->left);
        else{
            //If node is leaf
            if(node->left==NULL && node->right==NULL){
                delete node;
                return NULL;
            }
            else if(node->left==NULL){
                BinaryTreeNode<int>* temp=node->right;
                node->right=NULL;
                delete node;
                return temp;
            }
            else if(node->right==NULL){
                BinaryTreeNode<int>* temp=node->left;
                node->left=NULL;
                delete node;
                return temp;
            }
            else{
                BinaryTreeNode<int>* minnode=findMin(node->right);
                
                node->data=minnode->data;
                node->right=del(minnode->data,node->right);
                return node;
                
            }   
        }
        
        return node;
    }
    void pr(BinaryTreeNode<int>* node){
        if(node==NULL)
            return;
        
        cout<<node->data<<":";
        
        if(node->left!=NULL)
            cout<<"L:"<<node->left->data<<",";
        if(node->right!=NULL)
            cout<<"R:"<<node->right->data;
        cout<<endl;
        
        pr(node->left);
        pr(node->right);
    }
    public:
    bool search(int key){
        return search(key,root);
    }
    
    void insert(int key){
        this->root=ins(key,this->root);
    }
    void remove(int key){
        this->root=del(key,this->root);
    }
    void print(){
        pr(root);
    }
};






------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------



Create & Insert Duplicate Node
______________________________
Send Feedback
For a given a Binary Tree of type integer, duplicate every node of the tree and attach it to the left of itself.
The root will remain the same. So you just need to insert nodes in the given Binary Tree.
Example:
alt txt

After making the changes to the above-depicted tree, the updated tree will look like this.
alt txt

You can see that every node in the input tree has been duplicated and inserted to the left of itself.





void insertDuplicateNode(BinaryTreeNode<int> *root) {
    
    if(root==NULL)
        return ;
    
    insertDuplicateNode(root->left);
    insertDuplicateNode(root->right);
    
    BinaryTreeNode<int>* temp=root->left;
    BinaryTreeNode<int>* newnode=new BinaryTreeNode<int>(root->data);
    
    root->left=newnode;
    newnode->left=temp;
}





---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


Pair Sum Binary Tree
____________________
Send Feedback
Given a binary tree and an integer S, print all the pair of nodes whose sum equals S.
Note:
1. Assume the given binary tree contains all unique elements.
2. In a pair, print the smaller element first. Order of different pairs doesn't matter.



#include<algorithm>
void convert_to_array(BinaryTreeNode<int>* root,vector<int> &output)
{
    if(root==NULL)
        return ;
    
    output.push_back(root->data);
    convert_to_array(root->left,output);
    convert_to_array(root->right,output);
    
}
void pairSum(BinaryTreeNode<int> *root, int sum) {
    
    vector<int> output;
    convert_to_array(root,output);
    
    sort(output.begin(),output.end());
    int i=0;
    int j=output.size()-1;
    while(i<j)
    {
        if(output[i]+output[j]<sum)
            i++;
        else if(output[i]+output[j]>sum)
            j--;
        else
        {
            cout<<output[i]<<" "<<output[j]<<endl;
            i++;
            j--;
        }
    }
}





------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


LCA of Binary Tree
__________________
Send Feedback
Given a binary tree and data of two nodes, find 'LCA' (Lowest Common Ancestor) of the given two nodes in the binary tree.
LCA
LCA of two nodes A and B is the lowest or deepest node which has both A and B as its descendants. 
Example:
In this example, the green coloured node is the LCA to A and B.


pair<BinaryTreeNode <int>*,int> getLCA_helper(BinaryTreeNode<int>* root,int a,int b)
{
    if(root==NULL)
    {
        pair<BinaryTreeNode<int>*,int> p;
        p.first=NULL;
        p.second=-1;
        return p;
    }
    
    if(root->data==a or root->data==b)
    {
        pair<BinaryTreeNode<int>*,int> p;
        p.first=root;
        p.second=root->data;
        return p;
    }
    
    pair<BinaryTreeNode<int>*,int> p1=getLCA_helper(root->left,a,b);
    pair<BinaryTreeNode<int>*,int> p2=getLCA_helper(root->right,a,b);
    
    pair<BinaryTreeNode<int>*,int> p3;
    if(p1.first!=NULL and p2.first!=NULL)
    {
        p3.first=root;
        p3.second=root->data;
        return p3;
    }
    if(p1.first!=NULL)
    return p1;
    
    return p2;
    
}
int getLCA(BinaryTreeNode <int>* root , int a, int b) {
    
    pair<BinaryTreeNode<int>*,int> p=getLCA_helper(root,a,b);
    return p.second;
}






--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


LCA of BST
_____________
Send Feedback
Given a binary search tree and data of two nodes, find 'LCA' (Lowest Common Ancestor) of the given two nodes in the BST.
LCA
LCA of two nodes A and B is the lowest or deepest node which has both A and B as its descendants. 
Example:
In this example, the green coloured node is the LCA to A and B.
Alt Text

Note:
It is defined that each node is a descendant to itself, so, if there are two nodes X and Y and X has a direct connection from Y, then Y is the lowest common ancestor.




pair<BinaryTreeNode <int>*,int> getLCA_helper(BinaryTreeNode<int>* root,int a,int b)
{
    if(root==NULL)
    {
        pair<BinaryTreeNode<int>*,int> p;
        p.first=NULL;
        p.second=-1;
        return p;
    }
    
    if(root->data==a or root->data==b)
    {
        pair<BinaryTreeNode<int>*,int> p;
        p.first=root;
        p.second=root->data;
        return p;
    }
    
    pair<BinaryTreeNode<int>*,int> p1=getLCA_helper(root->left,a,b);
    pair<BinaryTreeNode<int>*,int> p2=getLCA_helper(root->right,a,b);
    
    pair<BinaryTreeNode<int>*,int> p3;
    if(p1.first!=NULL and p2.first!=NULL)
    {
        p3.first=root;
        p3.second=root->data;
        return p3;
    }
    if(p1.first!=NULL)
    return p1;
    
    return p2;
    
}
int getLCA(BinaryTreeNode<int>* root , int val1 , int val2){
    
    return getLCA_helper(root,val1,val2).second;
}






--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------



Largest BST
___________
Send Feedback
Given a Binary tree, find the largest BST subtree. That is, you need to find the BST with maximum height in the given binary tree. You have to return the height of largest BST.



#include<climits>
#include<algorithm>
#include<cmath>
int height(BinaryTreeNode<int>* root)
{
    if(root==NULL)
        return 0;
    
    int h1=height(root->left);
    int h2=height(root->right);
    
    if(h1>h2)
        return h1+1;
    else
        return h2+1;
}
bool check_bst(BinaryTreeNode<int>* root,int min=INT_MIN,int max=INT_MAX)
{
    if(root==NULL)
        return true;
    
    if(root->data<min || root->data>max)
        return false;
    
    bool i=check_bst(root->left,min,root->data-1);
    bool j=check_bst(root->right,root->data,max);
    return i and j;
}

int largestBSTSubtree(BinaryTreeNode<int> *root) {
    
    if(check_bst(root))
    {
        return height(root);
    }
    else
    {
        int ans1=largestBSTSubtree(root->left);
        int ans2=largestBSTSubtree(root->right);
        return max(ans1,ans2);
        
    }
}







-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------




Replace with Sum of greater nodes
__________________________________
Send Feedback
Given a binary search tree, you have to replace each node's data with the sum of all nodes which are greater or equal than it. You need to include the current node's data also.
That is, if in given BST there is a node with data 5, you need to replace it with sum of its data (i.e. 5) and all nodes whose data is greater than or equal to 5.
Note: You don't need to return or print, just change the data of each node.




int replaceWithLargerNodesSum_helper(BinaryTreeNode<int>* root,int sum)
{
    if(root==NULL)
        return sum;
    
    sum=replaceWithLargerNodesSum_helper(root->right,sum);
    sum+=root->data;
    root->data=sum;
    sum=replaceWithLargerNodesSum_helper(root->left,sum);

    return sum;
}
void replaceWithLargerNodesSum(BinaryTreeNode<int> *root) {
    int sum=0;
    replaceWithLargerNodesSum_helper(root,sum);
}






-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------



Path Sum Root to Leaf
____________________
Send Feedback
For a given Binary Tree of type integer and a number K, print out all root-to-leaf paths where the sum of all the node data along the path is equal to K.
Example:
alt txt

If you see in the above-depicted picture of Binary Tree, we see that there are a total of two paths, starting from the root and ending at the leaves which sum up to a value of K = 13.

The paths are:
a. 2 3 4 4
b. 2 3 8

One thing to note here is, there is another path in the right sub-tree in reference to the root, which sums up to 13 but since it doesn't end at the leaf, we discard it.
The path is: 2 9 2(not a leaf)



void helper(BinaryTreeNode<int>* root,int k,vector<int> v)
{
    if(root==NULL)
        return ;
    
    if(root->left==NULL and root->right==NULL)
    {
        if(k-root->data==0)
        {
           int i=0;
            while(i<v.size())
            {
                cout<<v.at(i)<<" ";
                i++;
            }
            cout<<root->data<<endl;
        }
        return ;
    }
    
    v.push_back(root->data);
    helper(root->left,k-root->data,v);  
    helper(root->right,k-root->data,v);
}
void rootToLeafPathsSumToK(BinaryTreeNode<int> *root, int k) {
    vector<int> v;
    helper(root,k,v);
}






--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------



Print nodes at distance k from node
____________________________________
Send Feedback
You are given a Binary Tree of type integer, a target node, and an integer value K.
Print the data of all nodes that have a distance K from the target node. The order in which they would be printed will not matter.
Example:
For a given input tree(refer to the image below):
1. Target Node: 5
2. K = 2
alt txt

Starting from the target node 5, the nodes at distance K are 7 4 and 1.




void print_helper(BinaryTreeNode<int> *root, int k)
{
    if(root==NULL or k<0)
        return ;
    
    if(k==0)
    {
        cout<<root->data<<endl;
        return ;
    }
    print_helper(root->left,k-1);
    print_helper(root->right,k-1);
}
int nodesAtDistanceK_helper(BinaryTreeNode<int> *root, int node, int k)
{
    if(root==NULL)
    {
        return -1;
    }
    if(root->data==node)
    {
        print_helper(root,k);
        return 0;
    }
    
    int DL=nodesAtDistanceK_helper(root->left,node,k);
    if(DL!=-1)
    {
        if(DL+1==k)
            cout<<root->data<<endl;
        else
            print_helper(root->right,k-2-DL);
        return DL+1;
    }
    int DR=nodesAtDistanceK_helper(root->right,node,k);
    if(DR!=-1)
    {
        if(DR+1==k)
            cout<<root->data<<endl;
        else
            print_helper(root->left,k-2-DR);
        return DR+1;
    }
    
     return -1;   
}
void nodesAtDistanceK(BinaryTreeNode<int> *root, int node, int k) {
    nodesAtDistanceK_helper(root,node,k);
}





-------------------------------------------------------------------END--------------------------------------------------------------------------------------------------------------------S