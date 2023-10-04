Maximum of minimum for every window size
HardAccuracy: 42.9%Submissions: 35K+Points: 8
The power of GeeksforGeeks now in your pockets! Download the App for Free

banner
Given an integer array. The task is to find the maximum of the minimum of every window size in the array.
Note: Window size varies from 1 to the size of the Array.

Example 1:

Input:
N = 7
arr[] = {10,20,30,50,10,70,30}
Output: 70 30 20 10 10 10 10 
Explanation: 
1.First element in output
indicates maximum of minimums of all
windows of size 1.
2.Minimums of windows of size 1 are {10},
 {20}, {30}, {50},{10}, {70} and {30}. 
 Maximum of these minimums is 70. 
3. Second element in output indicates
maximum of minimums of all windows of
size 2. 
4. Minimums of windows of size 2
are {10}, {20}, {30}, {10}, {10}, and
{30}.
5. Maximum of these minimums is 30 
Third element in output indicates
maximum of minimums of all windows of
size 3. 
6. Minimums of windows of size 3
are {10}, {20}, {10}, {10} and {10}.
7.Maximum of these minimums is 20. 
Similarly other elements of output are
computed.
Example 2:

Input:
N = 3
arr[] = {10,20,30}
Output: 30 20 10
Explanation: First element in output
indicates maximum of minimums of all
windows of size 1.Minimums of windows
of size 1 are {10} , {20} , {30}.
Maximum of these minimums are 30 and
similarly other outputs can be computed
Your Task:
The task is to complete the function maxOfMin() which takes the array arr[] and its size N as inputs and finds the maximum of minimum of every window size and returns an array containing the result. 

Expected Time Complxity : O(N)
Expected Auxilliary Space : O(N)

Constraints:
1 <= N <= 105
1 <= arr[i] <= 106


Expected Approach
Intuition
The idea is to use stack to find index of next smaller element in left and right for each element, then using it to find window size for each element in which it will be a minimum element, and ultimately use it to find maximum of minimum values for each window size.

Implementation
Declare an empty stack s, it will help in finding index of next smaller element in left and right for each element.
Declare two array left and right of size n+1, for storing index of next smaller element in left and right for each element respectively. 
Initialize all values of vector left with -1, and n for vector right.
Filling elements of left[] using logic discussed in next greater element problem.
Empty the stack s.
Filling elements of right[] using same logic.
Initializing ans array of size n+1 with all values as 0. ans[i] will keep track of maximum of minimum values in window of size i.
Filling answer list by comparing minimums of all lengths computed using left[] and right[].
Run a loop for i from 0 to n-1:
In each iteration for loop:
For ith element find length len for which it will be minimum element and take take max of ans[len] and a[i] and store the result in ans[len].
As we know: 
The result for length i, i.e. ans[i] would always be greater or same as result for length i+1, i.e., ans[i+1].
If ans[i] is not filled it means there is no direct element which is minimum of length i and therefore either the element of length ans[i+1], or ans[i+2], and so on is same as ans[i].
Run a loop for i from n-1 to 1, and in each iteration do ans[i] = max(ans[i], ans[i + 1]).
Store values in ans vector from index 1 to n, to res vector from index 0 to n-1.
Return res vector. 
Example:

Input: arr = {10, 20, 30, 50, 10, 70, 30} , n=7
        
        left = {-1,   0,   1,    2, -1,   4,   4}
        right = {7,    4,   4,    4,  7,   6,   7}
ans = {0, 70, 30, 20,  0,   0,    0, 10}, at the end of step7
ans = {0, 70, 30, 20, 10, 10, 10, 10} , at the end of step8
res = {70, 30, 20, 10, 10, 10, 10}.  
Complexity
Time Complexity: O(N), as every sub-task [next smaller element index in left and right, and forming ans vector] in this approach takes linear time.
Auxiliary Space: O(N), as array left, right, ans, and stack s having linear space complexity. 


class Solution
{
    public:
    //Function to find maximum of minimums of every window size.
    vector <int> maxOfMin(int arr[], int n)
    {
        //stack used to find previous and next smaller numbers.
        stack<int> s; 
    
        //using arrays to store previous and next smaller numbers.
        int left[n + 1];
        int right[n + 1];
    
        //initializing elements of left[] and right[].
        for (int i = 0; i < n; i++) {
            left[i] = -1;
            right[i] = n;
        }
    
        //filling elements of left[] using logic discussed in 
        //next greater element problem.
        for (int i = 0; i < n; i++)
        {
            while (!s.empty() && arr[s.top()] >= arr[i])
            s.pop();
            
            if (!s.empty()) 
            left[i] = s.top();
            s.push(i);
        }
    
        //emptying the stack as stack is going to be used for right[].
        while (!s.empty())
        s.pop();
    
        //filling elements of right[] using same logic.
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && arr[s.top()] >= arr[i])
            s.pop();
    
            if (!s.empty()) 
            right[i] = s.top();
            s.push(i);
        }
    
        //creating and initializing answer list.
        int ans[n + 1];
        for (int i = 0; i <= n; i++) ans[i] = 0;
    
        //filling answer list by comparing minimums of all
        //lengths computed using left[] and right[].
        for (int i = 0; i < n; i++) 
        {
            //length of the interval.
            int len = right[i] - left[i] - 1;
    
            //arr[i] is a possible answer for this length 'len' interval,
            //check if arr[i] is more than max for 'len'.
            ans[len] = max(ans[len], arr[i]);
        }
    
        //some entries in ans[] may not be filled yet. Filling
        //them by taking values from right side of ans[].
        for (int i = n - 1; i >= 1; i--) 
        ans[i] = max(ans[i], ans[i + 1]);
    
        vector <int> res (n);
        for (int i = 1; i <= n; i++) 
        res[i-1] = ans[i];
        
        //returning the answer list.
        return res;
    }
};
