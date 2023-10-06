/* check child sum property */

Children Sum Parent
EasyAccuracy: 51.58%Submissions: 89K+Points: 2
The power of GeeksforGeeks now in your pockets! Download the App for Free

banner
Given a Binary Tree. Check whether all of its nodes have the value equal to the sum of their child nodes.


Example 1:

Input:
     10
    /
  10 
Output: 1
Explanation: Here, every node is sum of
its left and right child.
Example 2:

Input:
       1
     /   \
    4     3
   /  \
  5    N
Output: 0
Explanation: Here, 1 is the root node
and 4, 3 are its child nodes. 4 + 3 =
7 which is not equal to the value of
root node. Hence, this tree does not
satisfy the given conditions.

Your Task:
You don't need to read input or print anything. Your task is to complete the function isSumProperty() that takes the root Node of the Binary Tree as input and returns 1 if all the nodes in the tree satisfy the following properties. Else, it returns 0.
For every node, data value must be equal to the sum of data values in left and right children. Consider data value as 0 for NULL child.  Also, leaves are considered to follow the property.


Expected Time Complexiy: O(N).
Expected Auxiliary Space: O(Height of the Tree).

 

Constraints:
1 <= N <= 105
1 <= Data on nodes <= 105


  //solution

  //{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;


// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/*Complete the function below

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution{
    public:
    //Function to check whether all nodes of a tree have the value 
    //equal to the sum of their child nodes.
    int isSumProperty(Node *root)
    {
     // Add your code here
     if(root == NULL) return 1;
     if(root->left == NULL && root->right == NULL)return 1;
     
     int sum = 0;
     if(root->left) sum += root->left->data;
     if(root->right) sum += root->right->data;
     
     if(root->data == sum)
     {
        return isSumProperty(root->left) && isSumProperty(root->right);
        
     }
     else
     {
         return 0;
     }
    }
};


//{ Driver Code Starts.

/* Driver program to test size function*/

  

int main() {

   
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s, ch;
        getline(cin, s);
        
        Node* root = buildTree(s);
        Solution ob;
        cout << ob.isSumProperty(root) << endl;
    }
    return 0;
}

// } Driver Code Ends


/*  Mirror Tree */

Given a Binary Tree, convert it into its mirror.
MirrorTree1            

Example 1:

Input:
      1
    /  \
   2    3
Output: 3 1 2
Explanation: The tree is
   1    (mirror)  1
 /  \    =>      /  \
2    3          3    2
The inorder of mirror is 3 1 2
Example 2:

Input:
      10
     /  \
    20   30
   /  \
  40  60
Output: 30 10 60 20 40
Explanation: The tree is
      10               10
    /    \  (mirror) /    \
   20    30    =>   30    20
  /  \                   /   \
 40  60                 60   40
The inroder traversal of mirror is
30 10 60 20 40.
Your Task:
Just complete the function mirror() that takes node as paramter  and convert it into its mirror. The printing is done by the driver code only.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the Tree).

Constraints:
1 ≤ Number of nodes ≤ 105
1 ≤ Data of a node ≤ 105

//solution

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

/* Helper function to test mirror(). Given a binary
   search tree, print out its data elements in
   increasing sorted order.*/
void inOrder(struct Node *node) {
    if (node == NULL) return;

    inOrder(node->left);
    printf("%d ", node->data);

    inOrder(node->right);
}


// } Driver Code Ends
// function Template for C++

/* A binary tree node has data, pointer to left child
   and a pointer to right child /
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

class Solution {
  public:
    // Function to convert a binary tree into its mirror tree.
    void mirror(Node* node)
    {
       if(node == NULL) return;
       
       Node* temp = node->left;
       node->left = node->right;
       node->right = temp;
       mirror(node->left);
       mirror(node->right);
    }
};


//{ Driver Code Starts.

/* Driver program to test size function*/
int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string str;
        getline(cin, str);
        Node *root = buildTree(str);
        Solution ob;
        ob.mirror(root);
        inOrder(root);
        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends


