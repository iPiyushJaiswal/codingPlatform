/*Problem GFG (Medium)

Count possible ways to construct buildings


Question link: https://www.geeksforgeeks.org/problems/count-possible-ways-to-construct-buildings5007/1

---------------------------

Logic: DP

---------------------------

Complexity: 

Method 1 : Recursion

Time Complexity= O(2^n)

Space Complexity= O(n) Recursive stack
----------------------------------
Method 2 : Memoization

Time Complexity= O(n)

Space Complexity= O(n) dp vector + O(n) Recursive stack
----------------------------------
Method 3 : Tabulation

Time Complexity= O(n)

Space Complexity= O(n) dp vector
----------------------------------
Method 4 : Space optimization

Time Complexity= O(n)

Space Complexity= O(1)
----------------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method : DP
*/

class Solution{
	public:
	int mod=1e9 +7;
	int rec(int i,int n)
	{
	    if(i>=n)
	    return 0;
	    int a=1 + rec(i+2,n)%mod;
	    int b=rec(i+1,n)%mod;
	    return (a+b)%mod;
	}
	int rec1(int i,int n,vector<int>&dp)
	{
	    if(i>=n)
	    return 0;
	    if(dp[i]!=-1)
	    return dp[i];
	    int a=1 + rec1(i+2,n,dp)%mod;
	    int b=rec1(i+1,n,dp)%mod;
	    return dp[i]=(a+b)%mod;
	}
	int TotalWays(int n)
	{
	    // Code here
	   // recursion
	   // int val=rec(0,n)+1;
	   
	   //memoization
	   //vector<int>dp(n+2,-1);
	   //int val=rec1(0,n,dp)+1;
	   //return (1ll*val*val)%mod;
	   
	   //tabulation
	   //vector<int>dp(n+2,0);
	   //for(int i=n-1;i>=0;i--)
	   //{
	   //    int a=1 + dp[i+2]%mod;
    // 	   int b=dp[i+1]%mod;
    // 	   dp[i]=(a+b)%mod;
	   //}
	   //int val=dp[0]+1;
	   //return (1ll*val*val)%mod;
	   
	   //space optimization
	  int prev2=0,prev1=0,curr=0;
	   for(int i=n-1;i>=0;i--)
	   {
    	   curr=(1+prev2+prev1)%mod;
    	   prev2=prev1;
    	   prev1=curr;
	   }
	   int val=curr+1;
	   return (1ll*val*val)%mod;
	}
};