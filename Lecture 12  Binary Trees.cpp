Print Level Wise
_________________
Send Feedback
For a given a Binary Tree of type integer, print the complete information of every node, when traversed in a level-order fashion.
To print the information of a node with data D, you need to follow the exact format :

           D:L:X,R:Y

Where D is the data of a node present in the binary tree. 
X and Y are the values of the left(L) and right(R) child of the node.
Print -1 if the child doesn't exist.



#include<queue>
void printLevelWise(BinaryTreeNode<int> *root) 
{
	if(root==NULL)
        return ;
    
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty())
    {
        BinaryTreeNode<int>* front=q.front();
        q.pop();
        cout<<front->data<<":";
        if(front->left==NULL)
        {
            cout<<"L:"<<"-1";
        }
        else
        {
            cout<<"L:"<<front->left->data;
            q.push(front->left);
        }
        
        
        if(front->right==NULL)
        {
            cout<<","<<"R:"<<"-1"<<endl;
        }
        else
        {
            cout<<","<<"R:"<<front->right->data<<endl;
            q.push(front->right);
        }
        
        
    }
}



--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Code : Find a node
__________________
Send Feedback
For a given Binary Tree of type integer and a number X, find whether a node exists in the tree with data X or not.
 Input Format:
The first line of each test case contains elements of the first tree in the level order form. The line consists of values of nodes separated by a single space. 
In case a node is null, we take -1 in its place.

The second line of each test case contains the node value you have to find.


For example, the input for the tree depicted in the below image would be:


bool isNodePresent(BinaryTreeNode<int> *root, int x) 
{
    if(root==NULL)
        return false;

    bool ans;
    if(root->data==x)
        return true;
    ans=isNodePresent(root->left,x);
    if(ans)
        return true;
    
    ans=isNodePresent(root->right,x);
    if(ans)
        return true;
    
    
    
    return false;
}






---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Code : Height of Binary Tree
____________________________
Send Feedback
For a given Binary Tree of integers, find and return the height of the tree.
Example:
                        10
                      /      \
                    20      30
                   /    \
                 40    50

Height of the given tree is 3. 

Height is defined as the total number of nodes along the longest path from the root to any of the leaf node.


int height(BinaryTreeNode<int>* root) 
{
    if(root==NULL)
        return 0;
    
    if(root->left==NULL and root->right==NULL)
    return 1;
    
    int h1=height(root->left);
    int h2=height(root->right);
    
    return std::max(h1,h2)+1;
    
}




--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Code : Mirror
_______________
Send Feedback
For a given Binary Tree of type integer, update it with its corresponding mirror image.
Example:
Alt text




void mirrorBinaryTree(BinaryTreeNode<int>* root) {
    // Write your code here
    if(root==NULL)
        return ;
    
    mirrorBinaryTree(root->left);
    mirrorBinaryTree(root->right);
    
    BinaryTreeNode<int>* temp=root->left;
    root->left=root->right;
    root->right=temp;
}






--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Preorder Binary Tree
_____________________
Send Feedback
You are given the root node of a binary tree.Print its preorder traversal.
Input Format:
The first and the only line of input will contain the node data, all separated by a single space. Since -1 is used as an indication whether the left or right node data exist for root, 
it will not be a part of the node data.

void preOrder(BinaryTreeNode<int> *root) 
{
	if(root==NULL)
        return ;
    
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
    
}


---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Postorder Binary Tree
Send Feedback
For a given Binary Tree of integers, print the post-order traversal.
Input Format:
The first and the only line of input will contain the node data, all separated by a single space. Since -1 is used as an indication whether the left or right node data exist for root, 
it will not be a part of the node data.


void postOrder(BinaryTreeNode<int> *root) 
{
	if(root==NULL)
        return ;
    
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}






--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


Code: Construct Tree from Preorder and Inorder
_______________________________________________
Send Feedback
For a given preorder and inorder traversal of a Binary Tree of type integer stored in an array/list, create the binary tree using the given two arrays/lists. 
You just need to construct the tree and return the root.
Note:
Assume that the Binary Tree contains only unique elements. 

