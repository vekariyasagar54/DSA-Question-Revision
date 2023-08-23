// Given an m x n grid of characters board and a string word, return true if word exists in the grid.

// The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.



// Example 1:


// Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
// Output: true
// Example 2:


// Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
// Output: true
// Example 3:


// Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
// Output: false


// Constraints:

// m == board.length
// n = board[i].length
// 1 <= m, n <= 6
// 1 <= word.length <= 15
// board and word consists of only lowercase and uppercase English letters.


// Follow up: Could you use  to make your solution faster with a larger board?
















#include<bits/stdc++.h>
using namespace std;

bool searchNext(vector<vector<char>> &board, string word, int row, int col,
                int index, int m, int n) {

    // if index reaches at the end that means we have found the word
    if (index == word.length())
        return true;

    // Checking the boundaries if the character at which we are placed is not
    //the required character
    if (row < 0 || col < 0 || row == m || col == n || board[row][col] !=
            word[index] or board[row][col] == '!')
        return false;

    // this is to prevent reusing of the same character
    char c = board[row][col];
    board[row][col] = '!';

    // top direction
    bool top = searchNext(board, word, row - 1, col, index + 1, m, n);
    // right direction
    bool right = searchNext(board, word, row, col + 1, index + 1, m, n);
    // bottom direction
    bool bottom = searchNext(board, word, row + 1, col, index + 1, m, n);
    // left direction
    bool left = searchNext(board, word, row, col - 1, index + 1, m, n);

    board[row][col] = c; // undo change

    return top || right || bottom || left;
}
bool exist(vector<vector<char>> board, string word) {

    int m = board.size();
    int n = board[0].size();

    int index = 0;

    // First search the first character
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {

            if (board[i][j] == word[index]) {
                if (searchNext(board, word, i, j, index, m, n))
                    return true;
            }
        }
    }

    return false;
}


int main() {
    vector<vector<char>> board {{'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}};

    string word = "ABCCED";

    bool res = exist(board, word);
    if (res == 1)
        cout << "True" << endl;
    else
        cout << "False" << endl;
}