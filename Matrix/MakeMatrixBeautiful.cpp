// A beautiful matrix is a matrix in which the sum of elements in each row and column is equal. Given a square matrix of size NxN. 
// Find the minimum number of operation(s) that are required to make the matrix beautiful and also find updated matrix. In one operation you can increment the value of any one cell by 1.
// Example 1:

// Input:
// N = 2
// matrix[][] = {{1, 2},
//               {3, 4}}
// Output: 
// 4
// Explanation:
// Updated matrix:
// 4 3
// 3 4
// 1. Increment value of cell(0, 0) by 3
// 2. Increment value of cell(0, 1) by 1
// Hence total 4 operation are required.
// Example 2:

// Input:
// N = 3
// matrix[][] = {{1, 2, 3},
//               {4, 2, 3},
//               {3, 2, 1}}
// Output: 
// 6
// Explanation:
// Number of operations applied on each cell are as follows:
// 1 2 0
// 0 0 0
// 0 1 2
// Such that all rows and columns have sum of 9.
// Your Task: 
// You don't need to read input or print anything. Complete the function findMinOpeartion() that takes matrix and n as input parameters and returns the minimum number of operations.

// Expected Time Complexity: O(N * N)
// Expected Auxiliary Space: O(N)

// Constraints:
// 1 <= N <= 103
// 1 <= matrix[i][j] <= 106










// Implementation
// Initialize two arrays, sumRow and sumCol, both of size n, to store the sum of elements in each row and each column, respectively.
// Loop through each element in the matrix and calculate the sums of rows and columns by accumulating the element values.
// Find the maximum sum value among the sums of rows and columns. This value (maxSum) represents the target sum that we want to achieve for all rows and columns.
// Initialize a variable count to keep track of the number of operations required to equalize the sums and  two pointers, i and j, to keep track of the current row and column, respectively.
// Enter a loop that continues until both i and j are within the range [0, n):
// Find the minimum difference (diff) between maxSum and the sum of the current row i and the sum of the current column j. This represents the amount needed to increment the current element to achieve the target sum.
// Increment the current matrix element, update the sum of the current row, and update the sum of the current column by adding the calculated difference (diff).
// Increment the count by the calculated difference (diff).
// If the sum of the current row is now equal to maxSum, increment i to move to the next row.
// If the sum of the current column is now equal to maxSum, increment j to move to the next column.
// Return the final value of count
// Code
//Back-end complete function Template for C

int max(int x, int y)
{
    if(x > y)
        return x;
    return y;
}

int min(int x, int y)
{
    if(x < y)
        return x;
    return y;
}

//Function to find minimum number of operations that are required 
//to make the matrix beautiful.
int findMinOpeartion(int n, int matrix[][n])
{
    int sumRow[n];
    int sumCol[n];
    for(int i=0; i<n; i++)
        sumRow[i] = sumCol[i] = 0;
    
    //calculating sumRow[] and sumCol[] array.
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            sumRow[i] += matrix[i][j];
            sumCol[j] += matrix[i][j];
        }
    }
            
    //finding maximum sum value in either row or in column.
    int maxSum = 0;
    for (int i = 0; i < n; ++i)
    {
        maxSum = max(maxSum, sumRow[i]);
        maxSum = max(maxSum, sumCol[i]);
    }
    
    int count = 0;
    for (int i = 0, j = 0; i < n && j < n;) 
    {
        //finding minimum increment required in either row or column.
        int diff = min(maxSum - sumRow[i],  maxSum - sumCol[j]);
        
        //adding difference in corresponding cell, sumRow[] and sumCol[] array.
        matrix[i][j] += diff;
        sumRow[i] += diff;
        sumCol[j] += diff;
        
        //updating the result.
        count += diff;
        
        //if ith row is satisfied, incrementing i for next iteration.
        if (sumRow[i] == maxSum)
            ++i;
        
        //if jth column is satisfied, incrementing j for next iteration.
        if (sumCol[j] == maxSum)
            ++j;
    }
    //returning the result.
    return count;
    
} 
