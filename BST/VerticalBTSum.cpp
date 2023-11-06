Vertical Traversal of Binary Tree
MediumAccuracy: 32.87%Submissions: 167K+Points: 4
Hiring Challenge for Working Professionals on 10th November.
Apply to 6 Companies through 1 Contest! 

banner
Given a Binary Tree, find the vertical traversal of it starting from the leftmost level to the rightmost level.
If there are multiple nodes passing through a vertical line, then they should be printed as they appear in level order traversal of the tree.

Example 1:

Input:
           1
         /   \
       2       3
     /   \   /   \
   4      5 6      7
              \      \
               8      9           
Output: 
4 2 1 5 6 3 8 7 9 
Explanation:

Example 2:

Input:
       1
    /    \
   2       3
 /    \      \
4      5      6
Output: 4 2 1 5 3 6
Your Task:
You don't need to read input or print anything. Your task is to complete the function verticalOrder() which takes the root node as input parameter and returns an array containing the vertical order traversal of the tree from the leftmost to the rightmost level. If 2 nodes lie in the same vertical level, they should be printed in the order they appear in the level order traversal of the tree.

Expected Time Complexity: O(N*log(N))
Expected Auxiliary Space: O(N)

Constraints:
1 <= Number of nodes <= 3*104

  class Solution
{
    public:
    //Function to find the vertical order traversal of Binary Tree.
    vector<int> verticalOrder(Node *root)
    {
        map<int , vector<int>> m;
        queue<pair<Node* , int>> q;
        pair<Node* , int> init = {root , 0};
        q.push(init);
       // m[0].push_back(root->data);
        while(q.empty() == false)
        {
            auto p = q.front();
            q.pop();
            int hd = p.second;
            int val = p.first->data;
            m[hd].push_back(val);
            if(p.first->left)
            {
                q.push({p.first->left , hd - 1});
            }
             if(p.first->right)
            {
                q.push({p.first->right , hd + 1});
            }
            
        }
        
        vector<int>ans;
        for(auto p : m)
        {
            vector<int> temp = p.second;
            for(auto x : temp)
            {
                ans.push_back(x);
            }
        }
        
        return ans;
    }
};
