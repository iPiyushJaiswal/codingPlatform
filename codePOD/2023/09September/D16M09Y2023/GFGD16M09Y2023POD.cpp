/*Problem GFG (Easy)

Count number of hops


Question link: https://practice.geeksforgeeks.org/problems/count-number-of-hops-1587115620/1

Logic: DP

Complexity: 

Method 1: Recursion

Time Complexity=O(3^n)

Space Complexity=O(n) recursive stack.

-------------------------

Method 2: Memoization

Time Complexity=O(n)

Space Complexity=O(n)dp vector + O(n) recursive stack.

-------------------------

Method 3: Tabulation

Time Complexity=O(n)

Space Complexity=O(n)dp vector.

-------------------------

Method 4: Space optimization

Time Complexity=O(n)

Space Complexity=O(1)

-----------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method : DP
*/

class Solution
{
    public:
    //Function to count the number of ways in which frog can reach the top.
    long long mod=1e9 +7;
    long long rec(int i,int n)
    {
        if(i==n)
        return 1;
        long long count=0;
        count+=rec(i+1,n);
        if(i+2<=n)
        count+=rec(i+2,n);
        if(i+3<=n)
        count+=rec(i+3,n);
        return count%mod;
    }
    long long rec1(int i,int n,vector<long long>&dp)
    {
        if(i==n)
        return 1;
        if(dp[i]!=-1)
        return dp[i];
        long long count=0;
        count+=rec1(i+1,n,dp);
        if(i+2<=n)
        count+=rec1(i+2,n,dp);
        if(i+3<=n)
        count+=rec1(i+3,n,dp);
        return dp[i]=count%mod;
    }
    long long countWays(int n)
    {
        // your code here
        // recursive
        // return rec(0,n);
        
        // memoization
        // vector<long long>dp(n+1,-1);
        // return rec1(0,n,dp);
        
        // tabulation
        // vector<long long>dp(n+1,0);
        // dp[n]=1;
        // for(int i=n-1;i>=0;i--)
        // {
        //     long long count=0;
        //     count+=dp[i+1];
        //     if(i+2<=n)
        //     count+=dp[i+2];
        //     if(i+3<=n)
        //     count+=dp[i+3];
        //     dp[i]=count%mod;
        // }
        // return dp[0];
        
        // space optimization
        long long prev1=0,prev2=0,prev3=0,curr=0;
        prev1=1;
        for(int i=n-1;i>=0;i--)
        {
            long long count=0;
            count+=prev1;
            if(i+2<=n)
            count+=prev2;
            if(i+3<=n)
            count+=prev3;
            curr=count%mod;
            prev3=prev2;
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }
};