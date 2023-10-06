//{ Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}

Node* buildTree(int in[], int post[], int n);

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Node* root = buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends




/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

//Function to return a tree created from postorder and inoreder traversals.

int pre = 1;
Node *bt(int in[], int post[], int r , int l , int n)
{
    if(l > r)return NULL;
    
    
    Node* head = new Node(post[n - pre]);
    int key = post[n - pre];
    pre++;
    
    int ind;
    for(int i = l ; i <= r ; i++)
    {
        if(in[i] == key)
        {
            ind = i;
            break;
        }
    }
    
    head->right = bt(in , post , r , ind + 1 , n);
    head->left = bt(in , post , ind - 1 , l , n);
    
    return head;
}

Node *buildTree(int in[], int post[], int n) 
{
   pre = 1;
   return bt(in , post , n - 1 , 0 , n);
}
