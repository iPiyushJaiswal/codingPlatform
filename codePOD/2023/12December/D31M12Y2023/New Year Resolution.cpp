/*Problem GFG (Medium)

New Year Resolution


Question link: https://www.geeksforgeeks.org/problems/good-by-2023/1

---------------------------

Logic: DP

---------------------------

Complexity: 

Method 1 : Recursion

Time Complexity= O(2^n)

Space Complexity= O(n) recursive stack
----------------------------------
Method 2 : Memoization

Time Complexity= O(n*sum)

Space Complexity=O(n*sum) dp vector + O(n) recursive stack
----------------------------------
Method 3 : Tabulation

Time Complexity= O(n*sum)

Space Complexity=O(n*sum) dp vector
----------------------------------
Method 4 : Space optimization

Time Complexity= O(n*sum)

Space Complexity=O(2*sum) dp vector
----------------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: DP
*/

class Solution {
    
    public:
    bool rec(int i,int n,int coins[],int sum)
    {
        if(sum!=0 &&(sum%20==0 || sum%24==0 || sum==2024))
        return true;
        if(i==n)
        return false;
        return rec(i+1,n,coins,sum+coins[i]) ||
        rec(i+1,n,coins,sum);
    }
    bool rec1(int i,int n,int coins[],int sum,vector<vector<int>>&dp)
    {
        if(i==n)
        {
            if(sum!=0 &&(sum%20==0 || sum%24==0 || sum==2024))
            return true;
            return false;
        }
        if(dp[i][sum]!=-1)
        return dp[i][sum];
        return dp[i][sum]=rec1(i+1,n,coins,sum+coins[i],dp) ||
        rec1(i+1,n,coins,sum,dp);
    }
    int isPossible(int N , int coins[]) 
    {
        // recursion
        // return rec(0,N,coins,0);
        
        // memoization
        // vector<vector<int>>dp(N+1,vector<int>(2025,-1));
        // return rec1(0,N,coins,0,dp);
        
        // tabulation
        // vector<vector<int>>dp(N+1,vector<int>(2025,0));
        // for(int i=1;i<103;i++)
        // {
        //     if(20*i<=2024)
        //     dp[N][20*i]=true;
        //     if(24*i<=2024)
        //     dp[N][24*i]=true;
        // }
        // dp[N][2024]=true;
        // for(int i=N-1;i>=0;i--)
        // {
        //     for(int j=2023;j>=0;j--)
        //     {
        //         bool a=0;
        //         if(j+coins[i]<=2024)
        //         a=dp[i+1][j+coins[i]];
        //         bool b=dp[i+1][j];
        //         dp[i][j]=a || b;
        //     }
        // }
        // return dp[0][0];
        
        // space optimization
        vector<int>dp(2025,0);
        vector<int>temp(2025,0);
        for(int i=1;i<103;i++)
        {
            if(20*i<=2024)
            dp[20*i]=true;
            if(24*i<=2024)
            dp[24*i]=true;
        }
        dp[2024]=true;
        for(int i=N-1;i>=0;i--)
        {
            for(int j=2023;j>=0;j--)
            {
                bool a=0;
                if(j+coins[i]<=2024)
                a=dp[j+coins[i]];
                bool b=dp[j];
                temp[j]=a || b;
            }
            dp=temp;
        }
        return dp[0];
    }
};