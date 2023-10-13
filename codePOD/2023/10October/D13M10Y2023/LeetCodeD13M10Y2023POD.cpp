/*Problem LeetCode (Easy)

746. Min Cost Climbing Stairs


Question link: https://leetcode.com/problems/min-cost-climbing-stairs/description/?envType=daily-question&envId=2023-10-13


Logic: DP

-------------------------

Complexity: 

Method 1:  Recursive

Time Complexity=O(2^n)

Space Complexity=O(n) recursive stack

--------------------------
Method 2:  Memoization

Time Complexity=O(2n)

Space Complexity=O(n) dp vector + O(n) recursive stack

--------------------------
Method 3:  Tabulation

Time Complexity=O(2n)

Space Complexity=O(n) dp vector

--------------------------
Method 4:  Space Optimization

Time Complexity=O(2n)

Space Complexity=O(3) 

--------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method : DP
*/

class Solution {
public:
    int rec(vector<int>&cost,int i,int n)
    {
        if(i>=n)
        return 0;
        int take=cost[i] + min(rec(cost,i+1,n),rec(cost,i+2,n));
        return take;
    }
    int rec1(vector<int>&cost,int i,int n, vector<int>&dp)
    {
        if(i>=n)
        return 0;
        if(dp[i]!=-1)
        return dp[i];
        int take=cost[i] + min(rec1(cost,i+1,n,dp),rec1(cost,i+2,n,dp));
        return dp[i]=take;
    }
    int tabu(vector<int>&cost,int j,int n)
    {
        vector<int>dp(n+2,0);
        for(int i=n-1;i>=j;i--)
        {
            dp[i]=cost[i] + min(dp[i+1],dp[i+2]);
        }
        return dp[j];
    }
    int spaceOp(vector<int>&cost,int j,int n)
    {
        vector<int>dp(3,0);
        for(int i=n-1;i>=j;i--)
        {
            dp[0]=cost[i] + min(dp[1],dp[2]);
            dp[2]=dp[1];
            dp[1]=dp[0];
        }
        return dp[j];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        
        // memoization
        // vector<int>dp(n+1,-1);
        // int a=rec1(cost,0,n,dp);
        // dp=vector<int>(n+1,-1);
        // int b=rec1(cost,1,n,dp);
        
        // tabulation
        // int a=tabu(cost,0,n);
        // int b=tabu(cost,1,n);

        // space optimization
        int a=spaceOp(cost,0,n);
        int b=spaceOp(cost,1,n);
        return min(a,b);        
    }
};