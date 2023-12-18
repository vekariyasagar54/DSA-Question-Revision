/*GO at following link for the detailed solution of the problem : https://www.geeksforgeeks.org/find-the-maximum-subarray-xor-in-a-given-array/*/
/*
Brute force:
Intuition:
This problem can easily be solved in simple iteration method. Since we have to find contiguous subsequence having maximum xor.  Iterating over each element, and keep a track of maximum xor that can be obtained with contiguous subsequences starting from that element.

Example:
N = 4

arr[] = {8,1,2,12}

output= 15

FOR ARR[i]=8	FOR ARR[i]=1	FOR ARR[i]=2
8^1=9	1^2=3	2^12=14
8^1^2=11	1^2^12=15	 
8^1^2^12=7	 	 
MAX=11	MAX=15	MAX=14
Implementation:
def maxSubarrayXOR(self, arr, n):
        ans=float('-inf')
        for i in range(n):
            c=0
            for j in range(i,n):
                c^=arr[j]
                ans=max(ans,c)
        return ans
Complexity:
Time Complexity:  O(N*N) since we have to first traverse the array and in each iteration we run another loop for finding the suitable array.
Space Complexity: O(1)No extra space needed. We just need a variable "ans" to store the result, hence, O(1). 

Expected Approach
Intuition:
Maximize the xor subarray by using trie data structure to find the binary inverse of current prefix xor inorder to set the left most unset bits and maximize the value.

Implementation:
Create an empty Trie. Every node of Trie is going to contain two children, for 0 and 1 values of a bit.
Initialize pre_xor = 0 and insert into the Trie, Initialize result = INT_MIN
Traverse the given array and do the following for every array element arr[i].
pre_xor  = pre_xor  ^ arr[i], pre_xor now contains xor of elements from arr[0] to arr[i].
Query the maximum xor value ending with arr[i] from Trie.
Update the result if the value obtained above is more than the current value of the result.
Complexity:
Time Complexity: O(N) To traverse the complete array once.
Space Complexity: To store the values , we need a Trie that has an auxiliary space of O(N).
*/

//Back-end complete function template for C++

// A Trie Node 
struct TrieNode 
{ 
	int value; // Only used in leaf nodes 
	TrieNode *arr[2]; 
}; 

// Utility function to create a Trie node 
TrieNode *newNode(){
  
  TrieNode *temp = new TrieNode;
  temp->value = 0;
  temp->arr[0] = temp->arr[1] = NULL;
  return temp;

}


//Function to insert pre_xor to trie with given root. 
void insert(TrieNode *root, int pre_xor) 
{ 
	TrieNode *temp = root; 

	//starting from the msb and inserting all bits of pre_xor into Trie. 
	for (int i=INT_SIZE-1; i>=0; i--) 
	{ 
		//finding current bit in given prefix. 
		bool val = pre_xor & (1<<i); 

		//creating a new node if needed. 
		if (temp->arr[val] == NULL) 
			temp->arr[val] = newNode(); 

		temp = temp->arr[val]; 
	} 
    //storing value at leaf node.
	temp->value = pre_xor; 
} 


//Function to find the maximum XOR ending with last number in 
//prefix XOR 'pre_xor'  and return the XOR of this maximum ith pre_xor 
//which is maximum XOR ending with last element of pre_xor.
int query(TrieNode *root, int pre_xor) 
{ 
	TrieNode *temp = root; 
	for (int i=INT_SIZE-1; i>=0; i--) 
	{ 
		//finding current bit in given prefix. 
		bool val = pre_xor & (1<<i); 

		//traverse Trie and looking for a prefix that has opposite bit,
		if (temp->arr[1-val]!=NULL) 
			temp = temp->arr[1-val]; 

		//if there is no prefix with opposite bit then looking for same bit. 
		else if (temp->arr[val] != NULL) 
			temp = temp->arr[val]; 
	} 
	return pre_xor^(temp->value); 
} 


class Solution
{
    public:
    //Function to return maximum XOR value. 
    int maxSubarrayXOR(int arr[], int n) 
    { 
    	//creating a Trie and inserting 0 into it. 
    	TrieNode *root = newNode(); 
    	insert(root, 0); 
    
    	//initializing answer and xor of current prefix.
    	int result = INT_MIN, pre_xor =0; 
    
    	//traversing all input array elements. 
    	for (int i=0; i<n; i++) 
    	{ 
    		//updating current prefix xor and inserting it into Trie .
    		pre_xor = pre_xor^arr[i]; 
    		insert(root, pre_xor); 
    
    		//Query for current prefix xor in Trie and updating 
    		//result if required.
    		result = max(result, query(root, pre_xor)); 
    	} 
    	return result; 
    } 
};
