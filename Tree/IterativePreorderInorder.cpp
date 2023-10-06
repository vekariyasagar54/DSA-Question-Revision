//for inorder iteratively.
// visit here  : https://www.geeksforgeeks.org/inorder-tree-traversal-without-recursion/


//for preorder\

Iterative Preorder Traversal

Given a Binary Tree, write an iterative function to print the Preorder traversal of the given binary tree.
To convert an inherently recursive procedure to iterative, we need an explicit stack. Following is a simple stack based iterative process to print Preorder traversal. 
1) Create an empty stack nodeStack and push root node to stack. 
2) Do the following while nodeStack is not empty. 
a) Pop an item from the stack and print it. 
b) Push right child of a popped item to stack 
c) Push left child of a popped item to stack
The right child is pushed before the left child to make sure that the left subtree is processed first.


 

// C++ program to implement iterative preorder traversal
#include <bits/stdc++.h>

using namespace std;

/* A binary tree node has data, left child and right child */
struct node {
    int data;
    struct node* left;
    struct node* right;
};

/* Helper function that allocates a new node with the given data and
   NULL left and right  pointers.*/
struct node* newNode(int data)
{
    struct node* node = new struct node;
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return (node);
}

// An iterative process to print preorder traversal of Binary tree
void iterativePreorder(node* root)
{
    // Base Case
    if (root == NULL)
        return;

    // Create an empty stack and push root to it
    stack<node*> nodeStack;
    nodeStack.push(root);

    /* Pop all items one by one. Do following for every popped item
       a) print it
       b) push its right child
       c) push its left child
    Note that right child is pushed first so that left is processed first */
    while (nodeStack.empty() == false) {
        // Pop the top item from stack and print it
        struct node* node = nodeStack.top();
        printf("%d ", node->data);
        nodeStack.pop();

        // Push right and left children of the popped node to stack
        if (node->right)
            nodeStack.push(node->right);
        if (node->left)
            nodeStack.push(node->left);
    }
}

// Driver program to test above functions
int main()
{
    /* Constructed binary tree is
            10
          /   \
        8      2
      /  \    /
    3     5  2
  */
    struct node* root = newNode(10);
    root->left = newNode(8);
    root->right = newNode(2);
    root->left->left = newNode(3);
    root->left->right = newNode(5);
    root->right->left = newNode(2);
    iterativePreorder(root);
    return 0;
}

 


Output: 
10 8 3 5 2 2

 

Time Complexity: O(N) 
Auxiliary Space: O(H), where H is the height of the tree.

 

Another Solution: In the previous solution we can see that the left child is popped as soon as it is pushed to the stack, therefore it is not required to push it into the stack. 



The idea is to start traversing the tree from the root node, and keep printing the left child while exists and simultaneously, push the right child of every node in an auxiliary stack. Once we reach a null node, pop a right child from the auxiliary stack and repeat the process while the auxiliary stack is not-empty. 


This is a micro-optimization over the previous approach, both the solutions use asymptotically similar auxiliary space.


Below is the implementation of the above approach: 
 

#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left, *right;

    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};

// Iterative function to do Preorder traversal of the tree
void preorderIterative(Node* root)
{
    if (root == NULL)
        return;

    stack<Node*> st;

    // start from root node (set current node to root node)
    Node* curr = root;

    // run till stack is not empty or current is
    // not NULL
    while (!st.empty() || curr != NULL) {
        // Print left children while exist
        // and keep pushing right into the
        // stack.
        while (curr != NULL) {
            cout << curr->data << " ";

            if (curr->right)
                st.push(curr->right);

            curr = curr->left;
        }

        // We reach when curr is NULL, so We
        // take out a right child from stack
        if (st.empty() == false) {
            curr = st.top();
            st.pop();
        }
    }
}

// Driver Code
int main()
{
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->left->left = new Node(70);
    root->left->right = new Node(50);
    root->right->left = new Node(60);
    root->left->left->right = new Node(80);

    preorderIterative(root);

    return 0;
}

 


Output: 
10 20 40 70 80 50 30 60

 
 

Time Complexity: O(N) 
Auxiliary Space: O(H), where H is the height of the tree.
