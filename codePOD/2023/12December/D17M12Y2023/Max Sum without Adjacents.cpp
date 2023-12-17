/*Problem GFG (Easy)

Max Sum without Adjacents


Question link: https://www.geeksforgeeks.org/problems/max-sum-without-adjacents2430/1

---------------------------

Logic: DP

---------------------------

Complexity: 

Method 1 : Recursion

Time Complexity= O(2^n)

Space Complexity= O(n) recursive stack

----------------------------------
Method 2 : Memoization

Time Complexity= O(n)

Space Complexity= O(n) dp vector + O(n) recursive stack

----------------------------------
Method 3 : Tabulation

Time Complexity= O(n)

Space Complexity= O(n) dp vector

----------------------------------
Method 4 : Space Optimization

Time Complexity= O(n)

Space Complexity= O(1)

----------------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: DP
*/

class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int rec(int i,int *arr,int n)
	{
	    if(i>=n)
	    return 0;
	    return max(arr[i] + rec(i+2,arr,n),rec(i+1,arr,n));
	}
	int rec1(int i,int *arr,int n,vector<int>&dp)
	{
	    if(i>=n)
	    return 0;
	    if(dp[i]!=-1)
	    return dp[i];
	    int a=0;
	    if(i<n)
	    a=arr[i] + rec1(i+2,arr,n,dp);
	    int b=rec1(i+1,arr,n,dp);
	    return dp[i]=max(a,b);
	}
	int findMaxSum(int *arr, int n) {
	    // code here
	   // recursion
	   // return rec(0,arr,n);
	   
	   //memoization
	   //vector<int>dp(n,-1);
	   //return rec1(0,arr,n,dp);
	   
	   //tabulation
	   //vector<int>dp(n+2,0);
	   //for(int i=n-1;i>=0;i--)
	   //dp[i]=max(arr[i] + dp[i+2],dp[i+1]);
	   //return dp[0];
	   
	   //space optimization
	   int prev1=0,prev2=0;
	   for(int i=n-1;i>=0;i--)
	   {
	       int curr=max(arr[i] + prev2,prev1);
	       prev2=prev1;
	       prev1=curr;
	   }
	   return prev1;
	}
};