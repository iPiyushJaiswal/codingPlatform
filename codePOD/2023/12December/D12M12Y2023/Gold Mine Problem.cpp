/*Problem GFG (Medium)

Gold Mine Problem


Question link: https://www.geeksforgeeks.org/problems/gold-mine-problem2608/1

---------------------------

Logic: DP

---------------------------

Complexity: 

Method 1 : Recursion

Time Complexity= O(n*3^m)

Space Complexity= O(m) recurive stack

----------------
Method 2 : Memoization

Time Complexity= O(n*m)

Space Complexity=O(n*m)dp vector + O(m) recurive stack

----------------
Method 3 : Tabulation

Time Complexity= O(n*m)

Space Complexity=O(n*m)dp vector

----------------
Method 4 : Space Optimization

Time Complexity= O(n*m)

Space Complexity=O(2n)dp vector

----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method : DP
*/

class Solution{
public:
int rec(int i,int j,int n, int m, vector<vector<int>> M)
{
    if(i==n || j==m || i<0)
    return 0;
    return M[i][j]+max(rec(i-1,j+1,n,m,M),max(rec(i,j+1,n,m,M),
    rec(i+1,j+1,n,m,M)));
}
int rec1(int i,int j,int n, int m, vector<vector<int>> M,
vector<vector<int>>&dp)
{
    if(i==n || j==m || i<0)
    return 0;
    if(dp[i][j]!=-1)
    return dp[i][j];
    return dp[i][j]=M[i][j]+max(rec1(i-1,j+1,n,m,M,dp),
    max(rec1(i,j+1,n,m,M,dp),
    rec1(i+1,j+1,n,m,M,dp)));
}
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        // code here
        int maxi=0;
        // for(int i=0;i<n;i++)
        // maxi=max(maxi,rec(i,0,n,m,M));
        
        // vector<vector<int>>dp(n,vector<int>(m,-1));
        // for(int i=0;i<n;i++)
        // maxi=max(maxi,rec1(i,0,n,m,M,dp));
        
        // tabulation
        // vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        // for(int i=0;i<n;i++)
        // dp[i][m-1]=M[i][m-1];
        // for(int j=m-2;j>=0;j--)
        // {
        //     for(int i=n-1;i>=0;i--)
        //     {
        //         int a=0;
        //         if(i-1>=0)
        //         a=dp[i-1][j+1];
        //         int b=dp[i][j+1];
        //         int c=0;
        //         if(i+1<n)
        //         c=dp[i+1][j+1];
        //         dp[i][j]=M[i][j]+max(a,max(b,c));
        //         maxi=max(maxi,dp[i][j]);
        //     }
        // }
        
        // space optimization
        vector<int>dp(n+1);
        vector<int>temp(n+1);
        for(int i=0;i<n;i++)
        dp[i]=M[i][m-1];
        for(int j=m-2;j>=0;j--)
        {
            for(int i=n-1;i>=0;i--)
            {
                int a=0;
                if(i-1>=0)
                a=dp[i-1];
                int b=dp[i];
                int c=0;
                if(i+1<n)
                c=dp[i+1];
                temp[i]=M[i][j]+max(a,max(b,c));
                maxi=max(maxi,temp[i]);
            }
            dp=temp;
        }
        return maxi;
    }
};