/*Problem LeetCode (Hard)

2742. Painting the Walls


Question link: https://leetcode.com/problems/painting-the-walls/?envType=daily-question&envId=2023-10-14


Logic: DP

-------------------------

Complexity: 

Method 1:  Recursive

Time Complexity=O(2^n)

Space Complexity=O(n) recursive stack

--------------------------
Method 2:  Memoization

Time Complexity=O(n*n)

Space Complexity=O(n*n) dp vector + O(n) recursive stack

--------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method : DP
*/

class Solution {
public:
    int rec(vector<int>& cost, vector<int>& time,int i,int n,int totalTime)
    {
        if(totalTime<=0)
        return 0;
        if(i>=n)
        return 1e7;
        int take=cost[i]+ rec(cost,time,i+1,n,totalTime-time[i]-1);
        int notTake=rec(cost,time,i+1,n,totalTime);
        return min(take,notTake);
    }
    int rec1(vector<int>& cost, vector<int>& time,int i,int n,int totalTime,
    vector<vector<int>>&dp)
    {
        if(totalTime<=0)
        return 0;
        if(i>=n)
        return 1e9;
        if(dp[i][totalTime]!=-1)
        return dp[i][totalTime];
        int take=cost[i]+ rec1(cost,time,i+1,n,totalTime-time[i]-1,dp);
        int notTake=rec1(cost,time,i+1,n,totalTime,dp);
        return dp[i][totalTime]=min(take,notTake);
    }
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n=cost.size();
        // return rec(cost,time,0,n,n);

        // memoization
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return rec1(cost,time,0,n,n,dp);
    }
};