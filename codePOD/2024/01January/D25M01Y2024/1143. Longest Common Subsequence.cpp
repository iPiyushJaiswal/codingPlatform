/*Problem LeetCode (Medium)

1143. Longest Common Subsequence


Question link: https://leetcode.com/problems/longest-common-subsequence/?envType=daily-question&envId=2024-01-25

Solution link: https://leetcode.com/problems/longest-common-subsequence/submissions/1156502648/?envType=daily-question&envId=2024-01-25


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

Space Complexity=O(n*2) dp vector
--------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: DP
*/

class Solution {
public:
    int rec(int i,int j,string& text1, string& text2)
    {
        if(i<0 || j<0)
        return 0;
        int take=0;
        if(text1[i]==text2[j])
        take=1 + rec(i-1,j-1,text1,text2);
        int notTake=max(rec(i-1,j,text1,text2),rec(i,j-1,text1,text2));
        return max(take,notTake);
    }
    int rec1(int i,int j,string& text1, string& text2,vector<vector<int>>&dp)
    {
        if(i<0 || j<0)
        return 0;
        if(dp[i][j]!=-1)
        return dp[i][j];
        int take=0;
        if(text1[i]==text2[j])
        take=1 + rec1(i-1,j-1,text1,text2,dp);
        int notTake=max(rec1(i-1,j,text1,text2,dp),rec1(i,j-1,text1,text2,dp));
        return dp[i][j]=max(take,notTake);
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        // recursion
        // return rec(n-1,m-1,text1,text2);

        // memoization
        // vector<vector<int>>dp(n,vector<int>(m,-1));
        // return rec1(n-1,m-1,text1,text2,dp);

        // tabulation
        // vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        // for(int i=1;i<=n;i++)
        // {
        //     for(int j=1;j<=m;j++)
        //     {
        //         int take=0;
        //         if(text1[i-1]==text2[j-1])
        //         take=1 + dp[i-1][j-1];
        //         int notTake=max(dp[i][j-1],dp[i-1][j]);
        //         dp[i][j]=max(take,notTake);
        //     }
        // }
        // return dp[n][m];

        // space optimization
        vector<int>dp(m+1,0);
        vector<int>temp(m+1,0);
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                int take=0;
                if(text1[i-1]==text2[j-1])
                take=1 + dp[j-1];
                int notTake=max(temp[j-1],dp[j]);
                temp[j]=max(take,notTake);
            }
            dp=temp;
        }
        return dp[m];
    }
};