// You are given a special linked list with N nodes where each node has a next pointer pointing to its next node. You are also given M random pointers, where you will be given M number of pairs denoting two nodes a and b  i.e. a->arb = b (arb is pointer to random node).

// Construct a copy of the given list. The copy should consist of exactly N new nodes, where each new node has its value set to the value of its corresponding original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. None of the pointers in the new list should point to nodes in the original list.

// For example, if there are two nodes X and Y in the original list, where X.arb --> Y, then for the corresponding two nodes x and y in the copied list, x.arb --> y.

// Return the head of the copied linked list.

// ArbitLinked List1

// Note :- The diagram isn't part of any example, it just depicts an example of how the linked list may look like.

// Example 1:

// Input:
// N = 4, M = 2
// value = {1,2,3,4}
// pairs = {{1,2},{2,4}}
// Output: 1
// Explanation: In this test case, there
// are 4 nodes in linked list.  Among these
// 4 nodes,  2 nodes have arbitrary pointer
// set, rest two nodes have arbitrary pointer
// as NULL. Second line tells us the value
// of four nodes. The third line gives the
// information about arbitrary pointers.
// The first node arbitrary pointer is set to
// node 2.  The second node arbitrary pointer
// is set to node 4.
// Example 2:

// Input:
// N = 4, M = 2
// value[] = {1,3,5,9}
// pairs[] = {{1,1},{3,4}}
// Output: 1
// Explanation: In the given testcase ,
// applying the method as stated in the
// above example, the output will be 1.

// Your Task:
// The task is to complete the function copyList() which takes one argument the head of the linked list to be cloned and should return the head of the cloned linked list.

// NOTE : 
// 1. If there is any node whose arbitrary pointer is not given then it's by default NULL. 
// 2. Your solution return an output 1 if your clone linked list is correct, else it returns 0.
// 3. Don't make any changes to the original linked list.

// Expected Time Complexity : O(n)
// Expected Auxilliary Space : O(1)

// Constraints:
// 1 <= N <= 100
// 1 <= M <= N
// 1 <= a, b <= 100

// C++ program to clone a linked list with next
// and arbit pointers in O(n) time
#include <bits/stdc++.h>
using namespace std;

// Structure of linked list Node
struct Node
{
	int data;
	Node *next,*random;
	Node(int x)
	{
		data = x;
		next = random = NULL;
	}
};

// Utility function to print the list.
void print(Node *start)
{
	Node *ptr = start;
	while (ptr)
	{
		cout << "Data = " << ptr->data << ", Random = "
			<< ptr->random->data << endl;
		ptr = ptr->next;
	}
}

// This function clones a given linked list
// in O(1) space
Node* clone(Node *start)
{
	Node* curr = start, *temp;

	// insert additional node after
	// every node of original list
	while (curr)
	{
		temp = curr->next;

		// Inserting node
		curr->next = new Node(curr->data);
		curr->next->next = temp;
		curr = temp;
	}

	curr = start;

	// adjust the random pointers of the
	// newly added nodes
	while (curr)
	{
		if(curr->next)
			curr->next->random = curr->random ?
								curr->random->next : curr->random;

		// move to the next newly added node by
		// skipping an original node
		curr = curr->next?curr->next->next:curr->next;
	}

	Node* original = start, *copy = start->next;

	// save the start of copied linked list
	temp = copy;

	// now separate the original list and copied list
	while (original && copy)
	{
		original->next =
		original->next? original->next->next : original->next;

		copy->next = copy->next?copy->next->next:copy->next;
		original = original->next;
		copy = copy->next;
	}

	return temp;
}

// Driver code
int main()
{
	Node* start = new Node(1);
	start->next = new Node(2);
	start->next->next = new Node(3);
	start->next->next->next = new Node(4);
	start->next->next->next->next = new Node(5);

	// 1's random points to 3
	start->random = start->next->next;

	// 2's random points to 1
	start->next->random = start;

	// 3's and 4's random points to 5
	start->next->next->random =
					start->next->next->next->next;
	start->next->next->next->random =
					start->next->next->next->next;

	// 5's random points to 2
	start->next->next->next->next->random =
									start->next;

	cout << "Original list : \n";
	print(start);

	cout << "\nCloned list : \n";
	Node *cloned_list = clone(start);
	print(cloned_list);

	return 0;
}
