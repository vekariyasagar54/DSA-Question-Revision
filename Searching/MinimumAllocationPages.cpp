// You have N books, each with Ai number of pages. M students need to be allocated contiguous books, with each student getting at least one book. Out of all the permutations, the goal is to find the permutation where the student with the most books allocated to him gets the minimum number of pages, out of all possible permutations.

// Note: Return -1 if a valid assignment is not possible, and allotment should be in contiguous order (see the explanation for better understanding).

 

// Example 1:

// Input:
// N = 4
// A[] = {12,34,67,90}
// M = 2
// Output:113
// Explanation:Allocation can be done in 
// following ways:
// {12} and {34, 67, 90} Maximum Pages = 191
// {12, 34} and {67, 90} Maximum Pages = 157
// {12, 34, 67} and {90} Maximum Pages =113.
// Therefore, the minimum of these cases is 113,
// which is selected as the output.

// Example 2:

// Input:
// N = 3
// A[] = {15,17,20}
// M = 2
// Output:32
// Explanation: Allocation is done as
// {15,17} and {20}
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function findPages() which takes 2 Integers N, and m and an array A[] of length N as input and returns the expected answer.


// Expected Time Complexity: O(NlogN)
// Expected Auxilliary Space: O(1)


// Constraints:
// 1 <= N <= 105
// 1 <= A [ i ] <= 106
// 1 <= M <= 105


//User function template in C++

class Solution 
{
    public:
   
   bool isPossible(int arr[], int n, int m, int curr_min)
{
	int studentsRequired = 1;
	int curr_sum = 0;

	// iterate over all books
	for (int i = 0; i < n; i++) {
		// check if current number of pages are greater
		// than curr_min that means we will get the result
		// after mid no. of pages
		if (arr[i] > curr_min)
			return false;

		// count how many students are required
		// to distribute curr_min pages
		if (curr_sum + arr[i] > curr_min) {
			// increment student count
			studentsRequired++;

			// update curr_sum
			curr_sum = arr[i];

			// if students required becomes greater
			// than given no. of students,return false
			if (studentsRequired > m)
				return false;
		}

		// else update curr_sum
		else
			curr_sum += arr[i];
	}
	return true;
}

// function to find minimum pages
int findPages(int arr[], int n, int m)
{
	long long sum = 0;

	// return -1 if no. of books is less than
	// no. of students
	if (n < m)
		return -1;

	// Count total number of pages
	for (int i = 0; i < n; i++)
		sum += arr[i];

	// initialize start as 0 pages and end as
	// total pages
	int start = 0, end = sum;
	int result = INT_MAX;

	// traverse until start <= end
	while (start <= end) {
		// check if it is possible to distribute
		// books by using mid as current minimum
		int mid = (start + end) / 2;
		if (isPossible(arr, n, m, mid)) {
			// update result to current distribution
			// as it's the best we have found till now.
			result = mid;

			// as we are finding minimum and books
			// are sorted so reduce end = mid -1
			// that means
			end = mid - 1;
		}

		else
			// if not possible means pages should be
			// increased so update start = mid + 1
			start = mid + 1;
	}

	// at-last return minimum no. of pages
	return result;
}
};