BinaryTreeNode<int>* buildTreehelper(int* inorder,int* preorder,int ins,int ine,int pres,int pree)
{
    if(ins>ine)
        return NULL;
    
    int rootdata=preorder[pres];
    int rootindex=-1;
    for(int i=ins;i<=ine;i++)
    {
        if(inorder[i]==rootdata)
        {
            rootindex=i;
            break;
        }
    }
    int lins=ins;
    int line=rootindex-1;
    int lpres=pres+1;
    int lpree=line-lins+lpres;
    int rins=rootindex+1;
    int rine=ine;
    int rpres=lpree+1;
    int rpree=pree;
    
    BinaryTreeNode<int>* root=new BinaryTreeNode<int>(rootdata);
    root->left=buildTreehelper(inorder,preorder,lins,line,lpres,lpree);
    root->right=buildTreehelper(inorder,preorder,rins,rine,rpres,rpree);
    
    return root;
}
BinaryTreeNode<int>* buildTree(int *preorder, int preLength, int *inorder, int inLength) 
{
     int size=preLength;
    return buildTreehelper(inorder,preorder,0,size-1,0,size-1);
    
}





----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Construct Tree from Postorder and Inorder
_________________________________________
Send Feedback
For a given postorder and inorder traversal of a Binary Tree of type integer stored in an array/list, create the binary tree using the given two arrays/lists. 
You just need to construct the tree and return the root.
Note:
Assume that the Binary Tree contains only unique elements. 


BinaryTreeNode<int>* buildTreehelper(int* inorder,int* postorder,int ins,int ine,int posts,int poste)
{
    if(ins>ine)
        return NULL;
    
    int rootdata=postorder[poste];
    int rootindex=-1;
    for(int i=ins;i<=ine;i++)
    {
        if(inorder[i]==rootdata)
        {
            rootindex=i;
            break;
        }
    }
    int lins=ins;
    int line=rootindex-1;
    int lposts=posts;
    int lposte=line-lins+lposts;
    int rins=rootindex+1;
    int rine=ine;
    int rposts=lposte+1;
    int rposte=poste-1;
    
    BinaryTreeNode<int>* root=new BinaryTreeNode<int>(rootdata);
    root->left=buildTreehelper(inorder,postorder,lins,line,lposts,lposte);
    root->right=buildTreehelper(inorder,postorder,rins,rine,rposts,rposte);
    
    return root;
}
BinaryTreeNode<int>* buildTree(int *postorder, int postLength, int *inorder, int inLength) 
{
     int size=postLength;
    return buildTreehelper(inorder,postorder,0,size-1,0,size-1);
    
}






--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Min and Max of Binary Tree
_____________________________
Send Feedback
For a given a Binary Tree of type integer, find and return the minimum and the maximum data values.
Return the output as an object of Pair class, which is already created.
Note:
All the node data will be unique and hence there will always exist a minimum and maximum node data.




#include<climits>
pair<int, int> getMinAndMax(BinaryTreeNode<int> *root) 
{
	if(root==NULL)
    {
        pair<int,int> p;
        p.first=INT_MAX;
        p.second=INT_MIN;
        return p;
    }
    
    pair<int,int> leftpair=getMinAndMax(root->left);
    pair<int,int> rightpair=getMinAndMax(root->right);
    
    pair<int,int> ret;
    ret.first=min(min(leftpair.first,rightpair.first),root->data);
    ret.second=max(max(leftpair.second,rightpair.second),root->data);
    
    return ret;
}








--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Sum Of Nodes
_____________
Send Feedback
For a given Binary Tree of integers, find and return the sum of all the nodes data.
Example:
                        10
                      /      \
                    20      30
                   /    \
                 40    50

When we sum up all the nodes data together, [10, 20, 30, 40 50] we get 150. Hence, the output will be 150.




int getSum(BinaryTreeNode<int>* root) 
{
    if(root==NULL)
        return 0;
    
    return root->data+getSum(root->left)+getSum(root->right);
}




----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Check Balanced
______________
Send Feedback
Given a binary tree, check if it is balanced. Return true if given binary tree is balanced, false otherwise.
Balanced Binary Tree:
A empty binary tree or binary tree with zero nodes is always balanced. For a non empty binary tree to be balanced, following conditions must be met:
1. The left and right subtrees must be balanced.
2. |hL - hR| <= 1, where hL is the height or depth of left subtree and hR is the height or depth of right subtree.    




class pair1
{
    public:
    int height;
    bool is_blanced;
};

