Given an array arr[] of N elements. The task is to count maximum number of distinct smaller elements on right side of any array element. For example, in {10, 6, 9, 7, 20, 19, 21, 18, 17, 16}, the result is 4.  Note that 20 has maximum 4 smaller elements on right side. Other elements have less count, for example 10 has 3 smaller elements on right side.

Example:


Input:
4
10
10 6 9 7 20 19 21 18 17 16
5
5 4 3 2 1
5
1 2 3 4 5
5
1 2 3 2 1

Output:
4
4
0
2

Explanation:

Testcase 1: Number of smaller elements on right side of every element (from left to right)
 in the array are 3 0 1 0 4 3 3 2 1 and 0 respecitvely. Maximum of all these counts is 4.
Testcase 2: Number of smaller elements on right side of every element (from left to right) 
in the array are 4 3 2 1 and 0 respecitvely. Maximum of all these counts is 4.
Input:
The first line of input contains number of testcases T. For each testcase, first line of input contains number of elements in the array and next line contains array elements.

Output:
For each testcase, print the maximum count of smaller elements on right side.

Constraints:
1 <= T <= 100
1 <= N <= 105
1 <= arr[i] <= 106




#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) 
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
    
        set<int> temp;
        int ans = 0;
         for (int i = n - 1; i >= 0; i--) 
         {
            
                int d = (int)distance(temp.begin() , temp.lower_bound(arr[i]));
              //  cout << "d : " << d <<" " << i << " ";
                if(temp.count(arr[i]))
                {
                    ans = max(ans , d);
                }
                else
                {
                    ans = max(ans , d);
                }
            temp.insert(arr[i]);
            
           // cout << ans << " " ;
         }
        
        cout << ans << "\n";
    }
    return 0;
}
