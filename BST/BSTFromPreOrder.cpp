Preorder to PostOrder
MediumAccuracy: 59.2%Submissions: 54K+Points: 4
Hiring Challenge for Working Professionals on 10th November.
Apply to 6 Companies through 1 Contest! 

banner
Given an array arr[] of N nodes representing preorder traversal of some BST. You have to build the exact PostOrder from the given given preorder traversal. 
In Pre-Order traversal, the root node is visited before the left child and right child nodes.

Example 1:

Input:
N = 5
arr[]  = {40,30,35,80,100}
Output: 35 30 100 80 40
Explanation: PreOrder: 40 30 35 80 100
Therefore, the BST will be:
              40
           /      \
         30       80
           \        \   
           35      100
Hence, the postOrder traversal will
be: 35 30 100 80 40
Example 2:

Input:
N = 8
arr[]  = {40,30,32,35,80,90,100,120}
Output: 35 32 30 120 100 90 80 40
Your Task:
You need to complete the given function and return the root of the tree. The driver code will then use this root to print the post order traversal.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= N <= 103
1 <= arr[i] <= 104

//User function template in C++

/*

typedef struct Node
{
    int data;
    struct Node *left, *right;
} Node;


// A utility function to create a new tree node
Node* newNode( int data )
{
    Node* temp = (Node *)malloc( sizeof( Node ) );
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

*/

class Solution{
public:
    //Function that constructs BST from its preorder traversal.
    Node* fun(int pre[], int l , int h , int &i , int n)
    {
        if(i > n - 1)return NULL;
        
        Node* root = NULL;
        if(pre[i] < h && pre[i] > l)
        {
            root = newNode(pre[i]);
            i++;
        }
        else
        {
            return NULL;
        }
        
        root->left = fun(pre , l , root->data , i , n);
        
        root->right = fun(pre , root->data , h , i , n);
        
        
        return root;
    }
    Node* post_order(int pre[], int size)
    {
       int low  = INT_MIN , high = INT_MAX;
       int i = 0;
       Node* root = fun(pre , low , high , i , size);
       return root;
    }
};  
