
// The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

// Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

// Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.



// Example 1:


// Input: n = 4
// Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
// Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above
// Example 2:

// Input: n = 1
// Output: [["Q"]]


// Constraints:

// 1 <= n <= 9



class Solution {
public:


    bool isVaild(vector<pair<int , int>> &pos, int x , int y)
    {
        for (int i = 0; i < pos.size(); ++i)
        {
            auto p = pos[i];
            if (x == p.first || y == p.second || (y - p.second == x - p.first) || (y - p.second == p.first - x))
            {
                return 0;
            }
        }

        return 1;
    }
    void helper(vector<vector<string>> &ans,
                vector<string> &row,
                vector<pair<int , int>> &pos, int &n , int x)
    {
        if ( n == x)
        {
            ans.push_back(row);
            return;
        }

        for (int i = 0 ; i < n ; i++)
        {
            if (isVaild(pos , x, i))
            {

                pos.push_back(make_pair(x, i));
                string str = "";
                for (int j = 0 ; j < n ; j++)
                {

                    if (j == i) str += "Q";
                    else str += ".";
                }
                row.push_back(str);
                helper(ans , row , pos , n , x + 1);
                row.pop_back();
                pos.pop_back();
            }

        }


    }

    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> ans;
        vector<string> row;
        vector<pair<int , int>> pos;


        helper(ans , row , pos , n , 0);

        return ans;

    }
};





