/* check for balanced BT */

Check for Balanced Tree
EasyAccuracy: 43.15%Submissions: 245K+Points: 2
The power of GeeksforGeeks now in your pockets! Download the App for Free

banner
Given a binary tree, find if it is height balanced or not. 
A tree is height balanced if difference between heights of left and right subtrees is not more than one for all nodes of tree. 

A height balanced tree
        1
     /     \
   10      39
  /
5

An unbalanced tree
        1
     /    
   10   
  /
5

Example 1:

Input:
      1
    /
   2
    \
     3 
Output: 0
Explanation: The max difference in height
of left subtree and right subtree is 2,
which is greater than 1. Hence unbalanced
Example 2:

Input:
       10
     /   \
    20   30 
  /   \
 40   60
Output: 1
Explanation: The max difference in height
of left subtree and right subtree is 1.
Hence balanced. 
Your Task:
You don't need to take input. Just complete the function isBalanced() that takes root node as parameter and returns true, if the tree is balanced else returns false.

Constraints:
1 <= Number of nodes <= 105
1 <= Data of a node <= 109

Expected time complexity: O(N)
Expected auxiliary space: O(h) , where h = height of tree

//solution

//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;


// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/* A binary tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

class Solution{
    public:
    //Function to check whether a binary tree is balanced or not.
    int fun(Node *root)
    {
         if(root == NULL)return 0;
        
        int lh = fun(root->left);
        if(lh == -1)return -1;
        int rh = fun(root->right);
        if(rh == -1)return -1;
        
        if(abs(lh - rh) > 1) return -1;
        else return max(lh , rh) + 1 ;
    }
    
    bool isBalanced(Node *root)
    {
       if(fun(root) >= 0) return 1;
       else return 0;
    }
};



//{ Driver Code Starts.

/* Driver program to test size function*/

  

int main() {

   
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s, ch;
        getline(cin, s);
        
        Node* root = buildTree(s);
        Solution ob;
        cout << ob.isBalanced(root) << endl;
    }
    return 0;
}

// } Driver Code Ends


/* Check if subtree */

/*NOTE : here SubTree is always the Last part of the Main Tree it can't be intermediate part for eg., in following example Subtree can't be 
        1        
      /   \            
     2     3

=>> or in second example it can't be ,

     10   
   /    \       
  20    30

*/
Check if subtree
MediumAccuracy: 24.34%Submissions: 126K+Points: 4
The power of GeeksforGeeks now in your pockets! Download the App for Free

banner
Given two binary trees with head reference as T and S having at most N nodes. The task is to check if S is present as subtree in T.
A subtree of a tree T1 is a tree T2 consisting of a node in T1 and all of its descendants in T1.

Example 1:

Input:
T:      1          S:   3
      /   \            /
     2     3          4
   /  \    /
  N    N  4
Output: 1 
Explanation: S is present in T

Example 2:

Input:
T:      26         S:   26
       /   \           /  \
     10     N        10    N
   /    \           /  \
   20    30        20  30
  /  \            /  \
 40   60         40  60
Output: 1 
Explanation: 
S and T are both same. Hence, 
it can be said that S is a subtree 
of T.
Your Task:
You don't need to read input or print anything. Your task is to complete the function isSubtree() that takes root node of S and T as parameters and returns 1 if S is a subtree of T else 0.

Note: The nodes can have the duplicate values.


Expected Time Complexity: O(N^2).
Expected Auxiliary Space: O(N).

Constraints:
1 <= Number of nodes <= 103
1 <= Value of nodes <= 104

//solution

here two differnet solution possible
1) O(N^2) : by checking first and only possible height nodes in Main Tree , N : nodes in MainTree
2) O(N)  : cheking PreOrder 

1)

