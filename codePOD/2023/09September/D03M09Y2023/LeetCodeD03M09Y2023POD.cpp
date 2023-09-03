/*Problem LeetCode (Medium)

62. Unique Paths


Question link: https://leetcode.com/problems/unique-paths/description/?envType=daily-question&envId=2023-09-03

Logic: DP + combinational problem.

Complexity: 

Method 1: Recurssion

Time Complexity=O(Exponential)

Space Complexity=O(n). 

--------------------------

Method 2: Memoization

Time Complexity=O(m*n)

Space Complexity=O(m*n). vector used as DP. + O(m+n) recursive stack.

--------------------------

Method 3: Tabulation

Time Complexity=O(m*n)

Space Complexity=O(m*n). vector used as DP.

--------------------------

Method 4: Space optimization 1

Time Complexity=O(m*n)

Space Complexity=O(2*n). vector used as DP.
 
--------------------------

Method 5: Space optimization 2

Time Complexity=O(min(m,n))

Space Complexity=O(1).

----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------
*/
class Solution {
public:
    int rec(int i,int j,int m,int n)
    {
        if(i==m && j==n)
        return 1;
        int val=0;
        if(i<=m && j+1<=n)
        val+=rec(i,j+1,m,n);
        if(i+1<=m && j<=n)
        val+=rec(i+1,j,m,n);
        return val;
    }
    int rec1(int i,int j,int m,int n, vector<vector<int>>&dp)
    {
        if(i==m && j==n)
        return 1;
        if(dp[i][j]!=-1)
        return dp[i][j];
        int val=0;
        if(i<=m && j+1<=n)
        val+=rec1(i,j+1,m,n,dp);
        if(i+1<=m && j<=n)
        val+=rec1(i+1,j,m,n,dp);
        return dp[i][j]=val;
    }
    int uniquePaths(int m, int n) {
    // return rec(0,0,m-1,n-1);

    // memoization
    // vector<vector<int>>dp(m,vector<int>(n,-1));
    // return rec1(0,0,m-1,n-1,dp);

    // tabulation
    // vector<vector<int>>dp(m+1,vector<int>(n+1,0));
    // dp[m-1][n-1]=1;
    // for(int i=m-1;i>=0;i--)
    // {
    //     for(int j=n-1;j>=0;j--)
    //     {
    //         if(i==m-1 && j==n-1)
    //         continue;
    //         int val=0;
    //         val+=dp[i][j+1];
    //         val+=dp[i+1][j];
    //         dp[i][j]=val;
    //     }
    // }
    // return dp[0][0];

    // space optimization
    // vector<int>dp(n+1,0);
    // vector<int>temp(n+1,0);
    // temp[n-1]=1;
    // for(int i=m-1;i>=0;i--)
    // {
    //     for(int j=n-1;j>=0;j--)
    //     {
    //         if(i==m-1 && j==n-1)
    //         continue;
    //         int val=0;
    //         val+=temp[j+1];
    //         val+=dp[j];
    //         temp[j]=val;
    //     }
    //     dp=temp;
    // }
    // return dp[0];

    // space optimized 2:
    int maxRange=m+n-2;
    int step=min(m,n)-1;
    long long ans=1;
    for(int i=0;i<step;i++)
    {
        ans=ans*(maxRange-i)/(i+1);
    }
    return ans;
    }
};