/*Problem GFG (Medium)

Consecutive 1's not allowed


Question link: https://www.geeksforgeeks.org/problems/consecutive-1s-not-allowed1912/1

---------------------------

Logic: DP

---------------------------

Complexity: 

Method 1 : Recursion

Time Complexity= O(2^n)

Space Complexity= O(n) recursive stack

----------------
Method 2 : Memoization

Time Complexity= O(n*2)

Space Complexity=O(n*2) dp vector + O(n) recursive stack

----------------
Method 3 : Tabulation

Time Complexity= O(n*2)

Space Complexity=O(n*2) dp vector

----------------
Method 4 : Space Optimization1

Time Complexity= O(n*2)

Space Complexity=O(2*2) dp vector

----------------
Method 5 : Fibonic series

Time Complexity= O(n)

Space Complexity= O(1)

----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: DP
*/

class Solution{
public:
	// #define ll long long
	int mod=1e9 +7;
	ll rec(int i,int n,int prev)
	{
	    if(i==n)
	    return 1;
	    ll a=0;
	    if(prev!=1)
	    a=rec(i+1,n,1)%mod;
	    ll b=rec(i+1,n,0)%mod;
	    return (a+b)%mod;
	}
	ll rec1(int i,int n,int prev,vector<vector<ll>>&dp)
	{
	    if(i==n)
	    return 1;
	    ll a=0;
	    if(dp[i][prev]!=-1)
	    return dp[i][prev];
	    if(prev!=1)
	    a=rec1(i+1,n,1,dp)%mod;
	    ll b=rec1(i+1,n,0,dp)%mod;
	    return dp[i][prev]=(a+b)%mod;
	}
	ll countStrings(int n) {
	    // code here
	   // recursion
	   // return rec(0,n,0);
	   
	   //memoization
	   //vector<vector<ll>>dp(n+1,vector<ll>(2,-1));
	   //return rec1(0,n,0,dp);
	   
	   //tabulation
	   //vector<vector<ll>>dp(n+1,vector<ll>(2,0));
	   //dp[n][0]=1;
	   //dp[n][1]=1;
	   //for(int i=n-1;i>=0;i--)
	   //{
	   //    for(int prev=1;prev>=0;prev--)
	   //    {
	   //        ll a=0;
	   //        if(prev!=1)
    //     	   a=dp[i+1][1]%mod;
    //     	   ll b=dp[i+1][0]%mod;
    //     	   dp[i][prev]=(a+b)%mod;
	   //    }
	   //}
	   //return dp[0][0];
	   
	   //space optimize
	   //vector<ll>dp(2,0);
	   //vector<ll>temp(2,0);
	   //dp[0]=1;
	   //dp[1]=1;
	   //for(int i=n-1;i>=0;i--)
	   //{
	   //    for(int prev=1;prev>=0;prev--)
	   //    {
	   //        ll a=0;
	   //        if(prev!=1)
    //     	   a=dp[1]%mod;
    //     	   ll b=dp[0]%mod;
    //     	   temp[prev]=(a+b)%mod;
	   //    }
	   //    dp=temp;
	   //}
	   //return dp[0];
	   
	   //space optmization 2
	   ll prev1=2;
	   ll prev2=3;
	   if(n==1)
	   return prev1;
	   if(n==2)
	   return prev2;
	   for(int i=3;i<=n;i++)
	   {
	       ll curr=(prev1+prev2)%mod;
	       prev1=prev2;
	       prev2=curr;
	   }
	   return prev2;
	}
};