Circular tour
MediumAccuracy: 34.79%Submissions: 148K+Points: 4
The power of GeeksforGeeks now in your pockets! Download the App for Free

banner
Suppose there is a circle. There are N petrol pumps on that circle. You will be given two sets of data.
1. The amount of petrol that every petrol pump has.
2. Distance from that petrol pump to the next petrol pump.
Find a starting point where the truck can start to get through the complete circle without exhausting its petrol in between.
Note :  Assume for 1 litre petrol, the truck can go 1 unit of distance.

Example 1:

Input:
N = 4
Petrol = 4 6 7 4
Distance = 6 5 3 5
Output: 1
Explanation: There are 4 petrol pumps with
amount of petrol and distance to next
petrol pump value pairs as {4, 6}, {6, 5},
{7, 3} and {4, 5}. The first point from
where truck can make a circular tour is
2nd petrol pump. Output in this case is 1
(index of 2nd petrol pump).
Your Task:
Your task is to complete the function tour() which takes the required data as inputs and returns an integer denoting a point from where a truck will be able to complete the circle (The truck will stop at each petrol pump and it has infinite capacity). If there exists multiple such starting points, then the function must return the first one out of those. (return -1 otherwise)

Expected Time Complexity: O(N)
Expected Auxiliary Space : O(1)

Constraints:
2 ≤ N ≤ 10000
1 ≤ petrol, distance ≤ 1000

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};


// } Driver Code Ends
/*
The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/

/*You are required to complete this method*/
class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
       int start = 0 , end = 0;
       int  t = 0 , d = 0 , size = 0;
       
       do
       {
           t += p[end].petrol;
           d += p[end].distance;
           if(t >= d)
           {
               end = (end + 1)%n;
               size++;
           }
           else
           {
               end = (end + 1)%n;
               if(end > start)
               {
                   start = end;
               }
               else 
               {
                   return -1;
               }
               size = 0;
               t = 0 , d = 0; 
           }
       }while(size != n && (start < n));
       
       
       if(size == n) return start;
       return -1;
    }
};




//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        petrolPump p[n];
        for(int i=0;i<n;i++)
            cin>>p[i].petrol>>p[i].distance;
        Solution obj;
        cout<<obj.tour(p,n)<<endl;
    }
}

// } Driver Code Ends