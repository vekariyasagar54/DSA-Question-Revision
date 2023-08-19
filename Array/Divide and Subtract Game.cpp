// Jon and Arya are playing a game. Rules of game as follows:
//   They have a single number N initially.
//    Both will play an alternate move. Jon starts first.
//    Both will play each move optimally.
//    In each move, they can perform only one of these operation
//           1. Divide that number by 2, 3, 4 or 5 and take floor of result.
//           2. Subtract that number by 2, 3, 4 or 5.
//    If after making a move the number becomes 1, the player who made the move automatically loses the game.
//    When number becomes zero, the game will stop and the player who can't make a move loses the game.

 

// Example 1:

// Input:
// N = 3
// Output:
// Jon
// Explanation:
// Jon will just subtract 3 from initial
// number and win the game.
// Example 2:

// Input:
// N = 6
// Output:
// Arya
// Explanation:
// Jon will divide by 3 and then in next step
// Arya will subtract by 2 and win the game.
 

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function divAndSub() which takes an Integer N as input and returns a string denoting who won the game.

 

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(N)

 

// Constraints:
// 1 <= N <= 105


//SOLUTION


//User function Template for C++

class Solution {
  public:
string divAndSub(int N)
{
    // Edge Case
    if (N == 1)
        return "Arya";

    if (N < 6)
        return "Jon";

    // Make a dp array of size N+1
    int arr[N + 1];
    arr[0] = 0;

    // Initialize the variable
    int i = 1;

    // If it's whose turn it is to win on
    // that move, we'll do 1, otherwise 0

    // For 1-5 Jon always win
    while (i < 6 && i <= N) {
        arr[i] = 1;

        i++;
    }

    i = 6;

    while (i <= N) {

        // Whosever turn will it be we will
        // check if there is any move by
        // performing, there is a chance for
        // him to win, means if any
        // arr[condition] = 0 then he will win
        // for sure else not
        if (arr[i / 2] == 0 || arr[i / 4] == 0
            || arr[i / 3] == 0 || arr[i / 5] == 0) {

            // Means the person doing the move
            // can win through division
            arr[i] = 1;
            //cout<< i << "  " ;
        }

        else if (arr[i - 2] == 0 || arr[i - 3] == 0
                 || arr[i - 4] == 0 || arr[i - 5] == 0) {

            // Means the person doing the move
            // can win through subtraction
            arr[i] = 1;
            // cout<< i << "  " ;
        }

        else 
        {

            // Else other person will win
            arr[i] = 0;
            
        }

        i++;
    }

    // If arr[N] is 1 then Jon win
    // else Arya win
    return arr[N] == 1 ? "Jon" : "Arya";
}

};
