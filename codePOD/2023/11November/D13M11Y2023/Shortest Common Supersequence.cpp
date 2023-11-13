/*Problem GFG (Medium)

Shortest Common Supersequence


Question link: https://www.geeksforgeeks.org/problems/shortest-common-supersequence0322/1

---------------------------

Logic: DP

---------------------------

Complexity: 

Method 1 : Recursion

Time Complexity= O(2^(min(m,n)))

Space Complexity=O(min(m,n)) recursive stack

-----------------------------
Method 2 : Memoization

Time Complexity= O(m*n)

Space Complexity=O(m*n)dp vector + O(min(m,n)) recursive stack

-----------------------------
Method 3 : Tabulation

Time Complexity= O(m*n)

Space Complexity=O(m*n)dp vector

-----------------------------
Method 4 : Space Optimization

Time Complexity= O(m*n)

Space Complexity=O(2n)dp vector

-----------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method : DP
*/

class Solution
{
    public:
    //Function to find length of shortest common supersequence of two strings.
    int rec(string x,string y,int i,int j)
    {
        if(i<0 || j<0)
        return 0;
        if(x[i]==y[j])
        return 1 + rec(x,y,i-1,j-1);
        return max(rec(x,y,i-1,j),rec(x,y,i,j-1));
    }
    int rec1(string x,string y,int i,int j,vector<vector<int>>&dp)
    {
        if(i<0 || j<0)
        return 0;
        if(dp[i][j]!=-1)
        return dp[i][j];
        if(x[i]==y[j])
        return dp[i][j]=1 + rec1(x,y,i-1,j-1,dp);
        return dp[i][j]=max(rec1(x,y,i-1,j,dp),rec1(x,y,i,j-1,dp));
    }
    int shortestCommonSupersequence(string X, string Y, int m, int n)
    {
        //code here
        // recursion
        // int c=rec(X,Y,m-1,n-1);
        // int a=m-c;
        // return a+n;
        
        // memoization
        // vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        // int c=rec1(X,Y,m-1,n-1,dp);
        // int a=m-c;
        // return a+n;
        
        // tabulation
        // vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        // int maxi=INT_MIN;
        // for(int i=1;i<=m;i++)
        // {
        //     for(int j=1;j<=n;j++)
        //     {
        //         if(X[i-1]==Y[j-1])
        //         dp[i][j]=1 + dp[i-1][j-1];
        //         else
        //         dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        //         maxi=max(maxi,dp[i][j]);
        //     }
        // }
        // int a=m-maxi;
        // return a+n;
        
        // space optimization
        vector<int>dp(n+1,0);
        vector<int>temp(n+1,0);
        int maxi=INT_MIN;
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(X[i-1]==Y[j-1])
                temp[j]=1 + dp[j-1];
                else
                temp[j]=max(dp[j],temp[j-1]);
                maxi=max(maxi,temp[j]);
            }
            dp=temp;
        }
        int a=m-maxi;
        return a+n;
    }
};