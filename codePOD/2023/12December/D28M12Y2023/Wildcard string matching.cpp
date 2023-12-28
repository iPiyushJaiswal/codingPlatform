/*Problem GFG (Hard)

Wildcard string matching


Question link: https://www.geeksforgeeks.org/problems/wildcard-string-matching1126/1

---------------------------

Logic: DP

---------------------------

Complexity: 

Method 1 : Recursion

Time Complexity= O(exponential)

Space Complexity= O(max(n,m))
----------------------------------
Method 2 : Memoization

Time Complexity= O(n*m)

Space Complexity= O(n*m) dp vector + O(max(n,m)) recursive stack
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

class Solution{
    public:
    bool rec(int i,int n,int j,int m,string w, string p)
    {
        if(i==n && j==m)
        return true;
        if(i==n || j==m)
        return false;
        bool a=false,b=false,c=false;
        if(w[i]=='?')
        a=rec(i+1,n,j+1,m,w,p);
        else if(w[i]=='*')
        b=rec(i,n,j+1,m,w,p) || rec(i+1,n,j+1,m,w,p);
        else if(w[i]==p[j])
        c=rec(i+1,n,j+1,m,w,p);
        return a || b || c;
    }
    bool rec1(int i,int n,int j,int m,string w, string p,
    vector<vector<int>>&dp)
    {
        if(i==n && j==m)
        return true;
        if(i==n || j==m)
        return false;
        if(dp[i][j]!=-1)
        return dp[i][j];
        bool a=false,b=false,c=false;
        if(w[i]=='?')
        a=rec1(i+1,n,j+1,m,w,p,dp);
        else if(w[i]=='*')
        b=rec1(i,n,j+1,m,w,p,dp) || rec1(i+1,n,j+1,m,w,p,dp);
        else if(w[i]==p[j])
        c=rec1(i+1,n,j+1,m,w,p,dp);
        return dp[i][j]=a || b || c;
    }
    bool match(string w, string p)
    {
        // code here
        int n=w.size();
        int m=p.size();
        // return rec(0,n,0,m,w,p);
        
        // memoization
        // vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        // return rec1(0,n,0,m,w,p,dp);
        
        // tabulation
        // vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        // dp[n][m]=1;
        // for(int i=n-1;i>=0;i--)
        // {
        //     for(int j=m-1;j>=i;j--)
        //     {
        //         bool a=false,b=false;
        //         if(w[i]=='?' || w[i]==p[j])
        //         a=dp[i+1][j+1];
        //         else if(w[i]=='*')
        //         b=dp[i][j+1] || dp[i+1][j+1];
        //         dp[i][j]=a || b;
        //     }
        // }
        // return dp[0][0];
        
        // space optimization
        vector<int>dp(m+1,0);
        vector<int>temp(m+1,0);
        dp[m]=1;
        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=i;j--)
            {
                bool a=false,b=false;
                if(w[i]=='?' || w[i]==p[j])
                a=dp[j+1];
                else if(w[i]=='*')
                b=temp[j+1] || dp[j+1];
                temp[j]=a || b;
            }
            dp=temp;
        }
        return dp[0];
    }
};