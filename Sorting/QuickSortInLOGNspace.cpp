// We can optimize the above code to make a recursive call only for the smaller part after partition. Below is implementation of this idea.

// Further Optimization :  


// C++ program of the above approach
#include <bits/stdc++.h>
using namespace std;
 
void quickSort(int arr[], int low, int high)
{
  while (low < high)
  {
    /* pi is partitioning index, arr[p] is now
           at right place */
    int pi = partition(arr, low, high);
 
    // If left part is smaller, then recur for left
    // part and handle right part iteratively
    if (pi - low < high - pi)
    {
      quickSort(arr, low, pi - 1);
      low = pi + 1;
    }
 
    // Else recur for right part
    else
    {
      quickSort(arr, pi + 1, high);
      high = pi - 1;
    }
  }
}
 
// This code is contributed by code_hunt.
// In the above code, if left part becomes smaller, then we make recursive call for left part. Else for the right part. In worst case (for space), when both parts are of equal sizes in all recursive calls, we use O(Log n) extra space. 

// Reference: 
// http://www.cs.nthu.edu.tw/~wkhon/algo08-tutorials/tutorial2b.pdf

// This article is contributed by Dheeraj Jain. Please write comments if you find anything incorrect, or you want to share more information about the topic discussed above
