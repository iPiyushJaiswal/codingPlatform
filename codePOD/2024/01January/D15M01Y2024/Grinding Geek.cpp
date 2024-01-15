/*Problem GFG (Medium)

Grinding Geek


Question link: https://www.geeksforgeeks.org/problems/grinding-geek/1

---------------------------

Logic: DP

---------------------------

Complexity: 

Method 1 : Recursion

Time Complexity= O(2^n)

Space Complexity= O(n) recursive stack
----------------------------------
Method 2 : Memoization

Time Complexity= O(n*target)

Space Complexity= O(n*target) dp vector + O(n) recursive stack
----------------------------------
Method 3 : Tabulation

Time Complexity= O(n*target)

Space Complexity= O(n*target) dp vector
----------------------------------
Method 4 : Space Optimization

Time Complexity= O(n*target)

Space Complexity= O(2*target) dp vector
----------------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: DP
*/

class Solution{
    public:
    int rec(int i,int n, int total, vector<int> &cost)
    {
        if(i==n)
        return 0;
        int a=0;
        if(total>=cost[i])
        a=1+rec(i+1,n,total-ceil(cost[i]*0.1),cost);
        int b=rec(i+1,n,total,cost);
        return max(a,b);
    }
    int rec1(int i,int n, int total, vector<int> &cost,
    vector<vector<int>>&dp)
    {
        if(i==n)
        return 0;
        if(dp[i][total]!=-1)
        return dp[i][total];
        int a=0;
        if(total>=cost[i])
        a=1+rec1(i+1,n,total-ceil(cost[i]*0.1),cost,dp);
        int b=rec1(i+1,n,total,cost,dp);
        return dp[i][total]=max(a,b);
    }
    int max_courses(int n, int total, vector<int> &cost)
    {
        //Code Here
        // recursion
        // return rec(0,n,total,cost);
        
        // memoization
        // vector<vector<int>>dp(n+1,vector<int>(total+1,-1));
        // return rec1(0,n,total,cost,dp);
        
        // tabulation
        // vector<vector<int>>dp(n+1,vector<int>(total+1,0));
        // for(int i=n-1;i>=0;i--)
        // {
        //     for(int j=0;j<=total;j++)
        //     {
        //         int a=0;
        //         if(j>=cost[i])
        //         a=1+dp[i+1][j-ceil(cost[i]*0.1)];
        //         int b=dp[i+1][j];
        //         dp[i][j]=max(a,b);
        //     }
        // }
        // return dp[0][total];
        
        // space optimization
        vector<int>dp(total+1,0);
        vector<int>temp(total+1,0);
        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<=total;j++)
            {
                int a=0;
                if(j>=cost[i])
                a=1+dp[j-ceil(cost[i]*0.1)];
                int b=dp[j];
                temp[j]=max(a,b);
            }
            dp=temp;
        }
        return dp[total];
    }
};