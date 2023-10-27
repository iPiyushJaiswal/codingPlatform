/*Problem GFG (Medium)

Minimum Deletions


Question link: https://practice.geeksforgeeks.org/problems/minimum-deletitions1648/1

---------------------------

Logic: DP

---------------------------

Complexity: 

Method 1 : Recursion

Time Complexity= O(2^n) expo .

Space Complexity=O(n) recursive stack

-----------------------------
Method 2 : Memoization

Time Complexity= O(n*n) .

Space Complexity=O(n*n)dp vector + O(n) recursive stack

-----------------------------
Method 3 : Tabulation

Time Complexity= O(n*n) .

Space Complexity=O(n*n)dp vector

-----------------------------
Method 4 : Space Optimization

Time Complexity= O(n*n) .

Space Complexity=O(2*n)dp vector

-----------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method : DP
*/

class Solution{
  public:
  int rec(int i,int j,int n,string s)
  {
      if(i>=j)
      return 0;
      int take=INT_MAX;
      if(s[i]==s[j])
      take=rec(i+1,j-1,n,s);
      int notTake=1 + min(rec(i+1,j,n,s),rec(i,j-1,n,s));
      return min(take,notTake);
  }
  int rec1(int i,int j,int n,string s,vector<vector<int>>&dp)
  {
      if(i>=j)
      return 0;
      if(dp[i][j]!=-1)
      return dp[i][j];
      int take=INT_MAX;
      if(s[i]==s[j])
      take=rec1(i+1,j-1,n,s,dp);
      int notTake=1 + min(rec1(i+1,j,n,s,dp),rec1(i,j-1,n,s,dp));
      return dp[i][j]=min(take,notTake);
  }
    int minimumNumberOfDeletions(string s) { 
        // code here
        int n=s.size();
        //recursion
        // return rec(0,n-1,n,s);
        
        // memoization
        // vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        // return rec1(0,n-1,n,s,dp);
        
        // tabulation
        // vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        // for(int i=n-1;i>=0;i--)
        // {
        //     for(int j=i+1;j<n;j++)
        //     {
        //         int take=INT_MAX;
        //         if(s[i]==s[j])
        //         take=dp[i+1][j-1];
        //         int notTake=1 + min(dp[i+1][j],dp[i][j-1]);
        //         dp[i][j]=min(take,notTake);
        //     }
        // }
        // return dp[0][n-1];
        
        // space optimization
        vector<int>dp(n+1,0);
        vector<int>temp(n+1,0);
        for(int i=n-1;i>=0;i--)
        {
            for(int j=i+1;j<n;j++)
            {
                int take=INT_MAX;
                if(s[i]==s[j])
                take=dp[j-1];
                int notTake=1 + min(dp[j],temp[j-1]);
                temp[j]=min(take,notTake);
            }
            dp=temp;
        }
        return dp[n-1];
    } 
};