Intuition:
We can leverage the idea that inorder and preorder traversal identify a tree uniquely. The process is to store inorder and preorder traversal of both trees in separate arrays. Then for a given binary tree S to be a subset of T, the inorder traversal of S should be a subset of the inorder traversal of T. Also, the preorder traversal of S should be a subset of the preorder traversal of T.

NOTE: We can also perform postorder instead of the preorder traversal.

Implementation:
make a function to store inorder traversal on the tree in a list.
make a Function to store preorder traversal on the tree in a list
make a recursive function to check whether S is a subset of T or not.
Code:
// Class Solution that contains the implementation of the isSubTree function
class Solution {
    // A vector to store the nodes where the depth equals the required depth
    vector<Node*> nodes;
public:
    // Function to check if T is a sub-tree of S
    bool isSubTree(Node* S, Node* T) {
        // If both trees are empty, they are identical
        if (!S && !T) return true;
        // If one of the trees is empty while the other is not, they are not identical
        if (!S || !T) return false;
        // Get the depth of T and use it to find nodes in S with the same depth
        getDepth(S, getDepth(T, -1));
        // Check if any of the nodes in S matches T
        for (Node* n: nodes)
            if (identical(n, T))
                return true;
        // If no match is found, return false
        return false;
    }
    
    // Function to get the depth of a tree and find nodes with the same depth in S
    int getDepth(Node* r, int d) {
        // If root is empty, return -1
        if (!r)
            return -1;
        // Calculate the depth of the left and right subtrees
        int depth = max(getDepth(r->left, d), getDepth(r->right, d)) + 1;
        // Check if the calculated depth matches the required depth
        // Required depth is -1 for tree T (only return the depth, no push)
        if (depth == d)
            nodes.push_back(r);
        // Return the depth of the current subtree
        return depth;
    }
    
    // Function to check if two trees are identical
    bool identical(Node* a, Node* b) {
        // If both nodes are empty, they are identical
        if (!a && !b) return true;
        // If one of the nodes is empty while the other is not, they are not identical
        if (!a || !b || a->data != b->data) return false;
        // Recursively check if the left and right subtrees are identical
        return identical(a->left, b->left) && identical(a->right, b->right);
    }
};
Complexity:
Time Complexity: The time complexity of the above solution is O(n^2), where n is the total number of nodes in the binary tree. 
Space Complexity: The auxiliary space required by the program is O(n).


2)

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

class Solution
{
  public:

    void convertPreorder(Node* root, string& s)
    {    // if it reached null pointer
        if (root == nullptr)
            s += ",#"; //append
        else {
            s += "," + to_string(root->data);
            convertPreorder(root->left, s);
            convertPreorder(root->right, s);
        }
    }

     bool isSubTree(Node* root, Node* subRoot)
    {
        string tree1, tree2;
        convertPreorder(root, tree1);
        convertPreorder(subRoot, tree2);
       
        if (tree1.find(tree2) == string::npos)
            return false;
          
        return true;
    }


 

};


//{ Driver Code Starts.

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string strT, strS;
        getline(cin, strT);
        Node *rootT = buildTree(strT);
        getline(cin, strS);
        Solution obj;
        Node *rootS = buildTree(strS);
        cout << obj.isSubTree(rootT, rootS) << "\n";

    }
    return 0;
}
// } Driver Code Ends



/*Maximum Width of Tree*/

Maximum Width of Tree
EasyAccuracy: 63.27%Submissions: 69K+Points: 2
The power of GeeksforGeeks now in your pockets! Download the App for Free

banner
Given a Binary Tree, find the maximum width of it. Maximum width is defined as the maximum number of nodes at any level.
For example, the maximum width of the following tree is 4 as there are 4 nodes at the 3rd level.

          1
       /     \
     2        3
   /    \    /    \
  4    5   6    7
    \
      8

Example 1:

Input:
       1
     /    \
    2      3