pair1 blanced(BinaryTreeNode<int> *root)
{
    if(root==NULL)
    {
        pair1 p;
        p.height=0;
        p.is_blanced=true;
        return p;
    }
    
    
    pair1 p1=blanced(root->left);
    pair1 p2=blanced(root->right);
    pair1 p3;
    p3.height=max(p1.height,p2.height)+1;
    if(abs(p1.height-p2.height)<=1 and p1.is_blanced and p2.is_blanced)
    {
        p3.is_blanced=true;
    }
    else
        p3.is_blanced=false;
    
    return p3;
}
    
    
    
bool isBalanced(BinaryTreeNode<int> *root) 
{
	return blanced(root).is_blanced;
}






--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Level order traversal
_____________________
Send Feedback
For a given a Binary Tree of type integer, print it in a level order fashion where each level will be printed on a new line. 
Elements on every level will be printed in a linear fashion and a single space will separate them.
Example:
alt txt

For the above-depicted tree, when printed in a level order fashion, the output would look like:

10
20 30 
40 50 60
Where each new line denotes the level in the tree.



void printLevelWise(BinaryTreeNode<int> *root) 
{
    if(root==NULL)
        return ;
    
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        
        BinaryTreeNode<int>* front=q.front();
        
        
        if(front==NULL)
        {
            cout<<endl;
            q.pop();
            if(!q.empty())
             q.push(NULL);
            
        }
        else
        {
            cout<<front->data<<" ";
            q.pop();
        if(front->left!=NULL)
            q.push(front->left);
        if(front->right!=NULL)
            q.push(front->right);
        }
        
        
    }
}






----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Remove Leaf nodes
__________________
Send Feedback
Given a binary tree, remove all leaf nodes from it. Leaf nodes are those nodes, which don't have any children.
Note:
1. Root will also be a leaf node if it doesn't have left and right child. 
2. You don't need to print the tree, just remove all leaf nodes and return the updated root.


BinaryTreeNode<int>* removeLeafNodes(BinaryTreeNode<int> *root) 
{
    if(root==NULL)
        return NULL;
    
    if(root->left==NULL and root->right==NULL)
    {
        //delete root;
        return NULL;
    }
    
    root->left=removeLeafNodes(root->left);
    root->right=removeLeafNodes(root->right);
    
    return root;
}





--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

ZigZag tree
______________
Send Feedback
Given a binary tree, print the zig zag order. In zigzag order, level 1 is printed from left to right, level 2 from right to left and so on. 
This means odd levels should get printed from left to right and even level right to left.
Input format:
The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. 
If any node does not have a left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, 
therefore, it will not be a part of the data of any node.




#include<vector>
#include<queue>

void zigZagOrder(BinaryTreeNode<int> *root) 
{
    if(root==NULL)
        return ;
    
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    bool flag=true;
    while(!q.empty())
    {
        int size=q.size();
        vector<int> row(size);
        
        for(int i=0;i<size;i++)
        {
            BinaryTreeNode<int>* front=q.front();
            q.pop();
            
            //find the position
            int index=(flag)?i:(size-1-i);
            row[index]=front->data;
            if(front->left)
                q.push(front->left);
            if(front->right)
                q.push(front->right);
        }
        flag=!flag;
        for(int i=0;i<row.size();i++)
        {
            cout<<row[i]<<" ";
        }
        cout<<endl;
    }
}






--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Nodes without sibling
____________________
Send Feedback
For a given Binary Tree of type integer, print all the nodes without any siblings.
Input Format:
The first and the only line of input will contain the node data, all separated by a single space. Since -1 is used as an indication whether the left or right node data exist for root, 
it will not be a part of the node data.




void printNodesWithoutSibling(BinaryTreeNode<int> *root) 
{
    if(root==NULL)
        return ;
    
    if(root->left==NULL and root->right!=NULL)
    {
        cout<<root->right->data<<" ";
        //printNodesWithoutSibling(root->right);
    }
    if(root->left!=NULL and root->right==NULL)
    {
        cout<<root->left->data<<" ";
        //printNodesWithoutSibling(root->left);
    }
    printNodesWithoutSibling(root->left);
    printNodesWithoutSibling(root->right);
    
}






----------------------------------------------------------------------------------------------END--------------------------------------------------------------------------------------------


