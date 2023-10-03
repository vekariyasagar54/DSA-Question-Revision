// Previous Greater Element

// Given an array of distinct elements, find previous greater element for every element. If previous greater element does not exist, print -1.

// Examples: 

// Input : arr[] = {10, 4, 2, 20, 40, 12, 30}
// Output :         -1, 10, 4, -1, -1, 40, 40

// Input : arr[] = {10, 20, 30, 40}
// Output :        -1, -1, -1, -1

// Input : arr[] = {40, 30, 20, 10}
// Output :        -1, 40, 30, 20
// Expected time complexity : O(n)

// An efficient solution is to use stack data structure. If we take a closer look, we can notice that this problem is a variation of stock span problem. We maintain previous greater element in a stack.


// C++ program previous greater element
// An efficient solution to print previous greater
// element for every element in an array.
#include <bits/stdc++.h>
using namespace std;

void prevGreater(int arr[], int n)
{
    // Create a stack and push index of first element 
    // to it
    stack<int> s;
    s.push(arr[0]);
    
    // Previous greater for first element is always -1.
    cout << "-1, ";

    // Traverse remaining elements
    for (int i = 1; i < n; i++) {

        // Pop elements from stack while stack is not empty 
        // and top of stack is smaller than arr[i]. We 
        // always have elements in decreasing order in a 
        // stack.
        while (s.empty() == false && s.top() < arr[i])
            s.pop();

        // If stack becomes empty, then no element is greater
        // on left side. Else top of stack is previous
        // greater.
        s.empty() ? cout << "-1, " : cout << s.top() << ", ";

        s.push(arr[i]);
    }
}
// Driver code
int main()
{
    int arr[] = { 10, 4, 2, 20, 40, 12, 30 };
    int n = sizeof(arr) / sizeof(arr[0]);
    prevGreater(arr, n);
    return 0;
}


// Output
// -1, 10, 4, -1, -1, 40, 40, 
// Complexity Analysis:

// Time Complexity: O(n). It seems more than O(n) at first look. If we take a closer look, we can observe that every element of array is added and removed from stack at most once. So there are total 2n operations at most. Assuming that a stack operation takes O(1) time, we can say that the time complexity is O(n).
// Auxiliary Space: O(n) in worst case when all elements are sorted in decreasing order.



Next Greater Element

Given an array, print the Next Greater Element (NGE) for every element. 

The Next greater Element for an element x is the first greater element on the right side of x in the array. Elements for which no greater element exist, consider the next greater element as -1. 

Example: 

Input: arr[] = [ 4 , 5 , 2 , 25 ]
Output:  4      -->   5
               5      -->   25
               2      -->   25
              25     -->   -1
Explanation: except 25 every element has an element greater than them present on the right side

Input: arr[] = [ 13 , 7, 6 , 12 ]
Output:  13      -->    -1
                7       -->     12
                6       -->     12
               12      -->     -1
Explanation: 13 and 12 don't have any element greater than them present on the right side


Find Next Greater Element using Stack:
The idea is to store the elements for which we have to find the next greater element in a stack and while traversing the array, if we find a greater element, we will pair it with the elements from the stack till the top element of the stack is less than the current element.

illustration:
Below is the illustration of the above approach: 



Follow the steps mentioned below to implement the idea:

Push the first element to stack.
Pick the rest of the elements one by one and follow the following steps in the loop. 
Mark the current element as next.
If the stack is not empty, compare top most element of stack with next.
If next is greater than the top element, Pop element from the stack. next is the next greater element for the popped element.
Keep popping from the stack while the popped element is smaller than next. next becomes the next greater element for all such popped elements.
Finally, push the next in the stack.
After the loop in step 2 is over, pop all the elements from the stack and print -1 as the next element for them.           
Below is the implementation of the above approach:

// A Stack based C++ program to find next
// greater element for all array elements.
#include <bits/stdc++.h>
using namespace std;

/* prints element and NGE pair for all
elements of arr[] of size n */
void printNGE(int arr[], int n)
{
    stack<int> s;

    /* push the first element to stack */
    s.push(arr[0]);

    // iterate for rest of the elements
    for (int i = 1; i < n; i++) {

        if (s.empty()) {
            s.push(arr[i]);
            continue;
        }

        /* if stack is not empty, then
           pop an element from stack.
           If the popped element is smaller
           than next, then
        a) print the pair
        b) keep popping while elements are
        smaller and stack is not empty */
        while (s.empty() == false && s.top() < arr[i]) {
            cout << s.top() << " --> " << arr[i] << endl;
            s.pop();
        }

        /* push next to stack so that we can find
        next greater for it */
        s.push(arr[i]);
    }

    /* After iterating over the loop, the remaining
    elements in stack do not have the next greater
    element, so print -1 for them */
    while (s.empty() == false) {
        cout << s.top() << " --> " << -1 << endl;
        s.pop();
    }
}

/* Driver code */
int main()
{
    int arr[] = { 11, 13, 21, 3 };
    int n = sizeof(arr) / sizeof(arr[0]);
    printNGE(arr, n);
    return 0;
}
Time Complexity: O(N) 
Auxiliary Space: O(N) 

 
Find Next Greater Element using Map: 
In this particular approach we are using the map as our main stack

This is same as above method but the elements are pushed and popped only once into the stack. The array is changed in place. The array elements are pushed into the stack until it finds a greatest element in the right of array. In other words the elements are popped from stack when top of the stack value is smaller in the current array element.
Once all the elements are processed in the array but stack is not empty. The left out elements in the stack doesn't encounter any greatest element . So pop the element from stack and change it's index value as -1 in the array.
// C++ code to implement the approach

#include <bits/stdc++.h>

using namespace std;

void nextLargerElement(int arr[], int n)
{
    vector<unordered_map<string, int> > s;

    // iterating over the array
    for (int i = 0; i < n; i++) {
        while (s.size() > 0
               && s[s.size() - 1]["value"] < arr[i]) {
            // updating the array as per the stack top
            unordered_map<string, int> d = s[s.size() - 1];
            s.pop_back();
            arr[d["ind"]] = arr[i];
        }
        // pushing values to stack
        unordered_map<string, int> e;

        e["value"] = arr[i];
        e["ind"] = i;
        s.push_back(e);
    }

    // updating the array as per the stack top
    while (s.size() > 0) {
        unordered_map<string, int> d = s[s.size() - 1];
        s.pop_back();
        arr[d["ind"]] = -1;
    }
}

// Driver Code

int main()
{
    int arr[] = { 6, 8, 0, 1, 3 };
    int n = 5;

    // Function call
    nextLargerElement(arr, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

// This code is contributed by phasing17

Output
8 -1 1 3 -1 
Time Complexity: O(N) 
Auxiliary Space: O(N)
