/*Problem LeetCode (Medium)

931. Minimum Falling Path Sum


Question link: https://leetcode.com/problems/minimum-falling-path-sum/description/

Solution link: https://leetcode.com/problems/minimum-falling-path-sum/submissions/1150777689/


Logic : DP

--------------------------
Complexity: 

Method 1: Recursion

Time Complexity=O(3^n)

Space Complexity=O(n) recursive stack
--------------------------
Method 2: Memoization

Time Complexity=O(n*n)

Space Complexity=O(n*n) dp vector + O(n) recursive stack 
--------------------------
Method 3: Tabulation

Time Complexity=O(n*n)

Space Complexity=O(n*n) dp vector
--------------------------
Method 4: Space Optimization

Time Complexity=O(n*n)

Space Complexity=O(2*n) dp vector
--------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: DP
*/

class Solution {
public:
    int rec(int i,int j,int n,vector<vector<int>>& matrix)
    {
        if(i==n)
        return 0;
        int ans=INT_MAX;
        for(int k=-1;k<=1;k++)
        {
            int col=j+k;
            if(col>=0 && col<n)
            ans=min(ans,matrix[i][j] + rec(i+1,col,n,matrix));
        }
        return ans;
    }
    int rec1(int i,int j,int n,vector<vector<int>>& matrix,
    vector<vector<int>>&dp)
    {
        if(i==n)
        return 0;
        if(dp[i][j]!=-1)
        return dp[i][j];
        int ans=INT_MAX;
        for(int k=-1;k<=1;k++)
        {
            int col=j+k;
            if(col>=0 && col<n)
            ans=min(ans,matrix[i][j] + rec1(i+1,col,n,matrix,dp));
        }
        return dp[i][j]=ans;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int ans=INT_MAX;
        // for(int j=0;j<n;j++)
        // {
        //     ans=min(ans,rec(0,j,n,matrix));
        // }
        // return ans;

        // memoization
        // vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        // for(int j=0;j<n;j++)
        // ans=min(ans,rec1(0,j,n,matrix,dp));
        // return ans;

        // tabulation
        // vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        // for(int i=n-1;i>=0;i--)
        // {
        //     for(int j=n-1;j>=0;j--)
        //     {
        //         int ans=INT_MAX;
        //         for(int k=-1;k<=1;k++)
        //         {
        //             int col=j+k;
        //             if(col>=0 && col<n)
        //             ans=min(ans,matrix[i][j] + dp[i+1][col]);
        //         }
        //         dp[i][j]=ans;
        //     }
        // }
        // int mini=INT_MAX;
        // for(int j=0;j<n;j++)
        // mini=min(mini,dp[0][j]);
        // return mini;

        // space optimization
        vector<int>dp(n+1,0);
        vector<int>temp(n+1,0);
        for(int i=n-1;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                int ans=INT_MAX;
                for(int k=-1;k<=1;k++)
                {
                    int col=j+k;
                    if(col>=0 && col<n)
                    ans=min(ans,matrix[i][j] + dp[col]);
                }
                temp[j]=ans;
            }
            dp=temp;
        }
        int mini=INT_MAX;
        for(int j=0;j<n;j++)
        mini=min(mini,dp[j]);
        return mini;
    }
};