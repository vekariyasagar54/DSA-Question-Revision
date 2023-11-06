// go through this link : https://practice.geeksforgeeks.org/batch/dsa-4/track/DSASP-BST/article/NzYxMg%3D%3D (article)
// for the problem  :  https://practice.geeksforgeeks.org/batch/dsa-4/track/DSASP-BST/problem/fixed-two-nodes-of-a-bst
Fixing Two nodes of a BST
HardAccuracy: 53.68%Submissions: 40K+Points: 8
Hiring Challenge for Working Professionals on 10th November.
Apply to 6 Companies through 1 Contest! 

banner
You are given the root of a binary search tree(BST), where exactly two nodes were swapped by mistake. Fix (or correct) the BST by swapping them back. Do not change the structure of the tree.
Note: It is guaranteed that the given input will form BST, except for 2 nodes that will be wrong. All changes must be reflected in the original linked list.
 
Example 1:
Input:
       10
     /    \
    5      8
   / \
  2   20
Output: 1
Explanation:
 
Example 2:

Input:
         11
       /    \
      3      17
       \    /
        4  10
Output: 1 
Explanation: 
By swapping nodes 11 and 10, the BST 
can be fixed.

Your Task:
You don't need to take any input. Just complete the function correctBst() that takes root node as parameter. The function should not return anything, all the changes must be done in the existing tree only. BST will then be checked by driver code and 0 or 1 will be printed.


Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)


Constraints:
1 ≤ Number of nodes ≤ 103


  /*
struct Node
{
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
  
  void swap( int* a, int* b )
{
    int t = *a;
    *a = *b;
    *b = t;
}
    void correctBSTUtil(struct Node* root, struct Node** first,
                     struct Node** middle, struct Node** last,
                     struct Node** prev )
{
    if(root)
    {
        // Recur for the left subtree
        correctBSTUtil( root->left, first, middle, last, prev );

        // If this node is smaller than the previous node, it's violating
        // the BST rule.
        if (*prev && root->data < (*prev)->data)
        {
          
            // If this is first violation, mark these two nodes as
            // 'first' and 'middle'
            if ( !*first )
            {
                *first = *prev;
                *middle = root;
            }

            // If this is second violation, mark this node as last
            else
                *last = root;
        }

        // Mark this node as previous
        *prev = root;

        // Recur for the right subtree
        correctBSTUtil( root->right, first, middle, last, prev );
    }
}

// A function to fix a given BST where two nodes are swapped.  This
// function uses correctBSTUtil() to find out two nodes and swaps the
// nodes to fix the BST
void correctBST(struct Node* root)
{
  
    struct Node *first, *middle, *last, *prev;
    first = middle = last = prev = NULL;

    correctBSTUtil( root, &first, &middle, &last, &prev );

    if( first && last )
        swap( &(first->data), &(last->data) );
    else if( first && middle )
        swap( &(first->data), &(middle->data) );

    
}
};