Output: 2
On the first level there is only
one node 1
On the second level there are
two nodes 2, 3 clearly it is the 
maximum number of nodes at any level

Example 2:

Input:
        10
      /     \
    20      30
   /    \
  40    60
Output: 2
There is one node on level 1(10)
There is two node on level 2(20, 30)
There is two node on level 3(40, 60)
Hence the answer is 2

Your Task:
You don't have to read any input. Complete the function getMaxWidth() that takes the node as a parameter and returns the maximum width. The driver code does the printing.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Width of the tree).

Constraints:
1 <= Number of Nodes<= 105
0 <= nodes values <= 105

  //solution

  //{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/*  Structure of a Binary Tree

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

class Solution {
  public:
    // Function to get the maximum width of a binary tree.
    int getMaxWidth(Node* root) {

        if(root == NULL)return 0;
        
        queue<Node*> q;
        q.push(root);
        int ans = 1;
        
        while(!q.empty())
        {
            int n = q.size();
            ans = max(ans ,n);
            for(int i = 0 ; i < n ; i++)
            {
                Node* curr = q.front();
                q.pop();
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
        }
        
        return ans;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    getchar();
    while (t--) {
        string inp;
        getline(cin, inp);
        Node* root = buildTree(inp);

        Solution ob;
        cout << ob.getMaxWidth(root) << endl;
    }
    return 0;
}

// } Driver Code Ends


/*Foldable Binary Tree*/

MediumAccuracy: 60.54%Submissions: 39K+Points: 4
The power of GeeksforGeeks now in your pockets! Download the App for Free

banner
Given a binary tree, check if the tree can be folded or not. A tree can be folded if left and right subtrees of the tree are structure wise mirror image of each other. An empty tree is considered as foldable.
Consider the below trees:
(a) and (b) can be folded.
(c) and (d) cannot be folded.


(a)
       10
     /    \
    7      15
     \    /
      9  11
(b)
        10
       /  \
      7    15
     /      \
    9       11
(c)
        10
       /  \
      7   15
     /    /
    5   11
(d)
         10
       /   \
      7     15
    /  \    /
   9   10  12
 
Example 1:

Input:
     10
    /    \
   7     15
 /  \   /  \
N   9  11   N
Output:Yes
Explaination:Structure of every left and right subtree are same. 
Example 2:

Input:
      10
    /    \
   7     15
 /  \   /  \
5   N  11   N
Output: No
Explaination: 7's left child is not NULL and right child is NULL. That's why the tree is not foldable. 


Your Task:
The task is to complete the function isFoldable() that takes root of the tree as input and returns true or false depending upon whether the tree is foldable or not.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the Tree).

Constraints:
0 <= n <= 103
1 <= data of node <= 104


  //solution

  //{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/* A binary tree node has data, pointer to left child
and a pointer to right child */
/*struct node
{
    int data;
    struct node* left;
    struct node* right;
    
    node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

//Function to check whether a binary tree is foldable or not.
//Function that checks if trees with roots n1 and n2 are mirror of each other.
bool IsFoldableUtil(Node *n1, Node *n2) 
{
    //if both left and right subtrees are NULL then we return true.
    if (n1 == NULL && n2 == NULL) 
    {
        return true;
    }

    //if one of the trees is NULL and other is not then we return false.
    if (n1 == NULL || n2 == NULL) {
        return false;
    }

    //else we check recursively if left and right subtrees are 
    //mirrors of their counterparts.
    return IsFoldableUtil(n1->left,n2->right)&&IsFoldableUtil(n1->right,n2->left);
}

//Function to check whether a binary tree is foldable or not.
bool IsFoldable(Node *root) 
{
    if (root == NULL) 
    {
        return true;
    }
    return IsFoldableUtil(root->left, root->right);
}

//{ Driver Code Starts.

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);
        if (IsFoldable(root)) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }

    }


    return 0;
}
// } Driver Code Ends

