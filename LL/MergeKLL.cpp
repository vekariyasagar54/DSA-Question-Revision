// Merge K sorted linked lists
// MediumAccuracy: 57.01%Submissions: 71K+Points: 4
// Win 2X Geekbits, Get on the Leaderboard & Top the Coding Charts! Register for GFG Weekly Coding Contest

// banner
// Given K sorted linked lists of different sizes. The task is to merge them in such a way that after merging they will be a single sorted linked list.

// Example 1:

// Input:
// K = 4
// value = {{1,2,3},{4 5},{5 6},{7,8}}
// Output: 1 2 3 4 5 5 6 7 8
// Explanation:
// The test case has 4 sorted linked 
// list of size 3, 2, 2, 2
// 1st    list     1 -> 2-> 3
// 2nd   list      4->5
// 3rd    list      5->6
// 4th    list      7->8
// The merged list will be
// 1->2->3->4->5->5->6->7->8.
// Example 2:

// Input:
// K = 3
// value = {{1,3},{4,5,6},{8}}
// Output: 1 3 4 5 6 8
// Explanation:
// The test case has 3 sorted linked
// list of size 2, 3, 1.
// 1st list 1 -> 3
// 2nd list 4 -> 5 -> 6
// 3rd list 8
// The merged list will be
// 1->3->4->5->6->8.
// Your Task:
// The task is to complete the function mergeKList() which merges the K given lists into a sorted one. The printing is done automatically by the driver code.

// Expected Time Complexity: O(nk Logk)
// Expected Auxiliary Space: O(k)
// Note: n is the maximum size of all the k link list

// Constraints
// 1 <= K <= 103



//there are two approaches to slove this problem 
//1) using min-heap
//2) using Divide and Conquer method


//method-1
/*Linked list Node structure

struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};
*/ 

class Solution{
  public:
  
    // Comparison object to be used to order the min-heap
    struct comp
    {
        bool operator()(const Node *lhs, const Node *rhs) const {
            return lhs->data > rhs->data;
        }
    };
    
    //Function to merge K sorted linked list.
    Node * mergeKLists(Node *arr[], int K)
    {
        // Your code here
        priority_queue<Node*, vector<Node*>, comp> pq;

        for (int i = 0; i < K; i++) {
            pq.push(arr[i]);
        }
 
        Node *head = nullptr, *last = nullptr;
        while (!pq.empty())
        {
            Node* min = pq.top();
            pq.pop();
 
            if (head == nullptr) {
                head = last = min;
            }
            else {
                last->next = min;
                last = min;
            }
 
            if (min->next != nullptr) {
                pq.push(min->next);
            }
        }
        return head;
    }
};


//method-2

/*Linked list Node structure

struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};
*/ 

class Solution{
  public:
    Node* sortedMerge(Node* a, Node* b)  
{  
   if(a==NULL)return b;
    if(b==NULL)return a;
    Node *head=NULL,*tail=NULL;
    if(a->data<=b->data){
        head=tail=a;a=a->next;
    }
    else{
        head=tail=b;b=b->next;
    }
    while(a!=NULL&&b!=NULL){
        if(a->data<=b->data){
            tail->next=a;tail=a;a=a->next;
        }
        else{
            tail->next=b;tail=b;b=b->next;
        }
    }
    if(a==NULL){tail->next=b;}
    else{
        tail->next=a;
    }
    return head;
}  


    Node * mergeKLists(Node *arr[], int k , int low = 0)
    {
        
           if(low < k - 1)
           {
               int mid = (low + k - 1)/2;
              Node* a = mergeKLists(arr , mid + 1, low);
              Node* b = mergeKLists(arr , k , mid + 1);
              arr[low] = sortedMerge(a, b);
              return arr[low];
           }
           else
           {
               return arr[low];
           }
    }
};
