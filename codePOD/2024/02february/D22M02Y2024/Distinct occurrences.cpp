/*Problem GFG (Medium)

Distinct occurrences


Question link:	https://www.geeksforgeeks.org/problems/distinct-occurrences/1

---------------------------

Logic: DP

---------------------------

Complexity: 

Method 1 : Recursion

Time Complexity= O(2^n)

Space Complexity= O(n) recursive stack
----------------------------------
Method 2 : Memoization

Time Complexity= O(n*m)

Space Complexity= O(n*m) dp vector + O(n) recursive stack
----------------------------------
Method 3 : Tabulation

Time Complexity= O(n*m)

Space Complexity= O(n*m) dp vector
----------------------------------
Method 4 : Space Optimization

Time Complexity= O(n*m)

Space Complexity= O(2*m) dp vector
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
    int mod=1e9 +7;
    int rec(string s,string t,int i,int j)
    {
        if(j<0)
        return 1;
        if(i<0)
        return 0;
        int a=0;
        if(s[i]==t[j])
        a=rec(s,t,i-1,j-1)%mod;
        int b=rec(s,t,i-1,j)%mod;
        return (a+b)%mod;
    }
    int rec1(string s,string t,int i,int j,vector<vector<int>>&dp)
    {
        if(j<0)
        return 1;
        if(i<0)
        return 0;
        if(dp[i][j]!=-1)
        return dp[i][j];
        int a=0;
        if(s[i]==t[j])
        a=rec1(s,t,i-1,j-1,dp)%mod;
        int b=rec1(s,t,i-1,j,dp)%mod;
        return dp[i][j]=(a+b)%mod;
    }
    int subsequenceCount(string s, string t)
    {
      //Your code here
      int n=s.size();
      int m=t.size();
      
    //   recursion
    //   return rec(s,t,n-1,m-1);
    
    // memoization
    // vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
    // return rec1(s,t,n-1,m-1,dp);
    
    // tabulation
    // vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    // dp[0][0]=1;
    // for(int i=1;i<=n;i++)
    // {
    //     dp[i][0]=1;
    //     for(int j=1;j<=m;j++)
    //     {
    //         int a=0;
    //         if(s[i-1]==t[j-1])
    //         a=dp[i-1][j-1]%mod;
    //         int b=dp[i-1][j]%mod;
    //         dp[i][j]=(a+b)%mod;
    //     }
    // }
    // return dp[n][m];
    
    // space optimization
    vector<int>dp(m+1,0);
    vector<int>temp(m+1,0);
    dp[0]=1;
    for(int i=1;i<=n;i++)
    {
        temp[0]=1;
        for(int j=1;j<=m;j++)
        {
            int a=0;
            if(s[i-1]==t[j-1])
            a=dp[j-1]%mod;
            int b=dp[j]%mod;
            temp[j]=(a+b)%mod;
        }
        dp=temp;
    }
    return dp[m];
    }
};