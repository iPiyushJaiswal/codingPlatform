/*Problem LeetCode (Medium)

576. Out of Boundary Paths


Question link: https://leetcode.com/problems/out-of-boundary-paths/?envType=daily-question&envId=2024-01-26

Solution link: https://leetcode.com/problems/out-of-boundary-paths/submissions/1158281103/?envType=daily-question&envId=2024-01-26


Logic : DP

--------------------------
Complexity: 

Method 1: Recursion

Time Complexity=O(4^(n*m))

Space Complexity=O(n*m) recursive stack 
--------------------------
Method 2: Memoization

Time Complexity=O(n*m)

Space Complexity=O(n*m) dp vector + O(n*m) recursive stack 
--------------------------
Method 3: Tabulation

Time Complexity=O(n*m)

Space Complexity=O(n*m) dp vector
--------------------------

----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: DP
*/

class Solution {
public:
int mod=1000000007;
    int rec(int m, int n, int mM, int i, int j)
    {
        if(i<0 || i>=m || j<0 || j>=n)
        return 1;
        if(mM==0)
        return 0;
        int a=rec(m,n,mM-1,i-1,j);
        int b=rec(m,n,mM-1,i,j+1);
        int c=rec(m,n,mM-1,i+1,j);
        int d=rec(m,n,mM-1,i,j-1);
        return (a+b+c+d)%mod;
    }
    long long rec1(int m, int n, int mM, int i, int j,vector<vector<vector<long long>>>&dp)
    {
        if(i<0 || i>=m || j<0 || j>=n)
        return 1;
        if(mM==0)
        return 0;
        if(dp[i][j][mM]!=-1)
        return dp[i][j][mM];
        long long a=rec1(m,n,mM-1,i-1,j,dp)%mod;
        long long b=rec1(m,n,mM-1,i,j+1,dp)%mod;
        long long c=rec1(m,n,mM-1,i+1,j,dp)%mod;
        long long d=rec1(m,n,mM-1,i,j-1,dp)%mod;
        return dp[i][j][mM]=(a+b+c+d)%mod;
    }

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        // recursion
        // return rec(m,n,maxMove,startRow,startColumn);

        // memoization
        // vector<vector<vector<long long>>>dp(m+2,vector<vector<long long>>(n+2,vector<long long>(maxMove+1,-1)));
        // return rec1(m,n,maxMove,startRow,startColumn,dp);

        // tabulation
         vector<vector<vector<long long>>>dp(m+2,vector<vector<long long>>(n+2,vector<long long>(maxMove+1,0)));
             for(int i=0;i<m+2;i++)
             {
                for(int j=0;j<n+2;j++)
                {
                    for(int k=0;k<=maxMove;k++)
                    {
                        if(i==0 || i==m+1 || j==0 || j==n+1)
                        dp[i][j][k]=1;
                    }
                }
            }
         for(int k=1;k<=maxMove;k++)
         {
             for(int i=1;i<=m;i++)
             {
                 for(int j=1;j<=n;j++)
                 {
                    dp[i][j][k]=(dp[i][j][k]+dp[i-1][j][k-1])%mod;
                    dp[i][j][k]=(dp[i][j][k]+dp[i][j+1][k-1])%mod;
                    dp[i][j][k]=(dp[i][j][k]+dp[i+1][j][k-1])%mod;
                    dp[i][j][k]=(dp[i][j][k]+dp[i][j-1][k-1])%mod;
                 }
             }
         }
         return dp[startRow+1][startColumn+1][maxMove];
    }
};