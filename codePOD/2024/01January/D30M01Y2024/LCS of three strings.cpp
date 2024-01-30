/*Problem GFG (Medium)

LCS of three strings


Question link:	https://www.geeksforgeeks.org/problems/lcs-of-three-strings0028/1

---------------------------

Logic: DP 

---------------------------

Complexity: 

Method 1 : Recursion 

Time Complexity= O(2^n1 * 2^n2 * 2*n3)

Space Complexity= O(n1+n2+n3) recursive stack.
----------------------------------
Method 2 : Memoization 

Time Complexity= O(n1*n2*n3)

Space Complexity= O(n1*n2*n3)dp vector + O(n1+n2+n3) recursive stack.
----------------------------------
Method 3 : Tabulation 

Time Complexity= O(n1*n2*n3)

Space Complexity= O(n1*n2*n3)dp vector
----------------------------------
Method 4 : Space Optimization 

Time Complexity= O(n1*n2*n3)

Space Complexity= O(2*n2*n3)dp vector
----------------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: DP 
*/

class Solution
{
    public:
        int rec(string A, string B, string C, int i, int j, int k)
        {
            if(i<0 || j<0 || k<0)
            return 0;
            int a=0,b=0;
            if(A[i]==B[j] && B[j]==C[k])
            a=1+rec(A,B,C,i-1,j-1,k-1);
            b=max(rec(A,B,C,i-1,j,k),max(rec(A,B,C,i,j-1,k),
            rec(A,B,C,i,j,k-1)));
            return max(a,b);
        }
        int rec1(string A, string B, string C, int i, int j, int k,
        vector<vector<vector<int>>>&dp)
        {
            if(i<0 || j<0 || k<0)
            return 0;
            if(dp[i][j][k]!=-1)
            return dp[i][j][k];
            int a=0,b=0;
            if(A[i]==B[j] && B[j]==C[k])
            a=1+rec1(A,B,C,i-1,j-1,k-1,dp);
            b=max(rec1(A,B,C,i-1,j,k,dp),max(rec1(A,B,C,i,j-1,k,dp),
            rec1(A,B,C,i,j,k-1,dp)));
            return dp[i][j][k]=max(a,b);
        }
        int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
        {
            // your code here
            // recursion
            // return rec(A,B,C,n1-1,n2-1,n3-1);
            
            // memoization
            // vector<vector<vector<int>>>dp(n1+1,vector<vector<int>>(n2+1,
            // vector<int>(n3+1,-1)));
            // return rec1(A,B,C,n1-1,n2-1,n3-1,dp);
            
            // tabulation
            // vector<vector<vector<int>>>dp(n1+1,vector<vector<int>>(n2+1,
            // vector<int>(n3+1,0)));
            // for(int i=1;i<=n1;i++)
            // {
            //     for(int j=1;j<=n2;j++)
            //     {
            //         for(int k=1;k<=n3;k++)
            //         {
            //             int a=0,b=0;
            //             if(A[i-1]==B[j-1] && B[j-1]==C[k-1])
            //             a=1+dp[i-1][j-1][k-1];
            //             b=max(dp[i-1][j][k],max(dp[i][j-1][k],
            //             dp[i][j][k-1]));
            //             dp[i][j][k]=max(a,b);
            //         }
            //     }
            // }
            // return dp[n1][n2][n3];
            
            // space optimization
            vector<vector<int>>dp(n2+1,vector<int>(n3+1,0));
            vector<vector<int>>temp(n2+1,vector<int>(n3+1,0));
            for(int i=1;i<=n1;i++)
            {
                for(int j=1;j<=n2;j++)
                {
                    for(int k=1;k<=n3;k++)
                    {
                        int a=0,b=0;
                        if(A[i-1]==B[j-1] && B[j-1]==C[k-1])
                        a=1+dp[j-1][k-1];
                        b=max(dp[j][k],max(temp[j-1][k],
                        temp[j][k-1]));
                        temp[j][k]=max(a,b);
                    }
                }
                dp=temp;
            }
            return dp[n2][n3];
        }
};